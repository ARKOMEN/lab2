#include "iostream"
#include "vector"
#include "Converter.h"

class processorMix : public Converter{
    std::vector<int16_t> &_data1;
    std::vector<int16_t> &_data2;
    uint32_t _from;
public:
    processorMix(std::vector<int16_t> &data1, std::vector<int16_t> &data2, uint32_t from);
    void converter() override;
};

class processorMute : public Converter{
    std::vector<int16_t> &_data;
    uint32_t _from;
    uint32_t _lenght;
public:
    processorMute(std::vector<int16_t> &data, uint32_t from, uint32_t lenght);
    void converter() override;
};