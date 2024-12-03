//the same rules apply as before, 
//except if removing a single level from an unsafe report 
//would make it safe, the report instead counts as safe.

//your answer is too low.
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

bool is_completely_safe(vector<int> v)
{
    if ((all_increasing_by_at_least_1_at_most_3(v))
            || (all_decreasing_by_at_least_1_at_most_3(v)))
    {
        return true;
    }
    return false;
}

bool considered_safe(vector<int> v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        vector<int> v_copy = v;
        v_copy.erase(v_copy.begin() + i);
        if (is_completely_safe(v_copy))
        {
            return true;
        }
    }
    return false;
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

        if (is_completely_safe(v) || considered_safe(v))
        {
            safe_count++;
        }
    }

    cout << "Safe reports: " << safe_count << endl;

    return 0;
}