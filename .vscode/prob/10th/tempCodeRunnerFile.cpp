file = fopen("input.txt", "r");
    if (file == NULL){
        printf("There is no file.");
        return;
    }
    else{
        printf("open file\n");
        organize_file();
        
    }