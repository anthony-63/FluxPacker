use std::{fs::File, io::Write};

pub const SUPER_SPECIAL_SEP: char = '⁜';

// typedef struct {
//     char* artist;
//     char* song_name;
//     char* mapper;
//     char* map_file;
//     char* mp3_file;
// } flux_packer;
pub struct FluxMapPacker {
    artist: String,
    song_name: String,
    mapper: String,
    map_file: String,
    mp3_file: String,
}

impl FluxMapPacker {
    // flux_packer* flux_packer_init(char* artist, char* song_name, char* mapper, char* map_data_file, char* audio_file);
    pub fn new(artist: &str, song_name: &str, mapper: &str, map_file: &str, mp3_file: &str) -> Self {
        return Self {
            artist: artist.to_string(), 
            song_name: song_name.to_string(), 
            mapper: mapper.to_string(),
            map_file: map_file.to_string(),
            mp3_file: mp3_file.to_string(),
        }
    }
    fn read_map_data(&self) -> Vec<u8> {
        return std::fs::read(&self.map_file).expect("ERROR: Failed to read map data");
    }
    fn read_mp3_data(&self) -> Vec<u8> {
        return std::fs::read(&self.mp3_file).expect("ERROR: Failed to read mp3 data");
    }
    pub fn pack(&self) {
        let out_name = format!("{}-{}_{}.flm", self.artist, self.song_name, self.mapper);
        let mut f = File::create(&out_name).expect("ERROR: Failed to open output map file for writing.");

        f.write(format!("{},{},{}", self.artist, self.song_name, self.mapper).as_bytes()).expect("ERROR: Failed to write metadata to map file.");
        f.write(&[SUPER_SPECIAL_SEP as u8]).expect("ERROR: Failed to write SUPER SPECIAL SEPERATOR No. 1");
        f.write(&self.read_map_data()).expect("ERROR: Failed to write map data to flm file");
        f.write(&[SUPER_SPECIAL_SEP as u8]).expect("ERROR: Failed to write SUPER SPECIAL SEPERATOR No. 2");
        f.write(&self.read_mp3_data()).expect("ERROR: Failed to write mp3 data to flm file");
    }
}