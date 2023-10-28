#include "ConfigParser.h"
#include "processor.h"

config_parser::config_parser(std::string& name_file, std::vector<wav_parser>& headers) : _name_config(name_file), _headers(headers){
    std::ifstream File(name_file);
    std::string line;
    bool in_process = false;
    processor object;
    std::size_t pos;
    while(getline(File, line)){
        if(line.find("mute") == 0){
            object.from = std::stoi(line.substr(4), &pos);
            int lenght = std::stoi(line.substr(pos + 5));
            if(!in_process){
                object.mute_size = lenght * headers[0].get_byteRate();
                object.new_data = object.mute(headers[0].get_data());
                object.new_size = headers[0].get_data_size();
                in_process = true;
            }
            else{
                object.mute_size = lenght*headers[0].get_byteRate();
                object.mute();
            }

        }
        else if(line[0] == 'm' && line[1] == 'i' && line[2] == 'x'){
            int n = std::stoi(line.substr(4), &pos);
            object.from = std::stoi(line.substr(pos + 5)) * headers[0].get_byteRate();
            if(!in_process){
                object.mix(headers[0].get_data(), headers[n - 1].get_data(), headers[0].get_data_size(), headers[n - 1].get_data_size());
                in_process = true;
            }
            else{
                object.mix(headers[n].get_data(), headers[n].get_data_size());
            }
        }
        else{
            std::cout << "bad input " << std::endl;
        }
    }
    NewWAV output(object.new_data, object.new_size);
}