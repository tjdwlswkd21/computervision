/* 1¹ø
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
Mat getGrayHistImage(const Mat& hist) {
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));
    double histMax;
    minMaxLoc(hist, 0, &histMax);
    Mat imgHist(100, 256, CV_8UC1, Scalar(255));
    for (int i = 0; i < 256; i++) {
        line(imgHist,
            Point(i, 100),
            Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)),
            Scalar(0));
    }
    return imgHist;
}
Mat calcGrayHist(const Mat& img) {
    CV_Assert(img.type() == CV_8UC1);
    Mat hist;
    int channels[] = { 0 };
    int dims = 1;
    const int histSize[] = { 256 };
    float graylevel[] = { 0, 256 };
    const float* ranges[] = { graylevel };
    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
    return hist;
}
int main() {
    Mat src = imread("C:/Users/tjdwl/source/repos/computervision/crayfish.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "Image load failed!" << endl;
        return -1;
    }
    Mat dst;
    normalize(src, dst, 0, 255, NORM_MINMAX);
    Mat histSrc = calcGrayHist(src);
    Mat histDst = calcGrayHist(dst);
    Mat imgHistSrc = getGrayHistImage(histSrc);
    Mat imgHistDst = getGrayHistImage(histDst);
    imshow("src", src);
    imshow("srcHist", imgHistSrc);
    imshow("dst (Stretching)", dst);
    imshow("dstHist", imgHistDst);
    waitKey(0);
    return 0;
}
*/

/* 2¹ø
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
Mat getGrayHistImage(const Mat& hist) {
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));

    double histMax;
    minMaxLoc(hist, 0, &histMax);

    Mat imgHist(100, 256, CV_8UC1, Scalar(255));
    for (int i = 0; i < 256; i++) {
        line(imgHist,
            Point(i, 100),
            Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)),
            Scalar(0));
    }
    return imgHist;
}
Mat calcGrayHist(const Mat& img) {
    CV_Assert(img.type() == CV_8UC1);
    Mat hist;
    int channels[] = { 0 };
    int dims = 1;
    const int histSize[] = { 256 };
    float graylevel[] = { 0, 256 };
    const float* ranges[] = { graylevel };

    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
    return hist;
}
int main() {
    Mat src = imread("C:/Users/tjdwl/source/repos/computervision/crayfish.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "Image load failed!" << endl;
        return -1;
    }
    Mat dst;
    equalizeHist(src, dst);
    Mat histSrc = calcGrayHist(src);
    Mat histDst = calcGrayHist(dst);
    Mat imgHistSrc = getGrayHistImage(histSrc);
    Mat imgHistDst = getGrayHistImage(histDst);
    imshow("src", src);
    imshow("srcHist", imgHistSrc);
    imshow("dst (Equalization)", dst);
    imshow("dstHist", imgHistDst);
    waitKey(0);
    return 0;
}
*/