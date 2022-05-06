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
		//for (x = 0; x < width; x++) {
		//	image[y][x] = x;
		//}
		if (y < 100) {
			light = 120;
			for (x = 0; x < width; x++) {
				image[x][y] = light;
			}
		}

		else if (y < 200) {
			light = 120+(15 / (200-y));
			for (x = 0; x < width; x++) {
				image[x][y] = light;
			}
		}

		else if (y < 280) {
			light = 135+((225 - 135) / (280-y));
			for (x = 0; x < width; x++) {
				image[x][y] = light;
			}
		}

		else if (y < 300) {
			light = 225+(15 / (300-y));
			for (x = 0; x < width; x++) {
				image[x][y] = light;
			}
		}

		else {
			light = 240;
			for (x = 0; x < width; x++) {
				image[x][y] = light;
			}
		}

		
	}

	// ���� ����
	fs.open("HW1-1_7.raw", ios::out | ios::binary);

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

	//FILE* fp;
	//fp = fopen("HW1-1.raw", "wb");
	//fwrite(image, sizeof(unsigned char), imageSize * imageSize, fp);
	//fclose(fp);

	//return 0;
}