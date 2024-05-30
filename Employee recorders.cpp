//Asayel Al-sharif 2230007121
//Ola yasir 2230009046
//Fatimah Alghafli 2230000822

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 100; // Maximum number of employees

struct Employee {
    string name;
    int id;
    string mobileNumber;
    string address;
    string job;
    double salary;
    double Number_of_overtime_hours;
};

struct EmployeeRecordsSystem {
    Employee employees[MAX_EMPLOYEES]; // Array to store employees
    int numEmployees; // Keep track of the number of employees
    
    EmployeeRecordsSystem() : numEmployees(0) {	}
    
    double calculateTotalSalaryWithOvertime() {
        double totalSalary = 0.0;
        for (int i = 0; i < numEmployees; ++i) {
            const Employee& employee = employees[i];
            double overtimePay = 0.0;
            if (employee.Number_of_overtime_hours > 0) {
                // Assuming overtime pay is calculated at 1.5 times the regular hourly rate
                overtimePay = 1.5 * (employee.Number_of_overtime_hours * (employee.salary / 30)); // Assuming 30 days in a month
            }
            totalSalary += (employee.salary + overtimePay);
        }
        return totalSalary;
    }//to calculate Total Salary With Overtime
    
void searchEmployeeByName() {
    string searchName;
    cout << "Enter the name of the employee to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].name == searchName) {
            cout << "Employee Found:" << endl;
            const Employee &employee = employees[i];
            cout << "-------------------------" << endl;
            cout << "Name: " << employee.name << endl;
            cout << "ID: " << employee.id << endl;
            cout << "Mobile Number: " << employee.mobileNumber << endl;
            cout << "Address: " << employee.address << endl;
            cout << "Job: " << employee.job << endl;
            cout << "Salary: " << employee.salary <<" SR" << endl;
            cout << "Number of Overtime hours: " << employee.Number_of_overtime_hours << endl;
            cout << "Total Salary with Overtime: " << (employee.salary + calculateTotalSalaryWithOvertime())<<" SR" << endl;
            cout << "-------------------------" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        // Ask the user if they meant to search for another employee with similar name
        string similarName;
        cout << "Employee not found. Do you mean to search for another employee with a similar name?" << endl;
        cout << "Enter the name (or a part of the name): ";
        cin.ignore();
        getline(cin, similarName);

        bool foundSimilar = false;
        for (int i = 0; i < numEmployees; ++i) {
            if (employees[i].name.find(similarName) != string::npos) {
                // Similar name found
                foundSimilar = true;

                cout << "Employee Found:" << endl;
                const Employee &employee = employees[i];
                cout << "-------------------------" << endl;
                cout << "Name: " << employee.name << endl;
                cout << "ID: " << employee.id << endl;
                cout << "Mobile Number: " << employee.mobileNumber << endl;
                cout << "Address: " << employee.address << endl;
                cout << "Job: " << employee.job << endl;
                cout << "Salary: " << employee.salary <<" SR" << endl;
                cout << "Number of Overtime hours: " << employee.Number_of_overtime_hours << endl;
                cout << "Total Salary with Overtime: " << (employee.salary + calculateTotalSalaryWithOvertime())<<" SR"<< endl;
                cout<< "-------------------------"<<endl;

                found = true; // Set found to true as we've found an employee with a similar name
                break;
            }
        }

        if (!found && !foundSimilar) {
            cout <<"Employee not found."<<endl;
        }
    }
}

