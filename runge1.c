"""
se define una funcion llamada RungeX que define el metodo que llena a X 
"""

#include <stdio.h>
#include <math.h>
#include "prime.h"
//incluye prime 1 y 2 

float* runge1(float *fp1,float *fp2,float *tiempo,float paso, int indice,int i,float dato){

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
  if(indicie==0){
  //primer paso
    k1=primex1(fp1[i-1],fp2[i-1],tiempo[i-1],dato);
  k11=primex2(fp1[i-1],fp2[i-1],tiempo[i-1],dato);

  x1= tiempo[i-1]+h/2; 
  y1=fp1[i-1]+k1*h/2;
  y11=fp2[i-1]+k11*h/2;

  //segundo paso
  k2=primex1(x1,y1,dato);
  k21=primex2(x1,y11,dato);

  x2 = tiempo[i-1] + (h/2.0);
  y2 = fp1[i-1] + (h/2.0) * k2;
  y21 = fp2[i-1] + (h/2.0) * k21;
  
  //tercer paso      
  k3 = primex1(x2, y2,dato);
  k31 = primex2(x2, y21,dato);  
  
  x3 = tiempo[i-1] + h;
  y3 = fp1[i-1] + h * k3;
  y31 = fp2[i-1] + h * k31;
  //promedio 
  k4 = primex1(x3, y3,dato);
  k4 = primex2(x3, y31,dato);
  
  kprom1= (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
  kprom2= (1.0/6.0)*(k11 + 2.0*k21 + 2.0*k31 + k41);
    
  po[i] = x[i-1] + h;
  po2[i] = fp1[i-1] + h * average_k;
  po3[i] = fp2[i-1] + h * average_k;

  solucion[0]=po1;
  solucion[1]=po2;
  solucion[2]=po3;

  return solucion;
}
    
 
  // para Y caso 1------------------------------------------------------------------------------------

  if(indicie==1){
  //primer paso
  k1=primey1(fp1[i-1],fp2[i-1],tiempo[i-1]);
  k11=primey2(fp1[i-1],fp2[i-1],tiempo[i-1]);

  x1= tiempo[i-1]+h/2; 
  y1=fp1[i-1]+k1*h/2;
  y11=fp2[i-1]+k11*h/2;

  //segundo paso
  k2=primey1(x1,y1);
  k21=primey2(x1,y11);

  x2 = tiempo[i-1] + (h/2.0);
  y2 = fp1[i-1] + (h/2.0) * k2;
  y21 = fp2[i-1] + (h/2.0) * k21;
  
  //tercer paso      
  k3 = primey1(x2, y2);
  k31 = primey2(x2, y21);  
  
  x3 = tiempo[i-1] + h;
  y3 = fp1[i-1] + h * k3;
  y31 = fp2[i-1] + h * k31;
  //promedio 
  k4 = primey1(x3, y3);
  k4 = primey2(x3, y31);
  
  kprom1= (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
  kprom2= (1.0/6.0)*(k11 + 2.0*k21 + 2.0*k31 + k41);
    
  po[i] = x[i-1] + h;
  po2[i] = fp1[i-1] + h * average_k;
  po3[i] = fp2[i-1] + h * average_k;

  solucion[0]=po1;
  solucion[1]=po2;
  solucion[2]=po3;

  return solucion;
}
  

  
  


}
