#include <bits/stdc++.h>
using namespace std;

// Directions: up, right, down, left
const vector<pair<int, int>> DIRECTIONS={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_stuck_in_loop(int rows, int cols, vector<string> map, int guard_x, int guard_y, int direction) {
    set<pair<int, int>> visited;
    pair<int, int> initial_position={guard_x, guard_y};

    while (true) {
        int next_x=guard_x+DIRECTIONS[direction].first;
        int next_y=guard_y+DIRECTIONS[direction].second;

        // Checking if the guard is out of bounds
        if (next_x<0 || next_x>=rows || next_y<0 || next_y>=cols) {
            return false;
        }

        // Checking if the next position is an obstacle
        if (map[next_x][next_y]=='#') {
            direction=(direction+1)%4;
        } 
        else {
            guard_x=next_x;
            guard_y=next_y;

            // If the guard revisits the initial position in the same direction, it's a loop
            if (visited.count({guard_x, guard_y})) {
                return true;
            }
            visited.insert({guard_x, guard_y});
        }
    }
}

int main() {
    int rows=130, cols=130;

    vector<string> mp(rows);
    for (int i = 0; i < rows; ++i) {
        getline(cin, map[i]);
    }

    // Finding the guard's starting position and direction
    int guard_x=0, guard_y=0, direction=0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (map[i][j] == '^') {
                guard_x=i;
                guard_y=j;
                direction=0; // Up initially.
                break;
            }
        }
    }

    int valid_positions=0;

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            // Skiping the guard's starting position and existing obstacles
            if ((i == guard_x && j == guard_y) || map[i][j] == '#') {
                continue;
            }

            // Temporarily placing an obstruction
            map[i][j] = '#';

            // Checking if the guard gets stuck in a loop
            if (is_stuck_in_loop(rows, cols, map, guard_x, guard_y, direction)) {
                valid_positions++;
            }

            // Removing the obstruction
            map[i][j] = '.';
        }
    }

    cout << valid_positions << endl;

    return 0;
}
