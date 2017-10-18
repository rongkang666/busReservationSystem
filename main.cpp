#include <iostream>
#include <vector>
#include "Bus.h"
#include "Seat.h"
#include <vector>
using namespace std;
/*****
 *@params input the input from user
 *@params min the min valid number
 *@params max the max valid number
 *Check if the user's input is valid or not
 *return true when input is valid
 */
bool userInputIsValid(string input, int min, int max);

/*****
 *@params buses a vector of buses
 *Main menu for user
 */
void mainMenu(vector<Bus> &buses);

/*****
 *@params buses a vector of buses
 *Menu for adding a bus
 */
void addABus(vector<Bus> &buses);

/*****
 *@params buses a vector of buses
 *Menu for making a reservation
 */
void reservation(vector<Bus> &buses);

/*****
 *@params buses a vector of buses
 *Menu for show information of bus
 */
void showBusInfo(vector<Bus> &buses);

int main() {
    vector<Bus> buses;//save the information for all buses in this system
    mainMenu(buses);
    return 0;
}

bool userInputIsValid(string input, int min, int max){
    try {
        string errorMsg = "Choice must be a number between " + to_string(min) + "~" + to_string(max) + ".";
        //the maximum option number is 4 in this system,
        //if the length of string is more than 1, then it must be a invalid input
        if(input.length()>1){
            throw invalid_argument(errorMsg);
        }
        //check the number is between the range
        int userChoice = stoi(input);
        if(min<=userChoice && userChoice<=max){
            return true;
        }else{
            throw invalid_argument(errorMsg);
        }
    } catch (invalid_argument e) {
        cout << e.what() << endl;//print out the error message
        cout << "Press Enter to continue." << endl;
        getchar();
        return false;
    }
}

void mainMenu(vector<Bus> &buses){
    int userChoice = 0;
    //main menu content
    while(userChoice != 4){
        string input = "";
        cout << "Welcome to bus reservation system" << endl;
        cout << "1. Add a bus" << endl;
        cout << "2. Reservation" << endl;
        cout << "3. Show buses information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (a number): " << endl;
        getline(cin, input);
        //check user's input
        if(userInputIsValid(input,1,4)){
            userChoice = stoi(input);
            if(userChoice == 1){
                addABus(buses);
            }else if(userChoice == 2){
                reservation(buses);
            }else if(userChoice == 3){
                showBusInfo(buses);
            }
        }else{
            //if invalid, reset choice to 0 and refresh the main menu
            userChoice = 0;
        }
    }
}


void addABus(vector<Bus> &buses){
    string input;
    int userChoice = 0;
    int capacity = 0;
    bool busIsAvailable = true;
    do{
        //get ID for new bus
        int busId = buses.size();
        //initilize new bus according to user's input
        cout << "You can add a new bus at here." <<
        " The Id for the new bus will be: " << busId << endl;
        cout << "Enter the bus capacity: ";
        cin >> capacity;
        cout << "Is this bus available now? (1 for Yes, 0 for No): " << endl;
        cin >> input;
        if(stoi(input) == 1){
            busIsAvailable = true;
        }else if(stoi(input) == 0){
            busIsAvailable = false;
        }
        //build new bus and add it into vector
        Bus newBus = Bus(busId, capacity, busIsAvailable);
        buses.push_back(newBus);
        getchar();
        cout << "You have create your new bus" << endl;
        cout << "1. Return to the main menu" << endl;
        cout << "2. Add another new bus" << endl;
        cout << "Enter your choice (a number): " << endl;
        getline(cin, input);
        if(userInputIsValid(input,1,2)){
            userChoice = stoi(input);
            if(userChoice == 1){
                return;
            }
        }else{
            cout << "returning to main menu" << endl;
            return;
        }
    }while(userChoice == 2);
}

void reservation(vector<Bus> &buses){
    int busId = 0;
    int seatId = 0;
    string passengerName;
    string input;
    int userChoice = 0;
    int capacity = 0;
    bool busIsAvailable = true;
    do{
        //get the busId and seatId to make reservation
        cout << "You can reserve a seat for one bus at here." << endl;
        cout << "Enter the bus Id: ";
        cin >> busId;
        cout << "Enter the seat Id: ";
        cin >> seatId;
        cout << "Enter the passenger's name: " << endl;
        getchar();
        getline(cin, passengerName);
        //check if the bus is exist
        if(busId > buses.size()){
            cout << "This bus is not exist" << endl;
            userChoice = 2;
            continue;
        }
        //check if the seat is exist on this bus
        if(seatId >= buses[busId].getCapacity()){
            cout << "This seat is not exist" << endl;
            userChoice = 2;
            continue;
        }
        //make reservation
        buses[busId].reserveASeatForBus(seatId, passengerName);
        cout << "What do you want to do?" << endl;
        cout << "1. Return to the main menu" << endl;
        cout << "2. Make another reservation" << endl;
        cout << "Enter your choice (a number): " << endl;
        getline(cin, input);
        if(userInputIsValid(input,1,2)){
            userChoice = stoi(input);
            if(userChoice == 1){
                return;
            }
        }else{
            cout << "returning to main menu" << endl;
            return;
        }
    }while(userChoice == 2);
}

void showBusInfo(vector<Bus> &buses){
    string input;
    int userChoice = 0;
    do{
        //show infomation for all bus at here
        cout << "here is bus info:" << endl;
        for(int i=0;i<buses.size();i++){
            cout << "Bus id: " << buses[i].getBusId() << endl;
            buses[i].printBusInfo();
            cout << endl;
        }
        cout << "What do you want to do?" << endl;
        cout << "1. Return to the main menu" << endl;
        cout << "2. Show information again" << endl;
        cout << "Enter your choice (a number): " << endl;
        getline(cin, input);
        if(userInputIsValid(input,1,2)){
            userChoice = stoi(input);
            if(userChoice == 1){
                return;
            }
        }else{
            cout << "returning to main menu" << endl;
            return;
        }
    }while(userChoice == 2);

}
