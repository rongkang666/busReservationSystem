#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>
using namespace std;
class Seat{
private:
    int seatId;//seat Id, unique
    bool isReserved;//is reserved or not
    string passengerName;//name for passenger make the reservation
public:
    Seat();
    Seat(int seatId_, bool isReserved_, string passengerName_);
    void setSeatId(int seatId_);
    int getSeatId();
    bool getIsReserved();
    string getPassengerName();
    /****
     *@params passengerName_ name for passenger make the reservation
     *check if this seat is still available, then make the reservation
     *return true when the reserve successfullt
     */
    bool reserveOneSeat(string passengerName_);
    /****
     *@params passengerName_ name for passenger cancel the reservation
     *check if the information are correct, then cancel the reservation
     *return true when the cancel successfullt
     */
    bool cancalReservationForOneSeat(int seatId_, string passengerName_);
};
#endif 
