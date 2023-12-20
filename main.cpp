#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Venicle{
protected:
    string brand;
    string model;
    int year;
    string Owner;
    bool Registration;
    string Motor_type;
    int original_price;
public:
    Venicle(string brand,string model,int year,string Owner,bool Registration,string Motor_type,int original_price){
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->Owner = Owner;
        this->Registration = Registration;
        this->Motor_type = Motor_type;
        this->original_price = original_price;

    }

    Venicle() {
        this->brand = "Not specified";
        this->model = "Not specified";
        this->year = 0;
        this->Owner = "Not specified";
        this->Registration = 0;
        this->Motor_type = "Not specified";
        this->original_price = 0;
    }

    Venicle(Venicle const& other){
        this->brand = other.brand;
        this->model = other.model;
        this->year = other.year;
        this->Owner = other.Owner;
        this->Registration = other.Registration;
        this->Motor_type = other.Motor_type;
        this->original_price = other.original_price;

    }



    void setBrand(string new_brand){
        brand = new_brand;
    }
    void setModel(string new_model){
        model = new_model;
    }
    void setYear(int new_year){
        year = new_year;
    }
    void setOwner(string new_owner){
        Owner = new_owner;
    }
    void setRegistration(bool new_registration){
        Registration - new_registration;
    }
    void setMotor_type(string new_motor_type){
        Motor_type = new_motor_type;
    }
    void setOriginal_price(int new_original_price){
        original_price = new_original_price;
    }
    void SetAll(string new_brand,string new_model,int new_year, string new_owner,bool new_registration,string new_motor_type,int new_original_price){
        brand = new_brand;
        model = new_model;
        year = new_year;
        Owner = new_owner;
        Registration - new_registration;
        Motor_type = new_motor_type;
        original_price = new_original_price;
    }

    void getBrand(){
        cout << "Brand: " << brand<<endl;
    }
    void getModel(){
        cout << "Model: " << model<<endl;
    }
    void getYear(){
        cout << "Year: " << year<<endl;
    }
    void getOwner(){
        cout << "Owner: " << Owner<<endl;
    }
    void getRegistration(){
        if(Registration == 1)
            cout << "Car is registred"<<endl;
        else
            cout << "Car is NOT registred"<<endl;
    }
    void getMotor_type(){
        cout << "Motor type: " << Motor_type<<endl;
    }
    void getOriginal_price(){
        cout << "Original price: " << original_price<<endl;
    }
    void getAll(){
        cout << "Brand: " << brand<<endl;
        cout << "Model: " << model<<endl;
        cout << "Year: " << year<<endl;
        cout << "Owner: " << Owner<<endl;
        if(Registration == 1)
            cout << "Car is registred"<<endl;
        else
            cout << "Car is NOT registred"<<endl;
        cout << "Motor type: " << Motor_type<<endl;
        cout << "Original price: " << original_price<<endl;
    }
    void Writing_to_file(const string& filename){               //возможно const!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ofstream file(filename);

        if (file.is_open()){
            file << brand << endl;
            file << model<< endl;
            file << year<< endl;
            file << Owner<< endl;
            file << Registration<< endl;
            file << Motor_type<< endl;
            file << original_price<< endl;
            file.close();
            cout << "Writing to the file has been completed" << endl;
        }
        else
            cout << "Writing to the file has NOT been completed" << endl;
    }

    void Reading_from_file(const string& filename){               //возможно const!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ifstream file(filename);

        if (file.is_open()){
            string line;
            while (getline(file,line)){
                cout << line << endl;
            }
            file.close();
            cout << "Reading to the file has been completed" << endl;
        }
        else
            cout << "Reading to the file has NOT been completed" << endl;
    }


protected:
    virtual void Register_car(){
        int price = 1;
        cout << "Cost of registration: "<< price << endl;
        cout << "Registration was successful"<<endl;
    }
    virtual void Rent_car(int days){
        int price = 1;
        cout << "Cost of rent: "<< price*days << endl;
        cout << "rent is taken for "<< days << "days" << endl;
    }
};

