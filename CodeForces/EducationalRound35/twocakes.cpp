#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
int main(){
int n,a,b;
cin>>n>>a>>b;
int ans=0,lv;
fr(i,1,n){
lv=min(a/i,b/(n-i));
ans=max(ans,lv);
}
cout<<ans;
return 0;
}
