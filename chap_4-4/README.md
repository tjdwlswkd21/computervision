# 1. Lenna 영상을 컬러 영상으로 읽은 후 화면에 각 키에 맞는 동작을 수행하시오

``` cpp
#include <iostream>                                                      // c++ 헤더파일 추가
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main(void) {                                                         // 메인 함수 선언
    Mat img = imread("C:/Users/tjdwl/source/repos/"                     // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp");                           // lenna.bmp를 읽어 img에 저장
    if (img.empty()) {                                                   // 이미지 로드 실패 여부 확인
        cerr << "Image load failed!" << endl;                           // 실패 시 에러 메시지 출력
        return 1; }                                                      // 1을 반환(비정상종료)
    namedWindow("img");                                                  // "img" 이름의 윈도우 생성
    while (true) {                                                       // 무한 루프 시작
        imshow("img", img);                                              // "img" 윈도우에 현재 이미지 출력
        int key = waitKey(0);                                            // 키 입력이 있을 때까지 대기 후 저장
        switch (key) {                                                   // 입력된 키값에 따라 분기
        case 'l':                                                        // 소문자 'l' 입력 시
            line(img, Point(200, 400), Point(350, 400),                 // img에 (200,400)→(350,400) 수평선의 시작·끝점 지정
                Scalar(255, 255, 255), 3);                               // 흰색(BGR), 두께 3으로 선 그리기
            break;                                                       // switch문 탈출
        case 'c':                                                        // 소문자 'c' 입력 시
            circle(img, Point(275, 275), 100,                           // img의 중심(275,275), 반지름 100의 원을
                Scalar(0, 0, 255), 3);                                   // 빨간색(BGR), 두께 3으로 그리기
            break;                                                       // switch문 탈출
        case 't':                                                        // 소문자 't' 입력 시
            putText(img, "Hello, Lenna",                                // img에 "Hello, Lenna" 텍스트를
                Point(img.cols / 2 - 130, 50),                          // 가로 중앙에서 좌측으로 130px 이동, y=50 위치에
                FONT_HERSHEY_SIMPLEX, 1.5, Scalar(0, 255, 255), 2);    // SIMPLEX 폰트, 크기 1.5, 노란색(BGR), 두께 2로 출력
            break;                                                       // switch문 탈출
        case 'q':                                                        // 소문자 'q' 입력 시
            return 0;                                                    // 0을 반환(정상종료)
        }                                                                // switch문 종료
    }                                                                    // while 루프 종료
}                                                                        // 메인함수 종료
```

https://youtube.com/shorts/XXzKidvVzXM?feature=share


# 2. Lenna 영상 위에서 발생하는 마우스 이벤트의 횟수를 세어서 출력하는 프로그램을 작성하시오 

``` cpp
#include <iostream>                                                      // c++ 헤더파일 추가
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
void on_mouse(int event, int x, int y, int flags, void* userdata);      // 마우스 콜백 함수 전방 선언
int main(void) {                                                         // 메인 함수 선언
    Mat img = imread("C:/Users/tjdwl/source/repos/"                     // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp");                           // lenna.bmp를 읽어 img에 저장
    if (img.empty()) {                                                   // 이미지 로드 실패 여부 확인
        cerr << "Image load failed!" << endl;                           // 실패 시 에러 메시지 출력
        return 1; }                                                      // 1을 반환(비정상종료)
    namedWindow("img");                                                  // "img" 이름의 윈도우 생성
    setMouseCallback("img", on_mouse);                                   // "img" 윈도우에 on_mouse 콜백 함수 등록
    imshow("img", img);                                                  // "img" 윈도우에 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
void on_mouse(int event, int x, int y, int flags, void* userdata) {     // 마우스 콜백 함수 정의
    static int count_down = 0;                                           // 마우스 버튼 누름 횟수(정적 변수로 유지)
    static int count_up = 0;                                             // 마우스 버튼 뗌 횟수(정적 변수로 유지)
    static int count_move = 0;                                           // 마우스 이동 횟수(정적 변수로 유지)
    switch (event) {                                                     // 마우스 이벤트 종류에 따라 분기
    case EVENT_LBUTTONDOWN:                                              // 마우스 왼쪽 버튼 누름 이벤트
        count_down++;                                                    // 누름 횟수 1 증가
        cout << "EVENT_LBUTTONDOWN: " << count_down << endl;            // 누름 횟수 출력
        break;                                                           // switch문 탈출
    case EVENT_LBUTTONUP:                                                // 마우스 왼쪽 버튼 뗌 이벤트
        count_up++;                                                      // 뗌 횟수 1 증가
        cout << "EVENT_LBUTTONUP: " << count_up << endl;                // 뗌 횟수 출력
        break;                                                           // switch문 탈출
    case EVENT_MOUSEMOVE:                                                // 마우스 이동 이벤트
        count_move++;                                                    // 이동 횟수 1 증가
        cout << "EVENT_MOUSEMOVE: " << count_move << endl;              // 이동 횟수 출력
        break;                                                           // switch문 탈출
    default:                                                             // 그 외 이벤트
        break;                                                           // switch문 탈출
    }                                                                    // switch문 종료
}                                                                        // 콜백 함수 종료
```

