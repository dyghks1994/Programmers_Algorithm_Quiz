#pragma once
class MockExam
{
public:
	MockExam();
	~MockExam();

	std::vector<int> solution(std::vector<int> answers);
	std::vector<int> solution2(std::vector<int> answers);
};

