void AI (int size1 , int arr1[][size1],int flag){
    for(int i = 1; i<size1-2; i+=2){
        for(int j =2 ; j<size1 ; j+=2){
            if(arr1[i][j]!= ' ' &&arr1[i+2][j]!= ' '){             // this if checks if 2 opposite horizontal sides are not empty.
                if(arr1[i+1][j-1]!= ' ' && arr1[i+1][j+1]== ' '){  // this if checks if 1 of the 2 opposite vertical sides is empty.
                    arr1[i+1][j+1]= 186 ;    // for vertical move
                    return ;
                }else if(arr1[i+1][j-1]== ' ' && arr1[i+1][j+1]!= ' '){ // this else if checks if 1 of the 2 opposite vertical sides is empty.
                    arr1[i+1][j-1]= 186 ;
                    return ;

                }
            }
            if(arr1[i+1][j-1]!= ' ' && arr1[i+1][j+1]!= ' '){       // this if checks if 2 opposite vertical sides are not empty.
                if(arr1[i][j]!= ' ' && arr1[i+2][j]== ' '){         // this if checks if 1 of the 2 opposite horizontal sides is empty.
                    arr1[i+2][j]= 205;      // for horizontal move
                    return ;
                }else if(arr1[i][j]== ' ' && arr1[i+2][j]!= ' '){   // this else if checks if 1 of the 2 opposite horizontal sides is empty.
                    arr1[i][j]= 205 ;
                    return ;
                }
            }
        }
    }

for(int i=1 ;i<size1 ;i++){                 //this loop makes random move if there is no box with single line missing.
    for(int j=1; j<size1;j++){
        if(arr1[i][j]==' ' && i != j && ((i+j)%2) != 0){
            if(j%2==0){
                arr1[i][j]=205;
                flag = 1 ;
                break ;
            }else{
                arr1[i][j]=186;
                flag = 1 ;
                break ;
            }
            }
            }if(flag){
                break ;
            }

            }

}
