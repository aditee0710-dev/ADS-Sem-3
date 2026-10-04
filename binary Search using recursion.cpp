#include <bits/stdc++.h>
using namespace std;
int binarysearch(int arr[], int beg, int end, int item) {
    if (beg > end)
        return -1;
    int mid = (beg + end) / 2;

    if (arr[mid] == item)
        return mid;

    if (item < arr[mid])
        return binarysearch(arr, beg, mid - 1, item);
    return binarysearch(arr, mid + 1, end, item);
}
int main() {
    int n;
    cout << "Enter size:" << endl;
    cin >> n;
    if (n <= 0) {
        cout << "Invalid size" << endl;
        return 0;
    }
    int *arr = new int[n];
    cout << "Enter array elements in sorted order:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int item;
    cout << "Enter item:" << endl;
    cin >> item;
    int loc = binarysearch(arr, 0, n - 1, item);
    if (loc == -1)
        cout << "Item not found" << endl;
    else
        cout << "Element found at index " << loc << endl;
    delete[] arr;
    return 0;
}