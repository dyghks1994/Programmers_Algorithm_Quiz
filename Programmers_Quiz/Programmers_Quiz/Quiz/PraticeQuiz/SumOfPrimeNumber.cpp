#include "stdafx.h"
#include "SumOfPrimeNumber.h"

SumOfPrimeNumber::SumOfPrimeNumber()
{
	int n = 10;		// �Է� n��, 2 <= n <= 10,000,000
	std::cout << "[2 ~ n ���� �� �Ҽ��� ���� ���ϱ�]" << std::endl;
	std::cout << "n = " << n << std::endl;

	std::cout << "2 ~ " << n << " ���� �� ��� �Ҽ��� ���� = " << solution(n) << std::endl;
}

SumOfPrimeNumber::~SumOfPrimeNumber()
{
}

long long SumOfPrimeNumber::solution(int N)
{
	long long answer = 0;	// �Ҽ����� ���� ������ ����, n�� �ּ� �Է°��� 2�̰� 2�� �Ҽ� �� ������ ¦���̹Ƿ� �׻� ���ϰ� ��
	

	std::vector<bool> primeVector;	// �����佺�׳׽��� ü�� ����� bool ����

	/*
	2���� N���� n-1���� ������ �� �ִ� �迭 �Ҵ�
	�迭 ���� ��ȣ�� �Ҽ��� ��ġ�ϵ��� �迭�� ũ���
	n + 1 ���̸�ŭ �Ҵ�(�ε��� ��ȣ 0�� 1�� ������� ����)

	ex) N = 10�̸�
	11�� size��ŭ �޸� �Ҵ�
	vecter �ε����� 0 ~ 10
	�ε��� 0, 1�� ������(0, 1�� �Ҽ� �ƴ�) -> 2 ~ 10 ���
	*/
	primeVector.reserve(N + 1);
	primeVector.resize(N + 1);

	for (int i = 2; i <= N; i++)
		primeVector[i] = true;	// �ʱ⿡ ���� true�� ����

	/*	�����佺�׳׽��� ü�� �°� �Ҽ��� ����
		����, primeVector[i]�� true�̸� i ������ i ����� ����� i��
		������ �ִ� ���� �ǹǷ� i ������ i ����� ���� false���� �ش�.
		primeVector[i]�� false�̸� i�� �̹� �Ҽ��� �ƴϹǷ� i�� ��� ����
		�Ҽ��� �ƴϰ� �ȴ�. �׷��Ƿ� �˻��� �ʿ䵵 ����.
	*/

	for (int i = 2; i * i <= N; i++)	// �Ǿ� �Ҽ� 2���� �����ؼ�, i�� ����� �־��� N�� ���� �ȿ� �ִ� ����
	{
		if (primeVector[i])	// ���� �Ҽ�(true)�� ���� �Ǿ� �ִٸ�
		{
			for (int j = i * 2; j <= N; j += i)	// i(�Ҽ�)�� ������� ����
				primeVector[j] = false;			// false��(�Ҽ��� �ƴ�) ����
		}	
	}		
		
	for(int i = 2; i<= N; i++)
		if(primeVector[i])	// �Ҽ����, true�� �����Ǿ� �ִٸ�
			answer += i;	// answer�� i ����
	
	return answer;
}