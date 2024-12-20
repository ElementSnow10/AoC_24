#include <bits/stdc++.h>
using namespace std;

// Directions: up, right, down, left
const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    int rows=130, cols=130;
    vector<string> mp(rows);
    for (int i=0; i<rows; i++) {
        getline(cin, mp[i]);
    }
    // Find the guard's starting position and direction
    int guard_x=0, guard_y=0, direction=0;
    bool found=false;
    for (int i=0;i<rows && !found; i++) {
        for (int j=0; j<cols; j++) {
            if (mp[i][j] == '^') {
                guard_x=i;
                guard_y=j;
                direction=0; // Up initially.
                found=true;
                break;
            }
        }
    }

    set<pair<int, int>> visited;
    visited.insert({guard_x, guard_y});

    while (true) {
        int next_x=guard_x+DIRECTIONS[direction].first;
        int next_y=guard_y+DIRECTIONS[direction].second;

        // Checking if the guard is out of bounds
        if (next_x<0 || next_x>=rows || next_y<0 || next_y>=cols) {
            break;
        }

        // Checking if the next position is an obstacle
        if (mp[next_x][next_y]=='#') {
            direction=(direction+1)%4;
        } 
        else {
            guard_x=next_x;
            guard_y=next_y;
            visited.insert({guard_x, guard_y});
        }
    }

    cout << visited.size() << endl;

    return 0;
}
