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
int v =1;
int moves=0;
int score1=0;
int score2=0;
typedef struct{
    int WhichPlayer ;
    int arr[12][12];
    int move;
    int scoreplayer1;
    int scoreplayer2;
    }History;


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
                           arr[i+1][j] = 219; ///////////////////////////////// 219
                        }
                        score++;
                    }
                }
            }
        }
    }
    return score;
}
void GamePlay(int playerNumber,int size1, int arr1[][size1],int totalmoves,History U[totalmoves+1]){
        int y,z ;
        there3 :
        print(size1,arr1);
        if(v==1){
            printf(ANSI_COLOR_BLUE "\n\n\n\n\t\t\t\t\t\t  Player One's Turn\n"ANSI_COLOR_RESET);
        }else if(v==2){
            printf(ANSI_COLOR_RED "\n\n\n\n\t\t\t\t\t\t  Player Two's Turn\n"ANSI_COLOR_RESET);
        }
        printf(ANSI_COLOR_GREEN"\n\t\t\t\t\t\t Total Number of Moves: %d\n"ANSI_COLOR_RESET,moves);
        printf(ANSI_COLOR_BLUE"\n \t\t\tCurrent Score of Player one : %d "ANSI_COLOR_RESET,score1);
        if(playerNumber==2){
        printf(ANSI_COLOR_RED" \t\t\tCurrent Score of Player Two : %d\n\n"ANSI_COLOR_RESET,score2);
        }else{
        printf(ANSI_COLOR_RED" \t\t\tCurrent Score of Computer : %d\n\n"ANSI_COLOR_RESET,score2);
        }
        if(v==0){
            goto there5;
        }
        printf(ANSI_COLOR_MAGENTA"Enter row : "ANSI_COLOR_RESET);
        scanf("%d",&y);
        printf(ANSI_COLOR_MAGENTA"Enter column : "ANSI_COLOR_RESET);
        scanf("%d",&z);
        if(y==100 && z==100){
            UndoRedo(size1,arr1,totalmoves,U);
            system("cls");
            goto there3;
        }
        if(y==z || (y%2==0)&&(z%2==0)|| (y%2==1)&&(z%2==1)||y==0||z==0 || arr1[y][z]!=' '){
                system("cls");
                printf("Invalid Move Please Try Again\n\n");
                goto there3;
        }else{
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
        }
}

void UndoRedo(int size1,int arr1[][size1],int totalmoves,History U[totalmoves+1]){
    v = U[moves-1].WhichPlayer ;
    score1=U[moves-1].scoreplayer1 ;
    score2=U[moves-1].scoreplayer2 ;
    for(int i=0 ;i<size1; i++){
        for(int j=0 ; j<size1 ; j++){
            arr1[i][j]=U[moves-1].arr[i][j] ;
                }
        }
        moves-- ;
}

int main()
{
    /*typedef struct{
    //int sizeGrid ;
    int arr[size1][size1];
    int move;
    int scoreplayer1;
    int scoreplayer2;
    }History;*/
    system(" ");
    int x;
    //int v ;    // represent which player is playing
    int playerNumber ;
    printf(ANSI_COLOR_YELLOW "For 1 player mode enter (1)\n\nFor 2 player mode enter (2)\n"ANSI_COLOR_RESET );
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
    //int score1 =0 ; int score2 =0;
    //int moves=0;
    int totalmoves= 2*x*(x+1);
    system("cls");
        /*typedef struct{
    int size1 ;
    int arr[size1][size1];
    int move;
    int scoreplayer1;
    int scoreplayer2;
    }History; */
        History U[totalmoves+1];
        History playes;
        //playes.size2= size1 ;
        playes.move = moves ;
        playes.scoreplayer1 = score1;
        playes.scoreplayer2 = score2;
        for(int i=0 ;i<size1; i++){
            for(int j=0 ; j<size1 ; j++){
                playes.arr[i][j] = arr1[i][j] ;
                }
        }
        //U[moves]= playes ;


       /* for(int i=0 ;i<size1; i++){
                for(int j=0 ; j<size1 ; j++){
            playes.arr[i][j] = arr1[i][j] ;
                }
        }
*/

    there :
    while(moves<totalmoves){
        v=1 ;
        playes.WhichPlayer = v ;
        U[moves]= playes ;
        GamePlay(playerNumber,size1,arr1,totalmoves,U);
        system("cls");
        moves++;
        playes.move = moves ;
        //playes.WhichPlayer = v ; ////
        if(moves>totalmoves){break ;}
        int tempScore1 = Scorefun(v,size1,arr1);
                        for(int i=0 ;i<size1; i++){
                    for(int j=0 ; j<size1 ; j++){
                        playes.arr[i][j] = arr1[i][j] ;
                }
        }
        score1 += tempScore1 ;
        playes.scoreplayer1 = score1;
        playes.scoreplayer2 = score2;
        //U[moves]=playes ;
        if(tempScore1){
            goto there;
        }

      /*  playes.move = moves ;
        playes.scoreplayer1 = score1;
        playes.scoreplayer2 = score2;
                for(int i=0 ;i<size1; i++){
                    for(int j=0 ; j<size1 ; j++){
                        playes.arr[i][j] = arr1[i][j] ;
                }
        }*/
       // U[moves]=playes ;
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
        GamePlay(playerNumber,size1,arr1,totalmoves,U);
        there4:
        system("cls");
        moves++;
        playes.move = moves ;
        //playes.WhichPlayer = v ;//
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
       /* playes.move = moves ;
        playes.scoreplayer1 = score1;
        playes.scoreplayer2 = score2;
                for(int i=0 ;i<size1; i++){
                    for(int j=0 ; j<size1 ; j++){
                        playes.arr[i][j] = arr1[i][j] ;
                }
        }
        U[moves]=playes ;*/

        }else{
            break ;
        }

    }
    print(size1,arr1);
    printf(ANSI_COLOR_BLUE "  Player ONE Score : %d "ANSI_COLOR_RESET ,score1) ;
    printf(ANSI_COLOR_RED "      \t\t\t\t\t\t Player TWO Score : %d\n"ANSI_COLOR_RESET ,score2) ;

    return 0;
}
