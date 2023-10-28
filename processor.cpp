#include "processor.h"

std::vector<char> processor::mute(std::vector<char> data){
    for(uint32_t i = from; i < mute_size; ++i){
           data.at(i) = 0;
    }
    return data;
}

void processor::mute(){
    for(uint32_t i = from; i < mute_size; ++i){
        new_data.at(i) = 0;
    }
}

void processor::mix(std::vector<char> data_1, std::vector<char> data_2, uint32_t size_1, uint32_t size_2){
    new_size = size_1 < size_2 ? size_1 : size_2;
    for(uint32_t i = 0; i < from; ++i){
        new_data.push_back(data_1.at(i));
    }
    for(uint32_t i = from; i < new_size; ++i){
        new_data.push_back((data_1.at(i) + data_2.at(i - from)) / 2);
    }
}

void processor::mix(std::vector<char> data_2, uint32_t size_2) {
    new_size = new_size < size_2 ? new_size : size_2;
    for(uint32_t i = from; i < new_size; ++i){
        new_data.at(i) = (new_data.at(i) + data_2.at(i - from)) / 2;
    }
}