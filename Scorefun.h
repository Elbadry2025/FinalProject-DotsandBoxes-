int Scorefun(int player,int s ,int arr[][s] ){        // the score function loops on the grid to
    int score = 0;                                    // check if a box has been completed and increases the value of score
    for(int i = 1; i<s-2; i+=2){                      // which is later added to score1 or score2.
        for(int j =2 ; j<s ; j+=2){
            if(arr[i][j]!= ' ' &&arr[i+2][j]!= ' '){
                if(arr[i+1][j-1]!= ' ' && arr[i+1][j+1]!= ' '){
                    if(arr[i+1][j] != 178 && arr[i+1][j] != 219 ){
                        if(player==1){
                           arr[i+1][j] = 178;
                        }else{
                           arr[i+1][j] = 219;
                        }
                        score++;
                    }
                }
            }
        }
    }
    return score;
}
