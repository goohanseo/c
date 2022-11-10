#pragma warning(disable:4996)
#include<stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "string_tools.h"
#include "library.h"
#define BUFFER_LENGTH 256

void process_command();
void handle_add();
void handle_load();
void handle_search();
void handle_play();
void handle_remove();
void handle_save();

int main()
{
    initialize();
    handle_load();
    process_command();
    return 0;
}

void handle_search(){
    char name[BUFFER_LENGTH], title[BUFFER_LENGTH];

    printf("    Artist: ");
    if (read_line(stdin,name,BUFFER_LENGTH) <= 0){ //0이면 입력하지 않은거
        printf("    Artist name required.\n");
        return;
    }
    printf("    Ttile:  ");
    int title_len = read_line(stdin, title, BUFFER_LENGTH);

    if (title_len <= 0){
        search_song(name);
    }
    else{
        search_song(name,title);
    }
}
void handle_load(){
    char buffer[BUFFER_LENGTH];
    printf("Data file name ? \n");
    if (read_line(stdin,buffer,BUFFER_LENGTH) <= 0){ //0이면 입력하지 않은거
        return;
    }
    FILE *fp = fopen(buffer, "r");
    if(fp == NULL){
        printf("No such file exists.\n");
        return;
    }
    load(fp);
    fclose(fp);
}


void process_command()
{
    char command_line[BUFFER_LENGTH];
    char *command;
    while(1){ //무한루프
        printf("$ "); //prompt 출력

        if (read_line(stdin,command_line,BUFFER_LENGTH) <= 0) {//라인 단위로 받아옴
        continue;
        }
        command = strtok(command_line, " ");
        if (strcmp(command, "add") == 0){
            handle_add();
        }
        else if (strcmp(command, "search")==0){
            handle_search();
        }
        else if (strcmp(command, "status")==0){
            status();
        }
        else if (strcmp(command, "play")==0){
            handle_play();
        }
        else if (strcmp(command, "remove")==0){
            handle_remove();
        }
        else if (strcmp(command, "save")==0){
            char *tmp = strtok(NULL, " ");
            if (strcmp(tmp,"as")!=0){
                continue;
            }
            handle_save();
        }
        else if (strcmp(command, "exit")==0){
            break;
        }
    }
}

void handle_remove(){
    char *id_str = strtok(NULL, " ");
    int index = atoi(id_str);
    remove(index);
}

void handle_save(){
    char *file_name = strtok(NULL, " ");
    FILE *fp = fopen(file_name, "w");
    save(fp);
    fclose(fp);
}

void handle_play(){
    char *id_str = strtok(NULL, " ");
    int index = atoi(id_str);
    play(index);
}

void handle_add(){

    char buffer[BUFFER_LENGTH];
    char *artist = NULL, *title = NULL, *path = NULL;

    printf(  "Artist:  ");
    if (read_line(stdin,buffer, BUFFER_LENGTH) > 0){ // 적어도 한 글자 이상 입력 되었음
       artist = strdup(buffer); //노래제목으로 덮어쓰여지기 전에 artist에 strdup해줌
    }

    printf(  "Title:  ");
    if (read_line(stdin,buffer, BUFFER_LENGTH) > 0){ // 적어도 한 글자 이상 입력 되었음
       title = strdup(buffer); //노래제목으로 덮어쓰여지기 전에 artist에 strdup해줌
    }

    printf(  "Path:  ");
    if (read_line(stdin,buffer, BUFFER_LENGTH) > 0){ // 적어도 한 글자 이상 입력 되었음
       path = strdup(buffer); //노래제목으로 덮어쓰여지기 전에 artist에 strdup해줌
    }

    printf("%s %s %s\n", artist, title, path);
    //add to the music library

    add_song(artist, title, path);
}


/////////////////////////////////////////////////////////////////////////////////
//library.cpp
#pragma warning(disable:4996)
#include "library.h"
#include <stdlib.h>
#include "string_tools.h"
// #include <windows.h>

#define NUM_CHARS 256 //한 바이트의 최대 표시
#define BUFFER_LENGTH 256
#define SIZE_INDEX_TABLE 100

