# IPM_transform
## 一种用于图像逆透视变换的小型应用程序

**22 Nov 2021:** 程序第一次提交，包含Python和C++处理程序

**Author:** zenxan

**Images:** 

### 原图像

<a target="_blank"><img src="https://img-blog.csdnimg.cn/fe695fee9ba04b9d9eb71e2e61024bbc.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBARGFfd2Fu,size_20,color_FFFFFF,t_70,g_se,x_16" 
alt="MAV platform" width="50%" height="50%" border="10" /></a>

### 处理结果

<a target="_blank"><img src="https://img-blog.csdnimg.cn/067d05665cc743c0a7d089513334a16e.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBARGFfd2Fu,size_20,color_FFFFFF,t_70,g_se,x_16" 
alt="MAV platform" width="30%" height="30%" border="10" /></a>

图像已经从正视图转为俯视图

## 1. Prerequisites

1.1 测试环境 **Ubuntu**==18.04， **Opencv**>=3.0 ，**Python**>=3

1.2 其他环境也应该都可以，需要修改部分内容即可

## 2. Build Application

下载程序并编译
```
mkdir workspace
cd workspace
git clone https://github.com/zenxan/IPM_transform.git 或者 git clone git://github.com/zenxan/IPM_transform.git
cd IPM_transform
mkdir build
cd build
cmake ..
make
```

执行C++程序
```
./main
```

执行Python程序
```
cd python
python3 ipm_tran.py 或者 python ipm_tran.py
```

## 3. Change Images

处理的图像保存在img文件夹中，命名为img1.jpeg

可以将需要处理的图片放置该文件夹

## 4. Param Setting

**C++:**

1.在main函数中，路径替换成自身图片路径

2.在main函数中，p1,p2,p3,p4替换成图像中选取的4个点（4个点在现实世界构成一个矩阵）

**Python:**

1.在main函数中，路径替换成自身图片路径

2.在main函数中，pts1中p1,p2,p3,p4替换成图像中选取的4个点（4个点在现实世界构成一个矩阵）

## 5. By the Way

p1:左上 &ensp; &ensp; p2:右上

p3:左下 &ensp; &ensp; p4:右下

