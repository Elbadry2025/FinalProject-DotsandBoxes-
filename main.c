#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include "grid.h"
#include "mainMenu.h"
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

/*void mainMenu(){
    int choice;
    int chooseFile;
    printf("\t\t\t\t\t  **Welcome to Dots and Boxes**\n\t\t\t\t\t\tproject made by\n\t\t\t\t\tELbadry Elbadry & Mohamed Hassan");
    printf("\n\n%cNew game(enter 1)\n\n%cLoad game(enter 2)\n\n%cTop 10 players(enter 3)\n\n%cExit(enter 4)\n\n%cEnter your choice: ",16,16,16,16,16);
    scanf("%d" ,&choice);
    switch(choice){
        case 1:
            system("cls");
            printf(ANSI_COLOR_YELLOW "For 1 player mode enter (1)\n\nFor 2 player mode enter (2)\n"ANSI_COLOR_RESET );
            break;
        case 2:
            jump5:
            system("cls");
            printf("Enter the saved file number 1 or 2 or 3: ");
            scanf("%d" ,&chooseFile);
            if(chooseFile != 1 && chooseFile != 2 && chooseFile != 3){
                system("cls");
                goto jump5;
            }
            break;
        case 4:
            exit(0);
        default:
            system("cls");
            mainMenu();
    }
}*/
typedef struct{

    int playerscore ;

}playerInfo;

void print(int size1,int arr1[][size1]){
    printf("\n\t\t\t\t\t\t    "); //
    for(int j=1 ;j<size1 ;j++){
        printf(" %d",arr1[0][j]);
    }
    printf("\n");
    for(int i=1 ; i<size1 ; i++){
        if(i>9){printf("\t\t\t\t\t\t   %d",i);} /////
        else{printf("\t\t\t\t\t\t   %d ",i);} /////
        for(int j=1; j<size1 ;j++){
            if( arr1[i][j]==254){
               printf( ANSI_COLOR_WHITE   "%c " ANSI_COLOR_RESET ,arr1[i][j] );
            }else if(arr1[i][j]==178){
               printf( ANSI_COLOR_BLUE   "%c " ANSI_COLOR_RESET ,arr1[i][j] );
            }else if(arr1[i][j]==219){ ////// 219
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
                    if(arr[i+1][j] != 178 && arr[i+1][j] != 219 ){
                        if(player==1){
                           arr[i+1][j] = 178;
                        }else{
                           arr[i+1][j] = 219;
                        }
                        score++;
                    }
                }
            }
        }
    }
    return score;
}

void GamePlay(int playerNumber,int size1, int arr1[][size1],int totalmoves,History U[totalmoves+1],time_t t1){
    time_t t = time(0);
    char *ti = ctime(&t);
        int y,z ;
        there3 :
        if(counter1==0){
            printf(ANSI_COLOR_CYAN"Date: %s"ANSI_COLOR_RESET,ti) ;
            printf(ANSI_COLOR_YELLOW"Time Passed : 00:00"ANSI_COLOR_RESET);
            counter1++ ;
        }else {
            printf(ANSI_COLOR_CYAN"Date: %s"ANSI_COLOR_RESET,ti) ;
            printf(ANSI_COLOR_YELLOW"Time Passed : %02d:%02.f"ANSI_COLOR_RESET,(int)difftime(t2,t1)/60, fmod(difftime(t2,t1),60));
        }
        print(size1,arr1);
        if(v==1){
            printf("\x1b[34;5m" " \n\n\n\n\t\t\t\t\t\t  Player One's Turn\n"ANSI_COLOR_RESET);
        }else if(v==2){
            printf("\x1b[31;5m" " \n\n\n\n\t\t\t\t\t\t  Player Two's Turn\n"ANSI_COLOR_RESET);
        }
        printf(ANSI_COLOR_GREEN"\n\t\t\t\t\t\tNumber of remaining lines: %d\n"ANSI_COLOR_RESET,(totalmoves-moves));
        printf(ANSI_COLOR_BLUE"\n\t\tNumber of moves of player one: %d"ANSI_COLOR_RESET,moves1);
        if(playerNumber==2){
            printf(ANSI_COLOR_RED"\t\t\tNumber of moves of player two: %d\n"ANSI_COLOR_RESET,moves2);
        }else{
            printf(ANSI_COLOR_RED"\t\t\tNumber of moves of the computer: %d\n"ANSI_COLOR_RESET,moves2);
        }
        printf(ANSI_COLOR_BLUE"\n\t\tCurrent Score of Player one : %d "ANSI_COLOR_RESET,score1);
        if(playerNumber ==2){
            printf(ANSI_COLOR_RED" \t\t\tCurrent Score of player two : %d\n\n"ANSI_COLOR_RESET,score2);
        }else{
            printf(ANSI_COLOR_RED" \t\t\tCurrent Score of Computer : %d\n\n"ANSI_COLOR_RESET,score2);
        }
            printf(ANSI_COLOR_YELLOW"**Enter 0,0 for UNDO and 1,1 for REDO** \n\n"ANSI_COLOR_RESET);
        if(v==0){
            goto there5;
        }
        printf(ANSI_COLOR_MAGENTA"%c Enter row : " ANSI_COLOR_RESET,16);
        scanf("%d",&y);
        printf(ANSI_COLOR_MAGENTA"%c Enter column : "ANSI_COLOR_RESET,16);
        scanf("%d",&z);
        t2 = time(0) ;
        if(y==0 && z==0 && moves != 0){          // For Undo
            counter++ ;
            Undo(size1,arr1,totalmoves,U);
            if(playerNumber==1){
                while(v!=1){
                    Undo(size1,arr1,totalmoves,U);
                }
            }
            system("cls");
            goto there3;
        }
        if(y==1 && z==1 && counter){                //For Redo
            counter-- ;
            Redo(size1,arr1,totalmoves,U) ;
            if(playerNumber==1){
                while(v!=1){
                    Redo(size1,arr1,totalmoves,U);
                }
            }
            system("cls");
            goto there3;
        }

        if(y==z || (y%2==0)&&(z%2==0)|| (y%2==1)&&(z%2==1)||y==0||z==0 || arr1[y][z]!=' '){
                system("cls");
                printf("Invalid Move Please Try Again\n\n");
                goto there3;
        }else{
            counter = 0;
            if(v==1){
                if(z%2==0){
                    arr1[y][z]=196;    // for horizontal move
                }else{
                    arr1[y][z]=179;    // for vertical move
                }
            }else if(v==2){
                if(z%2==0){
                    arr1[y][z]=205;    // for horizontal move
                }else{
                    arr1[y][z]=186;    // for vertical move
                }
            }else{
                int flag = 0;
                there5:
                AI(size1,arr1,flag) ;               //Computer Turn

            }
        }
}

