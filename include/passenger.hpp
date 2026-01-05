#pragma once
#include <string>
#include <vector>
#include "ticket.hpp"
#include "buses.hpp"

class Passenger{
    private:
        std::string name;   //Nname
        std::string email;  //Email
        std::vector<Ticket*> tickets; //Tickets bought
    public:
        Passenger(std::string name,std::string email);    //Constructor
        void show_tickets_bought();   //Show the tickets that were bought
        void buy_ticket(Bus*,int,int,int,double);  //Method that allows us to buy a ticket(for city bus)
        ~Passenger();     //Destructor
};