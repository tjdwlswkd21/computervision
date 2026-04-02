# 1. 멀티미디어 및 비디오 처리 관련 용어 정리

## 1. API (Application Programming Interface)
**정의:** 응용 프로그램에서 운영체제나 라이브러리의 기능을 사용할 수 있도록 미리 정해놓은 함수나 통신 규약이다.
**역할:** 개발자가 하드웨어 내부 동작을 몰라도 특정 기능을 쉽게 구현할 수 있게 돕는 징검다리 역할을 한다.

## 2. V4L (Video4Linux)
**정의:** 리눅스 시스템에서 실시간 비디오 캡처를 지원하기 위한 디바이스 드라이버 및 API 세트이다.
**역할:** 현재는 웹캠, TV 튜너 등 다양한 장치를 지원하는 V4L2가 표준으로 사용된다.

## 3. FFMPEG
**정의:** 디지털 오디오와 비디오를 기록, 변환, 스트리밍하는 오픈 소스 멀티미디어 프레임워크다.
**역할:** 거의 모든 종류의 코덱과 포맷을 지원하며, 영상 편집 소프트웨어나 플레이어의 핵심 엔진으로 쓰인다.

## 4. DirectShow
**정의:** 윈도우 기반 매체에서 멀티미디어 스트림을 조작하기 위해 마이크로소프트가 개발한 이전 세대 API다.
**역할:** 필터 단위를 연결하여 데이터를 처리하며, 오래된 웹캠과의 호환성을 위해 여전히 사용된다.

## 5. MSMF (Microsoft Media Foundation)
**정의:** DirectShow를 대체하기 위해 마이크로소프트가 도입한 차세대 멀티미디어 플랫폼이다.
**역할:** 고해상도 콘텐츠 처리 및 하드웨어 가속 성능을 더 효율적으로 지원한다.

## 6. GStreamer
**정의:** 다양한 멀티미디어 구성 요소를 연결하여 파이프라인을 구축하는 오픈 소스 프레임워크다.
**역할:** 리눅스 표준으로 주로 쓰이며, 오디오/비디오 재생 및 스트리밍에 매우 유연한 구조를 가지고 있다.

# 2. 카메라로 촬영한 컬러영상의 R,G,B 값 모두 100 만큼 증가시킨 후 원본과 결과영상을 모두 출력하라

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


# 3. 카메라로 촬영한 영상을 화면에 출력하라 Q 또는 q 를 누르면 종료, s 를 누를때마다 현재 프레임을 파일로 저장하라

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

# 4. 카메라로 촬영한 영상을 q 를 누르면 종료하라 새로운 창에 빨간 십자선을 더해 출력하라

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