#include <stdio.h>

int main() {
    int c = 1,d = 1, x1, x2;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&x1);
        if(i > 0) {
            if(x1 >= x2) d = 0;
            if(x1 <= x2) c = 0;
        }
        x2 = x1;
    }
    
    if(c) printf("C\n");
    else if(d) printf("D\n");
    else printf("N\n");
    
}