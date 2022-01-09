#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include "grid.h"         //Calling all functions
#include "mainMenu.h"
#include "print.h"
#include "Scorefun.h"
#include "SaveFun.h"
#include "GamePlay.h"
#include "Undo.h"
#include "Redo.h"
#include "moveshist.h"
#include "AI.h"
#include "topPlayers.h"
#include "ResetVariables.h"
#include "DebugGrid.h"
int main()
{
    start:
    mainMenu();
    time_t t1;
    system(" ");
    system("cls");
    // we get size1 from main menu by using x.
    int arr1[size1][size1];
    if(l1==0){     // A variable that checks if a game is loaded.
    grid(size1,arr1);
    totalmoves= 2*x*(x+1);
    system("cls");
    }
    if(l1==1){
        for(int i=0 ; i<size1 ;i++){
            for(int j=0; j<size1 ; j++){
                arr1[i][j]=arr2[i][j];
            }
        }
    }
    t1=time(0);
    if(v!=1){
        goto there2 ;
    }
    moveshist(moves1 ,moves2 ,totalmoves ,size1 ,arr1, U );
    there :
    while(moves<totalmoves){
        v=1 ;
        moveshist(moves1 ,moves2 ,totalmoves ,size1 ,arr1, U );
        GamePlay(playerNumber,size1,arr1,totalmoves,U,t1);
        if(v !=1){
            moves++ ;
            moves2++;
            MovesAfterLoad++;
            moveshist(moves1,moves2,totalmoves ,size1 ,arr1, U );
            system("cls");
            goto jump3;
        }
        system("cls");
        moves++;
        moves1++;
        MovesAfterLoad++;
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
            moveshist(moves1 ,moves2 ,totalmoves ,size1 ,arr1, U );
            GamePlay(playerNumber,size1,arr1,totalmoves,U ,t1);
            if(v !=2 && v!=0){
                moves++ ;
                moves1++;
                MovesAfterLoad++;
                moveshist(moves1,moves2,totalmoves ,size1 ,arr1,  U);
                system("cls");
                goto jump4;
            }
        there4:
        system("cls");
        moves++;
        moves2++;
        MovesAfterLoad++;
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
    printf(ANSI_COLOR_BLUE "\n\n       Player ONE Score : %d "ANSI_COLOR_RESET ,score1) ;
    printf(ANSI_COLOR_RED "      \t\t\t\t\t\t Player TWO Score : %d\n"ANSI_COLOR_RESET ,score2) ;
    p1.score = score1;
    if(playerNumber == 2){
        p2.score = score2;
    }
    if(p1.score>score2){
        printf(ANSI_COLOR_BLUE"%\t\t\t\t\t\t%s is the WINNER!!"ANSI_COLOR_RESET,p1.name);
    }else if(p1.score == score2){
        printf(ANSI_COLOR_GREEN"\n      \t\t\t\t\t\t      DRAW"ANSI_COLOR_RESET);
    }else if(score2>p1.score && playerNumber==2){
        printf(ANSI_COLOR_RED"\t\t\t\t\t\t%s is the WINNER!!"ANSI_COLOR_RESET,p2.name);
    }else if(score2>p1.score && playerNumber==1){
        printf(ANSI_COLOR_RED"\n      \t\t\t\t\t\tGAME OVER !!"ANSI_COLOR_RESET);
    }
    topPlayers();
    ////
    printf("\n\t\t\t\t\t\t ***Top Ten Players***\n\n");
    for(int i=0 ; i<10 ; i++){
        printf("\t\t\t\t\t\t      %d- %s: %d\n",i+1,top10[i].name,top10[i].score);
    }
    ////

    printf("\nEnter 1 to return to main menu or press any key to Exit: ");
    scanf("%d",&ReturnMainMenu);
    if(ReturnMainMenu==1){
        system("cls");
        ResetVariables();
        goto start ;
    }
    return 0;
}
