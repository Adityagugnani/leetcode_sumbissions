class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int common = gcd(x, y);
        if (common == target || x + common == target || y + common == target ||
            x + y == target || ((x % y) + x) == target ||
            (x % y + y) == target || (y % x + y) == target ||
            (y % x + x) == target || abs(x - y) + common == target ||
            target == x || target == y) {
            return true;
        }
        return false;
    }
};