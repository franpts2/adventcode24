#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int frequency_in_list(vector<int> list, int num)
{
    int count = 0;
    for (int i = 0; i < (int)list.size(); i++)
    {
        if (list[i] == num) count++;
    }
    return count;
}


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

    int sim_score = 0;
    for (int i = 0; i < (int)left_list.size(); i++)
    {
        int freq = frequency_in_list(right_list, left_list[i]);
        sim_score += (freq*left_list[i]);
    }

    cout << "Similarity score: " << sim_score << endl;

    return 0;
}