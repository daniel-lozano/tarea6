#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//Este es el esqueleto del segundo punto, lee condiciones iniciales, usa Runge Kutta 4 orden
/**
*infile: datos_iniciales.txt
*outfiles: 
* evolucion1.txt
* evolucion2.txt
* evolucion3.txt
* evolucion4.txt
* evolucion5.txt
**/
//--------------------------------------------------------------
float primex1(float x,float xp,float tiempo,float y,float X,float Y);
float primex2(float x,float xp,float tiempo,float y,float X,float Y);
float primey1(float y,float yp,float tiempo,float x,float X,float Y);
float primey2(float y,float yp,float tiempo,float x,float X,float Y);
float* runge1(float fp1,float fp2,float *tiempo,float paso, int indice,int i,float dato,float X,float Y);


int main(){

  FILE *in;
  char letra;
  float *x0,*y0,*vx0,*vy0,*solucion1,*solucion2;
  float *tiempo;
  float X,Y,Vx,Vy;
  int lineas=0;
  int pasos=100000;
  int dimensiones=3;
  int *numero;
  int i,j,k,indice;
  float p=5000000/pasos;

 
  in=fopen("datos_1.dat","r");

  if(!(in=fopen("datos_1.dat","r"),"r")){
    printf("problemas cargando el archivo \n");
    exit(1);    
    }

 
  printf("contando numero de masas\n");
  printf("pasos %d\n",pasos);
  printf("dt= %f\n",p);
  //cuenta las lineas

  do{
    letra = fgetc(in);
   

    if(letra=='\n'){
      lineas++;
    }

  }while(letra!=EOF);
  rewind(in);
  
  
  //se crea un arreglo de soluciones-----------------------------------

  printf("%d lineas del archivo\n",lineas);
  
  //creacion de arrays para la posicion y velocidad iniciales
  //x0, y0, vx0, vy0
  //ya sabemos que hay 120 lineas


  //alocacion de memoria para cada array


  x0 = malloc(lineas * sizeof(float));
  y0 = malloc(lineas * sizeof(float));
  vx0 = malloc(lineas * sizeof(float));
  vy0= malloc(lineas * sizeof(float));
  numero= malloc(lineas * sizeof(int));
  tiempo=malloc(sizeof(float)*pasos);
  solucion1=malloc(sizeof(float)*dimensiones); 
  solucion2=malloc(sizeof(float)*dimensiones); 

  FILE *evol1;
  FILE *evol2;
  FILE *evol3;
  FILE *evol4;
  FILE *evol5;
  
  evol1=fopen("1000_anos.dat","w");
  evol2=fopen("2000_anos.dat","w");
  evol3=fopen("3000_anos.dat","w");
  evol4=fopen("4000_anos.dat","w");
  evol5=fopen("5000_anos.dat","w");
  

 

  //escaneando datos y guardando en arrays
  //guardando los datos en las filas correspondientes


  for (k=0; k <lineas; k++){
	
    fscanf(in,"%d %f %f %f %f\n",&numero[k],&(x0[k]),&(y0[k]),&(vx0[k]),&(vy0[k])); 
   
}
  X=x0[0];
  Y=y0[0];
  Vx=vx0[0];
  Vy=vy0[0];
  printf("posiciones X=%f Y=%f\n",X,Y);
  printf("velocidades VX=%f VY=%f\n",Vx,Vy);
 
 
  for(i=0;i<pasos;i++){
    tiempo[i]=i;

  } 

  printf("inicilializando el tiempo  \n");

  printf("comienza el rungekutta \n");

  for(k=0;k<5;k++){

     for(i=1;i<pasos;i++){
    //tiempo

       for(j=1;j<lineas;j++){	
		
	 //masas
	 indice=0;
	 solucion1=runge1(x0[j],vx0[j],tiempo,p,indice,j,y0[j],X,Y);
	 indice=1;
	 solucion2=runge1(y0[j],vy0[j],tiempo,p,indice,j,x0[j],X,Y);

	 x0[j]=solucion1[1];
	 vx0[j]=solucion1[2];

	 y0[j]=solucion2[1];
	 vy0[j]=solucion2[2];
       }
     }

     printf("%d \n",k+1);
     for(i=0;i<121;i++){
	    
       if(k==0){
	 fprintf(evol1,"%d %f %f %f %f\n",i-1,x0[i],vx0[i],y0[i],vy0[i]);
	
       }
       if(k==1){	 
	 fprintf(evol2,"%d %f %f %f %f\n",i-1,x0[i],vx0[i],y0[i],vy0[i]);
      
       }
       if(k==2){
	  fprintf(evol3,"%d %f %f %f %f\n",i-1,x0[i],vx0[i],y0[i],vy0[i]);
       }
       if(k==3){
	  fprintf(evol4,"%d %f %f %f %f\n",i-1,x0[i],vx0[i],y0[i],vy0[i]);
       }

       if(k==4){
	  fprintf(evol5,"%d %f %f %f %f\n",i-1,x0[i],vx0[i],y0[i],vy0[i]);
       }

  }


}




return 0;
}

