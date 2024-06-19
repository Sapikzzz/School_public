import numpy as np
import matplotlib.pyplot as plt

def kronecker(n):
    if n == 0:
        return 1
    else:
        return 0

def y_base(n):
  if n == 0:
    return 3*(-1/8)**n
  else:
    return 3*(-1/8)**n - 3*(-1/8)**(n-1) - (9/10)*y_base(n - 1)

def y_analytical_base(n):
    return (-(135 / 31) * (-1 / 8) ** n)+((228/31) * (-9 / 10) ** n)

def y_step(n):
    if n == 0:
        return 3 * 1
    else:
        return 3 * 1 - 3 * 1 - (9 / 10) * y_step(n - 1)

def y_analytical_step(n):
    return 3*((-9/10)**n)

def y_impulse(n):
    if n == 0:
        return 3 * 1
    else:
        return 3 * kronecker(n) - 3 * kronecker(n-1) - (9 / 10) * y_impulse(n - 1)

def y_analytical_impulse(n):
    if n == 0:
        return 3*(-9/10)**n
    else:
        return 3*(-9/10)**n - 3*(-9/10)**(n-1)

def xdd(n):
    return (-30/9)*kronecker(n) + 57/9*(-9/10)**n


def y_step_initial(n, y1):
    if n == 0:
        return 3 * 1 - y1 * 9/10
    else:
        return 3 * 1 - 3 * 1 - (9 / 10) * y_step_initial(n - 1, y1)

def y_analytical_step_initial(n, y1):
    return (3 * (-9 / 10) ** n)-(9 / 10 * y1 * (-9 / 10) ** n)

def step_to_impulse(n):
    if n ==0:
        return y_step(n)
    else:
        return y_step(n) - y_step(n-1)

y_1 = np.zeros(40)  # base
y_2 = np.zeros(40)  # analytical
y_3 = np.zeros(40)  # step base
y_4 = np.zeros(40)  # step analytical
y_5 = np.zeros(40)  # impulse analytical
y_6 = np.zeros(40)  # impulse base
y_7 = np.zeros(40)  # step with initial analytical
y_8 = np.zeros(40)  # step with initial

y_9 = np.zeros(40)

y_10 = np.zeros(40)
y_11 = np.zeros(40)
y_12 = np.zeros(40)
y_13 = np.zeros(40)

x = np.arange(0,40,1)
for i in x:
    y_1[i] = y_base(x[i])

for i in x:
    y_2[i] = y_analytical_base(x[i])

for i in x:
    y_3[i] = y_step(x[i])

for i in x:
    y_4[i] = y_analytical_step(x[i])

for i in x:
    y_5[i] = y_analytical_impulse(x[i])

for i in x:
    y_6[i] = y_impulse(x[i])

for i in x:
    y_7[i] = y_analytical_step_initial(x[i], 0)

for i in x:
    y_8[i] = y_step_initial(x[i], 0)

for i in x:
    y_10[i] = y_step_initial(x[i], 0)

for i in x:
    y_11[i] = y_step_initial(x[i], 3)

for i in x:
    y_12[i] = y_step_initial(x[i], 20/3)

for i in x:
    y_9[i] = xdd(x[i])

for i in x:
    y_13[i] = step_to_impulse(x[i])

print(y_6)
print(y_13)
plt.plot(x, y_1, '.', label='Symulacyjnie')
plt.plot(x, y_2, '|', label='Analitycznie')
plt.title("Normal")
plt.legend()
plt.grid()
plt.show()
plt.plot(x, y_3, '.', label='Symulacyjnie')
plt.plot(x, y_4, '|', label='Analitycznie')
plt.title("Step")
plt.legend()
plt.grid()
plt.show()
plt.plot(x, y_5, '.', label='Analitycznie')
plt.plot(x, y_6, '|', label='Symulacyjnie')
plt.title("Impulse")
plt.legend()
plt.grid()
plt.show()
plt.plot(x, y_7, '.', label='Analitycznie')
plt.plot(x, y_8, '|', label='Symulacyjnie')
plt.title("Initial step")
plt.legend()
plt.grid()
plt.show()

plt.plot(x, y_10, '.', label='y1=0')
plt.plot(x, y_12, '.', label='y1=6.66')
plt.title("Comparison")
plt.legend()
plt.grid()
plt.savefig("Symmetry.pdf")
plt.show()