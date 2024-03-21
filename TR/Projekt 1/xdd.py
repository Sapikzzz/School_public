import numpy as np
import matplotlib.pyplot as plt 
from scipy.integrate import odeint
plt.close('all')


# Równanie różniczkowe pierwszego rzędu y'=e^(-t)
def dydt1(y,t): #zdefiniowanie równania na potrzeby solvera
    dydt=np.exp(-t)
    return dydt

def an1(t): #wyznaczone rozwiązanie analityczne 
    return(1-np.exp(-t))

y0=0 #warunki początkowe
t=np.linspace(0,6,100) #horyzont czasu 100 próbek na przedziale [0,6]


y1=odeint(dydt1,y0,t) #wywołanie solvera odeint

# Wykresy
# plt.figure(1)
# plt.plot(t,y1,linewidth=4,label="solver")
# plt.plot(t,an1(t),"--",linewidth=4,label="analitycznie")
# plt.grid()
# plt.legend()
# plt.show()

#------------------------------------------------------------------------------
# Równanie różniczkowe drugiego rzędu y''+3y'+y=1
# Ponieważ równanie jest II stopnia stosujemy podstawienie
# y=x[0] y'=x[1] i rozwiązujemy układ równań
# y'=x[1] i y''=-3x[1]-x[0]+1
def dydt2(x,t): #zdefiniowanie równania na potrzeby solvera
    dydt=[0,0] #Ponieważ rozwiązujemy układ równań definiujemy dydt jako listę, gdzie y'=dydt[0], y''=dydt[1]
    dydt[0]=x[1]
    dydt[1]=1-3*x[1]-x[0]
    return dydt

def an2(t): #wyznaczone rozwiązanie analityczne
    return(1+2/(5-3*np.sqrt(5))*np.exp(((-3+np.sqrt(5))/2)*t)
           +2/(5+3*np.sqrt(5))*np.exp(((-3-np.sqrt(5))/2)*t))


y0=[0,0] #Rownanie drugiego rzędu, zatem warunki początkowe y(0) i y'(0)

t=np.linspace(0,15,300) #zwiększamy horyzont czasowy, żeby objąć "ustalanie się" wykresu
y2=odeint(dydt2,y0,t) 
#Ponieważ rozwiązujemy układ równań otrzymujemy dwa rozwiązania 
#y jako rozwiązanie pierwszego równania oraz y' jako rozwiązanie drugiego
#ponieważ interesuje nas y bierzemy tylko pierwszą kolumnę rozwiązania, czyli y2[:,0]

# Wykresy
# plt.figure(2)
# plt.plot(t,y2[:,0],linewidth=4,label="solver")
# plt.plot(t,an2(t),'--',linewidth=4,label="analityczne")
# plt.grid()
# plt.legend()
# plt.show()


def dydt3(x,t):
  dydt=[0,0,0]
  dydt[0]=x[1]
  dydt[1]=x[2]
  dydt[2]=t**2*np.exp(-2*t)-16*x[2]-79*x[1]-120*x[0]
  return dydt

y0=[0,0,0]

def an3(t): #wyznaczone rozwiązanie analityczne
    return (1/18*np.exp(-2*t)*(t**2) - 1/6*np.exp(-2*t)*t + 61/324*np.exp(-2*t) -
             1/5*np.exp(-3*t) + 1/81*np.exp(-5*t) - 1/1620*np.exp(-8*t))

y3=odeint(dydt3,y0,t)

plt.figure(2)
plt.plot(t,y3[:,0],linewidth=2,label="solver")
plt.plot(t,an3(t),'--',linewidth=2,label="analityczne")
plt.grid()
plt.xlim(0,8)
plt.legend()
plt.show()