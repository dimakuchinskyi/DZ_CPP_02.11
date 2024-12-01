#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Library
{
private:
    map<string, vector<string>> _books;
    map<string, int> _publicationYears;

public:
    void addBook(const string title, const vector<string> authors, int year)
    {
        _books[title] = authors;
        _publicationYears[title] = year;
        cout << "Book added." << endl;
    }

    void findAuthors(const string title)
    {
        auto it = _books.find(title);
        if (it != _books.end())
        {
            cout << "Authors \"" << title << "\": ";
            for (auto author : it->second)
            {
                cout << author << ", ";
            }
            cout << "(Release: " << _publicationYears.at(title) << ")" << endl;
        }
        else
        {
            cout << "Book not found." << endl;
        }
    }

    void displayBooks()
    {
        for (auto book : _books)
        {
            cout << "Name of the book: " << book.first << endl;
            cout << "Authors: ";
            for (auto author : book.second)
            {
                cout << author << ", ";
            }
            cout << endl;
            cout << "Release: " << _publicationYears.at(book.first) << endl;
        }
    }
};

int main()
{
    Library library;
    int option;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Add new book" << endl;
        cout << "2. Find authors" << endl;
        cout << "3. Print all books with authors" << endl;
        cout << "Option: ";
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
        {
            cout << endl;
            string title;
            int year;
            vector<string> authors;
            string author;

            cout << "Enter name of the book: ";
            getline(cin, title);

            cout << "Enter the year: ";
            cin >> year;
            cin.ignore();

            cout << "Enter the authors (q for escape): ";
            while (true)
            {
                getline(cin, author);
                if (author == "q") break;
                authors.push_back(author);
            }

            library.addBook(title, authors, year);
            cout << endl;
            break;
        }
        case 2:
        {
            cout << endl;
            string title;
            cout << "Enter name of the book to find: ";
            getline(cin, title);
            library.findAuthors(title);
            cout << endl;
            break;
        }
        case 3:
        {
            cout << endl;
            library.displayBooks();
            cout << endl;
            break;
        }
        default:
        {
            cout << "Error." << endl;
            break;
        }
        }
    }

    return 0;
}
