#pragma once
#include <vector>
#include <string>
#include "buses.hpp"

class City{
    public:
        std::vector<Bus*> obj_buses;    //City ans intercity buses objects(for polimorphysm)
        void add_city_bus(std::string,std::string,int,int,std::vector<std::string>);    //Method that adds city buses
        void show_city_buses();    //Show city buses
        void look_for_city_route(std::string,std::string);   //Look for a route in city buses
        void add_intercity_bus(std::string,std::string,double,std::string,int,int,std::vector<std::string>);//Method that adds intercity buses
        void show_intercity_buses();   //Show intercity buses
        void look_for_intercity_route(std::string);  //Look for a route in intercity buses
        Bus* return_bus(int);   //Return a bus object
        ~City();    //Destructor
};