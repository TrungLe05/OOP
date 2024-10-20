#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Admin {
    private:
        string username;
        string password;
        bool isLoggedIn;

    public:
        Admin(string user, string pass) : username(user), password(pass), isLoggedIn(false) {}

        // Phương thức đăng nhập
        bool loginbByAdmin() {
            string inputUser, inputPass;
            cout << "Nhap ten dang nhap: ";
            cin >> inputUser;
            cout << "Nhap mat khau: ";
            cin >> inputPass;

            if (inputUser == username && inputPass == password) {
                isLoggedIn = true;
                cout << "Dang nhap thanh cong!" << endl;
                return true;
            } else {
                cout << "Ten dang nhap hoac mat khau sai!" << endl;
                return false;
            }
        }

        // Phương thức đăng xuất
        void logoutByAdmin() {
            if (isLoggedIn) {
                isLoggedIn = false;
                cout << "Dang xuat thanh cong!" << endl;
            } else {
                cout << "Ban chua dang nhap!" << endl;
            }
        }

        // Phương thức kiểm tra trạng thái đăng nhập
        bool isAdminLoggedIn() {
            return isLoggedIn;
        }
};

class EMPLOYEE {
    private:
        string username;
        string password;
        bool isLoggedIn;
    public:
        EMPLOYEE(string user, string pass) : username(user), password(pass), isLoggedIn(false) {}

        // Phương thức đăng nhập
        bool loginByEmployee() {
            string inputUser, inputPass;
            cout << "Nhap ten dang nhap: ";
            cin >> inputUser;
            cout << "Nhap mat khau: ";
            cin >> inputPass;

            if (inputUser == username && inputPass == password) {
                isLoggedIn = true;
                cout << "Dang nhap thanh cong!" << endl;
                return true;
            } else {
                cout << "Ten dang nhap hoac mat khau sai!" << endl;
                return false;
            }
        }

        // Phương thức đăng xuất
        void logoutByEmployee() {
            if (isLoggedIn) {
                isLoggedIn = false;
                cout << "Dang xuat thanh cong!" << endl;
            } else {
                cout << "Ban chua dang nhap!" << endl;
            }
        }

        // Phương thức kiểm tra trạng thái đăng nhập
        bool isEmployeeLoggedIn() {
            return isLoggedIn;
        }
};


// Class PRODUCT
class PRODUCT {
protected:
    int idProduct;
    string nameProduct;
    double price;

public:
    PRODUCT() : idProduct(0), nameProduct(" "), price(0.0) {}
    PRODUCT(int idProduct, string nameProduct, double price)
        : idProduct(idProduct), nameProduct(nameProduct), price(price) {}

    virtual void addProduct() {
        cout << "Nhap id san pham: ";
        cin >> this->idProduct;
        cin.ignore();
        cout << "Nhap ten san pham: ";
        getline(cin, this->nameProduct);
        cout << "Nhap gia cua san pham: ";
        cin >> this->price;
    }

    void displayProduct() const {
        cout << idProduct << "\t\t" << nameProduct << "\t\t" << price << endl;
    }

    virtual ~PRODUCT() {}
};

// Class FOOD kế thừa PRODUCT
class FOOD : public PRODUCT {
private:
    bool isSaltyFood;

public:
    FOOD() : isSaltyFood(false) {}

    void addFood() {
        string type;
        cout << "Nhap loai do an (Man/Ngot): ";
        cin.ignore();
        getline(cin, type);
        if (type == "Man") {
            this->isSaltyFood = true;
        } else if (type == "Ngot") {
            this->isSaltyFood = false;
        }

        PRODUCT::addProduct(); // Gọi lại hàm thêm sản phẩm từ lớp PRODUCT

        if (isSaltyFood) {
            cout << "Da them do an Man." << endl;
        } else {
            cout << "Da them do an Ngot." << endl;
        }
    }
};

class Menu {
private:
    vector<PRODUCT*> productList; // Danh sách các sản phẩm

public:
    void addProductToList(PRODUCT* product) {
        productList.push_back(product);
    }

    void displayMenu() {
        cout << "=====================MENU=====================" << endl;
        cout << "ID:\t\t Name:\t\t Price:\t\t" << endl;
        for (auto product : productList) {
            product->displayProduct();
        }
    }

    ~Menu() {
        // Giải phóng bộ nhớ các đối tượng sản phẩm trong danh sách
        for (auto product : productList) {
            delete product;
        }
    }
};

// Class PERSON
class PERSON {
protected:
    string name;
    int age;
    string sex;
public:
    PERSON();
    PERSON(string name, int age, string sex);
    void inputInformation();
    virtual void outputInformation();
    virtual ~PERSON();
};

PERSON::PERSON() {
    this->age = 0;  
    this->name = " ";
    this->sex = " ";
}

PERSON::PERSON(string name, int age, string sex) {
    this->age = age;
    this->name = name;
    this->sex = sex;
}

void PERSON::inputInformation() {
    cout << "Nhap ten: ";
    getline(cin, this->name);
    cout << "Nhap tuoi: ";
    cin >> this->age;
    cin.ignore();
    cout << "Nhap gioi tinh: ";
    getline(cin, this->sex);
}

