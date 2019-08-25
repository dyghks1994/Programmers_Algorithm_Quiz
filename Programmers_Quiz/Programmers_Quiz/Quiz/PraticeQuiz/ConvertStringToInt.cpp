#include "stdafx.h"
#include "ConvertStringToInt.h"


/*
�ƽ�Ű�ڵ�ǥ
+	43
-	45
0	48
1	49
2	50
3	51
4	52
5	53
6	54
7	55
8	56
9	57
*/

ConvertStringToInt::ConvertStringToInt()
{
	std::string s = "+5774";	// s�� ���̴� 1 �̻� 5���Ϸ�,	 s�� �� �տ��� ��ȣ(+, -)�� �� �� ����, "0"���δ� �������� ����

	std::cout << "���ڿ� S�� ������ ��ȯ��Ű�� ����" << std::endl;
	std::cout << "s = " << s << std::endl;
	std::cout << "��ȯ = " << solution(s) << std::endl;
}

ConvertStringToInt::~ConvertStringToInt()
{
}

int ConvertStringToInt::solution(std::string s)
{
	int answer = 0;

	for (int i = s.size() -1; i >= 0; i--)	// ������(������) ���� ó��(����)���� ��ȯ�Ѵ�
	{
		if (s[i] == '-' || s[i] == '+')		// �˻��ϴ� ���ڰ� '-' �̰ų� '+'�̸� ����
		{
			answer = s[i] == '-' ? answer * (-1) : answer;  // ��ȣ�� '-'�� ��� -1�� ���ؼ� ������ ��ȯ, '+'�̸� �׳� ����
			break;
		}
		
		// n���ڸ� ���� �ڸ��� ���ؼ� (1, 10, 100 ...) �ش��ϴ� ��ġ�� ���ڸ� ������
		answer += pow(10, s.size() - i - 1) * (s[i] - '0');	// '0' = �ƽ�Ű�ڵ� 48��
	}
	return answer;
}

/*
	return atoi(s); �� ����
*/