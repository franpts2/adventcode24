#include <iostream>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

//"mul(" + n1 + ","" + n2 + ")"
tuple<bool,int,int> is_well_formatted_mul(const string& str, size_t pos_mul)
{
    // Check if the position is valid
    if (pos_mul == string::npos) {
        return {false, 0, 0};
    }
    
    size_t pos_comma = str.find(",",pos_mul);
    size_t pos_end = str.find(")", pos_comma);

    // Check for proper formatting and boundaries
    if (pos_comma == string::npos || pos_end == string::npos) {
        return {false, 0, 0};
    }

    //extract numbers as substrings
    string n1str = str.substr(pos_mul + 4, pos_comma - (pos_mul + 4));
    string n2str = str.substr(pos_comma + 1, pos_end - (pos_comma + 1));

    //validate the numbers
    if (n1str.empty() || n2str.empty() || !isdigit(n1str[0]) || !isdigit(n2str[0])) {
        return {false, 0, 0};
    }

    
    //to int
    int n1 = stoi(n1str);
    int n2 = stoi(n2str);

    //1-3 digit numbers
    if (n1str.length() > 3 || n2str.length() > 3) {
        return {false, 0, 0};
    }

    return {true, n1, n2};
}

int perform_muls(vector<tuple<bool,int,int>> muls) 
{
    int total_mul = 0;
    for (const auto & mul : muls)
    {
        int a = get<1>(mul);
        int b = get<2>(mul);

        total_mul += a*b;
    }

    return total_mul;
}

int main()
{
    string line;
    vector<tuple<bool,int,int>> muls;
    while (getline(cin,line))
    {
        size_t start_pos = 0;

        while (true)
        {
            size_t pos_mul = line.find("mul(", start_pos);
            if (pos_mul == string::npos) {
                break; //no more occurrences
            }

            // Parse and validate the mul(X, Y) format
            auto result = is_well_formatted_mul(line, pos_mul);
            if (get<0>(result)==true) {
                muls.push_back(result);     //store valid results
            }

            // Move start position forward
            start_pos = pos_mul + 4;
        }
    }

    // Output stored mul(X, Y) results
    for (const auto& mul : muls) {
        cout << "mul(" << get<1>(mul) << "," << get<2>(mul) << ")\n";
    }

    int res = perform_muls(muls);

    cout << "Result: " << res << endl;

    return 0;
}