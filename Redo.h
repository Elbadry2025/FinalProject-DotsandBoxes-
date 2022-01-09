void Redo(int size1,int arr1[][size1],int totalmoves,History U[totalmoves+1]){
    // this function is used to redo the next move.
    if(v !=1){                  // this if statement checks which player made the next move
        moves2++;               // and increases his number of moves.
    }else{
        moves1++;
    }
    v = U[moves+1].WhichPlayer ;
    score1=U[moves+1].scoreplayer1 ;
    score2=U[moves+1].scoreplayer2 ;
    for(int i=0 ;i<size1; i++){
        for(int j=0 ; j<size1 ; j++){
            arr1[i][j]=U[moves+1].arr[i][j] ;
        }
    }
    moves++ ;
    MovesAfterLoad++;
}
