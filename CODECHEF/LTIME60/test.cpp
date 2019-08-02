#include <iostream>
#include <algorithm>
#include <string>
#include <assert.h>
using namespace std;


long long readInt(long long l,long long r,char endd){
    long long x=0;
    int cnt=0;
    int fi=-1;
    bool is_neg=false;
    while(true){
        char g=getchar();
        if(g=='-'){
            assert(fi==-1);
            is_neg=true;
            continue;
        }
        if('0'<=g && g<='9'){
            x*=10;
            x+=g-'0';
            if(cnt==0){
                fi=g-'0';
            }
            cnt++;
            assert(fi!=0 || cnt==1);
            assert(fi!=0 || is_neg==false);
            assert(!(cnt>19 || ( cnt==19 && fi>1) ));
        } else if(g==endd){
            assert(cnt>0);
            if(is_neg){
                x= -x;
            }
            assert(l<=x && x<=r);
            return x;
        } else {
            assert(false);
        }
    }
}
string readString(int l,int r,char endd){
    string ret="";
    int cnt=0;
    while(true){
        char g=getchar();
        assert(g!=-1);
        if(g==endd){
            break;
        }
        cnt++;
        ret+=g;
    }
    assert(l<=cnt && cnt<=r);
    return ret;
}
long long readIntSp(long long l,long long r){
    return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
    return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
    return readString(l,r,'\n');
}
string readStringSp(int l,int r){
    return readString(l,r,' ');
}

int T;
int n;
int sm_n=0;
string s,s2;


int b=31;
long long mod=1000000007;
long long p2[400400];
/*long long hsh[400400],hsh2[400400];
void hash_init(){
    for(int i=1;i<=n;i++){
        hsh[i] = (hsh[i-1] + (s[i] - 'a') * p2[i]) % mod;
        hsh2[i] = (hsh2[i-1] + (s2[i] - 'a') * p2[i]) % mod;
    }
}

long long get_hsh(int l,int r){
    return ((((hsh[r] - hsh[l-1]) * p2[n-l])% mod)+mod)%mod;
}

long long get_hsh2(int l,int r){
    return ((((hsh2[r] - hsh2[l-1]) * p2[n-l])% mod)+mod)%mod;
}
long long is_pal(int l,int r){
    return get_hsh(l,r) == get_hsh2(n-r+1,n-l+1);
}*/
int main(){
    //freopen("05.txt","r",stdin);
    //freopen("05o.txt","w",stdout);
    p2[0]=1;
    for(int i=1;i<400400;i++){
        p2[i]= (p2[i-1] * b)%mod;
    }
    T=readIntLn(1,1000);
    while(T--){
        s=readStringLn(1,200000);
        n= s.length();
        sm_n += n;
        for(int i=0;i<n;i++){
            assert('a'<=s[i] && s[i]<='z');
        }
        s2=s;
        reverse(s2.begin(),s2.end());

        int sol=0;
        long long hsh=0,hsh2=0;
        for(int i=0;i<n;i++){
            hsh += p2[i] * (s[i] - 'a');
            hsh %= mod;
            hsh2 += p2[i] *(s2[i] - 'a');
            hsh2 %= mod;
        }
        for(int i=0;i<n;i++){
            hsh -= p2[i] * ( s[i] - 'a');
            hsh += p2[i+n] * ( s[i] - 'a');
            hsh %= mod;
            if(hsh < 0 ) hsh += mod;
            hsh2 *= p2[2];
            hsh2 %= mod;
            hsh2 -= p2[n+1+i] * (s2[n-1-i] - 'a');
            hsh2 += p2[i+1] * (s2[n-1-i] - 'a');
            hsh2 %= mod;
            if(hsh2 < 0 ) hsh2 += mod;
            if(hsh  == hsh2)sol++;
        }
        cout<<sol<<endl;
    }
    assert(getchar()==-1);
}
