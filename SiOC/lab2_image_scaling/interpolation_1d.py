import numpy as np
import matplotlib.pyplot as plt
import kernels
from sklearn.metrics import mean_squared_error as MSE
from scipy.stats import truncnorm


def simple(u):
    return np.sin(2 * u)


def inverted_sin(u):
    return np.sin(np.power(u, -1))


def sign(u):
    return np.sign(np.sin(8 * u))


def interpolate(x, y, x_interpolate, kernel):
    width = x[1] - x[0]
    kernels = []
    for offset in x:
        kernels.append(kernel(x_interpolate, offset=offset, width=width))
    return y @ kernels


# Funkcja pozwalająca w łatwy sposób wygenerować punkty z rozkładu normalnego w zadanym przedziale
def get_truncated_normal(mean, sd, low, upp):
    return truncnorm((low - mean) / sd, (upp - mean) / sd, loc=mean, scale=sd)


original = 100
interpolated = 1000

x_original = np.linspace(1e-6, 2 * np.pi, original)


x_normal_distribution = get_truncated_normal(mean=0, sd=1, low=0, upp=np.pi * 2).rvs(interpolated)

# Wyświetlenie histogramu dla punktów z rozkładu normalnego z podanego przedziału
# hist = np.histogram(x_normal_distribution, bins=100)
# plt.figure(figsize=[20, 12])
# plt.hist(x_normal_distribution, bins=100)

y_sin = simple(x_original)
y_inverted_sin = inverted_sin(x_original)
y_sign = sign(x_original)

# Interpolacja wszystkich funkcji
x_interp = np.linspace(1e-6, 2 * np.pi, interpolated)

y_interp_sin = interpolate(x=x_original, y=y_sin, x_interpolate=x_interp, kernel=kernels.kernel_h3)
y_interp_inverted_sin = interpolate(x=x_original, y=y_inverted_sin, x_interpolate=x_interp, kernel=kernels.kernel_h3)
y_interp_sign = interpolate(x=x_original, y=y_sign, x_interpolate=x_interp, kernel=kernels.kernel_h3)

# Funkcje do obliczenia błędu MSE
y_true_sin = simple(x_interp)
y_true_inverted_sin = inverted_sin(x_interp)
y_true_sign = sign(x_interp)

mean_squared_error_sin = "{:.8f}".format(MSE(y_pred=y_interp_sin, y_true=y_true_sin))
mean_squared_error_inverted_sin = "{:.8f}".format(MSE(y_pred=y_interp_inverted_sin, y_true=y_true_inverted_sin))
mean_squared_error_sign = "{:.8f}".format(MSE(y_pred=y_interp_sign, y_true=y_true_sign))
print("MSE sin(x): " + mean_squared_error_sin)
print("MSE sin(x^-1): " + mean_squared_error_inverted_sin)
print("MSE sign(sin(8x)): " + mean_squared_error_sign)

# Wyświetlenie funcji oryginalnej
plt.figure(figsize=[20, 12])
plt.title("Sin(x)")
plt.plot(x_original, y_sin, 'ro')
plt.show()

plt.figure(figsize=[20, 12])
plt.title("Sin(x^-1)")
plt.plot(x_original, y_inverted_sin, 'ro')
plt.show()

plt.figure(figsize=[20, 12])
plt.title("Sgn(Sin(8x))")
plt.plot(x_interp, y_true_sign, 'ro')
plt.show()

# Wyświetlenie funcji interpolowanej
plt.figure(figsize=[20, 12])
plt.title("Interpolated Sin(x)")
plt.plot(x_interp, y_interp_sin, 'bo')
plt.show()

plt.figure(figsize=[20, 12])
plt.title("Interpolated Inverted Sin(x)")
plt.plot(x_interp, y_interp_inverted_sin, 'bo')
plt.show()

plt.figure(figsize=[20, 12])
plt.title("Interpolated Sign(x)")
plt.plot(x_interp, y_interp_sign, 'bo')
plt.show()


# Punkty do interpolacji z rozkładu normalnego

