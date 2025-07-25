#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<float> grades(numCourses);
    vector<int> creditHours(numCourses);

    float totalGradePoints = 0;
    int totalCredits = 0;

    cin.ignore();
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << " name: ";
        getline(cin, courseNames[i]);
        cout << "Grade for " << courseNames[i] << ": ";
        cin >> grades[i];
        cout << "Credit hours for " << courseNames[i] << ": ";
        cin >> creditHours[i];
        cin.ignore();
        totalGradePoints += grades[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    float GPA = totalGradePoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\nCourse Results:\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << courseNames[i] << " - Grade: " << grades[i]
             << ", Credits: " << creditHours[i] << endl;
    }

    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << GPA << endl;

    return 0;
}
