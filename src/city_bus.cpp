#include <iostream>
#include "city_bus.hpp"

using namespace std;

//Constructor
City_Bus::City_Bus(int type,string type_of_line,string no_bus,int taken,int capacity,vector<std::string> route):Bus(type){
    this->no_bus=no_bus;
    this->taken=taken;
    this->capacity=capacity;
    this->type_of_line=type_of_line;
    this->obj_route=new Route(route);
}

//The method that tells us if there are any available places
bool City_Bus::availeable(){
    if(this->capacity==this->taken){
        return false;
    }
    return true;
}

//Method that tells is how many empty places still are in the bus
void City_Bus::availeable_places(){
    cout<<"The number of available places in the city bus "<<this->no_bus<<" is: "<<this->capacity-this->taken<<'\n'<<'\n'; 
}

//The method that tells us how many tickets were sold
void City_Bus::tickets_sold(){
    cout<<"The number of tickets sold in the city bus "<<this->no_bus<<" is: "<<this->taken<<'\n'<<'\n'; 
}

//The method that adds a ticket to the taken parameter
void City_Bus::add_ticket(){
    this->taken++;
}

//The method that gives a raport about the bus
void City_Bus::raport(){
    cout<<"No. of bus:"<<this->no_bus<<"    Taken places:"<<this->taken<<"    Capacity:"<<this->capacity<<'\n'<<'\n';
}

//Yhe method that tells us if there are any routes for the input
bool City_Bus::is_in_route(string departure,string destination){
    return (obj_route->is_in_route(departure)&&obj_route->is_in_route(destination));
}

//The method that returns the no of the bus
std::string City_Bus::return_no_of_bus(){
    return this->no_bus;
}

//The method that shows a route
void City_Bus::show_route(){
    this->obj_route->no_of_stops();
    this->obj_route->show_stops();
}

//The method that shows if a line is express or not
void City_Bus::express_line(){
    if(this->type_of_line=="EXPRESS"){
        cout<<"This is an express line"<<'\n'<<'\n';
    }
    else{
        cout<<"This is not an express line. It is a normal line."<<'\n'<<'\n';
    }
}

//The destructor that frees the obj_route
City_Bus::~City_Bus(){
    delete this->obj_route;
}