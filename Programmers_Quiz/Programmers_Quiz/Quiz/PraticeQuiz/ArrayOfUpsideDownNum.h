#pragma once

/*
�ڿ��� n�� ������ �� �ڸ� ���ڸ� ���ҷ� ������ �迭 ���·� �������ּ���. 
������� n�� 12345�̸� [5,4,3,2,1]�� �����մϴ�.

���� ����
n�� 10,000,000,000������ �ڿ����Դϴ�.

����� ��
n	return
12345	[5,4,3,2,1]
*/
class ArrayOfUpsideDownNum
{
public:
	ArrayOfUpsideDownNum();
	~ArrayOfUpsideDownNum();

	std::vector<int> solution(long long n);
};