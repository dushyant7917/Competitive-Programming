#include <iostream>
#include <vector>
using namespace std;

int whoWins(vector<int> first, vector<int> second)
{
    bool firstWins = false;
    bool secondWins = false;
    for (int i = 0; i < 3; i++)
    {
        if (first[i] < second[i])
        {
            if (firstWins)
                return 0;
            secondWins = true;
        }
        else if (first[i] > second[i])
        {
            if (secondWins)
                return 0;
            firstWins = true;
        }
    }

    if (!firstWins && !secondWins)
        return 0;
    else if (firstWins)
        return -1;
    else
        return 1;
}

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        vector<int> first;
        vector<int> second;
        vector<int> third;

        for (int j = 0; j < 3; j++)
        {
            int value;
            cin >> value;
            first.push_back(value);
        }
        for (int j = 0; j < 3; j++)
        {
            int value;
            cin >> value;
            second.push_back(value);
        }
        for (int j = 0; j < 3; j++)
        {
            int value;
            cin >> value;
            third.push_back(value);
        }

        int result;
        result = whoWins(first, second);
        if (result == 0)
        {
            cout << "no" << endl;
            continue;
        }
        else
        {
            // First Wins
            if (result == -1)
            {
                result = whoWins(first, third);
                if (result == 0)
                {
                    cout << "no" << endl;
                    continue;
                }
                else
                {
                    // First Wins
                    if (result == -1)
                    {
                        // First at top. Just compare second and third
                        result = whoWins(second, third);
                        if (result != 0)
                            cout << "yes" << endl;
                        else
                            cout << "no" << endl;
                        continue;
                    }
                    // Third Wins and is at top. First already won against second
                    else
                    {
                        cout << "yes" << endl;
                        continue;
                    }
                }
            }
            // Second Wins
            else
            {
                result = whoWins(second, third);
                if (result == 0)
                {
                    cout << "no" << endl;
                    continue;
                }
                else
                {
                    // Second Wins and is at top.
                    if (result == -1)
                    {
                        result = whoWins(first, third);
                        if (result != 0)
                            cout << "yes" << endl;
                        else
                            cout << "no" << endl;
                        continue;
                    }
                    // Third Wins and is at top. First already lost to second
                    else
                    {
                        cout << "yes" << endl;
                        continue;
                    }
                }
            }
        }
    }

    return 0;
}
