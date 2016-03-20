#include<stdio.h>

void print_piece(int t);

void main()
{
int board[8][8],i,j,a,b,steps,m,t,p=0,pass,check1=0,check2=0,n;
char c[2],play1[20],play2[20];
printf("     Welcome to the game of CHESS     \n      CODER:  pkkonda\n\nEnter password:");
scanf("%d",&pass);
if(pass==1996)
{
    printf("\nEnter player1 name:");
    scanf("%s",play1);
    printf("\nEnter player2 name:");
    scanf("%s",play2);
    system("cls");

for(i=0;i<8;i++)
 {
    for(j=0;j<8;j++)
     {
      board[i][j]=0;
     }
 }
for(i=1;i<9;i+=5)
{
    for(j=0;j<8;j++)
    {
        if(i==1)
            board[i][j]=2;
        else
            board[i][j]=3;
    }
}
board[0][0]=board[0][7]=4;//player1 elephant
board[7][0]=board[7][7]=5;//player2 elephant
board[0][1]=board[0][6]=6;//player1 horse
board[7][1]=board[7][6]=7;//player2 horse
board[0][2]=board[0][5]=8;//player1 minister
board[7][2]=board[7][5]=9;//player2 minister
board[0][3]=10;//player1 queen
board[7][3]=11;//player2 queen
board[0][4]=12;//player1 king
board[7][4]=13;//player2 king


/*########   PRINTER   #######*/
for(i=0;i<8;i++)
 {
  for(j=0;j<8;j++)
   {
       if(board[i][j]==0)
       {
           if((i%2==0&&j%2==0)||(i%2!=0&&j%2!=0))
            printf("   __  ");
           else
            printf("   ..  ");
       }
      else
        {
            print_piece(board[i][j]);
        }
   }
 printf("\n\n\n\n");
}
//printf("PLAYER 1\n");


for(;;)
{
    check1=check2=0;

printf("*******  %s  *********",play1);
for(;;)
{
    printf("\nselect coordinates of piece:\n");
    scanf("%d %d",&i,&j);
    if(i>0&&i<9&&j>0&&j<9&&board[i-1][j-1]!=0&&board[i-1][j-1]%2==0)
        break;
    else
        printf("Error coordinates!");
}




//Player 1 soldier

if(board[i-1][j-1]==2)
 {
     for(;;){
    printf("move to");
    scanf("%d %d",&a,&b);
    if(board[a-1][b-1]==0&&a==i+1&&b==j)
    {
        board[a-1][b-1]=2;
        board[i-1][j-1]=0;
        p=1;
        break;
    }
    if(board[a-1][b-1]!=0&&board[a-1][b-1]%2==1)
       {
            if((b==j+1||b==j-1)&&a==1+i)
         {
           board[a-1][b-1]=2;
           board[i-1][j-1]=0;
           p=1;
           break;

         }
       }
    if(p==0)
      {
          printf("Error\n");
        for(;;)
        {
         printf("select coordinates of piece:\n");
         scanf("%d %d",&i,&j);
         if(i>0&&i<9&&j>0&&j<9&&board[i-1][j-1]!=0&&board[i-1][j-1]%2==0)
        {
           break;
        }
          else
            {
                printf("Error coordinates!");

            }
        }
      }


     }


}


/* PLAYER 1 ELEPHANT  */
//t=0;
if(board[i-1][j-1]==4)
  {
      error:
      p=0;
      printf("Enter direction:(w,a,s,d)\n");
      scanf("%s",c);
      printf("Enter no. of steps:\n");
      scanf("%d",&steps);
      //printf("%%ythtjrsyjhdxjh%%%%%");
      //t=c;
      if((int)c[0]==119)
      {
          //printf("VERified");
          for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1-steps][j-1]%2==0&&board[i-1-steps][j-1]!=0)
                p=1;
          }
          //printf("*******%d",p);
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto error;
          }

          if(p==0)
          {
              board[i-1-steps][j-1]=4;
              board[i-1][j-1]=0;
          }



      }


      if((int)c[0]==115)
      {
          for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1+steps][j-1]%2==0&&board[i-1+steps][j-1]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto error;
          }

          if(p==0)
          {
              board[i-1+steps][j-1]=4;
              board[i-1][j-1]=0;
          }

      }

      if((int)c[0]==97)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1][j-1-m]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1][j-1-steps]%2==0&&board[i-1][j-1-steps]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto error;
          }

          if(p==0)
          {
              board[i-1][j-1-steps]=4;
              board[i-1][j-1]=0;
          }

      }

      if((int)c[0]==100)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1][j-1+m]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1][j-1+steps]%2==0&&board[i-1][j-1+steps]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto error;
          }

          if(p==0)
          {
              board[i-1][j-1+steps]=4;
              board[i-1][j-1]=0;
          }

      }

  }



  //PLAYER 1 HORSE
  if(board[i-1][j-1]==6)
  {
      incorrect:
      printf("move to:\n");
      scanf("%d %d",&a,&b);
      if((board[a-1][b-1]==0||board[a-1][b-1]%2==1)&&((a==(i-2)&&(b==j-1||b==j+1))||((a==i-1)&&((b==j-2)||(b==j+2)))||((a==i+1)&&((b==j-2)||b==j+2))||((a==i+2)&&(b==j+1)||(b==j-1))))

        {
            board[a-1][b-1]=6;
            board[i-1][j-1]=0;
        }
      else
      {
          printf("Error coordinates:\n");
          goto incorrect;
      }
  }

  //PLAYER 1 MINISTER
  if(board[i-1][j-1]==8)
  {   pulse:
      p=0;
      printf("Select direction:7  9\n\n");
      printf("                 1  3\n  ");
      scanf("%d",&t);
      printf("Enter no. of steps:");
      scanf("%d",&steps);
      if(t==7)
      {
          for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1-m]!=0||(board[i-1-steps][j-1-steps]!=0&&board[i-1-steps][j-1-steps]%2==0))
              {
                  p=1;
                  break;
              }
          }

          if(p==1)
          {
              printf("Error coordinates\n");
              goto pulse;
          }

          if(p==0)
          {
              board[i-1-steps][j-1-steps]=8;
              board[i-1][j-1]=0;
          }
      }

      if(t==9)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1+m]!=0||(board[i-1-steps][j-1+steps]!=0&&board[i-1-steps][j-1+steps]%2==0))
              {
                  p=1;
                  break;
              }
          }

          if(p==1)
          {
              printf("Error coordinates\n");
              goto pulse;
          }

          if(p==0)
          {
              board[i-1-steps][j-1+steps]=8;
              board[i-1][j-1]=0;
          }
      }

      if(t==1)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1-m]!=0||(board[i-1+steps][j-1-steps]!=0&&board[i-1+steps][j-1-steps]%2==0))
              {
                  p=1;
                  break;
              }
          }

          if(p==1)
          {
              printf("Error coordinates\n");
              goto pulse;
          }

          if(p==0)
          {
              board[i-1+steps][j-1-steps]=8;
              board[i-1][j-1]=0;

          }
      }

      if(t==3)
         {
           for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1+m]!=0||(board[i-1+steps][j-1+steps]!=0&&board[i-1+steps][j-1+steps]%2==0))
              {
                  p=1;
                  break;
              }
          }

          if(p==1)
          {
              printf("Error coordinates\n");
              goto pulse;
          }

          if(p==0)
          {
              board[i-1+steps][j-1+steps]=8;
              board[i-1][j-1]=0;

          }
      }



  }


  //PLAYER 1 QUEEN
  if(board[i-1][j-1]==10)
  {   fault:
      p=0;
      printf("Selct direction:\n");
      printf("                    7 8 9\n                    4   6\n                    1 2 3\n");
      scanf("%d",&t);
      printf("Enter no. of steps:");
      scanf("%d",&steps);
      if(t==7)
      {
          for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1-m]!=0)//||(board[i-1-steps][j-1-steps]!=0&&board[i-1-steps][j-1-steps]%2==0))
              {
                  p=1;
                  break;
              }
          }

          if((board[i-1-steps][j-1-steps]!=0&&board[i-1-steps][j-1-steps]%2==0))
            p=1;

          if(p==1)
          {
              printf("Error coordinates\n");
              goto fault;
          }

          if(p==0)
          {
              board[i-1-steps][j-1-steps]=10;
              board[i-1][j-1]=0;
          }
      }

      if(t==9)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1+m]!=0)//||(board[i-1-steps][j-1+steps]!=0&&board[i-1-steps][j-1+steps]%2==0))
              {
                  p=1;
                  break;
              }
          }

          if((board[i-1-steps][j-1+steps]!=0&&board[i-1-steps][j-1+steps]%2==0))
            p=1;

          if(p==1)
          {
              printf("Error coordinates\n");
              goto fault;
          }

          if(p==0)
          {
              board[i-1-steps][j-1+steps]=10;
              board[i-1][j-1]=0;
          }
      }

      if(t==1)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1-m]!=0)//||(board[i-1+steps][j-1-steps]!=0&&board[i-1+steps][j-1-steps]%2==0))
              {
                  p=1;
                  break;
              }
          }

          if((board[i-1+steps][j-1-steps]!=0&&board[i-1+steps][j-1-steps]%2==0))
            p=1;

          if(p==1)
          {
              printf("Error coordinates\n");
              goto fault;
          }

          if(p==0)
          {
              board[i-1+steps][j-1-steps]=10;
              board[i-1][j-1]=0;

          }
      }

      if(t==3)
         {
           for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1+m]!=0)//||(board[i-1+steps][j-1+steps]!=0&&board[i-1+steps][j-1+steps]%2==0))
              {
                  p=1;
                  break;
              }
          }

          if((board[i-1+steps][j-1+steps]!=0&&board[i-1+steps][j-1+steps]%2==0))
            p=1;

          if(p==1)
          {
              printf("Error coordinates\n");
              goto fault;
          }

          if(p==0)
          {
              board[i-1+steps][j-1+steps]=10;
              board[i-1][j-1]=0;

          }
      }


      if(t==8)
      {
          //printf("VERified");
          for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1-steps][j-1]%2==0&&board[i-1-steps][j-1]!=0)
                p=1;
          }
          //printf("*******%d",p);
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto fault;
          }

          if(p==0)
          {
              board[i-1-steps][j-1]=10;
              board[i-1][j-1]=0;
          }



      }


      if(t==2)
      {
          for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1+steps][j-1]%2==0&&board[i-1+steps][j-1]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto fault;
          }

          if(p==0)
          {
              board[i-1+steps][j-1]=10;
              board[i-1][j-1]=0;
          }

      }

      if(t==4)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1][j-1-m]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1][j-1-steps]%2==0&&board[i-1][j-1-steps]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto fault;
          }

          if(p==0)
          {
              board[i-1][j-1-steps]=10;
              board[i-1][j-1]=0;
          }

      }

      if(t==6)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1][j-1+m]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1][j-1+steps]%2==0&&board[i-1][j-1+steps]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto fault;
          }

          if(p==0)
          {
              board[i-1][j-1+steps]=10;
              board[i-1][j-1]=0;
          }

      }

  }

  //PLAYER 1 KING
  if(board[i-1][j-1]==12)
  {   cross:
      p=0;
      printf("Selct direction:\n");
      printf("                    7 8 9\n                    4   6\n                    1 2 3\n");
      scanf("%d",&t);
      steps=1;
      if(t==7)
      {

              if(board[i-1-m][j-1-m]!=0||(board[i-1-steps][j-1-steps]!=0&&board[i-1-steps][j-1-steps]%2==0))
              {
                  p=1;

              }


          if(p==1)
          {
              printf("Error coordinates\n");
              goto cross;
          }

          if(p==0)
          {
              board[i-1-steps][j-1-steps]=12;
              board[i-1][j-1]=0;
          }
      }

      if(t==9)
      {

              if(board[i-1-m][j-1+m]!=0||(board[i-1-steps][j-1+steps]!=0&&board[i-1-steps][j-1+steps]%2==0))
              {
                  p=1;

              }


          if(p==1)
          {
              printf("Error coordinates\n");
              goto cross;
          }

          if(p==0)
          {
              board[i-1-steps][j-1+steps]=12;
              board[i-1][j-1]=0;
          }
      }

      if(t==1)
      {

              if(board[i-1+m][j-1-m]!=0||(board[i-1+steps][j-1-steps]!=0&&board[i-1+steps][j-1-steps]%2==0))
              {
                  p=1;

              }


          if(p==1)
          {
              printf("Error coordinates\n");
              goto cross;
          }

          if(p==0)
          {
              board[i-1+steps][j-1-steps]=12;
              board[i-1][j-1]=0;

          }
      }

      if(t==3)
         {

              if(board[i-1+m][j-1+m]!=0||(board[i-1+steps][j-1+steps]!=0&&board[i-1+steps][j-1+steps]%2==0))
              {
                  p=1;

              }


          if(p==1)
          {
              printf("Error coordinates\n");
              goto cross;
          }

          if(p==0)
          {
              board[i-1+steps][j-1+steps]=12;
              board[i-1][j-1]=0;

          }
      }


      if(t==8)
      {
          //printf("VERified");

              if(board[i-1-m][j-1]!=0)
                {
                    p=1;

                }

              if(p==0&&board[i-1-steps][j-1]%2==0&&board[i-1-steps][j-1]!=0)
                p=1;
          //printf("*******%d",p);
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto cross;
          }

          if(p==0)
          {
              board[i-1-steps][j-1]=12;
              board[i-1][j-1]=0;
          }



      }


      if(t==2)
      {

              if(board[i-1+m][j-1]!=0)
                {
                    p=1;

                }


          if(p==0&&(board[i-1+steps][j-1]%2==0&&board[i-1+steps][j-1]!=0))
                p=1;
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto cross;
          }

          if(p==0)
          {
              board[i-1+steps][j-1]=12;
              board[i-1][j-1]=0;
          }

      }

      if(t==4)
      {

              if(board[i-1][j-1-m]!=0)
                {
                    p=1;

                }


          if(p==0&&board[i-1][j-1-steps]%2==0&&board[i-1][j-1-steps]!=0)
                p=1;
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto cross;
          }

          if(p==0)
          {
              board[i-1][j-1-steps]=12;
              board[i-1][j-1]=0;
          }

      }

      if(t==6)
      {

              if(board[i-1][j-1+m]!=0)
                {
                    p=1;

                }


          if(p==0&&board[i-1][j-1+steps]%2==0&&board[i-1][j-1+steps]!=0)
            p=1;
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto cross;
          }

          if(p==0)
          {
              board[i-1][j-1+steps]=12;
              board[i-1][j-1]=0;
          }

      }

  }



