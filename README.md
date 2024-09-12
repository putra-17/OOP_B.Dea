<!-- ABOUT THE PROJECT -->
## About The Project
Restaurant Order Management System

Overview
This project is a modular and extensible restaurant order management system implemented in C++. It is designed with principles of Object-Oriented Programming (OOP) and Design Patterns to ensure easy maintenance and future scalability. The system simulates the interaction between a customer, a waiter, and the kitchen, managing orders and customer emotions dynamically.

Features
Order Management: Customers can place orders, and the system tracks the status of the order (Not Yet Taken, In Kitchen, Served).
Customer Emotion: The customer's emotional level decreases as they wait for their order and resets once the order is served.
Waiter Actions: The waiter takes the order, sends it to the kitchen, and delivers it when ready.
Table Management: Each table is associated with a customer, and the order status for the table is displayed dynamically.


<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Class Explanation
Class Breakdown
1. Order (Order Interface)
Defines the behavior for managing the order details and status.
2. Customer (Customer Interface)
Manages customer-related actions such as placing orders, tracking emotional level, and displaying customer information.
3. Table (Table Interface)
Manages table-specific operations, such as assigning customers and displaying order status.
4. Waiter (Waiter Interface)
Defines the actions that the waiter can perform, such as taking orders, preparing them in the kitchen, and delivering them to the customer.

### Built With

Visual Code Studio

How to Build and Run
1. Open code.cpp file
2. Copy raw code in code.cpp 
3. Compile the code using a C++ compiler.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Getting Started

How the Code Works
Customer and Table Assignment: A customer is created and assigned to a table. The customer places an order, which is associated with the table.
Waiter Interaction: A waiter takes the order from the table and simulates sending it to the kitchen. While the customer waits, their emotion level decreases. Once the kitchen finishes preparing the order, the waiter delivers it, and the customer’s emotion level is reset.
Modular Design: Each class is responsible for a specific part of the functionality, making the code easy to extend or modify without affecting other parts of the system.

How to Extend the Code
New Customer Types: You can easily add different types of customers (e.g., VIP, Regular) by creating a new class that implements the ICustomer interface.
Different Waiter Behavior: The waiter's behavior could be changed by subclassing IWaiter and overriding the methods to provide a different way of handling orders.
Additional Features: The system could be extended to include a notification system using the Observer Pattern to inform the customer when their order status changes.

## Contact
  
Your Name - Ibrahim Ar-Rafii        (5223600066)
          - Purba Tri Julia Putra   (5223600069)

Project Link: (https://github.com/putra-17/OOP_B.Dea/tree/main)

<p align="right">(<a href="#readme-top">back to top</a>)</p>
