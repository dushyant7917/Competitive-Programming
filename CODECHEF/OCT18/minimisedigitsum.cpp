#include <bits/stdc++.h>

using namespace std;

long long digitsToSum(long long n)
{
    long long sum = 0;

    while(n)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }

    return sum;
}

int main()
{
    long long t, n ,d, minSteps, minNum, num, steps;

    cin >> t;

    while(t--)
    {
        cin >> n >> d;

        queue< pair < long long, long long > > q;

        q.push(make_pair(n, 0));

        minNum = minSteps = 1e10 + 1;

        while(q.empty() == false)
        {
            num = q.front().first;

            steps = q.front().second;

            q.pop();

            if(num < minNum)
            {
                minNum = num;

                minSteps = steps;
            }

            if(steps <= 10)
            {
                q.push(make_pair(digitsToSum(num), steps + 1));

                q.push(make_pair(num + d, steps + 1));
            }
        }

        cout << minNum << " " << minSteps << "\n";
    }

    return 0;
}
