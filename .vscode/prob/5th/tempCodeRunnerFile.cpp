
    }
}

void colmin(){
    for(int i = 0; i < n; i++){
        int min = arr[i][0];
        for(int j = 0; j < n; j++){
            if (min > arr[i][j]){
                min = arr[i][j];
            }
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }