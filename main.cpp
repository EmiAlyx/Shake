
#include"shake.h"
//��ʼ��
snake s1;
food d1(s1.b1,s1.length);
int score = 0,kx=0,ky=0;
int lastx = 0,lasty = 0;
int sleepseond = 200;
char key = 'd';
void wall() {
	for (int i = 0; i <= HIG; i++) {
		for (int j = 0; j <= WID; j++) {
			if (j == WID ) {
				printf("|");
			}
			else if (i == HIG) {
				printf("_");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
void initUI() {
	COORD coord;
	for (size_t i = 0; i < s1.length; i++) {
		coord.X = s1.b1[i].x;
		coord.Y = s1.b1[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i == 0) {
			putchar('&');
		}
		else {
			putchar('*');
		}
	}
	//ȥ����β
	coord.X = lastx;
	coord.Y = lasty;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
	//��ʾʳ��
	coord.X = d1.x;
	coord.Y = d1.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('G');
	coord.X = 0;
	coord.Y = HIG+2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('\n');
}

void playgame() {
	while (1) {
	if (s1.ifclash()) {
		return;
	}

	initUI();
	if (_kbhit()) {
		key = _getch();
	}
	switch (key) {
	case'w': 
		kx = 0;
		ky = -1;
		break;
	case's':
		kx = 0;
		ky = 1;
		break;
	case'a':
		kx = -1;
		ky = 0;
		break;
	case'd':
		kx = 1;
		ky = 0;
		break;
	case'W':
		kx = 0;
		ky = -1;
		break;
	case'S':
		kx = 0;
		ky = 1;
		break;
	case'A':
		kx = -1;
		ky = 0;
		break;
	case'D':
		kx = 1;
		ky = 0;
		break;
	default:
		break;
	}
	//���ƶ�
	lastx = s1.b1[s1.length - 1].x;
	lasty = s1.b1[s1.length - 1].y;
	for (size_t i = s1.length - 1; i > 0; i--) {
		s1.b1[i].x = s1.b1[i - 1].x;
		s1.b1[i].y = s1.b1[i - 1].y;
	}
	s1.b1[0].x += kx;
	s1.b1[0].y += ky;
	if (s1.b1[0].x == d1.x && s1.b1[0].y == d1.y) {
		s1.get_long();
		d1.reset(s1.b1,s1.length);
		score+=5;
		if (sleepseond > 50) {//����
			sleepseond -= 10;
		}
	}
	Sleep(sleepseond);
}
}
struct goalsit {
	string name;
	int s=0;
};
class goalsits {
public:
	goalsit* m_goal;
	int num;
	goalsits(int num) {
		this->m_goal = new goalsit[num];
		this->num = num;
	}
	goalsits() {
		num = 0;
	}
	void swap(goalsit &a, goalsit& b) {
		string t_name;
		int t_s;
		t_name = a.name;
		t_s = a.s;
		a.name = b.name;
		a.s = b.s;
		b.name = t_name;
		b.s = t_s;
	}
	void paix() {
		int max=0;
		for (int i = 0; i < num-1;i++) {
			max = i;
			for (int j = i + 1; j < num; j++) {
				if (m_goal[max].s<m_goal[j].s) {
					max = j;
				}
			}
			if (max != i) {
				swap(m_goal[i], m_goal[max]);
			}
		}
	}
};
void readit() {
	ifstream ifs;
	ifs.open(GOALS,ios::in);
	char name[20];
	int goals;
	int num = 0;
	while (ifs >> name && ifs >> goals) {
		num++;
	}
	ifs.close();
	goalsits go(num);
	int i = 0;
	ifs.open(GOALS,ios::in);
	while (ifs >> name && ifs >> goals) {
		go.m_goal[i].name = name;
		go.m_goal[i].s =goals;
		i++;
	}
	ifs.close();
	
	go.paix();
	
	ofstream ofs;
	ofs.open(GOALS, ios::out);
	for (int i = 0; i < num; i++) {
		ofs << go.m_goal[i].name << " " << go.m_goal[i].s<< endl;
		
	}
	ofs.close();
	cout << "���а�Ϊ��" << endl;
	for (int i = 0; i < num; i++) {
		cout<<"��"<<i+1 << "�� �浵����" << go.m_goal[i].name << "  �÷֣� " << go.m_goal[i].s << endl;
	}
}
void reset() {
	s1.reset();
	d1.reset(s1.b1, s1.length);
	sleepseond = 200;
	score = 0;
	key = 'd';
}
int main() {
	//���ع��
	while (1) {
		cout << "z.��ʼ��Ϸ x.�鿴��Ϸ���� p.�˳���Ϸ" << endl;
		string stayname;
		char c='a';
		cin >> c;
		system("cls");
		ofstream ofs;
		switch (c) {
		case 'z':
			cout << "����浵��: ";
			cin >> stayname;
			system("cls");
			CONSOLE_CURSOR_INFO CC;
			CC.dwSize = sizeof(CC);
			CC.bVisible = FALSE;//
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CC);
			srand(time(NULL));//���������
			reset();
			wall();
			initUI();
			playgame();
			cout << "game over" << endl;
			cout << "��ķ���Ϊ��" << score << endl;
			ofs.open(GOALS,ios::app);
			ofs << stayname << " " << score << endl;
			ofs.close();
			system("pause");
			break;
		case'x':
			readit();
			
			break;
		case'p':
			return 0;
		}
		
	}
}