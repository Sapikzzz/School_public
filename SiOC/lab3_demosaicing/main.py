import numpy as np
import cv2
from skimage import io
import mosaicing
import kernels

image_bayer = io.imread('CFA_BIN/CFA/Bayer/namib.jpg')
image_fuji = io.imread('CFA_BIN/CFA/Fuji/namib.jpg')
#
# _ = io.imshow(image_bayer)
# io.show()
#
# _ = io.imshow(image_fuji)
# io.show()

def Bayer(image):
    bayer_mask = np.array([[[1, 1],
                            [1, 1]],

                           [[0.5, 0.5],
                            [0.5, 0.5]],

                           [[1, 1],
                            [1, 1]]])

    R = cv2.filter2D(image[:, :, 0], -1, bayer_mask[0])
    G = cv2.filter2D(image[:, :, 1], -1, bayer_mask[1])
    B = cv2.filter2D(image[:, :, 2], -1, bayer_mask[2])
    return np.dstack((R, G, B))


# _ = io.imshow(Bayer(image_bayer))
# io.show()


def Fuji(image):
    fuji_mask = np.array([[[1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8]],

                          [[1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20],
                           [1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20],
                           [1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20],
                           [1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20],
                           [1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20],
                           [1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20, 1 / 20]],

                          [[1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8],
                           [1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8, 1 / 8]]])

    R_fuji = cv2.filter2D(image[:, :, 0], -1, fuji_mask[0])
    G_fuji = cv2.filter2D(image[:, :, 1], -1, fuji_mask[1])
    B_fuji = cv2.filter2D(image[:, :, 2], -1, fuji_mask[2])

    return np.dstack((R_fuji, G_fuji, B_fuji))


# _ = io.imshow(Fuji(image_fuji))
# io.show()


image = io.imread('img.jpg')

_ = io.imshow(image)
io.show()


def Laplace(image):
    Laplace = np.array([[0, 1, 0],
                        [1, -4, 1],
                        [0, 1, 0]])

    Laplace_R = cv2.filter2D(image[:, :, 0], -1, Laplace)
    Laplace_G = cv2.filter2D(image[:, :, 1], -1, Laplace)
    Laplace_B = cv2.filter2D(image[:, :, 2], -1, Laplace)

    return np.dstack((Laplace_R, Laplace_G, Laplace_B))


# _ = io.imshow(Laplace(image))
# io.show()


def Gaussian(image):
    Gaussian = np.array([[1, 2, 1],
                         [1, 4, 1],
                         [1, 2, 1]]) / 16

    Gaussian_R = cv2.filter2D(image[:, :, 0], -1, Gaussian)
    Gaussian_G = cv2.filter2D(image[:, :, 1], -1, Gaussian)
    Gaussian_B = cv2.filter2D(image[:, :, 2], -1, Gaussian)

    return np.dstack((Gaussian_R, Gaussian_G, Gaussian_B))



# _ = io.imshow(Gaussian(image))
# io.show()

def Sharpen(image):
    Sharpen = np.array([[0, -1, 0],
                        [-1, 5, -1],
                        [0, -1, 0]])

    Sharpen_R = cv2.filter2D(image[:, :, 0], -1, Sharpen)
    Sharpen_G = cv2.filter2D(image[:, :, 1], -1, Sharpen)
    Sharpen_B = cv2.filter2D(image[:, :, 2], -1, Sharpen)

    return np.dstack((Sharpen_R, Sharpen_G, Sharpen_B))


_ = io.imshow(Sharpen(image))
io.show()

def Gaussian(image):
    Gaussian = np.array([[1, 2, 1],
                         [2, 4, 2],
                         [1, 2, 1]]) / 16

    Gaussian7_R = cv2.filter2D(image[:, :, 0], -1, Gaussian)
    Gaussian7_G = cv2.filter2D(image[:, :, 1], -1, Gaussian)
    Gaussian7_B = cv2.filter2D(image[:, :, 2], -1, Gaussian)

    return np.dstack((Gaussian7_R, Gaussian7_G, Gaussian7_B))


# _ = io.imshow(Gaussian(image))
# io.show()

# Function to create Gaussian filter of given size and sigma
def Gaussian_filter(size, sigma):
    Gaussian = np.zeros((size, size))
    for i in range(size):
        for j in range(size):
            Gaussian[i][j] = np.exp(-0.5 * ((i - size / 2) ** 2 + (j - size / 2) ** 2) / (2 * sigma ** 2))
    return Gaussian / np.sum(Gaussian)


