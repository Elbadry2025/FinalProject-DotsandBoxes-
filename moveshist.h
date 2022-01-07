void moveshist(int moves1 ,int moves2 ,int totalmoves ,int size1 , int arr1[][size1] ,History U[totalmoves+1]){
    for(int i=0 ;i<size1; i++){
        for(int j=0 ; j<size1 ; j++){
            playes.arr[i][j] = arr1[i][j] ;
        }
    }
    playes.WhichPlayer = v ;
    playes.move1 = moves1 ;
    playes.move2 = moves2 ;
    playes.scoreplayer1 = score1;
    playes.scoreplayer2 = score2;
    playes.move = moves ;
    U[moves]=playes ;
}
