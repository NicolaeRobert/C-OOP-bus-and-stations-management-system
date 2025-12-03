#pragma once
#include <vector>
#include <string>
#include "buses.hpp"

class City{
    public:
        std::vector<City_Bus*> obj_city_buses;    //City bus objects
        std::vector<Intercity_Bus*> obj_intercity_buses; //Intercity bus objects
        void add_city_bus(std::string,std::string,int,int,std::vector<std::string>);    //Method that adds city buses
        void show_city_buses();    //Show city buses
        void look_for_city_route(std::string,std::string);   //Look for a route in city buses
        void add_intercity_bus(std::string,std::string,double,std::string,int,int,std::vector<std::string>);//Method that adds intercity buses
        void show_intercity_buses();   //Show intercity buses
        void look_for_intercity_route(std::string);  //Look for a route in intercity buses
        City_Bus* return_city_bus(int);   //Return a city bus object
        Intercity_Bus* return_intercity_bus(int); //Return an intercity bus object
        ~City();    //Destructor
};