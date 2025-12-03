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
        City_Bus *obj_autobuz_urban;   //Object city bus
        Intercity_Bus *obj_autobuz_interurban;  //Object intercity bus
        Date date;  //The date when the ticket was bought
        double price;    //Price
    public:
        Ticket(City_Bus*,int,int,int,double);   //Constructor
        Ticket(Intercity_Bus*,int,int,int,double);  //Constructor
        void info_ticket();  //Shows info about a ticket
};