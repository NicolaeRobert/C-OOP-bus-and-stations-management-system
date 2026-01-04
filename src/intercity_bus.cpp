#include <iostream>
#include "intercity_bus.hpp"

using namespace std;


//Constructor
Intercity_Bus::Intercity_Bus(int type,string departure_city,string destination_city,double time,string no_bus,int taken,int capacity,vector<string> route):Bus(type){
    this->no_bus=no_bus;
    this->taken=taken;
    this->capacity=capacity;
    this->departure_city=departure_city;
    this->destination_city=destination_city;
    this->time=time;
    this->obj_route=new Route(route);
}

//Tells us if there are available places in this bus
bool Intercity_Bus::availeable(){
    if(this->capacity==this->taken){
        return false;
    }
    return true;
}

//Tells us the number of available places
void Intercity_Bus::availeable_places(){
    cout<<"The number of available places in the intercity bus "<<this->no_bus<<" is: "<<this->capacity-this->taken<<'\n'<<'\n'; 
}

//Tells us how many tickets have been sold
void Intercity_Bus::tickets_sold(){
    cout<<"The number of tickets sold in the intercity bus "<<this->no_bus<<" is: "<<this->taken<<'\n'<<'\n'; 
}

//Method that adds one more ticket to taken
void Intercity_Bus::add_ticket(){
    this->taken++;
}

//Gives us a small raport about the bus
void Intercity_Bus::raport(){
    cout<<"No. of bus:"<<this->no_bus<<"    Taken places:"<<this->taken<<"    Capacity:"<<this->capacity<<'\n'<<'\n';
}

//Check if a stop is in a bus(used primarely for intercity)
bool Intercity_Bus::is_in_route(string destination){
    this->obj_route->is_in_route(destination);
}

//Return the number of the bus
std::string Intercity_Bus::return_no_of_bus(){
    return this->no_bus;
}

//Shows the route of the bus selected
void Intercity_Bus::show_route(){
    this->obj_route->no_of_stops();
    this->obj_route->show_stops();
}

//Method that shows the time taken for an interurban bus to get to the destination
void Intercity_Bus::time_of_travel(){
    cout<<"The estimated time for this travel is:"<<this->time<<'\n'<<'\n';
}

//Destructor that frees the memory for the obj_route
Intercity_Bus::~Intercity_Bus(){
    delete this->obj_route;
}