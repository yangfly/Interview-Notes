#include <iostream>
#include <string>
using namespace std;

bool same_str(string & s, int la, int lb, int n)
{
    for (int i = 0; i < n; i++)
        if (s[la++] != s[lb++])
            return false;
    return true;
}

int shorttt(string & s)
{
    int n = s.length();
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i != 0) continue;
        int j;
        for (j = i; j < n; j += i) {
            if (!same_str(s, 0, j, i))
                break;
        }
        if (j >= n)
            return i;
    }
    return n;
}

int main()
{
    string s = "112112";
    cout << shorttt(s) << endl;
    return 0;
}



// int walk(int target)
// {
//     if (target == 0)
//         return 0;
//     target = abs(target);
//     int sum = -target, k = 0;
//     while (sum < 0 || sum % 2 != 0) {
//         sum += ++k;
//     }
//     return k;
// }

// int main()
// {
//     int target;
//     cin >> target;
//     cout << walk(target);
//     return 0;
// }
