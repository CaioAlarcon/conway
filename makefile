all:
	g++ *.cpp -o prog -pthread -lsfml-graphics -lsfml-window -lsfml-system
run:
	./prog
