#include <iostream>
#include <string>

using namespace std;

int main() {
    // Use cin to input an integer
    int age;
    cout << "Enter your age: ";
    cin >> age;
    
    // Use cin.ignore() to clear the remaining newline character in the buffer
    cin.ignore();

    // Use getline to input the entire line, including spaces
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // Use cout to output the result
    cout << "Hello, " << name << "! You are " << age << " years old." << endl;

    return 0;
}

/*
    Enter your age: 25
    Enter your name: John Doe
    Hello, John Doe! You are 25 years old.

*/