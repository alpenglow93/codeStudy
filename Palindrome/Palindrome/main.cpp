#include <iostream>
#include <string>
#include <vector>
using namespace std;

//babba

//다른 글자를 처음 만났을때 양쪽 인덱스에서의 유사회문 검사를 하고 그 결과를 리턴하는 함수
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

	//회문이긴하니까 return true
	return Lpali | Rpali;
}

int main()
{
	int t;
	string input;			//cin 하는 string을 잠시 저장하는 용도
	cin >> t;
	vector<string> words;	//문자열들을 보관할 장소
	vector<int> output;		//출력

	words.reserve(t);
	output.reserve(t);

	//입력된 t만큼의 문자열을 벡터에 push_back()
	for (int i = 0; i < t; i++)
	{
		cin >> input;
		words.push_back(input);
		input.clear();
	}

	for (int i = 0; i < t; i++)	//보관되어있는 문자열들을 하나씩 검사
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

			//여기로 내려왔으면 다른 글자를 만났다는 뜻
			if (chk == false)	//다른 글자를 처음 만났다
			{
				chk = true;

				//**이 부분을 변경해야함. 다음 글자가 같다고 그냥 ++ 하는게 아니고 양쪽 케이스 모두 판단해야함.
				//설마 다음 글자가 같은 회문이 있을줄은 생각도 못했네
				if (word[left + 1] == word[right] && word[left] == word[right - 1])
				{
					//이런 경우엔 어쩔 수 없이 함수 안에 들어가서 양쪽 모두 판단하고 결과를 뱉어내기
					//어차피 유사회문 아니면 일반문자열이라 bool 함수로 해서 pali 변수만 바꿔주면 될 듯
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
					//false일 경우 하던대로 하는 코드

					//else if 하지 말고 if로 한 다음 바로 위에서 통과 했는지 체크하고 윗 단에도 들어갔다 나온게 확인되면
					//이 if문에 들어왔다는것 자체가 양 쪽 모두 같단 얘기니까 그때 체크해도 되지 않을까?
					//false 나오면 그냥 하던대로 하면 될 것 같은데
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
			else //다른 글자를 만난적이 있다
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

	//출력
	for (int i = 0; i < t; i++)
	{
		cout << output[i] << endl;
	}

	return 0;
}