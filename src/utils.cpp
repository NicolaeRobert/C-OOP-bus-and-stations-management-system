#include <iostream>
#include <fstream>
#include "utils.hpp"
#include "buses.hpp"

using namespace std;

//The function that return the current day
int return_day(){
    //Get the raw time from the system(seconsds from 1 January 1970)
    time_t t = time(nullptr);

    //Convert those seconds into a structure(year, month, day, etc.)
    tm* now = localtime(&t);

    //tm_mday = the current day (1–31)
    int day = now->tm_mday;

    return day;
}

//The function that returns the current month
int return_month(){
    //Get the raw time from the system(seconsds from 1 January 1970)
    time_t t = time(nullptr);

    //Convert those seconds into a structure(year, month, day, etc.)
    tm* now = localtime(&t);

    //tm_mon = the months from 0 to 11
    int month = now->tm_mon + 1;
    
    return month;
}

//The function that returns the current year
int return_year(){
    //Get the raw time from the system(seconsds from 1 January 1970)
    time_t t = time(nullptr);

    //Convert those seconds into a structure(year, month, day, etc.)
    tm* now = localtime(&t);

    //tm_year = the number of years from 1900 to now
    int year = now->tm_year + 1900;

    return year;
}

//Functie care initializeaza orasele
bool initialize_city(City *city,int index){
    //Depending of the index sent we read from a respective file
    ifstream fin;
    if(index==1){
        fin.open("data/data_city_craiova.txt");
    }
    else if(index==2){
        fin.open("data/data_city_bucuresti.txt");
    }
    else{
        fin.open("data/data_city_timisoara.txt");
    }

    //Check if the file has been opened correctly, otherwise show a message of error
    if (!fin.is_open()) {
        cout << "Error at the opening of the file!\n";
        return false;
    }

    //Declare and read the number of city busses
    int no_buses;
    fin>>no_buses;

    //Pentru fiecare se creaza un obiect autobuz urban
    for(int i=0;i<no_buses;i++){
        //The variables that we read from the file for a single city bus object
        string type_of_line,no_bus;
        int taken,capacity;
        vector<string> route;

        //Reading the variables
        fin>>type_of_line>>no_bus;
        fin>>taken>>capacity;

        int no_stops;
        fin>>no_stops;
        fin.ignore();

        string stop;
        for(int j=0;j<no_stops;j++){
            getline(fin,stop);
            route.push_back(stop);
        }

        //Create the object
        city->add_city_bus(type_of_line,no_bus,taken,capacity,route);
    }

    //Read for intercity busses
    fin>>no_buses;//number of intercity buses

    //Create the objects intercity buses
    for(int i=0;i<no_buses;i++){
        //The variables that we read for an object
        string departure_city,arival_city;
        double time;
        string no_bus;
        int taken,capacity;
        vector<string> route;

        //Reading the variables
        fin>>departure_city>>arival_city;
        fin>>time;
        fin>>no_bus;
        fin>>taken>>capacity;

        int no_stops;
        fin>>no_stops;
        fin.ignore();

        string stop;
        for(int j=0;j<no_stops;j++){
            getline(fin,stop);
            route.push_back(stop);
        }

        //Create the object
        city->add_intercity_bus(departure_city,arival_city,time,no_bus,taken,capacity,route);
    }

    //Close the file
    fin.close();

    return true;
}

//Functia care ia informatia initiala de la user(nume, email si orasul ales)
void get_info_user(string *name,string *email,int &index){
    string user_name;
    string user_email;

    cout<<"Thank you for choosing our app. Before we start we need some info:"<<'\n';
    cout<<"Name:";
    getline(cin,user_name);
    cout<<'\n'<<"Email:";
    cin>>user_email;
    cout<<'\n';

    *name=user_name;
    *email=user_email;

    cout<<"Now that we have the info we can start by choosing a city:"<<'\n'<<'\n';
    cout<<"1.Craiova"<<'\n';
    cout<<"2.Bucuresti"<<'\n';
    cout<<"3.Timisoara"<<'\n'<<'\n';

    cout<<"Introduce a number from 1 to 3 in order to specify the city, or -1 to stop the program."<<'\n';
    cout<<"Number:";
    cin>>index;
    while(index<1||index>3){
        if(index==-1){
            break;
        }
        cout<<"The number introduced is wrong. Introduce a new one between 1 and 3, or -1 if you want to stop the program."<<'\n';
        cout<<"Number:";
        cin>>index;
    }
}

