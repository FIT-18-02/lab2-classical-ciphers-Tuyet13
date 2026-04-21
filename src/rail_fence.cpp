#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string read_message_from_file(const string &filename) {
    ifstream file(filename);
    string content, line;
    while (getline(file, line)) {
        content += line;
    }
    return content;
}

string rail_fence_encrypt(const string &text, int key) {
    if (key <= 1) return text;

    vector<string> rail(key);
    int row = 0;
    bool down = true;

    for (char c : text) {
        rail[row] += c;

        if (row == 0) down = true;
        else if (row == key - 1) down = false;

        row += down ? 1 : -1;
    }

    string result;
    for (auto &r : rail) result += r;
    return result;
}

string rail_fence_decrypt(const string &cipher, int key) {
    if (key <= 1) return cipher;

    int n = cipher.length();
    vector<vector<char>> rail(key, vector<char>(n, '\n'));

    int row = 0;
    bool down = true;

    for (int i = 0; i < n; i++) {
        rail[row][i] = '*';

        if (row == 0) down = true;
        else if (row == key - 1) down = false;

        row += down ? 1 : -1;
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < n; j++) {
            if (rail[i][j] == '*' && index < n) {
                rail[i][j] = cipher[index++];
            }
        }
    }

    string result;
    row = 0;
    down = true;

    for (int i = 0; i < n; i++) {
        result += rail[row][i];

        if (row == 0) down = true;
        else if (row == key - 1) down = false;

        row += down ? 1 : -1;
    }

    return result;
}

int main() {
    string text = read_message_from_file("data/input.txt");
    cout << rail_fence_encrypt(text, 3) << endl;
    return 0;
}
