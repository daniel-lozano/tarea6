all : datos_iniciales.txt

datos_iniciales.txt: galaxia1 

galaxia1:ic.c
	cc ic.c -lm -o galaxia1
	./galaxia1 0 0 0 0
	mv datos_iniciales.txt datos_1.dat
	./galaxia1 150000 200000 -100000 0
	mv datos_iniciales.txt datos_2.dat
	ipython notebook datos_iniciales_.ipynb &
	cc todo1.c -lm -o evolucion
	./evolucion
	cc todo2.c -lm -o colicion
	./colicion
clean:
	rm -f datos_iniciales.txt datos_iniciales_galaxia2.txt galaxias.png galaxia1 galaxia2 2galaxias.png *.dat evolucion


