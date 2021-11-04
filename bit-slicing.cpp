#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int i, j;
	unsigned char Image[512][512], Image1[512][512], Image2[512][512], Image3[512][512], Image4[512][512], Image5[512][512], Image6[512][512], Image7[512][512], Image8[512][512];
	unsigned char tmp1 = 0x80;
	unsigned char tmp2 = 0x40;
	unsigned char tmp3 = 0x20;
	unsigned char tmp4 = 0x10;
	unsigned char tmp5 = 0x08;
	unsigned char tmp6 = 0x04;
	unsigned char tmp7 = 0x02;
	unsigned char tmp8 = 0x01;

	FILE* lena = NULL;
	FILE* lena1 = NULL;
	FILE* lena2 = NULL;
	FILE* lena3 = NULL;
	FILE* lena4 = NULL;
	FILE* lena5 = NULL;
	FILE* lena6 = NULL;
	FILE* lena7 = NULL;
	FILE* lena8 = NULL;

	lena = fopen("lena_water_mark.raw", "rb");
	fread(Image, sizeof(char), 512 * 512, lena);
	fclose(lena);


	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			if ((Image[i][j] & tmp1) == pow(2, 7)) {
				Image1[i][j] = 255;
			}
			else {
				Image1[i][j] = 0;
			}
			if ((Image[i][j] & tmp2) == pow(2, 6)) {
				Image2[i][j] = 255;
			}
			else {
				Image2[i][j] = 0;
			}
			if ((Image[i][j] & tmp3) == pow(2, 5)) {
				Image3[i][j] = 255;
			}
			else {
				Image3[i][j] = 0;
			}
			if ((Image[i][j] & tmp4) == pow(2, 4)) {
				Image4[i][j] = 255;
			}
			else {
				Image4[i][j] = 0;
			}
			if ((Image[i][j] & tmp5) == pow(2, 3)) {
				Image5[i][j] = 255;
			}
			else {
				Image5[i][j] = 0;
			}
			if ((Image[i][j] & tmp6) == pow(2, 2)) {
				Image6[i][j] = 255;
			}
			else {
				Image6[i][j] = 0;
			}
			if ((Image[i][j] & tmp7) == pow(2, 1)) {
				Image7[i][j] = 255;
			}
			else {
				Image7[i][j] = 0;
			}
			if ((Image[i][j] & tmp8) == pow(2, 0)) {
				Image8[i][j] = 255;
			}
			else {
				Image8[i][j] = 0;
			}
		}
	}

	lena1 = fopen("lena1.raw", "wb");
	fwrite(Image1, sizeof(char), 512 * 512, lena1);
	fclose(lena1);

	lena2 = fopen("lena2.raw", "wb");
	fwrite(Image2, sizeof(char), 512 * 512, lena2);
	fclose(lena2);

	lena3 = fopen("lena3.raw", "wb");
	fwrite(Image3, sizeof(char), 512 * 512, lena3);
	fclose(lena3);

	lena4 = fopen("lena4.raw", "wb");
	fwrite(Image4, sizeof(char), 512 * 512, lena4);
	fclose(lena4);

	lena5 = fopen("lena5.raw", "wb");
	fwrite(Image5, sizeof(char), 512 * 512, lena5);
	fclose(lena5);

	lena6 = fopen("lena6.raw", "wb");
	fwrite(Image6, sizeof(char), 512 * 512, lena6);
	fclose(lena6);

	lena7 = fopen("lena7.raw", "wb");
	fwrite(Image7, sizeof(char), 512 * 512, lena7);
	fclose(lena7);

	lena8 = fopen("lena8.raw", "wb");
	fwrite(Image8, sizeof(char), 512 * 512, lena8);
	fclose(lena8);

	return 0;
}
