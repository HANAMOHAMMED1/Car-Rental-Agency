#include <iostream>
using namespace std;

class Person{
    string name; 
    string surname;
    int age;
    
    public:
    
    Person(string name = "" , string surname = "", int age = 0){
        this->name = name;
        this->surname = surname;
        this->age = age;
    }
    void display(){
        cout << "Name: " << this->getName() << endl;
        cout << "Surname: " << this->getSurname() << endl;
        cout << "Age: " << this->age << endl;
    }
    
    string getName(){
        return this->name;
    }
    string getSurname(){
        return this->surname;
    }
};

class Client : public Person{
    int clientId;
    
    public:
    
    Client(string name = ""  , string surname = "" , int age = 0,
    int clientId = 0): Person(name,surname,age){
        this->clientId = clientId;
    }
    
    void displayClient(){
        Person::display();
        cout << "Client id: " << this->getId() << endl;
    }
    
    int getId(){
        return this->clientId;
    }
    
};

class Worker{
    string position;
    double salary;
    
    public:
    
    Worker(string position = "" , double salary = 0){
        this->position = position;
        this->salary = salary;
    }
    
    void displayWorker(){
        cout << "Position: " << this->position << endl;
        cout << "Salary: " << this->salary << endl;
    }
};

class Employee : public Person, public Worker{
    
    public:
    
    Employee(string name = ""  , string surname = ""  ,
    int age = 0, string position = "", double salary = 0):
    Person(name, surname, age), Worker(position, salary){}
    
    void displayEmployee(){
        Person::display();
        Worker::displayWorker();
    }
};

class Car{
    
    string licensePlate;
    string brand;
    string model;
    int year;
    double dailyPrice;
    bool available;
    
    
    public:
    
    Car(string licensePlate = "", string brand = "", string model = "",
    int year = 0, double dailyPrice = 0, bool available = false){
        
        this->licensePlate = licensePlate;
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->dailyPrice = dailyPrice;
        this->available = available;
    }
    
    void display(){
        cout << "License Plate: " << this->getLicensePlate() << endl;
        cout << "Brand: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout << "Year: " << this->year << endl;
        cout << "Daily Prices: " << this->getPricePerDay() << endl;
        cout << "Availablity: " << (this->isAvailable() ) ? 
        "Available:)" :"Not Available:(" ;
        cout<< endl;
    }
    
    bool isAvailable(){
        return this->available;
    }
    
    void setAvailability(bool a){
        this->available = a;
    }
    
    double getPricePerDay() const {
        return this->dailyPrice;
    }
    
    string getLicensePlate() const {
        return this->licensePlate;
    }
    
    bool operator==(const Car& other){  //license
        if(this->getLicensePlate() == other.getLicensePlate() ){
            return true;
        } else {
            return false;
        }
    }
    
    bool operator<(const Car& other){ //price
        if(this->getPricePerDay() < other.getPricePerDay() ){
            return true;
        } else {
            return false;
        }
    }
};

class Agency{
    
    string agencyName;
    string address;
    Car cars[50];
    Client clients[50];
    Employee employees[10];
    int carCount, clientCount, employeeCount;

    public:    
    
    Agency(string address = "", string agencyName = ""){
        this->carCount = this->clientCount = this->employeeCount = 0;
        this->address = address;
        this->agencyName = agencyName;
    }
    
    void addCar(Car c){
        if(this->carCount < 50){
            this->cars[this->carCount] = c;
            this->carCount++ ;
        } else {
            cout << "Cannot store more cars\n";
        }
    }
    
    void addClient(Client c){
        if(this->clientCount < 50){
            this->clients[this->clientCount] = c;
            this->clientCount++;
        } else {
            cout << "Cannot store more clients \n";
        }   
    }
    
    void addEmployee(Employee e){
        if(this->employeeCount < 10){
            this->employees[this->employeeCount] = e;
            this->employeeCount++;
        } else {
            cout << "Cannot store more employees\n";
        }
    }
    
    void showAvailableCars(){
        for(int i = 0 ; i < this->carCount; i++){
            if(this->cars[i].isAvailable()){
                this->cars[i].display();
                cout << "-----------------------------" << endl; 
            }
        }
    }
    
    void processRental(Client client, Car &car){
        int i = 0;
        bool foundCar = false;
        while(i < carCount){
            if(cars[i] == car){
                foundCar = true;
                break;
            }
        i++;
    }
        int j = 0;
        bool foundClient = false;
        while(j < clientCount){
            if(clients[j].getId() == client.getId()){
                foundClient = true;
                break;
            }
        j++;
    }
        if(foundCar == false || foundClient == false){
            cout << "The Car OR client not found in the Agency\n" ;
        } else {
            if(cars[i].isAvailable()){
                cout << "Client details:\n";
                clients[j].displayClient();
                cout << "Car details:\n";
                cars[i].display();
                cout << "The 5-days renting price in 'Ryals': " 
                << cars[i].getPricePerDay() *5 << endl;
                cout << "The car is available for this client only \n";
                cars[i].setAvailability(false);
            } else {
                cout << "the car is not available for renting\n";
            }
        }

    }
};

int main(){
    
    cout << "\n============== ALJOMAIH  ===============";
    cout << "\n\n=======CAR RENTAL AGENCY SYSTEM=========\n\n";


    Agency a("Qassim", "Aljomaih");
    
   
    Car c1("AAA-111", "GMC", "Yukon",   2026, 250, true);
    Car c2("BBB-222", "GMC", "Terrain", 2025, 150, true);
    Car c3("CCC-333", "GMC", "Acadia",  2024, 180, true);

   
    a.addCar( c1 );
    a.addCar( c2 );
    a.addCar( c3 );
   
   
    Client cm1("Mohammed", "Alshammari", 40, 101);
    Client cm2("Abdullah", "Alanzi",     20, 202);
    Client cm3("Abdulaziz","Altuwijri",  27, 303);
    
    a.addClient( cm1 );
    a.addClient( cm2 );
    a.addClient( cm3 );
    
    Employee e1("Hana", "Alsaleh", 21, "Cyber Security Analyst", 12000);
    Employee e2("Leen", "Alsaleh", 20, "IT Support Engineer", 10000);
   
    a.addEmployee( e1 );
    a.addEmployee( e2 );
    
    a.showAvailableCars();

    
    if(c1 == c2){
        cout << "Both cars have the same license Plate\n";
    } else {
        cout << "Both cars do not have the same license Plate\n";
    }
    cout << "\n\n-------------------------\n\n";
    

    if(c1 < c2){
        cout << "Second car is more expensive than the first car\n";
    } else {
        cout << "First car is more expensive than the second car\n";
    }
    cout << "\n\n-------------------------\n\n";
    
   
    a.processRental(cm1, c2);
    cout << "\n\n-------------------------\n\n";
    
    a.showAvailableCars();

    e1.displayEmployee();
    
    return 0;
}
