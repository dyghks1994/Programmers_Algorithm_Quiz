#include "stdafx.h"
#include "SumOfDivisor.h"

SumOfDivisor::SumOfDivisor()
{
	std::cout << "자연수 n을 입력받아 n의 약수를 모두 더한 값을 리턴하는 문제" << std::endl;

	int n = 5;
	std::cout << "입력 n = " << n << std::endl;
	std::cout << n << "의 약수의 합은 = " << solution(n) << std::endl;
}

SumOfDivisor::~SumOfDivisor()
{
}

int SumOfDivisor::solution(int n)
{
	int answer = 0;

	int n_half = n / 2;	// 어떤 수 n의 최대공약수는 2 / n 보다 클 수 없으므로 n_half까지만 판별한다.

	for (int i = 1; i <= n_half; i++)
	{
		if (n % i == 0)		// 나머지가 0이라면 -> 약수!
			answer += i;	// 약수를 더함
	}
	answer += n;	// 자기 자신도 약수이므로 마지막에 더햊준다.

	return answer;
}
