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


def Stretching(Array): # 스트레칭 함수만 만들면 될 듯
    img_St = Array.copy()
    low = np.min(img_St)
    high = np.max(img_St)
    multi = (2**8) / (high - low)

    for x in range(img_St.shape[0]):
        for y in range(img_St.shape[1]):
            img_St[x, y] = (img_St[x, y] - low) * multi
    
    return img_St


Graph(Histogram(Stretching(img)))
Image.fromarray(Stretching(img)).show()