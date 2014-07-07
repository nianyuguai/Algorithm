#include <stdio.h>
#include <stdlib.h>

const char num[10]={"0123"};
#define N 4
#define M 3
int Queue[N]={0};
int top = 0;
int flag[N] = {0};

void perm(int s,int n)
{
    int i;
    if(s>n)
        return;
    if(s==n)
    {
        for(i = 0;i < n;i++)
        {
            printf("%c",Queue[i]);
        }
        printf("\t");
        return;
    }

    for(i = 0;i < n;i++)
    {
        if(flag[i]==0)
        {
            flag[i] = 1;
            Queue[s] = num[i];
            perm(s+1,n);
            flag[i] = 0;
        }
    }
}


void comb(int s,int m,int n)
{
    int i;

    if(s>n)
        return;
    if(top==m)
    {
        for(i = 0;i < m;i++)
        {
            printf("%c",Queue[i]);
        }
        printf("\t");
        return;
    }

    Queue[top++] = num[s];
    comb(s+1,n,m);
    top--;
    comb(s+1,n,m);

}
int main()
{
    int n;

    while(~scanf("%d",&n))
    {
        printf("\nperm():\n");
        perm(0,N);
        comb(0,N,M);
        printf("\n");
    }
    return 0;
}
