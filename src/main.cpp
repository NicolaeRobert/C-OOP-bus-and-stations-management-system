#include <iostream>
#include <vector>
#include <string>
#include "city.hpp"
#include "passenger.hpp"
#include "utils.hpp"

using namespace std;

int main(){
    //Declare the vector that hold all the cities
    vector<City*> city;
    //Create the cities
    city.push_back(new City);//Craiova
    city.push_back(new City);//Bucuresti
    city.push_back(new City);//Timisoara
    
    //Initialize the cities
    if(initialize_city(city[0],1)&&initialize_city(city[1],2)&&initialize_city(city[2],3)){

        //Get the info of the user and choose a city
        int index;
        string *name=new string;
        string *email=new string;
        get_info_user(name,email,index);

        //Create the user and free the temporarely used memory
        Passenger *passenger=new Passenger(*name,*email);
        delete name;
        delete email;

        //If index is -1 then stop, otherwise execute the app
        if(index!=-1){
            app(city[index-1],passenger);
        }

        //Free the memory user(heap)
        delete city[0];
        delete city[1];
        delete city[2];
    }

    return 0;
}