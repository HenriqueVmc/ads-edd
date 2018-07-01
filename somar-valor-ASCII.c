#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char c[10];
    int n[5],i=0,s=0;
    for(i=0;i<5;i++){
        n[i]=0;
        c[i]=0;
    }
    scanf("%s",c);

    int t=strlen(c);

    for(i=0;i<t;i++){
        n[i]=c[i];
        s+=n[i];
    }
    printf(">>%i\n", s);

    return 0;
}
