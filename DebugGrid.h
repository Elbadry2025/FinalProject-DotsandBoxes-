 void DebugGrid (int size1,int arr1[][size1]){
 FILE *display;
    display = fopen("GridDisplay.txt","a");
        fprintf(display,"\n\t\t\t\t\t\t    "); //
    for(int j=1 ;j<size1 ;j++){
        fprintf(display," %d",arr1[0][j]);
    }
    fprintf(display,"\n");
    for(int i=1 ; i<size1 ; i++){
        if(i>9){fprintf(display,"\t\t\t\t\t\t   %d",i);} /////
        else{fprintf(display,"\t\t\t\t\t\t   %d ",i);} /////
        for(int j=1; j<size1 ;j++){
            if( arr1[i][j]==254){
               fprintf(display,  "%c "  ,arr1[i][j] );
            }else if(arr1[i][j]==178){
               fprintf(display,   "%c "  ,arr1[i][j] );
            }else if(arr1[i][j]==219){ ////// 219
               fprintf(display,   "%c "  ,arr1[i][j] );
            }else{
                if(arr1[i][j]==205 || arr1[i][j]==186){
                    fprintf(display, "%c " ,arr1[i][j]);
                } else {
                    fprintf(display, "%c " ,arr1[i][j]);
                }
            }
        }
        fprintf(display,"\n");
    }
    fclose(display);
 }
