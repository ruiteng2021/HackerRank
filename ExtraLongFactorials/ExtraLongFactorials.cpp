#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    vector <int> res; 
      // Initialize result 
    res.push_back(1); 
    
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n 
    for (int i=2; i<=n; i++) {
        // calc last result with new factor
        int carry = 0;
        int resSize = res.size();
        for (int j=0; j<resSize; j++){
            int temp = res[j] * i + carry;
            carry = temp/10;
            res[j] = temp%10; // temp%10 is the last digit          
        }
        while(carry){
            res.push_back(carry%10);
            carry = carry/10;
        }
    }    

    //cout << "Factorial of given number is \n"; 
    for (int i=res.size()-1; i>=0; i--) 
        cout << res[i]; 
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

int multiply(int x, int res[], int res_size) 
{ 
    int carry = 0;  // Initialize carry 
  
    // One by one multiply n with individual digits of res[] 
    for (int i=0; i<res_size; i++) 
    { 
        cout << "res[i]: " << res[i] << endl;

        int prod = res[i] * x + carry; 
        cout << "prod: " << prod << endl;

        // Store last digit of 'prod' in res[]   
        res[i] = prod % 10;   
        cout << "res[i]: " << res[i] << endl;

        // Put rest in carry 
        carry  = prod/10;     
        cout << "carry: " << carry << endl;
    } 
  
    // Put carry in res and increase result size 
    while (carry) 
    { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
} 


// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    int res[500]; 
  
    // Initialize result 
    res[0] = 1; 
    int res_size = 1; 
  
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n 
    for (int x=2; x<=n; x++) 
        res_size = multiply(x, res, res_size); 
  
    //cout << "Factorial of given number is \n"; 
    for (int i=res_size-1; i>=0; i--) 
        cout << res[i]; 
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
*/