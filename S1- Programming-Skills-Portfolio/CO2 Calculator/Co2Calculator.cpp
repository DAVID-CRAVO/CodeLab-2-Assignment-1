#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// Function to display a message
void message(string text) {
    cout << text << endl;
}

// Function to display the main menu
void showMenu() {
    message("\n=== CO2 CALCULATOR ===");
    message("1. Transport emissions");
    message("2. Electricity emissions");
    message("3. Book printing emissions");
    message("0. Exit");
    cout << "Enter your choice: ";
}

// Function to check if the user entered a valid number
double getAmount(string question) {
    double amount;

    while (true) {
        cout << question;
        cin >> amount;

        // Check if the input is invalid
        if (cin.fail()) {
            message("Invalid input! Please enter a number.");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Check if the number is negative
        else if (amount < 0) {
            message("Invalid input! Enter a positive number.");
        }

        // Return the number if it is valid
        else {
            return amount;
        }
    }
}

// Function to calculate and display CO2 emissions
void calculateCO2(double amount, double factor) {
    double result = amount * factor;

    // Display the result with 4 decimal places
    cout << fixed << setprecision(4);
    cout << "Estimated CO2 emissions: "
         << result << " kg CO2" << endl;
}

// Function to calculate transport emissions
void transportEmissions() {
    int transportChoice;
    double factor = 0;

    message("\n=== TRANSPORT EMISSIONS ===");
    message("1. Car (petrol)");
    message("2. Bus");
    message("3. Train");
    message("4. Flight");
    cout << "Enter transport type: ";

    cin >> transportChoice;

    // Check for invalid input
    if (cin.fail()) {
        message("Invalid input! Please enter a number.");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Select the emission factor based on transport type
    if (transportChoice == 1) {
        factor = 0.20;
    }
    else if (transportChoice == 2) {
        factor = 0.10;
    }
    else if (transportChoice == 3) {
        factor = 0.04;
    }
    else if (transportChoice == 4) {
        factor = 0.25;
    }
    else {
        message("Invalid transport choice!");
        return;
    }

    // Ask for the distance travelled in kilometres
    double distance = getAmount("Enter distance in km: ");

    // Calculate emissions using distance and factor
    calculateCO2(distance, factor);
}

// Function to calculate electricity emissions
void electricityEmissions() {
    message("\n=== ELECTRICITY EMISSIONS ===");

    // Ask for electricity usage in kilowatt-hours
    double electricity = getAmount("Enter electricity used (kWh): ");

    // Electricity factor: 0.40 kg CO2 per kWh
    calculateCO2(electricity, 0.40);
}

// Function to calculate book printing emissions
void bookEmissions() {
    message("\n=== BOOK PRINTING EMISSIONS ===");

    // Ask for the number of pages in the book
    double pages = getAmount("Enter number of pages: ");

    // Book printing factor: 0.0007 kg CO2e per page
    calculateCO2(pages, 0.0007);
}

// Main function - program starts here
int main() {
    int choice;

    // Keep showing the menu until the user chooses to exit
    while (true) {
        showMenu();
        cin >> choice;

        // Check if the user entered invalid input
        if (cin.fail()) {
            message("Invalid input! Please enter a number.");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Option 1: Calculate transport emissions
        else if (choice == 1) {
            transportEmissions();
        }

        // Option 2: Calculate electricity emissions
        else if (choice == 2) {
            electricityEmissions();
        }

        // Option 3: Calculate book printing emissions
        else if (choice == 3) {
            bookEmissions();
        }

        // Option 0: Exit the program
        else if (choice == 0) {
            message("Thanks for using the CO2 Calculator!");
            break;
        }

        // Handle numbers that are not menu options
        else {
            message("Invalid choice! Enter 1, 2, 3 or 0.");
        }
    }

    return 0;
}
