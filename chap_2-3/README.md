# 1. 기존 영상을 불러와 밝기를 100 증가시킨 후 저장하고 윈도우에 출력하라.

``` cpp
#include "opencv2/opencv.hpp"   // opencv 헤더파일 추가
#include <iostream>             // c++ 헤더파일 추가
using namespace cv;             // cv(opencv) 네임스페이스 생략
using namespace std;            // std(c++) 네임스페이스 생략
int main() {                    // 메인 함수 선언
    cout << "Hello OpenCV " << CV_VERSION << endl;  // 문자열 + opencv버전 출력
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);// 이미지 파일 변수로 불러오기
    if (img.empty()) {                              // 이미지 파일 로드 실패 시 실행
        cerr << "Image load failed!" << endl;       // 안내문구 출력
        return 1;               // 비정상 종료
    }                           // 조건문 블록 종료
    img += 100;                 // 이미지 파일의 밝기 100 추가
    imwrite("bright.bmp", img); // 새로운 파일로 저장
    img = imread("bright.bmp", IMREAD_GRAYSCALE);   // 밝아진 영상 불러오기
    imshow("bright_image", img);// 밝아진 영상 출력
    waitKey(0);                 // 아무 키가 입력될 때까지 현재 상태 유지
    return 0;                   // 정상 종료
}                               // 메인 함수 종료
```

![실행결과](./bright.bmp)

# 2. 1초 간격으로 3개의 영상을 차례대로 출력하라

``` cpp
#include "opencv2/opencv.hpp"   // opencv 헤더파일 추가
#include <iostream>             // c++ 헤더파일 추가
using namespace cv;             // cv(opencv) 네임스페이스 생략
using namespace std;            // std(c++) 네임스페이스 생략
int main() {                    // 메인 함수 선언
    cout << "Hello OpenCV " << CV_VERSION << endl;  // 문자열 + opencv버전 출력
    for (int i = 1; i < 4; i++) {                   // 4번 반복
        string filename = to_string(i) + ".png";    // i번째 영상 점근용 파일이름 작성 (i.png)
        Mat img = imread(filename, IMREAD_GRAYSCALE);// 영상 불러오기
        if (img.empty()) {                          // 이미지 파일 로드 실패 시 실행
            cerr << "Image load failed!" << endl;   // 안내문구 출력
            return 1;           // 비정상 종료
        }                       // 조건문 블록 종료
        imshow("image", img);   // 영상 출력
        waitKey(1000);          // 1000ms 대기 중간에 다른 키 입력될 경우 반환값 버림.
    }                           // 반복문 종료
    return 0;                   // 정상 종료
}                               // 메인 함수 종료
```

https://github.com/user-attachments/assets/eb19e4e1-2f1c-416e-89ff-28a7e6e6c293

# 3. 0부터 9가 적혀있는 이미지를 순자적으로 1초마다 순회하다가 q를 입력받으면 중료하라

```cpp
#include "opencv2/opencv.hpp"   // opencv 헤더파일 추가
#include <iostream>             // c++ 헤더파일 추가
using namespace cv;             // cv(opencv) 네임스페이스 생략
using namespace std;            // std(c++) 네임스페이스 생략
int main() {                    // 메인 함수 선언
    cout << "Hello OpenCV " << CV_VERSION << endl;  // 문자열 + opencv버전 출력
    Mat img[10];                                    // 영상을 담을 객체 mat 배열 선언
    for (int i = 0; i < 10; i++) {                  // 10번 반복
        string filename = to_string(i) + ".png";    // i번째 영상 접근용 파일이름 작성 (i.png)
        img[i] = imread(filename, IMREAD_GRAYSCALE);// 영상 불러오기
        if (img.empty()) {                          // 이미지 파일 로드 실패 시 실행
            cerr << "Image load failed!" << endl;   // 안내문구 출력
            return 1;                               // 비정상 종료
        }                                           // 조건문 블록 종료
    }                                               // 반복문 종료
    int i = 0;                                      // 출력할 영상의 인덱스 초기화
    while(true) {                                   // 무한루프
        imshow("bright_image", img[i++ % 10]);      // 0부터 9까지 반복순회
        int x = waitKey(500);   // 500ms 대기, 대기중 특정 문자('q') 입력 시 변수에 저장
        if (x == 'q') break;    // 문자 'q' 가 입력될 경우 반복문 탈출
    }                           // 반복문 종료
    return 0;                   // 정상 종료
}                               // 메인 함수 종료
```

https://github.com/user-attachments/assets/eaf19c0a-1c7b-4e78-ab16-552e8d62b099