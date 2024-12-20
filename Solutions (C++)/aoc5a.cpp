#include <bits/stdc++.h>
using namespace std;

// Function to parse a line of comma-separated integers into a vector<int>
vector<int> parseUpdate(const string &line) {
    vector<int> result;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        result.push_back(stoi(token));
    }
    return result;
}

// Function to check if an update satisfies the ordering rules
bool isValidUpdate(const vector<int> &update, const vector<pair<int, int>> &rules) {
    unordered_map<int, int> position;
    for (size_t i=0; i<update.size(); i++) {
        position[update[i]]=i;
    }

    for (const auto &[x, y] : rules) {
        if (position.count(x) && position.count(y)) {
            if (position[x]>=position[y]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // Input the ordering rules
    vector<pair<int, int>> rules;
    string line;
    while(getline(cin,line)&&!line.empty()){
        size_t delimiter=line.find('|');
        int x=stoi(line.substr(0, delimiter));
        int y=stoi(line.substr(delimiter+1));
        rules.emplace_back(x,y);
    }
    // Input the updates
    vector<vector<int>> updates;
    while (getline(cin, line) && !line.empty()) {
        updates.push_back(parseUpdate(line));
    }

    // Process updates and find valid ones
    int sumOfMiddlePages=0;
    for (const auto &update : updates) {
        if (isValidUpdate(update, rules)) {
            int middleIndex=update.size() / 2;
            sumOfMiddlePages+=update[middleIndex];
        }
    }

    // Output the result
    cout << sumOfMiddlePages << endl;
    return 0;
}