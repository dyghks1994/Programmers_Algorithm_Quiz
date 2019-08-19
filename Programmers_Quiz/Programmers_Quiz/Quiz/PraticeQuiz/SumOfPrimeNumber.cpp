#include "stdafx.h"
#include "SumOfPrimeNumber.h"

SumOfPrimeNumber::SumOfPrimeNumber()
{
	int n = 10;		// 입력 n값, 2 <= n <= 10,000,000
	std::cout << "[2 ~ n 까지 중 소수의 합을 구하기]" << std::endl;
	std::cout << "n = " << n << std::endl;

	std::cout << "2 ~ " << n << " 까지 중 모든 소수의 합은 = " << solution(n) << std::endl;
}

SumOfPrimeNumber::~SumOfPrimeNumber()
{
}

long long SumOfPrimeNumber::solution(int N)
{
	long long answer = 0;	// 소수들의 합을 누적할 변수, n의 최소 입력값은 2이고 2는 소수 중 유일한 짝수이므로 항상 더하게 됌
	

	std::vector<bool> primeVector;	// 에라토스테네스의 체로 사용할 bool 벡터

	/*
	2부터 N까지 n-1개를 저장할 수 있는 배열 할당
	배열 참조 번호와 소수를 일치하도록 배열의 크기는
	n + 1 길이만큼 할당(인덱스 번호 0과 1은 사용하지 않음)

	ex) N = 10이면
	11개 size만큼 메모리 할당
	vecter 인덱스는 0 ~ 10
	인덱스 0, 1은 사용안함(0, 1은 소수 아님) -> 2 ~ 10 사용
	*/
	primeVector.reserve(N + 1);
	primeVector.resize(N + 1);

	for (int i = 2; i <= N; i++)
		primeVector[i] = true;	// 초기에 전부 true로 설정

	/*	에라토스테네스의 체에 맞게 소수를 구함
		만일, primeVector[i]가 true이면 i 이후의 i 배수는 약수로 i를
		가지고 있는 것이 되므로 i 이후의 i 배수에 대해 false값을 준다.
		primeVector[i]가 false이면 i는 이미 소수가 아니므로 i의 배수 역시
		소수가 아니게 된다. 그러므로 검사할 필요도 없다.
	*/

	for (int i = 2; i * i <= N; i++)	// 맨앞 소수 2부터 시작해서, i의 배수가 주어진 N의 범위 안에 있는 동안
	{
		if (primeVector[i])	// 현재 소수(true)로 설정 되어 있다면
		{
			for (int j = i * 2; j <= N; j += i)	// i(소수)의 배수들을 전부
				primeVector[j] = false;			// false로(소수가 아님) 설정
		}	
	}		
		
	for(int i = 2; i<= N; i++)
		if(primeVector[i])	// 소수라면, true로 설정되어 있다면
			answer += i;	// answer에 i 누적
	
	return answer;
}