// Alice and Bob are playing a turn-based game on a circular field surrounded by flowers. The circle represents the field, and there are x flowers in the clockwise direction between Alice and Bob, and y flowers in the anti-clockwise direction between them.

// The game proceeds as follows:

// Alice takes the first turn.
// In each turn, a player must choose either the clockwise or anti-clockwise direction and pick one flower from that side.
// At the end of the turn, if there are no flowers left at all, the current player captures their opponent and wins the game.
// Given two integers, n and m, the task is to compute the number of possible pairs (x, y) that satisfy the conditions:

// Alice must win the game according to the described rules.
// The number of flowers x in the clockwise direction must be in the range [1,n].
// The number of flowers y in the anti-clockwise direction must be in the range [1,m].
// Return the number of possible pairs (x, y) that satisfy the conditions mentioned in the statement.

// Example 1:

// Input: n = 3, m = 2
// Output: 3
// Explanation: The following pairs satisfy conditions described in the statement: (1,2), (3,2), (2,1).

// Example 2:

// Input: n = 1, m = 1
// Output: 0
// Explanation: No pairs satisfy the conditions described in the statement.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
       long long k = (long long)n * m / 2;
        return k;
    }
}s;

int main(){
    cout<<s.flowerGame(7,8)<<endl;
    
    return 0;
}