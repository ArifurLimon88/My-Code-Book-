#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105000;

int n;
int a[MAXN], tmp[MAXN];

void mergesort(int l, int r) {
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergesort(l, mid);
    mergesort(mid + 1, r);

    int p1 = l, p2 = mid + 1, cur = 1;
    while (p1 <= mid || p2 <= r) {
        if (p1 > mid || (p2 <= r && a[p2] < a[p1])) {
            tmp[cur] = a[p2];
            p2++;
        }
        else {
            tmp[cur] = a[p1];
            p1++;
        }
        cur++;
    }

    for (int i = 1; i <= r - l + 1; i++)
        a[l + i - 1] = tmp[i];
}

int main() {
    //assert(freopen("input.txt","r",stdin));
    //assert(freopen("output.txt","w",stdout));

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    mergesort(1, n);

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}
