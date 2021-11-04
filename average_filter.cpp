#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int i, j;
	int m, n;
	int tmp;
	unsigned char Image[512][512], Image_[512][512];

	FILE* lena = NULL;
	FILE* lena_ = NULL;

	lena = fopen("output_lena_GN_std_8.raw", "rb");
	fread(Image, sizeof(char), 512 * 512, lena);
	fclose(lena);

	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			if (i == 0 || i == 511 || j == 0 || j == 511) {
				Image_[i][j] = 0;
			}
			else {
				tmp = 0;
				for (m = i - 1; m < i + 2; m++) {
					for (n = j - 1; n < j + 2; n++) {
						if (m == i || n == j) {
							if (m == i && n == j) {
								tmp += (Image[m][n] * 4);
							}
							else {
								tmp += (Image[m][n] * 2);
							}
						}
						else {
							tmp += Image[m][n];
						}
					}
				}
				Image_[i][j] = tmp / 16;
			}
		}
	}

	lena_ = fopen("lena_blur.raw", "wb");
	fwrite(Image_, sizeof(char), 512 * 512, lena_);
	fclose(lena_);

	return 0;
}