https://youtu.be/EvOffTO8UZg


# 3. 그레이스케일 영상을 마우스로 클릭하는 화면 좌표와 그 점의 화소값을 출력하는 프로그램을 작성하시오

```cpp
#include <iostream>                                                      // c++ 헤더파일 추가
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
void on_mouse(int event, int x, int y, int flags, void* userdata);      // 마우스 콜백 함수 전방 선언
int main(void) {                                                         // 메인 함수 선언
    Mat img = imread("C:/Users/tjdwl/source/repos/"                     // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp", IMREAD_GRAYSCALE);         // lenna.bmp를 그레이스케일로 읽어 img에 저장
    if (img.empty()) {                                                   // 이미지 로드 실패 여부 확인
        cerr << "Image load failed!" << endl;                           // 실패 시 에러 메시지 출력
        return 1; }                                                      // 1을 반환(비정상종료)
    namedWindow("gray");                                                 // "gray" 이름의 윈도우 생성
    setMouseCallback("gray", on_mouse, &img);                           // "gray" 윈도우에 on_mouse 콜백 등록, img 주소 전달
    imshow("gray", img);                                                 // "gray" 윈도우에 그레이스케일 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
void on_mouse(int event, int x, int y, int flags, void* userdata) {     // 마우스 콜백 함수 정의
    if (event == EVENT_LBUTTONDOWN) {                                    // 마우스 왼쪽 버튼 누름 이벤트일 때
        Mat& img = *(Mat*)userdata;                                      // userdata를 Mat 참조형으로 변환하여 img에 저장
        int pixelValue = (int)img.at<uchar>(y, x);                      // 클릭한 (y,x) 위치의 픽셀값(uchar)을 int로 변환하여 저장
        cout << "좌표: (" << x << "," << y << "), "                     // 클릭한 좌표를 출력
            << "화소값: " << pixelValue << endl;                         // 해당 위치의 픽셀값 출력
    }                                                                    // 조건문 종료
}                                                                        // 콜백 함수 종료
```

https://youtu.be/OfYUSrcadiA


# 4. 컬러 영상을 마우스로 클릭하는 화면 좌표와 그 점의 화소값을 출력하는 프로그램을 작성하시오

```cpp
#include <iostream>                                                      // c++ 헤더파일 추가
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
void on_mouse(int event, int x, int y, int flags, void* userdata);      // 마우스 콜백 함수 전방 선언
int main(void) {                                                         // 메인 함수 선언
    Mat img = imread("C:/Users/tjdwl/source/repos/"                     // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp", IMREAD_COLOR);             // lenna.bmp를 컬러로 읽어 img에 저장
    if (img.empty()) {                                                   // 이미지 로드 실패 여부 확인
        cerr << "Image load failed!" << endl;                           // 실패 시 에러 메시지 출력
        return 1; }                                                      // 1을 반환(비정상종료)
    namedWindow("src");                                                  // "src" 이름의 윈도우 생성
    setMouseCallback("src", on_mouse, &img);                            // "src" 윈도우에 on_mouse 콜백 등록, img 주소 전달
    imshow("src", img);                                                  // "src" 윈도우에 컬러 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
}                                                                        // 메인함수 종료
void on_mouse(int event, int x, int y, int flags, void* userdata) {     // 마우스 콜백 함수 정의
    if (event == EVENT_LBUTTONDOWN) {                                    // 마우스 왼쪽 버튼 누름 이벤트일 때
        Mat& img = *(Mat*)userdata;                                      // userdata를 Mat 참조형으로 변환하여 img에 저장
        Vec3b pixelValue = img.at<Vec3b>(y, x);                         // 클릭한 (y,x) 위치의 BGR 픽셀값을 Vec3b로 저장
        cout << "좌표: (" << x << "," << y << "), "                     // 클릭한 좌표를 출력
            << "화소값 (B, G, R): " << pixelValue << endl;              // 해당 위치의 BGR 픽셀값 출력
    }                                                                    // 조건문 종료
}                                                                        // 콜백 함수 종료
```

https://youtu.be/Joh4sSzMeVI


# 5. 컬러 영상을 마우스로 드래깅 한 영역을 추출하여 화면에 출력하는 프로그램을 작성 하시오

