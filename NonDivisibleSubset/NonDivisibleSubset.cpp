#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s) {
    int ans;
    /*
    map<int,int> temp;
    for (auto x: s){
        temp[x % k] += 1;
    }
    */

    vector<int> temp(k);
    for (int x=0; x< s.size();x++){
        temp[s[x]%k] += 1;
    }

    if(temp[0]>0) // 1. 0 can only be one seleted
        ans++;
    for (int i = 1;i<k;i++){
        if(temp[i] == 0) continue;
        if(i+i==k){ // 2. reminder 2 can only one selected
            ans++;
        }
        else{
            ans += max(temp[i], temp[k-i]); // 3. temp[i], temp[k-i] will be only the max selected
            temp[i] = 0;
            temp[k-i] = 0;
        }
    }

    cout << endl;
    cout << ans << endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

/*
test case
15 7
278 576 496 727 410 124 338 149 209 702 282 718 771 575 436
ans: 11
7 4
19 10 12 10 24 25 22
ans : 3

6 9
422346306 940894801 696810740 862741861 85835055 313720373
Expected Output
5

*/

/*
here's the logic complete which follows BigO(n) complexity of the algorithm suppose let's say u give input 10 13 where K=13 and the values are : 
2375782 21836421 2139842193 2138723 23816 21836219 2948784 43864923 283648327 23874673.

Now the main logic behind this is if:

(a+b)%K=0(means evenly divisible) then (a%k+b%K=K)

Hence, we take first take the remainders of all the input integers by dividing them with K, In this case we divide all the integers by K=13 which 
gives us the following set of remainders:

6 9 8 2 0 2 7 11 1 4

now look carefully in the remainder set,

i.) 11+2=13=K thus, we cannot have both 11 and 2 , we must select one of them based on the higher frequency, 
in this case 2 has a higher frequency than 11 so SELECT all the 2s

ii.) 7+6=13=K thus, we cannot have both 7 and 6 , we must select one of them based on the higher frequency, 
in this case 6 and 7 both have equal frequencies so select any one of them, let's say(we select 6)

iii.) 9+4=13=k thus, we cannot have both 9 and 4 , we must select one of them based on the higher frequency, 
in this case 9 and 4 both have equal frequencies so select any one of them, let's say(we select 9)

now we are left with remainders 1,8,0

so the final subset of remainders comes out to be

[6,9,2,2,1,8,0]
the length of this subset is the answer which is"7"

Hope this helps:)
also there are two special cases

1.)if k=0 then return 1 since none will be divisible

2.)if k=1 then return 1 since all the numbers will be divisible

https://www.youtube.com/watch?v=jkhxkYC06mo

*/
/*
// Complete the nonDivisibleSubset function below.
    static int nonDivisibleSubset(int k, int[] S) {
        // In maths. if (a + b) % k = 0 => then ((a % k) + (b % k)) % k = 0
        // Example: (5 + 7) % 6 = 0 => then (5 % 6) + (7 % 6) > (5 + 1) % 6 = 0

        // Solution: Find remainder of each element in the array.
        // then, choose max element from the pair which together can able to be divided by k. If one pair is "i" then other pair will be "k-i"
        // For example: S = {2, 3, 7, 8, 12} and k = 5.
        // Now we have 3 numbers whose remainder 2 => ( 2 % 5 = 2, 7 % 5 = 2, 12 % 5 = 2)
        // and also we have 2 numbers whose remainder 3 => (3, 8)
        // Right now we have to choose one of the element from that pair (3, 2) (where 3 > numbers 2, 7, 12 && 2 > numbers 3, 8)
        // Because of the problem, we will choose the max which is 3.

        int[] remainderArr = new int[k];
        // find remainder of each element in the array S
        // For example k = 4, S = {0, 5, 7, 10} => remainderArr will be: {0, 1, 1, 1}
        // where each index represents remainder. For example remainderArr[2] = 1 means
        // that there is 1 number whose remainder 2 after divided 4. (10 % 4 = 2)
        for (Integer each : S) {
            remainderArr[each % k]++;
        }

        // After getting each remainder, index 0 (actually remainder 0) is a special case
        // Think of it like this:
        //      1. There will be no element such as k - 0 = k. (remainderArr[k] will give us ArrayIndexOutOfBoundsException)
        //      2. If there are 2 elements in remainderArr[0], we have to choose only 1, otherwise, we can sum up 2 or more
        //         zeros, then non-sub divisible set could be divisible by k.
        int zeroRemainder = remainderArr[0];

        // That's why, our initial subset size is 1, if there is a zero remainder,
        //                                           otherwise it is 0
        int maxNumberOfDivisibleSet = zeroRemainder > 0 ? 1 : 0;

        // Another thing is that pair which is itself. That's means, let's say k = 4, therefore pair of remainderArr[2]
        // will also be remainderArr[2]( i = 2 then, k - i = 2). Thus, we have to choose only 1 element from that pair (or we should increment
        // the result number just 1)
        // if condition "i != k - i" will handle this situation.
        for (int i = 1; i <= (k / 2); i++) {
            if (i != k - i)
                maxNumberOfDivisibleSet += Math.max(remainderArr[i], remainderArr[k - i]);
            else
                maxNumberOfDivisibleSet ++;
        }

        return maxNumberOfDivisibleSet;
    }
    */