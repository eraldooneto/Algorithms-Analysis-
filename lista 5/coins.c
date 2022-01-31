#include <stdio.h>

int max(int a,int b) 
{
    return a>b?a:b;
}

int robot_coin_collect(int m,int n,int a[][n])
{
    int i=1,j=1,k,c[m][n];

    c[0][0]=a[0][0];

    while(i<m && a[i][0]!=-1)
    {
        c[i][0]=c[i-1][0]+a[i][0];
        i=i+1;
    }

    for(;i<m;i++)
        c[i][0]=-6;

		while(j<n && a[0][j]!=-1)
		{
		    c[0][j]=c[0][j-1]+a[0][j];
		    j=j+1;
		}

    for(;j<n;j++)
        c[0][j]=-6;

    display(m,n,c);   
    printf("\n\n");

    for(i=1;i<m;i++)
    {
         for(j=1;j<n;j++)
         {
            if(a[i][j]!=-1)
                c[i][j]=max(c[i-1][j],c[i][j-1])+a[i][j];
            else
                c[i][j]=-6;
         }
    } 

    display(m,n,c);      
    return c[m-1][n-1];
}

void display(int m,int n,int c[][n])
{
     int i,j;

     for(i=0;i<m;i++)  
     {   
        for(j=0;j<n;j++)
            printf("%d\t",c[i][j]);
        printf("\n");
    }
}
