#include <fstream>
#include <iostream>
#include "WAVparser.h"
#include "NewWAV.h"

class config_parser{
    std::string _name_config;
    std::vector<wav_parser> _headers;
public:
    config_parser(std::string& name_file, std::vector<wav_parser>& headers);
};