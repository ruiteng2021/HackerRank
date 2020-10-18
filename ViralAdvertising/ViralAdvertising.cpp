#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {

    int shared = 5;
    int liked = 2;
    int cumulative = 2;

    for (int i=2; i<=n; i++){
        shared = liked * 3;
        liked = floor(shared/2);       
        cumulative = cumulative + liked;
    }
    cout << cumulative << endl;
    return cumulative;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
