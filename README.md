A comprehensive, object-oriented Hotel Management System implemented in C++. This application allows hotel staff to manage room inventory, track customer information (including VIP status), handle bookings, and automate the check-out and billing process.

🚀 Features
Room Management: Add new rooms and display all rooms with their current status (Single, Double, Suite).

Booking System: Real-time room booking that automatically updates room availability.

VIP Membership: Support for VIP customers with an automatic 15% discount applied during check-out.

Billing Engine: Calculates the final bill based on the number of nights stayed and the customer's discount tier.

Customer Search: Look up customer details using their unique Customer ID.

Dynamic Inventory: Automatically makes rooms available again once a guest checks out.

🛠️ Technical Concepts Used
This project demonstrates several core Object-Oriented Programming (OOP) principles:

Inheritance: The VIPCustomer class inherits from the Customer base class.

Polymorphism: Overriding methods like discount() and display() to provide specialized behavior for VIPs.

Encapsulation: Using private and protected data members with public getter and setter methods.

STL Vectors: Using std::vector to dynamically manage collections of rooms, customers, and bookings.

Lambda Expressions: Used within std::find_if for efficient searching within data structures.