//The function that executes the program
void app(City *city,Passenger *passenger){
    int input=0;

    //Execute the app until the user sais to stop
    while(input!=14){
        //Show the possibilities that he can do
        cout<<"Introduce a number from 1 to 14 depending of what you want the program to do."<<'\n';
        cout<<"The program has the next options:"<<'\n'<<'\n';
        cout<<"1.Show city buses."<<'\n';
        cout<<"2.Show intercity buses."<<'\n';
        cout<<"3.Look for a city stop."<<'\n';
        cout<<"4.Look for an intercity stop."<<'\n';
        cout<<"5.Empty places to a certain bus."<<'\n';
        cout<<"6.Tickets sold to a certain bus."<<'\n';
        cout<<"7.Raport to a bus."<<'\n';
        cout<<"8.Buy tickets."<<'\n';
        cout<<"9.Show tickets bought."<<'\n';
        cout<<"10.See if a bus is express line."<<'\n';
        cout<<"11.See the time for an intercity bus."<<'\n';
        cout<<"12.Show the route of a certain city bus."<<'\n';
        cout<<"13.Show the route of a certain intercity bus."<<'\n';
        cout<<"14.Stop the program."<<'\n'<<'\n';
        cout<<"Number:";
        cin>>input;
        cout<<'\n';

        //Validate the input
        while(input<1||input>14){
            cout<<"The number is not valid."<<'\n';
            cout<<"Introduce a number from 1 to 14."<<'\n'<<'\n';
            cout<<"Number:";
            cin>>input;
            cout<<'\n';
        }

        //The input cases
        if(input==1){
            city->show_city_buses();
        }
        else if(input==2){
            city->show_intercity_buses();
        }
        else if(input==3){
            string garbage;
            getline(cin,garbage);
            string departure,arrival;
            cout<<"Departure:";
            getline(cin,departure);
            cout<<'\n';
            cout<<"Arival:";
            getline(cin,arrival);
            cout<<'\n';
            city->look_for_city_route(departure,arrival);
        }
        else if(input==4){
            string destination;
            cout<<"Detination:";
            cin>>destination;
            cout<<'\n';
            city->look_for_intercity_route(destination);
        }
        else if(input==9){
            passenger->show_tickets_bought();
        }
        else if(input==10||input==12){
            int index_bus;

            cout<<"City busses:"<<'\n';
            city->show_city_buses();
            cout<<'\n';

            cout<<"Introduce the number of the bus wanted(from 1 to 5)."<<'\n';
            cout<<"Number:";
            cin>>index_bus;
            cout<<'\n';
            while(index_bus<1||index_bus>5){
                cout<<"Invalid number. Introduce another one(from 1 to 5)."<<'\n';
                cout<<"Number:";
                cin>>index_bus;
                cout<<'\n';
            }

            Bus *obj=city->return_bus(index_bus);

            if(input==10){
                obj->express_line();
            }
            else if(input==12){
                obj->show_route();
            }

        }
        else if(input==11||input==13){
            int index_bus;

            cout<<"Intercity buses:"<<'\n';
            city->show_intercity_buses();
            cout<<'\n';

            cout<<"Introduce the number of the bus wanted(from 1 to 5)."<<'\n';
            cout<<"Number:";
            cin>>index_bus;
            cout<<'\n';
            while(index_bus<1||index_bus>5){
                cout<<"Invalid number. Introduce another one(from 1 to 5)."<<'\n';
                cout<<"Number:";
                cin>>index_bus;
                cout<<'\n';
            }

            Bus *obj=city->return_bus(index_bus+5);

            if(input==11){
                obj->time_of_travel();
            }
            else if(input==13){
                obj->show_route();
            }
        }
        else if(input!=14){
            int type_of_bus,index_bus;
            cout<<"Introduce 1 for city bus and 2 for intercity bus."<<'\n';
            cout<<"Number:";
            cin>>type_of_bus;
            cout<<'\n';

            while(type_of_bus<1||type_of_bus>2){
                cout<<"Invalid number. Introduce another one that can be 1 or 2."<<'\n';
                cout<<"Number:";
                cin>>type_of_bus;
                cout<<'\n';
            }

            if(type_of_bus==1){
                cout<<"City buses:"<<'\n';
                city->show_city_buses();
                cout<<'\n';
            }
            else{
                cout<<"Intercity buses:"<<'\n';
                city->show_intercity_buses();
                cout<<"\n";
            }
            cout<<"Introduce a numbert that reprezents the bus choosen(no. from 1 to 5)."<<'\n';
            cout<<"Number:";
            cin>>index_bus;
            cout<<'\n';
            while(index_bus<1||index_bus>5){
                cout<<"Invalid number. Introduce another one(from 1 to 5)."<<'\n';
                cout<<"Number:";
                cin>>index_bus;
                cout<<'\n';
            }
            
            if(input==5){    
                if(type_of_bus==1){
                    Bus *obj=city->return_bus(index_bus);
                    obj->availeable_places();
                }
                else{
                    Bus *obj=city->return_bus(index_bus+5);
                    obj->availeable_places();
                }
            }
            else if(input==6){
                if(type_of_bus==1){
                    Bus *obj=city->return_bus(index_bus);
                    obj->tickets_sold();
                }
                else{
                    Bus *obj=city->return_bus(index_bus+5);
                    obj->tickets_sold();
                }
            }
            else if(input==7){
                if(type_of_bus==1){
                    Bus *obj=city->return_bus(index_bus);
                    obj->raport();
                }
                else{
                    Bus *obj=city->return_bus(index_bus+5);
                    obj->raport();
                }
            }
            else if(input==8){
                if(type_of_bus==1){
                    Bus *obj=city->return_bus(index_bus);
                    if(obj->availeable()==false){
                        cout<<"The bus is full. Can't buy a ticket."<<'\n'<<'\n';
                    }
                    else{
                        passenger->buy_ticket(obj,return_day(),return_month(),return_year(),4.5);
                        obj->add_ticket();
                    }
                }
                else{
                    Bus *obj=city->return_bus(index_bus+5);
                    if(obj->availeable()==false){
                        cout<<"The bus in full. Can't buy a ticket."<<'\n'<<'\n';
                    }
                    else{
                        passenger->buy_ticket(obj,return_day(),return_month(),return_year(),55.0);
                        obj->add_ticket();
                    }
                }
            }
        }
    }
}