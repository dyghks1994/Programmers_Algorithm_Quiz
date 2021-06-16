#include "stdafx.h"
#include "PrefixPhonebook.h"

PrefixPhonebook::PrefixPhonebook()
{
	cout
		<< "��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.\n"
		<< "��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.\n"

		<< "������ : 119\n"
		<< "���ؿ� : 97 674 223\n"
		<< "������ : 11 9552 4421\n"
		<< "��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.\n"

		<< "���� ����\n"
		<< "phone_book�� ���̴� 1 �̻� 1, 000, 000 �����Դϴ�.\n"
		<< "�� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.\n"
		<< "���� ��ȭ��ȣ�� �ߺ��ؼ� ������� �ʽ��ϴ�.\n"
		<< std::endl;

	/// ������ �ʿ��� �غ� ����
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
	

	/// ���� ��
	std::cout << "��� = " << boolalpha << solution(vec1) << std::endl;
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
				// ���� ����� ���Ϸ��� ���
				continue;
			}

			// *iter �� ��ȣ�� ����� ���ʿ� �񱳴�󺸴� ũ�� ���� ���ξ �� �� ����.
			if ((*iter).size() > phone_number.size())
			{
				continue;
			}

			// ���� ��ȣ�� �κ��� ������ ��Ʈ��
			std::string temp;

			for (int i = 0; i < phone_number.size(); i++)
			{
				// ���ڿ� �߰�(��ȣ �ϳ� ��)
				temp += phone_number[i];

				// ���� �� ��ȣ�� ������� Ŀ���� ���� �񱳴� �ǹ� ����
				if (temp.size() > (*iter).size())
				{
					break;
				}

				// iter ��ȣ�� phone_number �� �κ� ��ȣ�� ���ٸ�?
				// ���ξ��̴�!
				if (strcmp((*iter).c_str(), temp.c_str()) == 0)
				{
					return false;
				}
			}
		}
	}

	return true;
}
