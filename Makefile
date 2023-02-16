main: knights.o
	g++ -o main knights.o

knights.o: knights.cpp

clean:
	rm -f knights.o