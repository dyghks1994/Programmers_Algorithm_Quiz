#include "stdafx.h"
#include "CreateALargeNumber.h"

CreateALargeNumber::CreateALargeNumber()
{
	/// <summary>
	///  문제 출력
	/// </summary>
	std::cout
		<< "[문제설명]  "																												<< std::endl
		<< "어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.   "												<< std::endl
		<< "예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. "									<< std::endl
		<< "이 중 가장 큰 숫자는 94 입니다."																								<< std::endl 
		<< "문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. "										<< std::endl 
		<< "number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요."	<< std::endl << std::endl
		
		<< "[제한사항]" << std::endl
		<< "number는 1자리 이상, 1,000,000자리 이하인 숫자입니다." << std::endl
		<< "k는 1 이상 number의 자릿수 미만인 자연수입니다." << std::endl
		<< std::endl;

	/// 문제에 필요한 입력 준비
	// 테스트 케이스 1
	std::string number = "1924";
	int k = 2;

	// 테스트 케이스 2
	std::string number2 = "1231234";
	int k2 = 3;

	// 테스트 케이스 3
	std::string number3 = "4177252841";
	int k3 = 4;

	// 커스텀 테스트 케이스 
	std::string number4 = "1000";
	int k4 = 1;

	/// 결과 보기
	std::cout << "원본 = " << number3					  << std::endl;
	std::cout << "k    = " << k3						  << std::endl;
	std::cout << "결과 = " << solution2(number3.c_str(), k3) << std::endl;
}

CreateALargeNumber::~CreateALargeNumber()
{
}

/// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
std::string CreateALargeNumber::solution(std::string number, int k)
{
	std::string answer = number;

	// k번 만큼 반복
	for (int i = 0; i < k; i++)
	{
		// 가장 앞의 숫자의 인덱스로 초기화
		int minIndex = 0;

		while (true)
		{
			// 인덱스가 맨 마지막 숫자의 위치까지 왔다면
			if (minIndex == answer.size() - 1)
			{
				// 마지막 숫자 제거
				answer.erase(answer.size() - 1, 1);

				break;
			}

			// 현재 숫자와 다음 숫자를 비교해서 현재 숫자가 더 작으면
			if (answer[minIndex] < answer[minIndex + 1])
			{
				// 그 숫자 제거 후 다시 처음 숫자부터 반복
				answer.erase(minIndex, 1);

				break;
			}

			// 현재 숫자가 다음 숫자보다 작지 않으면 
			// 인덱스를 증가시키고 다음 숫자와 다다음 숫자 비교
			minIndex++;
		}

	}

	return answer;
}

std::string CreateALargeNumber::solution2(std::string number, int k)
{
	std::string answer = "";
	answer = number.substr(k);
	
	for (int i = k - 1; i >= 0; i--) {
		int j = 0;
		
		do {
			if (number[i] >= answer[j]) {
				char temp = answer[j];
				answer[j] = number[i];
				number[i] = temp;
				j++;
			}

			else 
			{
				break;
			}

		} while (1);
	}



	return answer;
}

