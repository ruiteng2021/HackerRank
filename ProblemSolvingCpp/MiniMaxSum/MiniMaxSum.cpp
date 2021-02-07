
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {

    long long min = 0;
    long long max = 0;
    sort(arr.begin(), arr.end()); 
    
    for(int i=0;i<arr.size()-1;i++)
    {
        min = min + arr[i];
    }
    for(int j=1;j<arr.size();j++)
    {
        max = max + arr[j];
    }

    cout << min << " " << max << endl;

}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}





/*
#include <bits/stdc++.h> // Vector 
#include <algorithm>  // Sort
using namespace std; 
  
int main() 
{ 
// Initalizing the vector v with these values
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
// Vector is sorted in ascending order   
    sort(v.begin(), v.end()); 
    
    for(int i: v)
    {
        cout << i << " ";
    }
    

    return 0; 
} 
*/