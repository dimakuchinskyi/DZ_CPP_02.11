#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;

class WordCounter {
private:
    map<string, int> wordFrequency;

    string cleanWord(const string& word) {
        size_t start = 0;
        while (start < word.length() && ispunct(word[start])) {
            start++;
        }
        size_t end = word.length();
        // ���������� ���������� � ���� �����
        while (end > start && ispunct(word[end - 1])) {
            end--;
        }
        return (start < end) ? word.substr(start, end - start) : "";
    }

public:
    // ����� ��� ������� ������
    void processText(const string& text) {
        istringstream stream(text);
        string word;
        while (stream >> word) {
            string cleanedWord = cleanWord(word);
            if (!cleanedWord.empty()) {
                wordFrequency[cleanedWord]++;
            }
        }
    }

    // ����� ��� ��������� ������� ���
    void displayFrequency() const {
        cout << "\n������� ��� � �����:\n";
        for (const auto& entry : wordFrequency) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }
};

int main() {
    string text;
    cout << "������ �����: ";
    getline(cin, text);

    WordCounter wordCounter;
    wordCounter.processText(text);
    wordCounter.displayFrequency();

    return 0;
}
