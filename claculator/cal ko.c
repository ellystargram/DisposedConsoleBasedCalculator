#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <string.h>


int main() {

	int errorcode = 0; //�����ڵ�
	int debug = 0;//�����
	int origin=debug;//������ ����װ�
	int launched = 0; //�������
	char sel = '0';//���ñ�
	char console[100];
	int darkmode = 1;//��ũ���on/off
	
hardreset://��ü�ʱ�ȭ
	system("title CAL Launcher");
	if (debug == 1)
		system("title CAL Launcher with debug");
	switch (darkmode) {
	case 1:
		system("color 0f");
		break;
	case 0:
		system("color f0");
		break;
	}
	if (debug == 666)
		goto special;
	if (debug < 0 || debug > 1) {
		errorcode = 1;
		goto error;
	}//debug�� ������ �� �ܷ̿� �����°� ������
	if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
	printf("CAL");
	printf("\nCGO studio present\n");
	if (debug != 0) {
		printf("\n����� ����\n");
		printf("\nA. ����׸��� ����, B. ����׸�� ���� ����, Z. ����ɼ�\n");
		scanf_s("%c", &sel);
		getchar();
		switch (sel) {
		case 'a':
		case 'A':
		case '1':
			if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
			goto start;
			break;
		case 'b':
		case 'B':
		case '2':
			debug = 0;
			if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
			goto hardreset;
			break;
		case 'z':
		case 'Z':
		case '0':
			goto start;
			break;
		case '=':
			goto console;
			break;
		default:
			errorcode = 2;
			goto error;
		}
	}
	else {
		printf("\n\nA. ����, Z.����ɼ�\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		switch (sel) {
		case 'a':
		case 'A':
		case '1':
			goto start;
			break;
		case 'z':
		case 'Z':
		case '0':
			goto poweroption;
			break;
		case '=':
			goto console;
			break;
		default:
			errorcode = 2;
			goto error;
			break;
		}
	}

start: //���� ����
	system("title CAL");
	if (debug == 1)
		system("title CAL with debug");
	int keep = 0;//�̾����ϱⰡ ����ֳ�?
	long long a1 = 0;//����a
	long long b1 = 0;//����b
	long long c1 = 0;//����c
	long double a2 = 0;//�Ǽ�a
	long double b2 = 0;//�Ǽ�b
	long double c2 = 0;//�Ǽ�c
	int XYZ = 0;	//����/�Ǽ�
	launched = 1;

	if (errorcode != 0)
		goto error;
	if (sel == 'z' || sel == 'Z' || sel == '0')
		goto poweroption;
	else if (sel == '=')
		goto console;
	if (!strcmp(console, "stat")) {
		goto console;
	}

softreset://�ٸ����
	printf("A. �Ϲݰ��, B. ��Ʈ����, C. ��Ʈ����Ʈ����, D. Ȧ¦����, Z. ����ɼ�\n");
	scanf_s("%c", &sel);
	getchar();
	if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

	switch (sel) {
	case 'a'://�Ϲݰ��
	case 'A':
	case '1':
		{printf("A. �������, B. �Ǽ����, Z. ����ɼ�\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		switch (sel) {

		case 'a'://�������
		case 'A':
		case '1':
		{XYZ = 0;
		if (keep == 0) {//�̾����ϱⰡ �ƴѰ�쿡�� ������
			printf("(X) x X = ?");
			printf("\nù��° ���� :");
			scanf_s("%lld", &a1);
			getchar();
			if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		}

		printf("%lld x (X) = ?", a1);
		printf("\n�ι�° ���� :");
		scanf_s("%lld", &b1);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

		printf("%lld (x) %lld = ?", a1, b1);
		printf("\n+, -, *, /, %%, ^\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		switch (sel) {
		case '+':
		case '1':
			c1 = a1 + b1;
			printf("%lld + %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '-':
		case '2':
			c1 = a1 - b1;
			printf("%lld - %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '*':
		case '3':
			c1 = a1 * b1;
			printf("%lld * %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '/':
		case '4':
			if (b1 == 0) {
				errorcode = 3;
				goto error;
			}
			c1 = a1 / b1;
			printf("%lld / %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '%':
		case '5':
			c1 = a1 % b1;
			printf("%lld %% %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '^':
		case '6':
			c1 = pow(a1, b1);
			if (c1 < 0) {
				puts("Overflow");
				goto softreset;
			}
			else {
				printf("%lld ^ %lld = %lld", a1, b1, c1);
			}
			goto done;
			break;
		case '=':
			goto console;
			break;
		default:
			errorcode = 2;
			goto error;
			break;
		}
		}

		case 'b'://�Ǽ����
		case 'B':
		case '2':
		{
			XYZ = 1;
			if (keep == 0) {//�̾����ϱⰡ �ƴѰ�쿡�� ������
				printf("(X) x X = ?");
				printf("\nù��° ���� :");
				scanf_s("%Lf", &a2);
				getchar();
				if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
			}

			printf("%Lf x (X) = ?", a2);
			printf("\n�ι�° ���� :");
			scanf_s("%Lf", &b2);
			getchar();
			if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

			printf("%Lf (x) %Lf / ?", a2, b2);
			printf("\n+, -, *, /, %%, ^\n");
			scanf_s("%c", &sel);
			getchar();
			if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
			switch (sel) {
			case '+':
			case '1':
				c2 = a2 + b2;
				printf("%Lf + %Lf = %Lf\n", a2, b2, c2);
				goto done;
				break;
			case '-':
			case '2':
				c2 = a2 - b2;
				printf("%Lf - %Lf = %Lf\n", a2, b2, c2);
				goto done;
				break;
			case '*':
			case '3':
				c2 = a2 * b2;
				printf("%Lf * %Lf = %Lf\n", a2, b2, c2);
				goto done;
				break;
			case '/':
			case '4':
				if (b2 == 0) {
					errorcode = 3;
					goto error;
				}
				c2 = a2 / b2;
				printf("%Lf / %Lf = %Lf\n", a2, b2, c2);
				goto done;
				break;
			case '%':
			case '5':
				c2 = fmod(a2, b2);
				printf("%Lf %% %Lf = %Lf\n", a2, b2, c2);
				goto done;
				break;
			case '^':
			case '6':
				c1 = pow(a1, b1);
				printf("%lld ^ %lld = %lld", a1, b1, c1);
				goto done;
				break;
			case '=':
				goto console;
				break;
			default:
				errorcode = 2;
				goto error;
				break;
			}
		case 'z'://����ɼ�
		case 'Z':
		case '0':
			goto poweroption;
			break;
		case '=':
			goto console;
			break;
		default:
			errorcode = 2;
			goto error;
			break;
		}
		}
		}
	case 'b'://��Ʈ����
	case 'B':
	case '2':
		{XYZ = 0;
		printf("(X) x X = ?");
		printf("\nù��° ���� :");
		scanf_s("%lld", &a1);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

		printf("%lld x (X) = ?", a1);
		printf("\n�ι�° ���� :");
		scanf_s("%lld", &b1);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

		printf("%lld (x) %lld = ?", a1, b1);
		printf("\n&, |, ^, ~\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

		switch (sel) {
		case '&':
		case '1':
			c1 = a1 & b1;
			printf("%lld & %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '|':
		case '2':
			c1 = a1 | b1;
			printf("%lld | %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '^':
		case '3':
			c1 = a1 ^ b1;
			printf("%lld ^ %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '~':
		case '4':
			c1 = ~a1;
			printf("~%lld = %lld\n", a1, c1);
			goto done;
			break;
		case '=':
			goto console;
			break;
		default:
			errorcode = 2;
			goto error;
			break;
		}
	 }
	case 'c'://��Ʈ����Ʈ����
	case 'C':
	case '3':
	{
		XYZ = 0;
		printf("(X) x X = ?");
		printf("\nù��° ���� :");
		scanf_s("%lld", &a1);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

		printf("%lld x (X) = ?", a1);
		printf("\n�ι�° ���� :");
		scanf_s("%lld", &b1);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

		printf("%lld (x) %lld = ?", a1, b1);
		printf("\n<, >\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

		switch (sel) {
		case '<':
		case '1':
			c1 = a1 < b1;
			printf("%lld < %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '>':
		case '2':
			c1 = a1 > b1;
			printf("%lld > %lld = %lld\n", a1, b1, c1);
			goto done;
			break;
		case '=':
			goto console;
			break;
		default:
			errorcode = 2;
			goto error;
			break;
		}
	}
	case 'd'://Ȧ¦����
	case 'D':
	case '4':
	{
		XYZ = 0;

		printf("(X) %% 2 = ?");
		printf("\n���� �Է��Ͻÿ� :");
		scanf_s("%lld", &a1);
		getchar();
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�

		printf("%lld %% 2 = %lld", a1, a1 % 2);
		if (a1 % 2 == 0)
			printf("\n���: ¦��\n");
		else
			printf("\n���: Ȧ��\n");
		goto done;
		break; }
	case 'z':
	case 'Z':
	case '0':
		goto poweroption;
		break;
	case '=':
		goto console;
		break;
	default:
		errorcode = 2;
		goto error;
		break;
	}
	
done://�����
	printf("A. �ٸ�����ϱ�, B. �̾����ϱ�, Z. ����ɼ�\n");
	scanf_s("%c", &sel);
	getchar();
	if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
	switch (sel) {
	case 'a':
	case 'A':
	case '1':
		keep = 0;//�̾��� ����
		goto softreset;
		break;
	case 'b':
	case 'B':
	case '2':
		keep = 1;//�̾��� Ű��
		a1 = c1;
		a2 = c2;
		if (XYZ == 0) {
			a2 = a1;
		}
		if (XYZ == 1) {
			a1 = a2;
		}
		goto softreset;
		break;
	case 'z':
	case 'Z':
	case '0':
		goto poweroption;
		break;
	case '=':
		goto console;
		break;
	default:
		errorcode = 2;
		goto error;
		break;
	}

poweroption://�����ɼ�
	system("title poweroption");
	if (debug == 1)
		system("title poweroption with debug");
	if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
	printf("A. ����, B. �����, C. ũ����, D. ��ũ��� ���");
	if (debug == 1)
		printf(", E. ������Ȳ, F. ����׸��� �����\n");
	else
		printf("\n");
	scanf_s("%c", &sel);
	getchar();
	if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
	switch (sel) {
	case 'a':
	case 'A':
	case '1':
		return 0;
		break;
	case 'b':
	case 'B':
	case '2':
		debug = 0;
		goto hardreset;
		break;
	case 'c':
	case 'C':
	case '3':
		printf("������: ������\n���: CGO studio\n������: 2022/07/12\n����: 1.2\n");
		system("pause");
		goto poweroption;
		break;
	case 'd':
	case 'D':
	case '4':
		if (darkmode == 0)
			darkmode++;
		else
			darkmode--;
		if (darkmode == 0)
			system("color f0");
		else
			system("color 0f");
		goto poweroption;
		break;
	case 'e':
	case 'E':
	case '5':
		if (debug == 0) {
			errorcode = 2;
			goto error;
		}
		if (launched == 0)
			goto start;
		printf("errorcode : %d\n", errorcode);
		printf("debug : %d\n", debug);
		printf("origin : %d\n", origin);
		printf("launched : %d\n", launched);
		printf("sel : %c\t%d\n", sel, sel);
		printf("console : %s\n", console);
		printf("darkmode : %d\n", darkmode);
		printf("keep : %d\n", keep);
		printf("a1 : %lld\n", a1);
		printf("b1 : %lld\n", b1);
		printf("c1 : %lld\n", c1);
		printf("a2 : %Lf\n", a2);
		printf("b2 : %Lf\n", b2);
		printf("c2 : %Lf\n", c2);
		printf("XYZ : %d\n", XYZ);

		system("pause");
		goto poweroption;
		break;
	case 'f':
	case 'F':
	case '6':
		debug = 1;
		goto hardreset;
		break;
	case '=':
		goto console;
		break;
	default:
		errorcode = 2;
		goto error;
		break;
	}
	

error://��������Ʈ
	if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
	system("title error");
	if (debug == 1)
		system("title error with debug");
	if (darkmode == 1)
		system("color 09");
	else
		system("color 1f");
	switch (errorcode) {
	case 0:
		printf("errorcode_unknown");
		break;
	case 1:
		printf("debug_error");
		break;
	case 2:
		printf("sellect_error");
		break;
	case 3:
		printf("/0_error");
		break;
	case 999:
		printf("forced_crash_error");
	}
	printf("�� �߻��Ͽ����ϴ�.\n");
	system("pause");
	if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
	printf("��� ����\n");
	printf("A. �����, B. ����, C. ��������");
	printf("\n");
	scanf_s("%c", &sel);
	getchar();
	switch (sel) {
	case 'A':
	case 'a':
	case '1':
		errorcode = 0;
		goto hardreset;
		break;
	case 'B':
	case 'b':
	case '2':
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		return 0;
		break;
	case 'C':
	case 'c':
	case '3':
		if (launched == 0) {
			goto start;
		}
		printf("errorcode : %d\n", errorcode);
		printf("debug : %d\n", debug);
		printf("sel : %c\n", sel);
		printf("keep : %d\n", keep);
		printf("a1 : %lld\n", a1);
		printf("b1 : %lld\n", b1);
		printf("c1 : %lld\n", c1);
		printf("a2 : %Lf\n", a2);
		printf("b2 : %Lf\n", b2);
		printf("c2 : %Lf\n", c2);
		printf("XYZ : %d\n", XYZ);
		printf("launched : %d\n", launched);

		system("pause");
		goto error;
		break;
	case '=':
		goto console;
		break;
	default:
		errorcode = 2;
		goto error;
		break;
	}
special:
	if (debug == 110) {//���ؼ� �̽��Ϳ���
		printf("\n�ؼ��̴� �ٺ���\n");
		printf("�ؼ��̴� ���α׷����� (��)�Ѵ�\n");
		printf("���� ������ ���� ������ ����Ǿ� 80�밡 �Ǿ���\n����������\n");
	}
	else if (debug == 116) {//ȫ�¹� �̽��Ϳ���
		printf("\nȫ�ֹ�\n���� ������ 7��12��\n�׳��� �װ� �¾�������\n");
	}
	
	else if (debug == 101) {//������ �̽��Ϳ���
		printf("\n���ذ�\nCDPR�� ��ü\n���ӵǴ� ��߿���\n������ �� OCTA�� ��ǰ�����ð�\n");
	}
	else if (debug == 102) {//�賫�� �̽��Ϳ���
		printf("\n1������ �����Ǵ� �系\n�״� �ڽ��� 1���� �ƴ϶� �����Ѵٳ�\n�״� �ڱ⸦ 1���̶� �θ��°� �Ⱦ��Ѵٳ�\n������ �����̶� ���������� ������ �۽�\n");
	}
	else if (debug == 103) {
		printf("\n�輭��\n�츮�� �ܰ��� ������ �̸��� ���Ƽ� �̸� �ܿ�� ����\n��Ʈ������ '����' '����'\n����������\n");
	}
	else if (debug == 104) {//������
		printf("\n������\nŰ�� ��¥ ŭ\n���� ����\n���� ����(���������)\n");
	}
	else if (debug == 105) {//�μ���
		printf("\n�μ���\n�����̴� ������ ���\n�忰�ɷ��� �����ܴ�\n���ڵ� �ϰ��ִ���\n");
	}
	else if (debug == 106) {//�۴ٿ�
		printf("\n�۴ٿ�\n�ڱ׸�ġ ���α׷����� 40���븦 �����̴�\n�� ����� ���̴�\n���� �׳��� 2�б� �߰���� ������?\n");
	}
	else if (debug == 10000) {//�¿��� �̽��Ϳ���
		printf("\n�¿���\n�츮 �ܱ��Ӵ� ����\n����� ����ħ\n����\n��� ���͸� �޶���\n");
	}
	else if (debug == 10001) {//���ǽ�
		printf("\n������\n���ǽ��̽ô�\n�����Ĵ�\n�ǾƳ� ġ�⸦ �����Ƽ� ���ָ� �ñ��.\n");
	}
	else if (debug == 10002) {//������
		printf("\n����B�� ����ġ�ô� �迩�� ������\n�����Ե��� ���� Ʈ���� �Ͻ� ��\n������ ����� �ʹ� ��μ� ���� �ɷ��� �������\n");
	}
	else if (debug == 10003) {//����ȣ��
		printf("\n����ȣ �������� ���⸦ ����ģ��\n�ʹ� ��ƴ�\n������ �����!\n����� �츮�� 1���̴ϱ� ������?\n");
	}
	else if (debug == 10004) {
		printf("\n���̰� ������\n���� �ʹ� �������\n�̷��� ���� ���� ���̵��� ����������\n������������\n");
	}
	system("pause");
	if (origin == 0)
		debug = 0;
	else
		debug = 1;
	goto poweroption;




console:
	printf("console: ");
	origin = debug;
	gets(console);
	if (!strcmp(console, "debugon")||!strcmp(console, "debug1") ){//����� Ű�� �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		debug = 1;
		origin = debug;
		printf("����� ����");
		printf("\n");
		system("pause");
		goto hardreset;
	}
	else if (!strcmp(console, "debugoff") || !strcmp(console, "debug0") ){//����� ���� �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		debug=0;
		origin=debug;
		printf("����� ����");
		printf("\n");
		system("pause");
		goto hardreset;
	}
	
	else if (!strcmp(console, "cdpr")|| !strcmp(console, "kyj")) {//CDPR���߼ӵ�������
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("���� �ӵ��� ���� �� CDPR�� ��� ����");
		debug = 101;
		goto special;
	}
	else if (!strcmp(console, "1st") || !strcmp(console, "knh")) {//1��
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("1������ �����Ǵ� ��� ����");
		debug = 102;
		goto special;
	}
	else if (!strcmp(console, "ksy")) {//�輭��
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("��Ī ��Ʈ�ø� ��� ����");
		debug = 103;
		goto special;
	}
	else if (!strcmp(console, "kuk")) {//������
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("Űū��� �ҷ����� ��");
		debug = 104;
		goto special;
	}
	else if (!strcmp(console, "msj")) {//�μ���
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("������� ��� ����");
		debug = 105;
		goto special;
	}
	else if (!strcmp(console, "sdy")) {//�۴ٿ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("���� ����� ���α׷��� �׷��� ������ �����ع�����");
		debug = 106;
		goto special;
	}

	else if (!strcmp(console, "ljs")) {//���ؼ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("�ؼ����� ���α׷��� ����");
		debug = 110;
		goto special;
	}

	else if (!strcmp(console, "hsb")) {//ȫ�ֹ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("ȫ�ֹ� ����");
		debug = 116;
		goto special;
	}
	else if (!strcmp(console, "teacherlsw")) {//Ƽ�� ���¿�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("�¿��� ����");
		debug = 10000;
		goto special;
	}
	else if (!strcmp(console, "teacherlju")) {//Ƽ�� ������
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("�������� ����");
		debug = 10001;
		goto special;
	}
	else if (!strcmp(console, "teacherkyj")) {//Ƽ�� �迩��
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("�迩���� ����");
		debug = 10002;
		goto special;
	}
	else if (!strcmp(console, "teacherrjh")) {//Ƽ�� ����ȣ
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("����ȣ ������ ����");
		debug = 10003;
		goto special;
	}
	else if (!strcmp(console, "teacherjmk")) {//Ƽ�� ���¿�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("���̰� ������ ����");
		debug = 10004;
		goto special;
	}
	else if (!strcmp(console, "hardreset")) {//��ü �ʱ�ȭ
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("�����");
		debug = 0;
		goto hardreset;
	}
	else if (!strcmp(console, "shutdown")) {//���� �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("����");
		return 0;
	}
	else if (!strcmp(console, "done")) {//done���� �̵��ϴ� �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		goto done;
	}
	else if (!strcmp(console, "start")) {//������ ���۽�Ű�� �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		goto start;
	}
	else if (!strcmp(console, "softreset")) {//��� ���� ����â���� ���� �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		goto softreset;
	}
	else if (!strcmp(console, "poweroption")) {//����ɼ����� ���� �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		goto poweroption;
	}
	else if (!strcmp(console, "forcedcrash")) {//���� �������� �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		printf("�������� ����");
		errorcode = 999;
		goto error;
	}
	else if (!strcmp(console, "darkmode")) {//��ũ��� ��Ŭ �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		if (darkmode == 0)
			darkmode++;
		else
			darkmode--;
		if (darkmode == 1)
			system("color 0f");
		else
			system("color f0");
		goto poweroption;
	}
	else if (!strcmp(console, "error")) {//����â���� ���� �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		goto error;
	}
	else if (!strcmp(console, "stat")) {//������Ȳ üũ �ܼ� ��ɾ�
		if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
		if (launched == 0) {//��ó���� ������ ��� ���� �߻� ���������� ����������
			printf("������ �ҷ��ɴϴ�. �ٽ� ����� �Է��Ͻÿ�.\n");
			goto start;
		}
		printf("errorcode : %d\n", errorcode);
		printf("debug : %d\n", debug);
		printf("origin : %d\n", origin);
		printf("launched : %d\n", launched);
		printf("sel : %c\t%d\n", sel, sel);
		printf("console : %s\n", console);
		printf("darkmode : %d\n", darkmode);
		printf("keep : %d\n", keep);
		printf("a1 : %lld\n", a1);
		printf("b1 : %lld\n", b1);
		printf("c1 : %lld\n", c1);
		printf("a2 : %Lf\n", a2);
		printf("b2 : %Lf\n", b2);
		printf("c2 : %Lf\n", c2);
		printf("XYZ : %d\n", XYZ);

		system("pause");
		goto poweroption;
	}
	if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
	printf("Ʋ�Ƚ��ϴ�.\n");
	system("pause");
	if (debug != 1)	system("cls");//debug�� 1�϶� cls�Ǵ°� ���� �ڵ�
	debug = 0;
	goto poweroption;
manual:
	//updated in V1.3
	return 0;	
}