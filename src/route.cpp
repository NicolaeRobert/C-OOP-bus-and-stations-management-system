#include <iostream>
#include "route.hpp"

using namespace std;

//The constructor
Route::Route(vector<string> stops){
    for(int i=0;i<stops.size();i++){
        this->stops.push_back(stops[i]);
    }
}

//The method that shows all the stops
void Route::show_stops(){
    cout<<"The stops for this bus are:"<<'\n';
    for(int i=0;i<this->stops.size();i++){
        cout<<i+1<<"."<<this->stops[i]<<"\n";
    }
    cout<<'\n'<<'\n';
}

//Method that shows the number of stops
void Route::no_of_stops(){
    cout<<"The number of stops for this bus are:"<<this->stops.size()<<'\n';
}

//The method used to see if a stop is in stops
bool Route::is_in_route(string stop){
    for(int i=0;i<this->stops.size();i++){
        if(this->stops[i]==stop){
            return true;
        }
    }
    return false;
}