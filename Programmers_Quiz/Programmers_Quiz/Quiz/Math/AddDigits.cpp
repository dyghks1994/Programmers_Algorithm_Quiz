#include "stdafx.h"
#include "AddDigits.h"

AddDigits::AddDigits()
{
	int n = 123;	// ������ ��

	std::cout << "�Էµ� �� n�� ��� �� �ڸ����� ���ϴ� �˰���" << std::endl;
	std::cout << "�Է� ���� : " << n << std::endl;
	std::cout << "�� �ڸ����� ��� ���� ���� ����? : " <<solution(n);
}

AddDigits::~AddDigits()
{
}

int AddDigits::solution(int n)
{
	int answer = 0;			// ������ 0���� �ʱ�ȭ

	for (; n > 0; n /= 10)	// n�� 0���� ũ�� �ݺ� ����, n�� ������ �� 10���� ������ �� ������ 1���ڸ� ���� ����
	{
		answer += (n % 10); // n�� 10���� ������ 1���ڸ� ���� ������ ���� answer�� ����
	}

	return answer;
}
