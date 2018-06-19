#include <stdio.h>

int main(void){
    int i, j, k, l; //counter
    int n; //size of matrix

    puts("Please input size.(n>=3)");
    scanf("%d",&n);
    if(n<3) return -1;

    //Making I_n
    int inv[n*n][n*n];
    int e[n*n][n*n];
    for(i=0;i<n*n;i++){
        for(j=0;j<n*n;j++){
            if(i==j){
                inv[i][j]=1;
                e[i][j]=1;
            }else{
                inv[i][j]=0;
                e[i][j]=0;
            }
        }
    }

    //Making expansion adjacent matrix(E_n)
    for(i=0;i<n*n;i++){
        for(j=0;j<n*n;j++){
            if(i>=n)        e[i][i-n]=1;
            if(i%n!=0)      e[i][i-1]=1;
            if((i+1)%n!=0)  e[i][i+1]=1;
            if(i<n*n-n)     e[i][i+n]=1;
        }
    }

    puts("E_n:");
    for(i=0;i<n*n;i++){
        for(j=0;j<n*n;j++) printf("%d ", e[i][j]);
        puts("");
    }

    for(i=1;i<n*n;i++){
        for(j=0;j<i;j++){
            if(e[i][j]!=0){
                for(k=i+1;k<n*n;k++){
                    if(e[k][j]!=0){
                        for(l=0;j<n*n;j++) e[i][l]=(e[i][l]+e[k][l])&1;
                    }
                }
            }
        }
    }

    puts("");
    for(i=0;i<n*n;i++){
        for(j=0;j<n*n;j++) printf("%d ", e[i][j]);
        puts("");
    }

    return 0;
}
