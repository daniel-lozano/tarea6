%pylab inline
import matplotlib.pyplot as plt
import numpy as np
from numpy import pi

archivo=np.loadtxt(open("datos_iniciales.txt","r"))
#se guardan los datos iniciales
x=archivo[:,1]
y=archivo[:,2]
vx=archivo[:,3]
vy=archivo[:,4]


#orbita 1, prueva de si estan bien 
x1=np.empty(12)
vx1=np.empty(12)
y1=np.empty(12)
vy1=np.empty(12)
#orbita 1 
for i in range (12):
    x1[i]=x[i+1]
    y1[i]=y[i+1]
    vx1[i]=vx[i+1]
    vy1[i]=vy[i+1]

plot(x1,y1,"ro",label="Posiciones")

legend()
xlabel("X")
ylabel("Y")
xlim(-15,15)
ylim(-15,15)
plt.show()
plt.close()

plot(vx1,label="vx")
plot(vy1,label="vy")
legend()
xlabel("Vx")
ylabel("Vy")
#xlim(-15,15)
#ylim(-15,15)
plt.show()
plt.close()

plot(x,y)
title("Puntos")
xlabel("X")
ylabel("Y")
plt.show()
plt.close()
plot(x,y,"ko")
title("Puntos")
xlabel("X")
ylabel("Y")
ylim(-100,100)
xlim(-100,100)
plt.show()
plt.close()
plot(x,y,"go")
title("Puntos")
xlabel("X")
ylabel("Y")

plot(vx,vy)
plt.show()
plt.close()
plot(vx,label="vx")
plot(vy,label="vy")
legend()
plt.show()
plt.close()

v=vx+vy
plot(v,"ro")
plot(v)
