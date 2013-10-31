all :a.out galaxia2

a.out: datos_iniciales.txt

datos_iniciales.txt:ic.c galaxia2

	cc ic.c -lm &
	./a.out 0 0 0 0 

galaxia2:ic2.c

	cc ic2.c -lm &
	./a.out

grafica: datos_iniciales.ipynb
	ipython notebook datos_iniciales.ipynb &

