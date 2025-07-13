// There is an m x n cake that needs to be cut into 1 x 1 pieces.

// You are given integers m, n, and two arrays:

// horizontalCut of size m - 1, where horizontalCut[i] represents the cost to cut along the horizontal line i.
// verticalCut of size n - 1, where verticalCut[j] represents the cost to cut along the vertical line j.
// In one operation, you can choose any piece of cake that is not yet a 1 x 1 square and perform one of the following cuts:

// Cut along a horizontal line i at a cost of horizontalCut[i].
// Cut along a vertical line j at a cost of verticalCut[j].
// After the cut, the piece of cake is divided into two distinct pieces.

// The cost of a cut depends only on the initial cost of the line and does not change.

// Return the minimum total cost to cut the entire cake into 1 x 1 pieces.

// Input: m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]

// Output: 13

// Perform a cut on the vertical line 0 with cost 5, current total cost is 5.
// Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
// Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
// Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
// Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
// The total cost is 5 + 1 + 1 + 3 + 3 = 13.

// Example 2:

// Input: m = 2, n = 2, horizontalCut = [7], verticalCut = [4]

// Output: 15

// Explanation:

// Perform a cut on the horizontal line 0 with cost 7.
// Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
// Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
// The total cost is 7 + 4 + 4 = 15.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end(), greater<int>());
        sort(vc.begin(), vc.end(), greater<int>());
        
        int i = 0, j = 0;
        int horizontalParts = 1, verticalParts = 1;
        int cost = 0;
        
        while (i < vc.size() && j < hc.size()) {
            if (vc[i] > hc[j]) {
                cost += vc[i++] * horizontalParts;
                verticalParts++;
            } else {
                cost += hc[j++] * verticalParts;
                horizontalParts++;
            }
        }
        
        while (i < vc.size()) {
            cost += vc[i++] * horizontalParts;
        }
        while (j < hc.size()) {
            cost += hc[j++] * verticalParts;
        }
        
        return cost;
    }
};


int main(){
    Solution s;
    int m=3,n=2;
    vector<int> hc={1,3},vc={5};
    cout<<s.minimumCost(m,n,hc,vc)<<endl;
    
    return 0;
}