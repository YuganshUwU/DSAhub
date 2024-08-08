/*  Leetcode link : https://leetcode.com/problems/design-parking-system/
    Difficulty : Easy
*/

// Time Complexity : O(1) 
// Space Complexity : O(1)

#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class ParkingSystem {
public:
    int B, M, S;

    ParkingSystem(int big, int medium, int small) : B(big), M(medium), S(small) {
        inc();
    }

    bool addCar(int carType) {
        if (carType == 1 && B) {
            B--;
            return true;
        } else if (carType == 2 && M) {
            M--;
            return true;
        } else if (carType == 3 && S) {
            S--;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
