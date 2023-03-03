#include "mappacker.h"

flux_packer* flux_packer_init(char* artist, char* song_name, char* mapper, char* map_data_file, char* audio_file) {
    flux_packer* packer = malloc(sizeof(flux_packer));
    packer->artist = artist;
    packer->song_name = song_name;
    packer->mapper = mapper;
    packer->map_file = map_data_file;
    packer->mp3_file = audio_file;
    return packer;
}

void flux_packer_pack(flux_packer* packer) {
    char output[6969];
    char map_buf[UINT16_MAX];
    unsigned char mp3_buf[UINT16_MAX];
    sprintf(output, "%s-%s_%s.fpm", packer->artist, packer->song_name, packer->mapper);
    FILE* out = fopen(output, "a+");
    FILE* mp3 = fopen(packer->mp3_file, "rb");
    FILE* map = fopen(packer->map_file, "r+");
    
    if(out == NULL) {
        fprintf(stderr, "Failed to open output file(%s) for writing\nQuitting...\n", output);
        exit(-1);
    }
    if(mp3 == NULL) {
        fprintf(stderr, "Failed to open mp3 file(%s) for reading\nQuitting...\n", packer->mp3_file);
        exit(-1);
    }
    if(map = NULL) {
        fprintf(stderr, "Failed to open map file(%s) for writing\nQuitting...\n", packer->map_file);
        exit(-1);
    }
    fprintf(out, "%s,%s,%s", packer->artist, packer->song_name, packer->mapper);
    fprintf(out, SUPER_COOL_SEPERATOR);
    fgets(map_buf, sizeof(map_buf), map);
    fprintf(out, map_buf);
    fprintf(out, SUPER_COOL_SEPERATOR);
    fread(mp3_buf, sizeof(mp3_buf), 1, mp3);
    fwrite(mp3_buf, sizeof(mp3_buf), 1, out);
    fclose(out);
}

void flux_packer_cleanup(flux_packer* packer) {
    free(packer);
}