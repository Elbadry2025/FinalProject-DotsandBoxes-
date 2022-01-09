void SaveFun (int arr1[][size1]){ // used to save the data related to the game in external file.
    FILE *save;                   // only 3 saves are allowed.
    switch (ChooseSave){
    case 1: save=fopen("save1.bin","wb");break;
    case 2: save=fopen("save2.bin","wb");break;
    case 3: save=fopen("save3.bin","wb");break;
    }
    fprintf(save,"%d %d %d %d %d %d %d %d %d %s ",score1,score2,moves,moves1,moves2,v,size1,totalmoves,playerNumber,p1.name);
    if(playerNumber==2){            // this 'if' checks if there is a player 2 to save his name.
        fprintf(save," %s ",p2.name);
    }
    for(int i=0 ; i<size1 ;i++){    // this nested 'for' loop is used save the current grid.
        for(int j=0; j<size1 ; j++){
            fprintf(save,"%c",arr1[i][j]);
        }
    }
    fclose(save);
}

void LoadFun(){             // this function is used to load a previously saved game.
    FILE *save;
    switch (ChooseSave){
    case 1: save=fopen("save1.bin","rb");break;
    case 2: save=fopen("save2.bin","rb");break;
    case 3: save=fopen("save3.bin","rb");break;
    }
    fscanf(save,"%d %d %d %d %d %d %d %d %d %s ",&score1,&score2,&moves,&moves1,&moves2,&v,&size1,&totalmoves,&playerNumber,p1.name);
    if(playerNumber==2){    // this 'if' checks if there is a player 2 to load his name.
        fscanf(save," %s ",p2.name);
    }
    for(int i=0 ; i<size1 ;i++){    // this nested 'for' loop is used load the saved grid.
        for(int j=0; j<size1 ; j++){
            fscanf(save,"%c",&arr2[i][j]);
        }
    }

    fclose(save);
}
