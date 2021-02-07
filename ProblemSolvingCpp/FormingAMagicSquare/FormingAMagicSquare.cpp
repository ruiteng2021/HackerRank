#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {

    int cost = INT_MAX;
    vector<vector<int>> t = 
    {
        {4,9,2,3,5,7,8,1,6},
        {4,3,8,9,5,1,2,7,6},
        {2,9,4,7,5,3,6,1,8},
        {2,7,6,9,5,1,4,3,8},
        {8,1,6,3,5,7,4,9,2},
        {8,3,4,1,5,9,6,7,2},
        {6,7,2,1,5,9,8,3,4},
        {6,1,8,7,5,3,2,9,4},
    };

    int temp = 0;
    for(int i=0;i<8;i++){
        temp = abs(s[0][0]-t[i][0]) + abs(s[0][1]-t[i][1]) +abs(s[0][2]-t[i][2]) + abs(s[1][0]-t[i][3]) + abs(s[1][1]-t[i][4]) + abs(s[1][2]-t[i][5])+ abs(s[2][0]-t[i][6]) + abs(s[2][1]-t[i][7]) + abs(s[2][2]-t[i][8]);
        cost = temp<cost?temp:cost;
    }
    cout << cost << endl;
    return cost;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
