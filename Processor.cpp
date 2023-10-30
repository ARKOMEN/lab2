#include "Processor.h"

std::vector<int16_t> Processor::mute(std::vector<int16_t> data){
    for(uint32_t i = from; i < muteSize/2; ++i){
           data.at(i) = 0;
    }
    return data;
}

void Processor::mute(){
    for(uint32_t i = from; i < muteSize/2; ++i){
        newData.at(i) = 0;
    }
}

void Processor::mix(std::vector<int16_t> data_1, std::vector<int16_t> data_2, uint32_t size_1, uint32_t size_2){
    newSize = size_1 < size_2 ? size_1 : size_2;
    for(uint32_t i = 0; i < from/2; ++i){
        newData.push_back(data_1.at(i));
    }
    for(uint32_t i = from; i < newSize/2; ++i){
        newData.push_back((data_1.at(i) + data_2.at(i - from)) / 2);
    }
}

void Processor::mix(std::vector<int16_t> data_2, uint32_t size_2) {
    newSize = newSize < size_2 ? newSize : size_2;
    for(uint32_t i = from; i < newSize/2; ++i){
        newData.at(i) = (newData.at(i) + data_2.at(i - from)) / 2;
    }
}