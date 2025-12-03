#include <iostream>
#include "city.hpp"

using namespace std;

//Method that adds city buses
void City::add_city_bus(string tip_linie,string numar_autobuz,int ocupate,int capacitate,vector<string> traseu){
    obj_city_buses.push_back(new City_Bus(tip_linie,numar_autobuz,ocupate,capacitate,traseu));
}

//Show city buses
void City::show_city_buses(){
    for(int i=0;i<obj_city_buses.size();i++){
        cout<<i+1<<". ";
        obj_city_buses[i]->raport();
    }
}

//Look for a route in city buses
void City::look_for_city_route(string plecare,string destinatie){
    vector<int> rezultat;
    int i;
    for(i=0;i<obj_city_buses.size();i++){
        if(obj_city_buses[i]->is_in_route(plecare,destinatie)==true){
            rezultat.push_back(i);
        }
    }
    if(rezultat.size()!=0){
        cout<<"This destionation exists and you can find it in the next buses:"<<'\n';
        for(i=0;i<rezultat.size();i++){
           cout<<obj_city_buses[rezultat[i]]->return_no_of_bus()<<'\n';
        }
    }
    else{
        cout<<"This destionation doesn't exists."<<'\n';
    }
    cout<<'\n';
}

//Method that adds intercity buses
void City::add_intercity_bus(string oras_plecare,string oras_sosire,double durata_calatorie,string numar_autobuz,int ocupate,int capacitate,vector<string> traseu){
    obj_intercity_buses.push_back(new Intercity_Bus(oras_plecare,oras_sosire,durata_calatorie,numar_autobuz,ocupate,capacitate,traseu));
}

//Show intercity buses
void City::show_intercity_buses(){
    for(int i=0;i<obj_intercity_buses.size();i++){
        cout<<i+1<<". ";
        obj_intercity_buses[i]->raport();
    }
}

//Look for a route in intercity buses
void City::look_for_intercity_route(string destinatie){
    vector<int> rezultat;
    int i;
    for(i=0;i<obj_intercity_buses.size();i++){
        if(obj_intercity_buses[i]->is_in_route(destinatie)==true){
            rezultat.push_back(i);
        }
    }
    if(rezultat.size()!=0){
        cout<<"This destionation exists and you can find it in the next buses:"<<'\n';
        for(i=0;i<rezultat.size();i++){
            cout<<obj_intercity_buses[rezultat[i]]->return_no_of_bus()<<'\n';
        }
    }
    else{
        cout<<"This destionation doesn't exists."<<'\n';
    }
    cout<<'\n';
}

//Return a city bus object
City_Bus* City::return_city_bus(int index){
    return obj_city_buses[index-1];
}

//Return an intercity bus object
Intercity_Bus* City::return_intercity_bus(int index){
    return obj_intercity_buses[index-1];
}

//Destructor
City::~City(){
    for(int i=0;i<obj_city_buses.size();i++){
        delete obj_city_buses[i];
    }
    obj_city_buses.clear();

    for(int i=0;i<obj_intercity_buses.size();i++){
        delete obj_intercity_buses[i];
    }
    obj_intercity_buses.clear();
}