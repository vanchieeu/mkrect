#include <iostream>
using namespace std;

typedef long long ll;

void swap(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(ll *a, int l, int r) {
    ll p = a[(l+r)/2];

    int i = l, j = r;
    while (i < j) {
        while (a[i] > p)
            i++;

        while (p > a[j])
            j--;

        if (i <= j) {
            swap(a+i, a+j);

            i++;
            j--;
        }
    }

    if (i < r)
        quickSort(a, i, r);
    if (l < j)
        quickSort(a, l, j);
}

int main() {
    int n;
    cin >> n;

    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n-1);

    ll max = 0, min = 0;
    bool checkMax = false, checkMin = false;

    for (int i = 0; i < n; i++) {
        if (max < a[i] && a[i] == a[i+1] && !checkMax) {
            max = a[i];
            i++;
            checkMax = true;
            continue;
        } else if (min == 0 && a[i] == a[i+1] && !checkMin) {
            min = a[i];
            checkMin = true;
            break;
        } 
    }

    if (checkMax && checkMin)
        cout << min*max;
    else
        cout << 0;
    return 0;
}