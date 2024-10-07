#include <iostream>
#include <string> // Required for using std::string

using namespace std;

int main() {
    // 1. Declaring a string using std::string
    string str = "Hello, world!";
    cout << "Initial string: " << str << endl; // Output: Initial string: Hello, world!

    // 2. Input a string using getline to read a full line with spaces
    cout << "Enter a string: ";
    getline(cin, str); // Reads the entire line, including spaces
    cout << "You entered: " << str << endl;

    // 3. String length (or size)
    cout << "Length of the string: " << str.length() << endl; // Using length() to get the number of characters

    // 4. Accessing individual characters using index
    if (!str.empty()) { // Ensure the string is not empty
        cout << "First character: " << str[0] << endl; // Accessing the first character
    }

    // 5. Substring (extracting a part of the string)
    if (str.length() > 4) {
        string sub = str.substr(0, 5); // Extracts first 5 characters
        cout << "Substring (first 5 characters): " << sub << endl; // Output depends on input
    }

    // 6. Find a substring within the string
    size_t pos = str.find("world");
    if (pos != string::npos) { // If substring is found
        cout << "Found 'world' at position: " << pos << endl; // Output will indicate where "world" starts
    } else {
        cout << "'world' not found in the string." << endl;
    }

    // 7. Replace a part of the string
    pos = str.find("Hello");
    if (pos != string::npos) {
        str.replace(pos, 5, "Hi"); // Replaces "Hello" with "Hi"
        cout << "String after replace: " << str << endl; // Output after replacing "Hello" with "Hi"
    }

    // 8. Erase a part of the string
    if (str.length() > 5) {
        str.erase(5, 3); // Erases 3 characters starting from index 5
        cout << "String after erasing 3 characters from position 5: " << str << endl;
    }

    // 9. Append or concatenate strings
    str.append(" Welcome!"); // Adds " Welcome!" at the end
    cout << "String after append: " << str << endl; // Output: The updated string after appending

    str += " Have a great day!"; // Concatenating using += operator
    cout << "String after concatenating with +=: " << str << endl;

    // 10. Compare strings
    string str2 = "Hello";
    int result = str.compare(str2);
    if (result == 0) {
        cout << "The strings are equal." << endl;
    } else if (result > 0) {
        cout << "The original string is greater than '" << str2 << "'." << endl;
    } else {
        cout << "The original string is less than '" << str2 << "'." << endl;
    }

    return 0;
}


/*
    Initial string: Hello, world!
    Enter a string: Hello OpenAI
    You entered: Hello OpenAI
    First character of the string: H
    Length of the string: 11
    Substring (first 5 characters): Hello
    'world' not found.
    String after replace: Hi OpenAI
    String after erase: HiAI
    String after appending: HiAI!!!
    String after concatenation: HiAI!!! Have a nice day!
    str1 is less than str2.

*/