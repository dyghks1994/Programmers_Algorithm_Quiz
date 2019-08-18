#include "stdafx.h"
#include "Array_Of_DivisibleNumber.h"

Array_Of_DivisibleNumber::Array_Of_DivisibleNumber()
{
	//arr = { 5, 9, 7, 10 };	// �⺻ �迭 �ʱ�ȭ
	arr = { 2, 36, 1, 3 };	// �⺻ �迭 �ʱ�ȭ
	divisor = 1;			// ���� �� ����

	std::vector<int> vec = solution(arr, divisor); // �˰��� �˻�(����)

	for (auto n : vec)
		std::cout << n << " ";
}

Array_Of_DivisibleNumber::~Array_Of_DivisibleNumber()
{
}

std::vector<int> Array_Of_DivisibleNumber::solution(std::vector<int> arr, int divisor)
{
	std::vector<int> answer;

	for (int i = 0; i < arr.size(); i++)	// �迭 ������ ��ŭ �ݺ��ϸ鼭
	{
		if (arr.at(i) % divisor == 0)		// �� ������Ʈ�� divisior �� ���� �������� 0���� �˻�
			answer.emplace_back(arr.at(i));	// �������� 0�̶�� answer �� �߰�
	}

	//�߰��� ������Ʈ�� �ϳ��� ������?
	if (answer.size() == 0)
	{
		answer.emplace_back(-1);	// -1�� �߰��ϰ�
		return answer;				// answer ����
	}
		
	//�߰��� answer �迭 ����
	for (int i = 0; i < answer.size() - 1; i++)
	{
		int min = answer.at(i);	// ���� ������Ʈ�� ù��°�� min������ �ʱ�ȭ
		int min_index = i;		// min���� �ִ� ���� index ����


		for (int j = i + 1; j < answer.size(); j++)	// ���� ������Ʈ �� 2��°���� ������ ������Ʈ���� �ݺ��ؼ� min�� ã��
		{
			if (answer.at(min_index) > answer.at(j))			// �� ���� ���� �߰ߵǸ�
			{
				min = answer.at(j);	// ���� min�� ����
				min_index = j;		// min_index ����
			}
		}

		// i �ε��� ��ġ�� �ִ� ���� min�� swap
		int temp = answer.at(i);
		answer.at(i) = answer.at(min_index);
		answer.at(min_index) = temp;
	}

	return answer;
}