class Passenger_Venicle : public Venicle{
public:
    int mileage;
    void setmileage(int new_mileage){
        mileage = new_mileage;
    }
    void getmileage(){
        cout << "mileage: " << mileage<<endl;
    }
    void SetAll(string new_brand,string new_model,int new_year, string new_owner,bool new_registration,string new_motor_type,int new_original_price,int new_mileage){
        brand = new_brand;
        model = new_model;
        year = new_year;
        Owner = new_owner;
        Registration - new_registration;
        Motor_type = new_motor_type;
        original_price = new_original_price;
        mileage = new_mileage;
    }
    void getAll(){
        cout << "Brand: " << brand<<endl;
        cout << "Model: " << model<<endl;
        cout << "Year: " << year<<endl;
        cout << "Owner: " << Owner<<endl;
        if(Registration == 1)
            cout << "Car is registred"<<endl;
        else
            cout << "Car is NOT registred"<<endl;
        cout << "Motor type: " << Motor_type<<endl;
        cout << "Original price: " << original_price<<endl;
        cout << "mileage: " << mileage<<endl;
    }
    void Register_car(){
        float price = 2000;
        if (year<2005)
            price = price * 0.75;
        if (original_price > 10000000)
            price = price*3;
        if (mileage > 500000)
            price = price*1.25;
        cout << "Cost of registration: "<< price << endl;
        Registration = 1;
        cout << "Registration was successful"<<endl;
    }
    void Rent_car(int days){
        float rent;
        if (year <= 2000)
            rent = 1000;
        if (2000< year <= 2010)
            rent = 1500;
        if (2010< year <= 2020)
            rent = 2000;
        if (year>2020)
            rent = 2500;

        if (original_price<1000000)
            rent=rent*0.75;
        if (1000000<=original_price<10000000)
            rent=rent*1.1;
        if (original_price>10000000)
            rent=rent*2;


        if (mileage > 500000)
            rent = rent*0.9;

        cout << "Cost of rent: "<< rent*days << endl;
        cout << "rent is taken for "<< days << "days" << endl;
    }
};

class Truck : public Venicle{
public:
    int payload;
    void setPayload(int new_payload){
        payload = new_payload;
    }
    void getPayload(){
        cout << "Payload: " << payload<<endl;
    }
    void SetAll(string new_brand,string new_model,int new_year, string new_owner,bool new_registration,string new_motor_type,int new_original_price,int new_payload){
        brand = new_brand;
        model = new_model;
        year = new_year;
        Owner = new_owner;
        Registration - new_registration;
        Motor_type = new_motor_type;
        original_price = new_original_price;
        payload = new_payload;
    }
    void getAll(){
        cout << "Brand: " << brand<<endl;
        cout << "Model: " << model<<endl;
        cout << "Year: " << year<<endl;
        cout << "Owner: " << Owner<<endl;
        if(Registration == 1)
            cout << "Car is registred"<<endl;
        else
            cout << "Car is NOT registred"<<endl;
        cout << "Motor type: " << Motor_type<<endl;
        cout << "Original price: " << original_price<<endl;
        cout << "Payload: " << payload<<endl;
    }
    void Register_car(){
        float price = 10000;
        if (year<2000)
            price = price * 0.25;
        if (original_price > 15000000)
            price = price*2.1;
        if (payload < 1000)
            price = price*0.75;
        cout << "Cost of registration: "<< price << endl;
        Registration = 1;
        cout << "Registration was successful"<<endl;
    }
    void Rent_car(int days){
        float rent;
        if (year <= 2000)
            rent = 5000;
        if (2000< year <= 2010)
            rent = 7500;
        if (2010< year <= 2020)
            rent = 12500;
        if (year>2020)
            rent = 17000;

        if (Motor_type == "Electric")
            rent = rent * 0.75;

        cout << "Cost of rent: "<< rent*days << endl;
        cout << "rent is taken for "<< days << "days" << endl;
    }
};

