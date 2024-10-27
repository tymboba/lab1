#include "keeper.h"
#include "fantast.h"
#include "romanist.h"
#include "poet.h"
#include "base.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int get_valid_number(const string& prompt) {
    string input;
    int number;
    while (true) {
        cout << prompt;
        cin >> input;
        try {
            number = stoi(input);
            break; 
        } catch (invalid_argument&) {
            cout << "Error: Please enter a valid number.\n";
        } catch (out_of_range&) {
            cout << "Error: The entered number is too large.\n";
        }
    }
    return number;
}

int main() {
    Keeper keeper;
    int choice = 0;

    do {
        cout << "\n---Menu ---\n";
        cout << "1. Add object\n";
        cout << "2. Delete object\n";
        cout << "3. Change object\n";
        cout << "4. Operator !\n";
        cout << "5. Operator ++\n";
        cout << "6. Show all objects\n";
        cout << "7. Save data to file\n";
        cout << "8. Load data from file\n";
        cout << "0. Log out\n";
        choice = get_valid_number("Enter transaction number: ");

        switch (choice) {
            case 1: {
                int index = get_valid_number("Enter an index to add an object: ");
                int objType = get_valid_number("Select object type:\n1. Fantastic\n2. Novelist\n3. Poet\nEnter type number: ");
                cin.ignore();
                Base* obj = nullptr;
                if (objType == 1) {
                    string name, years, books, movies_by_books;

                    cout << "Enter the name of the science fiction writer: ";
                    getline(cin, name);
                    cout << "Enter years of life: ";
                    getline(cin, years);
                    cout << "Enter books: ";
                    getline(cin, books);
                    cout << "Enter movies based on books: ";
                    getline(cin, movies_by_books);

                    obj = new Fantast(name, years, books, movies_by_books);
                } 
                else if (objType == 2) {
                    string name, years, books, bio;

                    cout << "Enter the novelist's name: ";
                    getline(cin, name);
                    cout << "Enter years of life:";
                    getline(cin, years);
                    cout << "Enter books: ";
                    getline(cin, books);
                    cout << "Enter bio: ";
                     getline(cin, bio);

                    obj = new Romanist(name, years, books, bio);
                } 
                else if (objType == 3) {
                    string name, years, poems;

                    cout << "Enter the poet's name: ";
                    getline(cin, name);
                    cout << "Enter years of life: ";
                    getline(cin, years);
                    cout << "Enter poems: ";
                    getline(cin, poems);

                    obj = new Poet(name, years, poems);
                } 
                else {
                    cout << "Invalid object type\n";
                    continue;
                }

                keeper.add(obj, index - 1);
                break;
            }

            case 2: {
                int index = get_valid_number("Enter index to delete object: ");
                keeper.delete_el(index - 1);
                break;
            }

            case 3: {
                int index = get_valid_number("Enter an index to edit the object: ");
                keeper.edit_el(index);
                break;
            }

            case 4:
                !keeper;
                break;

            case 5:
                keeper++;
                break;
            
            case 6:
                keeper.print_keeper();
                break;

            case 7: {
                string filename;
                cout << "Enter a file name to save:";
                cin >> filename;
                keeper.save_to_file(filename);
                break;
            }

            case 8: {
                string filename;
                cout << "Enter the file name to upload: ";
                cin >> filename;
                keeper.load_from_file(filename);
                break;
            }

            case 0:
                cout << "Exiting the program...\n";
                break;

            default:
                cout << "Wrong choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