Artist *artist_directory[NUM_CHARS];
SNode *index_directory[SIZE_INDEX_TABLE];
int num_index = 0;
void insert_node(Artist *ptr_artist, SNode *ptr_snode);
void print_artist(Artist *p);
void print_song(Song *);
void insert_to_index_directory(Song *ptr_song);
Artist *find_artist(char *name);
SNode *find_snode(Artist *ptr_artist, char *title);
void save_artist(Artist *p, FILE *fp);
void save_song(song *ptr_song, FILE *fp);
void destory_song(Song *ptr_song);
void remove_snode(Artist *ptr_artist, SNode *ptr_snode);

void initialize(){
    for (int i =0; i < NUM_CHARS; i++){
        artist_directory[i] = NULL;
    }
    for (int i =0; i < SIZE_INDEX_TABLE; i++){
        index_directory[i] = NULL;
    }
}


void load(FILE *fp){
    char buffer[BUFFER_LENGTH];
    char *name, *title, *path;
    while(1){ //무한루프
        if (read_line(fp,buffer,BUFFER_LENGTH) <= 0) {//라인 단위로 받아옴
        break;
        }
        name = strtok(buffer, "#");
        if(strcmp(name, " ")==0){
            name = NULL;
        }
        else{
            name = strdup(name);
        }
        title = strtok(NULL, "#");
        if(strcmp(title, " ")==0){
            title = NULL;
        }
        else{
            title = strdup(title);
        }
        path = strtok(NULL, "#");
        if(strcmp(path, " ")==0){
            path = NULL;
        }
        else{
            path = strdup(path);
        }
        printf("%s %s %s\n",name, title, path);
        add_song(name,title,path);
    }
}

void search_song(char *artist,char *title){
    Artist *ptr_artist = find_artist(artist);
    if(ptr_artist == NULL){
        printf("no such artist exists.\n");
        return;
    }

    SNode *ptr_snode = find_snode(ptr_artist,title);
    if(ptr_snode != NULL && strcmp(ptr_snode->song->title,title) == 0){
        printf("Found\n");
        print_song(ptr_snode->song);
    }
    else{
        printf("no such artist exists.\n");
        return;
    }
}

SNode *find_snode(Artist *ptr_artist, char *title){ //코드의 재활용을 위해
    SNode *ptr_snode = ptr_artist->head;
    while (ptr_snode != NULL && strcmp(ptr_snode->song->title,title) <0 ){
        ptr_snode = ptr_snode;
    }

    if(ptr_snode != NULL && strcmp(ptr_snode->song->title,title) == 0){
        return ptr_snode;
    }
    else{
        return NULL;
    }
}
void search_song(char *artist){
    Artist *ptr_artist = find_artist(artist);
    if(ptr_artist == NULL){
        printf("no such artist exists.\n");
        return;
    }
    printf("Found\n");
        print_artist(ptr_artist);
}
Artist *create_artist_instance(char *name){
    Artist *ptr_artist = (Artist *)malloc(sizeof(Artist)); 
    ptr_artist->name = name;
    ptr_artist->head = NULL;
    ptr_artist->tail = NULL;
    ptr_artist->next = NULL;
    return ptr_artist;
}
Artist *add_artist(char *name){
    Artist *ptr_artist = create_artist_instance(name);

    Artist *p = artist_directory[(unsigned char)name[0]]; //*p가 위의 연결리스트 삽입할 첫번째 노드
    Artist *q = NULL;

    while(p != NULL && strcmp(p->name, name)<0){
        q = p;
        p = p->next;
    }

    if ( p == NULL && q == NULL){ //유일한 노드
        artist_directory[(unsigned char)name[0]] = ptr_artist; 
        }
    else if (q == NULL){ //앞에다 추가
        ptr_artist->next = artist_directory[(unsigned char)name[0]];
        artist_directory[(unsigned char)name[0]] = ptr_artist; 
    }
    else{
        ptr_artist->next = p;
        q->next = ptr_artist;
    }
    return ptr_artist;
 
}
Song *create_song_instance(Artist *ptr_artist, char *title, char *path){
    Song *ptr_song = (Song *)malloc(sizeof(Song));
    ptr_song->artist = ptr_artist;
    ptr_song->title = title;
    ptr_song->path = path;
    ptr_song->index = num_index;
    num_index++;
    return ptr_song;
}
void add_song(char *artist, char *title, char *path){
    Artist *ptr_artist = find_artist(artist); //이미 존재하면 그 아티스트의 포인터로 
    if (ptr_artist == NULL){
        ptr_artist = add_artist(artist);
    }
    //add the song to the artist pointed by ptr_artist
    Song *ptr_song = create_song_instance(ptr_artist,title,path);
    SNode *ptr_snode= (SNode *)malloc(sizeof(SNode));
    ptr_snode->song = ptr_song; //node 생성시 필요하지 않아도 설정해주는 것이 좋음
    ptr_snode->next = NULL;
    ptr_snode->prev = NULL;

    //insert node
    insert_node(ptr_artist, ptr_snode);
    insert_to_index_directory(ptr_song);
}
void insert_to_index_directory(Song *ptr_song){
    SNode *ptr_snode= (SNode *)malloc(sizeof(SNode));
    ptr_snode->song = ptr_song; //node 생성시 필요하지 않아도 설정해주는 것이 좋음
    ptr_snode->next = NULL;
    ptr_snode->prev = NULL; //unused

    int index = ptr_song->index % SIZE_INDEX_TABLE;

    // add the snode into the single linked list at index_table[index]

    SNode *p = index_directory[index];
    SNode *q = NULL;
    while (p!=NULL && strcmp(p->song->title, ptr_song->title) < 0){
        q = p;
        p = p->next;
    }
    if ( q == NULL){ //add_first
       ptr_snode->next = p;
       index_directory[index] = ptr_snode;
    }
    else{ //add_after q
       ptr_snode->next = p;
       q->next = ptr_snode;
    }
}

