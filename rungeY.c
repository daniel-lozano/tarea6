//Se define una funcion que calcula el runge kutta de Y

#include <stdio.h>
#include <math.h>
#include "prime.h"
//incluye prime 1 y 2 

float* rungeY(float fp1,float fp2,float paso){

  float h=paso;
  float k1,k2,k3,k4;
  float k11,k21,k31,k41;
  float x1,y1,x2,y2,x3,y3;
  float x11,y11,x21,y21,x31,y31;

  k1=primey1(fp1,fp2);
  k11=primey2(fp1,fp2);
  
  x1 = x + (h/2.0);
  y1 = y + (h/2.0)*k1;
 

  k2 = func_prime(x1, y1)
    
    #second step
    x2 = x[i-1] + (h/2.0)
    y2 = y[i-1] + (h/2.0) * k2
    k3 = func_prime(x2, y2)
        
    #third step
    x3 = x[i-1] + h
    y3 = y[i-1] + h * k3
    k4 = func_prime(x3, y3)
    
    #fourth step
    average_k = (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4)
    
    x[i] = x[i-1] + h
    y[i] = y[i-1] + h * average_k

}
