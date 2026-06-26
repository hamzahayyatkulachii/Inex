#ifndef STUDENT_OPS_H
#define STUDENT_OPS_H
#include <string>
#include <vector>
using namespace std;

struct Student { string roll, name, dept, status; double cgpa; };

bool addStudent(const Student& s);
vector<string> searchByRoll(const string& roll);
vector<vector<string>> searchByName(const string& substring);
bool updateStudent(const string& roll, int colIndex, const string& newValue);
bool softDelete(const string& roll);
vector<Student> listActiveStudents();
#endif
