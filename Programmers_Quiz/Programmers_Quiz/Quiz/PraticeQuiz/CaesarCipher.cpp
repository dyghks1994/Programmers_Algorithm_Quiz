#include "stdafx.h"
#include "CaesarCipher.h"

CaesarCipher::CaesarCipher()
{
	s = "A  B xyz BAC";	// s에는 공백, 대문자, 소문자 알파벳만 들어간다
	int n = 4;	// 시저암호에서 몇번 밀것인지에 대한 수, (1 <= n <= 25)
	s_ciphered = solution(s, n);

	std::cout << "s = " << s << std::endl;
	std::cout << "s_ciphered = " << s_ciphered << std::endl;

}

CaesarCipher::~CaesarCipher()
{
}

std::string CaesarCipher::solution(std::string s, int n)
{
	std::string answer = "";	// 리턴할 answer 스트링 변수

	for (int i = 0; i < s.size(); i++)	// 스트링 s의 사이즈만큼 반복
	{
		if (s.at(i) == 32)			// s의 i번째 문자가 공백(space)이라면
			answer.push_back(' ');	// answer에 공백 추가

		else // 대문자나 소문자일 경우 
		{
			if (
					// 입력된 스트링이 대문자이고 && n을 더했을 때 대문자의 범위(90)를 넘어가거나 
					(s.at(i) <= 90 && (s.at(i) + n) > 90) ||	//90 = "Z", 91 = "["
					
					// 입력된 스트링이 소문자이고 && n을 더했을 때 소문자의 범위(122)를 넘어간 경우
					(s.at(i) >= 97 && (s.at(i) + n) > 122)		// 122 = "z", 123 = "{"
				)		
				// 더해야할 n의 값을 26만큼 빼서 다시 처음부터 돌아간 것과 같게끔 만든다.
				answer.push_back(s.at(i) + n - 26);	
		
			else
				answer.push_back(s.at(i) + n);	// n만큼 민 문자를 answer에 추가한다.
		}		
	}

	return answer;
}
