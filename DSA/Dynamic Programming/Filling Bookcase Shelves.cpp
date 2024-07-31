/*  Leetcode Link : https://leetcode.com/problems/filling-bookcase-shelves/
    Difficulty : Medium
*/

// By Recursion (TLE O(2^n));

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;
    int width;

    int finding(vector<vector<int>>& books, int idx, int maxH, int shelfWidth) {
        inc();

        if (idx >= n)
            return maxH;

        int bookHeight = books[idx][1];
        int bookWidth = books[idx][0];

        int take = INT_MAX;

        // keeping in the same shelf
        if (bookWidth <= shelfWidth) {
            take = finding(books, idx + 1, max(maxH, bookHeight), shelfWidth - bookWidth);
        }

        // skipping and keeping in the next shelf
        int skip = maxH + finding(books, idx + 1, bookHeight, width - bookWidth);

        return min(take, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        inc();
      
        n = books.size();
        width = shelfWidth;

        return finding(books, 0, 0, shelfWidth);
    }
};

------------------------------------------------------------------------------------------------------------------------

// By Recursion + Memoization (TC : O(n * shelfWidth), SC : O(n * shelfWidth + ))

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int n;
    int width;
    int dp[1001][1001];

    int finding(vector<vector<int>>& books, int idx, int maxH, int shelfWidth) {
        inc();

        if (idx >= n)
            return maxH;

        if(dp[idx][shelfWidth] != -1)
            return dp[idx][shelfWidth];

        int bookHeight = books[idx][1];
        int bookWidth = books[idx][0];

        int take = INT_MAX;

        // keeping in the same shelf
        if (bookWidth <= shelfWidth) {
            take = finding(books, idx + 1, max(maxH, bookHeight), shelfWidth - bookWidth);
        }

        // skipping and keeping in the next shelf
        int skip = maxH + finding(books, idx + 1, bookHeight, width - bookWidth);

        return dp[idx][shelfWidth] = min(take, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        inc();

        memset(dp, -1, sizeof(dp));
        
        n = books.size();
        width = shelfWidth;

        return finding(books, 0, 0, shelfWidth);
    }
};