class Bike : public Venicle{
public:
    int weight;
    void setweight(int new_weight){
        weight = new_weight;
    }
    void getweight(){
        cout << "weight: " << weight<<endl;
    }
    void SetAll(string new_brand,string new_model,int new_year, string new_owner,bool new_registration,string new_motor_type,int new_original_price,int new_weight){
        brand = new_brand;
        model = new_model;
        year = new_year;
        Owner = new_owner;
        Registration - new_registration;
        Motor_type = new_motor_type;
        original_price = new_original_price;
        weight = weight;
    }
    void getAll(){
        cout << "Brand: " << brand<<endl;
        cout << "Model: " << model<<endl;
        cout << "Year: " << year<<endl;
        cout << "Owner: " << Owner<<endl;
        if(Registration == 1)
            cout << "Car is registred"<<endl;
        else
            cout << "Car is NOT registred"<<endl;
        cout << "Motor type: " << Motor_type<<endl;
        cout << "Original price: " << original_price<<endl;
        cout << "weight: " << weight<<endl;
    }
    void Register_car(){
        float price = 1500;
        if (year<2005)
            price = price * 0.5;
        if (original_price > 500000)
            price = price*1.25;
        if (weight < 100)
            price = price*0.5;
        cout << "Cost of registration: "<< price << endl;
        Registration = 1;
        cout << "Registration was successful"<<endl;
    }
    void Rent_car(int days){
        float rent;
        if (year <= 2000)
            rent = 500;
        if (2000< year <= 2010)
            rent = 750;
        if (2010< year <= 2020)
            rent = 925;
        if (year>2020)
            rent = 1100;


        if (Motor_type == "Electric")
            rent = rent * 0.9;


        cout << "Cost of rent: "<< rent*days << endl;
        cout << "rent is taken for "<< days << "days" << endl;
    }
};


class Customer{
private:

    int Driving_Experiense;
    string phone_number;
public:
    string LastName;
    string FirstName;
    int number_of_requests;
    int bonus;
    Customer(string FirstName,string Last_Name,int Driving_experience,string phone_number,int bonus,int number_of_requests){
        this->FirstName=FirstName;
        this->LastName=Last_Name;
        this->Driving_Experiense=Driving_experience;
        this->phone_number = phone_number;
        this->number_of_requests = number_of_requests;
        this->bonus = bonus;
    }
    Customer(){
        this->FirstName="Not specified";
        this->LastName="Not specified";
        this->Driving_Experiense=0;
        this->phone_number = "Not specified";
        this->number_of_requests = 0;
        this->bonus = 0;
    }
    Customer(Customer const& other){
        this->FirstName=other.FirstName;
        this->LastName=other.LastName;
        this->Driving_Experiense=other.Driving_Experiense;
        this->phone_number = other.phone_number;
        this->bonus = other.bonus;
    }


    void setFirstName(string new_FirstName){
        FirstName = new_FirstName;
    }
    void setLastName(string new_LastName){
        LastName = new_LastName;
    }
    void setDrivingExperience(int new_driving_experience){
        Driving_Experiense = new_driving_experience;
    }
    void setphone_number(string new_phone_number){
        phone_number = new_phone_number;
    }
    void setNumber_of_requests(int new_number){
        number_of_requests = new_number;
    }
    void setBonus(int new_bonus){
        bonus = new_bonus;
    }
    void setAll(string new_FirstName,string new_LastName,int new_driving_experience,string new_phone_number,int new_number,int new_bonus){
        FirstName = new_FirstName;
        LastName = new_LastName;
        Driving_Experiense = new_driving_experience;
        phone_number = new_phone_number;
        number_of_requests = new_number;
        bonus = new_bonus;

    }

