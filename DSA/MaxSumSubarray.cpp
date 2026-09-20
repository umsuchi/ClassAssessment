class Solution {
  public:
    int maxSubarraySum(vector<int>& a, int k) {

        int sum = 0;
                
        for(int i = 0; i<k ; i++) sum += a[i];
        
        int t = sum;

        for(int j = 0, i = k; i<a.size(); i++, j++){
            
            sum -= a[j], sum += a[i];
               
            t = ((sum > t) ? sum : t);
        }

        return t;
    }
};
