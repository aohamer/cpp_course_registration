# C++ Course Registration System

This is a console-based C++ program that manages university courses, lecturers, and student registrations.

## Features

- Register students for courses with unique email validation
- Display course participants
- Show courses with available slots
- Notify students if a course will not take place (less than 3 participants)

## Classes

- `Person`: Base class with common attributes
- `Lecturer`: Derived from `Person`, with academic title
- `Student`: Derived from `Person`, with matriculation number and university
- `Course`: Manages course info, lecturer, and enrolled students

## How to compile and run

Compile using g++:

```bash
g++ main.cpp -o course_registration
./course_registration
