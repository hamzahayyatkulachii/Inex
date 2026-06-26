#include "reports.h"
#include "filehandler.h"
#include <iostream>

void printMeritList() {
    vector<vector<string>> data = readTXT("students.txt");
    // Bubble sort descending by CGPA manually
    for(size_t i=0; i<data.size(); ++i) {
        for(size_t j=0; j<data.size()-1-i; ++j) {
            if(stod(data[j][3]) < stod(data[j+1][3])) {
                vector<string> temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    cout << "MERIT LIST\
";
}

void printAttendanceDefaulters() {}
void printFeeDefaulters() {}
void printSemesterResult(const string& semester) {}
void printDepartmentSummary() {}
void exportReportToFile(const string& reportName) {}
