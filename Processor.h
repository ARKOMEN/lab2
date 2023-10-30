#include "iostream"
#include "vector"

class Processor{
public:
    uint32_t newSize;
    uint32_t muteSize;
    std::vector<int16_t> newData;
    uint32_t from;
    std::vector<int16_t> mute(std::vector<int16_t> data);
    void mute();
    void mix(std::vector<int16_t> data_1, std::vector<int16_t> data_2, uint32_t size_1, uint32_t size_2);
    void mix(std::vector<int16_t> data_2, uint32_t size_2);
};
