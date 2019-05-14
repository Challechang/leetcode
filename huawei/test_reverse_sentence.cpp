//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <vector>

using namespace std;

string reverse(string sentence) {

    vector<string> sentences;

    for (auto index = 0; index < sentence.size();) {
        while (index < sentence.size() && sentence[index] == ' ') {
            index++;
        }

        if (index == sentence.size()) {
            continue;
        }
        string word;
        while (index < sentence.size() && sentence[index] != ' ') {
            word.push_back(sentence[index]);
            index++;
        }
        sentences.emplace_back(word);
    }

    string result;
    for (auto it = sentences.rbegin(); it != sentences.rend(); ++it) {
        result.append(*it);
        result.push_back(' ');
    }
    if (sentences.empty()) {
        return result;
    } else {
        result.pop_back();
        return result;
    }
}

int main() {

    string sentence;

    while (getline(cin, sentence)) {

        cout << reverse(sentence) << endl;
    }
}