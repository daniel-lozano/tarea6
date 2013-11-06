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
float* runge1(float x,float vx,float y,float vy,float *tiempo,float paso,int i,float X,float Y);


int main(){

FILE *in;
  char letra;
  float *x0,*y0,*vx0,*vy0,*solucion1;
  float *tiempo;
  float X,Y,Vx,Vy;
  int lineas=0;
  int pasos=100000;
  int dimensiones=5;
  int *numero;
  int i,j,k,indice;
  float p=5000000/(pasos*5);

 
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


  printf("comienza el rungekutta \n");

  for(k=0;k<5;k++){

     for(i=1;i<pasos;i++){
    //tiempo

       for(j=1;j<lineas;j++){	
		
	 //masas
	
	 solucion1=runge1(x0[j],vx0[j],y0[j],vy0[j],tiempo,p,i,X,Y);
	
	
	 x0[j]=solucion1[1];
	 vx0[j]=solucion1[2];

	 y0[j]=solucion1[3];
	 vy0[j]=solucion1[4];
       }
     }

     //-----------------------------------------------------------------

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

//________________FUNCIONES______________________________________________]________________________________________


float primex1(float x,float vxp,float tiempo,float y,float X,float Y){
  return vxp;
}

float primex2(float x,float vxp,float tiempo,float y,float X,float Y){
  float G=4.46391*pow(10,-6);
  float M=pow(10,12);
  float a =-G*M*(x-X)*pow(pow(x-X,2)+pow(y-Y,2),-3/2);
  return a;
}

float primey1(float y,float vyp,float tiempo,float x,float X,float Y){
  return vyp;
}

float primey2(float y,float vyp,float tiempo,float x,float X,float Y){
  float G=4.46391*pow(10,-6);
  //=4.499866*pow(10,-9);
  float M=pow(10,12);
  float a =-G*M*(y-Y)*pow(pow(x-X,2)+pow(y-Y,2),-3/2);
  return a;
}



float* runge1(float x,float vx,float y,float vy,float *tiempo,float paso,int i,float X,float Y){

  // el indice indicara que derivada cogera si  X o Y, y si es el primer o segundo caso

  //X representara el tiempo y Y representara

  float h=paso;
  //k de x
  float kx1,kx2,kx3,kx4;
  float lx1,lx2,lx3,lx4;
  float kpromx,lpromx;

  //k de y

  float ky1,ky2,ky3,ky4;
  float ly1,ly2,ly3,ly4;
  float kpromy,lpromy;

  float t1,t2,t3;

  float x1,vx1,x2,vx2,x3,vx3;
  float y1,vy1,y2,vy2,y3,vy3;

  float po1,po2,po3,po4,po5;

  float *solucion;

  solucion=malloc(sizeof(float)*5);

  //primer paso X Y

  kx1=primex1(x,vx,tiempo[i-1],y,X,Y);
  lx1=primex2(x,vx,tiempo[i-1],y,X,Y);
  ky1=primey1(y,vy,tiempo[i-1],x,X,Y);
  ly1=primey2(y,vy,tiempo[i-1],x,X,Y);

  t1 = tiempo[i-1] + (h/2.0);
  x1=x + (h/2.0)*kx1;
  y1=y + (h/2.0)*ky1;
  vx1=vx + (h/2.0)*lx1;
  vy1=vy + (h/2.0)*ly1;
 
  //segundo paso X Y
 
  kx2=primex1(x1,vx1,t1,y1,X,Y);
  lx2=primex2(x1,vx1,t1,y1,X,Y);
  ky2=primey1(y1,vy1,t1,x1,X,Y);
  ly2=primey2(y1,vy1,t1,x1,X,Y);

  t2 = tiempo[i-1] + (h/2.0);
  x2=x + (h/2.0)*kx2;
  y2=y + (h/2.0)*ky2;
  vx2=vx + (h/2.0)*lx2;
  vy2=vy + (h/2.0)*ly2;
  
 //tercer paso X Y
 
  kx3=primex1(x2,vx2,t2,y2,X,Y);
  lx3=primex2(x2,vx2,t2,y2,X,Y);
  ky3=primey1(y2,vy2,t2,x2,X,Y);
  ly3=primey2(y2,vy2,t2,x2,X,Y);

  t3 = tiempo[i-1] + h;
  x3=x + h*kx3;
  y3=y + h*ky3;
  vx3=vx + h*lx3;
  vy3=vy + h*ly3;

  //cuarto paso X Y
 
  kx4=primex1(x3,vx3,t3,y3,X,Y);
  lx4=primex2(x3,vx3,t3,y3,X,Y);
  ky4=primey1(y3,vy3,t3,x3,X,Y);
  ly4=primey2(y3,vy3,t3,x3,X,Y);
 

  kpromx = (kx1 + 2.0*kx2 + 2*kx3 + kx4)/6.0;
  lpromx = (ky1 + 2.0*ky2 + 2*ky3 + ky4)/6.0;
  kpromy = (lx1 + 2.0*lx2 + 2*lx3 + lx4)/6.0;
  lpromy = (ly1 + 2.0*ly2 + 2*ly3 + ly4)/6.0;
  
  po1 = tiempo[i-1] + h;
  po2 = x + h*kpromx;
  po3 = vx + h*lpromx;
  po4 = y + h*kpromy;
  po5 = vy + h*lpromy;

  solucion[0]=po1;
  solucion[1]=po2;
  solucion[2]=po3;
  solucion[3]=po4;
  solucion[4]=po5;
  return solucion; 
}



