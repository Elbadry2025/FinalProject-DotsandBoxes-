void GamePlay(int playerNumber,int size1, int arr1[][size1],int totalmoves,History U[totalmoves+1],time_t t1){
    time_t t = time(0);
    char *ti = ctime(&t);
    int y,z ;       // y represents the row number while z represents the column number.
    there3 :
    if(counter1==0){
        printf(ANSI_COLOR_CYAN"Date: %s"ANSI_COLOR_RESET,ti) ;
        printf(ANSI_COLOR_YELLOW"Time Passed : 00:00"ANSI_COLOR_RESET);
        counter1++ ;
    }else {
        printf(ANSI_COLOR_CYAN"Date: %s"ANSI_COLOR_RESET,ti) ;
        printf(ANSI_COLOR_YELLOW"Time Passed : %02d:%02.f"ANSI_COLOR_RESET,(int)difftime(t2,t1)/60, fmod(difftime(t2,t1),60));
    }
    print(size1,arr1); // Calling the print function.
    if(v==1){
        printf("\x1b[34;5m" " \n\n\n\n\t\t\t\t\t\t  Player One's Turn\n"ANSI_COLOR_RESET);
    }else if(v==2){
        printf("\x1b[31;5m" " \n\n\n\n\t\t\t\t\t\t  Player Two's Turn\n"ANSI_COLOR_RESET);
    }
    printf(ANSI_COLOR_GREEN"\n\t\t\t\t\t\tNumber of remaining lines: %d\n"ANSI_COLOR_RESET,(totalmoves-moves));
    printf(ANSI_COLOR_BLUE"\t\tplayer one name : %s"ANSI_COLOR_RESET,p1.name);
    if(playerNumber==2){
        printf(ANSI_COLOR_RED"\t\t\t\t\tplayer two name: %s"ANSI_COLOR_RESET,p2.name);
    }else{
        printf(ANSI_COLOR_RED"\t\t\t\t\tplayer two name: Computer"ANSI_COLOR_RESET);
    }
    printf(ANSI_COLOR_BLUE"\n\t\tNumber of moves of player one: %d"ANSI_COLOR_RESET,moves1);
    if(playerNumber==2){
        printf(ANSI_COLOR_RED"\t\t\tNumber of moves of player two: %d"ANSI_COLOR_RESET,moves2);
    }else{
        printf(ANSI_COLOR_RED"\t\t\tNumber of moves of the computer: %d"ANSI_COLOR_RESET,moves2);
    }
    printf(ANSI_COLOR_BLUE"\n\t\tCurrent Score of Player one : %d "ANSI_COLOR_RESET,score1);
    if(playerNumber == 2){
        printf(ANSI_COLOR_RED" \t\t\tCurrent Score of player two : %d\n\n"ANSI_COLOR_RESET,score2);
    }else{
        printf(ANSI_COLOR_RED" \t\t\tCurrent Score of Computer : %d\n\n"ANSI_COLOR_RESET,score2);
    }
    printf(ANSI_COLOR_YELLOW"**Enter 0,0 for UNDO and 1,1 for REDO and 2,2 for SAVE and 3,3 for EXIT** \n\n"ANSI_COLOR_RESET);
    if(v==0){
        goto there5;
    }
    printf(ANSI_COLOR_MAGENTA"%c Enter row : " ANSI_COLOR_RESET,16);
    scanf("%d",&y);
    printf(ANSI_COLOR_MAGENTA"%c Enter column : "ANSI_COLOR_RESET,16);
    scanf("%d",&z);
    t2 = time(0) ;
    if(y == 3 && z == 3){       // this input is used to close the program.
        exit(0);
    }
    if(y== 2 && z == 2){        // this input is used to save the current progress in a specific file.
        j1:
        system("cls");
        printf("Choose which file to save your game in (1 , 2 , 3): ");
        scanf("%d",&ChooseSave);
        if(ChooseSave!=1 && ChooseSave!=2 && ChooseSave!=3 ){
            goto j1;
        }
        SaveFun(arr1);          // Calling the saving function.
        system("cls");
        printf("File Saved Successfully\n");
        goto there3;
    }
    if(y==0 && z==0 && moves != 0 && MovesAfterLoad!=0){    //This input is used to undo
        counter++ ;                             // this variable calculates number of moves undone.
        Undo(size1,arr1,totalmoves,U);          // Calling Undo function.
        if(playerNumber==1){
            while(v!=1){                        // In case of 1 player mode this while loop is used to undo moves of computer until
                Undo(size1,arr1,totalmoves,U);  // the previous move made by player.
            }
        }
            system("cls");
            goto there3;
        }
        if(y==1 && z==1 && counter){          // This input is used to redo
            counter-- ;                       // redo can only happen when undo was done that can be determined by the variable counter.
            Redo(size1,arr1,totalmoves,U) ;         // Calling Undo function.
            if(playerNumber==1){
                while(v!=1){                        // In case of 1 player mode this while loop is used to redo moves of computer until
                    Redo(size1,arr1,totalmoves,U);  // the previous move made by player.
                }
            }
            system("cls");
            goto there3;
        }

        if(y==z || (y%2==0)&&(z%2==0)|| (y%2==1)&&(z%2==1)||y==0||z==0 || arr1[y][z]!=' '){  // This if statement is used to
                scanf("%*[^\n]");                                                            // determine invalid moves made by user.
                system("cls");
                printf("Invalid Move Please Try Again\n\n");
                goto there3;
        }else{
            counter = 0;               // if a new move is made counter becomes 0 to prevent redo.
            if(v==1){                  // player 1 moves is single dash(horizontal or vertical).
                if(z%2==0){
                    arr1[y][z]=196;    // for horizontal move
                }else{
                    arr1[y][z]=179;    // for vertical move
                }
            }else if(v==2){            // player 2 or computer moves are double dash(horizontal or vertical).
                if(z%2==0){
                    arr1[y][z]=205;    // for horizontal move
                }else{
                    arr1[y][z]=186;    // for vertical move
                }
            }else{
                int flag = 0;           // make the AI play only single move each turn.
                there5:
                AI(size1,arr1,flag) ;           //Computer Turn

            }
        }
}
