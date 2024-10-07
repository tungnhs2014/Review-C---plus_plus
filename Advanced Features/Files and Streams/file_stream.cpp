#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Part 1: Using ifstream to read from a file
    ifstream inFile("input.txt");  // Open file "input.txt" for reading
    if (!inFile) {  // Check if the file was opened successfully
        cerr << "Unable to open input file." << endl;
        return 1;  // Exit the program with an error code
    }

    cout << "Reading from input.txt:" << endl;
    string line;
    while (getline(inFile, line)) {  // Read each line from the file
        cout << line << endl;  // Output each line to the console
    }
    inFile.close();  // Close the file after reading

    // Part 2: Using ofstream to write to a file
    ofstream outFile("output.txt");  // Open file "output.txt" for writing
    if (!outFile) {  // Check if the file was opened successfully
        cerr << "Unable to open output file." << endl;
        return 1;  // Exit the program with an error code
    }

    outFile << "Hello, world!" << endl;  // Write a line to the file
    outFile << "Writing to output.txt using ofstream." << endl;  // Write another line
    outFile.close();  // Close the file after writing

    // Part 3: Using fstream to read and write to the same file
    fstream file("data.txt", ios::in | ios::out | ios::app);  // Open file "data.txt" for both reading and appending
    if (!file) {  // Check if the file was opened successfully
        cerr << "Unable to open data file." << endl;
        return 1;  // Exit the program with an error code
    }

    // Write additional data to the file
    file << "Appending new data to data.txt" << endl;

    // Set the read position back to the start of the file
    file.seekg(0);

    cout << "\nReading from data.txt:" << endl;
    while (getline(file, line)) {  // Read each line from the file
        cout << line << endl;  // Output each line to the console
    }
    file.close();  // Close the file after reading and writing

    return 0;
}

/*
    Reading from input.txt:
    This is the first line of input.txt.
    This is the second line of input.txt.
    ...

    Reading from data.txt:
    Appending new data to data.txt
    ...
*/