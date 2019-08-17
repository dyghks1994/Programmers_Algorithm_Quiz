#include "stdafx.h"
#include "Array_Of_DivisibleNumber.h"

Array_Of_DivisibleNumber::Array_Of_DivisibleNumber()
{
	//arr = { 5, 9, 7, 10 };	// 기본 배열 초기화
	arr = { 2, 36, 1, 3 };	// 기본 배열 초기화
	divisor = 1;			// 나눌 수 세팅

	std::vector<int> vec = solution(arr, divisor); // 알고리즘 검사(수행)

	for (auto n : vec)
		std::cout << n << " ";
}

Array_Of_DivisibleNumber::~Array_Of_DivisibleNumber()
{
}

std::vector<int> Array_Of_DivisibleNumber::solution(std::vector<int> arr, int divisor)
{
	std::vector<int> answer;

	for (int i = 0; i < arr.size(); i++)	// 배열 사이즈 만큼 반복하면서
	{
		if (arr.at(i) % divisor == 0)		// 각 엘리먼트를 divisior 로 나눈 나머지가 0인지 검사
			answer.emplace_back(arr.at(i));	// 나머지가 0이라면 answer 에 추가
	}

	//추가된 엘리먼트가 하나도 없으면?
	if (answer.size() == 0)
	{
		answer.emplace_back(-1);	// -1을 추가하고
		return answer;				// answer 리턴
	}
		
	//추가된 answer 배열 정렬
	for (int i = 0; i < answer.size() - 1; i++)
	{
		int min = answer.at(i);	// 남은 엘리먼트중 첫번째를 min값으로 초기화
		int min_index = i;		// min값이 있는 곳의 index 저장


		for (int j = i + 1; j < answer.size(); j++)	// 남은 엘리먼트 중 2번째부터 마지막 엘리먼트까지 반복해서 min값 찾음
		{
			if (answer.at(min_index) > answer.at(j))			// 더 작은 수가 발견되면
			{
				min = answer.at(j);	// 새로 min값 설정
				min_index = j;		// min_index 설정
			}
		}

		// i 인덱스 위치에 있는 값과 min값 swap
		int temp = answer.at(i);
		answer.at(i) = answer.at(min_index);
		answer.at(min_index) = temp;
	}

	return answer;
}
