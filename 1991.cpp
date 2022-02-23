#include <iostream>
#include <string>
#include <map>

using namespace std;
struct TreeNode
{
	char label;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	explicit TreeNode(char s) :label(s) {};
};

enum order{PRE,IN,POST};
void printTree(TreeNode* root, order printorder)
{
	if (printorder == PRE)
		cout << root->label;

	if(root->left != nullptr)
		printTree(root->left, printorder);

	if (printorder == IN)
		cout << root->label;

	if (root->right != nullptr)
		printTree(root->right, printorder);

	if (printorder == POST)
		cout << root->label;

}


int main()
{
	int n;
	cin >> n;
	map<char, TreeNode*> tree;
	for (int i = 0; i < n; ++i)
	{
		TreeNode* root = new TreeNode('\0');
		char label;
		char left_label;
		char right_label;
		cin >> label >> left_label >> right_label;
		auto findRoot = tree.find(label);
		if (findRoot != tree.end())
			root = findRoot->second;
		else {
			root->label = label;
			tree.emplace(label, root);
		}
		if (left_label != '.') {
			TreeNode* left = new TreeNode(left_label);
			root->left = left;
			tree.emplace(make_pair(left_label, left));
		}
		if (right_label != '.') {
			TreeNode* right = new TreeNode(right_label);
			root->right = right;
			tree.emplace(make_pair(right_label, right));
		}
	}
	printTree(tree.find('A')->second, PRE);
	cout << '\n';

	printTree(tree.find('A')->second, IN);
	cout << '\n';

	printTree(tree.find('A')->second, POST);
}
