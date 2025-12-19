🏨 Hotel Management System (C++)
A comprehensive, Object-Oriented Hotel Management System implemented in C++. This application enables hotel staff to manage room inventory, track customer information (including VIP status), handle real-time bookings, and automate the check-out and billing process.

🚀 Features
Room Management: Add new rooms to the inventory and display all rooms with their specific types (Single, Double, Suite) and current status.

Booking System: Real-time room booking that automatically updates room availability upon reservation.

VIP Membership: Support for VIP customers with an automatic 15% discount applied during the billing process.

Billing Engine: Automatically calculates the final bill based on the duration of stay (nights) and the customer's discount tier.

Customer Search: Efficiently look up guest details using a unique Customer ID.

Dynamic Inventory: Automatically reverts room status to "Available" immediately after a guest checks out.

🛠️ Technical Concepts Used
This project serves as a practical demonstration of core Object-Oriented Programming (OOP) principles and modern C++ features:

Inheritance: The VIPCustomer class inherits from the Customer base class, reusing code while extending functionality.

Polymorphism: Utilizes method overriding for discount() and display() to provide specialized behavior for VIP guests at runtime.

Encapsulation: Protects data integrity by using private and protected members, exposed through public getter and setter methods.

STL Vectors: Employs std::vector to dynamically manage collections of rooms, customers, and active bookings.

Lambda Expressions: Used within std::find_if for clean, readable, and efficient searching within data structures.

Memory Management: Implements a custom destructor in the Hotel class to properly clean up dynamically allocated Customer objects.

📂 Project Structure

Room: Handles room attributes (number, type, price, availability).
Customer / VIPCustomer: Manages guest profiles and discount logic.
Booking: Links a Customer to a Room and calculates costs.
Hotel: The controller class that manages the logic for the entire system.

💻 Getting Started
Prerequisites
A C++ compiler (GCC/G++, Clang, or MSVC).
C++11 or higher (due to the use of Lambdas and auto).

Compilation
Use the following command to compile the project:

Bash
g++ -o hotel_system main.cpp
Execution
Run the compiled executable:

Bash
./hotel_system


📋 Usage Guide
Add Room: Initialize your hotel by adding rooms with a room number, type, and base price per night.
Book a Room:
Select from the list of available rooms.

Enter guest details.
Specify if the guest is a VIP to apply future discounts.

Check-Out: Enter the Booking ID and the number of nights stayed. The system will display the final invoice and free the room.

Search: Quickly find guest contact information using their ID.
