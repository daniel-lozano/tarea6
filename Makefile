all : datos_iniciales.txt

datos_iniciales.txt: galaxia1 

galaxia1:ic.c
	cc ic.c -lm -o galaxia1
	./galaxia1 0 0 0 0
	mv datos_iniciales.txt datos_1.dat
	./galaxia1 150 200 -100.0 0
	mv datos_iniciales.txt datos_2.dat

	ipython notebook datos_iniciales_.ipynb &

	cc todo1.c -lm -o evolucion
	cc todo2.c -lm -o colision
	./evolucion
	./colision
clean:
	rm -f datos_iniciales.txt  galaxias.png galaxia1 galaxia2 2galaxias.png *.dat evolucion colision


