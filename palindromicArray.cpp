/*
Palindromic Array

Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

Explanation:
For First test case.
n=5;
A[0] = 111    //which is a palindrome number.
A[1] = 222   //which is a palindrome number.
A[2] = 333   //which is a palindrome number.
A[3] = 444  //which is a palindrome number.
A[4] = 555  //which is a palindrome number.
As all numbers are palindrome so This will return 1.
*/

#include <bits/stdc++.h>
using namespace std;

int palinArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int rev = 0, temp = arr[i];
        while (temp > 0)
        {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }
        if (rev != arr[i])
            return 0;
    }
    return 1;
}

int main()
{
    int arr[] = {111, 222, 333, 444, 555};
    int n = 5;

    cout << "\nThe given array is a plaindromic array (1 or 0) : " << palinArray(arr, n) << endl;

    cout << endl;
    return 0;
}