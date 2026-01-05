#include <iostream>
#include "passenger.hpp"

using namespace std;

//The constructor
Passenger::Passenger(string name,string email){
    this->name=name;
    this->email=email;
}

//The method where we show the tickets bought
void Passenger::show_tickets_bought(){
    if(this->tickets.size()==0){
        cout<<"There are no tickets bought"<<'\n'<<'\n';
    }
    else{
        for(int i=0;i<this->tickets.size();i++){
            this->tickets[i]->info_ticket();
        }
        cout<<'\n';
    }
}

//The method that allows us to buy a ticket
void Passenger::buy_ticket(Bus *obj, int day,int month,int year,double price){
    this->tickets.push_back(new Ticket(obj, day, month, year, price));
}

//The destructor
Passenger::~Passenger(){
    for(int i=0;i<this->tickets.size();i++){
        delete this->tickets[i];
    }
}