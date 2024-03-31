#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <string.h>


int main() {

	int errorcode = 0; //에러코드
	int debug = 0;//디버그
	int origin=debug;//원래의 디버그값
	int launched = 0; //실행상태
	char sel = '0';//선택기
	char console[100];
	int darkmode = 1;//다크모드on/off
	
hardreset://전체초기화
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
	}//debug가 지정된 값 이외로 들어오는걸 막아줌
	if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
	printf("CAL");
	printf("\nCGO studio present\n");
	if (debug != 0) {
		printf("\n디버그 켜짐\n");
		printf("\nA. 디버그모드로 시작, B. 디버그모드 끄고 시작, Z. 종료옵션\n");
		scanf_s("%c", &sel);
		getchar();
		switch (sel) {
		case 'a':
		case 'A':
		case '1':
			if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
			goto start;
			break;
		case 'b':
		case 'B':
		case '2':
			debug = 0;
			if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
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
		printf("\n\nA. 시작, Z.종료옵션\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
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

start: //계산기 실행
	system("title CAL");
	if (debug == 1)
		system("title CAL with debug");
	int keep = 0;//이어계산하기가 살아있나?
	long long a1 = 0;//정수a
	long long b1 = 0;//정수b
	long long c1 = 0;//정수c
	long double a2 = 0;//실수a
	long double b2 = 0;//실수b
	long double c2 = 0;//실수c
	int XYZ = 0;	//정수/실수
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

softreset://다른계산
	printf("A. 일반계산, B. 비트연산, C. 비트시프트연산, D. 홀짝연산, Z. 종료옵션\n");
	scanf_s("%c", &sel);
	getchar();
	if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

	switch (sel) {
	case 'a'://일반계산
	case 'A':
	case '1':
		{printf("A. 정수계산, B. 실수계산, Z. 종료옵션\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		switch (sel) {

		case 'a'://정수계산
		case 'A':
		case '1':
		{XYZ = 0;
		if (keep == 0) {//이어계산하기가 아닌경우에만 실행함
			printf("(X) x X = ?");
			printf("\n첫번째 수는 :");
			scanf_s("%lld", &a1);
			getchar();
			if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		}

		printf("%lld x (X) = ?", a1);
		printf("\n두번째 수는 :");
		scanf_s("%lld", &b1);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

		printf("%lld (x) %lld = ?", a1, b1);
		printf("\n+, -, *, /, %%, ^\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
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

		case 'b'://실수계산
		case 'B':
		case '2':
		{
			XYZ = 1;
			if (keep == 0) {//이어계산하기가 아닌경우에만 실행함
				printf("(X) x X = ?");
				printf("\n첫번째 수는 :");
				scanf_s("%Lf", &a2);
				getchar();
				if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
			}

			printf("%Lf x (X) = ?", a2);
			printf("\n두번째 수는 :");
			scanf_s("%Lf", &b2);
			getchar();
			if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

			printf("%Lf (x) %Lf / ?", a2, b2);
			printf("\n+, -, *, /, %%, ^\n");
			scanf_s("%c", &sel);
			getchar();
			if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
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
		case 'z'://종료옵션
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
	case 'b'://비트연산
	case 'B':
	case '2':
		{XYZ = 0;
		printf("(X) x X = ?");
		printf("\n첫번째 수는 :");
		scanf_s("%lld", &a1);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

		printf("%lld x (X) = ?", a1);
		printf("\n두번째 수는 :");
		scanf_s("%lld", &b1);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

		printf("%lld (x) %lld = ?", a1, b1);
		printf("\n&, |, ^, ~\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

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
	case 'c'://비트시프트연산
	case 'C':
	case '3':
	{
		XYZ = 0;
		printf("(X) x X = ?");
		printf("\n첫번째 수는 :");
		scanf_s("%lld", &a1);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

		printf("%lld x (X) = ?", a1);
		printf("\n두번째 수는 :");
		scanf_s("%lld", &b1);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

		printf("%lld (x) %lld = ?", a1, b1);
		printf("\n<, >\n");
		scanf_s("%c", &sel);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

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
	case 'd'://홀짝연산
	case 'D':
	case '4':
	{
		XYZ = 0;

		printf("(X) %% 2 = ?");
		printf("\n수를 입력하시오 :");
		scanf_s("%lld", &a1);
		getchar();
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드

		printf("%lld %% 2 = %lld", a1, a1 % 2);
		if (a1 % 2 == 0)
			printf("\n결과: 짝수\n");
		else
			printf("\n결과: 홀수\n");
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
	
done://계산후
	printf("A. 다른계산하기, B. 이어계산하기, Z. 종료옵션\n");
	scanf_s("%c", &sel);
	getchar();
	if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
	switch (sel) {
	case 'a':
	case 'A':
	case '1':
		keep = 0;//이어계산 끄기
		goto softreset;
		break;
	case 'b':
	case 'B':
	case '2':
		keep = 1;//이어계산 키기
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

poweroption://전원옵션
	system("title poweroption");
	if (debug == 1)
		system("title poweroption with debug");
	if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
	printf("A. 종료, B. 재시작, C. 크레딧, D. 다크모드 토글");
	if (debug == 1)
		printf(", E. 변수상황, F. 디버그모드로 재시작\n");
	else
		printf("\n");
	scanf_s("%c", &sel);
	getchar();
	if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
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
		printf("제작자: 최지오\n계발: CGO studio\n개발일: 2022/07/12\n버젼: 1.2\n");
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
	

error://에러리스트
	if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
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
	printf("가 발생하였습니다.\n");
	system("pause");
	if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
	printf("비상 운전\n");
	printf("A. 재시작, B. 종료, C. 변수상태");
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
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
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
	if (debug == 110) {//이준성 이스터에그
		printf("\n준성이는 바보다\n");
		printf("준성이는 프로그래밍을 (못)한다\n");
		printf("나는 프밍을 오늘 점수가 상향되어 80대가 되었다\nㅋㅋㄹㅃㅃ\n");
	}
	else if (debug == 116) {//홍승범 이스터에그
		printf("\n홍쌍범\n그의 생일은 7월12일\n그날은 그가 맞아죽은날\n");
	}
	
	else if (debug == 101) {//강예준 이스터에그
		printf("\n예준강\nCDPR그 자체\n지속되는 계발연기\n언제쯤 내 OCTA를 납품받을련가\n");
	}
	else if (debug == 102) {//김낙현 이스터에그
		printf("\n1등으로 추정되는 사내\n그는 자신이 1등이 아니라 주장한다네\n그는 자기를 1등이라 부르는걸 싫어한다네\n아지르 달인이라 주장하지만 현실적 글쌔\n");
	}
	else if (debug == 103) {
		printf("\n김서연\n우리집 외가쪽 사촌형 이름과 같아서 이름 외우기 쉬움\n테트리스를 '정말' '잘함'\nㅋㅋㅋㅋㅋ\n");
	}
	else if (debug == 104) {//김유강
		printf("\n김유강\n키는 진짜 큼\n수학 잘함\n공부 잘함(어느정도는)\n");
	}
	else if (debug == 105) {//민성준
		printf("\n민성준\n성준이는 서구에 산다\n장염걸려서 아프단다\n디스코드 하고있더라\n");
	}
	else if (debug == 106) {//송다연
		printf("\n송다연\n자그마치 프로그래밍을 40점대를 맞으셨다\n와 개고수 납셨다\n과연 그녀의 2학기 중간고사 점수는?\n");
	}
	else if (debug == 10000) {//승원이 이스터에그
		printf("\n승원이\n우리 단기임대 선생\n디논을 가르침\n졸림\n계속 필터를 달라함\n");
	}
	else if (debug == 10001) {//음악쌤
		printf("\n이정은\n음악쌤이시다\n알토파다\n피아노 치기를 귀찮아서 외주를 맡긴다.\n");
	}
	else if (debug == 10002) {//여진쌤
		printf("\n영어B를 가르치시는 김여진 선생님\n선생님들중 가장 트렌드 하신 분\n조말론 향수는 너무 비싸서 법에 걸려서 못드려요\n");
	}
	else if (debug == 10003) {//유지호쌤
		printf("\n유지호 선생님은 전기를 가르친다\n너무 어렵다\n문제가 생겼어!\n전기는 우리반 1등이니까 괜찮나?\n");
	}
	else if (debug == 10004) {
		printf("\n정미경 선생님\n전자 너무 어려워요\n이러면 보통 시험 난이도가 내려가던데\nㅋㅋㅋㅋㅋㅋ\n");
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
	if (!strcmp(console, "debugon")||!strcmp(console, "debug1") ){//디버그 키는 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		debug = 1;
		origin = debug;
		printf("디버그 실행");
		printf("\n");
		system("pause");
		goto hardreset;
	}
	else if (!strcmp(console, "debugoff") || !strcmp(console, "debug0") ){//디버그 끄는 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		debug=0;
		origin=debug;
		printf("디버그 종료");
		printf("\n");
		system("pause");
		goto hardreset;
	}
	
	else if (!strcmp(console, "cdpr")|| !strcmp(console, "kyj")) {//CDPR개발속도보유자
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("개발 속도가 거의 뭐 CDPR인 사람 실행");
		debug = 101;
		goto special;
	}
	else if (!strcmp(console, "1st") || !strcmp(console, "knh")) {//1등
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("1등으로 추정되는 사람 실행");
		debug = 102;
		goto special;
	}
	else if (!strcmp(console, "ksy")) {//김서연
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("자칭 테트시르 고수 실행");
		debug = 103;
		goto special;
	}
	else if (!strcmp(console, "kuk")) {//김유강
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("키큰사람 불러오는 중");
		debug = 104;
		goto special;
	}
	else if (!strcmp(console, "msj")) {//민성준
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("서구사는 사람 실행");
		debug = 105;
		goto special;
	}
	else if (!strcmp(console, "sdy")) {//송다연
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("정말 대단한 프로그래밍 그랜드 마스터 실행해버리기");
		debug = 106;
		goto special;
	}

	else if (!strcmp(console, "ljs")) {//리준성
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("준성이의 프로그래밍 실행");
		debug = 110;
		goto special;
	}

	else if (!strcmp(console, "hsb")) {//홍쌍범
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("홍쌍범 실행");
		debug = 116;
		goto special;
	}
	else if (!strcmp(console, "teacherlsw")) {//티쳐 리승원
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("승원이 실행");
		debug = 10000;
		goto special;
	}
	else if (!strcmp(console, "teacherlju")) {//티쳐 김은정
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("이정은쌤 실행");
		debug = 10001;
		goto special;
	}
	else if (!strcmp(console, "teacherkyj")) {//티쳐 김여진
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("김여진쌤 실행");
		debug = 10002;
		goto special;
	}
	else if (!strcmp(console, "teacherrjh")) {//티쳐 유지호
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("유지호 선생님 실행");
		debug = 10003;
		goto special;
	}
	else if (!strcmp(console, "teacherjmk")) {//티쳐 리승원
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("정미경 선생님 실행");
		debug = 10004;
		goto special;
	}
	else if (!strcmp(console, "hardreset")) {//전체 초기화
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("재실행");
		debug = 0;
		goto hardreset;
	}
	else if (!strcmp(console, "shutdown")) {//종료 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("종료");
		return 0;
	}
	else if (!strcmp(console, "done")) {//done으로 이동하는 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		goto done;
	}
	else if (!strcmp(console, "start")) {//변수를 시작시키는 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		goto start;
	}
	else if (!strcmp(console, "softreset")) {//계산 종류 실행창으로 가는 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		goto softreset;
	}
	else if (!strcmp(console, "poweroption")) {//종료옵션으로 가는 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		goto poweroption;
	}
	else if (!strcmp(console, "forcedcrash")) {//강제 오류내는 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		printf("강제에러 실행");
		errorcode = 999;
		goto error;
	}
	else if (!strcmp(console, "darkmode")) {//다크모드 토클 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
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
	else if (!strcmp(console, "error")) {//에러창으로 가는 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		goto error;
	}
	else if (!strcmp(console, "stat")) {//변수상황 체크 콘솔 명령어
		if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
		if (launched == 0) {//런처에서 실행할 경우 오류 발생 가능함으로 지나가야함
			printf("변수를 불러옵니다. 다시 명령을 입력하시오.\n");
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
	if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
	printf("틀렸습니다.\n");
	system("pause");
	if (debug != 1)	system("cls");//debug가 1일때 cls되는걸 막는 코드
	debug = 0;
	goto poweroption;
manual:
	//updated in V1.3
	return 0;	
}