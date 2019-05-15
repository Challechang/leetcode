//
// Created by rbcheng on 19-5-15.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ErrorRecord {
public:
    string file_name;
    int line_number;
    int count;

    ErrorRecord(): line_number(0), count(0) {}
};

bool operator==(const ErrorRecord& a, const ErrorRecord& b) {

    return (a.file_name == b.file_name) && (a.line_number == b.line_number);
}

string get_file_name(string& path) {

    auto pos = path.find_last_of("\\");
    if (pos == string::npos) {
        return path;
    }
    const int max_file_name = 16;
    string file_name = path.substr(pos + 1);

    if (file_name.size() > max_file_name) {
        file_name = file_name.substr(file_name.size() - max_file_name);
    }
    return file_name;
}

int main() {

    string path;
    int line_number;
    vector<ErrorRecord> records;

    while (cin>>path>>line_number) {
        string file_name = get_file_name(path);
        ErrorRecord record;
        record.file_name = file_name;
        record.line_number = line_number;
        record.count = 1;

        auto it = find(records.begin(), records.end(), record);
        if (it == records.end()) {
            records.emplace_back(record);
        } else {
            it->count ++;
        }
    }

    int j = 0;
    if (records.size() >= 8) {
        j = records.size() - 8;
    }

    for (int i = j; i < records.size(); ++i) {

        cout << records[i].file_name << " " << records[i].line_number << " " << records[i].count << endl;

    }
}