# 1. 카메라로 촬영한 컬러영상의 R,G,B 값 모두 100 만큼 증가시킨 후 원본과 결과영상을 모두 출력하라

``` cpp
#include <iostream>                                                     // c++ 헤더파일 추가
#include <opencv2/opencv.hpp>                                           // opencv 헤더파일 추가
using namespace std;                                                    // std(c++) 네임스페이스 생략
using namespace cv;                                                     // cv(opencv) 네임스페이스 생략
int main(void) {                                                        // 메인 함수 선언
    VideoCapture cap(2);                                                // 2번 카메라 장치 열기
    if (!cap.isOpened()) {                                              // 카메라 열기 실패 여부 확인
        cerr << "Camera open failed!" << endl; return 1; }             // 실패 시 에러 메시지 출력 후 종료
    Mat frame, bright;                                                  // 원본 프레임, 밝기 조절 프레임 Mat 객체 선언
    cap >> frame;                                                       // 카메라로부터 한 프레임 받아오기
    if (frame.empty()) {                                                // 프레임이 비어있는지 확인
        cerr << "Frame is empty!" << endl; return 1; }                 // 비어있을 시 에러 메시지 출력 후 종료
    bright = frame + Scalar(100, 100, 100);                            // 모든 채널에 100을 더해 밝기 증가
    imshow("original", frame);                                         // "original" 윈도우에 원본 프레임 출력
    imshow("bright", bright);                                          // "bright" 윈도우에 밝기 조절 프레임 출력
    waitKey(0);                                                        // 키 입력이 있을 때까지 대기
    return 0;                                                          // 0을 반환(정상종료)
}                                                                      // 메인함수 종료
```
![실행결과](./4-1_1.png)


# 2. 카메라로 촬영한 영상을 화면에 출력하라 Q 또는 q 를 누르면 종료, s 를 누를때마다 현재 프레임을 파일로 저장하라

```cpp
#include <iostream>                                                     // c++ 헤더파일 추가
#include <opencv2/opencv.hpp>                                           // opencv 헤더파일 추가
using namespace std;                                                    // std(c++) 네임스페이스 생략
using namespace cv;                                                     // cv(opencv) 네임스페이스 생략
int main(void) {                                                        // 메인 함수 선언
    VideoCapture cap(2);                                                // 2번 카메라 장치 열기
    if (!cap.isOpened()) {                                              // 카메라 열기 실패 여부 확인
        cerr << "Camera open failed!" << endl;                         // 실패 시 에러 메시지 출력
        return 1;                                                       // 1을 반환(비정상종료)
    }                                                                   // 조건문 종료
    Mat frame;                                                          // 프레임 저장용 Mat 객체 선언
    int cnt = 0;                                                        // 저장된 프레임 개수 카운터 초기화
    while (true) {                                                      // 무한 반복
        cap >> frame;                                                   // 카메라로부터 한 프레임 받아오기
        if (frame.empty()) {                                            // 프레임이 비어있는지 확인
            cerr << "Frame is empty!" << endl;                         // 비어있을 시 에러 메시지 출력
            break;                                                      // 반복문 종료
        }                                                               // 조건문 종료
        imshow("frame", frame);                                        // "frame" 윈도우에 현재 프레임 출력
        int key = waitKey(30);                                         // 30ms 대기 후 키 입력값 저장
        if (key == 'q' || key == 'Q') {                                // q 또는 Q 키 입력 시
            break;                                                      // 반복문 종료
        } else if (key == 's') {                                       // s 키 입력 시
            String filename = format("frame%02d.jpg", cnt++);          // 프레임 번호로 파일명 생성 후 cnt 증가
            imwrite(filename, frame);                                   // 현재 프레임을 파일로 저장
        }                                                               // 조건문 종료
    }                                                                   // 반복문 종료
    destroyAllWindows();                                                // 모든 윈도우 닫기
    return 0;                                                           // 0을 반환(정상종료)
}                                                                       // 메인함수 종료
```
![실행결과](./4-1_2.png)

# 3. 카메라로 촬영한 영상을 q 를 누르면 종료하라 새로운 창에 빨간 십자선을 더해 출력하라

```cpp
#include <iostream>                                                     // c++ 헤더파일 추가
#include <opencv2/opencv.hpp>                                           // opencv 헤더파일 추가
using namespace std;                                                    // std(c++) 네임스페이스 생략
using namespace cv;                                                     // cv(opencv) 네임스페이스 생략
int main(void) {                                                        // 메인 함수 선언
    VideoCapture cap(2);                                                // 2번 카메라 장치 열기
    if (!cap.isOpened()) {                                              // 카메라 열기 실패 여부 확인
        cerr << "Camera open failed!" << endl;                         // 실패 시 에러 메시지 출력
        return 1;                                                       // 1을 반환(비정상종료)
    }                                                                   // 조건문 종료
    Mat frame, cross;                                                   // 원본 프레임, 십자선 프레임 Mat 객체 선언
    Vec3b mask(0, 0, 255);                                             // 빨간색(B:0 G:0 R:255) Vec3b 객체 선언
    int cnt = 0;                                                        // 카운터 변수 초기화
    while (true) {                                                      // 무한 반복
        cap >> frame;                                                   // 카메라로부터 한 프레임 받아오기
        if (frame.empty()) {                                            // 프레임이 비어있는지 확인
            cerr << "Frame is empty!" << endl;                         // 비어있을 시 에러 메시지 출력
            break;                                                      // 반복문 종료
        }                                                               // 조건문 종료
        frame.copyTo(cross);                                           // 원본 프레임을 cross에 복사
        cross.col(cross.cols / 2).setTo(Scalar(0, 0, 255));           // cross의 가운데 열을 빨간색 세로선으로 설정
        cross.row(cross.rows / 2).setTo(Scalar(0, 0, 255));           // cross의 가운데 행을 빨간색 가로선으로 설정
        imshow("frame", frame);                                        // "frame" 윈도우에 원본 프레임 출력
        imshow("cross", cross);                                        // "cross" 윈도우에 십자선 프레임 출력
        int key = waitKey(30);                                         // 30ms 대기 후 키 입력값 저장
        if (key == 'q') {                                              // q 키 입력 시
            break;                                                      // 반복문 종료
        }                                                               // 조건문 종료
    }                                                                   // 반복문 종료
    destroyAllWindows();                                                // 모든 윈도우 닫기
    return 0;                                                           // 0을 반환(정상종료)
}                                                                       // 메인함수 종료
```
![실행결과](./4-1_3.png)