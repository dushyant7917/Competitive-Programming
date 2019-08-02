    #include<bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef double dbl;
    #define fr(x,a,b) for(ll x=a;x<b;x++)
    #define rf(x,a,b) for(ll x=a;x>=b;x--)
    #define pii pair<ll,ll>
    #define fi first
    #define se second
    #define PB push_back
    #define MP make_pair
    #define mod 1000000007
    #define gmax LLONG_MAX
    #define gmin LLONG_MIN
    #define INF 2e9
    #define N 100001
    #define MAX(a,b,c) max(max(a,b),c)
    #define MIN(a,b,c) min(min(a,b),c)
    #define SZ(s) ((ll)s.size())
    #define MS(x,v) memset(x,v,sizeof(x))

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ll n,c;
        cin>>n>>c;

        ll low=1,high=n,mid,flag;

        while(low<=high) {
            mid=low+(high-low)/8;

            cout<<1<<" "<<mid<<"\n";
            cin>>flag;

            if(flag==1) {
                cout<<2<<"\n";
                high=mid-1;
            } else low=mid+1;
        }

        cout<<3<<" "<<low<<"\n";

        return 0;
    }
