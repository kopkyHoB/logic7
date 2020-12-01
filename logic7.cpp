#include <time.h>
#include <iostream>
#include <stack>
#include <queue>
#include <conio.h>
//работа сделана
using namespace std;
queue <int> Q;
int i, j, m, h;
int* vis;
int** graph;

void BFS() {
	for (int j = 0; j < m; j++) {
		printf("\nПоиск расстояний от вершины %d\n", j + 1);
		for (int i = 0; i < m; i++) {
			vis[i] = 1000;
		}

		int s = j;
		Q.push(s);
		int st = s;

		vis[s] = 0;

		while (!Q.empty())
		{
			s = Q.front();
			Q.pop();

			for (int r = 0; r < m; r++)
				if ((graph[s][r] > 0) && (vis[r] > vis[s] + graph[s][r]))
				{
					Q.push(r);
					vis[r] = vis[s] + graph[s][r];
				}
		}

		for (int i = 0; i < m; i++)
		{
				printf("%d ", vis[i]);
		}
	}
}


void DFS_main()
{
	setlocale(LC_ALL, "Rus");
	printf("Размерность:  ");
	scanf_s("%d", &m);
	printf("Диапазон  ");
	scanf_s("%d", &h);
	h++;
	graph = new int* [m];
	vis = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		graph[i] = new int[m];
	}
hah:
	//генерация матрицы
	int start;
	printf("Матрица смежности: \n");
	srand(time(NULL));
	for (i = 0; i < m; ++i) {
		for (j = i; j < m; ++j) {
			graph[i][j] = graph[j][i] = rand() % h;
		}
		graph[i][i] = 0; //обнуление вершины
	}
	//нумерование столбцов
	printf("  ");
	for (j = 0; j < m; j++)
	{
		printf("k%d ", j + 1);
	}

	printf("\n");

	//нумерование строк
	for (i = 0; i < m; ++i)
	{
		printf("v%d ", i + 1);
		vis[i] = 0;
		for (j = 0; j < m; ++j)
			printf("%d  ", graph[i][j]);
		printf("\n\n");
	}
	//вывод списков смежности
	for (i = 0; i < m; i++)
	{
		printf("\n%d - ", i + 1);
		for (j = 0; j < m; j++) {
			if (graph[i][j] == 1) printf("%d ", j + 1);
		}
	}

	printf("\nОбход в ширину: ");
	BFS();
	_getch();
}

int Menu(void)
{
	system("CLS");
	int c = 0;
	setlocale(LC_ALL, "Rus");
	while (c < '0' || c > '1')
	{
		printf(
			"::=================================::\n"
			"|| 1 : Обход в ширину              ||\n"
			"|| 0 : Выход                       ||\n"
			"::=================================::\n"
			"> ");
		c = _getch();
		system("cls");
	}
	return c;
}

void main(void)
{
	int Select;
	while ((Select = Menu()) != '0' && Select != 27)
		switch (Select)
		{
		case '1':
			DFS_main();
			break;
		}
}
