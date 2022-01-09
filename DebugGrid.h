 void DebugGrid (int size1,int arr1[][size1]){      // this function is used to print the grid into an external file (GridDisplay).
 FILE *display;
    display = fopen("GridDisplay.txt","a");
        fprintf(display,"\n\t\t\t\t\t\t    "); //
    for(int j=1 ;j<size1 ;j++){
        fprintf(display," %d",arr1[0][j]);
    }
    fprintf(display,"\n");
    for(int i=1 ; i<size1 ; i++){
        if(i>9){fprintf(display,"\t\t\t\t\t\t   %d",i);}
        else{fprintf(display,"\t\t\t\t\t\t   %d ",i);}
        for(int j=1; j<size1 ;j++){
            if( arr1[i][j]==254){           // dot
               fprintf(display,  "%c "  ,arr1[i][j] );
            }else if(arr1[i][j]==178){      // shape drawn when a box is completed by player 1.
               fprintf(display,   "%c "  ,arr1[i][j] );
            }else if(arr1[i][j]==219){      // shape drawn when a box is completed by player 2 or computer.
               fprintf(display,   "%c "  ,arr1[i][j] );
            }else{
                if(arr1[i][j]==205 || arr1[i][j]==186){   // move made by computer or player 2.
                    fprintf(display, "%c " ,arr1[i][j]);
                }else {                                  // move made by player 1.
                    fprintf(display, "%c " ,arr1[i][j]);
                }
            }
        }
        fprintf(display,"\n");
    }
    fclose(display);
 }
