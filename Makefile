all :a.out grafica

a.out: datos_iniciales.txt

datos_iniciales.txt: ic.c

	cc ic.c -lm
	./a.out 0 0 0 0 

grafica: datos_iniciales.ipynb
	ipython notebook datos_iniciales.ipynb &

