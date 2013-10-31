#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//el siguiente programa calcula las condiciones iniciales para la primera galaxia

void main(){

  FILE *file;
  int i;
  float Vpx,Vpy,x,y;

  x=150;
  y=200;
  Vpx=-100;
  Vpy=0;
  //indica el tiempo que ocurre


  
  int cuerpos=120;
  float pi=atan(1)*4;
  float teta1=2*pi/12;
  float teta2=2*pi/18;
  float teta3=2*pi/24;
  float teta4=2*pi/30;
  float teta5=2*pi/36;
  float masa=1;
  float radio=10;
  float G=1;
  float velocidad=pow(masa*G/radio,1/2);
  float angulo1,angulo2,angulo3,angulo4,angulo5;
  printf("variables guardadas\n");
  file=fopen("datos_iniciales_galaxia2.txt","w");

  for(i=-1;i<cuerpos;i++){
    
  
    if(i==-1){//centro de la galaxia
      //centro
      fprintf(file,"%d %lf %lf %lf %f\n",i ,x,y,Vpx,Vpy);
      
    }
    // fprintf(file,"%d\n",i);
    if(i>-1 && i<=11){//12
     
      angulo1=teta1*(12-i);
      fprintf(file,"%d %lf %lf %lf %lf\n",i,radio*cos(angulo1)+x,1*radio*sin(angulo1)+y,Vpx+velocidad*cos(angulo1),Vpy+velocidad*sin(angulo1));
      //  fprintf(file,"%d\n",i);
    }

    if(i>11 && i<=29){//18
      angulo2=teta2*(29-i);
      fprintf(file,"%d %lf %lf %lf %lf\n",i,2*radio*cos(angulo2)+x,2*radio*sin(angulo2)+y,Vpx+pow(1/2,1/2)*velocidad*cos(angulo2),Vpy+velocidad*pow(1/2,1/2)*sin(angulo2));
    }

    if(i>29 && i<=53){//24
      angulo3=teta3*(53-i);
      fprintf(file,"%d %lf %lf %lf %lf\n",i,3*radio*cos(angulo3)+x,3*radio*sin(angulo3)+y,Vpx+velocidad*cos(angulo3)*pow(1/3,1/2),Vpy+velocidad*sin(angulo3)*pow(1/3,1/2));
    }

     if(i>53 && i<=83){//30
       angulo4=teta4*(83-i);
      fprintf(file,"%d %lf %lf %lf %lf\n",i,4*radio*cos(angulo4)+x,4*radio*sin(angulo4)+y,Vpx+velocidad*cos(angulo4)*pow(1/4,1/2),Vpy+velocidad*sin(angulo4)*pow(1/4,1/2));
    }

     if(i>83 && i<=cuerpos-1){//36
       angulo5=teta5*(99-i);
       fprintf(file,"%d %lf %lf %lf %lf \n",i,5*radio*cos(angulo5)+x,5*radio*sin(angulo5)+y,Vpx+velocidad*cos(angulo5)*pow(1/5,1/2),Vpy+velocidad*sin(angulo5)*pow(1/5,1/2));
    }  


  }

}
