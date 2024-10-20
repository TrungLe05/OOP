#include <iostream>
#include <string>
#include <vector>
#include<ctime>
using namespace std;

class Admin {
    private:
        string userName; // tên admin đăng nhập vào
        string passWord; // mật khẩu của admin
        bool isLoggedIn; // kiểm tra xem đã đăng nhập hay chưa

    public:
        Admin(string userName, string passWord);
        bool loginbByAdmin();
        void logoutByAdmin();
        bool isAdminLoggedIn();
};

Admin::Admin(string userName, string passWord){
    this->userName = userName;
    this->passWord = passWord;
    isLoggedIn = false;
}

bool Admin::loginbByAdmin(){
    string inputUser, inputPass;
    cout << "Nhap ten dang nhap: ";
    cin >> inputUser;
    cout << "Nhap mat khau: ";
    cin >> inputPass;
    if (inputUser == this->userName && inputPass == this->passWord) {
        this->isLoggedIn = true;
        cout << "Dang nhap thanh cong!" << endl;
        return true;
        } else {
        cout << "Ten dang nhap hoac mat khau sai!" << endl;
        return false;
    }
}

void Admin::logoutByAdmin(){
    if (this->isLoggedIn) {
        this->isLoggedIn = false;
        cout << "Dang xuat thanh cong!" << endl;
    } else {
        cout << "Ban chua dang nhap!" << endl;
    }
}

bool Admin::isAdminLoggedIn() {
    return this->isLoggedIn;
}

//Tương tự với admin
//class EMPLOYEE để đăng nhập dưới tư cách là nhân viên của NTN coffee
class EMPLOYEE {
private:
    string userName;
    string passWord;
    bool isLoggedIn;

public:
    EMPLOYEE(string userName, string passWord);
    bool loginByEmployee();
    void logoutByEmployee();
    bool isEmployeeLoggedIn();
};

EMPLOYEE::EMPLOYEE(string userName, string passWord){
    this->passWord = passWord;
    this->userName = userName;
    isLoggedIn = false;
}

bool EMPLOYEE::loginByEmployee() {
    string inputUser, inputPass;
    cout << "Nhap ten dang nhap: ";
    cin >> inputUser;
    cout << "Nhap mat khau: ";
    cin >> inputPass;
    if (inputUser == this->userName && inputPass == this->passWord) {
        this->isLoggedIn = true;
        cout << "Nhan vien dang nhap thanh cong!" << endl;
        return true;
    } else {
        cout << "Ten dang nhap hoac mat khau sai!" << endl;
        return false;
    }
}

void EMPLOYEE::logoutByEmployee() {
    if (this->isLoggedIn) {
        this->isLoggedIn = false;
        cout << "Nhan vien dang xuat thanh cong!" << endl;
    } else {
        cout << "Nhan vien chua dang nhap!" << endl;
    }
}

bool EMPLOYEE::isEmployeeLoggedIn() {
    return isLoggedIn;
}

// Class PRODUCT
// class này dùng để cho lớp FOOD kế thừa
class PRODUCT {
protected:
    int idProduct; // mã sản phẩm
    string nameProduct; // ten của sản phẩm
    double price; // giá sản phẩm

public:
    PRODUCT();
    PRODUCT(int idProduct, string nameProduct, double price);
    virtual void addProduct(); // thêm 1 sp vào menu
    void displayProduct() const; // hiển thị danh sách các sản phẩm
    virtual ~PRODUCT();
};

PRODUCT::PRODUCT(){
    idProduct = 0;
    nameProduct = " ";
    price = 0.0;
}

PRODUCT::PRODUCT(int idProduct, string nameProduct, double price){
    this->idProduct = idProduct;
    this->nameProduct = nameProduct;
    this->price = price;
}

void PRODUCT::addProduct() {
    cout << "Nhap id san pham: ";
    cin >> this->idProduct;
    cin.ignore();
    cout << "Nhap ten san pham: ";
    getline(cin, this->nameProduct);
    cout << "Nhap gia cua san pham: ";
    cin >> this->price;
}

