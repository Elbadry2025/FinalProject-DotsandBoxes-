void grid (int size1,int arr1[][size1] ){
 //if(x== 1){ // x>>> stands for the lvl x=1 for beginner , x=2 for expert
        //int x;

        for(int j=0; j < size1; j++)
            {
                arr1[0][j] = j;
                arr1[j][0] = j;
                if(j%2 != 0)
                {
                    for(int i=1; i < size1; i=i+2)
                    {
                        arr1[i][j] = 254; // dot
                        arr1[i+1][j] =' '; //vertical move
                    }
                }
                else if(j%2 == 0)
                {
                    for(int i=1; i < size1; i = i+2)
                    {
                        arr1[i][j] =' '; //Horizontal move
                        arr1[i+1][j] =' '; // space in between
                    }
                }
            }


//}
}
