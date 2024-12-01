#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    vector<int> left_list;
    vector<int> right_list;

    while (getline(cin, line))
    {
        string leftie = line.substr(0, line.find(' '));
        string rightie = line.substr(line.find(' ') + 1);

        int lefti = stoi(leftie);
        int righti = stoi(rightie);

        left_list.push_back(lefti);
        right_list.push_back(righti);
    }
    sort(left_list.begin(), left_list.end());
    sort(right_list.begin(), right_list.end());

    // cout << "Left list: ";
    // for (int num : left_list) cout << num << " ";
    // cout << endl;

    // cout << "Right list: ";
    // for (int num : right_list) cout << num << " ";
    // cout << endl;

    int total_dist = 0;
    for (int i = 0; i < (int)left_list.size(); i++)
    {
        int dist = abs(left_list[i] - right_list[i]);
        total_dist += dist;
    }

    cout << "Total distance: " << total_dist << endl;

    return 0;
}