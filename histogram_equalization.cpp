#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int i, j;
	int size = 512*512;
    unsigned char Image[512][512], Image1[512][512];

    FILE* lena = NULL;
    FILE* lena1 = NULL;

    lena = fopen("lena_white.raw", "rb");
    fread(Image, sizeof(char), size, lena);
    fclose(lena);
	
	int histogram[256] = {0, };
	for (i=0; i<512; i++){
		for (j=0; j<512; j++){
			int tmp = Image[i][j];
			histogram[tmp]++;
		}
	}
	
	int cumulative_histogram[256] = {0, };
	int sum = 0;
	for (i=0; i<256; i++){
		sum += histogram[i];
		cumulative_histogram[i] = sum;
	}
	
	float normalized_histogram[256] = {0.0f, };
	for (i=0; i<256; i++){
		normalized_histogram[i] = (float)cumulative_histogram[i] / (float)size;
	}
	
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            Image1[i][j] = normalized_histogram[Image[i][j]] * 255;
        }
    }
	
    lena1 = fopen("lena_histogram_equalization.raw", "wb");
    fwrite(Image1, sizeof(char), size, lena1);
    fclose(lena1);

    return 0;
}
