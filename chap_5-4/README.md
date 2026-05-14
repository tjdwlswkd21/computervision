# 1. crayfish.jpg 영상의 히스토그램 스트레칭을 수행한 후 입력, 출력 영상을 출력하라.<br>히스토그램 스트레칭 전, 후의 히스토그램 그래프를 그려라.

``` cpp
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
Mat getGrayHistImage(const Mat& hist) {                                  // 히스토그램 데이터를 시각화 이미지로 변환하는 함수 정의
    CV_Assert(hist.type() == CV_32FC1);                                  // hist가 32비트 float 1채널인지 검증(아니면 오류)
    CV_Assert(hist.size() == Size(1, 256));                              // hist 크기가 1x256인지 검증(아니면 오류)
    double histMax;                                                      // 히스토그램 최댓값을 저장할 변수 선언
    minMaxLoc(hist, 0, &histMax);                                        // hist에서 최솟값(무시)·최댓값을 찾아 histMax에 저장
    Mat imgHist(100, 256, CV_8UC1, Scalar(255));                        // 100x256 크기의 흰색 8비트 1채널 히스토그램 이미지 생성
    for (int i = 0; i < 256; i++) {                                     // 256개의 밝기 레벨(0~255)에 대해 반복
        line(imgHist,                                                    // imgHist에
            Point(i, 100),                                               // 막대 하단(바닥)을 시작점으로
            Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), // 막대 상단을 끝점으로(높이 = 빈도 비율 × 100)
            Scalar(0));                                                  // 검정색으로 수직 막대선 그리기
    }                                                                    // 반복문 종료
    return imgHist;                                                      // 완성된 히스토그램 이미지 반환
}                                                                        // 함수 종료
Mat calcGrayHist(const Mat& img) {                                       // 그레이스케일 이미지의 히스토그램을 계산하는 함수 정의
    CV_Assert(img.type() == CV_8UC1);                                    // img가 8비트 1채널인지 검증(아니면 오류)
    Mat hist;                                                            // 히스토그램 결과를 저장할 Mat 객체 선언
    int channels[] = { 0 };                                             // 히스토그램을 계산할 채널 인덱스(0번 채널)
    int dims = 1;                                                        // 히스토그램 차원 수(1차원)
    const int histSize[] = { 256 };                                      // 히스토그램 빈(bin)의 수(256개)
    float graylevel[] = { 0, 256 };                                      // 히스토그램 계산 범위(0~255)
    const float* ranges[] = { graylevel };                               // 범위 배열의 포인터
    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges); // img 1장, 0번 채널, 마스크 없이 1차원 256빈 히스토그램 계산
    return hist;                                                         // 계산된 히스토그램 반환
}                                                                        // 함수 종료
int main() {                                                             // 메인 함수 선언
    Mat src = imread("C:/Users/tjdwl/source/repos/computervision/crayfish.bmp", IMREAD_GRAYSCALE); // crayfish.bmp를 그레이스케일로 읽어 src에 저장
    if (src.empty()) {                                                   // 이미지 로드 실패 시
        cout << "Image load failed!" << endl;                            // 오류 메시지 출력
        return -1;                                                       // 비정상 종료
    }                                                                    // 조건문 종료
    Mat dst;                                                             // 스트레칭 결과를 저장할 Mat 객체 선언
    normalize(src, dst, 0, 255, NORM_MINMAX);                           // src를 0~255 범위로 선형 정규화(히스토그램 스트레칭)하여 dst에 저장
    Mat histSrc = calcGrayHist(src);                                     // 원본 src의 그레이스케일 히스토그램 계산
    Mat histDst = calcGrayHist(dst);                                     // 스트레칭된 dst의 그레이스케일 히스토그램 계산
    Mat imgHistSrc = getGrayHistImage(histSrc);                          // src 히스토그램 데이터를 막대그래프 이미지로 변환
    Mat imgHistDst = getGrayHistImage(histDst);                          // dst 히스토그램 데이터를 막대그래프 이미지로 변환
    imshow("src", src);                                                  // "src" 윈도우에 원본 이미지 출력
    imshow("srcHist", imgHistSrc);                                       // "srcHist" 윈도우에 원본 히스토그램 출력
    imshow("dst (Stretching)", dst);                                     // "dst (Stretching)" 윈도우에 스트레칭 결과 이미지 출력
    imshow("dstHist", imgHistDst);                                       // "dstHist" 윈도우에 스트레칭 후 히스토그램 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
```

