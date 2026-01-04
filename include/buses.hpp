#pragma once
#include <string>
#include <vector>

class Bus{
    public:
        int type; //type=1 means that the bus is urban and 2 means it is interurban
        Bus(int);  //Constructor
        virtual bool availeable() = 0;     //Tells us if there are available places in this bus
        virtual void availeable_places() = 0;   //Tells us the number of available places
        virtual void tickets_sold() = 0;  //Tells us how many tickets have been sold
        virtual void add_ticket() = 0;    //Method that adds one more ticket to taken
        virtual void raport() = 0;      //Gives us a small raport about the bus
        virtual bool is_in_route(std::string) {};     //Check if a stop is in a bus(used primarely for intercity)
        virtual bool is_in_route(std::string,std::string) {}; //Check if a pair(departure-destination) exists(used primarely for city)
        virtual std::string return_no_of_bus() = 0;   //Return the number of the bus
        virtual void show_route() = 0;  //Shows the route of the bus selected
        virtual void express_line() {}; //Method that shows if an urban bus is express or not
        virtual void time_of_travel() {}; //Method that shows the time taken for an interurban bus to get to the destination
        virtual ~Bus() = 0;     //Destructor
};