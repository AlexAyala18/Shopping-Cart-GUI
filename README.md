# Shopping Cart GUI Application

Author: Alexander Ayala

---

## Overview

This project is a Windows Forms-based shopping cart application developed in C++/CLI using Microsoft Visual Studio. It provides a graphical interface for managing items in a shopping cart with database integration.

The application allows users to add, remove, search, and update items while maintaining persistent data storage.

---

## Features

- Add items to the shopping cart  
- Remove items from the system  
- Search for items  
- Update item descriptions  
- Update item quantities  
- Calculate total cart value  

---

## Technologies Used

- C++/CLI  
- Windows Forms  
- Microsoft Visual Studio  
- SQL Server  
- ADO.NET  

---

## System Design

The application is built using multiple Windows Forms, each responsible for a specific function:

- Welcome screen for user entry  
- Menu system for navigation  
- Individual forms for adding, removing, updating, and searching items  

User actions trigger database operations, and results are displayed through the GUI.

---

## How It Works

- The user interacts with the GUI to perform operations  
- Input is collected through form controls  
- SQL queries are executed to insert, update, or retrieve data  
- Results are displayed dynamically in the interface  

---

## How to Run

1. Open the solution file:
ShoppingCart.sln

2. Build the project in Visual Studio

3. Run the application using:
Start (F5)

---

## Notes

- This project was developed as part of coursework and includes foundational code provided during instruction  
- Focus was placed on GUI design, database interaction, and application logic  
- SQL Server must be configured locally for full functionality  

---

## Summary

This project demonstrates fundamental concepts in GUI development, database integration, and application design using C++ and Windows Forms.
