#include<iostream>
#include<string>
#include<algorithm>//STL reverse������ͷ�ļ���reverse��ת������
using namespace std;
int main()
{
	int cas, len, sub, maxn;
	int n, k, i, j;
	string s[102];
	cin >> cas;
	while (cas--)
	{
		cin >> n;
		len = 1000;
		sub = 0;
		for (i = 0; i < n; i++)
		{
			cin >> s[i];
			if (len > s[i].size())//����С ��ĸ��
			{
				len = s[i].size();
				sub = i;
			}
		}
		maxn = 0;
		for (i = s[sub].size(); i > 0; i--) //����С��ĸ����ʼ�ӳ��������Ӵ���
		{
			for (j = 0; j < s[sub].size() - i + 1; j++) //����Ϊi���Ӵ���ĸ������
			{
				string s1, s2;//s1Ϊ�Ӵ��� ��s2Ϊ�Ӵ���
				s1 = s[sub].substr(j, i);//ȥj��ʼi�������ַ�
				s2 = s1;
				reverse(s2.begin(), s2.end());//����
				for (k = 0; k < n; k++)
				{
					if (s[k].find(s1, 0) == -1 && s[k].find(s2, 0) == -1) //�������Ӵ���ĸ���ж�δ����ʱ������
						break;

				}
				if (k == n && maxn < s1.size())
					maxn = s1.size();

			}

		}
		cout << maxn << endl;
	}
	return 0;
}