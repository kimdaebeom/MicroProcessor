#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int i, j;
    unsigned char Image[512][512], Image_[512][512];

    FILE* lena = NULL;
    FILE* lena_ = NULL;

    lena = fopen("lena.raw", "rb");
    fread(Image, sizeof(char), 512 * 512, lena);
    fclose(lena);

    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            Image_[i][j] = 255 - Image[i][j];
        }
    }

    lena_ = fopen("lena2.raw", "wb");
    fwrite(Image_, sizeof(char), 512 * 512, lena_);
    fclose(lena_);

    return 0;
}