system("cls");
for(i=0;i<8;i++)
 {
  for(j=0;j<8;j++)
   {
       if(board[i][j]==0)
       {
           if((i%2==0&&j%2==0)||(i%2!=0&&j%2!=0))
            printf("   __  ");
           else
            printf("   ..  ");
       }
      else
        {

            print_piece(board[i][j]);
        }
   }
 printf("\n\n\n\n");
}


printf("********  %s  *********",play2);

for(;;)
{
    printf("\nselect coordinates of piece:\n");
    scanf("%d %d",&i,&j);
    if(i>0&&i<9&&j>0&&j<9&&board[i-1][j-1]!=0&&board[i-1][j-1]%2==1)
        break;
    else
        printf("Error coordinates!");
}




//Player 2 soldier

if(board[i-1][j-1]==3)
 {
     for(;;){
    printf("move to");
    scanf("%d %d",&a,&b);
    if(board[a-1][b-1]==0&&a==i-1&&b==j)
    {
        board[a-1][b-1]=3;
        board[i-1][j-1]=0;
        p=1;
        break;
    }
    if(board[a-1][b-1]!=0&&board[a-1][b-1]%2==0)
       {
            if((b==j+1||b==j-1)&&a==i-1)
         {
           board[a-1][b-1]=3;
           board[i-1][j-1]=0;
           p=1;
           break;

         }
       }
    if(p==0)
      {
          printf("Error\n");
        for(;;)
        {
         printf("select coordinates of piece:\n");
         scanf("%d %d",&i,&j);
         if(i>0&&i<9&&j>0&&j<9&&board[i-1][j-1]!=0&&board[i-1][j-1]%2==1)
        {
           break;
        }
          else
            {
                printf("Error coordinates!");

            }
        }
      }


     }


}


