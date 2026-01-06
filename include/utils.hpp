#pragma once
#include "city.hpp"
#include "passenger.hpp"
#include <ctime>
#include <string>

int return_day();  //Return the current day
int return_month();  //Return the current month
int return_yeat();  //Return the current year
bool initialize_city(City*,int); //Initialize city
void get_info_user(std::string *,std::string *,int&); //Get neccessary info from the user
void app(City*,Passenger*);   //Execute the program