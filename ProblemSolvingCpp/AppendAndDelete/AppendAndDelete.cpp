#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {

    int operations = 0;
    int number = 0;
    for (int i=0;i<t.length();i++){
        if(s[i] == t[i])
            number++;
        else
        {
            break;
        }                
    }

    if(s.length() < t.length()){
        operations = s.length() + t.length();
        if(operations > k){
            cout << "No" << endl;
            return "No";
        }
        else
        {
            cout << "Yes" << endl;
            return "Yes";
        }    
    }

    operations = (s.length() - number) + (t.length() - number);

    if(operations > k){
        cout << "No" << endl;
        return "No";
    }
    else
    {
        cout << "Yes" << endl;
        return "Yes";
    }    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}


/* test cases
Input (stdin)
Download
y
yu
2
Expected Output
Download
No

abcd
abcdert
10

Expected output: No

// cannot solve this case , don't understand why its answer is yes
Input (stdin)
Download
zzzzz
zzzzzzz
4
Expected Output
Download
Yes


*/