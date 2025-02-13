class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        int count=0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(pq.size()>=2){
            long long first=pq.top();
            pq.pop();
            long long second=pq.top();
            pq.pop();
            if(first>=k && second>=k){
                return count;
            }
            long long sum=min(first,second);
            sum*=2;
            sum+=max(first,second);
            pq.push(sum);
            count++;
        }return count;
    }
};