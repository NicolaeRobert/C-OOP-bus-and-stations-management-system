#pragma once
#include <string>
#include <vector>
#include "route.hpp"
#include "buses.hpp"

class Intercity_Bus:public Bus{
    private:
        std::string no_bus;      //Bus plate number
        int taken;        //No. of taken places
        int capacity;     //Total no. of places
        std::string departure_city;   //Departure city
        std::string destination_city;    //Destionation city
        double time;    //The time neccessary for the travel
        Route *obj_route;     //Route object
    public:
        Intercity_Bus(int,std::string,std::string,double,std::string,int,int,std::vector<std::string>);  //Constructor
        bool availeable() override;     //Tells us if there are available places in this bus
        void availeable_places() override;   //Tells us the number of available places
        void tickets_sold() override;  //Tells us how many tickets have been sold
        void add_ticket() override;    //Method that adds one more ticket to taken
        void raport() override;      //Gives us a small raport about the bus
        bool is_in_route(std::string) override;     //Check if a stop is in a bus(used primarely for intercity)
        std::string return_no_of_bus() override;   //Return the number of the bus
        void show_route() override;  //Shows the route of the bus selected
        void time_of_travel() override; //Method that shows the time taken for an interurban bus to get to the destination
        ~Intercity_Bus() override;     //Destructor that frees the memory for the obj_route
};