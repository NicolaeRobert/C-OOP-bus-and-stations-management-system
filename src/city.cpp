#include <iostream>
#include "city.hpp"
#include "city_bus.hpp"
#include "intercity_bus.hpp"

using namespace std;

//Method that adds city buses
void City::add_city_bus(string type_of_line,string no_bus,int taken,int capacity,vector<string> route){
    obj_buses.push_back(new City_Bus(1,type_of_line,no_bus,taken,capacity,route));
}

//Show city buses
void City::show_city_buses(){
    int nr=1;
    for(int i=0;i<obj_buses.size();i++){
        if(obj_buses[i]->type==1){
            cout<<nr<<". ";
            nr++;
            obj_buses[i]->raport();
        }
    }
}

//Look for a route in city buses
void City::look_for_city_route(string plecare,string destinatie){
    vector<int> rezultat;
    int i;
    for(i=0;i<obj_buses.size();i++){
        if(obj_buses[i]->type==1&&obj_buses[i]->is_in_route(plecare,destinatie)==true){
            rezultat.push_back(i);
        }
    }
    if(rezultat.size()!=0){
        cout<<"This destionation exists and you can find it in the next buses:"<<'\n';
        for(i=0;i<rezultat.size();i++){
           cout<<obj_buses[rezultat[i]]->return_no_of_bus()<<'\n';
        }
    }
    else{
        cout<<"This destionation doesn't exists."<<'\n';
    }
    cout<<'\n';
}

//Method that adds intercity buses
void City::add_intercity_bus(string departure_city,string destination_city,double time,string no_bus,int taken,int capacity,vector<string> route){
    obj_buses.push_back(new Intercity_Bus(2,departure_city,destination_city,time,no_bus,taken,capacity,route));
}

//Show intercity buses
void City::show_intercity_buses(){
    int nr=1;
    for(int i=0;i<obj_buses.size();i++){
        if(obj_buses[i]->type==2){
            cout<<nr<<". ";
            nr++;
            obj_buses[i]->raport();
        }
    }
}

//Look for a route in intercity buses
void City::look_for_intercity_route(string destinatie){
    vector<int> rezultat;
    int i;
    for(i=0;i<obj_buses.size();i++){
        if(obj_buses[i]->type==2&&obj_buses[i]->is_in_route(destinatie)==true){
            rezultat.push_back(i);
        }
    }
    if(rezultat.size()!=0){
        cout<<"This destionation exists and you can find it in the next buses:"<<'\n';
        for(i=0;i<rezultat.size();i++){
            cout<<obj_buses[rezultat[i]]->return_no_of_bus()<<'\n';
        }
    }
    else{
        cout<<"This destionation doesn't exists."<<'\n';
    }
    cout<<'\n';
}

//Return a city bus object
Bus* City::return_bus(int index){
    return obj_buses[index-1];
}

//Destructor
City::~City(){
    for(int i=0;i<obj_buses.size();i++){
        delete obj_buses[i];
    }
    obj_buses.clear();
}