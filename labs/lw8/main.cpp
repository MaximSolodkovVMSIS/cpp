#include <iostream>
#include <map>
#include <string>
#include <algorithm>

class Employee {
public:
    Employee(const std::string& n, int hours) : name(n), hoursWorked(hours) {}

    std::string getName() const {
        return name;
    }

    int getHoursWorked() const {
        return hoursWorked;
    }

    void printInfo() const {
        std::cout << name << " - " << hoursWorked << " hours" << std::endl;
    }
    void updateHoursWorkers(int newHours) {
        hoursWorked = newHours;
    }
private:
    std::string name;
    int hoursWorked;
};

class EmployeeManager {
public:
    void addEmployee(const std::string& department, const Employee& employee) {
        employees.emplace(department, employee);
    }
    void updateEmpoyeeHours(const std::string& department, const std::string& name, int newHours) {
        auto range = employees.equal_range(department);
        auto it = std::find_if(range.first, range.second, [&name](const auto& pair) {
            return pair.second.getName() == name;
        });
        if (it != range.second) {
            it->second.updateHoursWorkers(newHours);
            std::cout << "Update hours for employee " << name << " in department " << department << std::endl;
        }
        else {
            std::cout << "Emloyee " << name << "not found in department " << department << std::endl;
        }
    }
    void printMaxHoursEmployee() const {
        auto maxHoursIt = std::max_element(employees.begin(), employees.end(),
            [](const auto& pair1, const auto& pair2) {
                return pair1.second.getHoursWorked() < pair2.second.getHoursWorked();
            });
        if (maxHoursIt != employees.end()) {
            maxHoursIt->second.printInfo();
        }
        else {
            std::cout << "No employee in the system" << std::endl;
        }
    }
    void removeEmployeesFromDepartment(const std::string& department) {
        employees.erase(department);
        std::cout << "Removed all employees from department " << department << std::endl;
    }
    void printEmployeeMap() const {
        for (const auto& pair : employees) {
            std::cout << pair.first << ": ";
            pair.second.printInfo();
        }
    }

private:
    std::multimap<std::string, Employee> employees;
}; //  одинаковые значения ключей несколько  (pair<>)
//несколько значений для одного ключа

int main() {
    EmployeeManager employeeManager;

    employeeManager.addEmployee("IT", Employee("John", 40));
    employeeManager.addEmployee("Sales", Employee("Alice", 35));
    employeeManager.addEmployee("IT", Employee("Bob", 30));
    employeeManager.addEmployee("HR", Employee("Charlie", 45));

    std::cout << "Initial Employee Map:" << std::endl;
    employeeManager.printEmployeeMap();

    employeeManager.updateEmpoyeeHours("IT", "John", 45);
    std::cout << "\nEmployees with max hours: \n";
    employeeManager.printMaxHoursEmployee();

    employeeManager.removeEmployeesFromDepartment("Sales");

    std::cout << "\nEmployees Map after update: \n";
    employeeManager.printEmployeeMap();

    // Добавьте здесь ваш код для работы с данными, если нужно

    return 0;
}
