#pragma once

/* 
[���� ����]
������ ������ �������� �����濡 �����Ͽ����ϴ�. 
�� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.

�����濡 ������ �������� �̸��� ��� �迭 participant�� 
������ �������� �̸��� ��� �迭 completion�� �־��� ��, 
�������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

[���ѻ���]
������ ��⿡ ������ ������ ���� 1�� �̻� 100,000�� �����Դϴ�.
completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
������ �߿��� ���������� ���� �� �ֽ��ϴ�.

[����� ��]
participant											completion									return
["leo", "kiki", "eden"]								["eden", "kiki"]							"leo"
["marina", "josipa", "nikola", "vinko", "filipa"]	["josipa", "filipa", "marina", "nikola"]	"vinko"
["mislav", "stanko", "mislav", "ana"]				["stanko", "ana", "mislav"]					"mislav"
*/

using namespace std;

class UnfinishedAthlete
{
public:
	UnfinishedAthlete();
	~UnfinishedAthlete();

	string solution(vector<string> participant, vector<string> completion);

private:

};