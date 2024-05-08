import numpy as np
import matplotlib.pyplot as plt
from scipy import signal
import cmath
import math


def M(s):
    return s ** 4 + 12 * s ** 3 + 50 * s ** 2 + 84 * s + 45


def Michaj(w):
    return (w ** 4 - 50 * w ** 2 + 45) + 1j * (-12 * w ** 3 + 84 * w)


def Nyq(w, k):
    return (((k*(w**4-50*w**2+45+k))/
             ((w**4-50*w**2+45+k)**2 + (-12*w**3+84*w)**2)) +
            (1j*(-k*(-12*w**3+84*w))/
             ((w**4-50*w**2+45+k)**2 + (-12*w**3+84*w)**2)))

k = -44
w = np.linspace(0, 8, 1000)
Re = M(w * 1j).real
Im = M(w * 1j).imag
Re_n = (k / (M(w * 1j) + k)).real
Im_n = (k / (M(w * 1j) + k)).imag

plt.plot(Michaj(w).real, Michaj(w).imag, linewidth=2, label="Wykres funkcji michajłowa")
plt.plot(Re, Im, linestyle="--", label="sprawdzenie")

plt.legend()
plt.grid()
plt.show()

plt.plot(Nyq(w, k).real, Nyq(w, k).imag, label="Wykres funkcji Nyquista analitycznie")
plt.plot(Re_n, Im_n, linestyle="--", label="Symulacyjny wykres")

plt.legend()
plt.grid()
plt.show()


numerator = [k]
denominator = [1, 12, 50, 84, 45]

system = signal.TransferFunction(numerator, denominator)

# Time vector for simulation
t = np.linspace(0, 8, 1000)

# Compute step response
t, y = signal.step(system, T=t)

# Plot step response
plt.plot(t, y)
plt.axhline(y=0.2444, color='r', linestyle = '--')
plt.title('Step Response')
plt.xlabel('Time')
plt.ylabel('Output')
plt.grid()
plt.show()

numerator = [k]
denominator = [1, 12, 50, 84, 45+k]

system = signal.TransferFunction(numerator, denominator)


wzmocnienie = k/(45+k)

# Compute step response
t, y = signal.step(system, T=t)
# Plot step response
plt.plot(t, y)
plt.axhline(y=wzmocnienie, color='r', linestyle = '--')
plt.title('Step Response')
plt.xlabel('Time')
plt.ylabel('Output')
plt.grid()
plt.show()

# Tworzenie wartości dla osi X
x_values = np.linspace(0, 8, 1000)

# Obliczanie wartości dla osi Y (argument funkcji)
y_values_michaj = np.angle(Michaj(x_values)) % (2 * np.pi)

# Tworzenie wykresu
plt.plot(x_values, y_values_michaj)
plt.xlabel('Wartość w')
plt.ylabel('Argument funkcji Michajłowa')
plt.title('Zmiana argumentu funkcji Michajłowa')
plt.grid(True)
plt.show()

# Obliczanie wartości dla osi Y (argument funkcji)
y_values_nyquist = np.angle(Nyq(x_values,k)+1) % (2*np.pi)

# Tworzenie wykresu
plt.plot(x_values, y_values_nyquist)
plt.xlabel('Wartość w')
plt.ylabel('Argument funkcji Nyquista')
plt.title('Zmiana argumentu funkcji Nyquista')
plt.grid(True)
plt.show()