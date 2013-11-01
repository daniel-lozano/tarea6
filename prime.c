#include <stdio.h>
#include <math.h>

float G=1;
float M=1;

float primex1(float x,float xp,float tiempo,float y,float X,float Y){
  return xp;
}

float primex2(float x,float xp,float tiempo,float y,float X,float Y){

  float a =-G*M*(x-X)*pow(pow(x-X,2)+pow(y-Y,2),-3/2);
  return a;
}

float primey1(float y,float yp,float tiempo,float x,float X,float Y){
  return yp;
}

float primey2(float y,float yp,float tiempo,float x,float X,float Y){

  float a =-G*M*(y-Y)*pow(pow(x-X,2)+pow(y-Y,2),-3/2);
  return a;
}

