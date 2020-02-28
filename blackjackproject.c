#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <process.h>
#define spade 06                 //Used to print spade symbol
#define club 05                  //Used to print club symbol
#define diamond 04               //Used to print diamond symbol
#define heart 03                 //Used to print heart symbol
int k;
int l;
int d;
int n;
int b[14][15]={0};
int random_card;
int dealer_total;
int clubcard();      //Displays Club Card Image
int diamondcard();   //Displays Diamond Card Image
int heartcard();     //Displays Heart Card Image
int spadecard();     //Displays Spade Card Image
int randcard();      //Generates random card
int betting(int);       //Asks user amount to bet
void rules();//Prints "Rules of Vlad's Blackjack" menu
void score(int a[],int n,int m);
int main()
{
    int n;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n              222                111                            ");
    printf("\n            222 222            11111                              ");
    printf("\n           222   222          11 111                            ");
    printf("\n                222              111                               ");
    printf("\n               222               111                           ");
    printf("\n");
    printf("\n%c%c%c%c%c     %c%c            %c%c         %c%c%c%c%c    %c    %c                ", club, club, club, club, club, spade, spade, diamond, diamond, heart,heart, heart, heart, heart, club, club);
    printf("\n%c    %c    %c%c           %c  %c       %c     %c   %c   %c              ", club, club, spade, spade, diamond, diamond, heart, heart, club, club);

    printf("\n%c    %c    %c%c          %c    %c     %c          %c  %c               ", club, club, spade, spade, diamond, diamond, heart, club, club);

    printf("\n%c%c%c%c%c     %c%c          %c %c%c %c     %c          %c %c              ", club, club, club, club, club, spade, spade, diamond, diamond, diamond,diamond, heart, club, club);
    printf("\n%c    %c    %c%c         %c %c%c%c%c %c    %c          %c%c %c             ", club, club, spade, spade, diamond, diamond, diamond, diamond, diamond,diamond, heart, club, club, club);
    printf("\n%c     %c   %c%c         %c      %c    %c          %c   %c               ", club, club, spade, spade, diamond, diamond, heart, club, club);

    printf("\n%c     %c   %c%c        %c        %c    %c     %c   %c    %c             ", club, club, spade, spade, diamond, diamond, heart, heart, club, club);

    printf("\n%c%c%c%c%c%c    %c%c%c%c%c%c%c   %c        %c     %c%c%c%c%c    %c     %c            ", club, club, club, club, club, club, spade, spade, spade, spade, spade, spade, spade, diamond, diamond, heart, heart, heart, heart, heart, club, club);
    printf("\n");
    printf("\n                        21                                   ");

    printf("\n     %c%c%c%c%c%c%c%c      %c%c         %c%c%c%c%c    %c    %c                ", diamond, diamond, diamond, diamond, diamond, diamond, diamond, diamond,heart, heart, club, club, club, club, club, spade, spade);
    printf("\n        %c%c        %c  %c       %c     %c   %c   %c              ", diamond, diamond, heart, heart, club, club, spade, spade);

    printf("\n        %c%c       %c    %c     %c          %c  %c               ", diamond, diamond, heart, heart, club, spade, spade);

    printf("\n        %c%c       %c %c%c %c     %c          %c %c              ", diamond, diamond, heart, heart, heart, heart, club, spade, spade);

    printf("\n        %c%c      %c %c%c%c%c %c    %c          %c%c %c             ", diamond, diamond, heart, heart, heart, heart, heart, heart, club, spade, spade, spade);
    printf("\n        %c%c      %c      %c    %c          %c   %c               ", diamond, diamond, heart, heart, club, spade, spade);

    printf("\n     %c  %c%c     %c        %c    %c     %c   %c    %c             ", diamond, diamond, diamond, heart, heart, club, spade, spade);

    printf("\n      %c%c%c      %c        %c     %c%c%c%c%c    %c     %c            ", diamond, diamond, diamond, heart, heart, club, club, club, club, club, spade, spade);
    printf("\n");
    printf("\n         222                     111                         ");
    printf("\n        222                      111                         ");
    printf("\n       222                       111                         ");
    printf("\n      222222222222222      111111111111111                       ");
    printf("\n      2222222222222222    11111111111111111                         ");
    printf("\n");
    printf("\n");
    printf("\nRULES OF BLACKJACK GAME\n");
    rules();
    printf("enter how many players want to play the game");
    scanf("%d",&n);
    int sum=betting(n);
    printf("IT IS DEALERS TURN");
    dealer_total=randcard();
    if(dealer_total>21)
	    dealer_total=0;
    int a[n];
    for(int i=0;i<n;i++)
    {
            printf("IT IS %d PLAYER TURN_______",i+1);
            a[i]=randcard();
    }
    for(int i=0;i<n;i++)
    {
            printf("score of player  %d  is %d\n",i+1,a[i]);
    }
    printf("score of dealer is %d\n",dealer_total);
    score(a,n,sum);
    
    return 0;
 }

