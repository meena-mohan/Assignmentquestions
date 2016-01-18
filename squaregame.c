#include <stdio.h>
#include<stdlib.h>
void array(int arr[][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(arr[i][j]!=0)
			{
				printf("|%d| ",arr[i][j]);
			}
			else
			{
				printf("| | ");
			}
		}
	}
}
void lookforempty(int arr[][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
	  for(j=0;j<4;j++)
	  {
	  	 if(arr[i][j]==0)
	  	 {
	  	 	b_row=i;
	  	 	b_col=j;
	  	 }
	  }
	}
}
void swap(int b_row,int b_col,char mov,int arr[][4])
{
   int temp,i,j;
   switch(mov)
   {
   	 case 'U':
   	        if(b_row!=0)
   	        {
   	        	temp=arr[b_row][b_col];
   	        	arr[b_row][b_col]=arr[b_row-1][b_col];
   	        	arr[b_row-1][b_col]=temp;
   	        }
   	        break;
   	 case 'R':
   	        if(b_col!=3)
   	        {
   	            temp=arr[b_row][b_col];
   	        	arr[b_row][b_col]=arr[b_row][b_col+1];
   	        	arr[b_row][b_col+1]=temp;
   	        }
   	        break;
   	 case 'L':
   	        if(b_col!=0)
   	        {
   	        	temp=arr[b_row][b_col];
   	        	arr[b_row][b_col]=arr[b_row][b_col-1];
   	        	arr[b_row][b_col-1]=temp;
   	        }
   	        break;
   	 case 'D':
   	         if(b_row!=3)
   	         {
   	         		temp=arr[b_row][b_col];
   	            	arr[b_row][b_col]=arr[b_row+1][b_col];
   	            	arr[b_row+1][b_col]=temp;
   	         }
   }
}

int checkforvalue(int arr[][4])
{
	int flag=0,n=1,i,j;
	for(i=0;i<4;i++)
    {
       for(j=0:j<4;j++)
       {
       	  if(arr[i][j]!=0)
       	  {
       	  	n++;
       	  	if(n==15)
       	  	{
       	  	  flag=1;
       	  	  break;
       	  	}
       	  }
       	  else
       	  {
       	  	flag=0;
       	  	break;
       	  }
       }
    }
    return flag;
}

int main(void)
{
	int arr[4][4]={{1,5,9,2},{4,7,11,15},{3,0,6,13},{8,10,12,14}};
	int b_row,b_col;
	char mov;
    while(mov!='Q');
	{
		system("clear");
		lookforempty(arr);
		swap(b_row,b_col,mov,arr);
		array(arr);
		printf("U->up,D->down,L->left,R->right,Q->quit\n");
		printf("use oly caps\n");
		printf("enter the character:\n");
		scanf("%c",&mov);
		flag=checkforvalue(arr);
		if(flag==1)
		{
			printf("\nyou won the game\n");
			break;
		}
	}
	if(mov=='Q')
	{
		printf("u lose");
	}
	return 0;
}

