#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[97m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define MAXSIZE 22
int v =1;                    // Represent which player is playing.
int index;                   // Represent the number of saved files in top 10.
int size1=0 ;                // Represent the size of the grid.
int moves=0;                 // Represent the total number of moves played.
int moves1 =0;               // Represent the number of moves played by player 1.
int moves2 =0;               // Represent the number of moves played by player 2.
int score1=0;                // Represent the current score of player 1.
int score2=0;                // Represent the current score of player 2.
int counter=0;               // Counts the number of times undo was used.
int counter1=0;              //
int l1=0 ;                   // A variable that checks if a game is loaded
int x;                       // A variable that determines the size of the grid.
int level;                   // Represents the difficulty selected in the game.
int ChooseSave;              // Represents the number of the file chosen
int ReturnMainMenu;          // A variable used at the end of the program to make the user chose to exit or to play again.
int playerNumber ;           // A variable of value 1 or 2 to determine which will be played whether player vs computer or PVP.
int totalmoves ;             // Represents the total number of lines calculated with a specific formula.
int arr2[MAXSIZE][MAXSIZE];  //
int MovesAfterLoad =0 ;      // Represents number of moves played after loading.
FILE *R ;                    // A file that saves top 10 players.
time_t t2;                   //
typedef struct{              // This structure is used to save data while playing to help undo and redo moves.
    int WhichPlayer ;
    int arr[MAXSIZE][MAXSIZE];
    int move;
    int move1;
    int move2;
    int scoreplayer1;
    int scoreplayer2;
}History;
History playes ;
History U[221];             // U represents an array of the History structure.

typedef struct {            // This structure is used save player name and score to help in enlist top 10 players.
int score;
char name[30];
}playerInfo;
playerInfo p1 ;
playerInfo p2 ;
playerInfo top10[50] ;


void mainMenu(){
    system(" ");            // used to apply colors to the the text written.
    int choice;
    start:
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t  **Welcome to Dots and Boxes**\n\t\t\t\t\t\tproject made by\n\t\t\t\t     ELbadry Mohamed & Mohamed Hassan ELtobgy");
    // The 16 represents a specific shape when printed as %c.
    printf("\n\n%cNew game(enter 1)\n\n%cLoad game(enter 2)\n\n%cTop 10 players(enter 3)\n\n%cExit(enter 4)\n\n%cEnter your choice: ",16,16,16,16,16);
    scanf("%d" ,&choice);   // determines where to go in the main menu
    if(choice != 1 && choice != 2 && choice != 3 && choice != 4){
        scanf("%*[^\n]");   // Prevents the user from entering invalid input.
        system("cls");      // clears the the screen.
        goto start;         // goto function is used to make the compiler go to  a specific place.
    }
    switch(choice){
        case 1:
            system("cls");
            printf("For 1 player mode enter (1)\n\nFor 2 player mode enter (2)\n\n");
            scanf("%d",&playerNumber);
            while(playerNumber != 1 && playerNumber != 2){
                scanf("%*[^\n]");
                system("cls");
                printf("For 1 player mode enter (1)\n\nFor 2 player mode enter (2)\n");
                scanf("%d" , &playerNumber);
            }
            system("cls");
            printf("Player one Name: ");
            scanf("%s",p1.name);
            if(playerNumber==2){
                printf("Player two Name: ");
                scanf("%s",p2.name);
                system("cls");
            }
            again :
            printf("Choose the difficulty level:\n\n%cBeginner(enter 1)\n\n%cModerate(enter 2)\n\n%cHard(enter 3)\n\n%cExpert(enter 4)\n\n%cYour choice: ",16,16,16,16,16);
            scanf("%d" ,&level);
            switch(level){
                case 1: x = 2; break;
                case 2: x = 3; break;
                case 3: x = 4; break;
                case 4: x = 5; break;
                default:
                    scanf("%*[^\n]");
                    system("cls");
                    goto again;
            }
            size1= x*2+2 ;      //specific formula to calculated the number of dots.
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
            LoadFun();          //Calling the loading function.
            l1=1;
            break;
        case 3:
            R=fopen("Rank.bin","rb");
            for(int i=0 ; i<10; i++){
                fscanf(R,"%d\n",&top10[i].score);
                fscanf(R,"%s\n",top10[i].name);
            }
            fclose(R);
            system("cls");
            printf("\t\t\t\t\t\t ***Top Ten Players***\n\n");
            for(int i=0 ; i<10 ; i++){
                printf("\t\t\t\t\t\t      %d- %s: %d\n\n",i+1,top10[i].name,top10[i].score);
            }
        case 4:
            exit(0);           // Function used to exit from the whole program.
    }
}
