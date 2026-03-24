/* 1 번 
#include "opencv2/opencv.hpp"		        	    // opencv 헤더파일 추가
#include <iostream>             	        	    // c++ 헤더파일 추가
using namespace cv;             	        	    // cv(opencv) 네임스페이스 생략
using namespace std;            	        	    // std(c++) 네임스페이스 생략
int main() {						        	    // 메인 함수 선언
    Mat mat1 = (Mat_<float>(2, 2) << 3.5, 2.1, -1.5, -6.5);         // 실수 행렬을 float타입 Mat 객체에 저장
    Mat mat2 = (Mat_<float>(3, 3) << 0, 2, -1, 5, 10, 8, 6, -7, 9); // 실수 행렬을 float타입 Mat 객체에 저장
    Mat mat3 = (Mat_<float>(1, 4) << 1, 2, 3, 4);   // 실수 행렬을 float타입 Mat 객체에 저장
    Mat mat4 = (Mat_<float>(4, 1) << 5, 6, 7, 8);   // 실수 행렬을 float타입 Mat 객체에 저장
    cout << "mat1:\n" << mat1 << endl;              // Mat객체 출력
    cout << "mat2:\n" << mat2 << endl;              // Mat객체 출력
    cout << "mat3:\n" << mat3 << endl;              // Mat객체 출력
    cout << "mat4:\n" << mat4 << endl;              // Mat객체 출력
    return 0;							            // 0을 반환(정상종료)
}					    				            // 메인함수 종료
*/

/* 2 번 
#include "opencv2/opencv.hpp"							// opencv 헤더파일 추가
#include <iostream>             						// c++ 헤더파일 추가
using namespace cv;             						// cv(opencv) 네임스페이스 생략
using namespace std;            						// std(c++) 네임스페이스 생략
int main() {											// 메인 함수 선언
    Size size(400, 300);                                // 윈도우의 크기, size클래스로 변수화
    Mat blue_img(size, CV_8UC3, Scalar(255, 0, 0));     // 파란색 mat객체 생성
    Mat green_img(size, CV_8UC3, Scalar(0, 255, 0));    // 초록색 mat객체 생성
    Mat red_img(size, CV_8UC3, Scalar(0, 0, 255));      // 빨간색 mat객체 생성
    imshow("Blue Window", blue_img);                    // 파란색 mat객체 출력
    imshow("Green Window", green_img);                  // 초록색 mat객체 출력
    imshow("Red Window", red_img);                      // 빨간색 mat객체 출력
    waitKey(0);                                         // 윈도우 출력 후 대기
    return 0;											// 0을 반환(정상종료)
}														// 메인함수 종료
*/

/* 3 번 
#include "opencv2/opencv.hpp"                           // opencv 헤더파일 추가
#include <iostream>                                     // c++ 헤더파일 추가
#include <thread>                                       // 멀티스레드 헤더파일 추가
using namespace cv;                                     // cv(opencv) 네임스페이스 생략
using namespace std;                                    // std(c++) 네임스페이스 생략
int b = 255, g = 255, r = 255;                          // bgr 값을 흰색으로 초기화
bool running = true;                                    // 스레드 실행 상태 변수 선언
void inputThread() {                                    // 입력 전담 함수 선언
    while (running) {                                   // 실행 상태가 true인 동안 반복
        cout << "b값을 입력하라: "; cin >> b;           // 안내문구 출력, b값 설정
        if (b < 0) { running = false; break; }          // b값으로 음수가 입력될 경우 종료
        cout << "g값을 입력하라: "; cin >> g;           // 안내문구 출력, g값 설정
        cout << "r값을 입력하라: "; cin >> r;           // 안내문구 출력, r값 설정
    }                                                   // 반복문 종료
}                                                       // 입력 전담 함수 종료
int main() {                                            // 메인 함수 선언
    utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);// 로그 출력 끄기
    Size size(400, 300);                                // 윈도우 사이즈 설정
    Mat img(size, CV_8UC3);                             // 이미지를 저장할 객체 선언
    thread t(inputThread);                              // 입력 전담 스레드 시작
    t.detach();                                         // 스레드를 메인과 분리
    while (running) {                                   // 실행 상태가 true인 동안 반복
        img.setTo(Scalar(b, g, r));                     // 이미지 변경
        imshow("Color Window", img);                    // 이미지 출력
        waitKey(30);                                    // 30ms 대기, 윈도우를 고정시킴
    }                                                   // 무한반복문 종료
    return 0;                                           // 0을 반환(정상종료)
}                                                       // 메인함수 종료
*/

/* 4 번 
#include "opencv2/opencv.hpp"			// opencv 헤더파일 추가
#include <iostream>             		// c++ 헤더파일 추가
using namespace cv;             		// cv(opencv) 네임스페이스 생략
using namespace std;            		// std(c++) 네임스페이스 생략
int main() {							// 메인 함수 선언
    Size size(400, 300);                // 윈도우 사이즈 설정
    Mat img(size, CV_8UC3);             // 이미지를 저장할 객체 선언
    char exit;                          // 루프탈출 플래그 선언
                                        // 각각 파랑, 초록, 빨강 을 나타내는 밝기 값 저장
    Scalar colors[] = { Scalar(255, 0, 0), Scalar(0, 255, 0), Scalar(0, 0, 255) };
    int i = 0;                          // 윈도우 값을 나타낼 변수 i 선언
    while (true) {                      // 무한반복문
        img.setTo(colors[i++ % 3]);     // 0~2까지의 인덱스를 순차적으로 무한 순회
        imshow("Color Window", img);    // 이미지 출력
        exit = waitKey(1000);           // 1초 대기
        if (exit == 'q') break;         // 종료 플래그 체크 후 q가 저장되있을 경우 종료
    }                                   // 무한반복문 종료
    return 0;							// 0을 반환(정상종료)
}					    				// 메인함수 종료
*/

/* 5 번 
#include "opencv2/opencv.hpp"               // opencv 헤더파일 추가
#include <iostream>             			// c++ 헤더파일 추가
using namespace cv;             			// cv(opencv) 네임스페이스 생략
using namespace std;            			// std(c++) 네임스페이스 생략
int main() {								// 메인 함수 선언
    Size size(400, 300);                    // 윈도우 사이즈 설정
    Mat img(size, CV_8UC1);                 // 이미지를 저장할 객체 선언
    int i = 0;                              // 출력될 영상의 밝기 값을 저장할 변수 선언
    int x = 1;                              // 영상의 밝기 값을 변화시킬 값을 저장할 변수 선언
    char exit = 0;                          // 무한푸르 탈출 플래그 선언
    while (true) {                          // 무한루프문
        img.setTo(i);                       // 영상의 밝기를 i의 값으로 변경
        i += x;                             // i에 x의 값을 더해 밝기를 변경
        if (i >= 255 || i <= 0) x *= -1;    // i가 정해진 범위를 벗어날 경우 x의 부호 반전
        imshow("Color Window", img);        // 이미지 출력
        exit = waitKey(5);                  // 5ms 대기
        if (exit == 'q') break;             // 종료 플래그 활성화 시에 무한반복문 탈출
    }                                       // 무한반복문 종료
    return 0;								// 0을 반환(정상종료)
}											// 메인함수 종료
*/