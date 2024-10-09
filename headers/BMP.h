#include <string>
#include <vector>

#pragma pack(push, 1)
struct BMPHeader{
    u_int16_t file_type{0x4D42};
    u_int32_t file_size{0};
    u_int16_t res_1{0};
    u_int16_t res_2{0};
    u_int32_t data_offset{54};
    u_int32_t header_size{40};
    int32_t width{0};
    int32_t height{0};
    u_int16_t planes{1};
    u_int16_t bit_count{24};
    u_int32_t compression{0};
    u_int32_t size_image{0};
    int32_t x_pixels_per_meter{0};
    int32_t y_pixels_per_meter{0};
    u_int32_t colors_used{0};
    u_int32_t colors_important{0};
};

struct BMP{
private:
    BMPHeader header;
    std::vector<std::vector<u_int8_t>> data;
public:
    void image_settings(int32_t height, int32_t width);
    void draw_pixel(int x, int y);
    void draw_vertex(int x, int y);
    void draw_line(int x0, int y0, int x1, int y1);
    void draw_rec(int x0, int y0, int x1, int y1);
    void draw_num(int x, int y, int n);
    void file_write(const std::string &filename);
};
#pragma pack(pop)