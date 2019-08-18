#include "stdafx.h"
#include "CaesarCipher.h"

CaesarCipher::CaesarCipher()
{
	s = "A  B xyz BAC";	// s���� ����, �빮��, �ҹ��� ���ĺ��� ����
	int n = 4;	// ������ȣ���� ��� �а������� ���� ��, (1 <= n <= 25)
	s_ciphered = solution(s, n);

	std::cout << "s = " << s << std::endl;
	std::cout << "s_ciphered = " << s_ciphered << std::endl;

}

CaesarCipher::~CaesarCipher()
{
}

std::string CaesarCipher::solution(std::string s, int n)
{
	std::string answer = "";	// ������ answer ��Ʈ�� ����

	for (int i = 0; i < s.size(); i++)	// ��Ʈ�� s�� �����ŭ �ݺ�
	{
		if (s.at(i) == 32)			// s�� i��° ���ڰ� ����(space)�̶��
			answer.push_back(' ');	// answer�� ���� �߰�

		else // �빮�ڳ� �ҹ����� ��� 
		{
			if (
					// �Էµ� ��Ʈ���� �빮���̰� && n�� ������ �� �빮���� ����(90)�� �Ѿ�ų� 
					(s.at(i) <= 90 && (s.at(i) + n) > 90) ||	//90 = "Z", 91 = "["
					
					// �Էµ� ��Ʈ���� �ҹ����̰� && n�� ������ �� �ҹ����� ����(122)�� �Ѿ ���
					(s.at(i) >= 97 && (s.at(i) + n) > 122)		// 122 = "z", 123 = "{"
				)		
				// ���ؾ��� n�� ���� 26��ŭ ���� �ٽ� ó������ ���ư� �Ͱ� ���Բ� �����.
				answer.push_back(s.at(i) + n - 26);	
		
			else
				answer.push_back(s.at(i) + n);	// n��ŭ �� ���ڸ� answer�� �߰��Ѵ�.
		}		
	}

	return answer;
}
