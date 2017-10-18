#include <string>
#include <iostream>
#include "Seat.h"

using namespace std;

Seat::Seat(int seatId_, bool isReserved_, string passengerName_){
    seatId = seatId_;
    isReserved = isReserved_;
    passengerName = passengerName_;
}

void Seat::setSeatId(int seatId_){
    seatId = seatId_;
}

int Seat::getSeatId(){
    return seatId;
}

bool Seat::getIsReserved(){
    return isReserved;
}

string Seat::getPassengerName(){
    return passengerName;
}

bool Seat::reserveOneSeat(string passengerName_){
    //if it is reserved, this reservation can not be done
    if(isReserved){
        cout << "Sorry, this seat is not available" << endl;
        return false;
    }else{
        //otherwise make the reservation and print a successful message
        isReserved = true;
        passengerName = passengerName_;
        cout << "Successfully!" << endl;
        return true;
    }
}

bool Seat::cancalReservationForOneSeat(int seatId_, string passengerName_){
    //if the information is correct, cancel the reservation
    if(seatId == seatId_ && passengerName == passengerName_){
        isReserved = false;
        passengerName = "";
        return true;
    }else{
        //otherwise print a fail message and return false
        cout << "Sorry, the seat id or the name of passenger is not the same as the reservation, this reservation can"
         << "not be canceled" << endl;
        return false;
    }
}
