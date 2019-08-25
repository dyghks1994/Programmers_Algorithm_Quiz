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

	for (int i = 0; i < arr1.size(); i++)	// ���� ���� ��ŭ �ݺ�
	{
		std::vector<int> row;	// �߰��� �ӽ� �� ����

		for (int j = 0; j < arr1[i].size(); j++)	// ���� ���� ��ŭ �ݺ�
		{
			row.emplace_back(arr1[i][j] + arr2[i][j]);	// �� ����� [i][j] ���ҳ��� ����
		}

		answer.emplace_back(row);	// ������ ���Ұ� ������ ���ο� ���� ���ο� ��� answer�� �߰�
	}

	return answer;
}
