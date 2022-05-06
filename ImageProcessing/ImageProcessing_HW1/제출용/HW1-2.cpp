#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
using namespace std;

int main(void)
{
	int imageSize = 512;
	int width = 512, height = 512;
	//int x, y;

	//unsigned char** image;
	//fstream fs;
	unsigned char image[512][512];

	////2차원 메모리 할당하기
	//image = new unsigned char* [height];
	//for (y = 0; y < height; y++) {
	//	image[y] = new unsigned char[width];
	//}
	FILE* rawFile;
	fopen_s(&rawFile, "HW1-1_7.raw", "rb");
	fread(image, sizeof(char), width * height, rawFile);

	//// 파일 열기
	//fs.open("HW1-1_7.raw", ios::in | ios::binary);
	//fs.read(imageBuffer, )
	char inputImage[50] = "lena_bmp_512x512_new.bmp";
	FILE* inFile;
	fopen_s(&inFile, inputImage, "rb"); // "Read Binary"

	BITMAPFILEHEADER HF;
	BITMAPINFOHEADER IF; 
	RGBQUAD headerRGB[256];

	fread(&HF, sizeof(BITMAPFILEHEADER), 1, inFile);
	fread(&IF, sizeof(BITMAPINFOHEADER), 1, inFile);
	fread(headerRGB, sizeof(RGBQUAD), 256, inFile);

	FILE* outFile;
	fopen_s(&outFile, "HW1-2.bmp", "wb");

	fwrite(&HF, sizeof(BITMAPFILEHEADER), 1, outFile);
	fwrite(&IF, sizeof(BITMAPINFOHEADER), 1, outFile);
	fwrite(headerRGB, sizeof(RGBQUAD), 256, outFile);
	fwrite(image, sizeof(unsigned char), width * height, outFile);
	
	fclose(rawFile);
	fclose(outFile);


	//if (fs.good())
	//{
	//	//파일 쓰기
	//	for (y = 0; y < height; y++)
	//	{
	//		fs.write((char*)image[y], width);

	//	}
	//	fs.close();
	//}

	////메모리 해제
	//for (y = 0; y < height; y++)
	//{
	//	delete[] image[y];

	//}
	//delete[] image;

	return 0;


}