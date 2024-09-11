// Leetcode 50. Pow(x, n);

class Solution {
public:
    double myPow(double x, int n) {
        // if(x == 1 || x == 0)
        //         return x;

        int neg = n<0 ? true : false;
        n = abs(n);
        double pow = 1.0;

        while(n>0)
        {
            if(n%2 == 1){
                pow *= x;
                n = n-1;
                // if(n<=0) break;
            }
            else{
                n /= 2;
                x *= x;
            }
        }  

        if(neg) pow = 1.0 / pow;
        return pow;
    }
};