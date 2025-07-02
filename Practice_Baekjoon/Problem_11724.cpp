#include"Problem.h"
#include<iostream>
#include<stack>
#include<vector>


/*	링크 : https://www.acmicpc.net/problem/11724
*	티어 : 실버 II
*/

void Problem_11724::Solution() 
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> graph(n);

	for (int i = 0; i < m; i++) 
	{
		int u, v;
		std::cin >> u >> v;

		graph[u - 1].push_back(v);
		graph[v - 1].push_back(u);
	}

	int count = 0;
	std::vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) 
	{
		if (visited[i]) continue;
		std::stack<int> nodeSt;
		nodeSt.push(i + 1);

		while (!nodeSt.empty()) 
		{
			int nowNode = nodeSt.top();
			nodeSt.pop();
			if (visited[nowNode - 1]) continue;
			else 
			{
				visited[nowNode - 1] = true;
				
				for (int next : graph[nowNode - 1]) 
				{
					nodeSt.push(next);
				}
			}
		}
		count++;
	}

	std::cout << count << std::endl;
}