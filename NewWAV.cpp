#include "NewWAV.h"

NewWAV::NewWAV(std::vector<int16_t> data, uint32_t dataSize){
    _outFile = std::ofstream ("output.wav", std::ios::out|std::ios::binary);
    _NewWavHeader._subchunk2Size = dataSize;
    _NewWavHeader._chunkSize = dataSize + 32;
    _outFile.write(reinterpret_cast<char *>(&_NewWavHeader), sizeof (_NewWavHeader));
    for(uint32_t i = 0; i < dataSize/2; ++i)
        _outFile.write(reinterpret_cast<char *>(&data.at(i)), sizeof (int16_t));
}