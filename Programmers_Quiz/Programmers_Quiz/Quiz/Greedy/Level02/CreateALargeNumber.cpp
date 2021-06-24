#include "stdafx.h"
#include "CreateALargeNumber.h"

CreateALargeNumber::CreateALargeNumber()
{
	/// <summary>
	///  ���� ���
	/// </summary>
	std::cout
		<< "[��������]  "																												<< std::endl
		<< "� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.   "												<< std::endl
		<< "���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. "									<< std::endl
		<< "�� �� ���� ū ���ڴ� 94 �Դϴ�."																								<< std::endl 
		<< "���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. "										<< std::endl 
		<< "number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���."	<< std::endl << std::endl
		
		<< "[���ѻ���]" << std::endl
		<< "number�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�." << std::endl
		<< "k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�." << std::endl
		<< std::endl;

	/// ������ �ʿ��� �Է� �غ�
	// �׽�Ʈ ���̽� 1
	std::string number = "1924";
	int k = 2;

	// �׽�Ʈ ���̽� 2
	std::string number2 = "1231234";
	int k2 = 3;

	// �׽�Ʈ ���̽� 3
	std::string number3 = "4177252841";
	int k3 = 4;

	// Ŀ���� �׽�Ʈ ���̽� 
	std::string number4 = "1000";
	int k4 = 1;

	/// ��� ����
	std::cout << "���� = " << number3					  << std::endl;
	std::cout << "k    = " << k3						  << std::endl;
	std::cout << "��� = " << solution2(number3.c_str(), k3) << std::endl;
}

CreateALargeNumber::~CreateALargeNumber()
{
}

/// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
std::string CreateALargeNumber::solution(std::string number, int k)
{
	std::string answer = number;

	// k�� ��ŭ �ݺ�
	for (int i = 0; i < k; i++)
	{
		// ���� ���� ������ �ε����� �ʱ�ȭ
		int minIndex = 0;

		while (true)
		{
			// �ε����� �� ������ ������ ��ġ���� �Դٸ�
			if (minIndex == answer.size() - 1)
			{
				// ������ ���� ����
				answer.erase(answer.size() - 1, 1);

				break;
			}

			// ���� ���ڿ� ���� ���ڸ� ���ؼ� ���� ���ڰ� �� ������
			if (answer[minIndex] < answer[minIndex + 1])
			{
				// �� ���� ���� �� �ٽ� ó�� ���ں��� �ݺ�
				answer.erase(minIndex, 1);

				break;
			}

			// ���� ���ڰ� ���� ���ں��� ���� ������ 
			// �ε����� ������Ű�� ���� ���ڿ� �ٴ��� ���� ��
			minIndex++;
		}

	}

	return answer;
}

std::string CreateALargeNumber::solution2(std::string number, int k)
{
	std::string answer = "";
	answer = number.substr(k);
	
	for (int i = k - 1; i >= 0; i--) {
		int j = 0;
		
		do {
			if (number[i] >= answer[j]) {
				char temp = answer[j];
				answer[j] = number[i];
				number[i] = temp;
				j++;
			}

			else 
			{
				break;
			}

		} while (1);
	}



	return answer;
}

