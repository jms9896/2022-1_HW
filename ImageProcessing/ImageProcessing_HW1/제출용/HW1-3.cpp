#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
using namespace std;

int main(void)
{
	// 쓰다가 포기...
	
	
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

	//// 파일 열기
	//fs.open("HW1-1_7.raw", ios::in | ios::binary);
	//fs.read(imageBuffer, )


	unsigned char image[512][512];
	unsigned char temp[512][512]; // 버퍼로 쓸 temp배열 만들어주기

	int imageSize = 512;
	int light = 0;
	int width = 512, height = 512;
	int x, y;


	//파일 가져오기
	FILE* fp;
	fopen_s(&fp, "HW1-1_7.raw", "rb");
	fread(image, sizeof(char), width * height, fp);

	// temp에다가 집어넣어서 값 돌려야함. 잘못써서 시간 엄청씀;
	for (x = 0; x < imageSize; x++) {
		for (y = 0; y < imageSize; y++) {
			temp[y][imageSize - x] = image[x][y];
		}
	}
	//여기서부터는 1-2랑 똑같이 하면됨
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