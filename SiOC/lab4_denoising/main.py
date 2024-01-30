import numpy as np
from skimage import io
import cv2
import matplotlib.pyplot as plt
import pywt

image = io.imread('image_idk.jpg', as_gray=True)

print(image.shape)
_ = io.imshow(image)
io.show()


def Gaussian(image):
    def Gaussian_filter(size, sigma):
        Gaussian = np.zeros((size, size))
        for i in range(size):
            for j in range(size):
                Gaussian[i][j] = np.exp(-0.5 * ((i - size / 2) ** 2 + (j - size / 2) ** 2) / (2 * sigma ** 2))
        return Gaussian / np.sum(Gaussian)

    Gaussian = Gaussian_filter(7, 1)
    Gaussian7 = cv2.filter2D(image, -1, Gaussian)
    return Gaussian7


def denoise_image_fft_rgb_and_gray(image, threshold):
    def denoise_image_fft(image, threshold):
        image_fft = np.fft.fft2(image)
        nx, ny = image.shape
        image_fft[int(nx * threshold):int(nx * (1 - threshold))] = 0
        image_fft[:, int(ny * threshold):int(ny * (1 - threshold))] = 0
        image_new = np.fft.ifft2(image_fft).real
        return image_new

    if (len(image.shape) == 3):
        r, g, b = cv2.split(image)
        r_fft = denoise_image_fft(r, threshold)
        g_fft = denoise_image_fft(g, threshold)
        b_fft = denoise_image_fft(b, threshold)
        image_fft = np.dstack((r_fft, g_fft, b_fft))
        return image_fft
    else:
        return denoise_image_fft(image, threshold)


image_denoised_fft = denoise_image_fft_rgb_and_gray(image, threshold=0.05)

plt.imshow(image_denoised_fft, plt.cm.gray)
plt.show()

image_denoised_gaussian = Gaussian(image)

_ = io.imshow(image_denoised_gaussian)
io.show()

image_noisy_rgb = io.imread('image_large.jpg')

plt.imshow(image_noisy_rgb)
plt.show()


denoised_image_rgb_fft = denoise_image_fft_rgb_and_gray(image_noisy_rgb, threshold=0.05)
io.imshow(denoised_image_rgb_fft / 256)
io.show()


def denoise_image_wavelet(image, threshold, wavelet='db1', level=1, mode='soft'):
    coeffs = pywt.wavedec2(image, wavelet, level)
    coeffs, slices = pywt.coeffs_to_array(coeffs)

    coeffs_thresholded = pywt.threshold(coeffs, threshold, mode)
    reconstructed = pywt.array_to_coeffs(coeffs_thresholded, slices, output_format='wavedec2')
    reconstructed_image = pywt.waverec2(reconstructed, wavelet)

    return reconstructed_image


denoised_image_wavelet = denoise_image_wavelet(image, threshold=0.2, wavelet='db8', level=1, mode='hard')

plt.imshow(denoised_image_wavelet, plt.cm.gray)
plt.show()


def image_compress_fft_rgb_ang_gray(image, keep_fraction):
    def image_compress(image, keep_fraction):
        image_fft = np.fft.fft2(image)  # 2D FFT
        image_fft_sort = np.sort(np.abs(image_fft.reshape(-1)))  # Sorting the values
        threshold = image_fft_sort[int(np.floor((1 - keep_fraction) * len(image_fft_sort)))]  # Creating threshold
        indices = np.abs(image_fft) > threshold  # Creating indices
        image_fft_low = image_fft * indices
        image_low = np.fft.ifft2(image_fft_low).real  # Inverse FFT for compressed image
        return image_low

    if (len(image.shape) == 3):
        r, g, b = cv2.split(image)
        r = image_compress(r, keep_fraction)
        g = image_compress(g, keep_fraction)
        b = image_compress(b, keep_fraction)
        image_fft = np.dstack((r, g, b))
        return image_fft
    else:
        return image_compress(image, keep_fraction)

image_rgb = io.imread('pies.jpg')

plt.imshow(image_rgb)
plt.show()

image_compressed_fft = image_compress_fft_rgb_ang_gray(image_rgb, keep_fraction=0.01)


plt.imshow(image_compressed_fft/256)
plt.show()


def image_compress_wavelet_rgb_ang_gray(image, keep_fraction, wavelet, level):
    def image_compress(image, keep_fraction, wavelet, level):
        coeffs = pywt.wavedec2(image, wavelet, level)
        coeffs, slices = pywt.coeffs_to_array(coeffs)
        coefss_sorted = np.sort(np.abs(coeffs.reshape(-1)))
        thresh = coefss_sorted[int(np.floor((1 - keep_fraction) * len(coefss_sorted)))]
        ind = np.abs(coeffs) > thresh
        coeffs_array_filtered = coeffs * ind
        coeffs_filtered = pywt.array_to_coeffs(coeffs_array_filtered, slices, output_format='wavedec2')
        image_compressed = pywt.waverec2(coeffs_filtered, wavelet)
        return image_compressed

    if (len(image.shape) == 3):
        r, g, b = cv2.split(image)
        r = image_compress(r, keep_fraction, wavelet, level)
        g = image_compress(g, keep_fraction, wavelet, level)
        b = image_compress(b, keep_fraction, wavelet, level)
        image_wavelet = np.dstack((r, g, b))
        return image_wavelet
    else:
        return image_compress(image, keep_fraction, wavelet, level)


image_compressed_wavelet = image_compress_wavelet_rgb_ang_gray(image_rgb, keep_fraction=0.01, wavelet='db1', level=1)

plt.imshow(image_compressed_wavelet/256)
plt.show()
