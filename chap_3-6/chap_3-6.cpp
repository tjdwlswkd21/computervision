/* 1. 사진을 imread 함수를 이용하여 Mat 객체에 저장하고 영상의 행의 수 열의 수 채널수 type 을 화면에 출력하는 코드를 작성하시오 
#include <opencv2/opencv.hpp>                                           // opencv 헤더파일 추가
#include <iostream>                                                     // c++ 헤더파일 추가
#include <string>                                                       // string 헤더파일 추가
using namespace cv;                                                     // cv(opencv) 네임스페이스 생략
using namespace std;                                                    // std(c++) 네임스페이스 생략
string get_type_string(int type) {                                      // Mat 타입을 문자열로 변환하는 함수 선언
    switch (type) {                                                     // type 값에 따라 분기
    case CV_8UC1:  return "CV_8UC1";                                   // 8비트 1채널
    case CV_8UC2:  return "CV_8UC2";                                   // 8비트 2채널
    case CV_8UC3:  return "CV_8UC3";                                   // 8비트 3채널
    case CV_8UC4:  return "CV_8UC4";                                   // 8비트 4채널
    case CV_16UC1: return "CV_16UC1";                                  // 16비트 부호없는 1채널
    case CV_16SC1: return "CV_16SC1";                                  // 16비트 부호있는 1채널
    case CV_32FC1: return "CV_32FC1";                                  // 32비트 실수형 1채널
    case CV_64FC1: return "CV_64FC1";                                  // 64비트 실수형 1채널
    default:       return "Unknown Type";                              // 그 외 타입
    }                                                                   // switch문 종료
}                                                                       // 함수 종료
int main() {                                                            // 메인 함수 선언
    Mat img = imread("C:/Users/tjdwl/source/repos/computervision/chap_2-3/lenna.bmp", IMREAD_UNCHANGED);// 영상을 원본 그대로 읽어 Mat 객체에 저장
    if (img.empty()) {                                                  // 이미지 로드 실패 여부 확인
        cout << "이미지를 불러올 수 없습니다." << endl;                 // 실패 시 에러 메시지 출력
        return -1;                                                      // -1을 반환(비정상종료)
    }                                                                   // 조건문 종료
    cout << "행의 수 (Rows): " << img.rows << endl;                    // 이미지의 행(세로) 크기 출력
    cout << "열의 수 (Cols): " << img.cols << endl;                    // 이미지의 열(가로) 크기 출력
    cout << "채널 수 (Channels): " << img.channels() << endl;         // 이미지의 채널 수 출력
    cout << "타입 (Type): " << get_type_string(img.type()) << endl;   // 이미지의 타입 문자열 출력
    return 0;                                                           // 0을 반환(정상종료)
}                                                                       // 메인함수 종료
*/

/* 2. 행렬연산을 이용하여 아래 수식에서 행렬 X 를 구하는 프로그램을 작성하시오
#include <opencv2/opencv.hpp>                                           // opencv 헤더파일 추가
#include <iostream>                                                     // c++ 헤더파일 추가
using namespace cv;                                                     // cv(opencv) 네임스페이스 생략
using namespace std;                                                    // std(c++) 네임스페이스 생략
int main() {                                                            // 메인 함수 선언
    Mat A = (Mat_<float>(2, 2) << 1, 3, -4, 2);                       // 2x2 float형 행렬 A 선언 및 초기화
    Mat B = (Mat_<float>(2, 2) << 2, 3, 0, 5);                        // 2x2 float형 행렬 B 선언 및 초기화
    Mat C = (Mat_<float>(2, 2) << -2, -2, -2, -3);                    // 2x2 float형 행렬 C 선언 및 초기화
    Mat X = 3 * A + B.inv() + 10 * C - 5;                             // X = 3A + B의역행렬 + 10C - 5 계산
    cout << "Matrix A:\n" << A << "\n" << endl;                        // 행렬 A 출력
    cout << "Matrix B:\n" << B << "\n" << endl;                        // 행렬 B 출력
    cout << "Matrix C:\n" << C << "\n" << endl;                        // 행렬 C 출력
    cout << "Result Matrix X:\n" << X << endl;                         // 결과 행렬 X 출력
    return 0;                                                           // 0을 반환(정상종료)
}                                                                       // 메인함수 종료
*/

/* 3. 행렬 연산을 이용하여 영상의 밝기를 수정하는 프로그램을 작성하시오
#include <iostream>                                                     // c++ 헤더파일 추가
#include <opencv2/opencv.hpp>                                           // opencv 헤더파일 추가
using namespace std;                                                    // std(c++) 네임스페이스 생략
using namespace cv;                                                     // cv(opencv) 네임스페이스 생략
int main(void) {                                                        // 메인 함수 선언
    Mat image = imread("C:/Users/tjdwl/source/repos/"                  // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp"), bright;                  // lenna.bmp를 읽어 image에 저장, bright 객체 선언
    if (image.empty()) {                                                // 이미지 로드 실패 여부 확인
        cerr << "Frame is empty!" << endl; return 1; }                 // 실패 시 에러 메시지 출력 후 종료
    int num;                                                            // 밝기 변화량 변수 선언
    cout << "밝기 변화량을 입력";                                       // 안내문구 출력
    cin >> num;                                                         // 밝기 변화량 입력
    bright = image + Scalar(num, num, num);                            // 모든 채널에 num을 더해 밝기 조절한 이미지 생성
    imshow("original", image);                                         // "original" 윈도우에 원본 이미지 출력
    imshow("bright", bright);                                          // "bright" 윈도우에 밝기 조절 이미지 출력
    waitKey(0);                                                        // 키 입력이 있을 때까지 대기
    return 0;                                                           // 0을 반환(정상종료)
}                                                                       // 메인함수 종료
*/