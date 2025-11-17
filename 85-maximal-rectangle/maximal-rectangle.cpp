class Solution {
public:
    vector<int> NSL(vector<int> &temp){
        vector<int> nsl;
        stack<int> st;
        for(int i=0;i<temp.size();i++){
            if(st.empty()){
                nsl.push_back(-1);
            }else if(temp[st.top()]<temp[i]){
                nsl.push_back(st.top());
            }else{
                while(!st.empty() && temp[st.top()]>=temp[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl.push_back(-1);
                }else if(temp[st.top()]<temp[i]){
                    nsl.push_back(st.top());
                }
            }
            st.push(i);
        }
        return nsl;
    }
    vector<int> NSR(vector<int> &temp){
        vector<int> nsr;
        stack<int> st;
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                nsr.push_back(n);
            }else if(temp[st.top()]<temp[i]){
                nsr.push_back(st.top());
            }else{
                while(!st.empty() && temp[st.top()]>=temp[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsr.push_back(n);
                }else if(temp[st.top()]<temp[i]){
                    nsr.push_back(st.top());
                }
            }
            st.push(i);
        }
        reverse(nsr.begin(),nsr.end());
        return nsr;
    }
    int maxAreaOfHistogram(vector<int> &temp){
        vector<int> nsl=NSL(temp);
        vector<int> nsr=NSR(temp);
        int n=temp.size();
        int maxx=0;
        for(int i=0;i<n;i++){
            cout<<"nsl:"<<nsl[i]<<" "<<"nsr:"<<nsr[i]<<endl;
            int ind=(nsr[i]-nsl[i]-1)*temp[i];
            // ind*=temp[i];
            maxx=max(maxx,ind);
        }
        cout<<"--------"<<endl;
        return maxx;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j]-'0';
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=dp[i-1][j]+1;
                }else{
                    dp[i][j]=0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            vector<int> &temp=dp[i];
            int area=maxAreaOfHistogram(temp);
            ans=max(ans,area);
        }
        return ans;

    }
};