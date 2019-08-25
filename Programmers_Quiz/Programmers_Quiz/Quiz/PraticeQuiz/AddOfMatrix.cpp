#include "stdafx.h"
#include "AddOfMatrix.h"

AddOfMatrix::AddOfMatrix()
{
	std::vector<std::vector<int>> v1 = 
	{ 
		{ 1 }, 
		{ 2 }
	};
	
	std::vector<std::vector<int>> v2 = 
	{  
		{ 3 }, 
		{ 4 } 
	};

	std::cout << "v1 = " << std::endl;
	for (auto v : v1)
	{
		for (auto n : v)
			std::cout << n << std::endl;
		
		
	}
	std::cout << std::endl;
	std::cout << "v2 = " << std::endl;
	for (auto v : v2)
	{
		for (auto n : v)
			std::cout << n << std::endl;
	}
	std::cout << std::endl;
		

	std::cout << "v3 = " << std::endl;
	std::vector<std::vector<int>> v3 = solution(v1, v2);
	for (auto v : v3)
	{
		for (auto n : v)
			std::cout << n << std::endl;
	}
}

AddOfMatrix::~AddOfMatrix()
{
}

std::vector<std::vector<int>> AddOfMatrix::solution(std::vector<std::vector<int>> arr1, std::vector<std::vector<int>> arr2)
{
	std::vector<std::vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++)	// 행의 갯수 만큼 반복
	{
		std::vector<int> row;	// 추가할 임시 행 변수

		for (int j = 0; j < arr1[i].size(); j++)	// 열의 갯수 만큼 반복
		{
			row.emplace_back(arr1[i][j] + arr2[i][j]);	// 각 행렬의 [i][j] 원소끼리 더함
		}

		answer.emplace_back(row);	// 각각의 원소가 더해진 새로운 행을 새로운 행렬 answer에 추가
	}

	return answer;
}
