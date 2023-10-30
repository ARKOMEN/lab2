#include <vector>
#include <fstream>
#include <iostream>

class WavParser{
    struct _RIFF{
        uint8_t _chunkId[4];
        uint32_t _chunkSize;
        uint8_t _format[4];
    }_RIFF;

    uint8_t _subchunk1Id[4];
    uint32_t _subchunk1Size;
    struct _fmt{
        uint16_t _audioFormat;
        uint16_t _numChannels;
        uint32_t _sampleRate;
        uint32_t _byteRate;
        uint16_t _blockAlign;
        uint16_t _bitsPerSample;
    }_fmt;

    uint8_t  _subchunk2Id[4];
    uint32_t _subchunk2Size;

    std::string _nameWavFile;

    std::streampos _here;

    uint32_t _bufSize;
public:
    WavParser(std::string& nameFile);
    std::vector<int16_t> getData();
    uint32_t getDataSize();
    uint32_t getByteRate();
};
