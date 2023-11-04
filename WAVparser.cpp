#include "WAVparser.h"

WavParser::WavParser(std::string& nameFile) : _nameWavFile(nameFile){
    std::ifstream File(_nameWavFile, std::ios::binary);
    if(!File.read(reinterpret_cast<char*>(&_RIFF), sizeof (_RIFF))){
        std::cerr << "Failed to read the RIFF chunk.";
        return;
    }
    do{
        if(!File.read(reinterpret_cast<char*>(&_subchunk1Id), sizeof (_subchunk1Id))){
            std::cerr << "Failed to read chunk's name.";
            return;
        }
        if(!File.read(reinterpret_cast<char*>(&_bufSize), sizeof (_bufSize))){
            std::cerr << "Failed to read chunk's size";
            return;
        }
        if(_subchunk1Id[0] != 'f' || _subchunk1Id[1] != 'm' || _subchunk1Id[2] != 't'){
            if(!File.seekg(File.tellg() + static_cast<std::streampos>(_bufSize))){
                std::cerr << "Failed to seek";
                return;
            }
        }
        else{
            _subchunk1Size = _bufSize;
            break;
        }
    } while (File.good());
    if(!File.read(reinterpret_cast<char*>(&_fmt), sizeof (_fmt))){
        std::cerr << "Failed to read the fmt chunk.";
        return;
    }
    do{
        if(!File.read(reinterpret_cast<char*>(&_subchunk2Id), sizeof (_subchunk2Id))){
            std::cerr << "Failed to read chunk's name.";
            return;
        }
        if(!File.read(reinterpret_cast<char*>(&_bufSize), sizeof (_bufSize))){
            std::cerr << "Failed to read chunk's size";
            return;
        }
        if(_subchunk2Id[0] != 'd' || _subchunk2Id[1] != 'a' || _subchunk2Id[2] != 't' || _subchunk2Id[3] != 'a'){
            if(!File.seekg(File.tellg() + static_cast<std::streampos>(_bufSize))){
                std::cerr << "Failed to seek";
                return;
            }
        }
        else{
            _subchunk2Size = _bufSize;
            break;
        }
    } while (File.good());
    _here = File.tellg();
}

std::vector<int16_t> WavParser::getData() {
    std::ifstream File(_nameWavFile, std::ios::binary);
    std::vector<int16_t> data;
    int16_t buf;
    if(!File.seekg(_here)){
        std::runtime_error("Failed to seek");
    }
    for(uint32_t i = 0; i < this->getDataSize(); ++i) {
        if(!File.read(reinterpret_cast<char *>(&buf),sizeof(buf))){
            std::runtime_error("Failed to read data");
        }
        data.push_back(buf);
    }
    return data;
}

uint32_t WavParser::getDataSize() {
    return this->_subchunk2Size;
}

uint32_t WavParser::getByteRate() {
    return this->_fmt._byteRate;
}