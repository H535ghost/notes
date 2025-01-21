class Solution {
public:
    int smallestValue(int n) {
        
        int ans = 0;
        while(1) {
            int tmp = n;
            for (int i = 2 ; i <= n / i ; i ++ ) {
                if (n % i == 0) {

                    while(n % i == 0) {
                        ans += i;
                        n /= i;
                    }
                }
            }
            if (n > 1) ans += n;
            if (ans == tmp) break;
            else {
                n = ans;
                ans = 0;
            }
        }
        return ans;
    }
};