    void getFirstName(){
        cout<<"First name: " << FirstName<<endl;
    }
    void getLastName(){
        cout<<"Last name: " << LastName<<endl;
    }
    void getDrivingExperience(){
        cout<<"Driving experience: " << Driving_Experiense<<endl;
    }
    void getPhone_number(){
        cout<<"Phone number: " << phone_number<<endl;
    }
    void getNumber_of_requests(){
        cout<<"Number of requests: " << number_of_requests<<endl;
    }
    void getBonus(){
        cout<<"Bonus: " << bonus <<endl;
    }
    void getAll(){
        cout<<"First name: " << FirstName<<endl;
        cout<<"Last name: " << LastName<<endl;
        cout<<"Driving experience: " << Driving_Experiense<<endl;
        cout<<"Phone number: " << phone_number<<endl;
        cout<<"Number of requests: " << number_of_requests<<endl;
        cout<<"Bonus: " << bonus <<endl;
    }


    void Writing_to_file(const string& filename){               //возможно const!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ofstream file(filename);

        if (file.is_open()){
            file << FirstName << endl;
            file << LastName<< endl;
            file << Driving_Experiense<< endl;
            file << phone_number<< endl;
            file.close();
            cout << "Writing to the file has been completed" << endl;
        }
        else
            cout << "Writing to the file has NOT been completed" << endl;
    }

    void Reading_from_file(const string& filename){               //возможно const!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ifstream file(filename);

        if (file.is_open()){
            string line;
            int i = 0;
            while (getline(file,line)){
                if (i==0)
                    FirstName = line;
                if (i==1)
                    LastName = line;
                if (i==2)
                    Driving_Experiense = stoi(line);
                if (i==3)
                    phone_number = line;
                i=i+1;

            }
            file.close();
            cout << "Reading to the file has been completed" << endl;
        }
        else
            cout << "Reading to the file has NOT been completed" << endl;
    }
    Customer operator+(int a){
        Customer A;
        A.bonus = bonus + a;
        return A;
    }
    Customer operator -(int a){
        Customer A;
        A.bonus = bonus - a;
        return A;
    }



};

class MaintanceRecord{
private:
    string Service;
    int cost;
    int time;
public:
    MaintanceRecord(){
        Service = "Not specified";
        cost = 0;
        time = 0;
    }
    MaintanceRecord(string new_Service, int new_cost, int new_time){
        Service = new_Service;
        cost = new_cost;
        time = new_time;
    }
    MaintanceRecord(MaintanceRecord const& other){
        Service = other.Service;
        cost = other.cost;
        time = other.time;
    }


    void setService(string new_Service){
        Service = new_Service;
    }
    void setAll(string new_Service, int new_time,int new_cost){
        Service = new_Service;
    }

    void getService(){
        cout << "Service: " << Service<<endl;
    }
    void getPrice(){
        cout << "Cost: " << cost <<endl;
    }
    void getTime(){
        if (time < 2)
            cout << "Time: " << time << "hour" << endl;
        else
            cout << "Time: " << time << "hours" << endl;
    }
    void getAll(){
        cout << "Service: " << Service<<endl;
        cout << "Cost: " << cost << endl;
        if (time < 2)
            cout << "Time: " << time << "hour" << endl;
        else
            cout << "Time: " << time << "hours" << endl;
    }
    void Schedueld_maintenance(Customer A,Passenger_Venicle B){
        A.number_of_requests = A.number_of_requests + 1;
        Service = "Schedueld maintenance";
        cost = 15000;
        time = 24;
    }
    void Tire_replacement(Customer A,Passenger_Venicle B){
        A.number_of_requests = A.number_of_requests + 1;
        Service = "Tire replacement";
        cost = 3000;
        time = 1;
    }
    void Wasching(Customer A,Passenger_Venicle B){
        A.number_of_requests = A.number_of_requests + 1;
        Service = "Wasching";
        cost = 600;
        time = 2;
    }
    void Schedueld_maintenance(Customer A,Truck B){
        A.number_of_requests = A.number_of_requests + 1;
        Service = "Schedueld maintenance";
        cost = 35000;
        time = 48;
    }
    void Tire_replacement(Customer A,Truck B){
        A.number_of_requests = A.number_of_requests + 1;
        Service = "Tire replacement";
        cost = 5000;
        time = 1;
    }
    void Wasching(Customer A,Truck B){
        A.number_of_requests = A.number_of_requests + 1;
        Service = "Wasching";
        cost = 2000;
        time = 1;
    }

