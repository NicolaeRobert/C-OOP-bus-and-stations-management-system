#pragma once
#include "buses.hpp"

//Structure that defines the date
struct Date{
    int day;
    int month;
    int year;
};

class Ticket{
    private:
        Bus *obj_bus;  //Object city and intercity bus
        Date date;  //The date when the ticket was bought
        double price;    //Price
    public:
        Ticket(Bus*,int,int,int,double);   //Constructor
        void info_ticket();  //Shows info about a ticket
};