/* 1 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat img(400, 400, CV_8UC1, Scalar(255));                            // 400x400 크기의 흰색(255) 8비트 1채널 Mat 객체 생성
    int left = 100, right = 300, top = 100, bottom = 300;               // 사각형의 좌·우·상·하 좌표값 선언 및 초기화
    rectangle(img, Rect(left, top, right - left, bottom - top),         // img에 (left,top)을 시작점으로 200x200 크기의 사각형을
        Scalar(0), 1);                                                   // 검정색(0), 두께 1로 그리기
    line(img, Point(left, top), Point(right, bottom), Scalar(0), 1);   // 사각형의 좌상단→우하단 대각선을 검정색, 두께 1로 그리기
    line(img, Point(right, top), Point(left, bottom), Scalar(0), 1);   // 사각형의 우상단→좌하단 대각선을 검정색, 두께 1로 그리기
    imshow("src", img);                                                  // "src" 윈도우에 결과 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/

/* 2 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat img = imread("C://Users//tjdwl//source//repos//"                // 지정된 경로에서
        "computervision//chap_2-3//lenna.bmp");                         // lenna.bmp를 읽어 img에 저장
    if (img.empty()) return -1;                                          // 이미지 로드 실패 시 -1 반환(비정상종료)
    int w = img.cols, h = img.rows;                                      // 이미지의 가로(w)·세로(h) 크기 저장
    for (int i = 1; i <= 3; i++)                                        // 가로선 3개를 그리기 위해 1~3 반복
        line(img, Point(0, h * i / 4), Point(w, h * i / 4),            // 이미지를 세로로 4등분하는 수평선의 시작·끝점 지정
            Scalar(255, 255, 255), 1);                                   // 흰색(BGR), 두께 1로 수평선 그리기
    for (int i = 1; i <= 3; i++)                                        // 세로선 3개를 그리기 위해 1~3 반복
        line(img, Point(w * i / 4, 0), Point(w * i / 4, h),            // 이미지를 가로로 4등분하는 수직선의 시작·끝점 지정
            Scalar(255, 255, 255), 1);                                   // 흰색(BGR), 두께 1로 수직선 그리기
    imshow("Line", img);                                                 // "Line" 윈도우에 결과 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/

/* 3 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat img(400, 400, CV_8UC1, Scalar(255));                            // 400x400 크기의 흰색(255) 8비트 1채널 Mat 객체 생성
    Rect rect(100, 100, 200, 200);                                       // (100,100)을 시작점으로 200x200 크기의 Rect 객체 선언
    Point center(200, 200);                                              // 원의 중심점 (200,200) 선언
    int radius = 100;                                                    // 원의 반지름 100 선언
    rectangle(img, rect, Scalar(0), 1);                                 // img에 rect 영역을 검정색, 두께 1로 사각형 그리기
    circle(img, center, radius, Scalar(0), 1, LINE_AA);                 // img에 중심·반지름 기준으로 검정색, 두께 1, 안티앨리어싱으로 원 그리기
    imshow("src", img);                                                  // "src" 윈도우에 결과 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/

/* 4 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
using namespace std;                                                     // std(c++) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat img = imread("C://Users//tjdwl//source//repos//"                // 지정된 경로에서
        "computervision//chap_2-3//lenna.bmp");                         // lenna.bmp를 읽어 img에 저장
    if (img.empty()) {                                                   // 이미지 로드 실패 여부 확인
        cerr << "Lenna image load failed!" << endl; return -1; }        // 실패 시 에러 메시지 출력 후 -1 반환(비정상종료)
    Point center(220, 210);                                              // 원의 중심점 (220,210) 선언
    int radius = 170;                                                    // 원의 반지름 170 선언
    circle(img, center, radius, Scalar(255, 0, 0), 2, LINE_AA);        // img에 파란색(BGR), 두께 2, 안티앨리어싱으로 원 그리기
    imshow("image", img);                                                // "image" 윈도우에 결과 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/

/* 5 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat img(200, 600, CV_8UC3, Scalar(0, 0, 0));                        // 200x600 크기의 검정색 8비트 3채널 Mat 객체 생성
    Mat roi1 = img(Rect(0, 0, 200, 200));                               // img의 좌측 200x200 영역을 roi1으로 설정
    Mat roi2 = img(Rect(200, 0, 200, 200));                             // img의 중앙 200x200 영역을 roi2로 설정
    Mat roi3 = img(Rect(400, 0, 200, 200));                             // img의 우측 200x200 영역을 roi3으로 설정
    roi1.setTo(Scalar(255, 0, 0));                                       // roi1을 파란색(BGR)으로 채우기
    roi2.setTo(Scalar(0, 255, 0));                                       // roi2를 초록색(BGR)으로 채우기
    roi3.setTo(Scalar(0, 0, 255));                                       // roi3을 빨간색(BGR)으로 채우기
    Scalar w(255, 255, 255);                                             // 흰색(BGR) Scalar 객체 w 선언
    rectangle(roi1, Rect(50, 50, 100, 100), w, 5);                      // roi1에 흰색, 두께 5로 100x100 사각형 그리기
    circle(roi2, Point(100, 100), 50, w, 5);                            // roi2의 중심(100,100)에 흰색, 두께 5, 반지름 50의 원 그리기
    line(roi3, Point(50, 50), Point(150, 150), w, 5);                   // roi3에 좌상단→우하단 대각선을 흰색, 두께 5로 그리기
    line(roi3, Point(150, 50), Point(50, 150), w, 5);                   // roi3에 우상단→좌하단 대각선을 흰색, 두께 5로 그리기
    imshow("img", img);                                                  // "img" 윈도우에 결과 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/

/* 6 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat img = imread("C://Users//tjdwl//source//repos//"                // 지정된 경로에서
        "computervision//chap_2-3//lenna.bmp");                         // lenna.bmp를 읽어 img에 저장
    if (img.empty()) return -1;                                          // 이미지 로드 실패 시 -1 반환(비정상종료)
    std::string text = "Hello, Lenna";                                   // 출력할 문자열 선언
    int fontFace = FONT_HERSHEY_SIMPLEX;                                 // 폰트 종류를 HERSHEY_SIMPLEX로 지정
    double fontScale = 1.2;                                              // 폰트 크기 배율 1.2 지정
    int thickness = 2;                                                   // 텍스트 두께 2 지정
    int baseline = 0;                                                    // 텍스트 베이스라인 오프셋 변수 선언(0으로 초기화)
    Size textSize = getTextSize(text, fontFace,                         // 지정한 폰트·배율·두께 기준으로
        fontScale, thickness, &baseline);                                // 텍스트의 가로·세로 크기와 베이스라인 값 계산
    Point textOrg((img.cols - textSize.width) / 2, 50);                 // 텍스트를 가로 중앙 정렬, y=50 위치에 출력할 시작점 계산
    putText(img, text, textOrg, fontFace, fontScale,                    // img에 text를 지정한 폰트·크기로
        Scalar(0, 255, 255), thickness);                                 // 노란색(BGR), 두께 2로 텍스트 그리기
    imshow("image", img);                                                // "image" 윈도우에 결과 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/

/* 7 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat img(300, 300, CV_8UC3, Scalar(255, 255, 255));                  // 300x300 크기의 흰색 8비트 3채널 Mat 객체 생성
    int count = 0, isRunning = 0;                                        // 카운트 변수(0)와 실행 상태 변수(0=정지) 선언
    while (true) {                                                       // 무한 루프 시작
        img.setTo(Scalar(255, 255, 255));                                // 매 프레임마다 이미지를 흰색으로 초기화
        std::string text = format("%d", count);                          // 현재 count 값을 문자열로 변환
        int base;                                                        // 텍스트 베이스라인 오프셋 변수 선언
        Size sz = getTextSize(text, FONT_HERSHEY_SIMPLEX,               // HERSHEY_SIMPLEX 폰트, 크기 3, 두께 5 기준으로
            3, 5, &base);                                                // 텍스트의 가로·세로 크기 계산
        putText(img, text,                                               // img에 count 문자열을
            Point((300 - sz.width) / 2, (300 + sz.height) / 2),        // 이미지 중앙에 배치될 시작점 계산 후
            FONT_HERSHEY_SIMPLEX, 3, Scalar(0, 0, 0), 5);              // HERSHEY_SIMPLEX 폰트, 크기 3, 검정색, 두께 5로 출력
        imshow("Stopwatch", img);                                        // "Stopwatch" 윈도우에 현재 프레임 출력
        int key = waitKey(1000);                                         // 1초(1000ms) 대기 후 키 입력 저장
        if (key == 's') isRunning = 1;                                  // 's' 입력 시 카운트 시작(isRunning=1)
        else if (key == 't') isRunning = 0;                             // 't' 입력 시 카운트 정지(isRunning=0)
        else if (key == 'r') { count = 0; isRunning = 0; }             // 'r' 입력 시 카운트 초기화 및 정지
        else if (key == 'q') break;                                     // 'q' 입력 시 루프 종료
        if (isRunning) count = (count + 1) % 10;                        // 실행 중이면 count를 1 증가(0~9 순환)
    }                                                                    // while 루프 종료
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/

/* 8 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));                  // 500x500 크기의 흰색 8비트 3채널 Mat 객체 생성
    int x = 2, y = 2, sz = 100;                                         // 현재 셀 위치(x=2,y=2)와 셀 크기(sz=100) 초기화
    while (true) {                                                       // 무한 루프 시작
        for (int i = 0; i <= 500; i += sz) {                            // 0~500 범위에서 sz(100) 간격으로 반복
            line(img, Point(i, 0), Point(i, 500), Scalar(200, 200, 200)); // 수직 격자선을 회색으로 그리기
            line(img, Point(0, i), Point(500, i), Scalar(200, 200, 200)); // 수평 격자선을 회색으로 그리기
        }                                                                // 격자선 그리기 반복문 종료
        img(Rect(x * sz, y * sz, sz, sz)).setTo(Scalar(255, 0, 0));    // 현재 (x,y) 위치의 셀을 파란색으로 채우기
        imshow("Grid", img);                                             // "Grid" 윈도우에 현재 상태 출력
        int key = waitKey(0);                                            // 키 입력이 있을 때까지 대기 후 저장
        img(Rect(x * sz, y * sz, sz, sz)).setTo(Scalar(255, 255, 255)); // 이동 전 현재 셀을 흰색으로 초기화
        if (key == 'w' && y > 0) y--;                                   // 'w' 입력 & 위쪽 경계 아닐 때 y 감소(위로 이동)
        else if (key == 's' && y < 4) y++;                              // 's' 입력 & 아래쪽 경계 아닐 때 y 증가(아래로 이동)
        else if (key == 'a' && x > 0) x--;                              // 'a' 입력 & 왼쪽 경계 아닐 때 x 감소(왼쪽 이동)
        else if (key == 'd' && x < 4) x++;                              // 'd' 입력 & 오른쪽 경계 아닐 때 x 증가(오른쪽 이동)
        else if (key == 'q') break;                                     // 'q' 입력 시 루프 종료
    }                                                                    // while 루프 종료
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/

/* 9 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));                  // 500x500 크기의 흰색 8비트 3채널 Mat 객체 생성
    Point pt(250, 250);                                                  // 현재 위치를 이미지 중앙 (250,250)으로 초기화
    while (true) {                                                       // 무한 루프 시작
        imshow("Draw Line", img);                                        // "Draw Line" 윈도우에 현재 이미지 출력
        int key = waitKey(0);                                            // 키 입력이 있을 때까지 대기 후 저장
        if (key == 'q') break;                                          // 'q' 입력 시 루프 종료
        Point next_pt = pt;                                              // 다음 이동 위치를 현재 위치로 초기화
        if (key == 'a' && pt.x >= 50) next_pt.x -= 50;                 // 'a' 입력 & 왼쪽 경계(50) 아닐 때 x를 50 감소(왼쪽 이동)
        else if (key == 'w' && pt.y >= 50) next_pt.y -= 50;            // 'w' 입력 & 위쪽 경계(50) 아닐 때 y를 50 감소(위로 이동)
        else if (key == 'd' && pt.x <= 450) next_pt.x += 50;           // 'd' 입력 & 오른쪽 경계(450) 아닐 때 x를 50 증가(오른쪽 이동)
        else if (key == 's' && pt.y <= 450) next_pt.y += 50;           // 's' 입력 & 아래쪽 경계(450) 아닐 때 y를 50 증가(아래로 이동)
        if (pt != next_pt) {                                             // 위치가 실제로 이동했을 때만
            line(img, pt, next_pt, Scalar(0, 0, 0), 2);                // 이전 위치에서 새 위치까지 검정색, 두께 2로 선 그리기
            pt = next_pt;                                               // 현재 위치를 새 위치로 업데이트
        }                                                                // 조건문 종료
    }                                                                    // while 루프 종료
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/