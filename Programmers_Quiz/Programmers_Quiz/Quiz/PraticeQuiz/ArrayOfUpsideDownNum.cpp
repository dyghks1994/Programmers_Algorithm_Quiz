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

	while (temp)	// temp�� 0�� �ƴϸ�
	{
		answer.emplace_back(temp % 10);	// 10���� ���� �������� ���Ϳ� �߰��ϰ� 
		temp /= 10;						// temp�� 10���� ����
	}

	return answer;
}
