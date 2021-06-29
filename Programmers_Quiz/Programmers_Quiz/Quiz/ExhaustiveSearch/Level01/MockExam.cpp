#include "stdafx.h"
#include "MockExam.h"

MockExam::MockExam()
{
	std::cout
		<< "[��������]  " << std::endl
		<< "�����ڴ� ������ ������ ����� �ظ��Դϴ�. " << std::endl
		<< "������ ���ι��� ���ǰ�翡 ���� ������ ���� ������ �մϴ�.  " << std::endl
		<< "�����ڴ� 1�� �������� ������ �������� ������ ���� ����ϴ�." << std::endl << std::endl
		<< "1�� �����ڰ� ��� ���: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ..." << std::endl
		<< "2�� �����ڰ� ��� ���: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ..." << std::endl
		<< "3�� �����ڰ� ��� ���: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ..." << std::endl << std::endl
		<< "1�� �������� ������ ���������� ������ ������� ���� �迭 answers�� �־����� ��, " << std::endl
		<< "���� ���� ������ ���� ����� �������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���." << std::endl << std::endl

		<< "[���ѻ���]" << std::endl
		<< "������ �ִ� 10,000 ������ �����Ǿ��ֽ��ϴ�." << std::endl
		<< "������ ������ 1, 2, 3, 4, 5�� �ϳ��Դϴ�." << std::endl
		<< "���� ���� ������ ���� ����� ������ ���, return�ϴ� ���� �������� �������ּ���." << std::endl
		
		<< std::endl;


	/// �Է� �� ����
	// �׽�Ʈ���̽� 1
	std::vector<int> answers;
	answers.push_back(1);
	answers.push_back(2);
	answers.push_back(3);
	answers.push_back(4);
	answers.push_back(5);

	/////////////////////////////////////
	
	// �׽�Ʈ���̽� 2
	std::vector<int> answers2;
	answers2.push_back(1);
	answers2.push_back(3);
	answers2.push_back(2);
	answers2.push_back(4);
	answers2.push_back(2);

	/// solution
	std::vector<int> returnVec = solution(answers);
	std::cout << "return = ";
	for (auto num : returnVec)
	{
		std::cout << num << ", ";
	}
	std::cout << std::endl;
}

MockExam::~MockExam()
{
}

/// <summary>
/// ����ü�� �̿��� Ǯ��
/// ��Ȯ�� �׽�Ʈ : ����
/// ȿ���� �׽�Ʈ : ����
/// </summary>
struct SSupojas
{
	static const int count = 3;	// ������ ��

	int score;					// ����
	std::vector<int> answer;	// ����(���)�ϴ� ���
};

std::vector<int> MockExam::solution(std::vector<int> answers)
{
	std::vector<int> answer;	// ���� ������ ������(��)

	/// �����ڵ� �迭
	SSupojas supojas[3];			

	// ������ 1�� �ʱ�ȭ
	supojas[0].score = 0;
	supojas[0].answer = {1, 2, 3, 4, 5};

	// ������ 2�� �ʱ�ȭ
	supojas[1].score = 0;
	supojas[1].answer = { 2, 1, 2, 3, 2, 4, 2, 5 };

	// ������ 3�� �ʱ�ȭ
	supojas[2].score = 0;
	supojas[2].answer = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	

	/// �� �����ڵ��� ������ ���
	// ������ ����ŭ ��ȸ(�ݺ�)
	for (auto& supoja : supojas)
	{
		// �������� ���� ��ȸ�� iter ����
		std::vector<int>::iterator iter = supoja.answer.begin();

		// �־��� �����(answers) ��ŭ �ݺ�
		for (auto answer : answers)
		{
			// ���� ���� ��� ������ �������� ���� �ߴٸ� 
			if (iter == supoja.answer.end())
			{
				iter = supoja.answer.begin(); // iter�� �ٽ� ó������
			}

			// ���� ������ ��� �������� ���� ��ġ �Ѵٸ�
			if (answer == *iter)
			{
				supoja.score++;	// ���� 1 ����
			}

			// �������� ���� ��� ��ȣ�� iterator �ű�
			iter++;
		}
	}

	/// ���� ����� �ְ����� ����
	int highScore = 0; // �ְ���

	for (int i = 0; i < SSupojas::count; i++)
	{
		// ���� �������� ������ �ְ��� ���� ũ��
		if (supojas[i].score > highScore)
		{
			// �ְ��� ����
			highScore = supojas[i].score;
		}
	}

	/// �ְ����� �ش��ϴ� �����ڵ�(1��)�� answer�� �߰�
	for (int i = 0; i < SSupojas::count; i++)
	{
		// ���� �������� ������ �ְ����� ������
		if (supojas[i].score == highScore)
		{
			answer.push_back(i + 1);	// �ְ��� ����(answer)�� �߰�
		}
	}

	return answer;
}

/////////////////////////////////////////////////////////////////////////////////

/// ���α׷��ӽ� �ٸ� ����� Ǯ��
std::vector<int> MockExam::solution2(std::vector<int> answers)
{
	std::vector<int> one = { 1,2,3,4,5 };
	std::vector<int> two = { 2,1,2,3,2,4,2,5 };
	std::vector<int> thr = { 3,3,1,1,2,2,4,4,5,5 };

	std::vector<int> answer;
	std::vector<int> they(3);
	
	for (int i = 0; i < answers.size(); i++) 
	{
		if (answers[i] == one[i % one.size()]) they[0]++;	/// % ������ Ű����Ʈ 
		if (answers[i] == two[i % two.size()]) they[1]++;
		if (answers[i] == thr[i % thr.size()]) they[2]++;
	}
	
	int they_max = *max_element(they.begin(), they.end());	/// std::max_element Ű����Ʈ
	
	for (int i = 0; i < 3; i++) 
	{
		if (they[i] == they_max) answer.push_back(i + 1);
	}
	
	return answer;
}
