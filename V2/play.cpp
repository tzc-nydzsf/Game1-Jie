#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct data {
	long long win[25],time[25],psb[25];
}old[35][35];
struct data2 {
	long long cpt[25],plr[25],time[25];
}nw[35][35];
int d[]={0,			-1,			-2,			-3,			-4,			-5,
					-6,			-7,			-8,			-10,		-0x3f3f3f3f,
					0,			0,			0,			0,			0,			
					0,			-1,			-1,			-1,			1};
string chs[]={"",	"���� -1","˫�� -2","���� -3","�ز� -4","Ƭ�� -5",
					"�ɲ� -6","���� -7","������ -8","������ -10","����ĩ�� -15",
					"�ⵥ 0","С�� 0","��� 0","���� 0","�� 0",
					"�� 0","�� -1","������ -1","������ -1","�� +1"};
int cbl[21][21]={
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0,-1,-2,-3,-4,-5,-6,-7,-8, 0, 0, 0, 0,-2, 0, 0, 0, 0, 0, 0,
 0, 0, 0,-1,-2,-3,-4,-5,-6,-7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0,-1,-2,-3,-4,-5,-6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0,-1,-2,-3,-4,-5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0,-1,-2,-3,-4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0,-1,-2,-3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0,-1,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0,-1,-2,-3,-4,-5,-6,-7,-8, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0,
 0, 0, 0,-2,-2,-2,-2,-2,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2, 0, 0, 0,-2,-2,-2,-2, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0,-2,-2,-2,-2,-2,-2,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0,-2,-2,-2,-2, 0, 0, 0, 0, 0, 0,-2, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2,-2,-2,-2,-2, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2, 0, 0,-2,-2, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2,-2,-2, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2,-2,-2,-2, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2,-2,-2,-2,-2, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int cpt[21][21]={
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  0, -2, -2, -2, -2, -2, -2, -2, -2, -2,  0, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
  0, -3, -3, -3, -3, -3, -3, -3, -3, -3,  0, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
  0, -4, -4, -4, -4, -4, -4, -4, -4, -4,  0, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,
  0, -5, -5, -5, -5, -5, -5, -5, -5, -5,  0, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
  0, -6, -6, -6, -6, -6, -6, -6, -6, -6,  0, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,
  0, -7, -7, -7, -7, -7, -7, -7, -7, -7,  0, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,
  0, -8, -8, -8, -8, -8, -8, -8, -8, -8,  0, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
  0,-10,-10,-10,-10,-10,-10,-10,-10,-10,  0,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  1,  2,  3,  4,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  0, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  0, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1};
int bly=2,blc=2,pty=2,ptc=2,yc,cc,aty,atc;
bool mdy,mdc,avy[25],avc[25],zbms,zb;
int now,chc[25],chc2[32768];
void SetPos(int i,int j) {
	COORD pos={j,i};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out, pos);
}
void HideCurSor(void) {
	CONSOLE_CURSOR_INFO info={1,0};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(Out,&info);
}
void rule() {
	HideCurSor();
	system("mode con cols=83 lines=35");
	printf("�������£�\n�����ͣ�\n");
	for(int i=1;i<=11;++i)
		if(i!=10) printf("%d: [%s]\n",i,chs[i].c_str(),d[i]);
	printf("�ǹ����ͣ�\n");
	for(int i=12;i<=20;++i)
		printf("%d: [%s]\n",i,chs[i].c_str(),d[i]);
	printf("������ͬ������������������1��0.5Ѫ�������������1�۳�ȫ��Ѫ������ʱ�ⵥ�൱�ڵ�����\n");
	printf("ʹ�ó��ⵥ�⹥������Է�û��סֱ��������ʹ���ⵥ��۳�0.5Ѫ��\n");
	printf("�ⵥһ��ֻ��ʹ��һ��\n");
	printf("С������ס����������2�Ĺ���\n");
	printf("�������ס����Ϊ3-5�Ĺ���\n");
	printf("��������������������1�Ĺ���\n");
	printf("�գ���ס����Ϊ6-7�Ĺ���\n");
	printf("�����գ���ס����Ϊ8��������\n");
	printf("�����գ���ס����Ϊ10�Ľ�����\n");
	printf("��������Է�ʹ�õ���������5�Ĺ��������öԷ�ʹ�ôι�������ĵ���\n");
	printf("�������ܷ�ס�κι��������Է����ʹ������Է�ֱ������\n");
	printf("�᣺���1��\n");
	system("pause");
}
void show() {
	HideCurSor();
	system("cls");
	SetPos(0,0);
	printf("���Ѫ����%.1f",1.0*bly/2);
	SetPos(0,14);
	printf("����Ѫ����%.1f",1.0*blc/2);
	SetPos(1,0);
	printf("��ĵ�����%d",pty);
	SetPos(1,14);
	printf("���Ե�����%d",ptc);
	SetPos(2,0);
	printf("����ѡ��");
	SetPos(3,0);
	for(int i=1;i<=20;++i) {
		avy[i]=false;
		if(pty>=-d[i]&&i!=10&&(i!=11||!mdy)) {
			printf("%d: [%s]\n",i,chs[i].c_str(),d[i]);
			avy[i]=true;
		}
	}
}
void gcc() {
	if(ptc>=6*(pty+1)) {
		cc=6;
		return;
	}
	now=0;
	memset(chc,0,sizeof(chc));
	for(int i=1;i<=20;++i) {
		if(i<=9)
			if(ptc>=-d[i]&&(i-pty<=2||(i!=4&&i!=5&&i!=7))) chc[++now]=i;
		if(i==11)
			if(!mdc) chc[++now]=i;
		if(i==12)
			if(pty>1) chc[++now]=i;
		if(i==13)
			if(pty>=3) chc[++now]=i;
		if(i==14)
			if(pty>0||!mdy) chc[++now]=i;
		if(i==15)
			if(pty>1) chc[++now]=i;
		if(i==16)
			if(ptc>1) chc[++now]=i;
		if(i==17)
			if(pty>=6&&ptc>0) chc[++now]=i;
		if(i==18)
			if(pty>=8&&ptc>0) chc[++now]=i;
		if(i==19)
			if(pty>=10&&ptc>0) chc[++now]=i;
		if(i==20)
			chc[++now]=i;
	}
	if(pty>30||ptc>30) {
		cc=chc[rand()%now+1];
		return;
	}
	int now2=0;
	int t[25];
	for(int i=1;i<=20;++i)
		t[i]=old[ptc][pty].psb[i];
	for(int i=1;i<=now;++i)
		if(old[ptc][pty].psb[chc[i]]==0)
			t[chc[i]]+=10;
	memset(chc2,0,sizeof(chc2));
	for(int i=1;i<=now;++i)
		for(int j=1;j<=t[chc[i]];++j)
			chc2[++now2]=chc[i];
	cc=chc2[rand()%now2+1];
}
void getdata() {
	long long a,b,c,d;
	freopen("data","r",stdin);
	while(cin>>a>>b) {
		for(int i=1;i<=20;++i) {
			cin>>c>>d;
			if(a<=30&&b<=30) {
				old[a][b].win[i]=c,old[a][b].time[i]=d;
				if(d!=0) old[a][b].psb[i]=100*c/d;
			}
		}
	}
}
void upd() {
	if(yc==11) mdy=1;
	if(cc==11) mdc=1;
	if(ptc<=30&&pty<=30) {
		++nw[ptc][pty].cpt[cc];
		++nw[pty][ptc].plr[yc];
		++nw[ptc][pty].time[cc];
		++nw[pty][ptc].time[yc];
	}
	bly+=cbl[yc][cc];
	blc+=cbl[cc][yc];
	pty+=cpt[yc][cc];
	ptc+=cpt[cc][yc];
}
void run() {
	HideCurSor();
	srand(time(0));
	rule();
	system("cls");
	printf("�����С���\n");
	getdata();
	printf("�������\n");
	Sleep(500);
	freopen("CON", "r", stdin);
	while(1) {
		HideCurSor();
		system("mode con cols=30 lines=30");
		show();
		gcc();
		if(zbms)
			printf("����ѡ���� [%s]\n����114514�ر�����ģʽ\n",chs[cc].c_str());
		else printf("����114514��������ģʽ\n");
		while(1) {
			scanf("%d",&yc);
			if(yc==114514) break;
			if(yc>20||yc<=0||yc==10) {
				printf("��Ч������ѡ\n");
			}
			else if(!avy[yc]) {
				printf("���޷�ʹ��[%s]������ѡ\n",chs[yc].c_str());
			}
			else break;
		}
		if(yc==114514) {
			if(!zbms) printf("����ģʽ�ѿ���\n");
			else printf("����ģʽ�ѹر�\n");
			zb=true;
			zbms^=1;
			system("pause");
			continue;
		}
		if(!avy[yc]) {
			printf("���Ա��ˣ�\n������\n");
			system("pause\n");
			return;
		}
		printf("��ѡ���� [%s]\n",chs[yc].c_str());
		if(!zbms)
			printf("����ѡ���� [%s]\n",chs[cc].c_str());
		upd();
		if(bly<=0||blc<=0) break;
		system("pause");
	}
	if(blc<=0) {
		printf("��Ӯ��\n");
		system("pause");
		if(!zb) {
			freopen("data","w",stdout);
			for(int i=0;i<=30;++i) {
					for(int j=0;j<=30;++j) {
					printf("%lld %lld\n",i,j);
					for(int k=1;k<=20;++k) {
						printf("%lld %lld ",old[i][j].win[k]+nw[i][j].plr[k],old[i][j].time[k]+nw[i][j].time[k]);
					}
					printf("\n");
				}
			}
		}
	}
	else {
		printf("������\n");
		system("pause");
		if(!zb) {
			freopen("data","w",stdout);
			for(int i=0;i<=30;++i) {
				for(int j=0;j<=30;++j) {
					printf("%lld %lld\n",i,j);
					for(int k=1;k<=20;++k) {
						printf("%lld %lld ",old[i][j].win[k]+nw[i][j].cpt[k],old[i][j].time[k]+nw[i][j].time[k]);
					}
					printf("\n");
				}
			}
		}
	}
}
int main() {
	run();
	return 0;
}
