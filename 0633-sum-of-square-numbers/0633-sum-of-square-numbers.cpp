class Solution {
private:
    bool isSquare(int number) {
        if (number < 0) {
            return false;
        }
        int root = static_cast<int>(sqrt(number));
        return (root * root == number);
    }
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c/2); i++){
            if( isSquare(c - i * i)){
                cout << i << endl;
                return true;
            }
        }
        return false;
    }
};