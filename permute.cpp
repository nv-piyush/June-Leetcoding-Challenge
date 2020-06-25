class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector <char> candidates(n);
        
        for(int i = 0; i < n; i++)
           candidates[i] = ((i + 1) + '0');
        
        vector <int> fact(n + 1);
        fact[0] = 1;
        
        for(int i = 1; i <= n; i++)
           fact[i] = fact[i - 1] * i;
        
        k--;
        for(int i = n - 1; i >= 0; i--){
           int idx = k / fact[i];
           ans += candidates[idx];
            
           for(int j = idx; j + 1< candidates.size(); j++)
              candidates[j] = candidates[j + 1];
            
           k = k % fact[i];
        }
        return ans;
    }
};
