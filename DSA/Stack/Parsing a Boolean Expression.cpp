/*  LeetCode link : https://leetcode.com/problems/parsing-a-boolean-expression/
    Difficulty : Hard
*/

// Time Complexity : O(N)
// Space Complexity : O(N)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    bool parseBoolExpr(string expression) {
        inc();

        string curr = "";

        for (char& ch : expression) {
            if (ch == ',')
                continue;
            else if (ch != ')')
                curr.push_back(ch);
            else {

                string temp = "";
                while (!curr.empty() && curr.back() != '(') {
                    temp.push_back(curr.back());
                    curr.pop_back();
                }

                curr.pop_back();
                char operation = curr.back();
                curr.pop_back();

                bool result = (temp.front() == 't');
                if (operation == '!')
                    curr.push_back(result ? 'f' : 't');
                else {

                    for (int i = 1; i < temp.length(); i++) {
                        if (operation == '|')
                            result |= (temp[i] == 't');
                        else
                            result &= (temp[i] == 't');
                    }

                    curr.push_back(result ? 't' : 'f');
                }
            }
        }

        return curr.front() == 't';
    }
};
