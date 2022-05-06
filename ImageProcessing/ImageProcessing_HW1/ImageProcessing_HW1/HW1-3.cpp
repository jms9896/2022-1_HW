#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
using namespace std;

int main(void)
{
	unsigned char image[512][512];
	unsigned char temp[512][512];

	int imageSize = 512;
	int light = 0;
	int width = 512, height = 512;
	int x, y;

	//unsigned char** image;
	//unsigned char** temp;
	//fstream fs;
	////2차원 메모리 할당하기
	//image = new unsigned char* [height];
	//for (y = 0; y < height; y++) {
	//	image[y] = new unsigned char[width];
	//}
	//temp = new unsigned char* [height];
	//for (y = 0; y < height; y++) {
	//	temp[y] = new unsigned char[width];
	//}

	//// 파일 열기
	//fs.open("HW1-1_7.raw", ios::out | ios::binary);

	//if (fs.good())
	//{
	//	//파일 쓰기
	//	for (y = 0; y < height; y++)
	//	{
	//		fs.write((char*)image[y], width);
	//		fs.write((char*)temp[y], width);
	//	}
	//	fs.close();
	//}

	////메모리 해제
	//for (y = 0; y < height; y++)
	//{
	//	delete[] image[y];

	//}
	//delete[] image;
	FILE* rawFile;
	fopen_s(&rawFile, "HW1-1_7.raw", "rb");
	fread(image, sizeof(char), width * height, rawFile);

	//// 파일 열기
	//fs.open("HW1-1_7.raw", ios::in | ios::binary);
	//fs.read(imageBuffer, )

	for (x = 0; x < imageSize; x++) {
		for (y = 0; y < imageSize; y++) {
			temp[y][imageSize - x] = image[x][y];
		}
	}

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
	fopen_s(&outFile, "HW1-3.bmp", "wb");

	fwrite(&HF, sizeof(BITMAPFILEHEADER), 1, outFile);
	fwrite(&IF, sizeof(BITMAPINFOHEADER), 1, outFile);
	fwrite(headerRGB, sizeof(RGBQUAD), 256, outFile);
	fwrite(temp, sizeof(unsigned char), width * height, outFile);

	fclose(rawFile);
	fclose(outFile);
	fclose(inFile);



	return 0;

}