//________________FUNCIONES______________________________________________-


float primex1(float x,float vxp,float tiempo,float y,float X,float Y){
  return vxp;
}

float primex2(float x,float vxp,float tiempo,float y,float X,float Y){
  float G=4.499866*pow(10,-9);
  float M=pow(10,12);
  float a =-G*M*(x-X)*pow(pow(x-X,2)+pow(y-Y,2),-3/2);
  return a;
}

float primey1(float y,float vyp,float tiempo,float x,float X,float Y){
  return vyp;
}

float primey2(float y,float vyp,float tiempo,float x,float X,float Y){
  float G=4.499866*pow(10,-9);
  float M=pow(10,12);
  float a =-G*M*(y-Y)*pow(pow(x-X,2)+pow(y-Y,2),-3/2);
  return a;
}



float* runge1(float x,float vx,float *tiempo,float paso, int indice,int i,float dato,float X,float Y){

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
  k1=primex1(x,vx,tiempo[i-1],dato,X,Y);
  k11=primex2(x,vx,tiempo[i-1],dato,X,Y);

  x1= tiempo[i-1]+h/2; 
  y1=x+k1*h/2;
  y11=vx+k11*h/2;

  //segundo paso
  k2=primex1(y1,y11,tiempo[i-1],dato,X,Y);
  k21=primex2(y1,y11,tiempo[i-1],dato,X,Y);

  x2 = tiempo[i-1] + (h/2.0);
  y2 = x + (h/2.0) * k2;
  y21 = vx + (h/2.0) * k21;
  
  //tercer paso      
  k3 = primex1(y2,y21,tiempo[i-1],dato,X,Y);
  k31 = primex2(y2,y21,tiempo[i-1],dato,X,Y);  
  
  x3 = tiempo[i-1] + h;
  y3 = x + h * k3;
  y31 = vx + h * k31;
  //promedio 
  k4 = primex1(y3,y31,tiempo[i-1],dato,X,Y);
  k4 = primex2(y3,y31,tiempo[i-1],dato,X,Y);
  
  //promedio
  kprom1= (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
  kprom2= (1.0/6.0)*(k11 + 2.0*k21 + 2.0*k31 + k41);
    
  po1 = tiempo[i-1] + h;
  po2 = x + h *kprom1;
  po3 = vx + h *kprom2;

  solucion[0]=po1;
  solucion[1]=po2;
  solucion[2]=po3;

  return solucion;
}
    
 
  // para Y caso 1------------------------------------------------------------------------------------

  if(indice==1){
  //primer paso
  k1=primey1(x,vx,tiempo[i-1],dato,X,Y);
  k11=primey2(x,vx,tiempo[i-1],dato,X,Y);

  x1= tiempo[i-1]+h/2; 
  y1=x+k1*h/2;
  y11=vx+k11*h/2;

  //segundo paso
  k2=primey1(y1,y11,tiempo[i-1],dato,X,Y);
  k21=primey2(y1,y11,tiempo[i-1],dato,X,Y);

  x2 = tiempo[i-1] + (h/2.0);
  y2 = x + (h/2.0) * k2;
  y21 = vx + (h/2.0) * k21;
  
  //tercer paso      
  k3 = primey1(y2,y21,tiempo[i-1],dato,X,Y);
  k31 = primey2(y2,y21,tiempo[i-1],dato,X,Y);  
  
  x3 = tiempo[i-1] + h;
  y3 = x + h * k3;
  y31 = vx + h * k31;
  //promedio 
  k4 = primey1(y3,y31,tiempo[i-1],dato,X,Y);
  k4 = primey2(y3,y31,tiempo[i-1],dato,X,Y);
  
  kprom1= (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
  kprom2= (1.0/6.0)*(k11 + 2.0*k21 + 2.0*k31 + k41);
    
  po1 = tiempo[i-1] + h;
  po2 = x + h * kprom1;
  po3 = vx + h * kprom2;

  solucion[0]=po1;
  solucion[1]=po2;
  solucion[2]=po3;

  return solucion;
}
 
}


//----------------------------------------------------------------------
