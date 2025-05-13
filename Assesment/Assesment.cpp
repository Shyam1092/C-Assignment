#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class EventOrganizer {
private:
    string eventName;
    string firstName;
    string lastName;
    int numberOfGuests;
    int numberOfMinutes;

    const double CostPerHour = 18.50;
    const double CostPerMinute = 0.40;
    const double CostOfDinner = 20.70;

public:
    void getEventDetails() {
        cout << "Enter the name of the event: ";
        getline(cin, eventName);
        
        cout << "Enter your first name: ";
        getline(cin, firstName);
        
        cout << "Enter your last name: ";
        getline(cin, lastName);
        
        cout << "Enter the number of guests: ";
        cin >> numberOfGuests;
        
        cout << "Enter the number of minutes: ";
        cin >> numberOfMinutes;
    }

    void calculateCost() {
        // Calculate number of servers required
        int numberOfServers = ceil(static_cast<double>(numberOfGuests) / 20);
        
        // Calculate cost for one server
        double costForOneServer = (numberOfMinutes / 60) * CostPerHour + (numberOfMinutes % 60) * CostPerMinute;
        
        // Calculate total food cost
        double totalFoodCost = numberOfGuests * CostOfDinner;
        
        // Calculate average cost per person
        double averageCost = totalFoodCost / numberOfGuests;
        
        // Calculate total cost
        double totalCost = totalFoodCost + (costForOneServer * numberOfServers);
        
        // Calculate deposit amount
        double depositAmount = totalCost * 0.25;

        // Display the results
        cout << "\nEvent Cost Estimation:\n";
        cout << "Total Food Cost: $" << totalFoodCost << endl;
        cout << "Cost for One Server: $" << costForOneServer << endl;
        cout << "Total Cost: $" << totalCost << endl;
        cout << "Deposit Amount (25%): $" << depositAmount << endl;
        cout << "Average Cost Per Person: $" << averageCost << endl;
    }
};

int main() {
    EventOrganizer event;
    event.getEventDetails();
    event.calculateCost();
    return 0;
}
