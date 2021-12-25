#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[97m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void print(int size1,int arr1[][size1]){
    for(int j=1 ;j<size1 ;j++){
        printf(" %d",arr1[0][j]);
    }
    printf("\n");
    for(int i=1 ; i<size1 ; i++){
        printf("%d",i);
        for(int j=1; j<size1 ;j++){
            if( arr1[i][j]==254){
               printf( ANSI_COLOR_WHITE   "%c " ANSI_COLOR_RESET ,arr1[i][j] );
            }else if(arr1[i][j]==178){
               printf( ANSI_COLOR_BLUE   "%c " ANSI_COLOR_RESET ,arr1[i][j] );
            }else if(arr1[i][j]==177){
               printf( ANSI_COLOR_RED   "%c " ANSI_COLOR_RESET ,arr1[i][j] );
            }else{
                if(arr1[i][j]==205 || arr1[i][j]==186){
                    printf(ANSI_COLOR_RED "%c "ANSI_COLOR_RESET ,arr1[i][j]);
                } else {
                    printf(ANSI_COLOR_BLUE "%c "ANSI_COLOR_RESET ,arr1[i][j]);
                }

            }
        }
        printf("\n");
    }

}
int Scorefun(int player,int s ,int arr[][s] ){
    int score = 0;
    for(int i = 1; i<s; i+=2){
        for(int j =2 ; j<s ; j+=2){
            if(arr[i][j]!= ' ' &&arr[i+2][j]!= ' '){
                if(arr[i+1][j-1]!= ' ' && arr[i+1][j+1]!= ' '){
                    if(arr[i+1][j] != 178 && arr[i+1][j] != 177 ){
                        if(player==1){
                           arr[i+1][j] = 178;
                        }else{
                           arr[i+1][j] = 177;
                        }
                        score++;
                    }
                }
            }
        }
    }
    return score;
}

int main()
{
    int x;
    int v ;    // represent which player is playing
    printf("Enter N The size1 of The Grid which is nxn: ");
    scanf("%d",&x);
    int size1= x*2+2 ;
    int arr1[size1][size1];
    grid(size1,arr1);
    int score1 =0 ; int score2 =0;
    int moves=0;
    int totalmoves= 2*x*(x+1);
    system("cls");
    there :
    while(moves<totalmoves){
        v=1 ;
        int y,z;
        there3 :
        print(size1,arr1);
        printf(ANSI_COLOR_BLUE "\n\n\n\n\t\t\tPlayer One"ANSI_COLOR_RESET);
        printf("\n\t\t\tTotal Number of Moves: %d\n \t\t\tCurrent Score Player one : %d\n \t\t\tCurrent Score Player two : %d\n",moves,score1,score2);
        printf("Enter row : ");
        scanf("%d",&y);
        printf("Enter column : ");
        scanf("%d",&z);
        if(y==z || (y%2==0)&&(z%2==0)|| (y%2==1)&&(z%2==1)||y==0||z==0 || arr1[y][z]!=' '){
                system("cls");
                printf("Invalid Move Please Try Again\n\n");
                goto there3;
        }else{
            if(z%2==0){  // for horizontal move
                arr1[y][z]=196 ;
            }else{
                arr1[y][z]=179; // for vertical move
            }
            system("cls");
            moves++;if(moves>totalmoves){break ;}
        }
        int tempScore1 = Scorefun(v,size1,arr1);
        score1 += tempScore1 ;
        if(tempScore1){
          goto there;
        }
        // Player Two

        there2 :
        v=2 ;
        if(moves<totalmoves){
        int flag2 = 0;
        int y,z ;
        there4:
        print(size1,arr1);
        printf(ANSI_COLOR_RED"\n\n\n\n\t\t\tPlayer Two"ANSI_COLOR_RESET);
        printf("\n\t\t\tTotal Number of Moves: %d\n \t\t\tCurrent Score Player one : %d\n \t\t\tCurrent Score Player two : %d\n",moves,score1,score2);
        printf("Enter row : ");
        scanf("%d",&y);
        printf("Enter column : ");
        scanf("%d",&z);
        if(y==z || (y%2==0)&&(z%2==0)|| (y%2==1)&&(z%2==1)||y==0||z==0 || arr1[y][z]!=' '){
                system("cls");
                printf("Invalid Move Please Try Again\n\n");
                goto there4 ;

        }else{
            printf(ANSI_COLOR_RED"\n\n\n\n\t\t\tPlayer Two"ANSI_COLOR_RESET);
            if(z%2==0){  // for horizontal move
                arr1[y][z]=205 ;
            }else{
                arr1[y][z]=186; // for vertical move
            }
            system("cls");
            moves++;
        }
        int tempScore2 = Scorefun(v,size1, arr1);
        score2 += tempScore2 ;
        if(tempScore2){
             goto there2 ;
        }

        }else {break ; }


    }
    print(size1,arr1);printf("  Player ONE Score : %d \t\t\t Player TWO Score : %d\n",score1,score2) ;


    return 0;
}
