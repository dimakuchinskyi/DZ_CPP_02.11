#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Student 
{
private:
    string _name;
    vector<int> _grades;

public:
    Student() = default;
    Student(string name)
    {
        SetName(name);
    }

    void addGrade(int grade) 
    {
        _grades.push_back(grade);
    }

    void SetName(string name)
    {
        _name = name;
    }

    string getName() const {
        return _name;
    }

    double getAverageGrade()
    {
        int sum = 0;
        for (int grade : _grades) 
        {
            sum += grade;
        }
        return static_cast<double>(sum) / _grades.size();
    }

    void print()
    {
        cout << "Student: " << getName() << ", Average Grade: " << getAverageGrade() << endl;
    }
};

class GradeBook 
{
private:
    map<string, Student> _students;
public:
    void addStudent(string name) 
    {
        _students[name] = Student(name);
        cout << "Added." << endl;
    }

    void addGrade(const string& name, int grade)
    {
        auto it = _students.find(name);
        it->second.addGrade(grade);
        cout << "Grade added" << endl;
    }

    void displayStudents() 
    {
        for (auto& student : _students) 
        {
            cout << student.first << " - " << student.second.getAverageGrade() << endl;
        }
    }
};

int main() {
    GradeBook gradeBook;
    int option;
    string studentName;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add new student\n";
        cout << "2. Add grade for an existing student\n";
        cout << "3. Display students with their average grade\n";
        cout << "Select an option: ";
        cin >> option;
        cin.ignore();

        switch (option) {
        case 1: {
            cout << "Enter student name: ";
            getline(cin, studentName);
            gradeBook.addStudent(studentName);
            break;
        }
        case 2: {
            cout << "Enter student name: ";
            getline(cin, studentName);
            int grade;
            cout << "Enter grade to add: ";
            cin >> grade;
            gradeBook.addGrade(studentName, grade);
            break;
        }
        case 3: {
            gradeBook.displayStudents();
            break;
        }
        default: {
            cout << "Invalid option. Please try again.";
            break;
        }
        }
    }

    return 0;
}
