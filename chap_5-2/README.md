# 1. 코드 5-5에서 연산자 함수를 사용하지 말고 픽셀값을 직접 참조하는 방식으로 같은 결과를 얻도록 수정하라. (204페이지 코드 5-3을 참고할 것.)

``` cpp
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat src = imread("C:/Users/tjdwl/source/repos/"                     // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp", IMREAD_GRAYSCALE);         // lenna.bmp를 그레이스케일로 읽어 src에 저장
    float s = 2.f;                                                       // 픽셀값에 곱할 밝기 배율(2배) 선언
    Mat dst = src.clone();                                               // src를 복사하여 결과 이미지 dst 생성
    for (int i = 0; i < src.rows; i++) {                                // 이미지의 모든 행을 순회
        for (int j = 0; j < src.cols; j++) {                            // 이미지의 모든 열을 순회
            dst.at<uchar>(i, j) = saturate_cast<uchar>(                 // (i,j) 위치의 픽셀값에
                src.at<uchar>(i, j) * s);                               // 배율 s를 곱한 뒤 0~255 범위로 포화 연산하여 저장
        }                                                                // 내부 반복문 종료
    }                                                                    // 외부 반복문 종료
    imshow("src", src);                                                  // "src" 윈도우에 원본 이미지 출력
    imshow("dst", dst);                                                  // "dst" 윈도우에 밝기 증가 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
```

![실행결과](./chap_5-2_1.png)


# 2. 코드 5-6에서 연산자 함수를 사용하지 말고 픽셀값을 직접 참조하는 방식으로 같은 결과를 얻도록 수정하라. (204페이지 코드 5-3을 참고할 것.)

``` cpp
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat src = imread("C:/Users/tjdwl/source/repos/"                     // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp", IMREAD_GRAYSCALE);         // lenna.bmp를 그레이스케일로 읽어 src에 저장
    float alpha = 1.f;                                                   // 명암비 조절 강도(alpha) 선언 및 초기화
    Mat dst = src.clone();                                               // src를 복사하여 결과 이미지 dst 생성
    for (int i = 0; i < src.rows; i++) {                                // 이미지의 모든 행을 순회
        for (int j = 0; j < src.cols; j++) {                            // 이미지의 모든 열을 순회
            int srcval = src.at<uchar>(i, j);                           // (i,j) 위치의 원본 픽셀값을 int로 저장
            float dstval = srcval + (srcval - 128) * alpha;             // 128 기준으로 픽셀값을 alpha 배율로 명암비 조절
            dst.at<uchar>(i, j) = saturate_cast<uchar>(dstval);        // 계산 결과를 0~255 범위로 포화 연산하여 dst에 저장
        }                                                                // 내부 반복문 종료
    }                                                                    // 외부 반복문 종료
    imshow("src", src);                                                  // "src" 윈도우에 원본 이미지 출력
    imshow("dst", dst);                                                  // "dst" 윈도우에 명암비 조절 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
```

![실행결과](./chap_5-2_2.png)


# 3. 코드5-6에서 α가 너무 크면 어떻게 되는가? 실행결과를 첨부하고 이유를 설명하라. / 코드5-6에서 α가 너무 작으면 어떻게 되는가? 실행결과를 첨부하고 이유를 설명하라.

``` cpp
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat src = imread("C:/Users/tjdwl/source/repos/"                     // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp", IMREAD_GRAYSCALE);         // lenna.bmp를 그레이스케일로 읽어 src에 저장
    float alpha1 = 0.5f;                                                 // 낮은 명암비 강도(0.5배) 선언
    float alpha2 = 2.f;                                                  // 높은 명암비 강도(2배) 선언
    Mat dst1 = src.clone();                                              // src를 복사하여 낮은 명암비 결과 이미지 dst1 생성
    Mat dst2 = src.clone();                                              // src를 복사하여 높은 명암비 결과 이미지 dst2 생성
    for (int i = 0; i < src.rows; i++) {                                // 이미지의 모든 행을 순회
        for (int j = 0; j < src.cols; j++) {                            // 이미지의 모든 열을 순회
            int srcval = src.at<uchar>(i, j);                           // (i,j) 위치의 원본 픽셀값을 int로 저장
            float dstval1 = srcval + (srcval - 128) * alpha1;           // alpha1(0.5)로 명암비를 낮게 조절한 픽셀값 계산
            float dstval2 = srcval + (srcval - 128) * alpha2;           // alpha2(2.0)로 명암비를 높게 조절한 픽셀값 계산
            dst1.at<uchar>(i, j) = saturate_cast<uchar>(dstval1);      // dstval1을 0~255 포화 연산하여 dst1에 저장
            dst2.at<uchar>(i, j) = saturate_cast<uchar>(dstval2);      // dstval2를 0~255 포화 연산하여 dst2에 저장
        }                                                                // 내부 반복문 종료
    }                                                                    // 외부 반복문 종료
    imshow("src", src);                                                  // "src" 윈도우에 원본 이미지 출력
    imshow("dst1", dst1);                                                // "dst1" 윈도우에 낮은 명암비 이미지 출력
    imshow("dst2", dst2);                                                // "dst2" 윈도우에 높은 명암비 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
```

