# -*- coding: utf-8 -*-
"""
Created on Tue Apr 25 14:45:27 2023

@author: JK
"""

import threading

import cv2 #OpenCV
import matplotlib.pyplot as plt  # 用于显示图像
import numpy as np               # 用于简化数据操作

frozen_model='frozen_inference_graph.pb'
config_file='ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
COCO_labels = { 0: 'background',
    1: '"person"', 2: 'bicycle', 3: 'car', 4: 'motorcycle',
    5: 'airplane', 6: 'bus', 7: 'train', 8: 'truck', 9: 'boat',
    10: 'traffic light', 11: 'fire hydrant',12: 'street sign', 13: 'stop sign', 14: 'parking meter',
    15: 'zebra', 16: 'bird', 17: 'cat', 18: 'dog',19: 'horse',20: 'sheep',21: 'cow',22: 'elephant',
    23: 'bear', 24: 'zebra', 25: 'giraffe', 26: 'hat', 27: 'backpack', 28: 'umbrella',29: 'shoe',
    30: 'eye glasses', 31: 'handbag', 32: 'tie', 33: 'suitcase', 34: 'frisbee', 35: 'skis',
    36: 'snowboard', 37: 'sports ball', 38: 'kite', 39: 'baseball bat', 40: 'baseball glove',
    41: 'skateboard', 42: 'surfboard', 43: 'tennis racket', 44: 'bottle', 45: 'plate',
    46: 'wine glass', 47: 'cup', 48: 'fork', 49: 'knife', 50: 'spoon', 51: 'bowl', 52: 'banana',
    53: 'apple', 54: 'sandwich', 55: 'orange', 56: 'broccoli', 57: 'carrot', 58: 'hot dog', 59: 'pizza',
    60: 'donut', 61: 'cake', 62: 'chair', 63: 'couch', 64: 'potted plant', 65: 'bed', 66: 'mirror',
    67: 'dining table', 68: 'window', 69: 'desk', 70: 'toilet', 71: 'door', 72: 'tv', 73: 'laptop',
    74: 'mouse', 75: 'remote', 76: 'keyboard', 77:'cell phone',78: 'microwave', 79: 'oven', 80: 'toaster', 81: 'sink',
    82: 'refrigerator', 83: 'blender', 84: 'book', 85: 'clock', 86: 'vase', 87: 'scissors',
    88: 'teddy bear', 89: 'hair drier', 90: 'toothbrush', 91: 'hair brush'}
model=cv2.dnn_DetectionModel(frozen_model,config_file)
model.setInputSize(320,320)
model.setInputScale(1.0/127.5)
model.setInputMean((127.5,127.5,127.5))
model.setInputSwapRB(True)
def detect_objs(img):
    #img=cv2.imread(r'd:\sample2.jpg')         #读入D盘根目录中的图片
    #img=cv2.cvtColor(img,cv2.COLOR_BGR2RGB) #转换颜色
    classIndex,confidence,bbox = model.detect(img,confThreshold=0.55)

    font=cv2.FONT_HERSHEY_PLAIN
    font_scale=3
    if len(classIndex)>0:
        for classIdx,conf,box in zip(classIndex.flatten(),confidence.flatten(),bbox):
            if classIdx>90 or classIdx==0:
                continue
            cv2.rectangle(img,box,(255,0,0),2)
            # print(classIdx)
            cv2.putText(img,COCO_labels[classIdx],(box[0]+5,box[1]+25),font,fontScale=font_scale,color=(0,0,255),thickness=2)
    #plt.imshow(img)
    return img

import cv2
cap=cv2.VideoCapture(0,cv2.CAP_DSHOW)
success,image=cap.read()
while success:
    success,image=cap.read()
    if not success:
        print("reading from cam not successful")
        continue
    image2=detect_objs(image)
    cv2.imshow('Detection',image2)
    k=cv2.waitKey(1)
    if k&0xFF==27:
        break
cap.release()
cv2.destroyAllWindows()