import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint

# plt.close('all')


# 3.0 -> u(t) = t^2*e^{-2t}
def dydt_1(x, t):   # Rozwiązanie symulacyjne dla podstawowe równania
    dydt = [0, 0, 0]
    dydt[0] = x[1]  # Podstawienie
    dydt[1] = x[2]
    dydt[2] = t ** 2 * np.exp(-2 * t) - 16 * x[2] - 79 * x[1] - 120 * x[0]
    return dydt


y0 = [0,0,0]


def an_1(t):  # rozwiązanie analityczne dla podstawowego równania
    return (1 / 18 * np.exp(-2 * t) * (t ** 2) - 1 / 6 * np.exp(-2 * t) * t + 61 / 324 * np.exp(-2 * t) -
            1 / 5 * np.exp(-3 * t) + 1 / 81 * np.exp(-5 * t) - 1 / 1620 * np.exp(-8 * t))


# 4.0 -> u(t) = delta diraca & u(t) = delta kroneckera
def dydt_skok(x, t):    # rozwiązanie symulacyjne dla odpowiedzi skokowej
    dydt = [0, 0, 0]
    dydt[0] = x[1]
    dydt[1] = x[2]
    dydt[2] = 1 - 16 * x[2] - 79 * x[1] - 120 * x[0]
    return dydt


def an2(t):     # rozwiązanie analityczne dla odpowiedzi skokowej
    return (1 / 120) + (1 / 30) * np.exp(-5 * t) - (1 / 120) * np.exp(-8 * t) - (1 / 30) * np.exp(-3 * t)


def an3(t):     # rozwiązanie analityczne dla odpowiedzi impulsowej
    return -(1 / 6) * np.exp(-5 * t) + (1 / 15) * np.exp(-8 * t) + (1 / 10) * np.exp(-3 * t)

def an4(t):     # rozwiązanie analityczne z warunkami początkowymi
    return ((1/120-1/30*np.exp(-3*t)+1/30*np.exp(-5*t)-1/120*np.exp(-8*t))
            +y0[2]*(1/10*np.exp(-3*t)+1/15*np.exp(-8*t)-1/6*np.exp(-5*t))
            +y0[1]*(13/10*np.exp(-3*t)+8/15*np.exp(-8*t)-11/6*np.exp(-5*t))
            +y0[0]*(4*np.exp(-3*t)-4*np.exp(-5*t)+np.exp(-8*t)))


t = np.linspace(0, 8, 30)   # 30 punktów
t2 = np.linspace(0, 1.5, 300) # 300 punktów
y3 = odeint(dydt_1, y0, t2)
y4 = odeint(dydt_skok, y0, t)   # wyznaczenie skokowej dla 30 punktów
y4_2 = odeint(dydt_skok, y0, t2)    # wyznaczenie skokowej dla 300 punktów
y5 = np.gradient(y4[:, 0], t)   # wyznaczenie impulsowej dla 30 punktów
y6 = np.gradient(y4_2[:, 0], t2)    # wyznaczenie impulsowej dla 300 punktów


y0_1 = [20,5,5]
y0_2 = [5,20,5]
y0_3 = [5,5,20]

def an4_1(t):     # rozwiązanie analityczne z warunkami początkowymi
    return ((1/120-1/30*np.exp(-3*t)+1/30*np.exp(-5*t)-1/120*np.exp(-8*t))
            +y0_1[2]*(1/10*np.exp(-3*t)+1/15*np.exp(-8*t)-1/6*np.exp(-5*t))
            +y0_1[1]*(13/10*np.exp(-3*t)+8/15*np.exp(-8*t)-11/6*np.exp(-5*t))
            +y0_1[0]*(4*np.exp(-3*t)-4*np.exp(-5*t)+np.exp(-8*t)))

def an4_2(t):     # rozwiązanie analityczne z warunkami początkowymi
    return ((1/120-1/30*np.exp(-3*t)+1/30*np.exp(-5*t)-1/120*np.exp(-8*t))
            +y0_2[2]*(1/10*np.exp(-3*t)+1/15*np.exp(-8*t)-1/6*np.exp(-5*t))
            +y0_2[1]*(13/10*np.exp(-3*t)+8/15*np.exp(-8*t)-11/6*np.exp(-5*t))
            +y0_2[0]*(4*np.exp(-3*t)-4*np.exp(-5*t)+np.exp(-8*t)))

def an4_3(t):     # rozwiązanie analityczne z warunkami początkowymi
    return ((1/120-1/30*np.exp(-3*t)+1/30*np.exp(-5*t)-1/120*np.exp(-8*t))
            +y0_3[2]*(1/10*np.exp(-3*t)+1/15*np.exp(-8*t)-1/6*np.exp(-5*t))
            +y0_3[1]*(13/10*np.exp(-3*t)+8/15*np.exp(-8*t)-11/6*np.exp(-5*t))
            +y0_3[0]*(4*np.exp(-3*t)-4*np.exp(-5*t)+np.exp(-8*t)))

y4_pocz1 = odeint(dydt_skok, y0_1, t2)  # Obliczenia dla różnych warunków początkowych
y4_pocz2 = odeint(dydt_skok, y0_2, t2)
y4_pocz3 = odeint(dydt_skok, y0_3, t2)

plt.figure(2)   # Wykres dla podstawowego systemu
plt.plot(t2,y3[:,0],linewidth=4,label="solver")
plt.plot(t2,an_1(t2),'--',linewidth=4,label="analityczne")
plt.grid()
plt.legend()
plt.show()

figure, axis = plt.subplots(2)  # Wykres dla odpowiedzi skokowej i impulsowej
axis[0].plot(t2, y4_2[:,0], linewidth=3, label="solver", color='blue')
axis[0].plot(t2, an2(t2), '--', linewidth=2, label="analityczne", color='red')
axis[1].plot(t2, y6, linewidth=3, label="solver", color='blue')
axis[1].plot(t2, an3(t2), '--', linewidth=2, label="analityczne", color='red')
axis[0].grid()
axis[0].legend()
axis[1].grid()
axis[1].legend()
plt.show()

figure, axis = plt.subplots(3)  # Wykres dla porównania warunków początkowych
axis[0].plot(t2, y4_pocz1[:,0], linewidth=3, label="solver", color='blue')
axis[0].plot(t2, an4_1(t2), '--', linewidth=2, label="analityczne", color='red')
axis[1].plot(t2, y4_pocz2[:,0], linewidth=3, label="solver", color='blue')
axis[1].plot(t2, an4_2(t2), '--', linewidth=2, label="analityczne", color='red')
axis[2].plot(t2, y4_pocz3[:,0], linewidth=3, label="solver", color='blue')
axis[2].plot(t2, an4_3(t2), '--', linewidth=2, label="analityczne", color='red')
axis[0].grid()
axis[0].legend()
axis[1].grid()
axis[1].legend()
axis[2].grid()
axis[2].legend()
plt.show()
