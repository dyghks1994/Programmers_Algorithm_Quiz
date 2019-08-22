#include "stdafx.h"
#include "CollatzConjecture.h"

CollatzConjecture::CollatzConjecture()
{
	long n = 626331;
	std::cout << "<콜라츠 추측 문제>" << std::endl;
	std::cout << "입력된 수 = " << n << std::endl;
	std::cout << "soluction(" << n << ") = " << solution(n) << std::endl;
}

CollatzConjecture::~CollatzConjecture()
{
}

int CollatzConjecture::solution(int num)
{
	int answer = 0;
	long long n = num;	// 연산중 int의 범위를 넘어가서 제대로된 연산이 안되기 떄문에 long long 으로 변환

	for (int i = 1; i <= 500; i++)	// 최대 500번 반복
	{
		if (n == 1)
			return answer;

		else if (n % 2 == 0)	// 짝수일 때
		{
			n = n / 2;		// 2로 나눔
			answer++;		// 횟수 증가
		}
		else		// 홀수일 떄
		{
			n = (n * 3) + 1;	// 3을 곱하고 1을 더함
			answer++;			// 횟수 증가
		}

		std::cout << i << " " << n << std::endl;
	}

	return -1;
}

/*
while(answer++ <= 500){
	num = num%2 ==0 ? num/2 : num*3+1;
	if(num == 1) break;
  }

	return answer > 500 ? -1 : answer;
*/