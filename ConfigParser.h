#include <fstream>
#include <iostream>
#include "WAVparser.h"
#include "NewWAV.h"
#include "Processor.h"

class ConfigParser{
public:
    ConfigParser(std::string& nameFile, std::vector<WavParser>& headers, int num);
};