void Undo(int size1,int arr1[][size1],int totalmoves,History U[totalmoves+1]){
    v = U[moves-1].WhichPlayer ;
    score1=U[moves-1].scoreplayer1 ;
    score2=U[moves-1].scoreplayer2 ;
    for(int i=0 ;i<size1; i++){
        for(int j=0 ; j<size1 ; j++){
            arr1[i][j]=U[moves-1].arr[i][j] ;
        }
    }
    if(v ==1){
        moves1--;
    }else{
        moves2--;
    }
    moves-- ;
}

void Redo(int size1,int arr1[][size1],int totalmoves,History U[totalmoves+1]){
    if(v !=1){
        moves2++;
    }else{
        moves1++;
    }
    v = U[moves+1].WhichPlayer ;
    score1=U[moves+1].scoreplayer1 ;
    score2=U[moves+1].scoreplayer2 ;
    for(int i=0 ;i<size1; i++){
        for(int j=0 ; j<size1 ; j++){
            arr1[i][j]=U[moves+1].arr[i][j] ;
        }
    }
    moves++ ;
}

void moveshist(int moves1 ,int moves2 ,int totalmoves ,int size1 , int arr1[][size1] ,History U[totalmoves+1]){
    for(int i=0 ;i<size1; i++){
        for(int j=0 ; j<size1 ; j++){
            playes.arr[i][j] = arr1[i][j] ;
        }
    }
    playes.WhichPlayer = v ;
    playes.move1 = moves1 ;
    playes.move2 = moves2 ;
    playes.scoreplayer1 = score1;
    playes.scoreplayer2 = score2;
    playes.move = moves ;
    U[moves]=playes ;
}



void AI (int size1 , int arr1[][size1],int flag){
for(int i = 1; i<size1; i+=2){
        for(int j =2 ; j<size1 ; j+=2){
            if(arr1[i][j]!= ' ' &&arr1[i+2][j]!= ' '){
                if(arr1[i+1][j-1]!= ' ' && arr1[i+1][j+1]== ' '){
                    arr1[i+1][j+1]= 186 ;
                    return ;
                }else if(arr1[i+1][j-1]== ' ' && arr1[i+1][j+1]!= ' '){
                    arr1[i+1][j-1]= 186 ;
                    return ;

                }
            }
            if(arr1[i+1][j-1]!= ' ' && arr1[i+1][j+1]!= ' '){
                if(arr1[i][j]!= ' ' &&arr1[i+2][j]== ' '){
                    arr1[i+2][j]= 205;
                    return ;
                }else if(arr1[i][j]== ' ' &&arr1[i+2][j]!= ' '){
                    arr1[i][j]=205 ;

                }
            }
        }
    }

for(int i=1 ;i<size1 ;i++){
    for(int j=1; j<size1;j++){
        if(arr1[i][j]==' ' && i != j && ((i+j)%2) != 0){
            if(j%2==0){
                arr1[i][j]=205;   // for horizontal move
                flag = 1 ;
                break ;
            }else{
                arr1[i][j]=186;    // for vertical move
                flag = 1 ;
                break ;
            }
            }
            }if(flag){
                break ;
            }

            }

}
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