/* PLAYER 2
 ELEPHANT  */
//t=0;
if(board[i-1][j-1]==5)
  {
      error1:
      p=0;
      printf("Enter direction:(w,a,s,d)\n");
      scanf("%s",c);
      printf("Enter no. of steps:\n");
      scanf("%d",&steps);
      //printf("%%ythtjrsyjhdxjh%%%%%");
      //t=c;
      if((int)c[0]==119)
      {
          //printf("VERified");
          for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1-steps][j-1]%2==1&&board[i-1-steps][j-1]!=0)
                p=1;
          }
          //printf("*******%d",p);
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto error1;
          }

          if(p==0)
          {
              board[i-1-steps][j-1]=5;
              board[i-1][j-1]=0;
          }



      }


      if((int)c[0]==115)
      {
          for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1+steps][j-1]%2==1&&board[i-1+steps][j-1]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto error1;

          }

          if(p==0)
          {
              board[i-1+steps][j-1]=5;
              board[i-1][j-1]=0;
          }

      }

      if((int)c[0]==97)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1][j-1-m]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1][j-1-steps]%2==1&&board[i-1][j-1-steps]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto error1;
          }

          if(p==0)
          {
              board[i-1][j-1-steps]=5;
              board[i-1][j-1]=0;
          }

      }

      if((int)c[0]==100)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1][j-1+m]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1][j-1+steps]%2==1&&board[i-1][j-1+steps]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto error1;
          }

          if(p==0)
          {
              board[i-1][j-1+steps]=5;
              board[i-1][j-1]=0;
          }

      }

  }



  //PLAYER 2 HORSE
  if(board[i-1][j-1]==7)
  {
      incorrect1:
      printf("move to:\n");
      scanf("%d %d",&a,&b);
      if((board[a-1][b-1]==0||board[a-1][b-1]%2==0)&&((a==(i-2)&&(b==j-1||b==j+1))||((a==i-1)&&((b==j-2)||(b==j+2)))||((a==i+1)&&((b==j-2)||b==j+2))||((a==i+2)&&(b==j+1)||(b==j-1))))

        {
            board[a-1][b-1]=7;
            board[i-1][j-1]=0;
        }
      else
      {
          printf("Error coordinates:\n");
          goto incorrect1;
      }
  }

  //PLAYER 2 MINISTER
  if(board[i-1][j-1]==9)
  {   pulse1:
      p=0;
      printf("Select direction:7  9\n\n");
      printf("                 1  3\n  ");
      scanf("%d",&t);
      printf("Enter no. of steps:");
      scanf("%d",&steps);
      if(t==7)
      {
          for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1-m]!=0||(board[i-1-steps][j-1-steps]!=0&&board[i-1-steps][j-1-steps]%2==1))
              {
                  p=1;
                  break;
              }
          }

          if(p==1)
          {
              printf("Error coordinates\n");
              goto pulse1;
          }

          if(p==0)
          {
              board[i-1-steps][j-1-steps]=9;
              board[i-1][j-1]=0;
          }
      }

      if(t==9)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1+m]!=0||(board[i-1-steps][j-1+steps]!=0&&board[i-1-steps][j-1+steps]%2==1))
              {
                  p=1;
                  break;
              }
          }

          if(p==1)
          {
              printf("Error coordinates\n");
              goto pulse1;
          }

          if(p==0)
          {
              board[i-1-steps][j-1+steps]=9;
              board[i-1][j-1]=0;
          }
      }

      if(t==1)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1-m]!=0||(board[i-1+steps][j-1-steps]!=0&&board[i-1+steps][j-1-steps]%2==1))
              {
                  p=1;
                  break;
              }
          }

          if(p==1)
          {
              printf("Error coordinates\n");
              goto pulse1;
          }

          if(p==0)
          {
              board[i-1+steps][j-1-steps]=9;
              board[i-1][j-1]=0;

          }
      }

      if(t==3)
         {
           for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1+m]!=0||(board[i-1+steps][j-1+steps]!=0&&board[i-1+steps][j-1+steps]%2==1))
              {
                  p=1;
                  break;
              }
          }

          if(p==1)
          {
              printf("Error coordinates\n");
              goto pulse1;
          }

          if(p==0)
          {
              board[i-1+steps][j-1+steps]=9;
              board[i-1][j-1]=0;

          }
      }



  }


  //PLAYER 2 QUEEN
  if(board[i-1][j-1]==11)
  {   fault1:
      p=0;
      printf("Selct direction:\n");
      printf("                    7 8 9\n                    4   6\n                    1 2 3\n");
      scanf("%d",&t);
      printf("Enter no. of steps:");
      scanf("%d",&steps);
      if(t==7)
      {
          for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1-m]!=0)//'||(board[i-1-steps][j-1-steps]!=0&&board[i-1-steps][j-1-steps]%2==1))
              {
                  p=1;
                  break;
              }
          }

          if((board[i-1-steps][j-1-steps]!=0&&board[i-1-steps][j-1-steps]%2==1))
            p=1;

          if(p==1)
          {
              printf("Error coordinates\n");
              goto fault1;
          }

          if(p==0)
          {
              board[i-1-steps][j-1-steps]=11;
              board[i-1][j-1]=0;
          }
      }

      if(t==9)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1+m]!=0)//||(board[i-1-steps][j-1+steps]!=0&&board[i-1-steps][j-1+steps]%2==1))
              {
                  p=1;
                  break;
              }
          }

          if((board[i-1-steps][j-1+steps]!=0&&board[i-1-steps][j-1+steps]%2==1))
            p=1;

          if(p==1)
          {
              printf("Error coordinates\n");
              goto fault1;
          }

          if(p==0)
          {
              board[i-1-steps][j-1+steps]=11;
              board[i-1][j-1]=0;
          }
      }

      if(t==1)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1-m]!=0)//||(board[i-1+steps][j-1-steps]!=0&&board[i-1+steps][j-1-steps]%2==1))
              {
                  p=1;
                  break;
              }
          }

          if((board[i-1+steps][j-1-steps]!=0&&board[i-1+steps][j-1-steps]%2==1))
            p=1;

          if(p==1)
          {
              printf("Error coordinates\n");
              goto fault1;

          }

          if(p==0)
          {
              board[i-1+steps][j-1-steps]=11;
              board[i-1][j-1]=0;

          }
      }

      if(t==3)
         {
           for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1+m]!=0)//||(board[i-1+steps][j-1+steps]!=0&&board[i-1+steps][j-1+steps]%2==1))
              {
                  p=1;
                  break;
              }
          }

          if((board[i-1+steps][j-1+steps]!=0&&board[i-1+steps][j-1+steps]%2==1))
            p=1;

          if(p==1)
          {
              printf("Error coordinates\n");
              goto fault1;
          }

          if(p==0)
          {
              board[i-1+steps][j-1+steps]=11;
              board[i-1][j-1]=0;

          }
      }


      if(t==8)
      {
          //printf("VERified");
          for(m=1;m<steps;m++)
          {
              if(board[i-1-m][j-1]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1-steps][j-1]%2==1&&board[i-1-steps][j-1]!=0)
                p=1;
          }
          //printf("*******%d",p);
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto fault1;
          }

          if(p==0)
          {
              board[i-1-steps][j-1]=11;
              board[i-1][j-1]=0;
          }



      }


      if(t==2)
      {
          for(m=1;m<steps;m++)
          {
              if(board[i-1+m][j-1]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1+steps][j-1]%2==1&&board[i-1+steps][j-1]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto fault1;
          }

          if(p==0)
          {
              board[i-1+steps][j-1]=11;
              board[i-1][j-1]=0;
          }

      }

      if(t==4)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1][j-1-m]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1][j-1-steps]%2==1&&board[i-1][j-1-steps]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto fault1;
          }

          if(p==0)
          {
              board[i-1][j-1-steps]=11;
              board[i-1][j-1]=0;
          }

      }

      if(t==6)
      {
           for(m=1;m<steps;m++)
          {
              if(board[i-1][j-1+m]!=0)
                {
                    p=1;
                    break;
                }
              if(p==0&&board[i-1][j-1+steps]%2==1&&board[i-1][j-1+steps]!=0)
                p=1;
          }
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto fault1;
          }

          if(p==0)
          {
              board[i-1][j-1+steps]=11;
              board[i-1][j-1]=0;
          }

      }

  }

  //PLAYER 2 KING
  if(board[i-1][j-1]==13)
  {   cross1:
      p=0;
      printf("Selct direction:\n");
      printf("                    7 8 9\n                    4   6\n                    1 2 3\n");
      scanf("%d",&t);
      steps=1;
      if(t==7)
      {

              if(board[i-1-m][j-1-m]!=0||(board[i-1-steps][j-1-steps]!=0&&board[i-1-steps][j-1-steps]%2==1))
              {
                  p=1;

              }


          if(p==1)
          {
              printf("Error coordinates\n");
              goto cross1;
          }

          if(p==0)
          {
              board[i-1-steps][j-1-steps]=13;
              board[i-1][j-1]=0;
          }
      }

      if(t==9)
      {

              if(board[i-1-m][j-1+m]!=0||(board[i-1-steps][j-1+steps]!=0&&board[i-1-steps][j-1+steps]%2==1))
              {
                  p=1;

              }


          if(p==1)
          {
              printf("Error coordinates\n");
              goto cross1;

          }

          if(p==0)
          {
              board[i-1-steps][j-1+steps]=13;
              board[i-1][j-1]=0;
          }
      }

      if(t==1)
      {

              if(board[i-1+m][j-1-m]!=0||(board[i-1+steps][j-1-steps]!=0&&board[i-1+steps][j-1-steps]%2==1))
              {
                  p=1;

              }


          if(p==1)
          {
              printf("Error coordinates\n");
              goto cross1;
          }

          if(p==0)
          {
              board[i-1+steps][j-1-steps]=13;
              board[i-1][j-1]=0;

          }
      }

      if(t==3)
         {

              if(board[i-1+m][j-1+m]!=0||(board[i-1+steps][j-1+steps]!=0&&board[i-1+steps][j-1+steps]%2==1))
              {
                  p=1;

              }


          if(p==1)
          {
              printf("Error coordinates\n");
              goto cross1;
          }

          if(p==0)
          {
              board[i-1+steps][j-1+steps]=13;
              board[i-1][j-1]=0;

          }
      }


      if(t==8)
      {
          //printf("VERified");

              if(board[i-1-m][j-1]!=0)
                {
                    p=1;

                }
              if(p==0&&board[i-1-steps][j-1]%2==1&&board[i-1-steps][j-1]!=0)
                p=1;

          //printf("*******%d",p);
          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto cross1;
          }

          if(p==0)
          {
              board[i-1-steps][j-1]=13;
              board[i-1][j-1]=0;
          }



      }


      if(t==2)
      {

              if(board[i-1+m][j-1]!=0)
                {
                    p=1;

                }
              if(p==0&&board[i-1+steps][j-1]%2==1&&board[i-1+steps][j-1]!=0)
                p=1;

          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto cross1;
          }

          if(p==0)
          {
              board[i-1+steps][j-1]=13;
              board[i-1][j-1]=0;
          }

      }

      if(t==4)
      {

              if(board[i-1][j-1-m]!=0)
                {
                    p=1;

                }
              if(p==0&&board[i-1][j-1-steps]%2==1&&board[i-1][j-1-steps]!=0)
                p=1;

          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto cross1;
          }

          if(p==0)
          {
              board[i-1][j-1-steps]=13;
              board[i-1][j-1]=0;
          }

      }

      if(t==6)
      {

              if(board[i-1][j-1+m]!=0)
                {
                    p=1;

                }
              if(p==0&&board[i-1][j-1+steps]%2==1&&board[i-1][j-1+steps]!=0)
                p=1;

          if(p==1)
          {
              printf("Error selection\n");
              p=0;
              goto cross1;
          }

          if(p==0)
          {
              board[i-1][j-1+steps]=13;
              board[i-1][j-1]=0;
          }

      }

  }



