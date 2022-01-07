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
        printf(ANSI_COLOR_BLUE"\t\tplayer one name : %s"ANSI_COLOR_RESET,p1.name);
        if(playerNumber==2){
        printf(ANSI_COLOR_RED"\t\t\t\tplayer two name: %s"ANSI_COLOR_RESET,p2.name);
        }else{
        printf(ANSI_COLOR_RED"\t\t\t\tplayer two name: Computer"ANSI_COLOR_RESET);
        }
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
