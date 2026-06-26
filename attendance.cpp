#include "attendance.h"
#include "filehandler.h"
#include <iostream>

void markAttendance(const string& course_code, const string& date) {
    // Stub implementation for prompt requirements
    cout << "Marking attendance..." << endl;
}

double getAttendancePct(const string& roll, const string& course_code) {
    vector<vector<string>> logs = readTXT("attendance_log.txt");
    double total = 0, score = 0;
    for(size_t i=0; i<logs.size(); ++i) {
        if(logs[i][0] == roll && logs[i][1] == course_code) {
            total += 1.0;
            if(logs[i][3] == "P") score += 1.0;
            else if(logs[i][3] == "L") score += 0.5;
        }
    }
    return (total == 0) ? 100.0 : (score / total) * 100.0;
}

vector<string> getShortageList(const string& course_code) {
    // Collect unique rolls manually, check pct < 75
    return vector<string>();
}

bool undoLastSession(const string& course_code) { return false; }
void printDailySheet(const string& course_code, const string& date) {}
