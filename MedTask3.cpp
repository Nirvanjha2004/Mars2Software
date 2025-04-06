#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char shiftBack(char ch, int shift) {
    // Ensure uppercase
    ch = toupper(ch);
    
    // Shift back and wrap if needed
    char shifted = ch - shift;
    if (shifted < 'A') {
        shifted += 26;
    }
    return shifted;
}

string decodeMessage(string input) {
    string decoded = "";
    for (int i = 0; i < input.length(); ++i) {
        decoded += shiftBack(input[i], i + 1); // shift increases by position
    }
    return decoded;
}

int main() {
    string encrypted;
    cout << "Enter encrypted message: ";
    cin >> encrypted;

    // Convert to uppercase
    for (char& c : encrypted) {
        c = toupper(c);
    }

    string result = decodeMessage(encrypted);
    cout << "Decoded message: " << result << endl;

    return 0;
}