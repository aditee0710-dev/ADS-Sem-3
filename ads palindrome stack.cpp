#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n, temp;
    cin >> n;
    temp = n;
    stack<int> s;
    while (n > 0)
    {
        s.push(n % 10);
        n = n / 10;
    }
    int reverse = 0;
    while (!s.empty())
    {
        reverse = reverse * 10 + s.top();
        s.pop();
    }
    if (temp == reverse) cout << "Palindrome";
    else cout << "Not Palindrome"; 
    return 0;
}