#include "stdafx.h"
#include "ExtractNotSameNum.h"

ExtractNotSameNum::ExtractNotSameNum()
{
	//std::vector<int> v1 = { 1, 1, 3, 3, 0, 1, 1 };
	std::vector<int> v1 = { 1, 2, 3, 3 };
	std::vector<int> v2 = solution(v1);

	std::cout << "v1 = ";
	for (auto n : v1)
		std::cout << n << " ";
	std::cout << std::endl;

	std::cout << "v2 = ";
	for (auto n : v2)
		std::cout << n << " ";
	std::cout << std::endl;

}

ExtractNotSameNum::~ExtractNotSameNum()
{
}

std::vector<int> ExtractNotSameNum::solution(std::vector<int> arr)
{
	std::vector<int> answer;

	answer.emplace_back(arr[0]);	// 첫번 째 숫자를 추가

	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] != arr[i - 1])			// 이전에 나온 숫자랑 다르면
			answer.emplace_back(arr[i]);	// 벡터에 추가
	}

	return answer;
}
