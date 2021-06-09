#include "stdafx.h"
#include "UnfinishedAthlete.h"

UnfinishedAthlete::UnfinishedAthlete()
{
	std::cout 
		<< "[문제 설명]\n"
		<< "수많은 마라톤 선수들이 마라톤에 참여하였습니다.\n"
		<< "단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.\n"
		<< "마라톤에 참여한 선수들의 이름이 담긴 배열 participant와\n"
		<< "완주한 선수들의 이름이 담긴 배열 completion이 주어질 때,\n"
		<< "완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.\n\n"

		<< "[제한사항]\n"
		<< "마라톤 경기에 참여한 선수의 수는 1명 이상 100, 000명 이하입니다.\n"
		<< "completion의 길이는 participant의 길이보다 1 작습니다.\n"
		<< "참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.\n"
		<< "참가자 중에는 동명이인이 있을 수 있습니다.\n"
		<< std::endl;

	/// 문제에 필요한 준비 세팅
	// 참가자 명단
	std::vector<std::string> participant;
	participant.emplace_back("mislav");
	participant.emplace_back("stanko");
	participant.emplace_back("mislav");
	participant.emplace_back("ana");

	// 완주자 명단
	std::vector<std::string> completion;
	completion.emplace_back("stanko");
	completion.emplace_back("ana");
	completion.emplace_back("mislav");

	/// 문제 답
	std::cout << "미완주자 는 -> " << solution(participant, completion) << std::endl;
}

UnfinishedAthlete::~UnfinishedAthlete()
{
}


string UnfinishedAthlete::solution(vector<string> participant, vector<string> completion)
{
	std::string answer = "";

	/// 이름과 현재 상태를 저장하는 임시 테이블을 만든다.
	// 상태
	// 0 -> 그 이름은 달리지 않는 중이라 가정(동명이인 포함 모두 완주) 
	// 1 이상 ->그 이름의 사람이 몇명 달리고 있는지 카운트
	std::unordered_map<std::string, int> temp;
	
	// 참가자들을 모두 검사하면서 그 이름으로 temp에 키값으로 주면서 값을 1 증가
	// 그 이름을 가진 사람이 1명 추가됌(참가자 증가)
	for (auto name : participant)
	{
		temp[name]++;
	}

	// 완주자 목록을 검사하면서 해당하는 이름(사람)을 temp 에서 찾아 감소
	for (auto name : completion)
	{
		temp[name]--;
	}

	/// 완주자 처리를 모두 한후 마지막에 0이 아닌 하나의 이름이 존재, 그 사람이 미완주자!
	for (auto pair : temp)
	{
		// 테이블의 second가 0 보다 크다면? 미완주자
		if (pair.second > 0)
		{
			// answer 에 미완주자의 이름(key 값)을 넣음
			answer = pair.first;
			break;
		}
	}

	return answer;
}
