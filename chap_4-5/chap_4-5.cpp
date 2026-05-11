/* 1 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
void on_change(int pos, void* userdata) {                               // 트랙바 콜백 함수 정의(pos: 현재 트랙바 위치)
    cout << "현재 위치: " << pos << endl;                               // 현재 트랙바 위치값 출력
    if (pos > 0)                                                         // 트랙바 위치가 0보다 클 때
        circle(*(Mat*)userdata, Point(250, 250), pos,                   // userdata를 Mat로 변환, 중심(250,250), 반지름 pos의 원을
            Scalar(0, 255, 0), 3);                                       // 초록색(BGR), 두께 3으로 그리기
}                                                                        // 콜백 함수 종료
int main() {                                                             // 메인 함수 선언
    Mat img = imread("C:/Users/tjdwl/source/repos/"                     // 지정된 경로에서d
        "computervision/chap_2-3/lenna.bmp");                           // lenna.bmp를 읽어 img에 저장
    if (img.empty()) return -1;                                          // 이미지 로드 실패 시 -1 반환(비정상종료)
    namedWindow("Lenna");                                                // "Lenna" 이름의 윈도우 생성
    createTrackbar("level", "Lenna", 0, 100, on_change, &img);         // "Lenna" 윈도우에 0~100 범위의 트랙바 생성, img 주소 전달
    while (true) {                                                       // 무한 루프 시작
        imshow("Lenna", img);                                            // "Lenna" 윈도우에 현재 이미지 출력
        if (waitKey(10) == 'q') break;                                  // 10ms 대기 후 'q' 입력 시 루프 종료
    }                                                                    // while 루프 종료
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/

/* 2 번
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
Scalar color(255, 0, 0);                                                 // 현재 사각형 색상을 파란색(BGR)으로 전역 초기화
void on_change(int pos, void* userdata) {                               // 트랙바 콜백 함수 정의(pos: 트랙바 현재 위치)
    Scalar colors[4] = {                                                 // 선택 가능한 4가지 색상 배열 선언
        Scalar(255, 0, 0),                                               // 인덱스 0: 파란색(BGR)
        Scalar(0, 255, 0),                                               // 인덱스 1: 초록색(BGR)
        Scalar(0, 0, 255),                                               // 인덱스 2: 빨간색(BGR)
        Scalar(255, 255, 255) };                                         // 인덱스 3: 흰색(BGR, 채움 모드)
    color = colors[pos];                                                 // 트랙바 위치에 해당하는 색상을 전역 color에 저장
}                                                                        // 콜백 함수 종료
void on_mouse(int event, int x, int y, int flag, void* userdata) {      // 마우스 콜백 함수 정의
    static Point oldpos;                                                 // 마우스 버튼 누름 시작 좌표(정적 변수로 유지)
    Mat& img = *(Mat*)userdata;                                          // userdata를 Mat 참조형으로 변환하여 img에 저장
    if (event == EVENT_LBUTTONDOWN) {                                    // 마우스 왼쪽 버튼 누름 이벤트일 때
        oldpos = Point(x, y);                                           // 클릭 시작 좌표를 oldpos에 저장
    }                                                                    // 조건문 종료
    else if (event == EVENT_LBUTTONUP) {                                 // 마우스 왼쪽 버튼 뗌 이벤트일 때
        rectangle(img, oldpos, Point(x, y), color,                      // 시작점~끝점 범위의 사각형을 현재 color로 그리되
            ((color == Scalar(255, 255, 255)) ? -1 : 1));               // 흰색이면 채움(-1), 아니면 두께 1의 외곽선으로 그리기
    }                                                                    // 조건문 종료
}                                                                        // 콜백 함수 종료
int main() {                                                             // 메인 함수 선언
    Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));                  // 500x500 크기의 흰색 8비트 3채널 Mat 객체 생성
    namedWindow("win");                                                  // "win" 이름의 윈도우 생성
    Scalar color;                                                        // 지역 color 변수 선언(실제 사용은 전역 color)
    createTrackbar("Mode", "win", 0, 3, on_change);                     // "win" 윈도우에 0~3 범위의 트랙바 생성
    setMouseCallback("win", on_mouse, &img);                            // "win" 윈도우에 on_mouse 콜백 등록, img 주소 전달
    while (1) {                                                          // 무한 루프 시작
        imshow("win", img);                                              // "win" 윈도우에 현재 이미지 출력
        if (waitKey(10) == 27) break;                                   // 10ms 대기 후 ESC(27) 입력 시 루프 종료
    }                                                                    // while 루프 종료
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
*/