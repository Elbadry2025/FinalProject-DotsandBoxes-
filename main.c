#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[97m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define MAXSIZE 22
int v =1; // represent which player is playing
int moves=0;
int moves1 =0;
int moves2 =0;
int score1=0;
int score2=0;
int counter=0;
int counter1=0;
time_t t2;
typedef struct{
    int WhichPlayer ;
    int arr[MAXSIZE][MAXSIZE];
    int move;
    int move1;
    int move2;
    int scoreplayer1;
    int scoreplayer2;
    }History;
History playes ;
//Calling all functions
#include "grid.h"
#include "mainMenu.h"
#include "print.h"
#include "Scorefun.h"
#include "GamePlay.h"
#include "Undo.h"
#include "Redo.h"
#include "moveshist.h"
#include "AI.h"

typedef struct{
    int playerscore ;
}playerInfo;

int main()
{
    mainMenu();
    time_t t1;
    system(" ");
    int x;
    int playerNumber ;
    scanf("%d" , &playerNumber);
    system("cls");
    while(playerNumber != 1 && playerNumber != 2){
        printf("Enter 1 or 2 please : ");
        scanf("%d" , &playerNumber);
    }
    printf(ANSI_COLOR_YELLOW"Enter (N) The size of The Grid which is NxN boxes : "ANSI_COLOR_RESET);
    scanf("%d",&x);
    int size1= x*2+2 ;
    int arr1[size1][size1];
    grid(size1,arr1);
    int totalmoves= 2*x*(x+1);
    system("cls");
    History U[totalmoves+1];
    t1=time(0);
    there :
    while(moves<totalmoves){
        v=1 ;
        moveshist(moves1 ,moves2 ,totalmoves ,size1 ,arr1, U );
        GamePlay(playerNumber,size1,arr1,totalmoves,U,t1);
        if(v !=1){
            moves++ ;
            moves2++;
            moveshist(moves1,moves2,totalmoves ,size1 ,arr1, U );
            system("cls");
            goto jump3;
        }
        system("cls");
        moves++;
        moves1++;
        jump4:
        playes.move = moves ;
        playes.move1 = moves1 ;
        if(moves>totalmoves){break ;}
        int tempScore1 = Scorefun(v,size1,arr1);
        for(int i=0 ;i<size1; i++){
            for(int j=0 ; j<size1 ; j++){
                playes.arr[i][j] = arr1[i][j];
            }
        }
        score1 += tempScore1 ;
        playes.scoreplayer1 = score1;
        playes.scoreplayer2 = score2;
        if(tempScore1){
            goto there;
        }
        // Player Two
        there2 :
        if(playerNumber==2){
            v=2 ;
        }else{
            v=0 ;
        }
        if(moves<totalmoves){
            playes.WhichPlayer = v ;
            U[moves]= playes ;
            GamePlay(playerNumber,size1,arr1,totalmoves,U ,t1);
            if(v !=2 && v!=0){
                moves++ ;
                moves1++;
                moveshist(moves1,moves2,totalmoves ,size1 ,arr1,  U);
                system("cls");
                goto jump4;
            }
        there4:
        system("cls");
        moves++;
        moves2++;
        jump3:
        playes.move = moves ;
        playes.move2 = moves2 ;
        int tempScore2 = Scorefun(v,size1, arr1);
        for(int i=0 ;i<size1; i++){
            for(int j=0 ; j<size1 ; j++){
                playes.arr[i][j] = arr1[i][j] ;
            }
        }
        score2 += tempScore2 ;
        playes.scoreplayer1 = score1;
        playes.scoreplayer2 = score2;
        U[moves]=playes ;
        if(tempScore2){
             goto there2 ;
        }
        }else{
            break ;
        }
    }

    print(size1,arr1);
    printf(ANSI_COLOR_BLUE "  Player ONE Score : %d "ANSI_COLOR_RESET ,score1) ;
    printf(ANSI_COLOR_RED "      \t\t\t\t\t\t Player TWO Score : %d\n"ANSI_COLOR_RESET ,score2) ;
    return 0;
}
