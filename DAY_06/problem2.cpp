// Stock span problem
// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector <int> ans(arr.size());
        stack <int> st;
        for (int i = 0;i < arr.size();i++){
            while (!(st.empty()) && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if (st.empty()){
                ans[i] = i + 1;
            }
            else{
                ans[i] = i - st.top();
            }
            st.push(i);
        }
        return ans;
    }
};