```cpp
#include <iostream>                                                      // c++ 헤더파일 추가
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
struct MyData {                                                          // 콜백에 전달할 데이터 구조체 선언
    Mat img;                                                             // 원본 이미지를 저장할 Mat 멤버
    Point ptOld;                                                         // 마우스 버튼 누름 시작 좌표를 저장할 Point 멤버
};                                                                       // 구조체 선언 종료
void on_mouse(int event, int x, int y, int flags, void* userdata) {     // 마우스 콜백 함수 정의
    MyData* data = (MyData*)userdata;                                    // userdata를 MyData 포인터로 변환하여 data에 저장
    if (event == EVENT_LBUTTONDOWN) {                                    // 마우스 왼쪽 버튼 누름 이벤트일 때
        data->ptOld = Point(x, y);                                      // 클릭 시작 좌표를 ptOld에 저장
    }                                                                    // 조건문 종료
    else if (event == EVENT_LBUTTONUP) {                                 // 마우스 왼쪽 버튼 뗌 이벤트일 때
        if (data->ptOld != Point(x, y)) {                               // 시작점과 끝점이 다를 때(드래그가 발생했을 때)
            Rect rc(data->ptOld, Point(x, y));                          // 시작점~끝점으로 ROI 사각형 생성
            rc &= Rect(0, 0, data->img.cols, data->img.rows);           // ROI가 이미지 범위를 벗어나지 않도록 클리핑
            if (rc.width > 0 && rc.height > 0) {                        // ROI의 가로·세로가 유효할 때
                destroyWindow("ROI");                                    // 기존 "ROI" 윈도우 제거
                namedWindow("ROI", WINDOW_AUTOSIZE);                    // 새 "ROI" 윈도우 생성
                imshow("ROI", data->img(rc).clone());                   // ROI 영역을 복사하여 "ROI" 윈도우에 출력
            }                                                            // 조건문 종료
        }                                                                // 조건문 종료
        imshow("src", data->img);                                        // "src" 윈도우에 원본 이미지 재출력
    }                                                                    // 조건문 종료
}                                                                        // 콜백 함수 종료
int main() {                                                             // 메인 함수 선언
    MyData myParams;                                                     // MyData 구조체 객체 선언
    myParams.img = imread("C:/Users/tjdwl/source/repos/"                // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp", IMREAD_COLOR);             // lenna.bmp를 컬러로 읽어 myParams.img에 저장
    if (myParams.img.empty()) return -1;                                 // 이미지 로드 실패 시 -1 반환(비정상종료)
    namedWindow("src", WINDOW_AUTOSIZE);                                 // "src" 이름의 윈도우 생성
    namedWindow("ROI", WINDOW_AUTOSIZE);                                 // "ROI" 이름의 윈도우 생성
    setMouseCallback("src", on_mouse, &myParams);                       // "src" 윈도우에 on_mouse 콜백 등록, myParams 주소 전달
    imshow("src", myParams.img);                                         // "src" 윈도우에 원본 이미지 출력
    while (waitKey(10) != 27);                                           // ESC(27) 키 입력이 있을 때까지 10ms마다 대기
    destroyAllWindows();                                                 // 모든 윈도우 제거
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
```

https://youtu.be/SxE36JvMZWY


# 6. 마우스 왼쪽 버튼을 누르면 배경색이 Red 가 되고 마우스 오른쪽 버튼을 누르면 배경색이 Blue 가 되도록 프로그램을 작성하시오

```cpp
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
using namespace std;                                                     // std(c++) 네임스페이스 생략
void on_mouse(int event, int x, int y, int flags, void* userdata) {     // 마우스 콜백 함수 정의
    Mat& img = *(Mat*)userdata;                                          // userdata를 Mat 참조형으로 변환하여 img에 저장
    if (event == EVENT_LBUTTONDOWN)                                      // 마우스 왼쪽 버튼 누름 이벤트일 때
        img.setTo(Scalar(0, 0, 255));                                    // 이미지 전체를 빨간색(BGR)으로 채우기
    else if (event == EVENT_RBUTTONDOWN)                                 // 마우스 오른쪽 버튼 누름 이벤트일 때
        img.setTo(Scalar(255, 0, 0));                                    // 이미지 전체를 파란색(BGR)으로 채우기
}                                                                        // 콜백 함수 종료
int main() {                                                             // 메인 함수 선언
    Mat img(200, 400, CV_8UC3, Scalar(255, 255, 255));                  // 200x400 크기의 흰색 8비트 3채널 Mat 객체 생성
    namedWindow("src");                                                  // "src" 이름의 윈도우 생성
    setMouseCallback("src", on_mouse, &img);                            // "src" 윈도우에 on_mouse 콜백 등록, img 주소 전달
    while (true) {                                                       // 무한 루프 시작
        imshow("src", img);                                              // "src" 윈도우에 현재 이미지 출력
        if (waitKey(10) == 27)                                           // 10ms 대기 후 ESC(27) 입력 여부 확인
            break;                                                       // ESC 입력 시 루프 종료
    }                                                                    // while 루프 종료
    destroyAllWindows();                                                 // 모든 윈도우 제거
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
```

