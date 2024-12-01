#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string text;
    string word;
    map<string, int> wordFrequency;

    cout << "Enter text: ";
    getline(cin, text);

    istringstream stream(text);

    while (stream >> word) {
        if (!word.empty()) {
            wordFrequency[word]++;
        }
    }

    cout << "Frequency: " << endl;
    for (auto entry : wordFrequency) {
        cout << entry.first << " : " << entry.second << endl;
    }

    return 0;
}