def Gaussian_7(image):
    Gaussian7 = Gaussian_filter(7, 1)

    Gaussian7_R = cv2.filter2D(image[:, :, 0], -1, Gaussian7)
    Gaussian7_G = cv2.filter2D(image[:, :, 1], -1, Gaussian7)
    Gaussian7_B = cv2.filter2D(image[:, :, 2], -1, Gaussian7)

    return np.dstack((Gaussian7_R, Gaussian7_G, Gaussian7_B))

#
# _ = io.imshow(Gaussian_7(image))
# io.show()

def Gaussian_5(image):
    Gaussian5 = Gaussian_filter(5, 1)

    Gaussian5_R = cv2.filter2D(image[:, :, 0], -1, Gaussian5)
    Gaussian5_G = cv2.filter2D(image[:, :, 1], -1, Gaussian5)
    Gaussian5_B = cv2.filter2D(image[:, :, 2], -1, Gaussian5)

    return np.dstack((Gaussian5_R, Gaussian5_G, Gaussian5_B))


# _ = io.imshow(Gaussian_5(image))
# io.show()


def Sobel(image):
    Sobel_X = np.array([[1, 0, -1],
                        [2, 0, -2],
                        [1, 0, -1]])

    Sobel_Y = np.array([[1, 2, 1],
                        [0, 0, 0],
                        [-1, -2, -1]])

    Sobel_X_R = cv2.filter2D(image[:, :, 0], -1, Sobel_X)
    Sobel_X_G = cv2.filter2D(image[:, :, 1], -1, Sobel_X)
    Sobel_X_B = cv2.filter2D(image[:, :, 2], -1, Sobel_X)

    Sobel_X_rgb = np.dstack((Sobel_X_R, Sobel_X_G, Sobel_X_B))

    Sobel_Y_R = cv2.filter2D(image[:, :, 0], -1, Sobel_Y)
    Sobel_Y_G = cv2.filter2D(image[:, :, 1], -1, Sobel_Y)
    Sobel_Y_B = cv2.filter2D(image[:, :, 2], -1, Sobel_Y)

    Sobel_Y_rgb = np.dstack((Sobel_Y_R, Sobel_Y_G, Sobel_Y_B))

    return Sobel_X_rgb, Sobel_Y_rgb


Sobel_X_rgb, Sobel_Y_rgb = Sobel(image)

Sobel_rgb = Sobel_X_rgb + Sobel_Y_rgb


# _ = io.imshow(Sobel_X_rgb)
# io.show()
# _ = io.imshow(Sobel_Y_rgb)
# io.show()
# _ = io.imshow(Sobel_rgb)
# io.show()


def Average(image, kernel_size):
    Average_filter = np.ones((kernel_size, kernel_size)) / kernel_size ** 2

    Average_R = cv2.filter2D(image[:, :, 0], -1, Average_filter)
    Average_G = cv2.filter2D(image[:, :, 1], -1, Average_filter)
    Average_B = cv2.filter2D(image[:, :, 2], -1, Average_filter)

    return np.dstack((Average_R, Average_G, Average_B))


# _ = io.imshow(Average(image, kernel_size=3))
# io.show()

def Prewitt(image):
    P_1 = np.array([[-1, 0, 1],
                    [-1, 0, 1],
                    [-1, 0, 1]])


    P_2 = np.array([[1, 1, 1],
                    [0, 0, 0],
                    [-1, -1, -1]])

    Prewitt_1_R = cv2.filter2D(image[:, :, 0], -1, P_1)
    Prewitt_1_G = cv2.filter2D(image[:, :, 1], -1, P_1)
    Prewitt_1_B = cv2.filter2D(image[:, :, 2], -1, P_1)

    Prewitt_1_rgb = np.dstack((Prewitt_1_R, Prewitt_1_G, Prewitt_1_B))

    Prewitt_2_R = cv2.filter2D(image[:, :, 0], -1, P_2)
    Prewitt_2_G = cv2.filter2D(image[:, :, 1], -1, P_2)
    Prewitt_2_B = cv2.filter2D(image[:, :, 2], -1, P_2)

    Prewitt_2_RGB = np.dstack((Prewitt_2_R, Prewitt_2_G, Prewitt_2_B))

    return Prewitt_1_rgb, Prewitt_2_RGB


Prewitt_1_rgb, Prewitt_2_rgb = Prewitt(image)

Prewitt_full_rgb = Prewitt_1_rgb + Prewitt_2_rgb

# _ = io.imshow(Prewitt_1_rgb)
# io.show()
# _ = io.imshow(Prewitt_2_rgb)
# io.show()
# _ = io.imshow(Prewitt_full_rgb)
# io.show()

