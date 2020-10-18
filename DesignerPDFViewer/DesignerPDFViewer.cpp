#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word) {
    vector<int> letterHeights;
    vector<char> letters = {'a','b','c','d','e','f','g','h','i',
                            'j','k','l','m','n','o','p','r','s',
                            't','u','v','w','x','y','z'};
    for(int i=0;i<word.length();i++){
        switch(word[i]){
            case 'a':
               letterHeights.push_back(h[0]); 
               break;
            case 'b':
               letterHeights.push_back(h[1]); 
               break;
            case 'c':
               letterHeights.push_back(h[2]); 
               break;
            case 'd':
               letterHeights.push_back(h[3]); 
               break;
            case 'e':
               letterHeights.push_back(h[4]); 
               break;
            case 'f':
               letterHeights.push_back(h[5]); 
               break;
            case 'g':
               letterHeights.push_back(h[6]); 
               break;
            case 'h':
               letterHeights.push_back(h[7]); 
               break;
            case 'i':
               letterHeights.push_back(h[8]); 
               break;
            case 'j':
               letterHeights.push_back(h[9]); 
               break;
            case 'k':
               letterHeights.push_back(h[10]); 
               break;
            case 'l':
               letterHeights.push_back(h[11]); 
               break;
            case 'm':
               letterHeights.push_back(h[12]); 
               break;
            case 'n':
               letterHeights.push_back(h[13]); 
               break;
            case 'o':
               letterHeights.push_back(h[14]); 
               break;
            case 'p':
               letterHeights.push_back(h[15]); 
               break;               
            case 'q':
               letterHeights.push_back(h[16]); 
               break;
            case 'r':
               letterHeights.push_back(h[17]); 
               break;
            case 's':
               letterHeights.push_back(h[18]); 
               break;
            case 't':
               letterHeights.push_back(h[19]); 
               break;
            case 'u':
               letterHeights.push_back(h[20]); 
               break;
            case 'v':
               letterHeights.push_back(h[21]); 
               break;
            case 'w':
               letterHeights.push_back(h[22]); 
               break;
            case 'x':
               letterHeights.push_back(h[23]); 
               break;
            case 'y':
               letterHeights.push_back(h[24]); 
               break;
            case 'z':
               letterHeights.push_back(h[25]); 
               break;
            default:
               cout << "Wrong!" << endl;
               break;
        }     
    }

    int maxHeight = *max_element(letterHeights.begin(), letterHeights.end());
    cout << maxHeight*letterHeights.size() << endl;
    return maxHeight*letterHeights.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

    fout << result << "\n";

    fout.close();

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
