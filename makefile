all: busReservation

busReservation: main.o seat.o bus.o
	g++ main.o seat.o bus.o -o busReservation 

main.o: main.cpp
	g++ -c main.cpp 

seat.o: Seat.cpp
	g++ -c Seat.cpp 

bus.o: Bus.cpp
	g++ -c Bus.cpp

clean:
	rm *.o busReservation
