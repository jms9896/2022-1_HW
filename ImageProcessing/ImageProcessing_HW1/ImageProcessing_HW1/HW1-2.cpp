#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
using namespace std;

int main(void)
{
	// fstream���ٰ� ������ �ȵż� �ٽ� FILE�� ����Ž


	//int x, y;

	//unsigned char** image;
	//fstream fs;

	////2���� �޸� �Ҵ��ϱ�
	//image = new unsigned char* [height];
	//for (y = 0; y < height; y++) {
	//	image[y] = new unsigned char[width];
	//}

	//// ���� ����
	//fs.open("HW1-1_7.raw", ios::in | ios::binary);
	//fs.read(imageBuffer, ) �׳� FILE ����...

	int imageSize = 2^9;
	int width = 2^9, height = 2^9;
	unsigned char image[512][512];

	// ���̺귯������ HF IF RGB �����;ߵ�
	BITMAPFILEHEADER HF;
	BITMAPINFOHEADER IF; 
	RGBQUAD headerRGB[256];

	// ���� ��������
	FILE* fp;
	fopen_s(&fp, "HW1-1_7.raw", "rb");
	fread(image, sizeof(char), width * height, fp);


	// ���� ���� ��������
	char inputImage[50] = "lena_bmp_512x512_new.bmp";
	FILE* fp2;
	fopen_s(&fp2, inputImage, "rb");

	// HF IF RGB
	fread(&HF, sizeof(BITMAPFILEHEADER), 1, fp2);
	fread(&IF, sizeof(BITMAPINFOHEADER), 1, fp2);
	fread(headerRGB, sizeof(RGBQUAD), 256, fp2);


	// ���� ����
	FILE* fp3;
	fopen_s(&fp3, "HW1-2.bmp", "wb");
	// ��� �������!
	fwrite(&HF, sizeof(BITMAPFILEHEADER), 1, fp3);
	fwrite(&IF, sizeof(BITMAPINFOHEADER), 1, fp3);
	fwrite(headerRGB, sizeof(RGBQUAD), 256, fp3);
	fwrite(image, sizeof(unsigned char), width * height, fp3);
	
	// �޸� �ݱ�
	fclose(fp);
	fclose(fp2);
	fclose(fp3);


	//if (fs.good())
	//{
	//	//���� ����
	//	for (y = 0; y < height; y++)
	//	{
	//		fs.write((char*)image[y], width);

	//	}
	//	fs.close();
	//}

	////�޸� ����
	//for (y = 0; y < height; y++)
	//{
	//	delete[] image[y];

	//}
	//delete[] image;

	return 0;


}