#include "stdafx.h"
#include "SumOfDivisor.h"

SumOfDivisor::SumOfDivisor()
{
	std::cout << "�ڿ��� n�� �Է¹޾� n�� ����� ��� ���� ���� �����ϴ� ����" << std::endl;

	int n = 5;
	std::cout << "�Է� n = " << n << std::endl;
	std::cout << n << "�� ����� ���� = " << solution(n) << std::endl;
}

SumOfDivisor::~SumOfDivisor()
{
}

int SumOfDivisor::solution(int n)
{
	int answer = 0;

	int n_half = n / 2;	// � �� n�� �ִ������� 2 / n ���� Ŭ �� �����Ƿ� n_half������ �Ǻ��Ѵ�.

	for (int i = 1; i <= n_half; i++)
	{
		if (n % i == 0)		// �������� 0�̶�� -> ���!
			answer += i;	// ����� ����
	}
	answer += n;	// �ڱ� �ڽŵ� ����̹Ƿ� �������� ���Y�ش�.

	return answer;
}
