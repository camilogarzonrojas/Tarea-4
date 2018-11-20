all: primer_punto.png T1_final.png

primer_punto.png T1_final.png: dinamica* primera_parte bordes* puntos.txt
	python Plots_hw4.py

dinamica* primera_parte: ODE.cpp
	g++ ODE.cpp -o lanzamiento_de_proyectil.ejecutar
	./lanzamiento_de_proyectil.ejecutar

bordes* puntos.txt:
	g++ PDE.cpp -o difusion_en_calcita.ejecutar
	./difusion_en_calcita.ejecutar


clean:
	rm T*.png primer_punto.png dinamica* primera_parte bordes* puntos.txt *.ejecutar