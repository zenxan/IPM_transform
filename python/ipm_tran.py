import cv2
import numpy as np


def multi_transform(img, pts1):

    ROI_HEIGHT = 30000
    ROI_WIDTH = 3750

    # 设定逆透视图的宽度
    IPM_WIDTH = 500
    N = 5

    # 保证逆透视图的宽度大概为N个车头宽
    sacale=(IPM_WIDTH/N)/ROI_WIDTH
    IPM_HEIGHT=ROI_HEIGHT*sacale

    pts2 = np.float32([[IPM_WIDTH/2-IPM_WIDTH/(2*N), 0],
                       [IPM_WIDTH/2+IPM_WIDTH/(2*N), 0],
                       [IPM_WIDTH/2-IPM_WIDTH/(2*N), IPM_HEIGHT],
                       [IPM_WIDTH/2+IPM_WIDTH/(2*N), IPM_HEIGHT]])

    print(IPM_HEIGHT,IPM_WIDTH)

    matrix = cv2.getPerspectiveTransform(pts1, pts2)
    output = cv2.warpPerspective(img, matrix, (int(IPM_WIDTH),int(IPM_HEIGHT+50)))

    for i in range(0, 4):
        cv2.circle(img, (pts1[i][0], pts1[i][1]), 6, (0, 0, 255), cv2.FILLED)
    
    for i in range(0,4):
        cv2.circle(output, (pts2[i][0], pts2[i][1]),6, (0, 0, 255), cv2.FILLED)

    # p1 = (0, 250)
    # p2 = (img.shape[1], img.shape[0]-100)
    # point_color = (255, 0, 0)
    # cv2.rectangle(img, p1, p2, point_color, 2)

    cv2.imshow("src image", img)
    cv2.imshow("output image", output)
    cv2.waitKey(0)


if __name__ == '__main__':
    # 图像1
    img = cv2.imread("../img/img1.jpeg")
    pts1 = np.float32([[321, 250],       # p1
                       [408, 250],       # p2
                       [241, 393],       # p3
                       [477, 393]])      # p4

    # 图像2
    # img = cv2.imread("../img/img2.jpeg")
    # pts1 = np.float32([[243, 189],       # p1
    #                    [383, 186],       # p2
    #                    [77, 253],       # p3
    #                    [533, 253]])      # p4

    multi_transform(img, pts1)

