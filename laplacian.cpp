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
				int tmp = 0;
				for (m = i-1; m < i+2; m++){
					for (n = j-1; n < j+2; n++){
						if(m==i || n==j){
							if (m==i && n==j){
								tmp += (5 * Image[m][n]);
							}
							else{
								tmp -= Image[m][n];
							}
						}
					}
				}
				Image1[i][j] = tmp;
			}
        }
    }
	
    lena1 = fopen("lena_laplacian.raw", "wb");
    fwrite(Image1, sizeof(char), 512 * 512, lena1);
    fclose(lena1);

    return 0;
}
