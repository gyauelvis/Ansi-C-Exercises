#include <stdio.h>

int power(int, int);
int power1(int, int, int);

main(void){
    printf("power: %d ", power1(5,4,1));
}

int power(int m, int n){
    int ans = 1;
    for(int i = 0; i<n; i++)ans *= m;
    return ans;
}

// power function implemented with recursion 
int power1(int m, int n, int ans) {
    if(n == 0) return ans;
    ans = m * power1(m, n - 1, ans);
}