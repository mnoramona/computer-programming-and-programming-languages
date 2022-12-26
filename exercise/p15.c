#include <stdio.h>
int main()
{
    int n;
    int a[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int maxim = -1e9, left, right;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
          int sum=0;
            for(int k=i; k<=j; k++)
                sum=sum+a[k];
              if(sum>maxim){
                maxim=sum;
                left=i; 
                right=j;
            }
        }
    }
    for(int i=left; i<=right; i++)
        printf("%d ", a[i]);
    return 0;
}