class Solution {
public:

    int gcdOfOddEvenSums(int n) {
        int sumodd =0, sumeven=0;
        for (int i = 1; i <= 2 * n - 1; i += 2)
    sumodd += i;

for (int i = 2; i <= 2 * n; i += 2)
    sumeven += i;
    return calcGCD(sumodd, sumeven);
    }
    
    
private:
    int calcGCD(int a, int b) {
     
        int gcd = 1;
        int smallest = (a < b) ? a : b;
        
        for (int x = smallest; x >= 1; x--) {
            if (a % x == 0 && b % x == 0) {
                gcd = x;
                break; 
            }
        }
        return gcd;
    }
};
