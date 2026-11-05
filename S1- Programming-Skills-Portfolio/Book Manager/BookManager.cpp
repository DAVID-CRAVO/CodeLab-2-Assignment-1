#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Structure to store information about each book
struct Book {
    string title;
    string author;
    int pages;
    string reference;
    bool available;
};

// Array containing all 10 books
Book books[] = {
    {"The Great Gatsby", "F. Scott Fitzgerald", 180, "001", true},
    {"1984", "George Orwell", 328, "002", false},
    {"To Kill a Mockingbird", "Harper Lee", 281, "003", true},
    {"Pride and Prejudice", "Jane Austen", 279, "004", false},
    {"The Catcher in the Rye", "J.D. Salinger", 214, "005", true},
    {"Moby-Dick", "Herman Melville", 635, "006", false},
    {"War and Peace", "Leo Tolstoy", 1225, "007", true},
    {"The Hobbit", "J.R.R. Tolkien", 310, "008", false},
    {"Crime and Punishment", "Fyodor Dostoevsky", 671, "009", true},
    {"Brave New World", "Aldous Huxley", 268, "010", false}
};

// Calculate the total number of books in the array
// Divide the size of the entire array by the size of one Book
int totalBooks = sizeof(books) / sizeof(books[0]);

// Function to display the main menu
void showMenu() {
    cout << "\n=== LIBRARY MANAGEMENT SYSTEM ===\n";
    cout << "1. View all books\n";
    cout << "2. View available books\n";
    cout << "3. Search for a book\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

// Function to display the details of one book
void displayBook(Book book) {
    cout << "\nTitle: \"" << book.title << "\"\n";
    cout << "Author: " << book.author << endl;
    cout << "Pages: " << book.pages << " pages\n";
    cout << "Reference: " << book.reference << endl;

    // Display true if available, otherwise false
    cout << "Availability: "
         << (book.available ? "true" : "false") << endl;
}

// Function to display all books
void viewAllBooks() {
    cout << "\n=== ALL BOOKS ===\n";

    // Loop through every book in the array
    for (int i = 0; i < totalBooks; i++) {
        displayBook(books[i]);
    }
}

// Function to display only available books
void viewAvailableBooks() {
    cout << "\n=== AVAILABLE BOOKS ===\n";

    // Check each book in the array
    for (int i = 0; i < totalBooks; i++) {

        // Only display books with availability set to true
        if (books[i].available == true) {
            displayBook(books[i]);
        }
    }
}

// Function to search for a specific book by reference
void searchBook() {
    string searchReference;
    bool found = false; // Starts as false because no book has been found yet

    cout << "\nEnter book reference (e.g. 001): ";
    cin >> searchReference;

    // Go through the array to find a matching reference
    for (int i = 0; i < totalBooks; i++) {

        // Compare the entered reference with the current book
        if (books[i].reference == searchReference) {
            displayBook(books[i]); // Display the matching book
            found = true;          // Record that the book was found
            break;                 // Stop searching
        }
    }

    // If no matching reference was found, display an error
    if (found == false) {
        cout << "No books match your search, sorry!\n";
    }
}

// Main function: the program starts here
int main() {
    int choice; // Stores the user's menu selection

    // Keep displaying the menu until the user chooses to exit
    while (true) {
        showMenu();
        cin >> choice;

        // Check whether the user entered invalid input
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";

            cin.clear(); // Reset the input error state

            // Remove invalid characters from the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Option 1: Display every book
        else if (choice == 1) {
            viewAllBooks();
        }

        // Option 2: Display only available books
        else if (choice == 2) {
            viewAvailableBooks();
        }

        // Option 3: Search for a book using its reference
        else if (choice == 3) {
            searchBook();
        }

        // Option 0: Exit the program
        else if (choice == 0) {
            cout << "Thanks for using the library system!\n";
            break; // Exit the while loop
        }

        // Handle numbers that are not valid menu options
        else {
            cout << "Invalid choice! Enter 1, 2, 3 or 0.\n";
        }
    }

    return 0; // End the program successfully
}
