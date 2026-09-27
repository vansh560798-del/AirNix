#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class LibraryItem{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d){
        title = t;
        author = a;
        dueDate = d;
    }

    virtual ~LibraryItem() {}

    string getTitle() const{
        return title;
    }

    string getAuthor() const{
        return author;
    }

    string getDueDate() const{
        return dueDate;
    }

    void setTitle(string newTitle){
        if (newTitle.empty())
            throw invalid_argument("Title cannot be empty.");

        title = newTitle;
    }

    void setAuthor(string newAuthor){
        if (newAuthor.empty())
            throw invalid_argument("Author cannot be empty.");

        author = newAuthor;
    }

    void setDueDate(string newDueDate){
        dueDate = newDueDate;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

class Book : public LibraryItem{
private:
    string isbn;
    int quantity;
    bool checkedOut;

public:
    Book(string title, string author, string dueDate, string isbn, int quantity) : LibraryItem(title, author, dueDate){
        if (quantity < 0)
            throw invalid_argument("Quantity cannot be negative.");

        if (isbn.length() < 10)
            throw invalid_argument("Invalid ISBN format.");

        this->isbn = isbn;
        this->quantity = quantity;
        checkedOut = false;
    }

    void checkOut() override{
        if (checkedOut){
            cout << "Book is already checked out.\n";
            return;
        }

        if (quantity <= 0){
            cout << "Book is currently unavailable.\n";
            return;
        }

        checkedOut = true;
        quantity--;

        cout << "Book checked out successfully.\n";
    }

    void returnItem() override{
        if (!checkedOut){
            cout << "This book was not checked out.\n";
            return;
        }

        checkedOut = false;
        quantity++;

        cout << "Book returned successfully.\n";
    }

    void displayDetails() const override{
        cout << "\n----- BOOK DETAILS -----\n";
        cout << "Title       : " << getTitle() << endl;
        cout << "Author      : " << getAuthor() << endl;
        cout << "Due Date    : " << getDueDate() << endl;
        cout << "ISBN        : " << isbn << endl;
        cout << "Quantity    : " << quantity << endl;
        cout << "Status      : "
             << (checkedOut ? "Checked Out" : "Available")
             << endl;
    }
};

class DVD : public LibraryItem{
private:
    int duration;
    bool checkedOut;

public:
    DVD(string title, string author, string dueDate, int duration) : LibraryItem(title, author, dueDate){
        if (duration <= 0)
            throw invalid_argument("Duration must be greater than 0.");

        this->duration = duration;
        checkedOut = false;
    }

    void checkOut() override{
        if (checkedOut){
            cout << "DVD is already checked out.\n";
            return;
        }

        checkedOut = true;
        cout << "DVD checked out successfully.\n";
    }

    void returnItem() override{
        if (!checkedOut){
            cout << "This DVD was not checked out.\n";
            return;
        }

        checkedOut = false;
        cout << "DVD returned successfully.\n";
    }

    void displayDetails() const override{
        cout << "\n----- DVD DETAILS -----\n";
        cout << "Title       : " << getTitle() << endl;
        cout << "Author      : " << getAuthor() << endl;
        cout << "Due Date    : " << getDueDate() << endl;
        cout << "Duration    : " << duration << " minutes" << endl;
        cout << "Status      : "
             << (checkedOut ? "Checked Out" : "Available")
             << endl;
    }
};

class Magazine : public LibraryItem{
private:
    int issueNumber;
    bool checkedOut;

public:
    Magazine(string title, string author, string dueDate, int issueNumber) : LibraryItem(title, author, dueDate){
        if (issueNumber <= 0)
            throw invalid_argument("Issue number must be greater than 0.");

        this->issueNumber = issueNumber;
        checkedOut = false;
    }

    void checkOut() override{
        if (checkedOut){
            cout << "Magazine is already checked out.\n";
            return;
        }

        checkedOut = true;
        cout << "Magazine checked out successfully.\n";
    }

    void returnItem() override{
        if (!checkedOut){
            cout << "This magazine was not checked out.\n";
            return;
        }

        checkedOut = false;
        cout << "Magazine returned successfully.\n";
    }

    void displayDetails() const override{
        cout << "\n----- MAGAZINE DETAILS -----\n";
        cout << "Title       : " << getTitle() << endl;
        cout << "Author      : " << getAuthor() << endl;
        cout << "Due Date    : " << getDueDate() << endl;
        cout << "Issue No.   : " << issueNumber << endl;
        cout << "Status      : "
             << (checkedOut ? "Checked Out" : "Available")
             << endl;
    }
};

int main(){
    const int MAX_ITEMS = 100;

    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount = 0;

    int choice;

    do{
        cout << "\n=====================================\n";
        cout << "       LIBRARY MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Search Item\n";
        cout << "6. Check Out Item\n";
        cout << "7. Return Item\n";
        cout << "8. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";

        cin >> choice;

        try{
            if (choice == 1){
                if (itemCount >= MAX_ITEMS)
                    throw runtime_error("Library catalog is full.");

                string title, author, dueDate, isbn;
                int quantity;

                cin.ignore();

                cout << "Enter book title: ";
                getline(cin, title);

                cout << "Enter author: ";
                getline(cin, author);

                cout << "Enter due date: ";
                getline(cin, dueDate);

                cout << "Enter ISBN: ";
                getline(cin, isbn);

                cout << "Enter quantity: ";
                cin >> quantity;

                libraryItems[itemCount] =
                    new Book(title, author, dueDate, isbn, quantity);

                itemCount++;

                cout << "\nBook added successfully!\n";
            }

            else if (choice == 2){
                if (itemCount >= MAX_ITEMS)
                    throw runtime_error("Library catalog is full.");

                string title, author, dueDate;
                int duration;

                cin.ignore();

                cout << "Enter DVD title: ";
                getline(cin, title);

                cout << "Enter author/director: ";
                getline(cin, author);

                cout << "Enter due date: ";
                getline(cin, dueDate);

                cout << "Enter duration in minutes: ";
                cin >> duration;

                libraryItems[itemCount] =
                    new DVD(title, author, dueDate, duration);

                itemCount++;

                cout << "\nDVD added successfully!\n";
            }

            else if (choice == 3){
                if (itemCount >= MAX_ITEMS)
                    throw runtime_error("Library catalog is full.");

                string title, author, dueDate;
                int issueNumber;

                cin.ignore();

                cout << "Enter magazine title: ";
                getline(cin, title);

                cout << "Enter publisher/author: ";
                getline(cin, author);

                cout << "Enter due date: ";
                getline(cin, dueDate);

                cout << "Enter issue number: ";
                cin >> issueNumber;

                libraryItems[itemCount] =
                    new Magazine(title, author, dueDate, issueNumber);

                itemCount++;

                cout << "\nMagazine added successfully!\n";
            }

            else if (choice == 4){
                if (itemCount == 0){
                    cout << "\nNo items in the library.\n";
                }
                else{
                    cout << "\n===== ALL LIBRARY ITEMS =====\n";

                    for (int i = 0; i < itemCount; i++){
                        cout << "\nItem " << i + 1 << ":";
                        libraryItems[i]->displayDetails();
                    }
                }
            }

            else if (choice == 5){
                if (itemCount == 0){
                    cout << "\nNo items in the library.\n";
                    continue;
                }

                string searchTitle;

                cin.ignore();

                cout << "Enter title to search: ";
                getline(cin, searchTitle);

                bool found = false;

                for (int i = 0; i < itemCount; i++){
                    if (libraryItems[i]->getTitle() == searchTitle){
                        libraryItems[i]->displayDetails();
                        found = true;
                    }
                }

                if (!found)
                    cout << "\nItem not found.\n";
            }

            else if (choice == 6){
                if (itemCount == 0){
                    cout << "\nNo items in the library.\n";
                    continue;
                }

                string title;

                cin.ignore();

                cout << "Enter title to check out: ";
                getline(cin, title);

                bool found = false;

                for (int i = 0; i < itemCount; i++){
                    if (libraryItems[i]->getTitle() == title){
                        libraryItems[i]->checkOut();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Item not found.\n";
            }

            else if (choice == 7){
                if (itemCount == 0){
                    cout << "\nNo items in the library.\n";
                    continue;
                }

                string title;

                cin.ignore();

                cout << "Enter title to return: ";
                getline(cin, title);

                bool found = false;

                for (int i = 0; i < itemCount; i++){
                    if (libraryItems[i]->getTitle() == title){
                        libraryItems[i]->returnItem();
                        found = true;
                        break;
                    }
                }
                if (!found)
                   cout << "Item not found.\n";
            }
            else if (choice == 8){
                cout << "\nThank you for using Library Management System!\n";
            }
            else{
                cout << "\nInvalid choice. Please try again.\n";
            }
        }
        catch (const exception& e){
            cout << "\nError: " << e.what() << endl;
        }
    } while (choice != 8);

    for (int i = 0; i < itemCount; i++){
        delete libraryItems[i];
    }
    return 0;
}