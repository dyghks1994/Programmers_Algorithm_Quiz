#include "stdafx.h"
#include "WorkoutClothes.h"

WorkoutClothes::WorkoutClothes()
{
	std::cout
		<< "[문제설명]  "																																		<< std::endl
		<< "점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다.  "																						<< std::endl
		<< "다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다. "																					<< std::endl
		<< "학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다.  "									<< std::endl
		<< "예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다. "																		<< std::endl
		<< "체육복이 없으면 수업을 들을 수 없기 때문에 체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다. "											<< std::endl
		<< "전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, "	<< std::endl
		<< "체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요."																	<< std::endl << std::endl

		<< "[제한사항]"																																			<< std::endl
		<< "전체 학생의 수는 2명 이상 30명 이하입니다."																											<< std::endl
		<< "체육복을 도난당한 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다."																			<< std::endl
		<< "여벌의 체육복을 가져온 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다."																		<< std::endl
		<< "여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있습니다."																					<< std::endl
		<< "여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. "																							<< std::endl
		<< "이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다."								<< std::endl
		<< std::endl;

	/// 입력 값 세팅
	// 테스트케이스 1
	int n1 = 5;
	std::vector<int> lost1;
	std::vector<int> reserve1;
	
	lost1.push_back(2);
	lost1.push_back(4);
	reserve1.push_back(1);
	reserve1.push_back(3);
	reserve1.push_back(5);

	///////////////////////////////////////////////
	
	// 테스트케이스 2
	int n2 = 5;
	std::vector<int> lost2;
	std::vector<int> reserve2;

	lost2.push_back(2);
	lost2.push_back(4);
	reserve2.push_back(3);

	///////////////////////////////////////////////

	// 테스트케이스 3
	int n3 = 3;
	std::vector<int> lost3;
	std::vector<int> reserve3;

	lost3.push_back(3);
	reserve3.push_back(1);

	std::cout << solution(n3, lost3, reserve3) << std::endl;

}

WorkoutClothes::~WorkoutClothes()
{
}

int WorkoutClothes::solution(int n, std::vector<int> lost, std::vector<int> reserve)
{
	int answer = 0;						// 체육 수업을 들을 수 있는 학생 수

	std::vector<int> clothesCountVec;	// 체육복 개수 벡터
	clothesCountVec.resize(n + 2, 1);	// 모든 학생의 체육복 개수 1로 초기화
										// vector의 iter 참조시 잘못된 요소를 가리키는 것을 방지하기 위해 앞뒤로 여분 공간을 1나씩 만듬
	
	// -1을 매직넘버로 사용
	// 학생과 관련 없음, 프로그램 에러를 피하기 위함
	clothesCountVec.at(0) = -1;
	clothesCountVec.at(clothesCountVec.size() - 1) = -1;

	/// 도둑 맞은 학생들 적용
	for (auto lostStudent : lost)
	{
		// 도둑맞은 학생의 체육복 개수 감소;
		clothesCountVec.at(lostStudent)--; 
	}

	/// 여분 체육복을 가져온 학생들 적용
	for (auto reserveStudent : reserve)
	{
		// 여분 체육복을 가져온 학생들의 체육복 갯수 1 증가
		clothesCountVec.at(reserveStudent)++;	
	}

	// 체육복 개수 세팅 끝

	/// 체육복 빌려주기
	for (std::vector<int>::iterator iter = clothesCountVec.begin() + 1;
		iter != clothesCountVec.end() - 1;
		iter++)
	{
		// 체육복을 도둑맞았다면
		if (*iter == 0)
		{
			/// 내 이전과 다음 학생의 체육복 개수를 파악 후 여분이 있으면 빌림
			// 내 이전 번호 학생의 체육복 개수가 1보다 크면
			if (*(iter - 1) > 1)
			{
				( *(iter - 1) )--;	// 체육복 개수 1 감소(빌려옴)
				(*iter)++;			// 내 체육복 개수 1 증가

				answer++;			// 체육복을 빌렸으니 수업을 들을 수 있는 학생수에 카운트 함

				continue;
			}

			// 내 다음 번호 학생의 체육복 개수가 1보다 크면
			if (*(iter + 1) > 1)
			{
				( *(iter + 1) )--;	// 체육복 개수 1 감소(빌려옴)
				(*iter)++;			// 내 체육복 개수 1 증가

				answer++;			// 체육복을 빌렸으니 수업을 들을 수 있는 학생수에 카운트 함

				continue;
			}
		}

		/// 체육복을 도둑맞지 않았으면 카운트 함
		else
		{
			answer++;
		}
	}

	return answer;
}
