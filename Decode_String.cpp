#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string currentString = "";
        int number = 0;

        for (char c : s) {

            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            }

            else if (c == '[') {
                countStack.push(number);
                stringStack.push(currentString);

                number = 0;
                currentString = "";
            }

            else if (c == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string previousString = stringStack.top();
                stringStack.pop();

                string decoded = "";

                for (int i = 0; i < repeat; i++) {
                    decoded += currentString;
                }

                currentString = previousString + decoded;
            }

            else {
                currentString += c;
            }
        }

        return currentString;
    }
};

int main() {
    Solution obj;

    string s = "3[a2[c]]";

    string result = obj.decodeString(s);

    cout << "Encoded String: " << s << endl;
    cout << "Decoded String: " << result << endl;

    return 0;
}