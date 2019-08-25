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
	// ���������� �̿�
	for(int level = 0; level < s.size() - 1; level++)	// level�� ��ȸ�� °���� �Ǵ��ϴ� ����
		for(int i = 0; i < s.size() - level - 1; i++)	
			if (s[i] < s[i + 1])		// ���� ����(����)���� ���� ����(����)�� �� ũ��
			{
				char temp = s[i];			// �� ���ڸ� ����
				s[i] = s[i + 1];
				s[i + 1] = temp;
			}

	return s;
}
/*
sort (s.begin(), s.end(), greater<char>());	// sort�Լ� �̿��ؼ��� ���� ����
*/