#include "student_ops.h"
#include "filehandler.h"
#include <iostream>

bool addStudent(const Student& s) {
    if (s.roll.length() != 11 || s.roll.substr(0, 5) != "BSAI-" || s.roll[7] != '-') return false;
    for (size_t i = 0; i < s.name.length(); ++i) {
        if (s.name[i] >= '0' && s.name[i] <= '9') return false;
    }
    if (s.cgpa < 0.0 || s.cgpa > 4.0) return false;
    if (rowExists("students.txt", 0, s.roll)) return false;
    
    vector<string> row = {s.roll, s.name, s.dept, to_string(s.cgpa), "active"};
    appendTXT("students.txt", row);
    return true;
}

vector<string> searchByRoll(const string& roll) {
    return findRow("students.txt", 0, roll);
}

vector<vector<string>> searchByName(const string& substring) {
    vector<vector<string>> data = readTXT("students.txt");
    vector<vector<string>> results;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i][1].find(substring) != string::npos) results.push_back(data[i]);
    }
    return results;
}

bool updateStudent(const string& roll, int colIndex, const string& newValue) {
    if (colIndex == 0) return false; // Cannot update roll
    vector<vector<string>> data = readTXT("students.txt");
    bool found = false;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i][0] == roll) { data[i][colIndex] = newValue; found = true; break; }
    }
    if (found) writeTXT("students.txt", "roll,name,dept,cgpa,status", data);
    return found;
}

bool softDelete(const string& roll) {
    return updateStudent(roll, 4, "inactive");
}

vector<Student> listActiveStudents() {
    vector<vector<string>> data = readTXT("students.txt");
    vector<Student> active;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i][4] == "active") {
            active.push_back({data[i][0], data[i][1], data[i][2], data[i][4], stod(data[i][3])});
        }
    }
    // Selection sort by roll
    for (size_t i = 0; i < active.size(); ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < active.size(); ++j) {
            if (active[j].roll < active[minIdx].roll) minIdx = j;
        }
        Student temp = active[i];
        active[i] = active[minIdx];
        active[minIdx] = temp;
    }
    return active;
}
