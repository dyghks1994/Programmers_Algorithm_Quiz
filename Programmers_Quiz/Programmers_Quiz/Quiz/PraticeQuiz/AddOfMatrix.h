#pragma once

/*	[����� ����]
����� ������ ��� ���� ũ�Ⱑ ���� �� ����� ���� ��, 
���� ���� ���� ���� ���� ����� �˴ϴ�.
2���� ��� arr1�� arr2�� �Է¹޾�, 
��� ������ ����� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.

���� ����
��� arr1, arr2�� ��� ���� ���̴� 500�� ���� �ʽ��ϴ�.

����� ��
arr1	arr2	return

[[1,2],[2,3]]	[[3,4],[5,6]]	[[4,6],[7,9]]
[[1],[2]]	[[3],[4]]	[[4],[6]]
*/
class AddOfMatrix
{
public:
	AddOfMatrix();
	~AddOfMatrix();

	std::vector<std::vector<int>> solution(std::vector<std::vector<int>> arr1, std::vector<std::vector<int>> arr2);
};