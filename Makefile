pithread=pi_montecarlo
proj=driver
std=base

all:
	g++ -c $(pithread).cpp $(proj).cpp
	g++ -o driver -g -pthread $(pithread).o $(proj).o
driver:
	g++ -c $(std).cpp
	g++ -o $(proj) -g -pthread $(std).o
clean:
	rm *.o