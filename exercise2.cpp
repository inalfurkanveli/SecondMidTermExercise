//
// Created by FURKAN on 14.05.2026.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ticket {
protected:
    string eventName;
    string buyerName;
    double basePrice;

public:
    Ticket() {
        eventName = " ";
        buyerName = " ";
        basePrice = 0.0;
    }

    Ticket(string eventName, string buyerName, double basePrice) {
        this->eventName = eventName;
        this->buyerName = buyerName;
        this->basePrice = basePrice;
    }

    virtual double getPrice() =0;

    virtual void print() =0;
};

class PhysicalTicket : public Ticket {
private:
    double deliveryFee;

public:
    PhysicalTicket() : Ticket() {
        deliveryFee = 0.0;
    }

    PhysicalTicket(string eventName, string buyerName, double basePrice,
                   double deliveryFee) : Ticket(eventName, buyerName, basePrice),
                                         deliveryFee(deliveryFee) {
    };

    double getPrice() override {
        return basePrice + deliveryFee;
    };

    void print() override {
        cout << "[Physical] Buyer: " << buyerName << " | Event: " << eventName <<
                " | Total: " << getPrice() << " EUR" << endl;
    };
};

class ETicket : public Ticket {
private:
    bool earlyBird;

public:
    ETicket() : Ticket() {
        earlyBird = false;
    }

    ETicket(string eventName, string buyerName, double basePrice, bool earlyBird) : Ticket(eventName, buyerName,
            basePrice)
        , earlyBird(earlyBird) {
    };

    double getPrice() override {
        if (earlyBird) {
            return basePrice * 0.9;
        }
        return basePrice;
    };

    void print() override {
        cout << "[Digital] Buyer: " << buyerName << " | Event: " << eventName << " | Total: " << getPrice() << " EUR" <<
                endl;
    };
};

void analyzeTickets(vector<Ticket *> tickets) {
    double totalPhy = 0.0;
    double totalDigi = 0.0;
    for (int i = 0; i < tickets.size(); i++) {
        if (dynamic_cast<PhysicalTicket *>(tickets[i])) {
            totalPhy += tickets[i]->getPrice();
        } else if (dynamic_cast<ETicket *>(tickets[i])) {
            totalDigi += tickets[i]->getPrice();
        }
    }
    if (totalPhy > 0) {
        cout << "Physical Tickets: " << totalPhy << endl;
    } else {
        cout << "No physical tickets" << endl;
    }
    if (totalDigi > 0) {
        cout << "Digital Tickets: " << totalDigi << endl;
    } else {
        cout << "No digital tickets" << endl;
    }
};

//DO NOT CHANGE MAIN FUNCTION


int main() {
    int testCase;
    cin >> testCase;

    string eventName;
    string buyerName;
    double basePrice;
    double deliveryFee;
    bool earlyBird;
    char type;

    switch (testCase) {
        case 1: {
            cout << "TESTING CONSTRUCTORS" << endl;
            Ticket *t;
            cin >> eventName >> buyerName >> basePrice >> deliveryFee >> earlyBird;
            PhysicalTicket pt(eventName, buyerName, basePrice, deliveryFee);
            ETicket et(eventName, buyerName, basePrice, earlyBird);
            cout << "TEST PASSED" << endl;
            break;
        }
        case 2: {
            cout << "TESTING TICKET getPrice" << endl;
            cin >> type;
            Ticket *t;
            if (type == 'P') {
                cin >> eventName >> buyerName >> basePrice >> deliveryFee;
                t = new PhysicalTicket(eventName, buyerName, basePrice, deliveryFee);
            } else {
                cin >> eventName >> buyerName >> basePrice >> earlyBird;
                t = new ETicket(eventName, buyerName, basePrice, earlyBird);
            }
            cout << t->getPrice() << endl;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 3: {
            cout << "TESTING TICKET print" << endl;
            cin >> type;
            Ticket *t;
            if (type == 'P') {
                cin >> eventName >> buyerName >> basePrice >> deliveryFee;
                t = new PhysicalTicket(eventName, buyerName, basePrice, deliveryFee);
            } else {
                cin >> eventName >> buyerName >> basePrice >> earlyBird;
                t = new ETicket(eventName, buyerName, basePrice, earlyBird);
            }
            t->print();
            cout << "TEST PASSED" << endl;
            break;
        }
        case 4: {
            cout << "TESTING GLOBAL METHOD analyzeTickets" << endl;
            int n;
            cin >> n;
            vector<Ticket *> tickets;
            Ticket *t;

            for (int i = 0; i < n; i++) {
                cin >> type;
                if (type == 'P') {
                    cin >> eventName >> buyerName >> basePrice >> deliveryFee;
                    t = new PhysicalTicket(eventName, buyerName, basePrice, deliveryFee);
                } else {
                    cin >> eventName >> buyerName >> basePrice >> earlyBird;
                    t = new ETicket(eventName, buyerName, basePrice, earlyBird);
                }
                tickets.push_back(t);
            }
            analyzeTickets(tickets);
            break;
        }
    }
};
