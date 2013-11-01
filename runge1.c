"""
se define una funcion llamada RungeX que define el metodo que llena a X y Y
"""

#include <stdio.h>
#include <math.h>
#include "prime.h"

//incluye prime 1 y 2 

float* runge1(float *fp1,float *fp2,float *tiempo,float paso, int indice,int i,float dato,float X,float Y){

  // el indice indicara que derivada cogera si  X o Y, y si es el primer o segundo caso

  //X representara el tiempo y Y representara

  float h=paso;
  float k1,k2,k3,k4;
  float k11,k21,k31,k41;
  float kprom1,kprom2;
  float x1,y1,x2,y2,x3,y3;
  float y11,y21,y31;
  float po1,po2,po3;
  float *solucion;

  solucion=malloc(sizeof(float)*3);

  //Para X en el caso 1
  if(indice==0){

  //primer paso
  k1=primex1(fp1[i-1],fp2[i-1],tiempo[i-1],dato,X,Y);
  k11=primex2(fp1[i-1],fp2[i-1],tiempo[i-1],dato,X,Y);

  x1= tiempo[i-1]+h/2; 
  y1=fp1[i-1]+k1*h/2;
  y11=fp2[i-1]+k11*h/2;

  //segundo paso
  k2=primex1(y1,y11,tiempo[i-1],dato,X,Y);
  k21=primex2(y1,y11,tiempo[i-1],dato,X,Y);

  x2 = tiempo[i-1] + (h/2.0);
  y2 = fp1[i-1] + (h/2.0) * k2;
  y21 = fp2[i-1] + (h/2.0) * k21;
  
  //tercer paso      
  k3 = primex1(y2,y21,tiempo[i-1],dato,X,Y);
  k31 = primex2(y2,y21,tiempo[i-1],dato,X,Y);  
  
  x3 = tiempo[i-1] + h;
  y3 = fp1[i-1] + h * k3;
  y31 = fp2[i-1] + h * k31;
  //promedio 
  k4 = primex1(y3,y31,tiempo[i-1],dato,X,Y);
  k4 = primex2(y3,y31,tiempo[i-1],dato,X,Y);
  
  //promedio
  kprom1= (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
  kprom2= (1.0/6.0)*(k11 + 2.0*k21 + 2.0*k31 + k41);
    
  po1 = tiempo[i-1] + h;
  po2 = fp1[i-1] + h *kprom1;
  po3 = fp2[i-1] + h *kprom2;

  solucion[0]=po1;
  solucion[1]=po2;
  solucion[2]=po3;

  return solucion;
}
    
 
  // para Y caso 1------------------------------------------------------------------------------------

  if(indice==1){
  //primer paso
   k1=primey1(fp1[i-1],fp2[i-1],tiempo[i-1],dato,X,Y);
  k11=primey2(fp1[i-1],fp2[i-1],tiempo[i-1],dato,X,Y);

  x1= tiempo[i-1]+h/2; 
  y1=fp1[i-1]+k1*h/2;
  y11=fp2[i-1]+k11*h/2;

  //segundo paso
  k2=primey1(y1,y11,tiempo[i-1],dato,X,Y);
  k21=primey2(y1,y11,tiempo[i-1],dato,X,Y);

  x2 = tiempo[i-1] + (h/2.0);
  y2 = fp1[i-1] + (h/2.0) * k2;
  y21 = fp2[i-1] + (h/2.0) * k21;
  
  //tercer paso      
  k3 = primey1(y2,y21,tiempo[i-1],dato,X,Y);
  k31 = primey2(y2,y21,tiempo[i-1],dato,X,Y);  
  
  x3 = tiempo[i-1] + h;
  y3 = fp1[i-1] + h * k3;
  y31 = fp2[i-1] + h * k31;
  //promedio 
  k4 = primey1(y3,y31,tiempo[i-1],dato,X,Y);
  k4 = primey2(y3,y31,tiempo[i-1],dato,X,Y);
  
  kprom1= (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
  kprom2= (1.0/6.0)*(k11 + 2.0*k21 + 2.0*k31 + k41);
    
  po1 = tiempo[i-1] + h;
  po2 = fp1[i-1] + h * kprom1;
  po3 = fp2[i-1] + h * kprom2;

  solucion[0]=po1;
  solucion[1]=po2;
  solucion[2]=po3;

  return solucion;
}
 
}
