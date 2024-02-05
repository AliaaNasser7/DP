#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back

int mem[100000+2][2] , n;
vector<pair<int,int>>trees(1e5+2);

int mxtree(int i , int rol){
    if(i >= n-1)
        return 0;

    int &ret = mem[i][rol];
    if(ret != -1)
        return ret;

    if(trees[i].first - trees[i].second > trees[i-1].first + rol * trees[i-1].second)
        ret = max(ret , 1 + mxtree(i+1 , 0));

    if(trees[i].first + trees[i].second < trees[i+1].first)
        ret = max(ret , 1 + mxtree(i+1 , 1));

    return max(ret , mxtree(i+1 , 0));
}

int main() {
        fast
        cin >> n ;

        for(int i = 0 ;i < n ;i++){
            cin >> trees[i].first >> trees[i].second;
        }

        if(n <= 2) {
            cout << n;
            return 0;
        }

        memset(mem,-1,sizeof mem);
        cout<<mxtree(1,0)+2;

    return 0;
}
