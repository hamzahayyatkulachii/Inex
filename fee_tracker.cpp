#include "fee_tracker.h"
#include "filehandler.h"
#include <iomanip>

int daysInMonth(int m, int y) {
    if(m == 2) return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
    if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

int daysBetween(const string& d1, const string& d2) {
    // Parse DD-MM-YYYY manually without ctime
    if(d1.length() < 10 || d2.length() < 10) return 0;
    int day1 = stoi(d1.substr(0, 2)), m1 = stoi(d1.substr(3, 2)), y1 = stoi(d1.substr(6, 4));
    int day2 = stoi(d2.substr(0, 2)), m2 = stoi(d2.substr(3, 2)), y2 = stoi(d2.substr(6, 4));
    
    int t1 = y1 * 365 + day1;
    for(int i=0; i<y1; i++) if((i%4==0 && i%100!=0) || i%400==0) t1++;
    for(int i=1; i<m1; i++) t1 += daysInMonth(i, y1);
    
    int t2 = y2 * 365 + day2;
    for(int i=0; i<y2; i++) if((i%4==0 && i%100!=0) || i%400==0) t2++;
    for(int i=1; i<m2; i++) t2 += daysInMonth(i, y2);
    
    return t2 - t1;
}

bool recordPayment(const string& roll, const string& date, double amount) { return true; } // Stub
double computeLateFine(const string& roll, const string& semester) { return 0.0; } // Stub
void generateReceipt(const string& roll, const string& semester) {} // Stub
vector<vector<string>> getDefaulters() { return vector<vector<string>>(); } // Stub