void rules() //Prints "Rules of Vlad's Blackjack" list
{
     printf("\n           RULES of VLAD's BLACKJACK");
     printf("\n          ---------------------------");
     printf("\nI.");
     printf("\n     Thou shalt not question the odds of this game.");
     printf("\n      %c This program generates cards at random.", spade);
     printf("\n      %c If you keep losing, you are very unlucky!\n", diamond);

     printf("\nII.");
     printf("\n     Each card has a value.");
     printf("\n      %c Number cards 1 to 10 hold a value of their number.", spade);
     printf("\n      %c J, Q, and K cards hold a value of 10.", diamond);
     printf("\n      %c Ace cards hold a value of 11", club);
     printf("\n     The goal of this game is to reach a card value total of 21.\n");

     printf("\nIII.");
     printf("\n     After the dealing of the first two cards, YOU must decide whether to HIT or STAY.");
     printf("\n      %c Staying will keep you safe, hitting will add a card.", spade);
     printf("\n     Because you are competing against the dealer, you must beat his hand.");
          printf("\n     After the dealing of the first two cards, YOU must decide whether to HIT or STAY.");
     printf("\n      %c Staying will keep you safe, hitting will add a card.", spade);
     printf("\n     Because you are competing against the dealer, you must beat his hand.");
     printf("\n     BUT BEWARE!.");
     printf("\n      %c If your total goes over 21, you will LOSE!.", diamond);
     printf("\n     But the world is not over, because you can always play again.\n");
     printf("\n%c%c%c YOUR RESULTS ARE RECORDED AND FOUND IN SAME FOLDER AS PROGRAM %c%c%c\n", spade, heart, club, club, heart, spade);
}

