#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song{
    char *ptr_title;
    char *ptr_artist;
    struct Song *ptr_next;
} Song;

typedef struct Playlist{
    struct Song *ptr_head;
} Playlist;

Playlist *init_playlist(){
    Playlist *ptr_temp = malloc(sizeof(Playlist));
    if(ptr_temp == NULL){
        printf("Cannot allocate memory.");
        return NULL;
    }
    ptr_temp->ptr_head = NULL;
    return ptr_temp;
}

int add_song(Playlist *ptr_playlist, char *ptr_title, char *ptr_artist){
    Song *ptr_new = malloc(sizeof(Song));
    if(ptr_new == NULL){
        printf("Cannot allocate memory.\n");
        return -1;
    }
    char *ptr_tmp_title = malloc(strlen(ptr_title) + 1);
    char *ptr_tmp_artist = malloc(strlen(ptr_artist) + 1);
    if(ptr_tmp_title == NULL || ptr_tmp_artist == NULL){
        printf("Cannot allocate memory.\n");
        return -1;
    }

    strcpy(ptr_tmp_title, ptr_title);
    strcpy(ptr_tmp_artist, ptr_artist);

    ptr_new->ptr_title = ptr_tmp_title;
    ptr_new->ptr_artist = ptr_tmp_artist;
    ptr_new->ptr_next = NULL;

    Song *ptr_temp = ptr_playlist->ptr_head;
    if(ptr_playlist->ptr_head == NULL){
        ptr_playlist->ptr_head = ptr_new;
    }
    else{
        while(ptr_temp->ptr_next){
            ptr_temp = ptr_temp->ptr_next;
        }
        ptr_temp->ptr_next = ptr_new;
    }

    return 1;
}

void print_playlist(Playlist *ptr_playlist){
    Song *ptr_current = ptr_playlist->ptr_head;
    while(ptr_current){
        printf("Title: %s  Artist: %s \n", ptr_current->ptr_title, ptr_current->ptr_artist);
        ptr_current = ptr_current->ptr_next;
    }
}

void delete_first_song(Playlist *ptr_playlist){
    Song *ptr_current = ptr_playlist->ptr_head;
    ptr_playlist->ptr_head = ptr_current->ptr_next;
    free(ptr_current);
}

void delete_playlist(Playlist *ptr_playlist){
    Song *ptr_current = ptr_playlist->ptr_head;
    if(ptr_current){
        while(ptr_current){
            ptr_playlist->ptr_head = ptr_current->ptr_next;
            free(ptr_current);
            ptr_current = ptr_playlist->ptr_head;
        }
    }
    free(ptr_playlist);
}

int main(){
    Playlist *ptr_playlist = init_playlist();
    if(ptr_playlist == NULL){
        printf("Failed to create Playlist.");
        return -1;
    }

    add_song(ptr_playlist, "Highway to Hell", "AC / DC");
    add_song(ptr_playlist, "Test", "AC / DC");
    add_song(ptr_playlist, "Highway to Hell", "AC / DC");
    add_song(ptr_playlist, "Highway to Hell", "AC / DC");

    print_playlist(ptr_playlist);

    delete_playlist(ptr_playlist);

}