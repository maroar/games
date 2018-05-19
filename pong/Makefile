all: exec

pong.exe:
	g++ -c main.cpp -std=c++11
	g++ main.o -o pong.exe -lsfml-graphics -lsfml-window -lsfml-system

exec: pong.exe
	./pong.exe

clean:
	rm *.o *.exe
