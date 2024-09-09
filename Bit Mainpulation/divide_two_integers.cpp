//Leetcode 29.divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == dividend) return 1;
        int sign = true;
        if((dividend <= 0 && divisor >0)) sign = false;
        else if((dividend >= 0 && divisor < 0)) sign = false;
        long n = abs(dividend);
        long d = abs(divisor);
        long ans = 0;
        while(n >= d){
            int cnt = 0;
            while(n >= (d<<(cnt+1))){
                cnt += 1;
            }

            ans += 1<<cnt;
            n = n-(d << cnt);
        }
        if(ans == (1<<31) && sign ){
            return INT_MAX;
        }
        if(ans == (1<<31) && !sign ){
            return INT_MIN;
        }

        return sign ? ans : -ans;
    }
};