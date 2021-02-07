#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {

    string number = to_string(n);
    int count = 0;
    for (int i=0; i< number.size(); i++){
        if( (int(number[i]) - 48) != 0){
            if(n%(int(number[i]) - 48) == 0){
                count++;
            }
        }
    }
    cout << count << endl;
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
