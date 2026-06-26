#ifndef ATTENDANCE_H
#define ATTENDANCE_H
#include <string>
#include <vector>
using namespace std;

void markAttendance(const string& course_code, const string& date);
double getAttendancePct(const string& roll, const string& course_code);
vector<string> getShortageList(const string& course_code);
bool undoLastSession(const string& course_code);
void printDailySheet(const string& course_code, const string& date);
#endif
