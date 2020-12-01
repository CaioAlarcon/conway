all:
	g++ *.cpp -o prog -lsfml-graphics -lsfml-window -lsfml-system -std=gnu++11 -W -g
run:
	./prog
