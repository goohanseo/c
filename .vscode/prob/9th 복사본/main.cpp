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

// void handle_play();
// void handle_remove();
// void handle_save();

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
        // else if (strcmp(command, "play")==0){
        //     handle_play();
        // }
        // else if (strcmp(command, "remove")==0){
        //     handle_remove();
        // }
        // else if (strcmp(command, "save")==0){
        //     handle_save();
        // }
        else if (strcmp(command, "exit")==0){
            break;
        }
    }
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
#define NUM_CHARS 256 //한 바이트의 최대 표시
#define BUFFER_LENGTH 256

Artist *artist_directory[NUM_CHARS];
int num_index = 0;
void insert_node(Artist *ptr_artist, SNode *ptr_snode);
void print_artist(Artist *p);
void print_song(Song *);
Artist *find_artist(char *name);
SNode *find_snode(Artist *ptr_artist, char *title);

void initialize(){
    for (int i =0; i < NUM_CHARS; i++){
        artist_directory[i] = NULL;
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

    SNode *ptr_snode = find_snode(*ptr_artist,title);
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