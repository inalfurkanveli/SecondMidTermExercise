/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Subscription {
protected:
    string serviceName;
    string subscriberName;
    double monthlyRate;
public:
    Subscription() {
        serviceName=" ";
        subscriberName="";
        monthlyRate = 0;
    }
    Subscription(string serviceName, string subscriberName,double monthlyRate) {
        this->serviceName = serviceName;
        this->subscriberName=subscriberName;
        this->monthlyRate=monthlyRate;
    }
    virtual double calculateMonthlyCharge()=0;
    virtual void display()=0;
};
class PremiumSubscription:public Subscription {
private:
    double supportFee;
public:
    PremiumSubscription(string serviceName, string subscriberName, double
        monthlyRate,double supportFee):Subscription(serviceName,subscriberName,monthlyRate),
    supportFee(supportFee){};
    double calculateMonthlyCharge() override {
        return monthlyRate+supportFee;

    };
    void display() override {
      //[Premium] Subscriber: [subscriberName] | Service: [serviceName]
      //| Monthly Charge: [amount] USD
        cout<<"[Premium] Subscriber: "<<subscriberName<<" | Service: "<<serviceName<<" | Monthly Charge: "<<
            calculateMonthlyCharge()<<" USD"<<endl;
    };

};
class BasicSubscription: public Subscription {
private:
    bool hasDiscount;
public:
    BasicSubscription():Subscription() {
        hasDiscount=false;
    }
    BasicSubscription(string serviceName, string subscriberName, double monthlyRate, bool hasDiscount):Subscription(serviceName,subscriberName,monthlyRate)
    ,hasDiscount(hasDiscount){};
    double calculateMonthlyCharge() override {
        if (hasDiscount) {
            return monthlyRate*0.8;
        }
        return monthlyRate;

    };
    void display() override {
      cout<<"[Basic] Subscriber: "<<subscriberName<<" | Service: "<<serviceName<<" | Monthly Charge: "
        <<calculateMonthlyCharge()<<" USD"<<endl;
    }
};
void analyzeSubscriptions(vector<Subscription*> subs) {
    double preAmount=0.0;
    double basicAmount=0.0;
    for (int i=0;i<subs.size();i++) {
        if (dynamic_cast<PremiumSubscription*>(subs[i])) {
            preAmount+=subs[i]->calculateMonthlyCharge();
        }
        else if (dynamic_cast<BasicSubscription*>(subs[i])){
            basicAmount+=subs[i]->calculateMonthlyCharge();
        }
    }
    if (preAmount>0) {
        cout<<"Premium Subscriptions: "<<preAmount<<endl;
    }else {
        cout<<"No Premium Subscriptions"<<endl;
    }
    if (basicAmount>0) {
        cout<<"Basic Subscriptions: "<<basicAmount<<endl;
    }else {
        cout<<"No basic Subscriptions"<<endl;
    }
};



int main() {
    int testCase;
    cin >> testCase;

    string serviceName, subscriberName;
    double monthlyRate, supportFee;
    bool hasDiscount;
    char type;

    switch (testCase) {
        case 1: {
            cout << "TESTING CONSTRUCTORS" << endl;
            cin >> serviceName >> subscriberName >> monthlyRate >> supportFee >> hasDiscount;
            PremiumSubscription ps(serviceName, subscriberName, monthlyRate, supportFee);
            BasicSubscription bs(serviceName, subscriberName, monthlyRate, hasDiscount);
            cout << "TEST PASSED" << endl;
            break;
        }
        case 2: {
            cout << "TESTING calculateMonthlyCharge" << endl;
            Subscription *s;
            cin >> type;
            if (type == 'P') {
                cin >> serviceName >> subscriberName >> monthlyRate >> supportFee;
                s = new PremiumSubscription(serviceName, subscriberName, monthlyRate, supportFee);
            } else {
                cin >> serviceName >> subscriberName >> monthlyRate >> hasDiscount;
                s = new BasicSubscription(serviceName, subscriberName, monthlyRate, hasDiscount);
            }
            cout << s->calculateMonthlyCharge() << endl;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 3: {
            cout << "TESTING display METHOD" << endl;
            Subscription *s;
            cin >> type;
            if (type == 'P') {
                cin >> serviceName >> subscriberName >> monthlyRate >> supportFee;
                s = new PremiumSubscription(serviceName, subscriberName, monthlyRate, supportFee);
            } else {
                cin >> serviceName >> subscriberName >> monthlyRate >> hasDiscount;
                s = new BasicSubscription(serviceName, subscriberName, monthlyRate, hasDiscount);
            }
            s->display();
            cout << "TEST PASSED" << endl;
            break;
        }
        case 4: {
            cout << "TESTING analyzeSubscriptions FUNCTION" << endl;
            int n;
            cin >> n;
            vector<Subscription*> subs;
            for (int i = 0; i < n; i++) {
                cin >> type;
                Subscription *s;
                if (type == 'P') {
                    cin >> serviceName >> subscriberName >> monthlyRate >> supportFee;
                    s = new PremiumSubscription(serviceName, subscriberName, monthlyRate, supportFee);
                } else {
                    cin >> serviceName >> subscriberName >> monthlyRate >> hasDiscount;
                    s = new BasicSubscription(serviceName, subscriberName, monthlyRate, hasDiscount);
                }
                subs.push_back(s);
            }
            analyzeSubscriptions(subs);
            break;
        }
    }
};
*/