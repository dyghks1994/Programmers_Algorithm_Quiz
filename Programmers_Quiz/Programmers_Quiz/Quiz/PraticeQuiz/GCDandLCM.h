#pragma once

/* �� ���� �ִ������� �ּҰ���� ���ϱ�
�� ���� �Է¹޾� �� ���� �ִ������� �ּҰ������ ��ȯ�ϴ� �Լ�, 
solution�� �ϼ��� ������. 
�迭�� �� �տ� �ִ�����, �״��� �ּҰ������ �־� ��ȯ�ϸ� �˴ϴ�.

���� ��� �� �� 3, 12�� 
�ִ������� 3, 
�ּҰ������ 12�̹Ƿ� 
solution(3, 12)�� [3, 12]�� ��ȯ�ؾ� �մϴ�.

���� ����
�� ���� 1�̻� 1000000������ �ڿ����Դϴ�.
����� ��
n	m	return
3	12	[3, 12]
2	5	[1, 10]
*/
class GCDandLCM
{
public:
	GCDandLCM();
	~GCDandLCM();

	std::vector<int> solution(int n, int m);
};