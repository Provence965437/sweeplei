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

	//定义二维数组，多加两行两列。这里还挺有意思的，之前做五子棋，直接做判断对于边界点做特殊限制。很明显更麻烦。
	//随机函数种子
	srand((unsigned int)time(NULL) );

	int map[12][12] = {0};
	//埋雷，随机生成10个雷
	int m, n, i, j;
	for (int n = 0; n < 10;) {
		i = rand() % 10 + 1;
		j = rand() % 10 + 1;
		if (map[i][j] == 0) {
			map[i][j] = -1;
			n++;
		}
	}
	//埋数字
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
			MessageBox(hwnd, "你踩到雷了", "BOOM", MB_OK);
			return;
		}

	}
}

int mouseDown(int map[][12])
{
	//定义鼠标变量
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		int i = m.x / 50 + 1;
		int j = m.y / 50 + 1;
		//判断当前鼠标消息
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:

			if (map[i][j] == 0)
			{
				swap(map,i,j);
			}
			else
			{
				//其他情况直接翻开
				map[i][j] += 10;
			}
			return map[i][j];
		}
	}
}

//递归
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
	_getch();    //方式闪屏
	return 0;

}