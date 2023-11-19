import matplotlib.pyplot as plt
import numpy as np
import kernels
from skimage import io, color
from skimage.util import view_as_windows
from sklearn.metrics import mean_squared_error as MSE


image_original = io.imread("img.jpg")

print(image_original.shape)
image = color.rgb2gray(image_original)

io.imshow(image_original)
io.show()
io.imshow(image)
io.show()


def interpolate(x, y, x_interpolate, kernel):
    width = x[1] - x[0]
    kernels = []
    for offset in x:
        kernels.append(kernel(x_interpolate, offset=offset, width=width))
    return y @ kernels


def scale_down(image, kernel_size):
    kernel = np.ones((kernel_size, kernel_size)) / kernel_size ** 2
    windows = view_as_windows(image, window_shape=kernel_size, step=kernel_size)
    return np.sum(windows * kernel, axis=(2, 3)).squeeze()


def scale_up(image, kernel, ratio):
    def row_column_interpolate(row):
        x = np.linspace(0, len(row), len(row))
        x_interpolate = np.linspace(0, len(row), ratio * len(row))
        return interpolate(x, row, x_interpolate, kernel)

    interpolated = np.apply_along_axis(row_column_interpolate, 1, image)
    return np.apply_along_axis(row_column_interpolate, 0, interpolated)


def rgb_scale_up(image, kernel, ratio, scale_up_func):
    r = scale_up_func(image[:, :, 0], kernel, ratio)
    g = scale_up_func(image[:, :, 1], kernel, ratio)
    b = scale_up_func(image[:, :, 2], kernel, ratio)
    return (np.dstack((r, g, b))).astype(np.uint8)


def rgb_scale_down(image, kernel_size, scale_down_func):
    r = scale_down_func(image[:, :, 0], kernel_size)
    g = scale_down_func(image[:, :, 1], kernel_size)
    b = scale_down_func(image[:, :, 2], kernel_size)
    return (np.dstack((r, g, b))).astype(np.uint8)


def max_pool(image, kernel_size):
    windows = view_as_windows(image, window_shape=kernel_size, step=kernel_size)
    return np.max(windows, axis=(2, 3)).squeeze()


def min_pool(image, kernel_size):
    windows = view_as_windows(image, window_shape=kernel_size, step=kernel_size)
    return np.min(windows, axis=(2, 3)).squeeze()

# Skalowanie obrazu szarego i błąd MSE
downscale = scale_down(image, kernel_size=3)
_ = io.imshow(downscale)
io.show()

upscaled = scale_up(downscale, kernel=kernels.kernel_h3, ratio=3)

_ = io.imshow(upscaled)
io.show()

mean_squared_error_gray = "{:.8f}".format(MSE(y_pred=upscaled, y_true=image))
print("Błąd MSE w skali szarości: " + mean_squared_error_gray)

# Skalowanie obrazu RGB i błędy MSE dla poszczeólnych kanałów
rgb_down = rgb_scale_down(image=image_original, kernel_size=3, scale_down_func=scale_down)

_ = io.imshow(rgb_down)
io.show()

rgb_up = rgb_scale_up(image=rgb_down, kernel=kernels.kernel_h3, ratio=3, scale_up_func=scale_up)

_ = io.imshow(rgb_up)
io.show()

mean_squared_error_color = "{:.8f}".format(MSE(y_pred=rgb_up[:, :, 1], y_true=image_original[:, :, 0]))
print("Czerwony: " + mean_squared_error_color)
mean_squared_error_color = "{:.8f}".format(MSE(y_pred=rgb_up[:, :, 1], y_true=image_original[:, :, 1]))
print("Zielony: " + mean_squared_error_color)
mean_squared_error_color = "{:.8f}".format(MSE(y_pred=rgb_up[:, :, 1], y_true=image_original[:, :, 2]))
print("Niebieski: " + mean_squared_error_color)

# Max pooling i min pooling
max_pooling = max_pool(image, kernel_size=3)

_ = io.imshow(max_pooling)
io.show()

min_pooling = min_pool(image, kernel_size=3)

_ = io.imshow(min_pooling)
io.show()

# Porównanie sekwencyjnej interpolacji z interpolacją jednokrotną
img_downscale = scale_down(image=image, kernel_size=3)

img_full_upscale = scale_up(image=img_downscale, kernel=kernels.kernel_h3, ratio=8)

_ = io.imshow(img_full_upscale)
io.show()

img_seq_upscale = scale_up(image=img_downscale, kernel=kernels.kernel_h3, ratio=2)
img_seq_upscale_x4 = scale_up(image=img_seq_upscale, kernel=kernels.kernel_h3, ratio=2)
img_seq_upscale_x8 = scale_up(image=img_seq_upscale_x4, kernel=kernels.kernel_h3, ratio=2)

_ = io.imshow(img_seq_upscale_x8)
io.show()

mean_squared_error_seq = "{:.8f}".format(MSE(y_pred=img_seq_upscale_x8, y_true=img_full_upscale))
print("Błąd MSE w sekwencyjnym skalowaniu: " + mean_squared_error_seq)


# Porównanie różnych funkcji jądrowych
scale_h1 = scale_up(downscale, kernel=kernels.kernel_h1, ratio=3)
_ = io.imshow(scale_h1)
io.show()

scale_h2 = scale_up(downscale, kernel=kernels.kernel_h2, ratio=3)
_ = io.imshow(scale_h2)
io.show()

scale_h3 = scale_up(downscale, kernel=kernels.kernel_h3, ratio=3)
_ = io.imshow(scale_h3)
io.show()

scale_h4 = scale_up(downscale, kernel=kernels.kernel_h4, ratio=3)
_ = io.imshow(scale_h4)
io.show()