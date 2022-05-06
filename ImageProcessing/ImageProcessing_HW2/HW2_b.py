import os
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

def Histogram(Array):
    bright = np.zeros(2**8) # 밝기값 0인 numpy 벡터 생성. 여기다가 값 다 집어넣을거임

    for x in range(Array.shape[0]): # img 받아올거 x값 y값 집어넣고 밝기조절하는 for문
        for y in range(Array.shape[1]):
            bright[Array[x, y]] = bright[Array[x, y]] + 1
            
    return bright

def Graph(def_Histogram): # 히스토그램을 matplotlib로 불러오기
    plt.bar(np.arange(2**8), def_Histogram, width=1)
    plt.show()


file = "./lena_bmp_512x512_new.bmp" # 레나 파일 가져오고
img = np.array(Image.open(file)) # 넘파이 어레이로 이미지 파일 열어서 변수에 넣기

# ~ 여기까지 a에서 가져옴


def PixelSum(histo): # 픽셀값 더해줌
    sum = np.zeros(2**8)
    sum[0] = histo[0]
    for i in range(1, 2**8):
        sum[i] = sum[i-1] + histo[i]
    return sum

def LUT(histogram): # 룩업테이블 만들기
    sum = PixelSum(histogram) #누적합 만들어야됨
    nb_pix = sum[-1]
    lut = np.zeros(2**8)
    for i in range(2**8): # 노멀라이즈 = (누적합 / 픽셀수) * 8비트 명도
        lut[i] = (sum[i] / nb_pix)*(2**8) 

    return lut

def Equal(Array): # equalization 만들거임
    image_Equal = Array.copy() # 이미지 가져와서
    histogram = Histogram(image_Equal) # 히스토그램에 넣기
    lut = LUT(histogram) # 아까 만든 LUT에 집어넣기

    for x in range(image_Equal.shape[0]): # x y 값 집어넣기
        for y in range(image_Equal.shape[1]):
            curBright = image_Equal[x, y]
            image_Equal[x, y] = lut[curBright]

    return image_Equal


Graph(Histogram(Equal(img)))
Image.fromarray(Equal(img)).show()

