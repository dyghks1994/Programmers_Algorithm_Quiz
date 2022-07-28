#include "stdafx.h"
#include "MinimumRectangle.h"

using std::vector;

MinimumRectangle::MinimumRectangle()
{
	vector<vector<int>> vec;
	vec.push_back({ 60, 50 });
	vec.push_back({ 30, 70 });
	vec.push_back({ 60, 30 });
	vec.push_back({ 80, 40 });

	std::cout << solution(vec);

}

MinimumRectangle::~MinimumRectangle()
{
}

int MinimumRectangle::solution(vector<vector<int>> sizes)
{
	int answer = 0;

	for (auto& rectangle : sizes)
	{
		if (rectangle.at(0) < rectangle.at(1))
		{
			std::swap(rectangle.at(0), rectangle.at(1));
		}
	}

	int maxWidth = sizes[0][0];
	int maxHeight = sizes[0][1];

	for (size_t i = 1; i < sizes.size(); i++)
	{
		maxWidth = std::max(maxWidth, sizes[i][0]);
	}

	for (size_t i = 1; i < sizes.size(); i++)
	{
		maxHeight = std::max(maxHeight, sizes[i][1]);
	}

	answer = maxWidth * maxHeight;

	return answer;
}