void insert_node(Artist *ptr_artist, SNode *ptr_snode){
    SNode *p = ptr_artist->head;
    while(p!=NULL && strcmp(p->song->title, ptr_snode->song->title) < 0) //사전식 배열
    p = p->next;

    //add ptr_snode before p
    //1.empty 2.at the front 3.at the end 4. int the middle 딱딱 나누는것이 실수를 줄임
    if(ptr_artist->head == NULL){ //empty list
       ptr_artist->head = ptr_snode;
       ptr_artist->tail = ptr_snode;
    }
    else if (p == ptr_artist->head){ // at the front
       ptr_snode->next = ptr_artist->head;
       ptr_artist->head->prev = ptr_snode;
       ptr_artist->head = ptr_snode;
    }
    else if (p == NULL){ // at the end
       ptr_snode->prev = ptr_artist->tail;
       ptr_artist->tail->next = ptr_snode;
       ptr_artist->tail = ptr_snode;
    }
    else{ //before p
       ptr_snode-> next = p;
       ptr_snode-> prev = p->prev;
       p->prev->next = ptr_snode;
       p->prev = ptr_snode;
    }
}

Artist *find_artist(char *name){
    Artist *p = artist_directory[(unsigned char)name[0]]; // first artist with initial name[0] 이름의 첫글자
    while (p!=NULL && strcmp(p->name, name)<0){ //알파벳순 정렬
        p = p->next;
    }
    if (p !=NULL && strcmp(p->name, name) == 0){
        return p;
    }
    else{
        return NULL;
    }   
}

void status() //가수이름 사전식 배열의 가순 나순 다순을 검색
{
    for (int i =0; i< NUM_CHARS; i++){
        Artist *p = artist_directory[i];
        while (p != NULL){
            print_artist(p);
            p = p->next;
        }
    }
}

void print_artist(Artist *p){
    printf("%s\n", p->name);
    SNode *ptr_snode = p -> head;
    while (ptr_snode != NULL){
        print_song(ptr_snode->song);
        ptr_snode = ptr_snode-> next; 
    }
}

void print_song(Song *ptr_song){
    printf("    %d: %s, %s\n", ptr_song->index, ptr_song->title, ptr_song->path);
}

SNode *find_song(int index){
    SNode *ptr_snode = index_directory[index%SIZE_INDEX_TABLE];
    while (ptr_snode != NULL && ptr_snode->song->index != index){
        ptr_snode = ptr_snode->next;
    }
    return ptr_snode;
}

void play(int index){
    SNode *ptr_snode = find_song(index);
    if(ptr_snode == NULL){
        printf("No such song exists. \n");
    }

    printf("Found the song: %s\n", ptr_snode->song->title);
    //ShellExecute(GetDesktopWindow(), "open", ptr_snode->song->path, NULL, NULL, SW_SHOW);
}

void save (FILE *fp){
    for (int i =0; i< NUM_CHARS; i++){
        Artist *p = artist_directory[i];
        while (p != NULL){
            save_artist(p,fp);
            p = p->next;
        }
    }
}

