#include "stdafx.h"
#include "PrefixPhonebook.h"

PrefixPhonebook::PrefixPhonebook()
{
	cout
		<< "��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.\n"
		<< "��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.\n"

		<< "������ : 119\m"
		<< "���ؿ� : 97 674 223\n"
		<< "������ : 11 9552 4421\n"
		<< "��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.\n"

		<< "���� ����\n"
		<< "phone_book�� ���̴� 1 �̻� 1, 000, 000 �����Դϴ�.\n"
		<< "�� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.\n"
		<< "���� ��ȭ��ȣ�� �ߺ��ؼ� ������� �ʽ��ϴ�.\n"
		<< std::endl;

	/// ������ �ʿ��� �غ� ����
	std::vector<std::string> vec;
	vec.emplace_back("119");
	vec.emplace_back("9764223");
	vec.emplace_back("1195524421");

	/// ���� ��
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
