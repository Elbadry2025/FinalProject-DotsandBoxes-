void AI (int size1 , int arr1[][size1],int flag){
    for(int i = 1; i<size1; i+=2){
        for(int j =2 ; j<size1 ; j+=2){
            if(arr1[i][j]!= ' ' &&arr1[i+2][j]!= ' '){
                if(arr1[i+1][j-1]!= ' ' && arr1[i+1][j+1]== ' '){
                    arr1[i+1][j+1]= 186 ;
                    return ;
                }else if(arr1[i+1][j-1]== ' ' && arr1[i+1][j+1]!= ' '){
                    arr1[i+1][j-1]= 186 ;
                    return ;

                }
            }
            if(arr1[i+1][j-1]!= ' ' && arr1[i+1][j+1]!= ' '){
                if(arr1[i][j]!= ' ' &&arr1[i+2][j]== ' '){
                    arr1[i+2][j]= 205;
                    return ;
                }else if(arr1[i][j]== ' ' &&arr1[i+2][j]!= ' '){
                    arr1[i][j]=205 ;

                }
            }
        }
    }

for(int i=1 ;i<size1 ;i++){
    for(int j=1; j<size1;j++){
        if(arr1[i][j]==' ' && i != j && ((i+j)%2) != 0){
            if(j%2==0){
                arr1[i][j]=205;   // for horizontal move
                flag = 1 ;
                break ;
            }else{
                arr1[i][j]=186;    // for vertical move
                flag = 1 ;
                break ;
            }
            }
            }if(flag){
                break ;
            }

            }

}
