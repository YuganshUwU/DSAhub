/*  LeetCode link : https://leetcode.com/problems/my-calendar-ii/
    Difficulty : Medium
*/

// Time Complexity : O(N)
// Space Complexity : O(N)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class MyCalendarTwo {
public:
    vector<pair<int, int>> books;
    vector<pair<int, int>> doubleBooks;

    MyCalendarTwo() {
        inc();
    }

    bool book(int start, int end) {
        for (pair<int, int> curr : doubleBooks) {
            if (max(start, curr.first) < min(end, curr.second))
                return false;
        }

        for (pair<int, int> curr : books) {
            if (max(start, curr.first) < min(end, curr.second))
                doubleBooks.push_back({max(start, curr.first), min(end, curr.second)});
        }

        books.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
