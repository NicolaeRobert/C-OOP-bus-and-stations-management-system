# 🚌 Bus, Routes, Stops and Tickets Management — OOP

## 🧩 Short Description
This project is an object-oriented (OOP) application that manages buses, routes, passengers, and tickets in a city.  
The system supports administration of urban and interurban buses, route management (stops), ticket purchasing, traveler history, and various reports.

---

## 🏙️ Classes and Attributes

### **City**
- **Attributes:**
  - `urban_buses` → list of `UrbanBus`
  - `interurban_buses` → list of `InterurbanBus`
- **Methods:**
  - `add_urban_bus()`
  - `show_urban_buses()`
  - `find_urban_route(destination)`
  - `add_interurban_bus()`
  - `show_interurban_buses()`
  - `find_interurban_route(destination)`

---

### **Bus**
- **Attributes:**
  - `bus_number`
  - `occupied`
  - `capacity`
  - `route` → `Route` object
- **Methods:**
  - `free_seats()`
  - `tickets_sold()`
  - `buy_ticket(passenger)`
  - `report()`

---

### **UrbanBus** *(inherits Bus)*
- **Attributes:**
  - `line_type` (normal, express, night)
- **Methods:**
  - `show_urban_route()`
  - `is_express()`
  - `report()`

---

### **InterurbanBus** *(inherits Bus)*
- **Attributes:**
  - `departure_city`
  - `arrival_city`
  - `travel_duration`
- **Methods:**
  - `show_interurban_route()`
  - `calculate_duration()`
  - `report()`

---

### **Route**
Represents the full route associated with a bus.

- **Attributes:**
  - `stops` → list of stops along the route
- **Methods:**
  - `show_stops()`
  - `stop_count()`

---

### **Ticket**
Represents a purchased ticket.

- **Attributes:**
  - `bus` → the bus for which the ticket was bought
  - `passenger` → person who bought the ticket
  - `purchase_date`
  - `price`
- **Methods:**
  - `ticket_info()`

---

### **Passenger**
- **Attributes:**
  - `name`
  - `email`
  - `purchased_tickets` → list of `Ticket`
- **Methods:**
  - `show_tickets()`
  - `add_ticket(ticket)`

---

## 📊 Class Relationship Diagram

```mermaid
classDiagram
    class City {
        +urban_buses
        +interurban_buses
        +add_urban_bus()
        +show_urban_buses()
        +find_urban_route(destination)
        +add_interurban_bus()
        +show_interurban_buses()
        +find_interurban_route(destination)
    }

    class Bus {
        +bus_number
        +occupied
        +capacity
        +route
        +free_seats()
        +tickets_sold()
        +buy_ticket(passenger)
        +report()
    }

    class UrbanBus {
        +line_type
        +show_urban_route()
        +is_express()
        +report()
    }

    class InterurbanBus {
        +departure_city
        +arrival_city
        +travel_duration
        +show_interurban_route()
        +calculate_duration()
        +report()
    }

    class Route {
        +stops
        +show_stops()
        +stop_count()
    }

    class Ticket {
        +bus
        +passenger
        +purchase_date
        +price
        +ticket_info()
    }

    class Passenger {
        +name
        +email
        +purchased_tickets
        +show_tickets()
        +add_ticket(ticket)
    }

    City "1" --> "*" UrbanBus : contains
    City "1" --> "*" InterurbanBus : contains

    UrbanBus "1" --|> Bus : inherits
    InterurbanBus "1" --|> Bus : inherits

    Bus "1" --> "1" Route : has

    Passenger "1" --> "*" Ticket : owns
    Ticket "1" --> "1" Bus : assigned_to

    Passenger "1" --> "1" City : registered_in
