#pragma once
#include <string>
#include <vector>

class Route{
    private:
        std::vector<std::string> stops; //Stops
    public:
        Route(std::vector<std::string>);   //Constructor
        void show_stops(); //Method that shows all the stops
        void no_of_stops();    //Method that shows the number of stops
        bool is_in_route(std::string); //Method where we check if a route exist
};