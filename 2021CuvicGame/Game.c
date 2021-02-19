#include "util.h"
#include "Gmain.h"
#include "Judge.h"

void gLoop();
void LelCh(int level);		//���� üũ �Լ�
void drawMap(int level);
int selected[2] = { 0,0 };		// ������ array ���(?) ����
//int array[17] = { 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8 };
char array[17] = { '1','2','3','4','5','6','7','8','1','2','3','4','5','6','7','8' };
char L2[16] = {'a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h' };
char L3[16] = { '#','#','&','&','!','!','?','?','$','$','@','@','+','+','=','=' };
char L4[16] = { '~','~','-','-','=','=',',',',','.','.','/','/','|','|','_','_'};

//�ѱ۰� ���ڴ� 2����Ʈ��,,,,, ����,,,,,
//char L4[] = "�ääŤŤƤƤĤĤ����¤¤ϤϤʤ�";
//char L5[]
//����Ҷ��� printf("%c%c",L4[i],L4[i+1])  �̷�������....

void move(int* array_zo, int* x, int* y, int* correct);

int main() {
	init();
	while (1) {
		title();
		int menuCh = menu();
		if (menuCh == 0) {	//���� ����
			return 0;
		}
		else if (menuCh == 1) {		//���� ����
			gLoop();	//���� ����
		}
		else if (menuCh == 2) {		//���� ���
			game_rule();
		}
		system("cls");
	}
	return 0;
}

void gLoop() {
	int playing = 1;	// 1 : ���� ��, 0 :���� ����
	int level = 1,correct=0;
	int array_zo[6][6];		//array_zo ����	//����...?
	for (int j = 0; j < 6; j++)
		for (int i = 0; i < 6; i++)
			array_zo[i][j] = 1;
	for (int i = 0; i < 6; i++){
		array_zo[0][i] = 0;
		array_zo[i][0] = 0;
		array_zo[5][i] = 0;
		array_zo[i][5] = 0;
	}
	drawMap(level);		//�� ���
	setcolor(10, 0);	//�ʱ� Ŀ�� ��ġ���� ���
	int x = 11, y = 7;	
	gotoxy(x+1 , y);
	printf("\b%c", array[0]);
	while (playing) {	//���� ����
		if (_kbhit()) {
			move(array_zo, &x, &y, &correct);
			
		}
		
	}
}
void move(int* array_zo,int *x,int*y,int *correct) {	
	setcolor(7, 0);		//�̵� �� ������� ���
	printf("\b%c", array[cursor]);
	int key = keyControl();
	if (key == UP) {
		*y -= 4;
		cursor -= 4;
		if (*y < 7) {
			*y = 19;
			cursor += 16;
		}
	}
	else if (key == DOWN) {
		*y += 4;
		cursor += 4;
		if (*y > 19) {
			*y = 7;
			cursor -= 16;
		}
	}
	else if (key == LEFT) {
		*x -= 9;
		cursor -= 1;
		if (*x < 3) {
			*x = 38;
			cursor += 4;
		}
	}
	else if (key == RIGHT) {
		*x += 9;
		cursor += 1;
		if (*x > 38) {
			*x = 11;
			cursor -= 4;
		}
	}
	//Enter ù ��°
	else if (key == ENTER && number == 0) {
		setcolor(4, 0);
		printf("*");
		a = (*x - 11) / 9;
		b = (*y - 7) / 4;
		number++;
		selected[0] = cursor;
	}
	//Enter �� ��°
	else if (key == ENTER && number == 1)
	{
		c = (*x - 11) / 9;
		d = (*y - 7) / 4;
		number = 0;
		selected[1] = cursor;

		gotoxy(a * 9 + 11 + 1, b * 4 + 7);
		printf(" ");

		if (a == c && b == d || array[selected[0]] != array[selected[1]]) {		//���� �� ����
			for (int i = 0; i < 2; i++) {	//selected �Լ� �ʱ�ȭ
				selected[i] = 0;
			}
		}
		else {
			if (play_set(a, b, c, d, array_zo, array) == 1 || playa_set(a, b, c, d, array_zo, array) == 1 || playb_set(a, b, c, d, array_zo, array) == 1) {
				array[selected[0]] = 0;
				array[selected[1]] = 0;
				gotoxy(a * 9 + 11, b * 4 + 7);
				printf("\b\b\b\b        ");
				gotoxy(c * 9 + 11, d * 4 + 7);
				printf("\b\b\b\b        ");

				*correct++;	//correct 8�� �Ǹ� ������ ����
			}
		}
	}
	gotoxy(*x, *y);
	setcolor(10, 0);
	printf("%c", array[cursor]);
}

void LelCh(int level) {
	if (level == 2) {	//����
		memcpy(array, L2, sizeof(array));
	}
	else if (level == 3) {		//���� ��ȣ
		memcpy(array, L3, sizeof(array));
	}
	else if (level == 4) {		//����� ��ȣ
		memcpy(array, L4, sizeof(array));
	}
}
void drawMap(int level) {
	setcolor(14, 2);
	printf("\n                   ��  õ  ��                    \n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("                                          level : %d\n\n", level);
	LelCh(level);
	shuffle(array);
	for (int i = 0; i < 16; i++) {
		if (i % 4 == 0) {
			gotoxy(7, i + 7);
		}
		printf(" [  %c  ] ", array[i]);
	}
	gotoxy(0, 23);
	printf("=============================================\n\n");
	printf("  ������������������                ���������������� \n");
	printf("  �� reset ��  : R Ű        �� quit ��  : Q Ű \n");
	printf("  ������������������                ����������������\n");
	system("pause");
}