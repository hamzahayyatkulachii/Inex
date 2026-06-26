#ifndef FEE_TRACKER_H
#define FEE_TRACKER_H
#include <string>
#include <vector>
using namespace std;

bool recordPayment(const string& roll, const string& date, double amount);
int daysBetween(const string& d1, const string& d2);
double computeLateFine(const string& roll, const string& semester);
void generateReceipt(const string& roll, const string& semester);
vector<vector<string>> getDefaulters();
#endif
