#pragma once
#include <string>
#include <vector>
#include "route.hpp"

class Bus{
    private:
        std::string no_bus;      //Bus plate number
        int taken;        //No. of taken places
        int capacity;     //Total no. of places
    protected:
        Route *obj_route;     //Route object
    public:
        Bus(std::string,int,int,std::vector<std::string>);  //Constructor
        bool availeable();     //Tells us if there are available places in this bus
        void availeable_places();   //Tells us the number of available places
        void tickets_sold();  //Tells us how many tickets have been sold
        void add_ticket();    //Method that adds one more ticket to taken
        void raport();      //Gives us a small raport about the bus
        bool is_in_route(std::string);     //Check if a stop is in a bus(used primarely for intercity)
        bool is_in_route(std::string,std::string); //Check if a pair(departure-destination) exists(used primarely for city)
        std::string return_no_of_bus();   //Return the number of the bus
        ~Bus();     //Destructor
};

class City_Bus:public Bus{
    private:
        std::string type_of_line;  //Type of line
    public:
        City_Bus(std::string,std::string,int,int,std::vector<std::string>);    //Constructor
        void show_city_route();     //Show the route
        void express_line();       //Show if a line is express or not
};

class Intercity_Bus:public Bus{
    private:
        std::string departure_city;   //Departure city
        std::string destination_city;    //Destionation city
        double time;    //The time neccessary for the travel
    public:
        Intercity_Bus(std::string,std::string,double,std::string,int,int,std::vector<std::string>);    //Constructor
        void show_intercity_route();   //Show the route
        void show_time();   //Show the time neccessary for the travel
};