<!-- ABOUT THE PROJECT -->
## About The Project
Restaurant Order Management System

## Overview
This project is a simple simulation of a Diner Dash-style game implemented in C++. It follows the Single Responsibility Principle (SRP) by structuring the code into multiple classes, each handling a specific aspect of the game. The main components of the simulation include:

Classes :
Customer: Represents a customer in the restaurant. Manages emotions and orders.
Table: Manages the status of a table and the customer assigned to it.
Kitchen: Responsible for preparing and serving food orders.
OrderManager: Coordinates the interaction between customers, tables, and the kitchen, managing the order flow.

Features :
Order Management: Customers can place orders, and the system tracks the status of the order (Not Yet Taken, In Kitchen, Served).
Customer Emotion: The customer's emotional level decreases as they wait for their order and resets once the order is served.
Waiter Actions: The waiter takes the order, sends it to the kitchen, and delivers it when ready.
Table Management: Each table is associated with a customer, and the order status for the table is displayed dynamically.
Delayed Actions : This code has chrono to make the code more realisatic when preparing the orders.


<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Class Explanation
Class Breakdown

### 1. Customer Class
The Customer class represents an individual customer in the simulation. It holds information about the customer's emotional state, order, and a unique identifier (number).

Members:
Private Members:

int number: Represents the customer's unique identifier.
int emotions: Represents the customer's emotional state, which ranges from 0 (angry) to 5 (happy).
std::string order: The order that the customer places.
Public Members:

Constructor: Initializes the customer's number and optionally their emotional state (default is 5).
Getters and Setters:
getEmotions(): Returns the current emotional state.
setEmotions(int emotionValue): Sets the emotional state while ensuring it does not exceed 5.
decreaseEmotions(int amount): Decreases the emotional state by a specified amount, ensuring it does not fall below 0.
Order Management:
setOrder(const std::string& newOrder): Sets the order for the customer.
getOrder() const: Returns the customer's order.
Customer Information:
getNumber() const: Returns the customer's unique identifier.
printStatus() const: Prints the customer's current emotional state and order status.

### 2. Kitchen Class
The Kitchen class is responsible for preparing and serving the orders placed by customers.

Members:
Public Methods:
std::string prepareOrder(const std::string& order): Simulates the preparation of an order with a delay, and returns the prepared order.
std::string giveOrder(const std::string& order): Simulates serving the order with a delay, and returns the served order.

### 3. Table Class
The Table class manages a collection of customers seated at the table.

Members:
Private Members:

std::vector<Customer*> customers: A dynamic list of pointers to Customer objects.
Public Methods:

void setCustomer(Customer* customer): Adds a customer to the table's list.
void printTableStatus() const: Iterates over all customers and prints their status.
const std::vector<Customer*>& getCustomers() const: Returns a reference to the list of customers at the table.

### 4. OrderManager Class
The OrderManager class is responsible for managing the flow of order processing between the customers and the kitchen.

Members:
Private Members:

Kitchen& kitchen: A reference to the Kitchen instance for order preparation and serving.
Table& table: A reference to the Table instance that holds the customers.
Public Methods:

Constructor: Initializes the OrderManager with references to the Kitchen and Table instances.
void processOrders(): Manages the order processing by iterating over the customers at the table, preparing their orders, serving them, and adjusting their emotional states based on their queue position.

### Built With

Visual Code Studio

How to Build and Run
1. Open dinerdash.cpp file
2. Copy raw code in dinerdash.cpp 
3. Compile the code using a C++ compiler.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Getting Started

How the Code Works
Customer and Table Assignment: A customer is created and assigned to a table. The customer places an order, which is associated with the table.
Waiter Interaction: A waiter takes the order from the table and simulates sending it to the kitchen. While the customer waits, their emotion level decreases. Once the kitchen finishes preparing the order, the waiter delivers it, and the customer’s emotion level is reset.
Modular Design: Each class is responsible for a specific part of the functionality, making the code easy to extend or modify without affecting other parts of the system.

Additional Features: The system could be extended to include a notification system using the Observer Pattern to inform the customer when their order status changes.

## Contact
  
Your Name - Ibrahim Ar-Rafii        (5223600066)
          - Purba Tri Julia Putra   (5223600069)

Project Link: (https://github.com/putra-17/OOP_B.Dea/tree/main)

<p align="right">(<a href="#readme-top">back to top</a>)</p>
