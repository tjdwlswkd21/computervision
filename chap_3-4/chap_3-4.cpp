/* 2 번
#include "opencv2/opencv.hpp"                           // opencv 헤더파일 추가
#include <iostream>                                     // c++ 헤더파일 추가
using namespace cv;                                     // cv(opencv) 네임스페이스 생략
using namespace std;                                    // std(c++) 네임스페이스 생략
int main() {                                            // 메인 함수 선언
    Mat img1 = (Mat_<int>(3, 5) <<                      // 3행 5열의 int형 Mat 객체 선언
        1, 2, 3, 4, 5,                                  // 1행 데이터 초기화
        6, 7, 8, 9, 10,                                 // 2행 데이터 초기화
        11, 12, 13, 14, 15);                            // 3행 데이터 초기화
    Mat img2 = img1(Rect(2, 1, 3, 2)).clone();          // img1의 (2,1)에서 가로3 세로2 크기의 부분행렬을 복사하여 img2에 저장
    cout << "img1:\n" << img1 << "\nimg2:\n" << img2 << endl;// img1, img2 출력
    return 0;                                           // 0을 반환(정상종료)
}                                                       // 메인함수 종료
*/

/* 3 번 
#include "opencv2/opencv.hpp"                           // opencv 헤더파일 추가
#include <iostream>                                     // c++ 헤더파일 추가
using namespace cv;                                     // cv(opencv) 네임스페이스 생략
using namespace std;                                    // std(c++) 네임스페이스 생략
int main() {                                            // 메인 함수 선언
    Mat img1 = imread("dog.bmp");                       // dog.bmp 이미지 파일을 읽어 Mat 객체에 저장
    if (img1.empty()) {                                 // 이미지 로드 실패 여부 확인
        cout << "Image load failed!" << endl; return 1;}// 실패 시 에러 메시지 출력 후 종료
    Rect roi(100, 40, 80, 80);                          // (100,40)에서 가로80 세로80 크기의 관심영역(ROI) 설정
    img1(roi).setTo(Scalar(255, 0, 0));                 // 관심영역을 파란색(B:255 G:0 R:0)으로 설정
    imshow("Color Window", img1);                       // "Color Window" 이름의 윈도우에 img1 출력
    waitKey(0);                                         // 키 입력이 있을 때까지 대기
    return 0;                                           // 0을 반환(정상종료)
}                                                       // 메인함수 종료
*/

/* 4 번
#include "opencv2/opencv.hpp"                           // opencv 헤더파일 추가
#include <iostream>                                     // c++ 헤더파일 추가
using namespace cv;                                     // cv(opencv) 네임스페이스 생략
using namespace std;                                    // std(c++) 네임스페이스 생략
int main() {                                            // 메인 함수 선언
    Mat img1 = imread("dog.bmp");                       // dog.bmp 이미지 파일을 읽어 Mat 객체에 저장
    if (img1.empty()) {                                 // 이미지 로드 실패 여부 확인
        cout << "Image load failed!" << endl; return 1;}// 실패 시 에러 메시지 출력 후 종료
    Rect roi(100, 40, 80, 80);                          // (100,40)에서 가로80 세로80 크기의 관심영역(ROI) 설정
    Mat imgcopy[2] = { img1(roi).clone(),               // imgcopy[0]에 원본 관심영역을 복사하여 저장
        Mat(roi.height, roi.width,                      // imgcopy[1]에 관심영역과 동일한 크기의 Mat 객체 생성
        CV_8UC3, Scalar(255, 0, 0)) };                  // imgcopy[1]을 파란색(B:255 G:0 R:0)으로 초기화
    int i = 0;                                          // 반복 횟수 카운터 변수 초기화
    while (true) {                                      // 무한 반복
        imgcopy[i % 2].copyTo(img1(roi));               // i가 짝수면 원본, 홀수면 파란색 이미지를 관심영역에 복사
        imshow("Color Window", img1);                   // "Color Window" 이름의 윈도우에 img1 출력
        if (waitKey(1000) == 'q') break;                // 1초 대기 후 q 키 입력 시 반복문 종료
        i++;                                            // 반복 횟수 1 증가
    }                                                   // 반복문 종료
    return 0;                                           // 0을 반환(정상종료)
}                                                       // 메인함수 종료
*/

/* 5 번
#include "opencv2/opencv.hpp"                           // opencv 헤더파일 추가
#include <iostream>                                     // c++ 헤더파일 추가
using namespace cv;                                     // cv(opencv) 네임스페이스 생략
using namespace std;                                    // std(c++) 네임스페이스 생략
int main() {                                            // 메인 함수 선언
    int x = 0, l = 200;                                 // 사각형의 시작 x좌표와 한 변의 길이 초기화
    Mat img(200, 600, CV_8UC3, Scalar(255, 255, 255));  // 200x600 크기의 흰색 배경 Mat 객체 생성
    while (true) {                                      // 무한 반복
        img.setTo(Scalar(255, 255, 255));               // 매 반복마다 배경을 흰색으로 초기화
        img(Rect(x%600, 0, l, l)).setTo(Scalar(0,0,255));// x%600 위치에 200x200 크기의 빨강 사각형 출력
        imshow("Display", img);                         // "Display" 이름의 윈도우에 img 출력
        if (waitKey(1000) == 'q') break;                // 1초 대기 후 q 키 입력 시 반복문 종료
        x += 200;                                       // x 좌표를 200만큼 이동
        cout << x;                                      // 현재 x 좌표값 출력
    }                                                   // 반복문 종료
    return 0;                                           // 0을 반환(정상종료)
}                                                       // 메인함수 종료
*/

/* 6 번
#include "opencv2/opencv.hpp"                           // opencv 헤더파일 추가
#include <iostream>                                     // c++ 헤더파일 추가
using namespace cv;                                     // cv(opencv) 네임스페이스 생략
using namespace std;                                    // std(c++) 네임스페이스 생략
int main() {                                            // 메인 함수 선언
    Mat img1 = imread("C:/Users/tjdwl/source/repos/"   // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp");           // lenna.bmp 이미지 파일을 읽어 Mat 객체에 저장
    if (img1.empty()) {                                 // 이미지 로드 실패 여부 확인
        cout << "Image load failed!" << endl; return 1; // 실패 시 에러 메시지 출력 후 종료
    }                                                   // 조건문 종료
    int x, y, h, w, dc;                                // 관심영역 좌표, 크기, 픽셀 변화량 변수 선언
    cout << "관심영역의 좌측상단좌표(x, y):";           // 안내문구 출력
    cin >> x >> y;                                      // 관심영역 시작 좌표 x, y값 입력
    cout << "관심영역의 폭, 높이";                      // 안내문구 출력
    cin >> w >> h;                                      // 관심영역의 가로(w), 세로(h)값 입력
    cout << "픽셀변화량";                               // 안내문구 출력
    cin >> dc;                                          // 픽셀 밝기 변화량 입력
    Rect roi(x, y, w, h);                              // 입력받은 값으로 관심영역(ROI) 설정
    img1(roi) += Scalar(dc, dc, dc);                    // 관심영역의 모든 채널 픽셀값을 dc만큼 증가
    imshow("Color Window", img1);                       // "Color Window" 이름의 윈도우에 img1 출력
    waitKey(0);                                         // 키 입력이 있을 때까지 대기
    return 0;                                           // 0을 반환(정상종료)
}                                                       // 메인함수 종료
*/