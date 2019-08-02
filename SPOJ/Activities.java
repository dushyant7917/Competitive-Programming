import java.util.*;
import java.io.*;
class Pair<T>{
    final T x;
    final T y;
    Pair(T a, T b){
        this.x = a;
        this.y = b;
    }
}

public class Activities{
    private static int search(Pair<Integer> []p,int key, int l, int h)
    {
		// FIND THE LOWEST INDEX OF THE REQUIRED ACTIVITY
        int ll=l;
        while(l<h)
        {
            int mid = (l+h)/2;
            if(p[mid].x < key)l=mid+1;
            else if(p[mid].x == key){
                while(mid>=ll && p[mid].x == key)mid--;
                return mid+1;
            }
            else h=mid;
        }
        if(l==h && l>=0 && p[l].x>=key)return l;
        return -1;
    }
    public static void main(String[] args)throws IOException {
        final long mod = 100000000;
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
    while(true)
    {
        int n = Integer.parseInt(buff.readLine());
        if(n==-1)return;
        Pair <Integer> p [] = new Pair[n];
        for(int i=0;i<n;i++){
            String [] in = buff.readLine().split(" ");
            int x = Integer.parseInt(in[0]), y = Integer.parseInt(in[1]);
            p[i] = new <Integer>Pair(x,y);
        }
        Arrays.sort(p, new Comparator<Pair<Integer>>(){
            public int compare(Pair<Integer> p1, Pair<Integer> p2){
                if(p1.x == p2.x)return p1.y - p2.y;
                else return p1.x - p2.x;
            }
        });

        long dp[] = new long[n];
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
            int idx = search(p,p[i].y,i,n-1);
            dp[i] = 1+dp[i+1]%mod;
            if(idx != -1)dp[i]=(dp[i]%mod+dp[idx]%mod)%mod;
        }
        String res = (dp[0]%mod)+"";
        while(res.length()<8)res = '0'+res;
        System.out.println(res);
    }

  }
}
