#include <bits/stdc++.h>

using namespace std;

#define MAX 1002
#define INFINITE (1 << 15)
int arr[MAX][MAX];
struct Pnt 
{
    int x, y, max_val;
    Pnt() {}
    Pnt(int x, int y, int max_val) : x(x), y(y), max_val(max_val) {}

    bool operator < (const Pnt& other) const 
    {
        return max_val < other.max_val;
    }
};

struct Segtree2d 
{
    Pnt tree[1000000];
    int n, m;
    void initialization(int n, int m) {
        this -> n = n;
        this -> m = m;
        build(1, 1, 1, n, m);
    }

    Pnt query_2D(int x1, int y1, int x2, int y2) 
    {
        return query_2D(1, 1, 1, n, m, x1, y1, x2, y2);
    }

    Pnt build(int val, int a1, int b1, int a2, int b2) 
    {

        if (a1>a2 || b1>b2)
            return Pnt(0, 0, -INFINITE);

        if (a1 == a2 && b1 == b2)
            return tree[val] = Pnt(a1, b1, arr[a1][b1]);

        tree[val] = Pnt(0, 0, -INFINITE);
        tree[val] = max(tree[val], build(4 * val - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );
        tree[val] = max(tree[val], build(4 * val - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
        tree[val] = max(tree[val], build(4 * val + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );
        tree[val] = max(tree[val], build(4 * val + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );
        return tree[val];
    }

    Pnt query_2D(int val, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2) 
    {
        if (x1>a2||y1>b2||x2<a1||y2<b1||a1>a2||b1>b2)
            return Pnt(0, 0, -INFINITE);
        if (x1<=a1&&y1<=b1&&a2<=x2&&b2<=y2)
            return tree[val];

        Pnt max_val = Pnt(0, 0, -INFINITE);
        max_val = max(max_val, query_2D(4 * val - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2) );
        max_val = max(max_val, query_2D(4 * val - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2) );
        max_val = max(max_val, query_2D(4 * val + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2) );
        max_val = max(max_val, query_2D(4 * val + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2));
        return max_val;
    }

    
};
;
Segtree2d Tree_max;


/* Drier program */
int main(void) {
    int n, m;
    // input
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &arr[i][j]);

    // initializationialize
    Tree_max.initialization(n, m);

    // query_2D
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    cout<<Tree_max.query_2D(x1, y1, x2, y2).max_val<<endl;

    return 0;
}