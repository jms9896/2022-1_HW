#include <iostream>
#include <fstream>
using namespace std;
#pragma warning(disable : 4996)

int main(void)
{
	int imageSize = 512;
	int light = 0;
	int width = 512, height = 512;
	int x, y;

	unsigned char** image;
	fstream fs;
	//unsigned char image[512][512];
	
	//2���� �޸� �Ҵ��ϱ�
	image = new unsigned char* [height];
	for (y = 0; y < height; y++) {
		image[y] = new unsigned char[width];
	}

	//image ���� ����
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			image[y][x] = x;
		}
	}

	// ���� ����
	fs.open("HW1-1", ios::out | ios::binary);

	if (fs.good())
	{
		//���� ����
		for (y = 0; y < height; y++)
		{
			fs.write((char*)image[y], width);

		}
		fs.close();
	}

	//�޸� ����
	for (y = 0; y < height; y++)
	{
		delete [] image[y];

	}
	delete [] image;

	return 0;

	//for (int i = 0; i < imageSize; i++) {
	//	if (i < 100) {
	//		light = 120;
	//		for (int j = 0; j < imageSize; j++) {
	//			image[i][j] = light;
	//		}
	//	}

	//	else if (i < 200) {
	//		light = (15 / (i - 100));
	//		for (int j = 0; j < imageSize; j++) {
	//			image[i][j] = light;
	//		}
	//	}

	//	else if (i < 280) {
	//		light = (225 - 135) / (i - 200);
	//		for (int j = 0; j < imageSize; j++) {
	//			image[i][j] = light;
	//		}
	//	}

	//	else if (i < 300) {
	//		light = 15 / (i - 300);
	//		for (int j = 0; j < imageSize; j++) {
	//			image[i][j] = light;
	//		}
	//	}

	//	else {
	//		light = 240;
	//		for (int j = 0; j < imageSize; j++) {
	//			image[i][j] = light;
	//		}
	//	}

	//	//printf("%d", light);
	//}
	//for (int i = 0; i < 512; i++) {
	//	printf("%d", image[0][i]);
	//}
	////printf(image);
	//FILE* fp;
	//fp = fopen("HW1-1.raw", "wb");
	//fwrite(image, sizeof(unsigned char), imageSize * imageSize, fp);
	//fclose(fp);

	//return 0;
}