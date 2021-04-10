#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long long repeatedString(string s, long long n) {
    long long result = 0;
    vector<int> pos(s.length());
    for (int i=0;i<s.length();i++){
        if(s[i] == 'a'){
            pos[i] = 1;
            result++;
        }  
        else{
            pos[i] = 0;
        }          
    }

    result = n/s.length() * result;

    int reminder = n%s.length();
    if(reminder != 0)
    for (int i=0;i<reminder;i++){
        if(pos[i] == 1){
            result++;
        }            
    } 
    cout << result << endl;
    return result; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

/*
Compiler Message
Wrong Answer
babbaabbabaababaaabbbbbbbababbbabbbababaabbbbaaaaabbaababaaabaabbabababaabaabbbababaabbabbbababbaabb
860622337747
Expected Output
Download
395886275361


Segmentation Fault
Input (stdin)
Download
epsxyyflvrrrxzvnoenvpegvuonodjoxfwdmcvwctmekpsnamchznsoxaklzjgrqruyzavshfbmuhdwwmpbkwcuomqhiyvuztwvq
549382313570
Expected Output
Download
16481469408

*/