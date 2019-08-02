#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

int main(){
  ll q,n,cnt,ans_status;
  cin>>q;
  while(q--){
    cin>>n;
    ans_status=0;
    ll a[n],b[n];
    set<ll> u;
    loop(0,n){
      cin>>a[i];
      b[i]=a[i];
      u.insert(a[i]);
    }

    if(ans_status==0 && u.size()!=n){
      cout<<"Ugly\n";
      ans_status=1;
    }

    sort(b,b+n);
    if(ans_status==0){
      cnt=0;
      loop(0,n){
        if(a[i]==b[i]){
          cnt++;
        }
      }
      if(cnt==n){
        cout<<"Ugly\n";
        ans_status=1;
      }
    }

    if(ans_status==0){
      loop(0,n){
        if(a[i]>n || a[i]<1){
          cout<<"Ugly\n";
          ans_status=1;
          break;
        }
      }
    }
    if(ans_status==0){
      cout<<"Beautiful\n";
    }
  }

  return 0;
}
