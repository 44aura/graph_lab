#include <fstream>
#include "../headers/BMP.h"

void BMP::draw_pixel(int x, int y){
    for(int i = 0; i < 3; ++i){
        data[y][x * 3 + i] = 0;
    }
}

void BMP::draw_line(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = -abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        draw_pixel(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void BMP::draw_vertex(int x, int y){
    int x_ = x - 1;
    int y_ = y + 3;
    for (int n = 3; n <= 7; n += 2){
        for (int i = 0; i < n; i++){
            draw_pixel(x_ + i, y_);
        }
        x_ -= 1;
        y_ -= 1;
    }
    x_ += 1;
    for (int k = 0; k < 2; k++){
        for (int i = 0; i < 7; i++){
            draw_pixel(x_ + i, y_);
        }
        y_ -= 1;
    }
    x_ += 1;
    for (int n = 5; n >= 3; n -= 2){
        for (int i = 0; i < n; i++){
            draw_pixel(x_ + i, y_);
        }
        x_ += 1;
        y_ -= 1;
    }
}

void BMP::draw_rec(int x0, int y0, int x1, int y1){
    int rec_width = x1 - x0;
    int rec_height = y1 - y0;
    for (int y = 0; y <= rec_height; y++){
        for (int x = 0; x <= rec_width; x++){
            draw_pixel(x0 + x, y0 + y);
        }
    }
}

void BMP::draw_num(int x, int y, int n){
    x += 3;
    y -= 19;
    std::string num = std::to_string(n);
    for (size_t i = 0; i < num.size(); i++){
        if (num[i] == '1'){
            draw_rec(x + 3, y + 1, x + 4, y + 14);
            draw_rec(x + 2, y + 1, x + 2, y + 2);
            draw_rec(x + 2, y + 13, x + 5, y + 14);
        }
        else if (num[i] == '2'){
            draw_rec(x + 1, y + 1, x + 6, y + 2);
            draw_rec(x + 5, y + 3, x + 6, y + 6);
            draw_rec(x + 1, y + 7, x + 6, y + 8);
            draw_rec(x + 1, y + 9, x + 2, y + 12);
            draw_rec(x + 1, y + 13, x + 6, y + 14);
        }
        else if (num[i] == '3'){
            draw_rec(x + 1, y + 1, x + 6, y + 2);
            draw_rec(x + 5, y + 3, x + 6, y + 6);
            draw_rec(x + 1, y + 7, x + 6, y + 8);
            draw_rec(x + 5, y + 9, x + 6, y + 12);
            draw_rec(x + 1, y + 13, x + 6, y + 14);
        }
        else if (num[i] == '4'){
            draw_rec(x + 1, y + 1, x + 2, y + 7);
            draw_rec(x + 3, y + 6, x + 4, y + 7);
            draw_rec(x + 5, y + 1, x + 6, y + 14);
        }
        else if (num[i] == '5'){
            draw_rec(x + 1, y + 1, x + 6, y + 2);
            draw_rec(x + 1, y + 3, x + 2, y + 6);
            draw_rec(x + 1, y + 7, x + 6, y + 8);
            draw_rec(x + 5, y + 9, x + 6, y + 12);
            draw_rec(x + 1, y + 13, x + 6, y + 14);
        }
        else if (num[i] == '6'){
            draw_rec(x + 1, y + 1, x + 6, y + 2);
            draw_rec(x + 1, y + 1, x + 2, y + 14);
            draw_rec(x + 1, y + 7, x + 6, y + 8);
            draw_rec(x + 5, y + 9, x + 6, y + 12);
            draw_rec(x + 1, y + 13, x + 6, y + 14);
        }
        else if (num[i] == '7'){
            draw_rec(x + 1, y + 1, x + 6, y + 2);
            draw_rec(x + 5, y + 1, x + 6, y + 14);
        }
        else if (num[i] == '8'){
            draw_rec(x + 1, y + 1, x + 6, y + 2);
            draw_rec(x + 1, y + 13, x + 6, y + 14);
            draw_rec(x + 5, y + 1, x + 6, y + 14);
            draw_rec(x + 1, y + 1, x + 2, y + 14);
            draw_rec(x + 1, y + 7, x + 6, y + 8);
        }
        else if (num[i] == '9'){
            draw_rec(x + 1, y + 1, x + 6, y + 2);
            draw_rec(x + 1, y + 3, x + 2, y + 6);
            draw_rec(x + 1, y + 7, x + 6, y + 8);
            draw_rec(x + 5, y + 1, x + 6, y + 14);
            draw_rec(x + 1, y + 13, x + 6, y + 14);
        }
        else if (num[i] == '0'){
            draw_rec(x + 1, y + 1, x + 6, y + 2);
            draw_rec(x + 1, y + 13, x + 6, y + 14);
            draw_rec(x + 5, y + 1, x + 6, y + 14);
            draw_rec(x + 1, y + 1, x + 2, y + 14);
        }
        x += 8;
    }
}

void BMP::image_settings(int32_t height, int32_t width){
    header.file_type = 0x4D42;
    header.height = height;
    header.width = width;
    header.size_image = header.height * header.width * 3;
    header.file_size = sizeof(BMPHeader) + header.size_image;
    std::vector<std::vector<u_int8_t>> image(height, std::vector<u_int8_t>(width * 3, 255));
    data = image;
}

void BMP::file_write(const std::string &filename){
    std::ofstream outfile{filename, std::ios::binary};
    if (outfile.is_open()){
        outfile.write((char*)&header, sizeof(BMPHeader));
        for (int i = header.height - 1; i >= 0; --i){
            outfile.write((char*)data[i].data(), header.width * 3);
        }
    }
    outfile.close();
}