y_interp_normal_sin = interpolate(x=x_original, y=y_sin, x_interpolate=x_normal_distribution, kernel=kernels.kernel_h3)
y_interp_normal_inv_sin = interpolate(x=x_original, y=y_inverted_sin, x_interpolate=x_normal_distribution, kernel=kernels.kernel_h3)
y_interp_normal_sign = interpolate(x=x_original, y=y_sign, x_interpolate=x_normal_distribution, kernel=kernels.kernel_h3)

# Funkcje do obliczenia błędu MSE dla rozkładu normalnego
y_true_normal_sin = simple(x_normal_distribution)
y_true_normal_inv_sin = inverted_sin(x_normal_distribution)
y_true_normal_sign = sign(x_normal_distribution)


# Wyświetlenie funcji interpolowanej dla rozkładu normalnego
plt.figure(figsize=[20, 12])
plt.title("Interpolated Normal Sin(x)")
plt.plot(x_normal_distribution, y_interp_normal_sin, 'bo')
plt.show()

plt.figure(figsize=[20, 12])
plt.title("Interpolated Normal Sin(x^-1)")
plt.plot(x_normal_distribution, y_interp_normal_inv_sin, 'bo')
plt.show()

plt.figure(figsize=[20, 12])
plt.title("Interpolated Normal Sign(x)")
plt.plot(x_normal_distribution, y_interp_normal_sign, 'bo')
plt.show()

mean_squared_error_normal_sin = "{:.8f}".format(MSE(y_pred=y_interp_normal_sin, y_true=y_true_normal_sin))
mean_squared_error_normal_inv_sin = "{:.8f}".format(MSE(y_pred=y_interp_normal_inv_sin, y_true=y_true_normal_inv_sin))
mean_squared_error_normal_sign = "{:.8f}".format(MSE(y_pred=y_interp_normal_sign, y_true=y_true_normal_sign))
print("MSE normal sin(x): " + mean_squared_error_normal_sin)
print("MSE normal sin(x^-1): " + mean_squared_error_normal_inv_sin)
print("MSE normal sign(sin(x)): " + mean_squared_error_normal_sign)


# Sekwencja interpolacji o mniejszej ilości punktów
original = 100
interpolated_x2 = 200


x_original = np.linspace(1e-6, 2 * np.pi, original)
y_sin = simple(x_original)

x_interp = np.linspace(1e-6, 2 * np.pi, interpolated_x2)
y_interp = interpolate(x=x_original, y=y_sin, x_interpolate=x_interp, kernel=kernels.kernel_h3)
plt.figure(figsize=[20, 12])
plt.plot(x_interp, y_interp, 'bo')
plt.show()

interpolated_x4 = 400

x_interp_x4 = np.linspace(1e-6, 2 * np.pi, interpolated_x4)
y_interp_x4 = interpolate(x=x_interp, y=y_interp, x_interpolate=x_interp_x4, kernel=kernels.kernel_h3)
plt.figure(figsize=[20, 12])
plt.plot(x_interp_x4, y_interp_x4, 'ro')
plt.show()

interpolated_x8 = 800

x_interp_x8 = np.linspace(1e-6, 2 * np.pi, interpolated_x8)
y_interp_x8 = interpolate(x=x_interp_x4, y=y_interp_x4, x_interpolate=x_interp_x8, kernel=kernels.kernel_h3)
plt.figure(figsize=[20, 12])
plt.plot(x_interp_x8, y_interp_x8, 'ro')
plt.show()

interpolated_x16 = 1600

x_interp_x16 = np.linspace(1e-6, 2 * np.pi, interpolated_x16)
y_interp_x16 = interpolate(x=x_interp_x8, y=y_interp_x8, x_interpolate=x_interp_x16, kernel=kernels.kernel_h3)
plt.figure(figsize=[20, 12])
plt.title("Interpolated Sin(x) Sequence")
plt.plot(x_interp_x16, y_interp_x16, 'ro')
plt.show()

y_true = simple(x_interp_x16)


mean_squared_error = "{:.8f}".format(MSE(y_pred=y_true, y_true=y_interp_x16))
print(mean_squared_error)