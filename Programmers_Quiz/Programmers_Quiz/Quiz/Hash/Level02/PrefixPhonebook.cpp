#include "stdafx.h"
#include "PrefixPhonebook.h"

PrefixPhonebook::PrefixPhonebook()
{
	cout
		<< "전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.\n"
		<< "전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.\n"

		<< "구조대 : 119\n"
		<< "박준영 : 97 674 223\n"
		<< "지영석 : 11 9552 4421\n"
		<< "전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.\n"

		<< "제한 사항\n"
		<< "phone_book의 길이는 1 이상 1, 000, 000 이하입니다.\n"
		<< "각 전화번호의 길이는 1 이상 20 이하입니다.\n"
		<< "같은 전화번호가 중복해서 들어있지 않습니다.\n"
		<< std::endl;

	/// 문제에 필요한 준비 세팅
	std::vector<std::string> vec1;
	vec1.emplace_back("1195524421");
	vec1.emplace_back("9764223");
	vec1.emplace_back("119");
	
	std::vector<std::string> vec2;
	vec2.emplace_back("123");
	vec2.emplace_back("456");
	vec2.emplace_back("789");

	std::vector<std::string> vec3;
	vec3.emplace_back("12");
	vec3.emplace_back("123");
	vec3.emplace_back("1235");
	vec3.emplace_back("567");
	vec3.emplace_back("88");
	

	/// 문제 답
	std::cout << "결과 = " << boolalpha << solution(vec1) << std::endl;
}

PrefixPhonebook::~PrefixPhonebook()
{
}

bool PrefixPhonebook::solution(vector<string> phone_book)
{
	for (vector<string>::iterator iter = phone_book.begin();
		iter != phone_book.end();
		++iter)
	{
		for (auto phone_number : phone_book)
		{
			if (*iter == phone_number)
			{
				// 같은 대상을 비교하려는 경우
				continue;
			}

			// *iter 의 번호의 사이즈가 애초에 비교대상보다 크면 절대 접두어가 될 수 없다.
			if ((*iter).size() > phone_number.size())
			{
				continue;
			}

			// 비교할 번호의 부분을 저장할 스트링
			std::string temp;

			for (int i = 0; i < phone_number.size(); i++)
			{
				// 문자열 추가(번호 하나 더)
				temp += phone_number[i];

				// 비교할 원 번호의 사이즈보다 커지면 뒤의 비교는 의미 없음
				if (temp.size() > (*iter).size())
				{
					break;
				}

				// iter 번호와 phone_number 의 부분 번호가 같다면?
				// 접두어이다!
				if (strcmp((*iter).c_str(), temp.c_str()) == 0)
				{
					return false;
				}
			}
		}
	}

	return true;
}
