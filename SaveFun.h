void SaveFun (int arr1[][size1]){
FILE *save;
save=fopen("save1.bin","wb");
fprintf(save,"%d %d %d %d %d %d %d %d %d ",score1,score2,moves,moves1,moves2,v,size1,totalmoves,playerNumber);
for(int i=0 ; i<size1 ;i++){
    for(int j=0; j<size1 ; j++){
        fprintf(save,"%c",arr1[i][j]);
    }
}
for(int i=0 ; i<totalmoves ; i++){
    fprintf(save,"%d",U[i].WhichPlayer);
    fprintf(save,"%d",U[i].move);
    fprintf(save,"%d",U[i].move1);
    fprintf(save,"%d",U[i].move2);
    fprintf(save,"%d",U[i].scoreplayer1);
    fprintf(save,"%d",U[i].scoreplayer2);
}
for(int k=0 ; k<totalmoves+1; k++){
    for(int i=0 ; i<size1 ;i++){
        for(int j=0; j<size1 ; j++){
            fprintf(save,"%c",U[k].arr[i][j]);
    }
}
}
fclose(save);

}
void LoadFun(){
FILE *save;
save= fopen("save1.bin","rb");
fscanf(save,"%d %d %d %d %d %d %d %d %d ",&score1,&score2,&moves,&moves1,&moves2,&v,&size1,&totalmoves,&playerNumber);
//int arr1[size1][size1] ;
for(int i=0 ; i<size1 ;i++){
    for(int j=0; j<size1 ; j++){
        fscanf(save,"%c",&arr2[i][j]);
    }
}
for(int i=0 ; i<totalmoves ; i++){
    fscanf(save,"%d",&U[i].WhichPlayer);
    fscanf(save,"%d",&U[i].move);
    fscanf(save,"%d",&U[i].move1);
    fscanf(save,"%d",&U[i].move2);
    fscanf(save,"%d",&U[i].scoreplayer1);
    fscanf(save,"%d",&U[i].scoreplayer2);
}
for(int k=1 ; k<totalmoves+1; k++){
    for(int i=1 ; i<size1 ;i++){
        for(int j=1; j<size1 ; j++){
            fscanf(save,"%c",&U[k].arr[i][j]);
    }
}
}
fclose(save);

}
