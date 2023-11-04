#include "ConfigParser.h"

ConfigParser::ConfigParser(std::string &nameFile, std::vector<WavParser> &headers, int n){
    std::ifstream File(nameFile);
    std::string line;
    std::size_t pos;
    Converter *converter;
    std::vector<int16_t>* data = new std::vector<int16_t>[n];
    for(int i = 0; i < n; i++){
        data[i] = headers[i].getData();
    }
    while(getline(File, line)){
        if(line.find("mute") == 0){
            uint32_t from;
            try {
                from = std::stoi(line.substr(4), &pos) * headers[0].getByteRate();
            }
            catch(std::invalid_argument const &ex) {
                std::cerr << ex.what()  << ", invalid arguments";
                return;
            }
            if(from > headers[0].getDataSize()){
                std::cerr << "invalid arguments";
                return;
            }
            uint32_t lenght;
            try {
                lenght = std::stoi(line.substr(pos + 5))*headers[0].getByteRate();
            }
            catch(std::invalid_argument const &ex) {
                std::cerr << ex.what()  << ", invalid arguments";
                return;
            }
            if(from + lenght> headers[0].getDataSize()){
                std::cerr << "invalid arguments";
                return;
            }
            converter = new processorMute(data[0], from, lenght);
            converter->converter();
        }
        else if(line[0] == 'm' && line[1] == 'i' && line[2] == 'x'){
            int num;
            try{
                num = std::stoi(line.substr(4),&pos);
            }
            catch(std::invalid_argument const &ex) {
                std::cerr << ex.what()  << ", invalid arguments";
                return;
            }
            if(num > n){
                std::cerr << "invalid arguments";
                return;
            }
            uint32_t from;
            try{
                from = std::stoi(line.substr(pos + 5))*headers[0].getByteRate();
            }
            catch(std::invalid_argument const &ex) {
                std::cerr << ex.what()  << ", invalid arguments";
                return;
            }
            if(from > headers[0].getDataSize()){
                std::cerr << "invalid arguments";
                return;
            }
            converter = new processorMix(data[0],data[num-1], from);
            converter->converter();
        }
        else{
            std::cerr << "invalid arguments";
            return;
        }
    }
    NewWAV output(data[0], data[0].size());
    delete[] data;
}