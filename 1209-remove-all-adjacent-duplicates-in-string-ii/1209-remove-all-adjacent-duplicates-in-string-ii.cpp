class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char c : s){
            if(!st.empty() && st.top().first == c){
                st.top().second++;
                if(st.top().second == k){
                    st.pop();
                }
            }else{
                st.push({c, 1});
            }
            
        }
        string result = "";
        while(!st.empty()){
            char ch = st.top().first;
            int cnt = st.top().second;
            result = string(cnt, ch) + result;
            st.pop();
        }
        return result;
    }
};