#include <iostream>
#include <string>
#include <vector>
using namespace std;

//babba

//�ٸ� ���ڸ� ó�� �������� ���� �ε��������� ����ȸ�� �˻縦 �ϰ� �� ����� �����ϴ� �Լ�
bool pali_chk(string word, int l, int r)
{
	bool Lpali = true;
	bool Rpali = true;
	int left = l;
	int right = r;


	left++;
	while (left <= right)
	{
		if (word[left] == word[right])
		{
			left++;
			right--;
			continue;
		}
		else
		{
			Lpali = false;
			break;
		}
	}

	left = l;
	right = r;

	right--;
	while (left <= right)
	{
		if (word[left] == word[right])
		{
			left++;
			right--;
			continue;
		}
		else
		{
			Rpali = false;
			break;
		}

		left++;
		right--;
	}

	//ȸ���̱��ϴϱ� return true
	return Lpali | Rpali;
}

int main()
{
	int t;
	string input;			//cin �ϴ� string�� ��� �����ϴ� �뵵
	cin >> t;
	vector<string> words;	//���ڿ����� ������ ���
	vector<int> output;		//���

	words.reserve(t);
	output.reserve(t);

	//�Էµ� t��ŭ�� ���ڿ��� ���Ϳ� push_back()
	for (int i = 0; i < t; i++)
	{
		cin >> input;
		words.push_back(input);
		input.clear();
	}

	for (int i = 0; i < t; i++)	//�����Ǿ��ִ� ���ڿ����� �ϳ��� �˻�
	{
		int left = 0;
		int right = words[i].size();
		string word = words[i];

		bool chk = false;
		bool pali = true;

		for (left = 0; left < right; left++)
		{
			right--;

			if (word[left] == word[right])
			{
				continue;
			}

			//����� ���������� �ٸ� ���ڸ� �����ٴ� ��
			if (chk == false)	//�ٸ� ���ڸ� ó�� ������
			{
				chk = true;

				//**�� �κ��� �����ؾ���. ���� ���ڰ� ���ٰ� �׳� ++ �ϴ°� �ƴϰ� ���� ���̽� ��� �Ǵ��ؾ���.
				//���� ���� ���ڰ� ���� ȸ���� �������� ������ ���߳�
				if (word[left + 1] == word[right] && word[left] == word[right - 1])
				{
					//�̷� ��쿣 ��¿ �� ���� �Լ� �ȿ� ���� ���� ��� �Ǵ��ϰ� ����� ����
					//������ ����ȸ�� �ƴϸ� �Ϲݹ��ڿ��̶� bool �Լ��� �ؼ� pali ������ �ٲ��ָ� �� ��
					pali = pali_chk(word, left, right);
					break;
				}
				else if (word[left + 1] == word[right])
				{
					left++;
				}
				else if (word[left] == word[right - 1])
				{
					right--;
					//false�� ��� �ϴ���� �ϴ� �ڵ�

					//else if ���� ���� if�� �� ���� �ٷ� ������ ��� �ߴ��� üũ�ϰ� �� �ܿ��� ���� ���°� Ȯ�εǸ�
					//�� if���� ���Դٴ°� ��ü�� �� �� ��� ���� ���ϱ� �׶� üũ�ص� ���� ������?
					//false ������ �׳� �ϴ���� �ϸ� �� �� ������
					//
					//
					//
				}
				else
				{
					pali = false;
					break;
				}
			}
			else //�ٸ� ���ڸ� �������� �ִ�
			{
				pali = false;
				break;
			}
		}

		if (chk == false && pali == true)
		{
			output.push_back(0);
		}
		else if (chk == true && pali == false)
		{
			output.push_back(2);
		}
		else if (chk == false && pali == false)
		{
			output.push_back(2);
		}
		else if (chk == true && pali == true)
		{
			output.push_back(1);
		}
		else
		{
			return 0;
		}

		chk = false;
		pali = true;
	}

	//���
	for (int i = 0; i < t; i++)
	{
		cout << output[i] << endl;
	}

	return 0;
}