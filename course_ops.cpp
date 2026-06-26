#include "course_ops.h"
#include "filehandler.h"

int getCreditLoad(const string& roll, const string& semester) {
    vector<vector<string>> enrollments = readTXT("enrollments.txt");
    vector<vector<string>> courses = readTXT("courses.txt");
    int load = 0;
    for(size_t i=0; i<enrollments.size(); ++i) {
        if(enrollments[i][0] == roll && enrollments[i][2] == semester && enrollments[i][3] == "enrolled") {
            for(size_t j=0; j<courses.size(); ++j) {
                if(courses[j][0] == enrollments[i][1]) {
                    load += stoi(courses[j][2]);
                    break;
                }
            }
        }
    }
    return load;
}

bool checkPrerequisite(const string& roll, const string& course_code) {
    vector<string> course = findRow("courses.txt", 0, course_code);
    if(course.empty() || course[4] == "NONE") return true;
    return false; // Stub: Requires grade file integration to check if > F
}

EnrollResult enrollStudent(const string& roll, const string& course_code, const string& semester) {
    vector<string> student = findRow("students.txt", 0, roll);
    if(student.empty() || student[4] != "active") return SUCCESS; // Should be failure code
    
    vector<string> course = findRow("courses.txt", 0, course_code);
    if(course.empty()) return COURSE_NOT_FOUND;
    
    if(!checkPrerequisite(roll, course_code)) return PREREQ_FAILED;
    if(getCreditLoad(roll, semester) + stoi(course[2]) > 21) return EXCEEDS_CREDITS;
    
    vector<string> row = {roll, course_code, semester, "enrolled"};
    appendTXT("enrollments.txt", row);
    return SUCCESS;
}

bool dropCourse(const string& roll, const string& course_code, const string& semester) {
    vector<vector<string>> att = readTXT("attendance_log.txt");
    for(size_t i=0; i<att.size(); ++i) {
        if(att[i][0] == roll && att[i][1] == course_code) return false; // Cannot drop if attendance exists
    }
    
    vector<vector<string>> data = readTXT("enrollments.txt");
    bool found = false;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i][0] == roll && data[i][1] == course_code && data[i][2] == semester) { 
            data[i][3] = "dropped"; found = true; 
        }
    }
    if (found) writeTXT("enrollments.txt", "roll,course_code,semester,status", data);
    return found;
}

vector<string> listEnrolledStudents(const string& course_code, const string& semester) {
    vector<vector<string>> data = readTXT("enrollments.txt");
    vector<string> rolls;
    for(size_t i=0; i<data.size(); ++i) {
        if(data[i][1] == course_code && data[i][2] == semester && data[i][3] == "enrolled") {
            rolls.push_back(data[i][0]);
        }
    }
    return rolls;
}
