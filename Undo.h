void Undo(int size1,int arr1[][size1],int totalmoves,History U[totalmoves+1]){
    v = U[moves-1].WhichPlayer ;
    score1=U[moves-1].scoreplayer1 ;
    score2=U[moves-1].scoreplayer2 ;
    for(int i=0 ;i<size1; i++){
        for(int j=0 ; j<size1 ; j++){
            arr1[i][j]=U[moves-1].arr[i][j] ;
        }
    }
    if(v ==1){
        moves1--;
    }else{
        moves2--;
    }
    moves-- ;
}
