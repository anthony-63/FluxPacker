#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SUPER_COOL_SEPERATOR "⁜"

typedef struct {
    char* artist;
    char* song_name;
    char* mapper;
    char* map_file;
    char* mp3_file;
} flux_packer;

flux_packer* flux_packer_init(char* artist, char* song_name, char* mapper, char* map_data_file, char* audio_file);
void flux_packer_pack(flux_packer* packer);
void flux_packer_cleanup(flux_packer* packer);