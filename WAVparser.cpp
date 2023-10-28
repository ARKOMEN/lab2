#include "WAVparser.h"

wav_parser::wav_parser(std::string& name_file) : _name_wav_file(name_file){
    std::ifstream File(_name_wav_file, std::ios::binary);
    File.read(reinterpret_cast<char*>(&RIFF), sizeof (RIFF));
    do{
        File.read(reinterpret_cast<char*>(&subchunk1Id), sizeof (subchunk1Id));
    } while (subchunk1Id[0] != 'f' || subchunk1Id[1] != 'm' || subchunk1Id[2] != 't');
    File.read(reinterpret_cast<char*>(&fmt), sizeof (fmt));
    do{
        File.read(reinterpret_cast<char*>(&subchunk2Id), sizeof (subchunk2Id));
    } while (subchunk2Id[0] != 'd' || subchunk2Id[1] != 'a' || subchunk2Id[2] != 't' || subchunk2Id[3] != 'a');
    File.read(reinterpret_cast<char*>(&subchunk2Size), sizeof (subchunk2Size));
    here = File.tellg();
}

std::vector<char> wav_parser::get_data() {
    std::ifstream File(_name_wav_file, std::ios::binary);
    std::vector<char> data;
    char buf;
    File.seekg(here);
    for(uint32_t i = 0; i < this->get_data_size(); ++i) {
        File.read(reinterpret_cast<char *>(&buf),sizeof(char));
        data.push_back(buf);
    }
    return data;
}

uint32_t wav_parser::get_data_size() {
    return this->subchunk2Size;
}

uint32_t wav_parser::get_byteRate() {
    return this->fmt.byteRate;
}