#pragma once
#include <vector>
#include <fstream>

class parser{
    std::ifstream _txt;
    std::vector<std::string> _input_files;
    std::string _output_file;
public:
    parser(std::string txt, std::vector<std::string> input_files, std::string output_file);
    ~parser();
};