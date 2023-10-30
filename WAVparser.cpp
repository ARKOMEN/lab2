#include "WAVparser.h"

wav_parser::wav_parser(std::string& name_file) : _name_wav_file(name_file){
    std::ifstream File(_name_wav_file, std::ios::binary);
    File.read(reinterpret_cast<char*>(&RIFF), sizeof (RIFF));
    do{
        File.read(reinterpret_cast<char*>(&_subchunk1Id), sizeof (_subchunk1Id));
        File.read(reinterpret_cast<char*>(&_bufSize), sizeof (_bufSize));
        if(_subchunk1Id[0] != 'f' || _subchunk1Id[1] != 'm' || _subchunk1Id[2] != 't'){
            File.seekg(File.tellg() + static_cast<std::streampos>(_bufSize));
        }
        else{
            _subchunk1Size = _bufSize;
            break;
        }
    } while (File.good());
    File.read(reinterpret_cast<char*>(&fmt), sizeof (fmt));
    do{
        File.read(reinterpret_cast<char*>(&_subchunk2Id), sizeof (_subchunk2Id));
        File.read(reinterpret_cast<char*>(&_bufSize), sizeof (_bufSize));
        if(_subchunk2Id[0] != 'd' || _subchunk2Id[1] != 'a' || _subchunk2Id[2] != 't' || _subchunk2Id[3] != 'a'){
            File.seekg(File.tellg() + static_cast<std::streampos>(_bufSize));
        }
        else{
            _subchunk2Size = _bufSize;
            break;
        }
    } while (File.good());
    _here = File.tellg();
}

std::vector<int16_t> wav_parser::get_data() {
    std::ifstream File(_name_wav_file, std::ios::binary);
    std::vector<int16_t> data;
    int16_t buf;
    File.seekg(_here);
    for(uint32_t i = 0; i < this->get_data_size(); ++i) {
        File.read(reinterpret_cast<char *>(&buf),sizeof(buf));
        data.push_back(buf);
    }
    return data;
}

uint32_t wav_parser::get_data_size() {
    return this->_subchunk2Size;
}

uint32_t wav_parser::get_byteRate() {
    return this->fmt.byteRate;
}