#ifndef COURSE_OPS_H
#define COURSE_OPS_H
#include <string>
#include <vector>
using namespace std;

enum EnrollResult { SUCCESS, COURSE_NOT_FOUND, ALREADY_ENROLLED, EXCEEDS_CREDITS, PREREQ_FAILED };

EnrollResult enrollStudent(const string& roll, const string& course_code, const string& semester);
bool dropCourse(const string& roll, const string& course_code, const string& semester);
int getCreditLoad(const string& roll, const string& semester);
bool checkPrerequisite(const string& roll, const string& course_code);
vector<string> listEnrolledStudents(const string& course_code, const string& semester);
#endif
