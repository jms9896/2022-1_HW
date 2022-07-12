#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
using namespace std;

int main(void)
{
	// fstream쓰다가 도저히 안돼서 다시 FILE로 갈아탐


	//int x, y;

	//unsigned char** image;
	//fstream fs;

	////2차원 메모리 할당하기
	//image = new unsigned char* [height];
	//for (y = 0; y < height; y++) {
	//	image[y] = new unsigned char[width];
	//}

	//// 파일 열기
	//fs.open("HW1-1_7.raw", ios::in | ios::binary);
	//fs.read(imageBuffer, ) 그냥 FILE 쓰자...

	int imageSize = 2^9;
	int width = 2^9, height = 2^9;
	unsigned char image[512][512];

	// 라이브러리에서 HF IF RGB 가져와야됨
	BITMAPFILEHEADER HF;
	BITMAPINFOHEADER IF; 
	RGBQUAD headerRGB[256];

	// 파일 가져오기
	FILE* fp;
	fopen_s(&fp, "HW1-1_7.raw", "rb");
	fread(image, sizeof(char), width * height, fp);


	// 레나 원본 가져오기
	char inputImage[50] = "lena_bmp_512x512_new.bmp";
	FILE* fp2;
	fopen_s(&fp2, inputImage, "rb");

	// HF IF RGB
	fread(&HF, sizeof(BITMAPFILEHEADER), 1, fp2);
	fread(&IF, sizeof(BITMAPINFOHEADER), 1, fp2);
	fread(headerRGB, sizeof(RGBQUAD), 256, fp2);


	// 파일 쓰기
	FILE* fp3;
	fopen_s(&fp3, "HW1-2.bmp", "wb");
	// 헤더 집어넣자!
	fwrite(&HF, sizeof(BITMAPFILEHEADER), 1, fp3);
	fwrite(&IF, sizeof(BITMAPINFOHEADER), 1, fp3);
	fwrite(headerRGB, sizeof(RGBQUAD), 256, fp3);
	fwrite(image, sizeof(unsigned char), width * height, fp3);
	
	// 메모리 닫기
	fclose(fp);
	fclose(fp2);
	fclose(fp3);


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