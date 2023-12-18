import numpy as np
from skimage import io
from skimage import transform
import cv2

image = io.imread('pies.jpg')

x = 500
def Mosaicing(image):
    image = transform.resize(image, output_shape=(x, x, 3))

    green = np.zeros((x,x), dtype=np.uint8)
    green[::2, ::2] = 1
    green[1::2, 1::2] = 1

    red = np.zeros((x,x), dtype=np.uint8)
    red[::2, 1::2] = 1

    blue = np.zeros((x,x), dtype=np.uint8)
    blue[1::2, ::2] = 1

    bayer = np.dstack((red, green, blue))
    return image * bayer
