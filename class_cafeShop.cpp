#include <iostream>
#include <string>
using namespace std;

class Beverage {
private:
    string name;
    double price;
    string type; 
public:
    Beverage(string n, double p, string t) : name(n), price(p), type(t) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
    string getType() const { return type; }
    void setName(string n) { name = n; }
    void setPrice(double p) { price = p; }
    void setType(string t) { type = t; }
    void display() const {
        cout << "Beverage: " << name << " | Price: $" << price << " | Type: " << type << endl;
    }
};

class Employee {
private:
    string name;
    string position;
    double salary;

public:
    Employee(string n, string p, double s) : name(n), position(p), salary(s) {}

    string getName() const { return name; }
    string getPosition() const { return position; }
    double getSalary() const { return salary; }

    void setName(string n) { name = n; }
    void setPosition(string p) { position = p; }
    void setSalary(double s) { salary = s; }

    void display() const {
        cout << "Employee: " << name << " | Position: " << position << " | Salary: $" << salary << endl;
    }
};


class Customer {
private:
    string name;
    string phone;

public:
    Customer(string n, string p) : name(n), phone(p) {}

    string getName() const { return name; }
    string getPhone() const { return phone; }

    void setName(string n) { name = n; }
    void setPhone(string p) { phone = p; }

    void display() const {
        cout << "Customer: " << name << " | Phone: " << phone << endl;
    }
};

class Order {
private:
    Customer customer;
    vector<Beverage> beverages;
    double totalPrice;

public:
    Order(Customer c) : customer(c), totalPrice(0.0) {}

    void addBeverage(Beverage b) {
        beverages.push_back(b);
        totalPrice += b.getPrice();
    }

    double getTotalPrice() const { return totalPrice; }

    void display() const {
        cout << "Don dat hang cua khach: " << customer.getName() << endl;
        for (const auto& beverage : beverages) {
            beverage.display();
        }
        cout << "Tong gia: $" << totalPrice << endl;
    }
};


class CoffeeShop {
private:
    vector<Employee> employees;
    vector<Customer> customers;
    vector<Order> orders;

public:
    void addEmployee(Employee e) {
        employees.push_back(e);
    }

    void addCustomer(Customer c) {
        customers.push_back(c);
    }

    void addOrder(Order o) {
        orders.push_back(o);
    }

    void displayEmployees() const {
        cout << "Employees:" << endl;
        for (const auto& employee : employees) {
            employee.display();
        }
    }

    void displayCustomers() const {
        cout << "Customers:" << endl;
        for (const auto& customer : customers) {
            customer.display();
        }
    }

    void displayOrders() const {
        cout << "Orders:" << endl;
        for (const auto& order : orders) {
            order.display();
        }
    }
};


int main() {

    Beverage coffee("Coffee", 3.5, "hot");
    Beverage latte("Latte", 4.0, "hot");
    Beverage icedTea("Iced Tea", 2.5, "cold");

    Employee employee1("Le Quoc Trung", "Barista", 1500);
    Employee employee2("Bui Dai Nghia", "Cashier", 1200);

    Customer customer1("Nguyen Anh Nguyen", "123-456-789");

    Order order1(customer1);
    order1.addBeverage(coffee);
    order1.addBeverage(icedTea);

    CoffeeShop shop;
    shop.addEmployee(employee1);
    shop.addEmployee(employee2);
    shop.addCustomer(customer1);
    shop.addOrder(order1);

    shop.displayEmployees();
    shop.displayCustomers();
    shop.displayOrders();

    return 0;
}
