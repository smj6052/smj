#pragma once
//void title();
//int menu();
//void game_rule();

void title() {
	setcolor(14, 0);
	printf("\n\n=========================================================================\n\n");
	setcolor(10, 0);
	printf("                 #            #       #          #        #    \n");
	printf("         #       #        # # # # #   #         #         # \n");
	printf("        ##       #            #    ## #        ##     # # # \n");
	printf("       #  #      # # #      #   #     #       #   #       #    \n");
	printf("      #    #     #        #       #   #      #      #     #       \n");
	printf("     #      #    #           #                    # # # # #     \n");
	printf("                 #           #                  #          #  \n");
	printf("                 #           # # # # # #          # # # # #  \n");
	setcolor(14, 0);
	printf("\n=======================================================================\n");
}
int menu() {
	setcolor(7, 0);
	gotoxy(28, 15);
	printf("���ӽ���");
	gotoxy(28, 17);
	printf("���� ���");
	gotoxy(28, 19);
	printf("����\n\n\n");
	int x = 26, y = 15;
	gotoxy(x, y);
	printf(">");
	while (1) {		//���ѹݺ�	>> enter ġ�� ����
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x, y);
				printf("  ");
				gotoxy(x, y - 2);
				printf(">");
				y -= 2;
			}
			break;
		}
		case DOWN: {
			if (y < 19) {
				gotoxy(x, y);
				printf("  ");
				gotoxy(x, y + 2);
				printf(">");
				y += 2;
			}
			break;
		}
		case ENTER: {
			switch (y) {
			case 19: {
				system("cls");
				return 0;	//���� ����
			}
			case 15: {
				system("cls");
				return 1;	//���� ����
			}
			case 17: {
				system("cls");
				return 2;	//���� ���
			}
			}
		}
		}
	}
}

void game_rule() {
	system("cls");
	setcolor(6, 0);
	printf("\n\n\n========== �� õ ��  �� ��  �� �� ===========\n\n\n");
	setcolor(14, 0);
	printf("* ��� �и� ���� �ϸ� ������ ����˴ϴ�.\n\n");
	printf("  �и� ������ �� �ִ� ���� ������ �����ϴ�.\n\n");
	printf("  >>������ �� 2���� ������ ���� ��\n\n");
	printf("  >>������ ����� �� 2�� ���̿� �ٸ� �а� ���� ���, \n\n");
	printf("    ���� �Ǵ� ������ �������� �����Ͽ� �� ���� ���η����� Ƚ���� 2ȸ �̳� �� �� \n\n");
	printf("    (��, 3�� �̳��� ������ �Ǵ� ������ �������� 2���� �и� ���� ��) \n\n\n");
	printf("* ����Ű�� �����ϰ�, ���� �� ���͸� �����ϴ�.\n\n\n");
	printf("* �ð� ������ �ֽ��ϴ�.\n\n\n");
	printf("* �߸� ���� �� ����� �پ��ϴ�. (��� 5��)\n\n");
	printf("=====================================================");
	printf("\n\n �縦 ������ ����ȭ������ �̵��մϴ�..........");

	while (1) {
		if (keyControl() == LEFT) {
			break;
		}
	}
}

void print_life(int life) {
	gotoxy(7, 25);
	for (int k = 0; k < life; k++) {
		printf("��");	//��
	}
}