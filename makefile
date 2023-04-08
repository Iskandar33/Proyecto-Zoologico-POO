all: compiler
compiler: Sistema Habitat Animal Main
	g++ -o papu Sistema.o Animal.o Habitat.o Main.o
Sistema: Sistema.cpp Sistema.h
	g++ -c Sistema.cpp
Animal: Animal.cpp Animal.h
	g++ -c Animal.cpp
Habitat: Habitat.cpp Habitat.h
	g++ -c Habitat.cpp
Main: Main.cpp
	g++ -c Main.cpp