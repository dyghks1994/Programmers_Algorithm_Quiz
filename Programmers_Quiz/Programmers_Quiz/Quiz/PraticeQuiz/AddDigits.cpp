#include "stdafx.h"
#include "AddDigits.h"

AddDigits::AddDigits()
{
	int n = 123;	// 제공할 수

	std::cout << "입력된 수 n의 모든 각 자릿수를 더하는 알고리즘" << std::endl;
	std::cout << "입력 숫자 : " << n << std::endl;
	std::cout << "각 자릿수를 모두 더한 리턴 값은? : " <<solution(n);
}

AddDigits::~AddDigits()
{
}

int AddDigits::solution(int n)
{
	int answer = 0;			// 누적수 0으로 초기화

	for (; n > 0; n /= 10)	// n이 0보다 크면 반복 수행, n을 감소할 땐 10으로 나누어 맨 오른쪽 1의자리 수를 날림
	{
		answer += (n % 10); // n을 10으로 나누어 1의자리 수를 추출한 다음 answer에 누적
	}

	return answer;
}
