#include "stdafx.h"
#include "Find_Kth_Number.h"


Find_Kth_Number::Find_Kth_Number()
{
	Initialize();					// 풀이에 필요한 자료들 초기화
	PrintQuiz();					// 문제 설명
	solution(array, commands);		// 문제풀이 알고리즘 실행
	PrintAnswer();					// 리턴값 출력

}

Find_Kth_Number::~Find_Kth_Number()
{
}

void Find_Kth_Number::PrintQuiz()
{
	std::cout << "[K번째 수 구하기 문제]" << std::endl;
	std::cout << "배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다." << std::endl;
	std::cout << "예를 들어 array가[1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면" << std::endl;
	std::cout << "array의 2번째부터 5번째까지 자르면[5, 2, 6, 3]입니다." << std::endl;
	std::cout << "1에서 나온 배열을 정렬하면[2, 3, 5, 6]입니다." << std::endl;
	std::cout << "2에서 나온 배열의 3번째 숫자는 5입니다." << std::endl;
	std::cout << "배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요." << std::endl << std::endl;
	
	std::cout << "제한사항" << std::endl;
	std::cout << "array의 길이는 1 이상 100 이하입니다." << std::endl;
	std::cout << "array의 각 원소는 1 이상 100 이하입니다." << std::endl;
	std::cout << "commands의 길이는 1 이상 50 이하입니다." << std::endl;
	std::cout << "commands의 각 원소는 길이가 3입니다." << std::endl << std::endl;
	
	std::cout << "입출력 예" << std::endl;
	std::cout << setw(0) << "array" << setw(27) << "commands" << setw(35) << "return" << std::endl;
	std::cout << "[1, 5, 2, 6, 3, 7, 4] | [[2, 5, 3], [4, 4, 1], [1, 7, 3]] | [5, 6, 3]" << std::endl << std::endl;
	
	std::cout << "입출력 예 설명" << std::endl;
	std::cout << "[1, 5, 2, 6, 3, 7, 4]를 2번째부터 5번째까지 자른 후 정렬합니다.[2, 3, 5, 6]의 세 번째 숫자는 5입니다." << std::endl;
	std::cout << "[1, 5, 2, 6, 3, 7, 4]를 4번째부터 4번째까지 자른 후 정렬합니다.[6]의 첫 번째 숫자는 6입니다." << std::endl;
	std::cout << "[1, 5, 2, 6, 3, 7, 4]를 1번째부터 7번째까지 자릅니다.[1, 2, 3, 4, 5, 6, 7]의 세 번째 숫자는 3입니다. " << std::endl << std::endl;
}

void Find_Kth_Number::Initialize()
{
	// 문제 배열 초기화
	array.emplace_back(1);
	array.emplace_back(5);
	array.emplace_back(2);
	array.emplace_back(6);
	array.emplace_back(3);
	array.emplace_back(7);
	array.emplace_back(4);

	//조건 배열
	std::vector<int> condition1;
	condition1.emplace_back(2);
	condition1.emplace_back(5);
	condition1.emplace_back(3);

	std::vector<int> condition2;
	condition2.emplace_back(4);
	condition2.emplace_back(4);
	condition2.emplace_back(1);
	
	std::vector<int> condition3;
	condition3.emplace_back(1);
	condition3.emplace_back(7);
	condition3.emplace_back(3);

	commands.emplace_back(condition1);
	commands.emplace_back(condition2);
	commands.emplace_back(condition3);
}

void Find_Kth_Number::PrintAnswer()
{
	std::cout << "<return>" << std::endl;
	std::cout << "[";
	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer.at(i) << ",  ";
	}
	std::cout << "]" << std::endl;
		
	std::cout << answer.size();
}

vector<int> Find_Kth_Number::solution(vector<int> array, vector<vector<int>> commands)
{
	for (int i = 0; i < commands.size(); i++)	// 반복해야하는 조건의 수 만큼 반복해서 답을 구함
	{
		std::vector<int> temp_array;    // 잘라서 정렬할 임시 배열 생성

		// condition [x, y, z] 에서 x ~ y까지
		// 0부터 시작하는 배열 인덱스와 매칭하기 위해 -1을 해줌
		for (int j = (commands.at(i).at(0)) - 1; j <= (commands.at(i).at(1)) - 1; j++)
		{
			temp_array.emplace_back(array.at(j));	//임시배열에 원소 추가
		}

		// 정렬 시작
		for (int j = 0; j < temp_array.size() - 1; j++)	// temp_array 오름차순으로 정렬
		{
			int min = temp_array.at(j);	// 남은 수 중에서 첫번째를 가장 작은 수로 설정
			int min_index = j;          // 인덱스 설정

			for (int k = j + 1; k < temp_array.size(); k++)
			{
				// 현재 가장 작은 수가 비교한 수보다 크면?
				if (temp_array.at(min_index) > temp_array.at(k))
				{
					min = temp_array.at(k);		// 비교한 수를 가장 작은 수로 설정
					min_index = k;				// 가장 작은 수가 있는 인덱스 변경
				}
			}

			// swap
			int temp;
			temp = temp_array.at(j);
			temp_array.at(j) = temp_array.at(min_index);
			temp_array.at(min_index) = temp;

			// 주어진 조건 [x, y, z]에서 x ~ y번째 까지 자르고 정렬 완료
			//===========================================================
		}
		answer.emplace_back(temp_array.at(commands.at(i).at(2) - 1));	// answer에 답 추가
	}
	return answer;
}
