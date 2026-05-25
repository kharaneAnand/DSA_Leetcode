class Solution {
public:
    void swapTwoNumber(int a , int b) {
        a = a^b ;
        b = a^b ;
        a = a^b ;
    }
};