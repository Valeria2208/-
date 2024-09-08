//
//  main.cpp
//  ООП
//
//  Created by Valeria Dudinova on 08.09.2024.
//

#include <iostream>
using namespace std;

struct Employee
{
    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
    double salary;
};

Employee employees[100];
int employeeCount = 0;

bool isPhoneNumberValid(const char* phoneNumber)
{
    int length = 0;
    while (phoneNumber[length] != '\0')
    {
        length++;
    }
    return length == 10;
}

void addEmployee()
{
    if (employeeCount < 100)
    {
        Employee& emp = employees[employeeCount];
      cout << "Enter employee name: ";
      cin >> emp.firstName;
      cout << "Enter the employee's lastName: ";
      cin >> emp.lastName;
      cout << "Enter the employee's phone number (10 digits): ";
      cin >> emp.phoneNumber;

        while (!isPhoneNumberValid(emp.phoneNumber))
        {
            cout << "Invalid number format. Re-enter your phone number: ";
            cin >> emp.phoneNumber;
        }

     cout << "Enter the employee's salary: ";
    cin >> emp.salary;

        employeeCount++;
    }
    else
    {
        cout << "Can't add more employees.\n";
    }
}

void displayEmployees()
{
    for (int i = 0; i < employeeCount; ++i)
    {
        Employee& emp = employees[i];
        std::cout << "Name: " << emp.firstName
                  << ",lastName: " << emp.lastName
                  << ",phone number: " << emp.phoneNumber
                  << ", salary: " << emp.salary << "\n";
    }
}

int main()
{
    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Add an employee\n";
        cout << "2. Show all employees\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                cout << "Exit the program.\n";
                break;
            default:
                cout << "Wrong choice, try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}