void PRODUCT::displayProduct() const {
    cout << this->idProduct << "\t\t" << this->nameProduct << "\t\t" << this->price << endl;
}

PRODUCT::~PRODUCT() {}

// Class FOOD kế thừa PRODUCT
class FOOD : public PRODUCT {
private:
    bool isSaltyFood; // biến dùng để kiểm tra xem food vừa nhập là đồ mặn hay đồ ngọt 

public:
    FOOD();
    void addFood();
};

FOOD::FOOD(){
    isSaltyFood = false;
}

void FOOD::addFood() {
    string type;
    cout << "Nhap loai do an (Man/Ngot): "; 
    cin.ignore();
    getline(cin, type);
    if (type == "Man") {
        this->isSaltyFood = true;
    } else if (type == "Ngot") {
        this->isSaltyFood = false;
    }
    PRODUCT::addProduct(); 
    if (isSaltyFood) {
        cout << "Da them do an Man." << endl;
    } else {
        cout << "Da them do an Ngot." << endl;
    }
}

class MENU {
private:
    vector<PRODUCT*> productList; 

public:
    void addProductToList(PRODUCT* product);
    void displayMenu(); // menu sau khi thêm bớt sản phẩm
    void displayInitialMenu(); // menu ban đầu của NTN coffee lúc chưa thêm sản phẩm
    ~MENU();
};

void MENU::addProductToList(PRODUCT* product) {
    productList.push_back(product);
}

void MENU::displayMenu() {
    cout << "=====================MENU=====================" << endl;
    cout << "ID:\t\t Name:\t\t Price:\t\t" << endl;
    for (auto product : productList) {
        product->displayProduct();
    }
}

void MENU::displayInitialMenu(){
    cout << "=====================MENU======================" << endl;
    cout << "ID:\t\t Name:\t\t Price:\t\t" << endl;
    cout << "1.\t\t Ca Phe Pha May \t 18.000" << endl;
    cout << "2.\t\t Ca Phe Sua \t\t 20.000" << endl;
    cout << "3.\t\t Bac Xiu \t\t 22.000" << endl;
    cout << "4.\t\t Ca cao \t\t 25.000" << endl;
    cout << "5.\t\t Sua Tuoi \t\t 15.000" << endl;
    cout << "6.\t\t Ca Phe sua dua \t 28.000" << endl;
    cout << "7.\t\t Lipton Chanh Day \t 24.000" << endl;
    cout << "8.\t\t Tra Thao Duoc \t\t 22.000" << endl;
    cout << "9.\t\t Lipton Sua Chanh Day \t 20.000" << endl;
    cout << "10.\t\t Ep Dua Hau \t\t 18.000" << endl;
    cout << "11.\t\t Ep Ca Rot \t\t 18.000" << endl;
    cout << "12.\t\t Ep Tao \t\t 18.000" << endl;
    cout << "13.\t\t Ep Oi \t\t\t 18.000" << endl;

}


MENU::~MENU() {
    for (auto product : productList) {
        delete product;
    }
}

// Class PERSON
// tạo lớp person để staff và customer kế thừa thay vì phải thêm các thuộc tính name, age, sex vào từng class staff và customer
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
    cin.ignore();
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
    void inputInformation(); // thông tin của nhân viên
    void outputInformation();
    void checkIn(); // hàm để nhân viên check-in giờ đi làm ( chấm công )
    void checkOut();   // hàm để nhân viên check-out 
    double calculateSalary(); // hàm đựa vào tgian check-in và check-out để tính lương cho nhân viên
    virtual ~STAFF();
};

STAFF::STAFF(){
    this->checkInHour = 0;
    this->checkOutHour = 0;
    this->idStaff = 0;
    this->salary = 0.0;
    this->position = " ";
}

