 void topPlayers(){             //this function saves the top 10 players in an external file.
 FILE *topten;
    topten =fopen("ArrayIndex.bin","rb");
    fscanf(topten,"%d",&index);

    FILE *rank ;
    rank= fopen("Rank.bin","rb");
    for(int i=0 ; i< index; i++){
        fscanf(rank,"%d\n",&top10[i].score);
        fscanf(rank,"%s\n",top10[i].name);
    }
    if(p1.score > score2){                          //this 'if', 'else if','else if' are used to determine
        strcpy(top10[index].name,p1.name);          //the winning player and take his name and score.
        top10[index].score = p1.score;
        index++;
    }else if(p2.score > p1.score){
        strcpy(top10[index].name,p2.name);
        top10[index].score = p2.score;
        index++;
    }else if(p1.score == p2.score){
        strcpy(top10[index].name,p1.name);
        top10[index].score = p1.score;
        index++;
        strcpy(top10[index].name,p2.name);
        top10[index].score = p2.score;
        index++;
    }
    topten =fopen("ArrayIndex.bin","wb");
    fprintf(topten,"%d",index);
    fclose(topten);
    for(int i=0 ; i<index ;i++){                  //sorting the players using bubble sort
        for(int j=0 ; j<index-1;j++){
            if(top10[j].score < top10[j+1].score ){
                playerInfo temp = top10[j];
                top10[j]=top10[j+1];
                top10[j+1]=temp ;
            }
        }
    }
    rank= fopen("Rank.bin","wb");
    for(int i=0 ; i< index; i++){               // printing the data of the winners to external file.
        fprintf(rank,"%d\n",top10[i].score);    // to use it in ranking the top 10 players.
        fprintf(rank,"%s\n",top10[i].name);
    }
    fclose(rank);
 }
