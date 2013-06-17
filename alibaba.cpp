#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

stack<char> st;
char input[10002];
int main()
{
		freopen("alibaba.in","r",stdin);
		freopen("alibaba.out","w",stdout);
    int n,m;
    scanf("%d %d\n",&n,&m);
		gets(input);
		m=n-m;
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && (st.size()+n-i-1)>=m && st.top()<input[i])
            st.pop();
        st.push(input[i]);
    }
    vector<char> res;
    while(!st.empty())//reverse writing and done
    {
        res.push_back(st.top());
        st.pop();
    }
    for(int i = res.size()-1; i >= 0; i--)
    	printf("%c",res[i]);
    
}
