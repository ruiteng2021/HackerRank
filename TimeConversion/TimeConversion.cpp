#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    string time = "00000000";
    string hourS = "00";

    time[0] = s[0];
    time[1] = s[1];
    time[2] = s[2];
    time[3] = s[3];
    time[4] = s[4];
    time[5] = s[5];
    time[6] = s[6];
    time[7] = s[7];

    if (s[8] == 'P'){
        if ((time[0] != '1') && (time[1] != '2') || 
            (time[0] == '1') && (time[1] == '0') ||
            (time[0] == '1') && (time[1] == '1') ||
            (time[0] == '0') && (time[1] == '2')){
            hourS[0] = s[0];
            hourS[1] = s[1];
            int hourI = stoi(hourS);
            hourI += 12;
            string hourBuf = to_string(hourI); 
            time[0] = hourBuf[0];
            time[1] = hourBuf[1];           
        }
    }
    else
    {
        if ((time[0] == '1') && (time[1] == '2')){
            time[0] = '0';
            time[1] = '0';
        }
    }
    return time;      
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string result;

    for(;;){

        string s;
        getline(cin, s);
        result = timeConversion(s);
        cout << result << endl << endl;
    }

    fout << result << "\n";
    fout.close();

    return 0;
}
