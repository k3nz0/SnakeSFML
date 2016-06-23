all:
	g++ -c *.hpp *.cpp && g++ *.o -o snake -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && ./snake
