#include "stdafx.h"
#include "CollatzConjecture.h"

CollatzConjecture::CollatzConjecture()
{
	long n = 626331;
	std::cout << "<�ݶ��� ���� ����>" << std::endl;
	std::cout << "�Էµ� �� = " << n << std::endl;
	std::cout << "soluction(" << n << ") = " << solution(n) << std::endl;
}

CollatzConjecture::~CollatzConjecture()
{
}

int CollatzConjecture::solution(int num)
{
	int answer = 0;
	long long n = num;	// ������ int�� ������ �Ѿ�� ����ε� ������ �ȵǱ� ������ long long ���� ��ȯ

	for (int i = 1; i <= 500; i++)	// �ִ� 500�� �ݺ�
	{
		if (n == 1)
			return answer;

		else if (n % 2 == 0)	// ¦���� ��
		{
			n = n / 2;		// 2�� ����
			answer++;		// Ƚ�� ����
		}
		else		// Ȧ���� ��
		{
			n = (n * 3) + 1;	// 3�� ���ϰ� 1�� ����
			answer++;			// Ƚ�� ����
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