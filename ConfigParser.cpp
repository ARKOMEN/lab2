#include "ConfigParser.h"
#include "Processor.h"

ConfigParser::ConfigParser(std::string &nameFile, std::vector<WavParser> &headers) {
    std::ifstream File(nameFile);
    std::string line;
    bool inProcess = false;
    Processor object;
    std::size_t pos;
    while(getline(File, line)){
        if(line.find("mute") == 0){
            object.from = std::stoi(line.substr(4), &pos);
            int lenght = std::stoi(line.substr(pos + 5));
            if(!inProcess){
                object.muteSize = lenght * headers[0].getByteRate();
                object.newData = object.mute(headers[0].getData());
                object.newSize = headers[0].getDataSize();
                inProcess = true;
            }
            else{
                object.muteSize = lenght*headers[0].getByteRate();
                object.mute();
            }

        }
        else if(line[0] == 'm' && line[1] == 'i' && line[2] == 'x'){
            int n = std::stoi(line.substr(4), &pos);
            object.from = std::stoi(line.substr(pos + 5)) * headers[0].getByteRate();
            if(!inProcess){
                object.mix(headers[0].getData(), headers[n - 1].getData(), headers[0].getDataSize(), headers[n - 1].getDataSize());
                inProcess = true;
            }
            else{
                object.mix(headers[n - 1].getData(), headers[n - 1].getDataSize());
            }
        }
        else{
            std::cout << "bad input " << std::endl;
        }
    }
    NewWAV output(object.newData, object.newSize);
}