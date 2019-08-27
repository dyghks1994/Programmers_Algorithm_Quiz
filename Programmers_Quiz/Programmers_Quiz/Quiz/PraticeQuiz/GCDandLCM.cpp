#include "stdafx.h"
#include "GCDandLCM.h"

GCDandLCM::GCDandLCM()
{
	int n = 3;
	int m = 12;
	std::vector<int> gcd_lcm = solution(n, m);

	std::cout << n << "과 " << m << "의 최대공약수(GCD) = " << gcd_lcm[0] << std::endl;
	std::cout << n << "과 " << m << "의 최소공배수(LCM) = " << gcd_lcm[1] << std::endl;
}

GCDandLCM::~GCDandLCM()
{
}

std::vector<int> GCDandLCM::solution(int n, int m)
{
	std::vector<int> answer;

	for (int i = n; i > 0; i--)
	{
		if ((n % i == 0) && (m % i == 0))	// 반복용 변수 i를 n으로 초기화 하고 1까지 마이너스 해가면서 두 수를 i로 나눠 봄, 동시에 0이 되면 최대공약수!
		{
			answer.emplace_back(i);			// 벡터에 최대공약수 추가
			answer.emplace_back(n * m / i);	// 최소공배수(LCM) 추가. LCM -> n * m / LCM(n,m)
		}
	}


	/*	유클리드 호제법으로 푸는 방법 by 반복문
	int big;        // 큰 수
    int small;      // 작은 수
    int r;          // 나머지 저장할 변수

    big   = (n > m) ? n : m;    // n과 m중 더 큰 수를 big에 저장
    small = (n < m) ? n : m;    // n과 m중 더 작은 수를 small에 저장
    int gcd = small;            // 최대공약수 초기화    

    while (small != 0)  // small이 0이 아니면 반복, small이 big / small == 0이면 최대공약수!
    {
        r = big % small;    // r에 big과 small의 나머지를 구함
        big = small;        // big에 small을 대입
        small = r;          // small에 r을 대입
                            // 그후 small이 0이 될 때까지 계속 반복
    }
    gcd = big;              // 최대공약수 저장

    int lcm = n * m / gcd;

    answer.emplace_back(gcd);   // 벡터에 최대공약수 추가
    answer.emplace_back(lcm);   // 벡터에 최소공배수 추가
	*/
	return answer;
}
