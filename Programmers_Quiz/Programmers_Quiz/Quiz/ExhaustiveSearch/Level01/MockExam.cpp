#include "stdafx.h"
#include "MockExam.h"

MockExam::MockExam()
{
	std::cout
		<< "[문제설명]  " << std::endl
		<< "수포자는 수학을 포기한 사람의 준말입니다. " << std::endl
		<< "수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다.  " << std::endl
		<< "수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다." << std::endl << std::endl
		<< "1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ..." << std::endl
		<< "2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ..." << std::endl
		<< "3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ..." << std::endl << std::endl
		<< "1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, " << std::endl
		<< "가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요." << std::endl << std::endl

		<< "[제한사항]" << std::endl
		<< "시험은 최대 10,000 문제로 구성되어있습니다." << std::endl
		<< "문제의 정답은 1, 2, 3, 4, 5중 하나입니다." << std::endl
		<< "가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요." << std::endl
		
		<< std::endl;


	/// 입력 값 세팅
	// 테스트케이스 1
	std::vector<int> answers;
	answers.push_back(1);
	answers.push_back(2);
	answers.push_back(3);
	answers.push_back(4);
	answers.push_back(5);

	/////////////////////////////////////
	
	// 테스트케이스 2
	std::vector<int> answers2;
	answers2.push_back(1);
	answers2.push_back(3);
	answers2.push_back(2);
	answers2.push_back(4);
	answers2.push_back(2);

	/// solution
	std::vector<int> returnVec = solution(answers);
	std::cout << "return = ";
	for (auto num : returnVec)
	{
		std::cout << num << ", ";
	}
	std::cout << std::endl;
}

MockExam::~MockExam()
{
}

/// <summary>
/// 구조체를 이용한 풀이
/// 정확성 테스트 : 성공
/// 효율성 테스트 : 성공
/// </summary>
struct SSupojas
{
	static const int count = 3;	// 수포자 수

	int score;					// 점수
	std::vector<int> answer;	// 제출(찍는)하는 답안
};

std::vector<int> MockExam::solution(std::vector<int> answers)
{
	std::vector<int> answer;	// 가장 잘찍은 수포자(들)

	/// 수포자들 배열
	SSupojas supojas[3];			

	// 수포자 1번 초기화
	supojas[0].score = 0;
	supojas[0].answer = {1, 2, 3, 4, 5};

	// 수포자 2번 초기화
	supojas[1].score = 0;
	supojas[1].answer = { 2, 1, 2, 3, 2, 4, 2, 5 };

	// 수포자 3번 초기화
	supojas[2].score = 0;
	supojas[2].answer = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	

	/// 각 수포자들의 점수를 계산
	// 수포자 수만큼 순회(반복)
	for (auto& supoja : supojas)
	{
		// 수포자의 답을 순회할 iter 생성
		std::vector<int>::iterator iter = supoja.answer.begin();

		// 주어진 답안지(answers) 만큼 반복
		for (auto answer : answers)
		{
			// 만약 답을 찍는 패턴의 마지막에 도달 했다면 
			if (iter == supoja.answer.end())
			{
				iter = supoja.answer.begin(); // iter를 다시 처음으로
			}

			// 현재 문재의 답과 수포자의 답이 일치 한다면
			if (answer == *iter)
			{
				supoja.score++;	// 점수 1 증가
			}

			// 수포자의 다음 찍기 번호로 iterator 옮김
			iter++;
		}
	}

	/// 점수 계산후 최고점을 구함
	int highScore = 0; // 최고점

	for (int i = 0; i < SSupojas::count; i++)
	{
		// 현재 수포자의 점수가 최고점 보다 크면
		if (supojas[i].score > highScore)
		{
			// 최고점 갱신
			highScore = supojas[i].score;
		}
	}

	/// 최고점에 해당하는 수포자들(1등)을 answer에 추가
	for (int i = 0; i < SSupojas::count; i++)
	{
		// 현재 수포자의 점수가 최고점과 같으면
		if (supojas[i].score == highScore)
		{
			answer.push_back(i + 1);	// 최고점 벡터(answer)에 추가
		}
	}

	return answer;
}

/////////////////////////////////////////////////////////////////////////////////

/// 프로그래머스 다른 사람의 풀이
std::vector<int> MockExam::solution2(std::vector<int> answers)
{
	std::vector<int> one = { 1,2,3,4,5 };
	std::vector<int> two = { 2,1,2,3,2,4,2,5 };
	std::vector<int> thr = { 3,3,1,1,2,2,4,4,5,5 };

	std::vector<int> answer;
	std::vector<int> they(3);
	
	for (int i = 0; i < answers.size(); i++) 
	{
		if (answers[i] == one[i % one.size()]) they[0]++;	/// % 연산자 키포인트 
		if (answers[i] == two[i % two.size()]) they[1]++;
		if (answers[i] == thr[i % thr.size()]) they[2]++;
	}
	
	int they_max = *max_element(they.begin(), they.end());	/// std::max_element 키포인트
	
	for (int i = 0; i < 3; i++) 
	{
		if (they[i] == they_max) answer.push_back(i + 1);
	}
	
	return answer;
}
