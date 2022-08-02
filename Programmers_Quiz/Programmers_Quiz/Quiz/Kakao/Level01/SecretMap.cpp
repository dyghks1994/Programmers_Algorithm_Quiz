#include "stdafx.h"
#include "SecretMap.h"

using std::vector;
using std::string;

SecretMap::SecretMap()
{
	vector<int> arr1;
	arr1.push_back(9);
	arr1.push_back(20);
	arr1.push_back(28);
	arr1.push_back(18);
	arr1.push_back(11);

	vector<int> arr2;
	arr2.push_back(30);
	arr2.push_back(1);
	arr2.push_back(21);
	arr2.push_back(17);
	arr2.push_back(28);

	vector<string> strVec = solution(5, arr1, arr2);
	for (auto& str : strVec)
	{
		std::cout << str << std::endl;
	}
}

SecretMap::~SecretMap()
{
}

std::vector<std::string> SecretMap::solution(int n, std::vector<int> arr1, std::vector<int> arr2)
{
	vector<string> answer;

	vector<int> secretMap;

	for (size_t i = 0; i < n; i++)
	{
		secretMap.emplace_back(arr1[i] | arr2[i]);
	}

	for (size_t j = 0; j < n; j++)
	{
		string str;
		for (int k = n - 1; k >= 0; k--)
		{
			int comp = 1 << k;

			(secretMap[j] & comp) ? str.append("#") : str.append(" ");
		}

		answer.push_back(str);
	}

	return answer;
}
