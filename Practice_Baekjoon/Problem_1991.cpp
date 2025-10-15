#include"problem.h"
#include<iostream>
#include<map>

using namespace std;

void Problem_1991::Preorder(const map<char, pair<char, char>>& tree, char node)
{
	if (node == '.')
		return;

	cout << node;
	Preorder(tree, tree.at(node).first);
	Preorder(tree, tree.at(node).second);
}

void Problem_1991::Inorder(const map<char, pair<char, char>>& tree, char node)
{
	if (node == '.')
		return;

	Inorder(tree, tree.at(node).first);
	cout << node;
	Inorder(tree, tree.at(node).second);
}


void Problem_1991::Postorder(const map<char, pair<char, char>>& tree, char node)
{
	if (node == '.')
		return;

	Postorder(tree, tree.at(node).first);
	Postorder(tree, tree.at(node).second);
	cout << node;
}


void Problem_1991::Solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n{ 0 };
	cin >> n;

	map<char, pair<char, char>> tree; // first: left, second: right

	for (int i = 0; i < n; ++i) 
	{
		char node, left, right;
		cin >> node >> left >> right;
		tree.emplace(node, pair(left, right));
	}
	Preorder(tree, 'A');
	cout << "\n";
	Inorder(tree, 'A');
	cout << "\n";
	Postorder(tree, 'A');
	cout << "\n";
}