![실행결과](./chap_5-4_1.png)


# 2. crayfish.jpg 영상의 히스토그램 평활화를 수행한 후 입력, 출력 영상을 출력하라.<br>히스토그램 평활화 전, 후의 히스토그램 그래프를 그려라.

``` cpp
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
Mat getGrayHistImage(const Mat& hist) {                                  // 히스토그램 데이터를 시각화 이미지로 변환하는 함수 정의
    CV_Assert(hist.type() == CV_32FC1);                                  // hist가 32비트 float 1채널인지 검증(아니면 오류)
    CV_Assert(hist.size() == Size(1, 256));                              // hist 크기가 1x256인지 검증(아니면 오류)
    double histMax;                                                      // 히스토그램 최댓값을 저장할 변수 선언
    minMaxLoc(hist, 0, &histMax);                                        // hist에서 최솟값(무시)·최댓값을 찾아 histMax에 저장
    Mat imgHist(100, 256, CV_8UC1, Scalar(255));                        // 100x256 크기의 흰색 8비트 1채널 히스토그램 이미지 생성
    for (int i = 0; i < 256; i++) {                                     // 256개의 밝기 레벨(0~255)에 대해 반복
        line(imgHist,                                                    // imgHist에
            Point(i, 100),                                               // 막대 하단(바닥)을 시작점으로
            Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), // 막대 상단을 끝점으로(높이 = 빈도 비율 × 100)
            Scalar(0));                                                  // 검정색으로 수직 막대선 그리기
    }                                                                    // 반복문 종료
    return imgHist;                                                      // 완성된 히스토그램 이미지 반환
}                                                                        // 함수 종료
Mat calcGrayHist(const Mat& img) {                                       // 그레이스케일 이미지의 히스토그램을 계산하는 함수 정의
    CV_Assert(img.type() == CV_8UC1);                                    // img가 8비트 1채널인지 검증(아니면 오류)
    Mat hist;                                                            // 히스토그램 결과를 저장할 Mat 객체 선언
    int channels[] = { 0 };                                             // 히스토그램을 계산할 채널 인덱스(0번 채널)
    int dims = 1;                                                        // 히스토그램 차원 수(1차원)
    const int histSize[] = { 256 };                                      // 히스토그램 빈(bin)의 수(256개)
    float graylevel[] = { 0, 256 };                                      // 히스토그램 계산 범위(0~255)
    const float* ranges[] = { graylevel };                               // 범위 배열의 포인터
    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges); // img 1장, 0번 채널, 마스크 없이 1차원 256빈 히스토그램 계산
    return hist;                                                         // 계산된 히스토그램 반환
}                                                                        // 함수 종료
int main() {                                                             // 메인 함수 선언
    Mat src = imread("C:/Users/tjdwl/source/repos/computervision/crayfish.bmp", IMREAD_GRAYSCALE); // crayfish.bmp를 그레이스케일로 읽어 src에 저장
    if (src.empty()) {                                                   // 이미지 로드 실패 시
        cout << "Image load failed!" << endl;                            // 오류 메시지 출력
        return -1;                                                       // 비정상 종료
    }                                                                    // 조건문 종료
    Mat dst;                                                             // 평활화 결과를 저장할 Mat 객체 선언
    equalizeHist(src, dst);                                              // src에 히스토그램 평활화를 적용하여 dst에 저장
    Mat histSrc = calcGrayHist(src);                                     // 원본 src의 그레이스케일 히스토그램 계산
    Mat histDst = calcGrayHist(dst);                                     // 평활화된 dst의 그레이스케일 히스토그램 계산
    Mat imgHistSrc = getGrayHistImage(histSrc);                          // src 히스토그램 데이터를 막대그래프 이미지로 변환
    Mat imgHistDst = getGrayHistImage(histDst);                          // dst 히스토그램 데이터를 막대그래프 이미지로 변환
    imshow("src", src);                                                  // "src" 윈도우에 원본 이미지 출력
    imshow("srcHist", imgHistSrc);                                       // "srcHist" 윈도우에 원본 히스토그램 출력
    imshow("dst (Equalization)", dst);                                   // "dst (Equalization)" 윈도우에 평활화 결과 이미지 출력
    imshow("dstHist", imgHistDst);                                       // "dstHist" 윈도우에 평활화 후 히스토그램 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
```

![실행결과](./chap_5-4_2.png)
