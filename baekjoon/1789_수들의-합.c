/*
맨 처음에 int형으로 하면 계속 틀렸다고 나오다가, long long 타입으로 하니까 통과되네.
타이핑이 이렇게 중요하구나....
*/

#include <stdio.h>

int main(void) {
    
    long long s;
    scanf("%d", &s);
    
    long long temp = 0;
    long long cnt = 0;
    long long adder = 1;
    
    while (temp < s) {
        temp += adder;
        cnt++; 
        // printf("temp: %d, adder: %d, cnt: %d\n", temp, adder, cnt);
        adder++;
    }
    
    if (temp <= s) {
        printf("%d", cnt);
    } else {
        printf("%d", cnt-1);
    }
}