#ifndef BUS_H
#define BUS_H

#include <stdio.h>
#include <vector>
#include "Seat.h"
using namespace std;
class Bus{
private:
    int busId;//a unique id for each bus
    int capacity;//the maximum number of seat for this bus
    bool busIsAvailable;//this bus is avaliable or not
    int numberOfSeatsAvaliable;//the number of seats still be avaliable
    vector<Seat> seats;//the seats for this bus
public:
    Bus(int busId_, int capacity_, bool busIsAvailable_);
    void setBusId(int busId_);
    int getBusId();
    void setCapacity(int capacity_);
    int getCapacity();
    void setBusIsAvailable(bool busIsAvailable_);
    bool getBusIsAvailable();
    void setNumberOfSeatsAvailable(int numberOfSeatsAvaliable_);
    int getNumberOfSeatsAvailable();
    void setSeats(vector<Seat> seats_);
    vector<Seat> getSeats();
    /*******
     *@params seatId_ the seatId for reservation
     *@params passengerName_ the name of passenger
     *this function will make a reservation for passenger on this bus
     */
    void reserveASeatForBus(int seatId_, string passengerName_);
    /*******
     *@params seatId_ the seatId for reservation
     *@params passengerName_ the name of passenger
     *this function will cancel a reservation for passenger on this bus
     */
    void cancelReservationForASeatForBus(int seatId_, string passengerName_);
    /*******
     *Print information for one bus
     */
    void printBusInfo();
};
#endif 
