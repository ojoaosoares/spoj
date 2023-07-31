#include <stdio.h>

int main() {
    int n,x1,x2, total = 10;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x1);
        if(i > 0) {
            if(x1 - x2  < 10)
            total += x1 - x2;
            else total += 10;
        }
        x2 = x1;
    }
    printf("%d\n",total);
    
}