system("cls");
for(i=0;i<8;i++)
 {
  for(j=0;j<8;j++)
   {
       if(board[i][j]==0)
       {
           if((i%2==0&&j%2==0)||(i%2!=0&&j%2!=0))
            printf("   __  ");
           else
            printf("   ..  ");
       }
      else
        {

            print_piece(board[i][j]);
        }
   }
 printf("\n\n\n\n");
}



//win lose condition
for(m=0;m<8;m++)
{
    for(n=0;n<8;n++)
    {
        if(board[i][j]==12)
            check1=1;
        if(board[i][j]==13)
            check2=1;
    }
}

if(check1==0)
  {
    printf("\nWinner:%s",play2);
    break;
  }
if(check2==0)
  {
    printf("\nWinner:%s",play1);
    break;
  }

}
}

else
    printf("Incorrect password\n");
}
/****************************/
/****************************/
/****************************/

void print_piece(int t)
{
            if(t==2)
            printf("   S   ");
            if(t==3)
            printf("  *S*  ");
            if(t==4)
            printf("   E   ");
            if(t==5)
            printf("  *E*  ");
            if(t==6)
            printf("   H   ");
            if(t==7)
            printf("  *H*  ");
            if(t==8)
            printf("   M   ");
            if(t==9)
            printf("  *M*  ");
            if(t==10)
            printf("   Q   ");
            if(t==11)
            printf("  *Q*  ");
            if(t==12)
            printf("   K   ");
            if(t==13)
            printf("  *K*  ");

}



