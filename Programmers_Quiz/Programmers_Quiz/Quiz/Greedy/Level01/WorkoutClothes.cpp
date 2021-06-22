#include "stdafx.h"
#include "WorkoutClothes.h"

WorkoutClothes::WorkoutClothes()
{
	std::cout
		<< "[��������]  "																																		<< std::endl
		<< "���ɽð��� ������ ���, �Ϻ� �л��� ü������ �������߽��ϴ�.  "																						<< std::endl
		<< "������ ���� ü������ �ִ� �л��� �̵鿡�� ü������ �����ַ� �մϴ�. "																					<< std::endl
		<< "�л����� ��ȣ�� ü�� ������ �Ű��� �־�, �ٷ� �չ�ȣ�� �л��̳� �ٷ� �޹�ȣ�� �л����Ը� ü������ ������ �� �ֽ��ϴ�.  "									<< std::endl
		<< "���� ���, 4�� �л��� 3�� �л��̳� 5�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. "																		<< std::endl
		<< "ü������ ������ ������ ���� �� ���� ������ ü������ ������ ���� �ִ��� ���� �л��� ü�������� ���� �մϴ�. "											<< std::endl
		<< "��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, ������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��, "	<< std::endl
		<< "ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���."																	<< std::endl << std::endl

		<< "[���ѻ���]"																																			<< std::endl
		<< "��ü �л��� ���� 2�� �̻� 30�� �����Դϴ�."																											<< std::endl
		<< "ü������ �������� �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�."																			<< std::endl
		<< "������ ü������ ������ �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�."																		<< std::endl
		<< "���� ü������ �ִ� �л��� �ٸ� �л����� ü������ ������ �� �ֽ��ϴ�."																					<< std::endl
		<< "���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�. "																							<< std::endl
		<< "�̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, ���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�."								<< std::endl
		<< std::endl;

	/// �Է� �� ����
	// �׽�Ʈ���̽� 1
	int n1 = 5;
	std::vector<int> lost1;
	std::vector<int> reserve1;
	
	lost1.push_back(2);
	lost1.push_back(4);
	reserve1.push_back(1);
	reserve1.push_back(3);
	reserve1.push_back(5);

	///////////////////////////////////////////////
	
	// �׽�Ʈ���̽� 2
	int n2 = 5;
	std::vector<int> lost2;
	std::vector<int> reserve2;

	lost2.push_back(2);
	lost2.push_back(4);
	reserve2.push_back(3);

	///////////////////////////////////////////////

	// �׽�Ʈ���̽� 3
	int n3 = 3;
	std::vector<int> lost3;
	std::vector<int> reserve3;

	lost3.push_back(3);
	reserve3.push_back(1);

	std::cout << solution(n3, lost3, reserve3) << std::endl;

}

WorkoutClothes::~WorkoutClothes()
{
}

int WorkoutClothes::solution(int n, std::vector<int> lost, std::vector<int> reserve)
{
	int answer = 0;						// ü�� ������ ���� �� �ִ� �л� ��

	std::vector<int> clothesCountVec;	// ü���� ���� ����
	clothesCountVec.resize(n + 2, 1);	// ��� �л��� ü���� ���� 1�� �ʱ�ȭ
										// vector�� iter ������ �߸��� ��Ҹ� ����Ű�� ���� �����ϱ� ���� �յڷ� ���� ������ 1���� ����
	
	// -1�� �����ѹ��� ���
	// �л��� ���� ����, ���α׷� ������ ���ϱ� ����
	clothesCountVec.at(0) = -1;
	clothesCountVec.at(clothesCountVec.size() - 1) = -1;

	/// ���� ���� �л��� ����
	for (auto lostStudent : lost)
	{
		// ���ϸ��� �л��� ü���� ���� ����;
		clothesCountVec.at(lostStudent)--; 
	}

	/// ���� ü������ ������ �л��� ����
	for (auto reserveStudent : reserve)
	{
		// ���� ü������ ������ �л����� ü���� ���� 1 ����
		clothesCountVec.at(reserveStudent)++;	
	}

	// ü���� ���� ���� ��

	/// ü���� �����ֱ�
	for (std::vector<int>::iterator iter = clothesCountVec.begin() + 1;
		iter != clothesCountVec.end() - 1;
		iter++)
	{
		// ü������ ���ϸ¾Ҵٸ�
		if (*iter == 0)
		{
			/// �� ������ ���� �л��� ü���� ������ �ľ� �� ������ ������ ����
			// �� ���� ��ȣ �л��� ü���� ������ 1���� ũ��
			if (*(iter - 1) > 1)
			{
				( *(iter - 1) )--;	// ü���� ���� 1 ����(������)
				(*iter)++;			// �� ü���� ���� 1 ����

				answer++;			// ü������ �������� ������ ���� �� �ִ� �л����� ī��Ʈ ��

				continue;
			}

			// �� ���� ��ȣ �л��� ü���� ������ 1���� ũ��
			if (*(iter + 1) > 1)
			{
				( *(iter + 1) )--;	// ü���� ���� 1 ����(������)
				(*iter)++;			// �� ü���� ���� 1 ����

				answer++;			// ü������ �������� ������ ���� �� �ִ� �л����� ī��Ʈ ��

				continue;
			}
		}

		/// ü������ ���ϸ��� �ʾ����� ī��Ʈ ��
		else
		{
			answer++;
		}
	}

	return answer;
}
