#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> 

void random(int n,int game[n][n])
{
    int num1,num2,add,i,j;
    srand(time(NULL));
    num1=rand()%n;
    num2=rand()%n; 
    for(i=0;i<num1;i++)
    {
        for(j=num2;j<n;j++)
        {
            if(game[i][j]==0)
            {
                game[i][j]=2;
                return;
            }
        }
    }
}
int game_over(int n,int game[n][n])
{    
    int i,j,resul=0;
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(game[i][j]==2048)
                {
                    resul=1;
                    break;
                }
                
                else if(game[i][j]==0)
                {   
                    resul=2;
                    continue;
                    
                }
                else if(game[i][j]==game[i+1][j] || game[i][j]==game[i][j+1] || game[i][j]==game[i][j-1] || game[i][j]==game[i-1][j] )
                {    
                    
                    resul=2;
                    continue;
                }
            }
        }
        if(resul==1)
        {    
            printf("You won the game congrats!!!!!");
            exit(0);
        }
        else if(resul==0)
        {  
            printf("You lost the game");
            exit(0);
        }
        //printf("%d\n",resul);    
}
int key_w(int n,int game[n][n])
{
    int i,j;
    for(j=0;j<n;j++)
    {
        i=1;
        while(1)
        {
            while(game[i][j]==0)
            {
                if(i==n)
                    break;
                i++;
            }
            if(i==n)
                break;
            while(i>0 && (game[i-1][j]==0 || game[i][j]==game[i-1][j]))
            {
                game[i-1][j]+=game[i][j];
                game[i][j]=0;
                i--;
            }
            i++;
        }
        game_over(n,game);
    }
}
int key_a(int n,int game[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        j=1;
        while(1)
        {
            while(game[i][j]==0)
            {
                if(j==n)
                    break;
                j++;
            }
            if(j==n)
                break;
            while(j>0 && (game[i][j-1]==0 || game[i][j]==game[i][j-1]))
            {
                game[i][j-1]+=game[i][j];
                game[i][j]=0;
                j--;
            }
            j++;
        }
        game_over(n,game);
    }
}

int key_d(int n,int game[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        j=2;
        while(1)
        {
            while(game[i][j]==0)
            {
                if(j==-1)
                    break;
                j--;
            }
            if(j==-1)
                break;
            while(j<n-1 && (game[i][j+1]==0 || game[i][j]==game[i][j+1]))
            {
                game[i][j+1]+=game[i][j];
                game[i][j]=0;
                j++;
            }
            j--;
        }
        game_over(n,game);
    }
}
int key_s(int n,int game[n][n])
{
    int i,j;
    for(j=0;j<n;j++)
    {
        i=2;
        while(1)
        {
            while(game[i][j]==0)
            {
                if(i==-1)
                    break;
                i--;
            }
            if(i==-1)
                break;
            while(i<n-1 && (game[i+1][j]==0 || game[i][j]==game[i+1][j]))
            {
                game[i+1][j]+=game[i][j];
                game[i][j]=0;
                i++;
            }
            i--;
        }
        game_over(n,game);
    }
}
int main()
{   
    int n,count=0,i,j,num1=0,num2=0;
    char c;
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                               Welcome to the game of 2048\n                 ");
    printf("              The goal of this game is to arrange the numbers to form 2048, atb!!!");
    printf("\n");
    printf("Enter the size of the 2048 grid[3,4,5]:\n");
    scanf("%d",&n);
    printf("To exit the game press 'n'\n");
    int game[n][n];
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            game[i][j]=0;
    game[n-1][0]=2;

    do
    {   
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++){
                /*if(game[i][j]==0)
                    game[i][j]=' ';*/
                printf("[\t%d\t]",game[i][j]);
                count=count+game[i][j];
                printf(" ");}    
            printf("\n\n");
        }
        
        printf("                                                                       score:%d",count);
        count=0;
        
        printf("\n");
        printf("Enter one of the keys('w','s','a','d'):");
        printf("\n");
        scanf(" %c",&c);

        if(c=='w')
        {
            key_w(n,game);
        }
        else if(c=='a')
        {
            key_a(n,game);
        }
        else if(c=='s')
        {
            key_s(n,game);
        }
        else if(c=='d')
        {
            key_d(n,game);
        }
        else if(c=='n')
        {
            break;
        }
        else
            printf("Press given characters only :)"); 
        random(n,game);
        game_over(n,game);   
        
    }while(c!='n');
}  

   
  