void PERSON::outputInformation() {
    cout << "============INFORMATION============" << endl;
    cout << "Name:\t\t Age:\t\t Sex: " << endl;
    cout << this->name << "\t " << this->age << "\t" << this->sex << endl;
}

PERSON::~PERSON() {}

// Class STAFF kế thừa từ PERSON
class STAFF : public PERSON {
protected:
    int idStaff;
    double salary;
    string position;
    int checkInHour;
    int checkOutHour;

public:
    STAFF();
    STAFF(int idStaff, double salary, string position);
    void inputInformation();
    void outputInformation() override;
    void checkIn();
    void checkOut();
    double calculateSalary();
    virtual ~STAFF();
};

STAFF::STAFF() : checkInHour(0), checkOutHour(0) {
    this->idStaff = 0;
    this->salary = 0.0;
    this->position = " ";
}

STAFF::STAFF(int idStaff, double salary, string position)
    : PERSON(), idStaff(idStaff), salary(salary), position(position), checkInHour(0), checkOutHour(0) {}

void STAFF::inputInformation() {
    PERSON::inputInformation();
    cout << "Nhap id nhan vien: ";
    cin >> this->idStaff;
    cin.ignore();
    cout << "Vi tri lam viec (Partime/Fulltime): ";
    getline(cin, this->position);
}

void STAFF::outputInformation() {
    PERSON::outputInformation();
    cout << "ID:\t\t Salary:\t Position:\t" << endl;
    cout << this->idStaff << "\t\t" << this->salary << "\t\t" << this->position << endl;
}

void STAFF::checkIn() {
    cout << "Nhap gio check-in (0-23): ";
    cin >> this->checkInHour;
    if (checkInHour >= 0 && checkInHour <= 23)
        cout << "Check-in thanh cong vao gio " << checkInHour << "h" << endl;
    else
        cout << "Gio khong hop le!" << endl;
}

void STAFF::checkOut() {
    cout << "Nhap gio check-out (0-23): ";
    cin >> this->checkOutHour;
    if (checkOutHour >= checkInHour && checkOutHour <= 23)
        cout << "Check-out thanh cong vao gio " << checkOutHour << "h" << endl;
    else
        cout << "Gio check-out khong hop le!" << endl;
}

double STAFF::calculateSalary() {
    int workingHours = checkOutHour - checkInHour;
    if (position == "Partime") {
        return workingHours * 18000;
    } else if (position == "Fulltime") {
        return workingHours * 23000;
    } else {
        return 0;
    }
}

STAFF::~STAFF() {}

// Class CUSTOMER kế thừa từ PERSON
class CUSTOMER : public PERSON {
private:
    string customerID;
public:
    CUSTOMER();
    CUSTOMER(string customerID);
    void inputInformation();
    void outputInformation() override;
    virtual ~CUSTOMER();
};

CUSTOMER::CUSTOMER() {
    this->customerID = " ";
}

CUSTOMER::CUSTOMER(string customerID)
    : PERSON(), customerID(customerID) {}

void CUSTOMER::inputInformation() {
    PERSON::inputInformation();
    cout << "Nhap ma khach hang: ";
    getline(cin, this->customerID);
}

void CUSTOMER::outputInformation() {
    PERSON::outputInformation();
    cout << "Customer ID: " << this->customerID << endl;
}

CUSTOMER::~CUSTOMER() {}

int main() {
    // Tạo một quản lý với username: admin và password: 1234
    Admin admin("admin", "1234");
    EMPLOYEE empl ("Le Quoc Trung", "6451071082");
    Menu menu;

    int choice;
    do {
        cout << "\n1. Dang nhap voi tu cach la quan ly" << endl;
        cout << "2. Dang nhap voi tu cach la nhan vien" << endl;
        cout << "3. Them do an" << endl;
        cout << "4. Hien thi menu" << endl;
        cout << "5. Dang xuat(Admin)" << endl;
        cout << "6. Dang xuat(Employee)" << endl;
        cout << "7. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (!admin.isAdminLoggedIn()) {
                admin.loginbByAdmin();
            } else {
                cout << "Ban da dang nhap roi!" << endl;
            }
            break;

        case 2:
             if (!empl.isEmployeeLoggedIn()) {
                empl.loginByEmployee();
            } else {
                cout << "Ban da dang nhap roi!" << endl;
            }
            break;

        case 3:
            if (admin.isAdminLoggedIn()) {
                FOOD* food = new FOOD();
                int n; // số lượng thức ăn cần thêm từ admin
                cout << "Nhap so luong thuc an: " << endl;
                cin >> n;
                for (int i = 1; i <= n; i++){
                    food->addFood();
                    menu.addProductToList(food); // Thêm sản phẩm vào menu  
                }
            } else {
                cout << "Ban can dang nhap truoc!" << endl;
            }
            break;

        case 4:
            menu.displayMenu();
            break;

        case 5:
            admin.logoutByAdmin();
            break;
        case 6:
            empl.logoutByEmployee();
            break;
        case 7:
            cout << "Ket thuc chuong trinh!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }

    } while (choice != 7);

    return 0;
}
