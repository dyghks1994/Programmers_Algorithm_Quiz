#include "stdafx.h"
#include "UnfinishedAthlete.h"

UnfinishedAthlete::UnfinishedAthlete()
{
	std::cout 
		<< "[���� ����]\n"
		<< "������ ������ �������� �����濡 �����Ͽ����ϴ�.\n"
		<< "�� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.\n"
		<< "�����濡 ������ �������� �̸��� ��� �迭 participant��\n"
		<< "������ �������� �̸��� ��� �迭 completion�� �־��� ��,\n"
		<< "�������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.\n\n"

		<< "[���ѻ���]\n"
		<< "������ ��⿡ ������ ������ ���� 1�� �̻� 100, 000�� �����Դϴ�.\n"
		<< "completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.\n"
		<< "�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.\n"
		<< "������ �߿��� ���������� ���� �� �ֽ��ϴ�.\n"
		<< std::endl;

	/// ������ �ʿ��� �غ� ����
	// ������ ���
	std::vector<std::string> participant;
	participant.emplace_back("mislav");
	participant.emplace_back("stanko");
	participant.emplace_back("mislav");
	participant.emplace_back("ana");

	// ������ ���
	std::vector<std::string> completion;
	completion.emplace_back("stanko");
	completion.emplace_back("ana");
	completion.emplace_back("mislav");

	/// ���� ��
	std::cout << "�̿����� �� -> " << solution(participant, completion) << std::endl;
}

UnfinishedAthlete::~UnfinishedAthlete()
{
}


string UnfinishedAthlete::solution(vector<string> participant, vector<string> completion)
{
	std::string answer = "";

	/// �̸��� ���� ���¸� �����ϴ� �ӽ� ���̺��� �����.
	// ����
	// 0 -> �� �̸��� �޸��� �ʴ� ���̶� ����(�������� ���� ��� ����) 
	// 1 �̻� ->�� �̸��� ����� ��� �޸��� �ִ��� ī��Ʈ
	std::unordered_map<std::string, int> temp;
	
	// �����ڵ��� ��� �˻��ϸ鼭 �� �̸����� temp�� Ű������ �ָ鼭 ���� 1 ����
	// �� �̸��� ���� ����� 1�� �߰���(������ ����)
	for (auto name : participant)
	{
		temp[name]++;
	}

	// ������ ����� �˻��ϸ鼭 �ش��ϴ� �̸�(���)�� temp ���� ã�� ����
	for (auto name : completion)
	{
		temp[name]--;
	}

	/// ������ ó���� ��� ���� �������� 0�� �ƴ� �ϳ��� �̸��� ����, �� ����� �̿�����!
	for (auto pair : temp)
	{
		// ���̺��� second�� 0 ���� ũ�ٸ�? �̿�����
		if (pair.second > 0)
		{
			// answer �� �̿������� �̸�(key ��)�� ����
			answer = pair.first;
			break;
		}
	}

	return answer;
}
