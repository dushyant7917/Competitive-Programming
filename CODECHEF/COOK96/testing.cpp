#include <iostream>
#include <algorithm>
#include <string>
#include <assert.h>
#include <map>
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
int n,k;
int sm_n=0;
map<int,int> mp;
int h;
pair<int,int> arr[100100];
int sm[100100];
int m;
map<int,int>::iterator ii;
int main(){
    T=readIntLn(1,100);
    while(T--){
        mp.clear();
        n=readIntSp(1,100000);
        sm_n += n;
        assert(sm_n<=100000);
        k=readIntLn(0,n);
        k=n-k; // instead of selecting K sticks, we remove n-k sticks
        for(int i=0;i<n-1;i++){
            h=readIntSp(1,1000000000);
            mp[h]++; // keep frequencies of sticks in a map
        }
        h=readIntLn(1,1000000000);
        mp[h]++;
        m=1;
        for(ii=mp.begin();ii!=mp.end();ii++){
            if(ii->second > 1){
                arr[m++] = *ii;
            }
        }
        m--;
        int req=0;
        int mxx=0;
        for(int i=1;i<=m;i++){
            sm[i] = sm[i-1] + arr[i].second; // prefix sum of frequencies, we gonna need that
            if(arr[i].second > 1){
                req += arr[i].second -1;
                mxx = max ( arr[i].second -1,mxx);
            }
        }
        if (req -min(mxx,2)<= k){ // condition to tell if we can prevent having any rectangle
            cout<<"ans:"<<-1<<endl<<endl;
            continue;
        }

        //for(int i=m;i>=1;i--) cout<<arr[i].first<<"->"<<arr[i].second<<"\n"; cout<<"\n";

        long long ans=1ll<<60;
        for(int i=m;i>=1;i--){   // go through sticks from tallest to smallest
            cout<<"i:"<<i<<" freq:"<<arr[i].second<<"\n";
            if(arr[i].second > 3){ // if we leave more than 3 sticks of currently tallest stick then answer is immediately  arr[i].first * 1ll *arr[i].first
                if(arr[i].second - 3 > k){
                    ans = min(ans, arr[i].first * 1ll *arr[i].first);
                    break;
                }
                k -= arr[i].second - 3;
                arr[i].second= 3;
            }
            if(arr[i].second  == 3){ // if there are  3 sticks we don't know whether we should remove 2 sticks or not, sometimes first option is optimal sometimes second
                int l=1,r=i; // so if we decided to leave 3 sticks then Chef's brother clear will take 2 of them for first dimension of rectangle
                while(r-l>1){ // now we have to minimize the second dimension
                    int mid=(r+l)/2;
                    if(sm[i-1] - sm[mid-1] - (i-mid) > k){
                        l=mid;
                    }
                    else{
                        r=mid;
                    }
                }
                cout<<"ind:"<<l<<"\n";
                ans = min(ans,arr[i].first * 1ll * arr[l].first);
            }
            if(arr[i].second > 1){ // if there are more than 1 stick we have to take them
                if(arr[i].second - 1 > k){ // if we can't take them then we minimize the second dimension
                    for(int j=i-1;j>=1;j--){
                        if(arr[j].second - 1 > k){
                            ans = min (ans, arr[j].first * 1ll * arr[i].first);
                            break;
                        }
                        k -= arr[j].second - 1;
                    }
                    break;
                }
                k -= arr[i].second  - 1; // if we can take them we try this option
                arr[i].second = 1;
            }
        }
        cout<<"ans:"<<ans<<endl<<endl;
    }
    assert(getchar()==-1);
}
