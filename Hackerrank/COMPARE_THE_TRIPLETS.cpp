#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int i,sa=0,sb=0;
    int a[3];
    for(i=0;i<3;i++)
      scanf("%d",&a[i]);
    int b[3];
    for(i=0;i<3;i++)
            scanf("%d",&b[i]);
    for(i=0;i<3;i++)
    {
    if(a[i]>b[i])
        sa++;
        else if(b[i]>a[i])
            sb++;
    }
        
        printf("%d %d",sa,sb);
    return 0;
}