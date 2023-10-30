#include <fstream>
#include <iostream>
#include <vector>

class NewWAV{
    struct NewWAV_header {
        uint8_t _chunkId[4] = {'R', 'I', 'F', 'F'};
        uint32_t _chunkSize;
        uint8_t _format[4] = {'W', 'A', 'V', 'E'};
        uint8_t _subchunk1Id[4] = {'f', 'm', 't', ' '};
        uint32_t _subchunk1Size = 16;
        uint16_t _audioFormat = 1;
        uint16_t _numChannels = 1;
        uint32_t _sampleRate = 44100;
        uint32_t _byteRate = 44100 * 2;
        uint16_t _blockAlign = 2;
        uint16_t _bitsPerSample = 16;
        uint8_t _subchunk2Id[4] = {'D', 'A', 'T', 'A'};
        uint32_t _subchunk2Size;
    }NewWAV_header;

    std::ofstream _out_file;

public:
    NewWAV(std::vector<int16_t> data, uint32_t data_size);
};