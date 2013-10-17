#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void main(int argc,char **argv){

  
  if(argc<5){
    printf("Debe dar 4 argumentos correspondientes a:\n la posicion en X inicial\n la posicion en y inicial\n la velocidad en x inicial\n la velocidad en y inicial\n");
    exit(1);
}
  FILE *file;
  int i;
  float Vpx,Vpy,x,y;

  x=atof(argv[1]);
  y=atof(argv[2]);
  Vpx=atof(argv[3]);
  Vpy=atof(argv[4]);
  
  float pi=atan(1)*4;
  float teta1=2*pi/12;
  float teta2=2*pi/18;
  float teta3=2*pi/24;
  float teta4=2*pi/30;
  float teta5=2*pi/36;
  float masa=pow(10,12);
  float radio=10;
  float G=1;
  float velocidad=pow(masa*G/radio,1/2);
  float angulo1,angulo2,angulo3,angulo4,angulo5;

  file=fopen("datos iniciales","w");

  for(i=-1;i<100;i++){
    
    
    if(i=-1){
      //centro
      fprintf(file,"%d %lf %lf %lf ",-1 ,x,y,Vpx,Vpy);
    }
    
    if(i>-1 && i<=11){
      //12
      
      angulo1=teta1*(12-i);
      fprintf(file,"%d %lf %lf %lf %lf",i,radio*cos(angulo1)+x,1*radio*sin(angulo1)+y,Vpx+velocidad*cos(angulo1),Vpy+velocidad*sin(angulo1));
    }

    if(i>11 && i<=29){//18
      angulo2=teta2*(29-i);
      fprintf(file,"%d %lf %lf %lf %lf",i,radio*cos(angulo2)+x,2*radio*sin(angulo2)+y,Vpx+velocidad*cos(angulo2),Vpy+velocidad*sin(angulo2));
    }

    if(i>29 && i<=53){//24
      angulo3=teta3*(53-i);
      fprintf(file,"%d %lf %lf %lf %lf",i,radio*cos(angulo3)+x,3*radio*sin(angulo3)+y,Vpx+velocidad*cos(angulo3),Vpy+velocidad*sin(angulo3));
    }

     if(i>53 && i<=83){//30
       angulo4=teta4*(83-i);
      fprintf(file,"%d %lf %lf %lf %lf",i,radio*cos(angulo4)+x,4*radio*sin(angulo4)+y,Vpx+velocidad*cos(angulo4),Vpy+velocidad*sin(angulo4));
    }

     if(i>83 && i<=99){//36
       angulo5=teta5*(99-i);
      fprintf(file,"%d %lf %lf %lf %lf",i,radio*cos(angulo5)+x,5*radio*sin(angulo5)+y,Vpx+velocidad*cos(angulo5),Vpy+velocidad*sin(angulo5));
    }  


}
