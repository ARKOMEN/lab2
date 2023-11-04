#include "Processor.h"

processorMute::processorMute(std::vector<int16_t> &data, uint32_t from, uint32_t lenght)
:_data(data), _from(from),_lenght(lenght){}

void processorMute::converter(){
    for(uint32_t i = _from/2; i < (_lenght + _from)/2; ++i){
           _data.at(i) = 0;
    }
}

processorMix::processorMix(std::vector<int16_t> &data1, std::vector<int16_t> &data2, uint32_t from)
:_data1(data1), _data2(data2), _from(from){}

void processorMix::converter(){
    uint32_t size_1 = _data1.size();
    uint32_t size_2 = _data2.size();
    if(size_1 < size_2){
        for(uint32_t i = _from/2; i < size_1; i++){
            _data1.at(i) = (_data1.at(i) + _data2.at(i - _from/2));
        }
    }
    else{
        for(uint32_t i = _from/2; i < size_2; i++){
            _data1.at(i) = (_data1.at(i) + _data2.at(i - _from/2));
        }
    }
}

