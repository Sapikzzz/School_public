import numpy as np

def kernel_h1(u, offset, width):
    u = u - offset
    return (u >= 0) * (u < width)


def kernel_h2(u, offset, width):
    u = u - offset
    return (u >= (-1 * width / 2)) * (u < width / 2)


def kernel_h3(u, offset, width):
    u = u - offset
    u = u / width
    return (1 - np.abs(u)) * (np.abs(u) < 1)


def kernel_h4(u, offset, width):
    u = u - offset
    u = u / width
    return np.sinc(u)