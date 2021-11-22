// #include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

bool executeipm(Mat& img,Mat& dst,Point2d P1,Point2d P2,Point2d P3,Point2d P4)
{
    if (img.data)
    {
        Point2f corners[4];//原图四个点
        Point2f corners_trans[4];//逆透视图四个点

        //**车载场景图象的其他参数**//
        float roi_x0=0;
        float roi_y0=228;
        float ROI_HEIGHT=30000;
        float ROI_WIDTH=3750;
        //************************//

        corners[0] = P2;
        corners[1] = P3;
        corners[2] = P1;
        corners[3] = P4;

        //设定逆透视图的宽度
        float IPM_WIDTH=500;
        float N=5;
        //保证逆透视图的宽度大概为N个车头宽
        float sacale=(IPM_WIDTH/N)/ROI_WIDTH;
        float IPM_HEIGHT=ROI_HEIGHT*sacale;

        //逆透视图初始化
        dst=Mat::zeros(IPM_HEIGHT+50,IPM_WIDTH,img.type());
        // dst=Mat::zeros(800,1000,img.type());

        cout << "原图像大小" << img.size() <<endl;
        cout << "变换后图像大小" << dst.size() <<endl;

        corners_trans[0] = Point2f(IPM_WIDTH/2-IPM_WIDTH/(2*N),0);  //P2
        corners_trans[1] = Point2f(IPM_WIDTH/2+IPM_WIDTH/(2*N),0);  //P3
        corners_trans[2] = Point2f(IPM_WIDTH/2-IPM_WIDTH/(2*N),IPM_HEIGHT);   //P1
        corners_trans[3] = Point2f(IPM_WIDTH/2+IPM_WIDTH/(2*N),IPM_HEIGHT);   //P4

        // cout << IPM_WIDTH/2-IPM_WIDTH/(2*N)<<endl;
        // cout << IPM_WIDTH/2+IPM_WIDTH/(2*N)<<endl;
        // cout << IPM_HEIGHT<<endl;
        
        //计算原图到逆透视图和逆透视图到原图的变换矩阵
        Mat warpMatrix_src2ipm;
        warpMatrix_src2ipm = getPerspectiveTransform(corners, corners_trans);
        warpPerspective(img, dst, warpMatrix_src2ipm, dst.size());
        //标出两组点
        for(int i=0;i<4;i++)
            circle(img,corners[i],5,Scalar(0,255,255),4);
        for(int i=0;i<4;i++)
            circle(dst,corners_trans[i],5,Scalar(0,255,255),4);

        imshow("img",img);
        imshow("dst",dst);
        imwrite("../img/result_img.png", img);
        imwrite("../img/result.png", dst);
    }
    else
    {
        cout << "NO IMAGE!!!" << endl;
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    Mat src, dst;

    // 图像1
    src = imread("../img/img1.jpeg");

    Point2d p1(321,250);
    Point2d p2(408,250);
    Point2d p3(241,393);
    Point2d p4(477,393);

    // 图像2
    // src = imread("../python/img2.jpeg");
    // Point2d p1(243,189);
    // Point2d p2(383,186);
    // Point2d p3(77,253);
    // Point2d p4(533,253);

    executeipm(src,dst,p3,p1,p2,p4);
    waitKey(0);
    return 0;
}


