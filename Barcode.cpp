#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back

int dots[1000+2];
int mem[1000+2][1000+2][3];
ll n , k , x , y;
int barcod(int col , int wid , int last){
    if(col == k) {
        if(wid < x || wid > y)
            return 10000000;
        return 0;
    }

    int& ret = mem[col][wid][last];
    if(ret != -1) return ret;
    int dot = 1e9;
    if(col == 0 || (last == 0 && wid+1 <= y) || (last == 1 && wid >= x))
        dot = n - dots[col] + barcod(col + 1 , (last == 0) ? wid+1 : 1 , 0);
    int hash = 1e9;
    if(col == 0 || (last == 1 && wid+1 <= y) || (last == 0 && wid >= x))
        hash = dots[col] + barcod(col + 1 , (last == 1) ? wid+1 : 1 , 1);
    ret = min(dot , hash);
    return ret;
}
int main() {
    fast

        cin >> n >> k >> x >> y;
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < k ;j++){
                char c;
                cin >> c;

                if(c == '.')
                    dots[j]++;
            }
        }
        memset(mem,-1,sizeof mem);
        cout << barcod(0 , 0 , 2);

    return 0;
}
