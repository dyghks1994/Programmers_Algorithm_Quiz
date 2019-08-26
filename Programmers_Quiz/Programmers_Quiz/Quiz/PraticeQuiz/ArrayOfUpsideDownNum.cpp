#include "stdafx.h"
#include "ArrayOfUpsideDownNum.h"

ArrayOfUpsideDownNum::ArrayOfUpsideDownNum()
{
	long long n = 12345;
	std::vector<int> v = solution(n);

	std::cout << "n = " << n << std::endl;
	std::cout << "ArrayOfUpsideDownNum(n) = ";
	for (auto i : v)
		std::cout << i << " ";
}

ArrayOfUpsideDownNum::~ArrayOfUpsideDownNum()
{
}

std::vector<int> ArrayOfUpsideDownNum::solution(long long n)
{
	std::vector<int> answer;

	long long temp = n;

	while (temp)	// temp가 0이 아니면
	{
		answer.emplace_back(temp % 10);	// 10으로 나눈 나머지를 벡터에 추가하고 
		temp /= 10;						// temp를 10으로 나눔
	}

	return answer;
}
