#include <stdio.h>
#include <math.h>

float G=1;
float M=1;

float primex1(float x,float xp,float tiempo,float y){
  return xp;
}

float primex2(float x,float xp,float tiempo,float y){

  float a =G*M*cos(atan(y/x))*pow(pow(x,2)+pow(y,2),-1);
  return a;
}

float primey1(float y,float yp,float tiempo,float x){
  return yp;
}

float primey2(float y,float yp,float tiempo,float x){

  float a =G*M*sin(atan(y/x))*pow(pow(x,2)+pow(y,2),-1);
  return a;
}