알파가 너무 큰 경우에는 평균 밝기를 기준으로 픽셀들이 양극단으로 강하게 밀려나면서 명암비가 극도로 높아지는데, 이로 인해 밝은 영역은 순백색(255)으로, 어두운 영역은 순검정색(0)으로 포화되는 클리핑 현상이 발생하여 영상의 세부적인 질감이나 정보가 손실되고 이미지가 매우 거칠게 표현된다.
또한 알파가 너무 작은 경우(0에 가깝거나 음수인 경우)에는 픽셀 간의 밝기 차이가 줄어들면서 모든 픽셀값이 영상의 평균값 근처로 수렴하게 되는데, 이로 인해 밝고 어두운 경계가 모호해지는 저대비 현상이 나타나며 알파가 -1에 가까워질수록 영상은 아무런 형체를 알아볼 수 없는 평탄한 회색조 이미지로 변하게 된다.

![실행결과](./chap_5-2_3.png)


# 4. 코드5-6은 입력 영상의 픽셀값을 128을 기준으로 구분하여 명암비를 개선한다. 여기서 128을 입력영상 픽셀값의 평균값으로 변경하여 명암비 개선을 수행하라. (영상의 픽셀값의 평균값을 구할때는 함수 mean()을 이용하라.)

``` cpp
#include <opencv2/opencv.hpp>                                            // opencv 헤더파일 추가
#include <iostream>                                                      // c++ 헤더파일 추가
using namespace std;                                                     // std(c++) 네임스페이스 생략
using namespace cv;                                                      // cv(opencv) 네임스페이스 생략
int main() {                                                             // 메인 함수 선언
    Mat src = imread("C:/Users/tjdwl/source/repos/"                     // 지정된 경로에서
        "computervision/chap_2-3/lenna.bmp", IMREAD_GRAYSCALE);         // lenna.bmp를 그레이스케일로 읽어 src에 저장
    float alpha = 1.f;                                                   // 명암비 조절 강도(alpha) 선언 및 초기화
    Scalar m = mean(src);                                                // 이미지 전체 픽셀의 평균값을 Scalar로 계산
    int avg = m[0];                                                      // Scalar의 첫 번째 채널값(평균 밝기)을 int로 저장
    cout << avg << "\n\n\n\n\n";                                        // 평균 밝기값 출력(약 124)
    Mat dst = src.clone();                                               // src를 복사하여 결과 이미지 dst 생성
    for (int i = 0; i < src.rows; i++) {                                // 이미지의 모든 행을 순회
        for (int j = 0; j < src.cols; j++) {                            // 이미지의 모든 열을 순회
            int srcval = src.at<uchar>(i, j);                           // (i,j) 위치의 원본 픽셀값을 int로 저장
            float dstval = srcval + (srcval - avg) * alpha;             // 평균 밝기(avg) 기준으로 alpha 배율만큼 명암비 조절
            dst.at<uchar>(i, j) = saturate_cast<uchar>(dstval);        // 계산 결과를 0~255 범위로 포화 연산하여 dst에 저장
        }                                                                // 내부 반복문 종료
    }                                                                    // 외부 반복문 종료
    imshow("src", src);                                                  // "src" 윈도우에 원본 이미지 출력
    imshow("dst", dst);                                                  // "dst" 윈도우에 명암비 조절 이미지 출력
    waitKey(0);                                                          // 키 입력이 있을 때까지 대기
    return 0;                                                            // 0을 반환(정상종료)
}                                                                        // 메인함수 종료
```

![실행결과](./chap_5-2_4.png)
