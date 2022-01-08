void SaveFun (int arr1[][size1]){
FILE *save;
save=fopen("save1.bin","wb");
fprintf(save,"%d %d %d %d %d %d %d %d %d %s ",score1,score2,moves,moves1,moves2,v,size1,totalmoves,playerNumber,p1.name);
if(playerNumber==2){
    fprintf(save," %s ",p2.name);
}
for(int i=0 ; i<size1 ;i++){
    for(int j=0; j<size1 ; j++){
        fprintf(save,"%c",arr1[i][j]);
    }
}
fclose(save);

}
void LoadFun(){
FILE *save;
save= fopen("save1.bin","rb");
fscanf(save,"%d %d %d %d %d %d %d %d %d %s ",&score1,&score2,&moves,&moves1,&moves2,&v,&size1,&totalmoves,&playerNumber,p1.name);
if(playerNumber==2){
    fscanf(save," %s ",p2.name);
}
for(int i=0 ; i<size1 ;i++){
    for(int j=0; j<size1 ; j++){
        fscanf(save,"%c",&arr2[i][j]);
    }
}

fclose(save);

}