    void Schedueld_maintenance(Customer A,Bike B){
        A.number_of_requests = A.number_of_requests + 1;
        Service = "Schedueld maintenance";
        cost = 11500;
        time = 12;
    }
    void Tire_replacement(Customer A,Bike B){
        A.number_of_requests = A.number_of_requests + 1;
        Service = "Tire replacement";
        cost = 1000;
        time = 1;
    }
    void Wasching(Customer A,Bike B){
        A.number_of_requests = A.number_of_requests + 1;
        Service = "Wasching";
        cost = 450;
        time = 1;
    }

};

int main(){

    cout << "hello, please provide your personal information" <<endl;
    cout<< "Your first name: ";
    string a;
    cin >> a;
    cout<<endl;
    cout<< "Your last name: ";
    string b;
    cin >> b;
    cout<<endl;
    cout<< "Your driving experience: ";
    int c;
    cin >> c;
    cout<<endl;
    cout<< "Your phone number: ";
    string e;
    cin >> e;
    cout<<endl;
    Customer Client1(a,b,c,e,0,0);
    Client1.getAll();

    Client1 = Client1 + 200;
    Client1 = Client1 - 50;
    Client1.getBonus();



    Customer Client2;
    Client2.Reading_from_file("proverka.txt");
    Client2.getAll();
    Client2.Writing_to_file("test.txt");





    cout<<"what type of car are you interested in  ";
    string f;
    cin >> f;
    if (f == "Passenger_Venicle"){
        Passenger_Venicle Car1;
        string a1;
        cout << "Model: ";
        cin >> a1;
        Car1.setModel(a1);
        cout << endl;
        string a2;
        cout << "Brand: ";
        cin >> a2;
        Car1.setBrand(a2);
        cout << endl;
        int a3;
        cout << "Year: ";
        cin >> a3;
        Car1.setYear(a3);
        cout << endl;
        string a4;
        a4 = Client1.FirstName + " " + Client1.LastName;
        Car1.setOwner(a4);
        cout << endl;
        bool a5;
        cout << "is the car registered or not: ";
        cin >> a5;
        Car1.setRegistration(a5);
        cout << endl;
        string a6;
        cout << "Motor type: ";
        cin >> a6;
        Car1.setMotor_type(a6);
        cout << endl;
        int a7;
        cout << "Original price: ";
        cin >> a7;
        Car1.setOriginal_price(a7);
        cout << endl;
        int a8;
        cout << "Mileage: ";
        cin >> a8;
        Car1.setmileage(a8);
        cout << endl;
        Car1.getAll();

        cout << "What do you want to do?";
        string f2;
        cin >> f2;
        cout << endl;
        if (f2=="Rent"){
            int a2;
            cout << "Days: ";
            cin >> a2;
            cout << endl;
            Car1.Rent_car(a2);
        }
        if (f2=="Registration"){
            Car1.Register_car();
        }
        if (f2 == "Schedueld_maintenance"){
            MaintanceRecord repair1;
            repair1.Schedueld_maintenance(Client1,Car1);
            repair1.getAll();
        }
        if (f2 == "Tire_replacement"){
            MaintanceRecord repair1;
            repair1.Tire_replacement(Client1,Car1);
            repair1.getAll();
        }
        if (f2 == "Washing"){
            MaintanceRecord repair1;
            repair1.Wasching(Client1,Car1);
            repair1.getAll();
        }
    }
    if (f == "Truck"){
        Truck Car1;
        string a1;
        cout << "Model: ";
        cin >> a1;
        Car1.setModel(a1);
        cout << endl;
        string a2;
        cout << "Brand: ";
        cin >> a2;
        Car1.setBrand(a2);
        cout << endl;
        int a3;
        cout << "Year: ";
        cin >> a3;
        Car1.setYear(a3);
        cout << endl;
        string a4;
        a4 = Client1.FirstName + " " + Client1.LastName;
        Car1.setOwner(a4);
        cout << endl;
        bool a5;
        cout << "is the car registered or not: ";
        cin >> a5;
        Car1.setRegistration(a5);
        cout << endl;
        string a6;
        cout << "Motor type: ";
        cin >> a6;
        Car1.setMotor_type(a6);
        cout << endl;
        int a7;
        cout << "Original price: ";
        cin >> a7;
        Car1.setOriginal_price(a7);
        cout << endl;
        int a8;
        cout << "Payload: ";
        cin >> a8;
        Car1.setPayload(a8);
        cout << endl;
        Car1.getAll();

        cout << "What do you want to do?";
        string f2;
        cin >> f2;
        cout << endl;
        if (f2=="Rent"){
            int a2;
            cout << "Days: ";
            cin >> a2;
            cout << endl;
            Car1.Rent_car(a2);
        }
        if (f2=="Registration"){
            Car1.Register_car();
        }
        if (f2 == "Schedueld_maintenance"){
            MaintanceRecord repair1;
            repair1.Schedueld_maintenance(Client1,Car1);
            repair1.getAll();
        }
        if (f2 == "Tire_replacement"){
            MaintanceRecord repair1;
            repair1.Tire_replacement(Client1,Car1);
            repair1.getAll();
        }
        if (f2 == "Washing"){
            MaintanceRecord repair1;
            repair1.Wasching(Client1,Car1);
            repair1.getAll();
        }
    }
    if (f == "Bike"){
        Bike Car1;
        string a1;
        cout << "Model: ";
        cin >> a1;
        Car1.setModel(a1);
        cout << endl;
        string a2;
        cout << "Brand: ";
        cin >> a2;
        Car1.setBrand(a2);
        cout << endl;
        int a3;
        cout << "Year: ";
        cin >> a3;
        Car1.setYear(a3);
        cout << endl;
        string a4;
        a4 = Client1.FirstName + " " + Client1.LastName;
        Car1.setOwner(a4);
        cout << endl;
        bool a5;
        cout << "is the car registered or not: ";
        cin >> a5;
        Car1.setRegistration(a5);
        cout << endl;
        string a6;
        cout << "Motor type: ";
        cin >> a6;
        Car1.setMotor_type(a6);
        cout << endl;
        int a7;
        cout << "Original price: ";
        cin >> a7;
        Car1.setOriginal_price(a7);
        cout << endl;
        int a8;
        cout << "weight: ";
        cin >> a8;
        Car1.setweight(a8);
        cout << endl;
        Car1.getAll();

        cout << "What do you want to do?";
        string f2;
        cin >> f2;
        cout << endl;
        if (f2=="Rent"){
            int a2;
            cout << "Days: ";
            cin >> a2;
            cout << endl;
            Car1.Rent_car(a2);
        }
        if (f2=="Registration"){
            Car1.Register_car();
        }
        if (f2 == "Schedueld_maintenance"){
            MaintanceRecord repair1;
            repair1.Schedueld_maintenance(Client1,Car1);
            repair1.getAll();
        }
        if (f2 == "Tire_replacement"){
            MaintanceRecord repair1;
            repair1.Tire_replacement(Client1,Car1);
            repair1.getAll();
        }
        if (f2 == "Washing"){
            MaintanceRecord repair1;
            repair1.Wasching(Client1,Car1);
            repair1.getAll();
        }
    }








    return 0;
}