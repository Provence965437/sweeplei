#include<stdio.h>
#include<graphics.h>
#include<conio.h>    //_getch
#include<time.h>
void putimg(int map[][12]);
void swap(int map[][12], int m, int n);
int mouseDown(int map[][12]);
HWND hwnd;
void init()
{
	initgraph(500, 500);

	//�����ά���飬����������С����ﻹͦ����˼�ģ�֮ǰ�������壬ֱ�����ж϶��ڱ߽�����������ơ������Ը��鷳��
	//�����������
	srand((unsigned int)time(NULL) );

	int map[12][12] = {0};
	//���ף��������10����
	int m, n, i, j;
	for (int n = 0; n < 10;) {
		i = rand() % 10 + 1;
		j = rand() % 10 + 1;
		if (map[i][j] == 0) {
			map[i][j] = -1;
			n++;
		}
	}
	//������
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {

			if(map[i][j]!=-1)
			{
				int count = 0;
				for (int m = -1; m <= 1; m++)
				{
					for (int n = -1; n <= 1; n++)
					{
						if (map[i + m][j + n] == -1)
							count++;
					}
				 }
				map[i][j] = count;
				
			}
		}
	}

	
	while (1)
	{
		putimg(map);
		if (mouseDown(map) == 9)
		{
			putimg(map);
			MessageBox(hwnd, "��ȵ�����", "BOOM", MB_OK);
			return;
		}

	}
}

int mouseDown(int map[][12])
{
	//����������
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		int i = m.x / 50 + 1;
		int j = m.y / 50 + 1;
		//�жϵ�ǰ�����Ϣ
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:

			if (map[i][j] == 0)
			{
				swap(map,i,j);
			}
			else
			{
				//�������ֱ�ӷ���
				map[i][j] += 10;
			}
			return map[i][j];
		}
	}
}

//�ݹ�
void swap(int map[][12], int m, int n)
{
	map[m][n] = 10;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (m + i >= 1 && m + i <= 10 && n + j >= 1 && n + j <= 10) {
				if(map[m + i][n + j]<9)
					if (map[m + i][n + j] == 0)
						swap(map, m + i, n + j);
					else
						map[m + i][n + j] += 10;
			}
		}
	}
}
void putimg(int map[][12])
{
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			IMAGE img;
			switch (map[i][j])
			{
			case 9:
				loadimage(&img, "img\\lei.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			case 10:
				loadimage(&img, "img\\0.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			case 11:
				loadimage(&img, "img\\1.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			case 12:
				loadimage(&img, "img\\2.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			case 13:
				loadimage(&img, "img\\3.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			case 14:
				loadimage(&img, "img\\4.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			case 15:
				loadimage(&img, "img\\5.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			case 16:
				loadimage(&img, "img\\6.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			case 17:
				loadimage(&img, "img\\7.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			case 18:
				loadimage(&img, "img\\9.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
				break;
			default:
				loadimage(&img, "img\\back.jpg", 50, 50);
				putimage((i - 1) * 50, (j - 1) * 50, &img);
			}
		}
	}
}
int main()
{
	init();
	_getch();    //��ʽ����
	return 0;

}