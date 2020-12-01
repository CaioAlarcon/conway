all:
	g++ *.cpp -o conway -pthread -lsfml-graphics -lsfml-window -lsfml-system
run:
	./conway