https://youtu.be/EqWI8H97Kl8


# 7. 각 색 영역을 지정해 해당 영역을 클릭할 시 나머지 영역이 해당 색으로 변하는 프로그램을 작성하시오

```cpp
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
const Rect* get_boxes() {                                                // 버튼 영역 배열을 반환하는 함수 정의
    static const Rect boxes[3] = {                                       // 3개의 버튼 Rect를 정적 배열로 선언
        {0,0,200,100}, {0,100,200,100}, {0,200,200,100} };              // 각 버튼의 (x,y,width,height) 초기화
    return boxes;                                                        // 버튼 배열 포인터 반환
}                                                                        // 함수 종료
void draw(Mat& img, int sel) {                                           // 이미지에 버튼 메뉴를 그리는 함수 정의
    const Rect* boxes = get_boxes();                                     // 버튼 영역 배열 가져오기
    const char* names[3] = { "Red", "Green", "Blue" };                  // 각 버튼의 이름 문자열 배열 선언
    img.setTo(Scalar(255, 255, 255));                                    // 이미지 전체를 흰색으로 초기화
    for (int i = 0; i < 3; i++) {                                       // 3개의 버튼을 순서대로 그리기 위해 반복
        bool on = (i == sel);                                            // 현재 인덱스가 선택된 버튼인지 여부 저장
        rectangle(img, boxes[i], Scalar(0, 0, 0),                       // 버튼 사각형을 검정색으로 그리되
            on ? FILLED : 2);                                            // 선택된 버튼은 채움, 미선택 버튼은 두께 2로 그리기
        putText(img, names[i],                                           // 버튼 이름 텍스트를
            Point(boxes[i].x + 40, boxes[i].y + 60),                   // 버튼 내부 적절한 위치에
            FONT_HERSHEY_SIMPLEX, 1,                                    // SIMPLEX 폰트, 크기 1로
            on ? Scalar(255, 255, 255) : Scalar(0, 0, 0), 2);          // 선택 시 흰색, 미선택 시 검정색, 두께 2로 출력
    }                                                                    // 반복문 종료
    if (sel >= 0)                                                        // 선택된 버튼이 있을 때
        putText(img, std::string(names[sel]) + " pressed.",             // 선택된 버튼 이름 + " pressed." 텍스트를
            Point(230, 160), FONT_HERSHEY_SIMPLEX, 0.8,                 // (230,160) 위치에 SIMPLEX 폰트, 크기 0.8로
            Scalar(0, 0, 0), 2);                                        // 검정색, 두께 2로 출력
}                                                                        // 함수 종료
void on_mouse(int event, int x, int y, int, void* userdata) {           // 마우스 콜백 함수 정의(flags 파라미터 미사용)
    if (event != EVENT_LBUTTONDOWN) return;                             // 왼쪽 버튼 누름 이벤트가 아니면 함수 종료
    Mat& img = *static_cast<Mat*>(userdata);                            // userdata를 Mat 참조형으로 변환하여 img에 저장
    const Rect* boxes = get_boxes();                                     // 버튼 영역 배열 가져오기
    for (int i = 0; i < 3; i++)                                         // 3개의 버튼을 순서대로 확인
        if (boxes[i].contains(Point(x, y))) {                           // 클릭 좌표가 i번째 버튼 영역 안에 있으면
            draw(img, i); return; }                                      // i번째 버튼을 선택 상태로 다시 그리고 함수 종료
}                                                                        // 콜백 함수 종료
int main() {                                                             // 메인 함수 선언
    Mat img(300, 500, CV_8UC3);                                          // 300x500 크기의 8비트 3채널 Mat 객체 생성
    draw(img, -1);                                                       // 선택 없이(-1) 초기 메뉴 화면 그리기
    namedWindow("Menu");                                                 // "Menu" 이름의 윈도우 생성
    setMouseCallback("Menu", on_mouse, &img);                           // "Menu" 윈도우에 on_mouse 콜백 등록, img 주소 전달
    while (waitKey(10) != 27) imshow("Menu", img);                      // ESC(27) 입력 전까지 10ms마다 "Menu" 윈도우 갱신
}                                                                        // 메인함수 종료
```

https://youtu.be/LDhEgGHCKz8