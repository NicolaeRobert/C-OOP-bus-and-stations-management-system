#pragma once
#include <string>
#include <vector>
#include "route.hpp"
#include "buses.hpp"

class City_Bus:public Bus{
    private:
        std::string no_bus;      //Bus plate number
        int taken;        //No. of taken places
        int capacity;     //Total no. of places
        std::string type_of_line;  //Type of line
        Route *obj_route;     //Route object
    public:
        City_Bus(int,std::string,std::string,int,int,std::vector<std::string>);  //Constructor
        bool availeable() override;     //Tells us if there are available places in this bus
        void availeable_places() override;   //Tells us the number of available places
        void tickets_sold() override;  //Tells us how many tickets have been sold
        void add_ticket() override;    //Method that adds one more ticket to taken
        void raport() override;      //Gives us a small raport about the bus
        bool is_in_route(std::string,std::string) override; //Check if a pair(departure-destination) exists(used primarely for city)
        std::string return_no_of_bus() override;   //Return the number of the bus
        void show_route() override;  //Shows the route of the bus selected
        void express_line() override; //Method that shows if an urban bus is express or not
        ~City_Bus() override;     //Destructor that frees the memory for the obj_route

};