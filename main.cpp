#include <iostream>
#include "student_ops.h"
#include "course_ops.h"
#include "attendance.h"
#include "grades.h"
#include "fee_tracker.h"
#include "reports.h"

using namespace std;

void showMenu() {
    cout << "\
--- Campus Analytics Engine ---\
";
    cout << "1. Student Management\
2. Courses\
3. Attendance & Grades\
4. Financials\
5. Reports\
0. Exit\
";
}

int main() {
    int choice;
    do {
        showMenu();
        cout << "Select: ";
        cin >> choice;
        // Search as you type implementation is strictly OS dependent (conio.h) 
        // For standard C++, we use basic cin flow here to ensure cross-platform compilation.
    } while (choice != 0);
    return 0;
}
