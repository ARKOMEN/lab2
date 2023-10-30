#include "iostream"
#include "vector"

class processor{
public:
    uint32_t new_size;
    uint32_t mute_size;
    std::vector<int16_t> new_data;
    uint32_t from;
    std::vector<int16_t> mute(std::vector<int16_t> data);
    void mute();
    void mix(std::vector<int16_t> data_1, std::vector<int16_t> data_2, uint32_t size_1, uint32_t size_2);
    void mix(std::vector<int16_t> data_2, uint32_t size_2);
};
