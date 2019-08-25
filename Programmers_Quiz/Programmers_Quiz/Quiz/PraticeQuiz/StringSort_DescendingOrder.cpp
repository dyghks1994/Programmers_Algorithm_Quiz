#include "stdafx.h"
#include "StringSort_DescendingOrder.h"

StringSort_DescendingOrder::StringSort_DescendingOrder()
{
	std::string s = "Zbcdefg";
	std::cout << "s = "  << s  << std::endl;

	std::string s2 = solution(s);
	std::cout << "s2 = " << s2 << std::endl;
}

StringSort_DescendingOrder::~StringSort_DescendingOrder()
{
}

std::string StringSort_DescendingOrder::solution(std::string s)
{
	// 버블정렬을 이용
	for(int level = 0; level < s.size() - 1; level++)	// level은 몇회전 째인지 판단하는 변수
		for(int i = 0; i < s.size() - level - 1; i++)	
			if (s[i] < s[i + 1])		// 현재 원소(문자)보다 다음 원소(문자)가 더 크면
			{
				char temp = s[i];			// 두 문자를 스왑
				s[i] = s[i + 1];
				s[i + 1] = temp;
			}

	return s;
}
/*
sort (s.begin(), s.end(), greater<char>());	// sort함수 이용해서도 쉽게 가능
*/