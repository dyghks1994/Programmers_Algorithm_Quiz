#include "stdafx.h"
#include "GCDandLCM.h"

GCDandLCM::GCDandLCM()
{
	int n = 3;
	int m = 12;
	std::vector<int> gcd_lcm = solution(n, m);

	std::cout << n << "�� " << m << "�� �ִ�����(GCD) = " << gcd_lcm[0] << std::endl;
	std::cout << n << "�� " << m << "�� �ּҰ����(LCM) = " << gcd_lcm[1] << std::endl;
}

GCDandLCM::~GCDandLCM()
{
}

std::vector<int> GCDandLCM::solution(int n, int m)
{
	std::vector<int> answer;

	for (int i = n; i > 0; i--)
	{
		if ((n % i == 0) && (m % i == 0))	// �ݺ��� ���� i�� n���� �ʱ�ȭ �ϰ� 1���� ���̳ʽ� �ذ��鼭 �� ���� i�� ���� ��, ���ÿ� 0�� �Ǹ� �ִ�����!
		{
			answer.emplace_back(i);			// ���Ϳ� �ִ����� �߰�
			answer.emplace_back(n * m / i);	// �ּҰ����(LCM) �߰�. LCM -> n * m / LCM(n,m)
		}
	}


	/*	��Ŭ���� ȣ�������� Ǫ�� ��� by �ݺ���
	int big;        // ū ��
    int small;      // ���� ��
    int r;          // ������ ������ ����

    big   = (n > m) ? n : m;    // n�� m�� �� ū ���� big�� ����
    small = (n < m) ? n : m;    // n�� m�� �� ���� ���� small�� ����
    int gcd = small;            // �ִ����� �ʱ�ȭ    

    while (small != 0)  // small�� 0�� �ƴϸ� �ݺ�, small�� big / small == 0�̸� �ִ�����!
    {
        r = big % small;    // r�� big�� small�� �������� ����
        big = small;        // big�� small�� ����
        small = r;          // small�� r�� ����
                            // ���� small�� 0�� �� ������ ��� �ݺ�
    }
    gcd = big;              // �ִ����� ����

    int lcm = n * m / gcd;

    answer.emplace_back(gcd);   // ���Ϳ� �ִ����� �߰�
    answer.emplace_back(lcm);   // ���Ϳ� �ּҰ���� �߰�
	*/
	return answer;
}
