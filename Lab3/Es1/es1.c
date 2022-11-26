#include <stdio.h>
#include <stdlib.h>

int majorityW(int *v, int n);
int majorityR(int l, int r, int *v);
int majority(int a, int b);

int main() {
    int v[8]={2, 2, 0, 1, 1, 2, 2, 2};
    int m = majorityW(v, 8);
    
    
    if (m==-1)
        printf("No majority element");
    else
        printf("Majority element = %d", m);

    return 0;
}

int majorityW(int *v, int n) {
    int l=0, r=n-1;
    return majorityR(l, r, v);
}
#include <stdio.h>
#include <stdlib.h>

int majorityW(int *v, int n);
int majorityR(int l, int r, int *v);
int majority(int a, int b);

int main() {
    int v[8]={2, 2, 0, 1, 1, 2, 2, 2};
    int m = majorityW(v, 8);
    
    
    if (m==-1)
        printf("No majority element");
    else
        printf("Majority element = %d", m);

    return 0;
}

int majorityW(int *v, int n) {
    int l=0, r=n-1;
    return majorityR(l, r, v);
}

int majorityR(int l, int r, int *v) {
    int q = (l+r)/2;
    if (l == r) {
        return v[l];
    }
    int a = majorityR(l, q, v);
    int b = majorityR(q+1, r, v);
    int x = majority(a, b);
    if (x == -1) {
        int cnta=0, cntb=0;
        for (int i=l; i<=r; i++) {
            if (v[i]==a)
                cnta++;
            if (v[i]==b)
                cntb++;
        }
        if (cnta > (r-l+1)/2)
            return a;
        if (cntb > (r-l+1)/2)
            return b;
    }
    return x;
}

int majority(int a, int b) {
    if (a==b)
        return a;
    return -1;
}

#include <stdio.h>
#include <stdlib.h>

int majorityW(int *v, int n);
int majorityR(int l, int r, int *v);
int majority(int a, int b);

int main() {
    int v[8]={2, 2, 0, 1, 1, 2, 2, 2};
    int m = majorityW(v, 8);
    
    
    if (m==-1)
        printf("No majority element");
    else
        printf("Majority element = %d", m);

    return 0;
}

int majorityW(int *v, int n) {
    int l=0, r=n-1;
    return majorityR(l, r, v);
}

int majorityR(int l, int r, int *v) {
    int q = (l+r)/2;
    if (l == r) {
        return v[l];
    }
    int a = majorityR(l, q, v);
    int b = majorityR(q+1, r, v);
    int x = majority(a, b);
    if (x == -1) {
        int cnta=0, cntb=0;
        for (int i=l; i<=r; i++) {
            if (v[i]==a)
                cnta++;
            if (v[i]==b)
                cntb++;
        }
        if (cnta > (r-l+1)/2)
            return a;
        if (cntb > (r-l+1)/2)
            return b;
    }
    return x;
}

int majority(int a, int b) {
    if (a==b)
        return a;
    return -1;
}




int majorityR(int l, int r, int *v) {
    int q = (l+r)/2;
    if (l == r) {
        return v[l];
    }
    int a = majorityR(l, q, v);
    int b = majorityR(q+1, r, v);
    int x = majority(a, b);
    if (x == -1) {
        int cnta=0, cntb=0;
        for (int i=l; i<=r; i++) {
            if (v[i]==a)
                cnta++;
            if (v[i]==b)
                cntb++;
        }
        if (cnta > (r-l+1)/2)
            return a;
        if (cntb > (r-l+1)/2)
            return b;
    }
    return x;
}

int majority(int a, int b) {
    if (a==b)
        return a;
    return -1;
}


