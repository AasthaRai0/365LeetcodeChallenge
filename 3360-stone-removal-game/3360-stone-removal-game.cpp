class Solution {
public:
    bool canAliceWin(int n) {
        int moves=10;
        int turn = 0;
        while(n >= moves){
            n = n - moves;
            moves--;
            turn++;
        }
        return turn % 2 == 1;
    }
};