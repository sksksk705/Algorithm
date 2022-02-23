#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	TreeNode* parent;
	int number;
	vector<pair<TreeNode*,int>> children;
	explicit TreeNode(int n) :number(n) {}
};

int longest;

int height(TreeNode* tree)
{

}

int main()
{
	int n;
	cin >> n;
	TreeNode* root = new TreeNode(1);
	for (int i = 0; i < n; ++i)
	{
		int rootnum;
		cin >> rootnum;
		while (true)
		{
			int children, edge;
			cin >> children;
			if (children == -1)
				break;
			TreeNode* subtree = new TreeNode(children);
			cin >> edge;
			root->children.push_back(make_pair(subtree, edge));
		}
	}
}