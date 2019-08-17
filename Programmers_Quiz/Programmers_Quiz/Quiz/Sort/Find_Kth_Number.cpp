#include "stdafx.h"
#include "Find_Kth_Number.h"


Find_Kth_Number::Find_Kth_Number()
{
	Initialize();					// Ǯ�̿� �ʿ��� �ڷ�� �ʱ�ȭ
	PrintQuiz();					// ���� ����
	solution(array, commands);		// ����Ǯ�� �˰��� ����
	PrintAnswer();					// ���ϰ� ���

}

Find_Kth_Number::~Find_Kth_Number()
{
}

void Find_Kth_Number::PrintQuiz()
{
	std::cout << "[K��° �� ���ϱ� ����]" << std::endl;
	std::cout << "�迭 array�� i��° ���ں��� j��° ���ڱ��� �ڸ��� �������� ��, k��°�� �ִ� ���� ���Ϸ� �մϴ�." << std::endl;
	std::cout << "���� ��� array��[1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3�̶��" << std::endl;
	std::cout << "array�� 2��°���� 5��°���� �ڸ���[5, 2, 6, 3]�Դϴ�." << std::endl;
	std::cout << "1���� ���� �迭�� �����ϸ�[2, 3, 5, 6]�Դϴ�." << std::endl;
	std::cout << "2���� ���� �迭�� 3��° ���ڴ� 5�Դϴ�." << std::endl;
	std::cout << "�迭 array, [i, j, k]�� ���ҷ� ���� 2���� �迭 commands�� �Ű������� �־��� ��, commands�� ��� ���ҿ� ���� �ռ� ������ ������ �������� �� ���� ����� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���." << std::endl << std::endl;
	
	std::cout << "���ѻ���" << std::endl;
	std::cout << "array�� ���̴� 1 �̻� 100 �����Դϴ�." << std::endl;
	std::cout << "array�� �� ���Ҵ� 1 �̻� 100 �����Դϴ�." << std::endl;
	std::cout << "commands�� ���̴� 1 �̻� 50 �����Դϴ�." << std::endl;
	std::cout << "commands�� �� ���Ҵ� ���̰� 3�Դϴ�." << std::endl << std::endl;
	
	std::cout << "����� ��" << std::endl;
	std::cout << setw(0) << "array" << setw(27) << "commands" << setw(35) << "return" << std::endl;
	std::cout << "[1, 5, 2, 6, 3, 7, 4] | [[2, 5, 3], [4, 4, 1], [1, 7, 3]] | [5, 6, 3]" << std::endl << std::endl;
	
	std::cout << "����� �� ����" << std::endl;
	std::cout << "[1, 5, 2, 6, 3, 7, 4]�� 2��°���� 5��°���� �ڸ� �� �����մϴ�.[2, 3, 5, 6]�� �� ��° ���ڴ� 5�Դϴ�." << std::endl;
	std::cout << "[1, 5, 2, 6, 3, 7, 4]�� 4��°���� 4��°���� �ڸ� �� �����մϴ�.[6]�� ù ��° ���ڴ� 6�Դϴ�." << std::endl;
	std::cout << "[1, 5, 2, 6, 3, 7, 4]�� 1��°���� 7��°���� �ڸ��ϴ�.[1, 2, 3, 4, 5, 6, 7]�� �� ��° ���ڴ� 3�Դϴ�. " << std::endl << std::endl;
}

void Find_Kth_Number::Initialize()
{
	// ���� �迭 �ʱ�ȭ
	array.emplace_back(1);
	array.emplace_back(5);
	array.emplace_back(2);
	array.emplace_back(6);
	array.emplace_back(3);
	array.emplace_back(7);
	array.emplace_back(4);

	//���� �迭
	std::vector<int> condition1;
	condition1.emplace_back(2);
	condition1.emplace_back(5);
	condition1.emplace_back(3);

	std::vector<int> condition2;
	condition2.emplace_back(4);
	condition2.emplace_back(4);
	condition2.emplace_back(1);
	
	std::vector<int> condition3;
	condition3.emplace_back(1);
	condition3.emplace_back(7);
	condition3.emplace_back(3);

	commands.emplace_back(condition1);
	commands.emplace_back(condition2);
	commands.emplace_back(condition3);
}

void Find_Kth_Number::PrintAnswer()
{
	std::cout << "<return>" << std::endl;
	std::cout << "[";
	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer.at(i) << ",  ";
	}
	std::cout << "]" << std::endl;
		
	std::cout << answer.size();
}

vector<int> Find_Kth_Number::solution(vector<int> array, vector<vector<int>> commands)
{
	for (int i = 0; i < commands.size(); i++)	// �ݺ��ؾ��ϴ� ������ �� ��ŭ �ݺ��ؼ� ���� ����
	{
		std::vector<int> temp_array;    // �߶� ������ �ӽ� �迭 ����

		// condition [x, y, z] ���� x ~ y����
		// 0���� �����ϴ� �迭 �ε����� ��Ī�ϱ� ���� -1�� ����
		for (int j = (commands.at(i).at(0)) - 1; j <= (commands.at(i).at(1)) - 1; j++)
		{
			temp_array.emplace_back(array.at(j));	//�ӽù迭�� ���� �߰�
		}

		// ���� ����
		for (int j = 0; j < temp_array.size() - 1; j++)	// temp_array ������������ ����
		{
			int min = temp_array.at(j);	// ���� �� �߿��� ù��°�� ���� ���� ���� ����
			int min_index = j;          // �ε��� ����

			for (int k = j + 1; k < temp_array.size(); k++)
			{
				// ���� ���� ���� ���� ���� ������ ũ��?
				if (temp_array.at(min_index) > temp_array.at(k))
				{
					min = temp_array.at(k);		// ���� ���� ���� ���� ���� ����
					min_index = k;				// ���� ���� ���� �ִ� �ε��� ����
				}
			}

			// swap
			int temp;
			temp = temp_array.at(j);
			temp_array.at(j) = temp_array.at(min_index);
			temp_array.at(min_index) = temp;

			// �־��� ���� [x, y, z]���� x ~ y��° ���� �ڸ��� ���� �Ϸ�
			//===========================================================
		}
		answer.emplace_back(temp_array.at(commands.at(i).at(2) - 1));	// answer�� �� �߰�
	}
	return answer;
}
