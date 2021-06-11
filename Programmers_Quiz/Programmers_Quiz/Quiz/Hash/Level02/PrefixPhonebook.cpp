#include "stdafx.h"
#include "PrefixPhonebook.h"

PrefixPhonebook::PrefixPhonebook()
{
	cout
		<< "전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.\n"
		<< "전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.\n"

		<< "구조대 : 119\m"
		<< "박준영 : 97 674 223\n"
		<< "지영석 : 11 9552 4421\n"
		<< "전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.\n"

		<< "제한 사항\n"
		<< "phone_book의 길이는 1 이상 1, 000, 000 이하입니다.\n"
		<< "각 전화번호의 길이는 1 이상 20 이하입니다.\n"
		<< "같은 전화번호가 중복해서 들어있지 않습니다.\n"
		<< std::endl;

	/// 문제에 필요한 준비 세팅
	std::vector<std::string> vec;
	vec.emplace_back("119");
	vec.emplace_back("9764223");
	vec.emplace_back("1195524421");

	/// 문제 답
	std::cout << solution(vec) << std::endl;
}

PrefixPhonebook::~PrefixPhonebook()
{
}

bool PrefixPhonebook::solution(vector<string> phone_book)
{
	for (auto number : phone_book)
	{

	}
	return false;
}
