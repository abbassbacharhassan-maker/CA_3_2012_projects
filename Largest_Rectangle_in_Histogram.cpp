#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        // Add zero to process remaining bars
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                int area = height * width;

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main() {
    Solution obj;

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = obj.largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}