void searchEmployeeByJob() {
    string searchJob;
    cout << "Enter the job of the employee to search: ";
    cin.ignore();
    getline(cin, searchJob);

    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].job == searchJob) {
            cout << "Employee Found:" << endl;
            const Employee &employee = employees[i];
            cout << "-------------------------" << endl;
            cout << "Name: " << employee.name << endl;
            cout << "ID: " << employee.id << endl;
            cout << "Mobile Number: " << employee.mobileNumber << endl;
            cout << "Address: " << employee.address << endl;
            cout << "Job: " << employee.job << endl;
            cout << "Salary: " << employee.salary <<" SR" << endl;
            cout << "Number of Overtime hours: " << employee.Number_of_overtime_hours << endl;
            cout << "Total Salary with Overtime: " << (employee.salary + calculateTotalSalaryWithOvertime())<<" SR" << endl;
            cout<< "-------------------------"<<endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout <<"Employee not found. Maybe There is not an Employee with this Job. Make sure"<<endl;
        // Ask the user if they want to search again
        char response;
        cout <<"Do you want to search again? (y/n)"<<endl;
        cin >> response;
        if (response == 'y' || response == 'Y') {
            searchEmployeeByJob();
        }
    }
}
    void loadEmployeesFromFile() {
        ifstream inputFile("employees.txt");
        if (!inputFile.is_open()) {
            cout << "File is open but No existing employee records found ." << endl;
            return;
        }

        while (!inputFile.eof()) {
            Employee employee;
            getline(inputFile, employee.name);
            inputFile >> employee.id;
            inputFile.ignore();
            getline(inputFile, employee.mobileNumber);
            getline(inputFile, employee.address);
            getline(inputFile, employee.job);
            inputFile >> employee.salary >> employee.Number_of_overtime_hours;
            inputFile.ignore();
            employees[numEmployees++] = employee;
        }

        inputFile.close();
        cout << "Employee records loaded successfully." << endl;
    }//to open file

    void saveEmployeesToFile() {
        ofstream outputFile("employees.txt");
        if (!outputFile.is_open()) {
            cout << "Error: Unable to save employee records." << endl;
            return;
        }

        for (int i = 0; i < numEmployees; ++i) {
            const Employee &employee = employees[i];
            outputFile <<"Name:"<< employee.name << endl;
            outputFile <<"ID:"<<employee.id << endl;
            outputFile <<"Mobile Number:"<< employee.mobileNumber << endl;
            outputFile <<"Address:"<<employee.address << endl;
            outputFile <<"Job:"<< employee.job << endl;
            outputFile <<"Salary:"<< employee.salary <<endl;
            outputFile<< "Number_of_overtime_hours:" << employee.Number_of_overtime_hours << endl;
            outputFile << "Total Salary with Overtime:" << (employee.salary + calculateTotalSalaryWithOvertime()) << endl;
            outputFile<<"......................................."<<endl;
        }

        outputFile.close();
        cout << "Employee records saved successfully." << endl;
    }//to save employee record

    void addEmployee() {
        if (numEmployees >= MAX_EMPLOYEES) {
            cout << "Maximum number of employees reached." << endl;
            return;
        }

        Employee employee;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, employee.name);
        cout << "Enter employee ID: ";
        cin>>employee.id;
        cout << "Enter employee mobile number: ";
        cin >> employee.mobileNumber;
        cout << "Enter employee address: ";
        cin.ignore();
        getline(cin, employee.address);
        cout << "Enter employee job: ";
        getline(cin, employee.job);
        cout << "Enter employee salary: ";
        cin >> employee.salary;
        cout << "Enter Number of overtime hours: ";
        cin >> employee.Number_of_overtime_hours;

        employees[numEmployees++] = employee;
        cout << "Employee added successfully." << endl;
    }// to add employee

    void removeEmployee() {
        int employeeId;
        cout << "Enter the ID of the employee to remove: ";
        cin >> employeeId;

        int index = findEmployeeIndex(employeeId);
        if (index != -1) {
            // Shift elements to fill the gap
            for (int i = index; i < numEmployees - 1; ++i) {
                employees[i] = employees[i + 1];
            }
            numEmployees--;
            cout << "Employee removed successfully." << endl;
        } else {
            cout << "Employee not found." << endl;
        }
    }//to remove employee

    void updateEmployee() {
        int employeeId;
        cout << "Enter the ID of the employee to update: ";
        cin >> employeeId;

        int index = findEmployeeIndex(employeeId);
        if (index != -1) {
            Employee& employee = employees[index];
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, employee.name);
            cout << "Enter new mobile number: ";
            cin >> employee.mobileNumber;
            cout << "Enter new address: ";
            cin.ignore();
            getline(cin, employee.address);
            cout << "Enter new job: ";
            getline(cin, employee.job);
            cout << "Enter new salary: ";
            cin >> employee.salary;
            cout << "Enter Number of overtime hours: ";
            cin >> employee.Number_of_overtime_hours;

            cout << "Employee information updated successfully." << endl;
        } else {
            cout << "Employee not found." << endl;
        }
    }//to update employee

    void displayEmployees() {
        if (numEmployees == 0) {
            cout << "No employees in the system." << endl;
        } else {
            cout << "Employee Records:" << endl;
            for (int i = 0; i < numEmployees; ++i) {
                const Employee& employee = employees[i];
                cout << "-------------------------" << endl;
                cout << "Name: " << employee.name << endl;
                cout << "ID: " << employee.id << endl;
                cout << "Mobile Number: " << employee.mobileNumber << endl;
                cout << "Address: " << employee.address << endl;
                cout << "Job: " << employee.job << endl;
                cout << "Salary: " << employee.salary <<" SR"<< endl;
                cout << "Number of Overtime hours: " << employee.Number_of_overtime_hours << endl;
                cout << "Total Salary with Overtime: " << (employee.salary + calculateTotalSalaryWithOvertime())<<" SR" << endl;
                cout << "-------------------------" << endl;
            }
        }
    }//to display employee record with value of total salary

    void bubbleSortEmployeesByName() {
        for (int i = 0; i < numEmployees - 1; ++i) {
            for (int j = 0; j < numEmployees - i - 1; ++j) {
                if (employees[j].name > employees[j + 1].name) {
                    // Swap employees
                    Employee temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }//to sort employees by name using bubble sort

private:
    // Helper function to find the index of an employee with a given ID
    int findEmployeeIndex(int id) {
        for (int i = 0; i < numEmployees; ++i) {
            if (employees[i].id == id) {
                return i;
            }
        }
        return -1; // Employee not found
    }
};//means this variable can only be used in the existing class



int main() {
    EmployeeRecordsSystem recordsSystem;
    recordsSystem.loadEmployeesFromFile(); // Load existing employee records

    //the menu:
    int choice;

    do {
        cout << "-------------------------" << endl;
        cout << "Employee Records System Menu:" << endl;
        cout << "1. Add an employee" << endl;
        cout << "2. Remove an employee" << endl;
        cout << "3. Update an employee" << endl;
        cout << "4. Display all employees with total salary" << endl;
        cout << "5. Save employee records to file" << endl;
        cout << "6. Search employee by name" << endl;
        cout << "7. Search employee by their Job " << endl;
        cout << "8. Sort employees by name and display" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice (1-9): "<<endl;
        cout << "-------------------------" << endl;
        cin >> choice;
        cout << "-------------------------" << endl;
        switch (choice) {
            case 1:
                recordsSystem.addEmployee();
                break;
            case 2:
                recordsSystem.removeEmployee();
                break;
            case 3:
                recordsSystem.updateEmployee();
                break;
            case 4:
                recordsSystem.displayEmployees();
                break;
            case 5:
                recordsSystem.saveEmployeesToFile();
                break;
            case 6:
            	recordsSystem.searchEmployeeByName(); // Sort employees by name 
            	break;
            	case 7:
    recordsSystem.searchEmployeeByJob();
    break;
            case 8:	
                recordsSystem.bubbleSortEmployeesByName(); // Sort employees by name
                recordsSystem.displayEmployees(); // Display sorted employees
                break;
            case 9:
                cout << "Thank You for using our System To sort and arrange Your Employees . Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 9 );

    return 0;
}
