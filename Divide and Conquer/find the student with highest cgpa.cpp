/*You are given a list of students who have
name, id and cgpa. Your task is to find the
student with highest cgpa. [ you can’t sort the
list]*/
#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

// Student structure with name, id, and cgpa
struct Student
{
    string name;
    int id;
    double cgpa;

    // Constructor to initialize student details
    Student(string n, int i, double c) : name(n), id(i), cgpa(c) {}
};

// Function to find the student with the highest CGPA in a given range [low, high]
Student highestCgpaStudent(vector<Student>& students, int low, int high)
{
    // Base case: If the list has only one student, return that student
    if (low == high)
    {
        return students[low];
    }

    // Find the middle index
    int mid = low + (high - low) / 2;

    // Recursively find the highest CGPA student in the left and right halves
    Student leftMax = highestCgpaStudent(students, low, mid);
    Student rightMax = highestCgpaStudent(students, mid + 1, high);

    // Combine step: Return the student with the higher CGPA
    return (leftMax.cgpa >= rightMax.cgpa) ? leftMax : rightMax;
}

// Function to find the student with the highest CGPA in the entire list
Student findHighestCgpaStudent(vector<Student>& students)
{
    int n = students.size();
    return highestCgpaStudent(students, 0, n - 1);
}

int main()
{
    // Example list of students
    vector<Student> students =
    {
        Student("Alice", 1, 3.6),
        Student("Bob", 2, 3.9),
        Student("Charlie", 3, 3.7),
        Student("David", 4, 4.0),
        Student("Eve", 5, 3.8)
    };

    // Find and print the student with the highest CGPA
    Student highest = findHighestCgpaStudent(students);
    cout << "Student with the highest CGPA: " << highest.name << " (ID: " << highest.id <<",CGPA: " << highest.cgpa << ")" << endl;

    return 0;
}


