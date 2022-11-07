void search_song(char *artist,char *title){
    Artist *ptr_artist = find_artist(artist);
    if(ptr_artist == NULL){
        printf("no such artist exists.\n");
        return;
    }

    SNode *ptr_snode = ptr_artist->head;
    while (ptr_snode != NULL && strcmp(ptr_snode->song->title,title) <0 ){
        ptr_snode = ptr_snode;
    }

    if(ptr_snode != NULL && strcmp(ptr_snode->song->title,title) == 0){
        print_song(ptr_snode->song);
    }
    else{
        printf("no such artist exists.\n");
        return;
    }
}