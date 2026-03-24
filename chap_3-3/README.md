# 1. Mat 객체를 생성하여 다음 행렬들을 저장하고 화면에 출력하는 코드를 작성하라

``` cpp
#include "opencv2/opencv.hpp"							// opencv 헤더파일 추가
#include <iostream>             						// c++ 헤더파일 추가
#include <cmath>										// norm 함수 사용을 위한 헤더파일 추가
using namespace cv;             						// cv(opencv) 네임스페이스 생략
using namespace std;            						// std(c++) 네임스페이스 생략
int main() {											// 메인 함수 선언
	Point a, b;											// Point 객체 선언
	cout << "첫번째 점의 x, y좌표를 입력:";				// 안내문구 출력
	cin >> a.x >> a.y;									// Point 객체 a의 x, y값 설정
	cout << "두번째 점의 x, y좌표를 입력:";				// 안내문구 출력
	cin >> b.x >> b.y;									// Point 객체 b의 x, y값 설정
	cout << "pt1:" << a << endl << "pt2:" << b << endl;	// Point 객체 a, b의 x, y값 출력
	cout << "두 점 사이의 거리: " << norm(a - b);		// Point 객체 a와 b 사이의 거리 출력
	return 0;											// 0을 반환(정상종료)
}														// 메인함수 종료
```
![실행결과](./chap3-3_1.png)


# 2. 3개의 윈도우를 출력하라 크기는 400 X 300 이고 색상은 Blue, Green, Red 이다.

``` cpp
#include "opencv2/opencv.hpp"												// opencv 헤더파일 추가
#include <iostream>															// c++ 헤더파일 추가
using namespace cv;															// cv(opencv) 네임스페이스 생략
using namespace std;														// std(c++) 네임스페이스 생략
int main() {																// 메인 함수 선언
	Size a, b;																// Size 객체 선언
	cout << "첫번째 사각형의 폭, 높이 입력:";								// 안내문구 출력
	cin >> a.width >> a.height;												// Size객체 a의 가로세로 값 설정
	cout << "두번째 사각형의 폭, 높이 입력:";								// 안내문구 출력
	cin >> b.width >> b.height;												// Size객체 b의 가로세로 값 설정
	cout << "s1:" << a << endl << "s2:" << b << endl;						// Size 객체 a, b의 가로세로 값 출력
	cout << "s1의 면적" << a.area() << endl << "s2의 면적:" << b.area();	// Size 객체 a, b의 면적 값 출력
	return 0;																// 0을 반환(정상종료)
}
```
![실행결과](./chap3-3_2.png)


# 3. 무한반복하며 키보드로부터 컬러값을 입력받아 화면의 배경색을 변경해주는 코드를 작성하라 윈도우 크기는 400 X 300 이고 초기색은 흰색으로 설정하라

```cpp
#include "opencv2/opencv.hpp"			// opencv 헤더파일 추가
#include <iostream>						// c++ 헤더파일 추가
using namespace cv;						// cv(opencv) 네임스페이스 생략
using namespace std;					// std(c++) 네임스페이스 생략
int main() {							// 메인 함수 선언
	Rect r1(10, 10, 20, 20);			// Rect 객체 선언
	Point p1(15, 15);					// Point 객체 선언
	if ((r1 + Size(1, 1)).contains(p1))	// rect 객체의 가로세로 값을 1씩 증가시켜 테두리를 모두 포함, p1이 r1안에 존재하는지 확인
		cout << "존재한다.";			// 존재할 경우 실행
	else cout << "존재하지 않는다.";	// 존재하지 않을 경우 실행
	return 0;							// 0을 반환(정상종료)
}										// 메인함수 종료
```
https://youtu.be/7nJ9gO23Rsw


# 4. 1 초마다 화면 배경 바꾸기 예제를 수정하여 다음처럼 윈도우의 배경이 1 초 주기로 Blue -->Green -->Red -->Blue -->Green 를 무한 반복하고 q 키를 누르면 종료하는 코드를 작성하시오

```cpp
#include "opencv2/opencv.hpp"								// opencv 헤더파일 추가
#include <iostream>             							// c++ 헤더파일 추가
using namespace cv;             							// cv(opencv) 네임스페이스 생략
using namespace std;            							// std(c++) 네임스페이스 생략
int main() {												// 메인 함수 선언
	Rect r1;												// Rect 객체 선언
	Point p1;												// Point 객체 선언
	cout << "사각형의 좌측상단의 좌표를 입력하시오(x,y):";	// 안내문구 출력
	cin >> r1.x >> r1.y;									// Rect 객체 r1의 시작 점 좌표값 설정
	cout << "사각형의 폭,높이를 입력하시오(width, height):";// 안내문구 출력
	cin >> r1.width >> r1.height;							// Rect 객체 r1의 가로세로 값 설정
	cout << "점 P의 좌표를 입력하시오:";					// 안내문구 출력
	cin >> p1.x >> p1.y;									// Point 객체 p1의 x, y값 설정
	if (p1.inside(r1 + Size(1, 1)))							// p1이 가로세로 값을 1씩 증가시켜 테두리를 모두 포함한 r1 내에 존재하는지 확인
		cout << "존재한다.";								// 존재할 경우 실행
	else cout << "존재하지 않는다.";						// 존재하지 않을 경우 실행
	return 0;												// 0을 반환(정상종료)
}															// 메인함수 종료
```
https://youtu.be/NxpoI5s2J2w


# 5. 초기에 400 x 400 크기의 검정색 배경의 윈도우를 생성하고 5 msec 마다 화면 배경색의 그레이 레벨을 1 씩 증가시킨다 배경색이 흰색이 되면 다시 5 msec 마다 1 씩 감소시킨다 그리고 다시 검정색이 되면 다시 1 씩 증가시킨다 이과정을 무한히 반복한다 Q 를 누리면 종료하도록 한다

```cpp
#include "opencv2/opencv.hpp"						// opencv 헤더파일 추가
#include <iostream>									// c++ 헤더파일 추가
using namespace cv;									// cv(opencv) 네임스페이스 생략
using namespace std;								// std(c++) 네임스페이스 생략
int main() {										// 메인 함수 선언
	String str;										// String 객체 선언
	for (int i = -1; i < 16 - 2;) {					// i값이 -1부터 14사이에 있을 때 반복
		str = format("실행결과%02d.bmp", i += 2);	// i 값과 이미지파일 이름의 공통 문자열을 합성시켜 이미지파일 이름 생성
		cout << str << endl;						// 이미지파일 이름 출력
	}												// 반복문 종료
	return 0;										// 0을 반환(정상종료)
}													// 메인함수 종료
```
https://youtu.be/Zcp-8WOjHhg