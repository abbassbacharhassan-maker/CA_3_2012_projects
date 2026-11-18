
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;

        for (int i = 0; i < accounts.size(); i++) {
            int sum = 0;

            for (int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[i][j];
            }

            maxWealth = max(maxWealth, sum);
        }

        return maxWealth;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> accounts = {
        {1, 5},
        {7, 3},
        {3, 5}
    };

    cout << obj.maximumWealth(accounts);

    return 0;
}
