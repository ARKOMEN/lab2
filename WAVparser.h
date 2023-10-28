#include <vector>
#include <fstream>
#include <iostream>

class wav_parser{
    struct RIFF{
        uint8_t chunkId[4];
        uint32_t chunkSize;
        uint8_t format[4];
    }RIFF;

    uint8_t subchunk1Id[4];
    struct fmt{
        uint32_t subchunk1Size;
        uint16_t audioFormat;
        uint16_t numChannels;
        uint32_t sampleRate;
        uint32_t byteRate;
        uint16_t blockAlign;
        uint16_t bitsPerSample;
    }fmt;

    uint8_t  subchunk2Id[4];
    uint32_t subchunk2Size;

    std::string _name_wav_file;

    std::streampos here;
public:
    wav_parser(std::string& name_file);
    std::vector<char> get_data();
    uint32_t get_data_size();
    uint32_t get_byteRate();
};
