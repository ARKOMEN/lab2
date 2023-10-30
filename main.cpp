#include "ConfigParser.h"

using namespace std;

int main(int argc, char** argv) {
    vector<string> inputs;
    string config;
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
    ConfigParser Config(config, headers);
    return 0;
}
//string_view
//фабричный метод
//почитать про virtual override