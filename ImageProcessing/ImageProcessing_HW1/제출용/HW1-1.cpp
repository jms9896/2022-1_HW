#include <iostream>
#include <fstream>
using namespace std;
#pragma warning(disable : 4996)

int main(void)
{
	int imageSize = 2^9; // �̹��� ũ��� 512*512
	int light = 0; // ��� ���� �ʱ갪 0
	int width = 2^9, height = 2^9; // ���� ���� ���� �־��µ� �ּ����ٺ��ϱ� �׳� �̹��� ũ�� �־ �Ƴ�
	int x, y;

	// å�� ���������Ͷ� fstream�Ἥ ���� 1-1�� �̰ɷ� ����
	unsigned char** image;
	fstream fs;
	
	// 2���� �޸� �Ҵ��ϱ�
	image = new unsigned char* [height];
	for (y = 0; y < height; y++) {
		image[y] = new unsigned char[width];
	}

	// image ���� ����. �밡���� ����
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

	// ���� ����
	fs.open("HW1-1_7.raw", ios::out | ios::binary);

	if (fs.good())
	{
		// ���� ����
		for (y = 0; y < height; y++)
		{
			fs.write((char*)image[y], width);

		}
		fs.close();
	}

	// �޸� ����
	for (y = 0; y < height; y++)
	{
		delete [] image[y];

	}
	delete [] image;

	return 0;

}