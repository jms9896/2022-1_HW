#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
using namespace std;

int main(void)
{
	// ���ٰ� ����...
	
	
	//unsigned char** image;
	//unsigned char** temp;
	//fstream fs;
	////2���� �޸� �Ҵ��ϱ�
	//image = new unsigned char* [height];
	//for (y = 0; y < height; y++) {
	//	image[y] = new unsigned char[width];
	//}
	//temp = new unsigned char* [height];
	//for (y = 0; y < height; y++) {
	//	temp[y] = new unsigned char[width];
	//}

	//// ���� ����
	//fs.open("HW1-1_7.raw", ios::out | ios::binary);

	//if (fs.good())
	//{
	//	//���� ����
	//	for (y = 0; y < height; y++)
	//	{
	//		fs.write((char*)image[y], width);
	//		fs.write((char*)temp[y], width);
	//	}
	//	fs.close();
	//}

	////�޸� ����
	//for (y = 0; y < height; y++)
	//{
	//	delete[] image[y];

	//}
	//delete[] image;

	//// ���� ����
	//fs.open("HW1-1_7.raw", ios::in | ios::binary);
	//fs.read(imageBuffer, )


	unsigned char image[512][512];
	unsigned char temp[512][512]; // ���۷� �� temp�迭 ������ֱ�

	int imageSize = 512;
	int light = 0;
	int width = 512, height = 512;
	int x, y;


	//���� ��������
	FILE* fp;
	fopen_s(&fp, "HW1-1_7.raw", "rb");
	fread(image, sizeof(char), width * height, fp);

	// temp���ٰ� ����־ �� ��������. �߸��Ἥ �ð� ��û��;
	for (x = 0; x < imageSize; x++) {
		for (y = 0; y < imageSize; y++) {
			temp[y][imageSize - x] = image[x][y];
		}
	}
	//���⼭���ʹ� 1-2�� �Ȱ��� �ϸ��
	char inputImage[50] = "lena_bmp_512x512_new.bmp";
	FILE* fp2;
	fopen_s(&fp2, inputImage, "rb"); // "Read Binary"

	BITMAPFILEHEADER HF;
	BITMAPINFOHEADER IF;
	RGBQUAD headerRGB[256];

	fread(&HF, sizeof(BITMAPFILEHEADER), 1, fp2);
	fread(&IF, sizeof(BITMAPINFOHEADER), 1, fp2);
	fread(headerRGB, sizeof(RGBQUAD), 256, fp2);

	FILE* fp3;
	fopen_s(&fp3, "HW1-3.bmp", "wb");

	fwrite(&HF, sizeof(BITMAPFILEHEADER), 1, fp3);
	fwrite(&IF, sizeof(BITMAPINFOHEADER), 1, fp3);
	fwrite(headerRGB, sizeof(RGBQUAD), 256, fp3);
	fwrite(temp, sizeof(unsigned char), width * height, fp3);

	fclose(fp);
	fclose(fp3);
	fclose(fp2);



	return 0;

}