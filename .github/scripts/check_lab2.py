#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool is_valid_message(const string &text) {
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

char shift_char(char c, int shift) {
    if (!isalpha(static_cast<unsigned char>(c))) return c;

    char base = isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
    shift %= 26;
    if (shift < 0) shift += 26;

    return (c - base + shift) % 26 + base;
}

string caesar_encrypt(const string &plaintext, int shift) {
    string result;
    for (char c : plaintext) {
        result += shift_char(c, shift);
    }
    return result;
}

string caesar_decrypt(const string &ciphertext, int shift) {
    return caesar_encrypt(ciphertext, -shift);
}

int main() {
    string msg = "HELLO";
    cout << caesar_encrypt(msg, 3) << endl;
    return 0;
}
