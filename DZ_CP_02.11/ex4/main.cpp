#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class StudentGroup
{
private:
    map<string, vector<string>> _groups;

public:
    void addStudent(string group, string student)
    {
        _groups[group].push_back(student);
        cout << "Student added" << endl;
    }

    void removeStudent(string group, string student)
    {
        auto it = _groups.find(group);
        if (it != _groups.end())
        {
            auto students = it->second;
            auto pos = find(students.begin(), students.end(), student);
            if (pos != students.end())
            {
                students.erase(pos);
                cout << "Student deleted." << endl;
            }
            else
            {
                cout << "Student not found." << endl;
            }
        }
        else
        {
            cout << "Group not find." << endl;
        }
    }

    void displayGroup(string group)
    {
        auto it = _groups.find(group);
        if (it != _groups.end())
        {
            cout << "List of students: " << group << ":" << endl;
            for (const auto& student : it->second)
            {
                cout << "- " << student << endl;
            }
        }
        else
        {
            cout << "Group not find." << endl;
        }
    }
};

int main()
{
    StudentGroup studentGroup;
    int option;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Add student" << endl;
        cout << "2. delete student" << endl;
        cout << "3. Show full list" << endl;
        cout << "Option: ";
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
        {
            cout << endl;
            string group, student;

            cout << "Enter name of the group: ";
            getline(cin, group);
            cout << "Enter name of the student: ";
            getline(cin, student);
            studentGroup.addStudent(group, student);
            cout << endl;
            break;
        }
        case 2:
        {
            cout << endl;
            string group, student;

            cout << "Enter name of the group: ";
            getline(cin, group);
            cout << "Enter name of the student for delete: ";
            getline(cin, student);
            studentGroup.removeStudent(group, student);
            cout << endl;
            break;
        }
        case 3:
        {
            cout << endl;
            string group;
            cout << "Name of the group: ";
            getline(cin, group);
            studentGroup.displayGroup(group);
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
