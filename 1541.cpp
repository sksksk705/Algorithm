#include <bits/stdc++.h>

// �Ҿ���� ��ȣ
// �ּڰ��� ����� + - �ۿ� ���� ������ + �ۿ� ������ �ʾҴٸ� �� ���ϰ�
// �ѹ��̶� - �� ���Դٸ� �� �ڿ��� ���� ����.

using namespace std;

enum STATE {PLUS , MINUS};		//���� ��ȣ�� ���Ծ����� üũ�ϱ� ���� ���º���(�⺻ �÷���)

int main()
{
	int result = 0;

	string numstr ("");			//0�� ó���ϱ� ���� ���ڿ��� �޾Ƶ���.
	char ch;
	int idx = 0;
	STATE state = PLUS;
	while (true)		
	{
		cin.get(ch);			//�� ���ھ� üũ
		if (isdigit(ch))		//���ڶ�� string�� �߰�
			numstr += ch;
		else					//��ȣ��� string�� ���ڷ� �ٲ��ְ� ���� '-'�� �־��ٸ� ���� '+'�ۿ� �����ٸ� ���Ѵ�.
		{
			int realnum = stoi(numstr);
			if (state == MINUS)
				result -= realnum;
			else if (state == PLUS)
			{
				if (ch == '-') {
					state = MINUS;	//'-'��ȣ�� ������ ���¸� ���̳ʽ��� �ٲ��ش�.
				}
				result += realnum;
			}
			numstr = "";	//�� ���ڿ��� �ʱ�ȭ
		}
		if (ch == '\n')
			break;
	}
	cout << result;

	return 0;
}