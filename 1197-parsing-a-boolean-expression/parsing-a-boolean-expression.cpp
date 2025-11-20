class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto it:expression){
            if(it=='(' || it==','){
                continue;
            }else if(it=='t' || it=='f' || it=='&' || it=='|' || it=='!'){
                st.push(it);
            }else{
                bool hasTrue=false,hasFalse=false;
                while(!st.empty() && st.top()!='&' && st.top()!='|' && st.top()!='!'){
                    if(st.top()=='t'){
                        hasTrue=true;
                    }
                    if(st.top()=='f'){
                        hasFalse=true;
                    }
                    st.pop();
                }
                char ch=st.top();
                st.pop();
                if(ch=='!'){
                    st.push((hasTrue)?'f':'t');
                }else if(ch=='|'){
                    st.push((hasTrue)?'t':'f');
                }else{
                    st.push((hasFalse)?'f':'t');
                }
            }
        }
        return st.top()=='t';
    }
};