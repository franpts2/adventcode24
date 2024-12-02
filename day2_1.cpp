//your puzzle input consists of many reports, one report per line. 
//Each report is a list of numbers called levels that are separated by spaces

//a report only counts as safe if both of the following are true:
// - The levels are either all increasing or all decreasing.
// - Any two adjacent levels differ by at least one and 
//   at most three.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

bool all_increasing_by_at_least_1_at_most_3(vector<int> v)
{
    for (int i = 0; i < (int)v.size()-1; i++)
    {
        if (v[i] > v[i+1] || v[i] == v[i+1])
        {
            return false;
        }
        if (abs(v[i] - v[i+1]) < 1 || abs(v[i] - v[i+1]) > 3)
        {
            return false;
        }
    }
    return true;
}

bool all_decreasing_by_at_least_1_at_most_3(vector<int> v)
{
    for (int i = 0; i< (int)v.size()-1; i++)
    {
        if (v[i] < v[i+1] || v[i] == v[i+1])
        {
            return false;
        }
        if (abs(v[i] - v[i+1]) < 1 || abs(v[i] - v[i+1]) > 3)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int safe_count = 0;

    string line;

    while (getline(cin,line))
    {
        vector<int> v;
        
        stringstream ss(line);
        int num;
        while (ss >> num)
        {
            v.push_back(num);
        }

        if ((all_increasing_by_at_least_1_at_most_3(v))
            || (all_decreasing_by_at_least_1_at_most_3(v)))
        {
            safe_count++;
        }
    }

    cout << "Safe reports: " << safe_count << endl;

    return 0;
}