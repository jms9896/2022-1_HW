#include <iostream>
#include <fstream>
using namespace std;
#pragma warning(disable : 4996)

int main(void)
{
	int imageSize = 2^9; // 이미지 크기는 512*512
	int light = 0; // 밝기 정보 초깃값 0
	int width = 2^9, height = 2^9; // 가로 세로 만들어서 넣었는데 주석쓰다보니까 그냥 이미지 크기 넣어도 됐네
	int x, y;

	// 책에 이중포인터랑 fstream써서 만들어서 1-1은 이걸로 썼음
	unsigned char** image;
	fstream fs;
	
	// 2차원 메모리 할당하기
	image = new unsigned char* [height];
	for (y = 0; y < height; y++) {
		image[y] = new unsigned char[width];
	}

	// image 정보 저장. 노가다의 시작
	for (y = 0; y < height; y++) {

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

	// 파일 열기
	fs.open("HW1-1_7.raw", ios::out | ios::binary);

	if (fs.good())
	{
		// 파일 쓰기
		for (y = 0; y < height; y++)
		{
			fs.write((char*)image[y], width);

		}
		fs.close();
	}

	// 메모리 해제
	for (y = 0; y < height; y++)
	{
		delete [] image[y];

	}
	delete [] image;

	return 0;

}