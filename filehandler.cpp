#include "filehandler.h"
#include <fstream>
#include <iostream>

vector<vector<string>> readTXT(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    if (!file.is_open()) return data;
    string line;
    bool first = true;
    while (getline(file, line)) {
        if (first) { first = false; continue; } // Skip header
        vector<string> row;
        string cell = "";
        bool inQuotes = false;
        for (size_t i = 0; i < line.length(); ++i) {
            char c = line[i];
            if (c == '"') inQuotes = !inQuotes;
            else if (c == ',' && !inQuotes) { row.push_back(cell); cell = ""; }
            else cell += c;
        }
        row.push_back(cell);
        data.push_back(row);
    }
    return data;
}

void writeTXT(const string& filename, const string& header, const vector<vector<string>>& data) {
    ofstream file(filename);
    if (!file.is_open()) return;
    file << header << "\
";
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            string cell = data[i][j];
            bool needsQuotes = false;
            for (size_t k = 0; k < cell.length(); ++k) if (cell[k] == ',') needsQuotes = true;
            if (needsQuotes) file << "\\"" << cell << "\\"";
            else file << cell;
            if (j < data[i].size() - 1) file << ",";
        }
        file << "\
";
    }
}

void appendTXT(const string& filename, const vector<string>& row) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) return;
    for (size_t i = 0; i < row.size(); ++i) {
        file << row[i];
        if (i < row.size() - 1) file << ",";
    }
    file << "\
";
}

vector<string> findRow(const string& filename, int colIndex, const string& match) {
    vector<vector<string>> data = readTXT(filename);
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].size() > colIndex && data[i][colIndex] == match) return data[i];
    }
    return vector<string>();
}

bool rowExists(const string& filename, int colIndex, const string& match) {
    return !findRow(filename, colIndex, match).empty();
}
