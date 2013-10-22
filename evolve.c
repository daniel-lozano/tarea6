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

void main(){
do{
    letra = fgetc(in);
    if(letra=='\n'){
      lineas++;
    }
  }while(letra!=EOF);
  
  fclose(in);
  return lineas;
  
//creacion de arrays para la posicion y velocidad iniciales
//x0, y0, vx0, vy0
//ya sabemos que hay 120 lineas

float *x0;
float *y0;
float *vx0;
float *vy0;

int i,j,k;
//alocacion de memoria para cada array

x0 = malloc(lineas * sizeof(float));
y0 = malloc(lineas * sizeof(float));
vx0 = malloc(lineas * sizeof(float));
vy0= malloc(lineas * sizeof(float));

//escaneando datos y guardando en arrays
//guardando los datos en las filas correspondientes
  for (k=0; k <lineas; k++){
	
    fscanf(in, "%f %f %f %f\n",&(x0[k]),&(y0[k]),&(vx0[k]),&(vy0[k]); 
  }
  fclose(in);

}

/**
 * como se trata de una ecuacion dif. de segundo orden 
 * d^2r/dt^2= -J(1/r^2)
 * donde J=GM
 * r1'=r2
 * r2'=-k(1/r1^2)
 * */
 
//definiendo r1 y r2

int lineas = contar_lineas(datos_iniciales.txt[1]);
float *r1;
float *r2;

r1 = malloc(lineas * sizeof(float));
r2 = malloc(lineas * sizeof(float));

 
int func_prime_1(r1,r2){
	return r2;
	
}

int func_prime2(r1,r2){
	J=1;
	return -J*(1/pow(r1,2));
} 


int main runge_kutta_4(){
	
	//variable de salto
	int h;
	int k1,k2,k3,k4;
	
	
	
	//esta funcion desarrolla el metodo de Runge Kutta de 4 orden
	
	//aqui se llama al numero de lineas
	int lineas = contar_lineas(datos_iniciales.txt[1]);ev

}

void evoluciones(){
	//esta funcion crea los 4 archivos de evoluciones
	//para imprimir en los archivos de texto fprintf(file,bla bla bla)
	
	
	evol1=fopen("evolucion1.txt","w");
	evol2=fopen("evolucion2.txt","w");
	evol3=fopen("evolucion3.txt","w");
	evol4=fopen("evolucion4.txt","w");
	evol5=fopen("evolucion5.txt","w");
	
	
	
	
}


//metodo para sacar Ro y Vo ------------------------------

int radio_velocidad(char *datos_iniciales){
	
	int lineas = contar_lineas(datos_iniciales.txt[1]);
	
	float *ro;
	float *vo;
	ro = malloc(lineas * sizeof(float));
	vo = malloc(lineas * sizeof(float));
	
	
	for(i=0; i<lineas; i++){
		ro[i]=sqrt(pow(x0[i],2)+pow(y0[i],2));
		vo[i]=sqrt(pow(vx0[i],2)+pow(vy0[i],2));
	}
	
	
}


int sacar_columnas(char *datos_iniciales.txt){
	
	in = fopen(datos_iniciales.txt, "r");
	  if(!in){
		printf("problems opening the file %s\n", datos_iniciales.txt);
		exit(1);
  }
}
