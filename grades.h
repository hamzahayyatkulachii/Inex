#ifndef GRADES_H
#define GRADES_H
#include <string>
#include <vector>
using namespace std;

struct Stats { double highest, lowest, mean, median; };

double bestThreeOfFive(double marks[], int n);
double computeWeightedTotal(double quizzes[], int qCount, double asgn[], int aCount, double mid, double finalScore);
string getLetterGrade(double total);
double computeGPA(const string& roll, const string& semester);
Stats computeClassStats(const string& course_code);
string applyAttendancePenalty(const string& roll, const string& course_code, double totalMarks);
#endif
