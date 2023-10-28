#include "iostream"
#include "vector"

class processor{
public:
    uint32_t new_size;
    uint32_t mute_size;
    std::vector<char> new_data;
    uint32_t from;
    std::vector<char> mute(std::vector<char> data);
    void mute();
    void mix(std::vector<char> data_1, std::vector<char> data_2, uint32_t size_1, uint32_t size_2);
    void mix(std::vector<char> data_2, uint32_t size_2);
};
