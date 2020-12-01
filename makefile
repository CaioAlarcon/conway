all:
	g++ *.cpp -lpthread -lsfml-graphics -lsfml-window -lsfml-system -std=gnu++11  -o prog 
run:
	./prog