STAFF::STAFF(int idStaff, double salary, string position) : PERSON(), idStaff(idStaff), salary(salary), position(position), checkInHour(0), checkOutHour(0) {} // hàm khởi tạo đầy đủ tham số của lớp STAFF kế thừa từ lớp PERSON

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
    if (position == "Partime" || position == "partime") {
        return workingHours * 18000;
    } else if (position == "Fulltime" || position == "fulltime") {
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
    string order;
public:
    CUSTOMER();
    CUSTOMER(string customerID);
    void inputInformation();
    void outputInformation();
    void yourOrder();
    virtual ~CUSTOMER();
};

CUSTOMER::CUSTOMER() {
    this->customerID = " ";
}

CUSTOMER::CUSTOMER(string customerID) : PERSON(), customerID(customerID) {}

void CUSTOMER::inputInformation() {
    PERSON::inputInformation();
    cout << "Nhap ma khach hang: ";
    getline(cin, this->customerID);
}

void CUSTOMER::outputInformation() {
    PERSON::outputInformation();
    cout << "Customer ID: " << this->customerID << endl;
}

bool select[13];
void CUSTOMER::yourOrder(){
    cout << "Quan coffee NTN xin chao a!" << endl;
    cout << "Anh/chi muon dung gi a!" << endl;
    MENU menu;
    menu.displayInitialMenu();
    cout << "Day la menu ben minh a" << endl;
    for (int i = 0; i < 13; i++){
    select[i] = false;
    }
    int choice;
    cout << "Quy khach hay chon id mon ma minh muon oder" << endl;
    cin >> choice;
    switch(choice){
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13:
        cout << "Da oder thanh cong!" << endl;
        select[choice-1]=true;
        break;
        default:
        cout << "Lua chon cua quy khach khong hop le!" << endl;
    }
}


CUSTOMER::~CUSTOMER() {}

// struct Date{
//     int day;
//     int month;
//     int year;
// }; typedef struct Date date;

class TRANSACTION{
    private:
        int idTransaction; // mã hóa đơn
        string paymentMethod; // phương thức thanh toán (tiền mặt/TKNH)
        int dateTransaction;
    public:
        TRANSACTION();
        void calculateOrder(); // tính tổng tiền của đơn hàng vừa rồi
        void payment();
};

TRANSACTION::TRANSACTION(){
    idTransaction = 0;
    paymentMethod = " ";
    dateTransaction = 0;
}

void TRANSACTION::calculateOrder(){
    
}


int main() {
    // Tạo một quản lý với username: admin và password: 1234
    Admin admin("admin", "1234");
    EMPLOYEE empl ("LeQuocTrung", "12345");
    MENU menu;
    STAFF staff;
    CUSTOMER customer;
    menu.displayInitialMenu();
    int choice;
    do {
        cout << "\n1. Dang nhap voi tu cach la quan ly" << endl;
        cout << "2. Dang nhap voi tu cach la nhan vien" << endl;
        cout << "3. Them do an" << endl;
        cout << "4. Hien thi menu" << endl;
        cout << "5. Goi Mon " << endl;
        cout << "6. Dang xuat(Admin)" << endl;
        cout << "7. Dang xuat(Employee)" << endl;
        cout << "8. Thoat" << endl;
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
            staff.inputInformation();
            staff.checkIn();
            break;

        case 3:
            if (admin.isAdminLoggedIn()) {
                FOOD* food = new FOOD();
                    food->addFood();
                    menu.addProductToList(food); // Thêm sản phẩm vào menu  
                }
            else {
                cout << "Ban can dang nhap truoc!" << endl;
            }
            break;

        case 4:
            menu.displayMenu();
            break;
        case 5:
            customer.yourOrder();
            break;
        case 6:
            admin.logoutByAdmin();
            break;
        case 7:
            empl.logoutByEmployee();
            break;
        case 8:
            cout << "Ket thuc chuong trinh!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }

    } while (choice != 8);

    return 0;
}
