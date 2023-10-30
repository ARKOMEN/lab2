#include <fstream>
#include <iostream>
#include "WAVparser.h"
#include "NewWAV.h"

class ConfigParser{
    std::vector<WavParser> _headers;
public:
    ConfigParser(std::string& nameFile, std::vector<WavParser>& headers);
};