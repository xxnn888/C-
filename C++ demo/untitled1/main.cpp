#include<iostream>
#include <stack>
#include<algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        st.push(s[i]);
    }
    for (int i = 0; i < s.size(); ++i) {
        if (st.top() != s[i]) {
            cout << s << "���ǻ��ġ�";
            return 0;
        } else {
            st.pop();
        }
    }
    cout << s << "�ǻ��ġ�";
    return 0;
}
