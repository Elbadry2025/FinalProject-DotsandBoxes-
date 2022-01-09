void print(int size1,int arr1[][size1]){
    printf("\n\t\t\t\t\t\t    "); //
    for(int j=1 ;j<size1 ;j++){
        printf(" %d",arr1[0][j]);
    }
    printf("\n");
    for(int i=1 ; i<size1 ; i++){
        if(i>9){printf("\t\t\t\t\t\t   %d",i);} /////
        else{printf("\t\t\t\t\t\t   %d ",i);} /////
        for(int j=1; j<size1 ;j++){
            if( arr1[i][j]==254){
               printf( ANSI_COLOR_WHITE   "%c " ANSI_COLOR_RESET ,arr1[i][j] );
            }else if(arr1[i][j]==178){
               printf( ANSI_COLOR_BLUE   "%c " ANSI_COLOR_RESET ,arr1[i][j] );
            }else if(arr1[i][j]==219){ ////// 219
               printf( ANSI_COLOR_RED   "%c " ANSI_COLOR_RESET ,arr1[i][j] );
            }else{
                if(arr1[i][j]==205 || arr1[i][j]==186){
                    printf(ANSI_COLOR_RED "%c "ANSI_COLOR_RESET ,arr1[i][j]);
                } else {
                    printf(ANSI_COLOR_BLUE "%c "ANSI_COLOR_RESET ,arr1[i][j]);
                }
            }
        }
        printf("\n");
    }
DebugGrid(size1,arr1);
}
