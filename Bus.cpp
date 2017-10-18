#include <string>
#include <iostream>
#include "Bus.h"

using namespace std;

Bus::Bus(int busId_, int capacity_, bool busIsAvailable_){
    busId = busId_;
    capacity = capacity_;
    busIsAvailable = busIsAvailable_;
    numberOfSeatsAvaliable = capacity_;
    seats = vector<Seat>();
    for(int i=0;i<capacity;i++){
        Seat seat(i,false,"");
        seats.push_back(seat);
    }
}

void Bus::setBusId(int busId_){
    busId = busId_;
}

int Bus::getBusId(){
    return busId;
}

void Bus::setCapacity(int capacity_){
    capacity = capacity_;
}

int Bus::getCapacity(){
    return capacity;
}

void Bus::setBusIsAvailable(bool busIsAvailable_){
    busIsAvailable = busIsAvailable_;
}

bool Bus::getBusIsAvailable(){
    return busIsAvailable;
}

void Bus::setNumberOfSeatsAvailable(int numberOfSeatsAvaliable_){
    numberOfSeatsAvaliable = numberOfSeatsAvaliable_;
}

int Bus::getNumberOfSeatsAvailable(){
    return numberOfSeatsAvaliable;
}

void Bus::setSeats(vector<Seat> seats_){
    seats = seats_;
}

vector<Seat> Bus::getSeats(){
    return seats;
}

void Bus::reserveASeatForBus(int seatId_, string passengerName_){
    if(seats[seatId_].reserveOneSeat(passengerName_)){
        //make reservation successfuly. one seat is not avaliable anymore
        numberOfSeatsAvaliable--;
    }
}

void Bus::cancelReservationForASeatForBus(int seatId_, string passengerName_){
    if(seats[seatId_-1].cancalReservationForOneSeat(seatId_, passengerName_)){
        //cancel reservation successfuly. one seat is avaliable again
        numberOfSeatsAvaliable++;
    }
}

void Bus::printBusInfo(){
    for(int i=0;i<seats.size();i++){
        //for each seat, if it is reserved, print the name, otherwise print empty
        if(seats[i].getIsReserved()){
            cout << seats[i].getPassengerName() << "\t";
        }else{
            cout << "Empty" << "\t";
        }
        if((i+1)%4==0){
            cout << endl;
        }
    }
}









