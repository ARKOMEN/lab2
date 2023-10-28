#include "NewWAV.h"

NewWAV::NewWAV(std::vector<char> data, uint32_t data_size){
    _out_file = std::ofstream ("output.wav", std::ios::out|std::ios::binary);
    NewWAV_header._subchunk2Size = data_size;
    NewWAV_header._chunkSize = data_size + 32;
    _out_file.write(reinterpret_cast<char*>(&NewWAV_header), sizeof (NewWAV_header));
    for(uint32_t i = 0; i < data_size; ++i)
        _out_file.write(&data.at(i), sizeof (char));
}