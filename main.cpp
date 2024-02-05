#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back

vector<int>days(101);
int mem[105][5], n;

int vac(int curr , int prev){
        if(curr == n)
            return 0;

        int &ret = mem[curr][prev];
        if(ret != -1)
            return ret;

        if(days[curr] == 0 || prev == days[curr])
            ret = vac(curr+1, 0) + 1;       //leave

        else if(days[curr] != 3)
            ret = vac(curr+1, days[curr]);

        else{
            if(prev == 0 || prev == 4)
                ret  = min(vac(curr+1 , 1) , vac(curr+1, 2));

            else if(prev == 1)
                ret = vac(curr+1, 2);

            else
                ret = vac(curr+1 , 1);
        }
        return ret;
}

int main() {
    fast

    cin >> n ;

    for(int i = 0 ;i < n ;i++){
        cin>>days[i];
    }

    memset(mem,-1,sizeof mem);
    cout<< vac(0,4);

    return 0;
}
