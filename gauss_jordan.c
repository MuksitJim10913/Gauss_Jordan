#include<stdio.h>
int main()
{
    int i,j,k,n;
    float A[20][20],c,x[10],check[50],b;
    printf("\nEnter the size of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf(" A[%d][%d]:", i,j);
            scanf("%f",&A[i][j]);
        }
    }


    for( i=1;i<n;i++)
        {
            for( j=1;j<=(n+1);j++)
            {
                check[j]=A[i][j]/A[i+1][j];
            }

           for( j=1;j<=n;j++)
           {
              if(check[j]==check[j+1])
               {
                  b=1;
               }
               else if((b==1)&&(check[j]!=check[j+1]))
               {
                  b=2;
               }
           }
        }
        if(b==1)
        {
            printf("infinite solution");
        }
        else if(b==2)
        {
            printf("No solution");
        }
        else
        {

    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i==j){
                A[i][j]=A[i][j]/A[i][j];
            }

           else if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }

    printf("\nThe solution is:\n");
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1]/A[i][i];
        printf("\n x%d=%f\n",i,x[i]);
    }
    return(0);
}
}

