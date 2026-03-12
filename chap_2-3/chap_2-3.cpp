/*
// 1¹ø
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main() {
    cout << "Hello OpenCV " << CV_VERSION << endl;
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return 1;
    }
    img += 100;
    imwrite("bright.bmp", img);
    img = imread("bright.bmp", IMREAD_GRAYSCALE);
    imshow("bright_image", img);
    waitKey(0);
    return 0;
}

// 2¹ø
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main() {
    cout << "Hello OpenCV " << CV_VERSION << endl;
    for (int i = 1; i < 4; i++) {
        string filename = to_string(i) + ".png";
        Mat img = imread(filename, IMREAD_GRAYSCALE);
        imshow("bright_image", img);
        waitKey(1000);
    }
    return 0;
}
*/
// 3¹ø
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main() {
    cout << "Hello OpenCV " << CV_VERSION << endl;
    Mat img[10];
    for (int i = 0; i < 10; i++) {
        string filename = to_string(i) + ".png";
        img[i] = imread(filename, IMREAD_GRAYSCALE);
    }
    int i = 0;
    while(true) {
        imshow("bright_image", img[i++ % 10]);
        int x = waitKey(500);
        if (x == 'q') break;
    }
    return 0;
}