void save_artist(Artist *p, FILE *fp){
    SNode *ptr_snode = p -> head;
    while (ptr_snode != NULL){
        save_song(ptr_snode->song, fp);
        ptr_snode = ptr_snode-> next; 
    }
}

void save_song(Song *ptr_song, FILE *fp){
    if(ptr_song->artist != NULL){
        fprintf(fp, "%s#", ptr_song->artist->name);
    }
    else{
        fprintf(fp, "#");
    }
    
    if(ptr_song->title != NULL){
        fprintf(fp, "%s#", ptr_song->title);
    }
    else{
        fprintf(fp, "#");
    }
    if(ptr_song->path != NULL){
        fprintf(fp, "%s#\n", ptr_song->path);
    }
    else{
        fprintf(fp, "#\n");
    }
}

void remove(int index){ //단반향 연결리스트에서 삭제할 노드 이전의 노드의 주소를 찾아야한다.
    //finde the song play와 비슷
    SNode *q = NULL; //previous to p
    SNode *p = index_directory[index%SIZE_INDEX_TABLE]; //head node
    while (p != NULL && p->song->index != index){
        q = p;
        p = p->next;
    }

    if (p == NULL){ //eitehr empty list or nor exist
       printf("No such song exists.\n");
       return;
    }
    Song *ptr_song = p->song;
    if (q == NULL){ // remove first
        index_directory[index%SIZE_INDEX_TABLE] = p->next;
    }
    else{ //remove after q
        q->next = p->next; // q->next = q->next->next;
    }
    free(p);

    Artist *ptr_artist = ptr_song->artist;
    
    //finde the snode in the double linked list of ptr_artist
    SNode *ptr_snode = find_snode(ptr_artist, ptr_song ->title);
    if (ptr_snode == NULL){
        printf("Not found snode - something wrong.\n");
        return;
    }
    remove_snode(ptr_artist,ptr_snode);
    destory_song(ptr_song);
}

void destory_song(Song *ptr_song){
    if(ptr_song->title != NULL){
        free(ptr_song->title);
    }
    if(ptr_song->path != NULL){
        free(ptr_song->path);
    }
    free(ptr_song);
}

void remove_snode(Artist *ptr_artist,SNode *ptr_snode){
	SNode* first = ptr_artist->head;
	SNode* last = ptr_artist->tail;
	if (first == ptr_snode && last == ptr_snode) { // SNode가 유일한 노드일 때
		first = NULL;
		last = NULL;
	}
	else if (first == ptr_snode) { // remove first
		ptr_snode->next->prev = NULL;
		first = ptr_snode->next;
	}
	else if (last == ptr_snode) { // remove last
		ptr_snode->prev->next = NULL;
		last = ptr_snode->prev;
	}
	else { // in the middle
		ptr_snode->next->prev = ptr_snode->prev;
		ptr_snode->prev->next = ptr_snode->next;
	}
	free(ptr_snode);
}
///////////////////////////////////////////////////////////
//library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct song Song;
typedef struct snode SNode;
typedef struct artist Artist;

struct song{
    Artist *artist;
    char *title;
    char *path;
    int index;
};
struct snode{
    struct snode *next, *prev;
    Song *song;
};
struct artist{
    char *name;
    struct artist *next;
    SNode *head, *tail;
};

void initialize();
void add_song(char *artist, char *title, char *path);
void status();
void load(FILE *fp);
void search_song(char *artist,char *title);
void search_song(char *artist);
void play(int index);
void save (FILE *fp);
void remove(int index);
#endif //LIBRARY_H 

///////////////////////////////////////////////////////////
//string_tools.cpp
#include "string_tools.h"
int read_line(FILE *fp, char str[], int n){
    int ch,i =0;
    while ((ch=fgetc(fp)) != '\n' && ch != EOF){
        if(i<n-1){
            str[i++] = ch;
            }
        str[i]= '\0';
        }
        return i;
    
}

//소스파일은 항상 자신의 헤더 파일을 include 해주어야함
//소스파일 -> 헤더파일 -> 메인함수
//7번 한글로 x

///////////////////////////////////////////////////////////
//string_tools.cpp
#pragma warning(disable:4996)

#ifndef STRING_TOOLS_H
#define STRING_TOOLS_H
#include <stdio.h>

int read_line(FILE *fp, char str[], int n);

#endif

//ifndef endif 지시어 이용하여 헤더파일 중복 include 방지