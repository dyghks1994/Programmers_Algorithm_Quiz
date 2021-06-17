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

/// <summary>
/// 해쉬(unordered_map)를 이용한 풀이
/// 
/// 정확성 테스트 : 성공
/// 효율성 테스트 : 성공
/// 
/// 이 방법 외에도 정렬을 이용하던가 또 다른 알고리즘을 이용한 방법도 많은 듯 하다.
/// </summary>
/// <param name="phone_book"></param>
/// <returns></returns>
bool PrefixPhonebook::solution(vector<string> phone_book)
{
	bool answer = true;

	std::unordered_map<std::string, int> table;	// 각 부분 번호에 대한 카운트를 저장할 테이블
	std::string str = "";

	// 폰북의 번호들을 순회
	for (auto number : phone_book)
	{
		// 스트링 초기화
		str = "";

		// 하나의 번호의 부분 숫자(스트링)을 순회
		for (auto part : number)
		{
			str += part;	// 스트링을 하나씩 추가하면서
			table[str]++;	// 테이블에 등록(카운트 증가)
		}
	}

	// 다시 폰북에서 번호들을 순회
	for (auto number : phone_book)
	{
		// 폰북에서 완전한 번호에대한 카운트가 1보다 크면
		if (table[number] > 1)
		{
			// 접두어로 된 번호가 있었다는 의미
			answer = false;		// fals로 세팅
			break;
		}
	}

	return answer;
}

/// <summary>
/// 별 다른 도움 없이(구글링)
/// 혼자 머리박아 짠 코드
/// 반복문을 이용했고 일반적으로 사람이 생각하기 편한? 방식 그대로 옮긴 코드
/// 기준 번호(스트링)에 비교 번호(스트링)의 부분 번호들을 하나씩 늘려가면서 일치하는가 판별
/// 
/// 정확성 테스트 : 성공
/// 효율성 테스트 : 실패
/// </summary>
/// <param name="phone_book"></param>
/// <returns></returns>
bool PrefixPhonebook::solution2(vector<string> phone_book)
{
	// 폰북의 처음 부터 마지막 번호까지 순회하면서 검사
	// iter == 기준번호
	for (vector<string>::iterator iter = phone_book.begin();
		iter != phone_book.end();
		++iter)
	{
		// 폰북에서 다른 하나의 비교번호를 선택해서 그 비교번호의 앞에서부터 부분번호를 검사
		for (auto phone_number : phone_book)
		{
			// 기준번호와 같은 번호이면 패스
			if (*iter == phone_number)
			{
				// 같은 대상을 비교하려는 경우
				continue;
			}

			// 기준번호의 사이즈가 애초에 비교대상보다 크면 절대 접두어가 될 수 없다. (패스)
			if ((*iter).size() > phone_number.size())
			{
				continue;
			}

			// 비교할 번호의 부분을 저장할 스트링
			std::string temp;

			// 0번 인덱스부터 사이즈만큼 늘려가며 비교번호를 늘리기
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
