# 1. 기존 영상을 불러와 밝기를 100 증가시킨 후 저장하고 윈도우에 출력하라.

``` cpp
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
```

![실행결과](./bright.bmp)

# 2. 1초 간격으로 3개의 영상을 차례대로 출력하라

``` cpp
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
```

<video src="./3_pic.mp4" controls style="max-width: 100%;"></video>

# 3. 0부터 9가 적혀있는 이미지를 순자적으로 1초마다 순회하다가 q를 입력받으면 중료하라

```cpp
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
        int x = waitKey(1000);
        if (x == 'q') break;
    }
    return 0;
}
```

<video src="./10_pic_loop.mp4" controls style="max-width: 100%;"></video>