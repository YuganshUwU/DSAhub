/*  Leetcode link : https://leetcode.com/problems/snapshot-array/
    Difficulty : Medium
*/

// Approach 1  TC : O(1), SC : O(length* snap_id) ~ MLE

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class SnapshotArray {
public:
    vector<vector<int>> result;
    vector<int> temp;
    int snapID;

    SnapshotArray(int length) {
        inc();

        snapID = 0;
        temp.resize(length, 0);
    }

    void set(int index, int val) { 
        temp[index] = val; 
    }

    int snap() {
        result.push_back(temp);
        snapID++;

        return snapID - 1;
    }

    int get(int index, int snap_id) { 
        return result[snap_id][index]; 
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

------------------------------------------------------------------------------------------------------------

// Approach 2  TC : O(log(n)) , where n = number of elements in the indexth element , SC : O(length)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> result;
    int snapID;

    SnapshotArray(int length) {
        inc();

        snapID = 0;
        result.resize(length);

        for (int i = 0; i < length; i++) {
            result[i].push_back({0, 0});
        }
    }

    void set(int index, int val) {
        result[index].push_back({snapID, val}); 
    }

    int snap() {
        snapID++;

        return snapID - 1;
    }

    int get(int index, int snap_id) {
        int l = 0;
        int r = result[index].size() - 1;
        int output = 0;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(result[index][mid].first <= snap_id){
                output = result[index][mid].second;
                l = mid + 1;
            } else
                r = mid - 1;
        }

        return output;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

------------------------------------------------------------------------------------------------------------

// Approach 3 : Using STL - Complexities : (same as above)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> result;
    int snapID;

    SnapshotArray(int length) {
        inc();

        snapID = 0;
        result.resize(length);

        for (int i = 0; i < length; i++) {
            result[i].push_back({0, 0});
        }
    }

    void set(int index, int val) { result[index].push_back({snapID, val}); }

    int snap() {
        snapID++;

        return snapID - 1;
    }

    int get(int index, int snap_id) {
        auto it = upper_bound(result[index].begin(), result[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