def Scharr(image):
    S_1 = np.array([[3, 0, -3],
                    [10, 0, -10],
                    [3, 0, -3]])

    S_2 = np.array([[3, 10, 3],
                    [0, 0, 0],
                    [-3, -10, -3]])
    Scharr_1_R = cv2.filter2D(image[:, :, 0], -1, S_1)
    Scharr_1_G = cv2.filter2D(image[:, :, 1], -1, S_1)
    Scharr_1_B = cv2.filter2D(image[:, :, 2], -1, S_1)

    Scharr_1_RGB = np.dstack((Scharr_1_R, Scharr_1_G, Scharr_1_B))

    Scharr_2_R = cv2.filter2D(image[:, :, 0], -1, S_2)
    Scharr_2_G = cv2.filter2D(image[:, :, 1], -1, S_2)
    Scharr_2_B = cv2.filter2D(image[:, :, 2], -1, S_2)

    Scharr_2_RGB = np.dstack((Scharr_2_R, Scharr_2_G, Scharr_2_B))

    return Scharr_1_RGB, Scharr_2_RGB

Scharr_1_RGB, Scharr_2_RGB = Scharr(image)

Scharr_full_RGB = Scharr_1_RGB + Scharr_2_RGB
#
# _ = io.imshow(Scharr_1_RGB)
# io.show()
# _ = io.imshow(Scharr_2_RGB)
# io.show()
#
# _ = io.imshow(Scharr_full_RGB)
# io.show()

image_to_sharpen = image/256

blurred_image_average = Gaussian_5(image_to_sharpen)


image_sharpened = 2*image_to_sharpen - blurred_image_average


_ = io.imshow(image_sharpened)
io.show()


def interpolate(x, y, x_interpolate, kernel):
    width = x[1] - x[0]
    kernels = []
    for offset in x:
        kernels.append(kernel(x_interpolate, offset=offset, width=width))
    return y @ kernels


# Function used for interpolation of red and blue channels
def interpolate_rb(image, kernel, ratio):
    def row_column_interpolate(row):
        x = np.linspace(0, len(row), len(row))
        x_interpolate = np.linspace(0, len(row), ratio * len(row))
        return interpolate(x, row, x_interpolate, kernel)

    interpolated = np.apply_along_axis(row_column_interpolate, 1, image)
    return np.apply_along_axis(row_column_interpolate, 0, interpolated)


# Function used for interpolation of green channel
def interpolate_g(image, kernel, ratio):
    def row_column_interpolate(row):
        x = np.linspace(0, len(row), len(row))
        x_interpolate = np.linspace(0, len(row), ratio * len(row))
        return interpolate(x, row, x_interpolate, kernel)

    return np.apply_along_axis(row_column_interpolate, 1, image)


i = mosaicing.Mosaicing(image)  # Making a mosaic for interpolation

# Making an array of values from each channel according to Bayer pattern for each color

i_red = []

for x in range(0, len(i[:,:,0]), 2):
    for y in range(1, len(i[:,:,0]), 2):
        i_red = np.append(i_red, i[:,:,0][x][y])

i_green = []

for x in range(0, len(i[:,:,1]), 1):
    for y in range(0, len(i[:,:,1]), 2):
        if(x % 2 == 0):
            i_green = np.append(i_green, i[:,:,1][x][y])
        else:
            i_green = np.append(i_green, i[:,:,1][x][y+1])


i_blue = []

for x in range(1, len(i[:,:,2]), 2):
    for y in range(0, len(i[:,:,2]), 2):
        i_blue = np.append(i_blue, i[:,:,2][x][y])

# Reshaping arrays into 2d arrays

#print(i_red.size)
i_red = np.reshape(i_red, (int(np.sqrt(i_red.size)), int(np.sqrt(i_red.size))))
#print(i_red.shape)

#print(i_green.size)
i_green = np.reshape(i_green, (int(np.sqrt(i_green.size/2))*2, int(np.sqrt(i_green.size/2))))
#print(i_green.shape)

#print(i_blue.size)
i_blue = np.reshape(i_blue, (int(np.sqrt(i_blue.size)), int(np.sqrt(i_blue.size))))
#print(i_blue.shape)


R_image_interpolation = interpolate_rb(i_red, kernels.kernel_h1, 2)
G_image_interpolation = interpolate_g(i_green, kernels.kernel_h1, 2)
B_image_interpolation = interpolate_rb(i_blue, kernels.kernel_h1, 2)


# _ = io.imshow(R_image_interpolation)
# io.show()
# _ = io.imshow(G_image_interpolation)
# io.show()
# _ = io.imshow(B_image_interpolation)
# io.show()


RGB_image_interpolation = np.dstack((R_image_interpolation, G_image_interpolation, B_image_interpolation))

# _ = io.imshow(i)
# io.show()
#
# _ = io.imshow(RGB_image_interpolation)
# io.show()
#
# _ = io.imshow(Bayer(i))
# io.show()