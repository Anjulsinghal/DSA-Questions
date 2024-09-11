//204. Count primes with Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;

        vector<bool> seen(n, false);
        int ans = 0;

        for (int num = 2; num < n; num++) {
            if (seen[num]) continue;
            ans++;
            if (num > sqrt(n)) continue;  // Prevent overflow
            for (int mult = num * num; mult < n; mult += num) {
                seen[mult] = true;
            }
        }

        return ans;
    }
};