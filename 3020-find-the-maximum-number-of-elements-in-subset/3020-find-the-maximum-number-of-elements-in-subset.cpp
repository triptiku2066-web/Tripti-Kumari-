class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for(int num:nums){
            freq[num]++;
        }
        int max_len=1;
        if(freq.count(1)){
            int count_ones=freq[1];
            max_len=(count_ones %2==0)? count_ones-1: count_ones;
        }
        for(auto& [val, count]: freq){
            if(val==1) continue;
            long long curr=val;
            int current_len=0;
            while (curr<= 1e9 && freq.count(curr)&& freq[curr]>=2){
                current_len+=2;
                curr *=curr;
            }
            if(freq.count(curr)&& freq[curr]==1){
                current_len+=1;
            } else{
                current_len -= 1;
            }
            max_len = max(max_len, current_len);
        }
        return max_len;
    }
};