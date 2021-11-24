class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            int temp = i;
            while(temp > 0){
                int digit = temp%10;
                if(digit == 0 || i%digit != 0){
                    break;
                }
                temp=temp/10;
            }
            if(temp == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};