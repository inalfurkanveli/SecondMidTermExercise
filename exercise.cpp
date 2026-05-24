#include <iostream>
#include <string>
#include <vector>
#include <bits/chrono.h>
using namespace std;
class Vehicle {
protected:
    string brand;
    string model;
    double baseDailyRate;

public:
    Vehicle() {
        brand=" ";
        model=" ";
        baseDailyRate=0;
    }
    Vehicle(string brand,string model,double baseDailyRate) {
        this->brand=brand;
        this->model=model;
        this->baseDailyRate=baseDailyRate;
    }
    virtual double getCalculateRent(int days)=0;
    virtual void displayInfo(int days)=0;
};
class Car: public Vehicle {
protected:
    bool hasInsurence;
public:
    Car():Vehicle() {
        hasInsurence=false;
    }
    Car(string brand,string model,double baseDailyRate,bool hasInsurence):Vehicle(brand,model,baseDailyRate),
    hasInsurence(hasInsurence){
    };
    double getCalculateRent(int days) override {
        double dailyRate=baseDailyRate;
        if (hasInsurence) {
            dailyRate+=15.0;
        }
        else {
            return baseDailyRate*days;

        }
    }
    void displayInfo(int days) {
        //[Car] Brand: [brand] | Model: [model] |
        //Total Rent: [calculated_rent] EUR
        cout<<"Brand: "<<brand<<"| Model: "<<model<<" | Total Rent: "<<
            getCalculateRent(days)<<" EUR"<<endl;
    }

};
class Motorcycle: public Vehicle {
protected:
  bool helmetIncluded;
public:
    Motorcycle():Vehicle(),helmetIncluded(false) {
    }
    Motorcycle(string brand,string model,double dailyRate,bool helmetIncluded):Vehicle(brand,model,dailyRate),helmetIncluded(helmetIncluded) {
        this->helmetIncluded=helmetIncluded;
    }
    double getCalculateRent(int days) override {
        double total=baseDailyRate*days;
        if (helmetIncluded) {
            return total+10.0;
        }
        else {
            return total;
        }
    }
    void displayInfo(int days) {
        cout<<"Brand: "<<brand<<" | Model: "<<model<<" | Total Rent: "<<
            getCalculateRent(days)<<endl;
    }
};
void analyzeRentals(vector<Vehicle*> vehicles, int days) {
    double carRentTotal=0.0;
    double motorRentTotal=0.0;
    for (int i=0;i<vehicles.size();i++) {
        if (dynamic_cast<Car*>(vehicles[i])) {
            carRentTotal+=vehicles[i]->getCalculateRent(days);
        }
        else if (dynamic_cast<Motorcycle*>(vehicles[i])) {
            motorRentTotal+=vehicles[i]->getCalculateRent(days);
        }
    }
    if (carRentTotal>0) {
        cout<<"Total Car Rent: "<<carRentTotal<<endl;
    }else {
        cout<<"No Car Rent"<<endl;
    }
    if (motorRentTotal>0) {
        cout<<"Total Motorcycle: "<<motorRentTotal<<endl;
    }else {
        cout<<"No Motorcycle Rent"<<endl;
    }
};

int main() {
    vector<Vehicle*> rentals;
    rentals.push_back(new Car("BMW", "320i", 50.0, true));        // (50+15) * 3 = 195
    rentals.push_back(new Car("Fiat", "Egea", 30.0, false));      // 30 * 3 = 90
    rentals.push_back(new Motorcycle("Yamaha", "R6", 40.0, true)); // (40 * 3) + 10 = 130
    int rentalDays=5;
    cout << "--- Rental Details ---" << endl;
    for (Vehicle* v : rentals) {
        v->displayInfo(rentalDays);
    }

    cout << "\n--- Financial Analysis (For 3 Days) ---" << endl;
    analyzeRentals(rentals, 3);

    // Temizlik
    for (Vehicle* v : rentals) delete v;
    return 0;
}