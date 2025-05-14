#include<bits/stdc++.h>
using namespace std;

void nextSmaller(vector<int> &v) {
    int n = v.size();
    vector<int> res(n,-1);//store next smaller element
    stack<int> st;
    for(int i=n-1; i>=0; i--) {//traverse from n-1 to 0
        //check if st.top() is greater than new inserted element
        while(st.size() > 0 && st.top() > v[i]) {
            st.pop();
        }
        //if not then insert st.top() in res array
        if(st.size() > 0) {
            res[i] = st.top();
        }
        //push curr element to the stack
        st.push(v[i]);
    }
    for(int x : v) cout<<x<<" ";
    cout<<endl;
    for(int y : res) cout<<y<<" ";
}

int main() {
    vector<int> v = {10, 1, 7, 4, 2, 0, 8};
    nextSmaller(v);
    return 0;
}