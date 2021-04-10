#include <bits/stdc++.h>
#include <chrono>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

// removed all cout statement, otherwise cost many time to print , some test case will fail

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {

    vector<int> buffRanked; 
    vector<int> result;

    for (int i=0; i<ranked.size(); i++){
        buffRanked.push_back(ranked[i]);
        int count = 0;
        for (int j=i+1; j<ranked.size(); j++){
            if(ranked[i] == ranked[j]){
                count ++;
            }
            else
            {
                i = i + count;
                break;
            }             
        }
    }

    for (int i=0; i<player.size(); i++) {
        int left = 0;
        int right = buffRanked.size()-1;
        int middle =0;

        while(left < right){
            middle = floor((left+right)/2);
            //cout << player[i] << " " << buffRanked[middle] << endl;
            if (player[i] > buffRanked[middle]){
                right  = middle - 1;
            }
            else if (player[i] < buffRanked[middle]){
                left  = middle + 1;
            }
            else
            {
                /* code */
                result.push_back(middle+1);
                //cout << middle+1 << endl;
                break;
                //cout << left << endl;
            }      
        }

        if(left > right){
            result.push_back(middle+1);
            //cout << middle+1 << endl;
        }

        if(left == right){
            //cout << middle << endl;
            if(player[i] < buffRanked[left]){
                result.push_back(left+2);
                //cout << left+2 << endl;
            }
            else if(player[i] > buffRanked[left])
            {
                result.push_back(left+1);
                //cout << left+1 << endl;
            }
            else
            {
                result.push_back(left+1);
                //cout << left+1 << endl;
            }
            
            
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
