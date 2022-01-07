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
int playerNumber ;
int totalmoves ;
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
typedef struct {
int score;
char name[30];
}playerInfo;
playerInfo p1 ;
playerInfo p2 ;


void mainMenu(){
    int choice;
    int chooseFile;
    printf("\t\t\t\t\t  **Welcome to Dots and Boxes**\n\t\t\t\t\t\tproject made by\n\t\t\t\t\tELbadry Mohamed & Mohamed Hassan");
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
            LoadFun();
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
}
