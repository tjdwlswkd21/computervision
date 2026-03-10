#include <opencv2/opencv.hpp>   // opencv 헤더파일 포함
#include <iostream>             // c++ 헤더파일 포함
using namespace cv;             // cv 이름영역 생략
using namespace std;            // std 이름영역 생략
int main() {                    // 메인함수 선언
    cout << "Hello OpenCV " << CV_VERSION << endl;  // 문자열, cv버전 출력
    Mat img = imread("my_face.png");                // Mat 객체 img 선언, 이미지 파일 읽어오기 후 저장
    if (img.empty()) {                              // img객체에 데이터가 없으면 아래 코드 블록 실행
        cerr << "Image load failed!" << endl;       // 이미지 로드 오류 안내문자열 출력
        return -1;              // 비정상 종료
    }                           // 조건문 종료
    namedWindow("image");       // image 라는 이름의 영상을 출력할 윈도우 생성
    imshow("image", img);       // 윈도우에 영상 출력
    waitKey(0);                 // 아무 키가 입력될 때까지 현재 상태로 대기
    return 0;                   // 정상 종료
}                               // 메인함수 종료