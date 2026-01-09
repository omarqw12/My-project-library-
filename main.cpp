#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class library {
public:
    string name;
    string description;
    string example;

    library (string n, string d,string e) {
        name = n;
        description = d;
        example = e;
    }
    void display() const {
        cout << "Name library: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Example code: " << example << endl;
    }
};
void showMenu() {
    cout << "\n* Please Enter your choice *" << endl;
    cout << "1. View all libraries (عرض كل المكتبات)" << endl;
    cout << "2. Search for a library (بحث عن مكتبه)" << endl;
    cout << "3. Exit (خروج)" << endl;
}
void searchLibrary(const vector<library>& libs) {
    string searchName;
    cout << "Please Enter your library name: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < libs.size(); i++) {
        if (libs[i].name == searchName) {
            libs[i].display();
            found = true;
            break;
        }
    }
    if (!found) cout << "No found this library!" << endl;
}
void viewAll(const vector<library>& libs) {
    for (int i = 0; i < libs.size(); i++) {
        libs[i].display();
        cout << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    vector<library> librarys;
    librarys.push_back(library("#include <iostream>","تستخدم لعمليات الادخال و الاخراج","cout << \"hello\" <<endl;"));
    librarys.push_back(library("#include <array>","تستخدم لتخزين مجموعة من العناصر ولكن لها مساحه محدده","int arr[2]={2,1};"));

    int choice;
    int attempts = 3;
    do{
        if (attempts <= 0) {
            cout << "\n!!! You have exhausted all your attempts !!!" << endl;
            break;
        }
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            attempts--;
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        switch (choice) {
            case 1:
                viewAll(librarys);
                break;
            case 2:
                searchLibrary(librarys);
                break;
            case 3:
                cout<<"Goodbye! (مع السلامه)"<<endl;
                break;
            default:
                attempts--;
                cout << "Wrong choice!" << endl;
        }
    } while(choice != 3);
    return 0;
};