#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[97m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define MAXSIZE 22
int v =1;           // represent which player is playing
int index ;
int size1=0 ;
int moves=0;
int moves1 =0;
int moves2 =0;
int score1=0;
int score2=0;
int counter=0;
int counter1=0;
int l1=0 ;
int x;
int ChooseSave;
int playerNumber ;
int totalmoves ;
int arr2[MAXSIZE][MAXSIZE];
int MovesAfterLoad =0 ;
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
History U[221];

typedef struct {
int score;
char name[30];
}playerInfo;
playerInfo p1 ;
playerInfo p2 ;
playerInfo top10[25] ;


void mainMenu(){
    int choice;
    start:
    printf("\t\t\t\t\t  **Welcome to Dots and Boxes**\n\t\t\t\t\t\tproject made by\n\t\t\t\t\tELbadry Mohamed & Mohamed Hassan");
    printf("\n\n%cNew game(enter 1)\n\n%cLoad game(enter 2)\n\n%cTop 10 players(enter 3)\n\n%cExit(enter 4)\n\n%cEnter your choice: ",16,16,16,16,16);
    scanf("%d" ,&choice);
    if(choice != 1 && choice != 2 && choice != 3 && choice != 4){
        scanf("%*[^\n]");
        system("cls");      //pervents the user from entering charachters.
        goto start;
    }
    switch(choice){
        case 1:
            system("cls");
            printf(ANSI_COLOR_YELLOW "For 1 player mode enter (1)\n\nFor 2 player mode enter (2)\n"ANSI_COLOR_RESET );
            scanf("%d",&playerNumber);
            while(playerNumber != 1 && playerNumber != 2){
                scanf("%*[^\n]");
                system("cls");
                printf(ANSI_COLOR_YELLOW "For 1 player mode enter (1)\n\nFor 2 player mode enter (2)\n"ANSI_COLOR_RESET );
                scanf("%d" , &playerNumber);
            }
            break;
        case 2:
            jump5:
            system("cls");
            printf("Enter the saved file number 1 or 2 or 3: ");
            scanf("%d" ,&ChooseSave);
            if(ChooseSave != 1 && ChooseSave != 2 && ChooseSave != 3){
                system("cls");
                scanf("%*[^\n]");
                goto jump5;
            }
            LoadFun();
            l1=1;
            break;
        case 4:
            exit(0);
    }
}
