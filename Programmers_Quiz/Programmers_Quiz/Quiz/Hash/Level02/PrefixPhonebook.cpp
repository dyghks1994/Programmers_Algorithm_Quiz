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

/// <summary>
/// �ؽ�(unordered_map)�� �̿��� Ǯ��
/// 
/// ��Ȯ�� �׽�Ʈ : ����
/// ȿ���� �׽�Ʈ : ����
/// 
/// �� ��� �ܿ��� ������ �̿��ϴ��� �� �ٸ� �˰����� �̿��� ����� ���� �� �ϴ�.
/// </summary>
/// <param name="phone_book"></param>
/// <returns></returns>
bool PrefixPhonebook::solution(vector<string> phone_book)
{
	bool answer = true;

	std::unordered_map<std::string, int> table;	// �� �κ� ��ȣ�� ���� ī��Ʈ�� ������ ���̺�
	std::string str = "";

	// ������ ��ȣ���� ��ȸ
	for (auto number : phone_book)
	{
		// ��Ʈ�� �ʱ�ȭ
		str = "";

		// �ϳ��� ��ȣ�� �κ� ����(��Ʈ��)�� ��ȸ
		for (auto part : number)
		{
			str += part;	// ��Ʈ���� �ϳ��� �߰��ϸ鼭
			table[str]++;	// ���̺� ���(ī��Ʈ ����)
		}
	}

	// �ٽ� ���Ͽ��� ��ȣ���� ��ȸ
	for (auto number : phone_book)
	{
		// ���Ͽ��� ������ ��ȣ������ ī��Ʈ�� 1���� ũ��
		if (table[number] > 1)
		{
			// ���ξ�� �� ��ȣ�� �־��ٴ� �ǹ�
			answer = false;		// fals�� ����
			break;
		}
	}

	return answer;
}

/// <summary>
/// �� �ٸ� ���� ����(���۸�)
/// ȥ�� �Ӹ��ھ� § �ڵ�
/// �ݺ����� �̿��߰� �Ϲ������� ����� �����ϱ� ����? ��� �״�� �ű� �ڵ�
/// ���� ��ȣ(��Ʈ��)�� �� ��ȣ(��Ʈ��)�� �κ� ��ȣ���� �ϳ��� �÷����鼭 ��ġ�ϴ°� �Ǻ�
/// 
/// ��Ȯ�� �׽�Ʈ : ����
/// ȿ���� �׽�Ʈ : ����
/// </summary>
/// <param name="phone_book"></param>
/// <returns></returns>
bool PrefixPhonebook::solution2(vector<string> phone_book)
{
	// ������ ó�� ���� ������ ��ȣ���� ��ȸ�ϸ鼭 �˻�
	// iter == ���ع�ȣ
	for (vector<string>::iterator iter = phone_book.begin();
		iter != phone_book.end();
		++iter)
	{
		// ���Ͽ��� �ٸ� �ϳ��� �񱳹�ȣ�� �����ؼ� �� �񱳹�ȣ�� �տ������� �κй�ȣ�� �˻�
		for (auto phone_number : phone_book)
		{
			// ���ع�ȣ�� ���� ��ȣ�̸� �н�
			if (*iter == phone_number)
			{
				// ���� ����� ���Ϸ��� ���
				continue;
			}

			// ���ع�ȣ�� ����� ���ʿ� �񱳴�󺸴� ũ�� ���� ���ξ �� �� ����. (�н�)
			if ((*iter).size() > phone_number.size())
			{
				continue;
			}

			// ���� ��ȣ�� �κ��� ������ ��Ʈ��
			std::string temp;

			// 0�� �ε������� �����ŭ �÷����� �񱳹�ȣ�� �ø���
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
