#include "ConfigParser.h"

using namespace std;

int main(int argc, char** argv) {
    vector<string> inputs;
    string config;

    if(argc == 1 || (argv[1][0] == '-' && argv[1][1] == 'h')){
        cout << "Help" << endl
        << "arguments: <config.txt> <input1.wav> ... <inputN.wav>" << endl
        << "config.txt example:"<< endl
        << "--------------------------------------------------------" << endl
        << "mute 10 5" << endl
        << "mix 2 5" << endl
        << "--------------------------------------------------------" << endl
        << "Mute 1st input file starting from 10 seconds 5 seconds\n"
        << "Mix 1st input file with 2nd from 5" << endl;
    }

    for(int i = 1; i < argc; i++){
        string str = static_cast<string>(argv[i]);
        if(str.find("txt") != str.size() - 3){
            inputs.push_back(argv[i]);
        }
        else{
            config = argv[i];
        }
    }
    vector<WavParser> headers;
    for(int i = 0; i < argc - 2; i++){
        WavParser header(inputs[i]);
        headers.push_back(header);
    }
    configParser(config, headers, argc - 2);
    return 0;
}