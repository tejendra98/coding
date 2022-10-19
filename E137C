#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        string s;
        cin>>s;
        stack<int> st;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                if(s[i]=='0') {
                    st.push(arr[i]);
                }
                else {
                    ans+=arr[i];
                }
            }
            else {
                if(s[i]=='0') {
                    st.pop();
                    st.push(arr[i]);
                }
                else {
                    if(arr[i]<st.top()) {
                        ans+=st.top();
                        st.pop();
                        st.push(arr[i]);
                        s[i]='0';
                    }
                    else {
                        ans+=arr[i];
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
