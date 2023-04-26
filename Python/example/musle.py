# -*- coding: utf-8 -*-
"""
Created on Tue Apr 25 15:23:51 2023

@author: JK
"""

import cv2 as cv
import mediapipe as mp 
img = cv.imread(r"D:\\Code_Storge\\GitHub_Local\\Python\\example\\img_src\\me.jpg")
mp_draw = mp.solutions.drawing_utils
mp_pose =  mp.solutions.pose
Ps = mp_pose.Pose(min_detection_confidence = 0.5,min_tracking_confidence=0.5)
rst = Ps.process(img)
mp_draw.draw_landmarks(img,rst.pose_landmarks,mp_pose.POSE_CONNECTIONS)

cv.imshow("me",img)
cv.waitKey(0)