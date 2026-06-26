#include "grades.h"
#include "attendance.h"

double bestThreeOfFive(double marks[], int n) {
    if(n < 3) { double sum=0; for(int i=0; i<n; ++i) sum+=marks[i]; return n==0 ? 0 : sum/n; }
    int idx1 = -1, idx2 = -1;
    double m1 = 1e9, m2 = 1e9;
    for(int i=0; i<n; ++i) {
        if(marks[i] < m1) { m2 = m1; idx2 = idx1; m1 = marks[i]; idx1 = i; }
        else if(marks[i] < m2) { m2 = marks[i]; idx2 = i; }
    }
    double sum = 0;
    for(int i=0; i<n; ++i) { if(i != idx1 && i != idx2) sum += marks[i]; }
    return sum / 3.0;
}

double computeWeightedTotal(double quizzes[], int qCount, double asgn[], int aCount, double mid, double finalScore) {
    double qAvg = bestThreeOfFive(quizzes, qCount);
    double aAvg = 0;
    for(int i=0; i<aCount; ++i) aAvg += asgn[i];
    if(aCount > 0) aAvg /= aCount;
    return (qAvg * 0.10) + (aAvg * 0.10) + (mid * 0.30) + (finalScore * 0.50);
}

string getLetterGrade(double total) {
    if(total >= 85) return "A";
    if(total >= 80) return "B+";
    if(total >= 70) return "B";
    if(total >= 65) return "C+";
    if(total >= 60) return "C";
    if(total >= 50) return "D";
    return "F";
}

double computeGPA(const string& roll, const string& semester) { return 0.0; } // Stub
Stats computeClassStats(const string& course_code) { return {0,0,0,0}; } // Stub
string applyAttendancePenalty(const string& roll, const string& course_code, double totalMarks) {
    if(getAttendancePct(roll, course_code) < 75.0) return "F";
    return getLetterGrade(totalMarks);
}
