#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int i, j;
	int m, n;
    unsigned char Image[512][512], Image1[512][512];

    FILE* lena = NULL;
    FILE* lena1 = NULL;

    lena = fopen("lena.raw", "rb");
    fread(Image, sizeof(char), 512 * 512, lena);
    fclose(lena);

    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            if (i==0 || i == 511 || j == 0 || j == 511){
				Image1[i][j] = 0;
			}
			else{
				int tmp1 = 0;
				int tmp2 = 0;
				for (m = i-1; m < i+2; m++){
					for (n = j-1; n < j+2; n++){
						if (m == i-1){
							if(n==j-1){
								tmp1 -= Image[m][n];
							}
							else if(n==j){
								tmp1 -= 2 * Image[m][n];
							}
							else if(n==j+1){
								tmp1 -= Image[m][n];
							}
						}
						else if (m == i + 1){
							if(n==j-1){
								tmp2 += Image[m][n];
							}
							else if(n==j){
								tmp2 += 2 * Image[m][n];
							}
							else if(n==j+1){
								tmp2 += Image[m][n];
							}
						}
					}
				}
				tmp1 = abs(tmp1 + tmp2);
				Image1[i][j] = tmp1;
			}
        }
    }
	
    lena1 = fopen("lena_sobel.raw", "wb");
    fwrite(Image1, sizeof(char), 512 * 512, lena1);
    fclose(lena1);

    return 0;
}
