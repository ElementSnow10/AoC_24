#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int>& levels) {
    bool increasing = levels[1] > levels[0];
    for (size_t i = 1; i < levels.size(); ++i) {
        if (increasing) {
            if (levels[i]<=levels[i-1] || abs(levels[i]-levels[i-1])>3) {
                return false;
            }
        } else {
            if (levels[i]>=levels[i-1] || abs(levels[i]-levels[i-1])>3) {
                return false;
            }
        }
    }
    return true;
}

bool canBeMadeSafe(const vector<int>& levels) {
    for (size_t i=0; i<levels.size(); i++) {
        vector<int> modifiedLevels = levels;
        modifiedLevels.erase(modifiedLevels.begin() + i);
        if (isSafe(modifiedLevels)) {
            return true;
        }
    }
    return false;
}

int main() {
    int count=0;
    string input;
    while (getline(cin, input)) {
        stringstream ss(input);
        vector<int> levels;
        int level;
        while (ss >> level) {
            levels.push_back(level);
        }
        if (isSafe(levels) || canBeMadeSafe(levels)) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
