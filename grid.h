void grid (int size1,int arr1[][size1] ){     // This function is used to initialize an empty grid containing dots and spaces.
    for(int j=0; j < size1; j++){
            arr1[0][j] = j;
            arr1[j][0] = j;
            if(j%2 != 0){
                for(int i=1; i < size1; i=i+2){
                    arr1[i][j] = 254;   // dot
                    arr1[i+1][j] =' ';  //vertical move
                }
            }else if(j%2 == 0){
                for(int i=1; i < size1; i = i+2){
                    arr1[i][j] =' ';    //Horizontal move
                    arr1[i+1][j] =' ';  // space in between
                }
            }
        }

}
