#include "stdafx.h"
#include "ConvertStringToInt.h"


/*
아스키코드표
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
	std::string s = "+5774";	// s의 길이는 1 이상 5이하로,	 s의 맨 앞에는 부호(+, -)가 올 수 있음, "0"으로는 시작하지 않음

	std::cout << "문자열 S를 정수로 변환시키는 문제" << std::endl;
	std::cout << "s = " << s << std::endl;
	std::cout << "변환 = " << solution(s) << std::endl;
}

ConvertStringToInt::~ConvertStringToInt()
{
}

int ConvertStringToInt::solution(std::string s)
{
	int answer = 0;

	for (int i = s.size() -1; i >= 0; i--)	// 마지막(오른쪽) 부터 처음(왼쪽)으로 변환한다
	{
		if (s[i] == '-' || s[i] == '+')		// 검사하는 문자가 '-' 이거나 '+'이면 리턴
		{
			answer = s[i] == '-' ? answer * (-1) : answer;  // 부호가 '-'일 경우 -1을 곱해서 음수로 변환, '+'이면 그냥 리턴
			break;
		}
		
		// n의자리 인지 자리를 구해서 (1, 10, 100 ...) 해당하는 위치의 숫자를 곱해줌
		answer += pow(10, s.size() - i - 1) * (s[i] - '0');	// '0' = 아스키코드 48번
	}
	return answer;
}

/*
	return atoi(s); 도 가능
*/