int randcard() //Generates random card
{
        int sum,ch;char choice1;
        srand((unsigned) time(NULL)); //Generates random seed for rand() function
        int p;
        do{

     do{
              ch=0;
             random_card = ((rand()%4)+1);
             l=((rand()%13)+1);
             if(b[l][random_card]==0)
             {
                     b[l][random_card]=1;
                     ch=1;
             }
     }while(!ch);
     if(l==1)
     {
             if(sum<=10)
                     l=11;
             else
                     l=1;
     }
     if(random_card==1)
     {
         sum+=clubcard(l);

     }

     if(random_card==2)
     {
        sum+= diamondcard(l);

     }

     if(random_card==3)
     {
        sum+= heartcard(l);

     }

     if(random_card==4)
     {
         sum+=spadecard(l);

     }
     printf("players total=%d",sum);
     if(sum>21)
     {
             printf("you have lost");
             choice1='s';
     }
     else
     {
     printf("enter s to stay or h to hit");
     scanf(" %c",&choice1);

     if((choice1!='s') && (choice1!='S') && (choice1!='H') && (choice1!='h')) // If invalid choice entered
    {
        printf("\n");
        printf("Incorrect Choice. Please Enter h for hit or s for stay\n");
        scanf(" %c",&choice1);
    }}
        }while(choice1=='h' || choice1=='H');
        return sum;
} // End Function
int clubcard(int k) //Displays Club Card Image
{

    if(k<=10 && k!=1) //If random number is 9 or less, print card with that number
    {
    //Club Card
    printf("-------\n");
    printf("|%c    |\n", club);
    printf("|  %d  |\n", k);
    printf("|    %c|\n", club);
    printf("-------\n");
    }
     if(k==1) //If random number is 11, print card with A (Ace) on face
    {
    //Club Card
    printf("-------\n");
    printf("|%c    |\n", club);
    printf("|  A  |\n");
    printf("|    %c|\n", club);
    printf("-------\n");

    }


    if(k==11) //If random number is 11, print card with j on face
    {
    //Club Card
    printf("-------\n");
    printf("|%c    |\n", club);
    printf("|  J  |\n");
    printf("|    %c|\n", club);
    printf("-------\n");
    k=10; //Set card value to 10
    }


    if(k==13) //If random number is 13, print card with K (King) on face
    {
    //Club Card
    printf("-------\n");
    printf("|%c    |\n", club);
    printf("|  K  |\n");
    printf("|    %c|\n", club);
    printf("-------\n");
    k=10;
    }


    if(k==12) //If random number is 12, print card with Q (Queen) on face
    {
    //Club Card
    printf("-------\n");
    printf("|%c    |\n", club);
    printf("|  Q  |\n");
    printf("|    %c|\n", club);
    printf("-------\n");
    k=10; //Set card value to 10
    }
    return k;
}// End function
int diamondcard(int k) //Displays Diamond Card Image
{
     if(k<=10 && k!=1) //If random number is 9 or less, print card with that number
    {
    //Diamond Card
    printf("-------\n");
    printf("|%c    |\n", diamond);
    printf("|  %d  |\n", k);
    printf("|    %c|\n", diamond);
    printf("-------\n");
    }

    if(k==11) //If random number is 11, print card with J (Jack) on face
    {
    //Diamond Card
    printf("-------\n");
    printf("|%c    |\n", diamond);
    printf("|  J  |\n");
    printf("|    %c|\n",diamond);
    printf("_______\n");
    k=10;
     }

    if(k==1) //If random number is 11, print card with A (Ace) on face
    {
    //Diamond Card
    printf("-------\n");
    printf("|%c    |\n", diamond);
    printf("|  A  |\n");
    printf("|    %c|\n", diamond);
    printf("-------\n");

    }

    if(k==12) //If random number is 12, print card with Q (Queen) on face
    {
    //Diamond Card
    printf("-------\n");
    printf("|%c    |\n", diamond);
    printf("|  Q  |\n");
    printf("|    %c|\n", diamond);
    printf("-------\n");
    k=10; //Set card value to 10
    }

    if(k==13) //If random number is 13, print card with K (King) on face
    {
    //Diamond Card
    printf("-------\n");
    printf("|%c    |\n", diamond);
    printf("|  K  |\n");
    printf("|    %c|\n", diamond);
    printf("-------\n");
    k=10; //Set card value to 10
    }
    return k;
}// End function
int heartcard(int k) //Displays Heart Card
{

    if(k<=10 && k!=1) //If random number is 10 or less, print card with that number
    {
    //Heart Card
    printf("-------\n");
    printf("|%c    |\n", heart);
    printf("|  %d  |\n", k);
    printf("|    %c|\n", heart);
    printf("-------\n");
    }

    if(k==11) //If random number is 11, print card with J (Jack) on face
    {
    //Heart Card
    printf("-------\n");
    printf("|%c    |\n", heart);
    printf("|  J  |\n");
    printf("|    %c|\n", heart);
    printf("-------\n");k=10;
    }

    if(k==1) //If random number is 1, print card with A (Ace) on face
    {
    //Heart Card
        //Heart Card
    printf("-------\n");
    printf("|%c    |\n", heart);
    printf("|  J  |\n");
    printf("|    %c|\n", heart);
    printf("-------\n");k=10;
    }

    if(k==1) //If random number is 1, print card with A (Ace) on face
    {
    //Heart Card
    printf("-------\n");
    printf("|%c    |\n", heart);
    printf("|  A  |\n");
    printf("|    %c|\n", heart);
    printf("-------\n");
    }

    if(k==12) //If random number is 12, print card with Q (Queen) on face
    {
    //Heart Card
    printf("-------\n");
    printf("|%c    |\n", heart);
    printf("|  Q  |\n");
    printf("|    %c|\n", heart);
    printf("-------\n");
    k=10; //Set card value to 10
    }

    if(k==13) //If random number is 13, print card with K (King) on face
    {
    //Heart Card
    printf("-------\n");
    printf("|%c    |\n", heart);
    printf("|  K  |\n");
    printf("|    %c|\n", heart);
    printf("-------\n");
    k=10; //Set card value to 10
    }
    return k;
}
int spadecard(int k) //Displays Spade Card
{
    if(k<=10 && k!=1) //If random number is 10 or less, print card with that number
    {
    //Spade Card
    printf("-------\n");
    printf("|%c    |\n", spade);
    printf("|  %d  |\n", k);
    printf("|    %c|\n", spade);
    printf("-------\n");
    }

    if(k==11) //If random number is 11, print card with J (Jack) on face
    {
    //Spade Card
    printf("-------\n");
    printf("|%c    |\n", spade);
    printf("|  J  |\n");
    printf("|    %c|\n", spade);
    printf("-------\n");k=10;
    }

    if(k==1) //If random number is 1, print card with A (Ace) on face
    {
    //Spade Card
    printf("-------\n");
    printf("|%c    |\n", spade);
    printf("|  A  |\n");
    printf("|    %c|\n", spade);
    printf("-------\n");
    }

    if(k==12) //If random number is 12, print card with Q (Queen) on face
    {
    //Spade Card
    printf("-------\n");
    printf("|%c    |\n", spade);
    printf("|  Q  |\n");
    printf("|    %c|\n", spade);
    printf("-------\n");
    k=10; //Set card value to 10
    }

    if(k==13) //If random number is 13, print card with K (King) on face
    {
    //Spade Card
    printf("-------\n");
    printf("|%c    |\n", spade);
    printf("|  K  |\n");
    printf("|    %c|\n", spade);
    printf("-------\n");
    k=10; //Set card value to 10
    }
    return k;
} // End Function
int betting(int n)
{
	int i,sum=0;
	char ch;int cash[n];int bet[n];
	for(i=0;i<n;i++)
	{
		cash[i]=500;
	}
	i=0;
	while(i<n)
	{
		printf("\nplayer %d choice\n",i+1);
		printf("enter y to bet or n to no");
		scanf(" %c",&ch);
		 if((ch!='y') && (ch!='Y') && (ch!='n') && (ch!='N')) // If invalid choice entered
                  {
                          printf("\n");
                          printf("Incorrect Choice. Please Enter y for yes or n for no\n");
                           scanf(" %c",&ch);
		  }
		 if(ch=='Y'|| ch=='y')
		 {
			 printf("\nenter how much you want to bet\n");
			 scanf("%d",&bet[i]);
			 if(bet[i]>500)
			 {
				 printf("SOORY----- you can only afford upto 500\n enter other amount");
				 scanf("%d",&bet[i]);
		 }
		 }
		 else
		 {
			 bet[i]=0;
		 }
		
	
		 sum=sum+bet[i];i=i+1;
	}
return sum;
}
void score(int a[],int n,int sum)
{
	int i=0,c=-1,c1=-1;
	if(dealer_total==21)
		printf("\nAll players have lost AND dealer won %d amount in betting\n",sum);

	else
	{
	for(i=0;i<n;i++)
	{
		if(a[i]>21)
		{
			a[i]=0;

		}
		if(a[i]==21)
			c1=i;
	}

	if(c1!=-1)
	{
		printf("player %d is winner and won %d amount in betting",c1+1);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>dealer_total)
		{
			c=i;
		}
	}
	if(c!=-1)
	{
		printf(" player %d is winner and won %d amount in betting",c+1);
	}
	else
	{
		printf("DEALER WON THE  GAME AND WON %d AMOUNT IN BETTING",sum);
	}
	}
}






