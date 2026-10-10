# Car Rental Agency Management System

A console-based car rental management system developed using C++ as part of a university programming project.

## Overview

This project simulates a car rental agency where cars, clients, and employees are managed using object-oriented programming concepts. It demonstrates how classes and their relationships can be used to organize a simple management system.

## Features

- Display available cars and their details.
- Register cars, clients, and employees within the agency.
- Process a five-day car rental and calculate the total rental cost.
- Update car availability after a rental.
- Compare cars by license plate and daily rental price.
- Display client, employee, and vehicle information.

## Object-Oriented Programming Concepts

- **Classes and Objects:** Represent people, clients, employees, cars, and the agency.
- **Inheritance:** Use single inheritance for clients and multiple inheritance for employees.
- **Encapsulation:** Store class data in private members and access selected information through member functions.
- **Operator Overloading:** Compare cars using `==` and `<`.
- **Arrays:** Store cars, clients, and employees within the agency.
- **Pass by Reference:** Pass a car by reference when processing a rental.

## Technologies

- C++
- Standard C++ Library

## How to Run

Compile `main.cpp` using a C++ compiler, then run the generated executable.

For example, using g++:

```bash
g++ -std=c++11 main.cpp -o car_rental
```

Run the program:

- Windows: `car_rental.exe`
- Linux/macOS: `./car_rental`

## Project Scope

This is an educational console-based project. It demonstrates basic car rental operations using in-memory data and does not use a database or persistent storage.
