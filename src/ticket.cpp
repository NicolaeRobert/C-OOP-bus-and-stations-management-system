#include <iostream>
#include "ticket.hpp"

using namespace std;

//The constructor
Ticket::Ticket(Bus *obj,int day, int month,int year,double price){
    this->obj_bus=obj;
    this->date.day=day;
    this->date.month=month;
    this->date.year=year;
    this->price=price;
}

//Methid that gives us info about a ticket
void Ticket::info_ticket(){
    if(this->obj_bus->type==2){
        cout<<"Intercity bus with plate no: "<<this->obj_bus->return_no_of_bus();
    }
    else{
        cout<<"City bus with plate no: "<<this->obj_bus->return_no_of_bus();
    }
    cout<<"   Bought on the date: "<<this->date.day<<'/'<<this->date.month<<'/'<<this->date.year;
    cout<<"   Price: "<<this->price<<'\n';
}