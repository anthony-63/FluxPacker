#include <stdio.h>

#include "mappacker.h"

#define FLUX_PACKER_ART \
"  ______ _              _____           _         \n" \
" |  ____| |            |  __ \\         | |            \n" \
" | |__  | |_   ___  __ | |__) |_ _  ___| | _____ _ __ \n" \
" |  __| | | | | \\ \\/ / |  ___/ _` |/ __| |/ / _ \\ '__|\n" \
" | |    | | |_| |>  <  | |  | (_| | (__|   <  __/ |   \n" \
" |_|    |_|\\__,_/_/\\_\\ |_|   \\__,_|\\___|_|\\_\\___|_|   \n" \
                                                      
int main() {
    // im a little silly >:)
    char song_name[690];
    char mapper_name[420];
    char artist_name[911];
    char audio_file_name[80085];
    char map_data_file_name[7175]; 

    printf("%s\n", FLUX_PACKER_ART);
    printf("Welcome to flux packer.\nEnter the song name: ");
    scanf("%[^\n]%*c", song_name);
    printf("Enter the artist name: ");
    scanf("%[^\n]%*c", artist_name);
    printf("Enter the mapper name: ");
    scanf("%[^\n]%*c", mapper_name);
    printf("Enter the audio file name: ");
    scanf("%[^\n]%*c", audio_file_name);
    printf("Enter the map data.txt file name: ");
    scanf("%[^\n]%*c", map_data_file_name);
    printf("Now that your done with that longgg process. Let me generate the packed map file for you.\nPacking...\n");
    flux_packer* packer = flux_packer_init(artist_name, song_name, mapper_name, map_data_file_name, audio_file_name);
    flux_packer_pack(packer);
    flux_packer_cleanup(packer);
    printf("Done! Have fun!\n");
}