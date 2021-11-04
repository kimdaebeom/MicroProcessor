#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int i, j;
    int m, n;
    unsigned char Image[512][512], Image_[512][512];
    vector<int> vec;

    FILE* lena = NULL;
    FILE* lena_ = NULL;

    lena = fopen("lena_salt_noise.raw", "rb");
    fread(Image, sizeof(char), 512 * 512, lena);
    fclose(lena);

    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            if (i == 0 || i == 511 || j == 0 || j == 511) {
                Image_[i][j] = 0;
            }
            else {
                vec.clear();
                for (m = i - 1; m < i + 2; m++) {
                    for (n = j - 1; n < j + 2; n++) {
                        vec.push_back(Image[m][n]);
                    }
                }
                sort(vec.begin(), vec.end());
                Image_[i][j] = vec[4];
            }
        }
    }

    lena_ = fopen("lena_median.raw", "wb");
    fwrite(Image_, sizeof(char), 512 * 512, lena_);
    fclose(lena_);

    return 0;
}
