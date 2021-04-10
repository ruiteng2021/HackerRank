#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    int pageToTurnFrom1;
    int pageToTurnFromLast;
    int min;

    if((p-1)%2 == 0){
        pageToTurnFrom1 = (p-1)/2;
    }
    else
    {
        pageToTurnFrom1 = floor((p-1)/2) + 1;
    }

    if((n-p)%2 == 0){
        pageToTurnFromLast = (n-p)/2;
    }
    else
    {
        if((n%2)!=0 && (n-p)==1)
            pageToTurnFromLast = 0;
        else if((n%2)==0 && (n-p)==1)
            pageToTurnFromLast = 1;
        else if((n%2)!=0) {
            pageToTurnFromLast = floor((n-p)/2);
        }  
        else
        {
            pageToTurnFromLast = floor((n-p)/2) + 1;
        }         
    }

    if (pageToTurnFrom1 >= pageToTurnFromLast)
        min = pageToTurnFromLast;
    else
    {
        min = pageToTurnFrom1;
    }  

    cout << min << endl;
    return min;
}

int main()
{
    int result;
    ofstream fout(getenv("OUTPUT_PATH"));
    for(;;){

         int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int p;
        cin >> p;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        result = pageCount(n, p);
    }
   
    fout << result << "\n";

    fout.close();

    return 0;
}
