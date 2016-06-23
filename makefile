all:
	g++ -c include/*.hpp src/*.cpp && g++ *.o -o snake -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./snake
