pithread=pi_montecarlo
proj=driver
all:
	gcc -c $(pithread).cpp $(driver).cpp
	gcc -o driver -g $(pithread).cpp $(driver).cpp