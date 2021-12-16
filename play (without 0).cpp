#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

static char buf2[100000010],*pp=buf2;
inline void pc(char ch) {
	if(pp-buf2==100000000) fwrite(buf2,1,100000000,stdout),pp=buf2;
	*pp++=ch;
}
inline void pcc() {
	fwrite(buf2,1,pp-buf2,stdout);
	pp=buf2;
}
void write(long long x) {
	static int sta[25];
	int top=0;
	do {
		sta[top++]=x%10,x/=10;
	} while(x);
	while(top) pc(sta[--top]+48);
//	pc('\n');
}

struct data {
	long long win[25],time[25],psb[25];
}old[55][55];
struct data2 {
	long long cpt[25],plr[25],time[25];
}nw[55][55];
int d[]={0,			-1,				-2,				-3,				-4,				-5,
					-6,				-7,				-8,				-10,			-15,
					0,				0,				0,				0,				0,			
					0,				-1,				-1,				-1,				1};
string chs[]={"摩擦 0",	"单刀 -1",		"双刀 -2",		"致命 -3",		"地波 -4",		"片波 -5",
					"派波 -6",		"气波 -7",		"青龙波 -8",	"金龙波 -10",	"世界末日 -15",
					"免单 0",		"小防 0",		"大防 0",		"反弹 0",		"吸 0",
					"拉 0",			"收 -1",		"青龙收 -1",	"金龙收 -1",	"结 +1"};
int cbl[21][21]={
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-2,-2,-2,-2,-2,-2,-2,-2,-2,
 0, 0,-1,-2,-2,-2,-2,-2,-2,-2,-2, 0, 0, 0,-2, 0, 0, 0, 0, 0, 0,
 0, 0, 0,-1,-2,-2,-2,-2,-2,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0,-1,-2,-2,-2,-2,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0,-1,-2,-2,-2,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0,-1,-2,-2,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0,-1,-2,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0,-1,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0,-1,-2,-2,-2,-2,-2,-2,-2,-2, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0,
 0, 0, 0,-2,-2,-2,-2,-2,-2,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2, 0, 0, 0,-2,-2,-2,-2,-2,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0,-2,-2,-2,-2,-2,-2,-2,-2,-2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0,-2,-2,-2,-2,-2, 0, 0, 0, 0, 0,-2, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2, 0, 0,-2,-2,-2,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2,-2,-2, 0, 0,-2,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2,-2,-2,-2, 0,-2,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int cpt[21][21]={
  0,  1,  2,  3,  4,  5,  6,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
 -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
 -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
 -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,
 -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
 -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,
 -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,
 -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,
-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  1,  2,  3,  4,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1};
int bly=2,blc=2,pty=2,ptc=2,yc,cc,aty,atc;
long long tt;
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
	system("mode con cols=83 lines=37");
	printf("规则如下：\n攻击型：\n");
	for(int i=1;i<=11;++i)
		printf("%d: [%s]\n",i,chs[i].c_str());
	printf("非攻击型：\n");
	for(int i=12;i<=20;++i)
		printf("%d: [%s]\n",i,chs[i].c_str());
//	printf("特殊型：\n");
//	printf("0: [%s]\n",chs[0].c_str());
	printf("攻击型同样点数抵消，点数差1扣0.5血量，点数差大于1扣除全部血量（此时免单相当于单刀）\n");
	printf("使用除免单外攻击如果对方没防住直接死亡，使用免单则扣除0.5血量\n");
	printf("免单一局只能使用一次\n");
	printf("小防：防住点数不大于2的攻击\n");
	printf("大防：防住点数为3-5的攻击\n");
	printf("反弹：反弹点数不大于1的攻击\n");
	printf("收：防住点数为6-7的攻击\n");
	printf("青龙收：防住点数为8的青龙波\n");
	printf("金龙收：防住点数为10的金龙波\n");
	printf("吸：如果对方使用点数不大于5的攻击，则获得对方使用此攻击所需的点数\n");
	printf("拉：不能防住任何攻击，但对方如果使用吸则对方直接死亡\n");
	printf("结：获得1点\n");
//	printf("摩擦：当对方使用点数不大于7的攻击时可以获得对方使用此攻击所需的点数\n");
//	printf("      当对方使用点数大于7的攻击时可以防住对方的攻击\n");
//	printf("      当对方不使用攻击时则使用者直接死亡\n");
	system("pause");
}
void show() {
	HideCurSor();
	system("cls");
	SetPos(0,0);
	printf("你的血量：%.1f",1.0*bly/2);
	SetPos(0,14);
	printf("电脑血量：%.1f",1.0*blc/2);
	SetPos(1,0);
	printf("你的点数：%d",pty);
	SetPos(1,14);
	printf("电脑点数：%d",ptc);
	SetPos(2,0);
	printf("请你选择：");
	SetPos(3,0);
	for(int i=1;i<=20;++i) {
		avy[i]=false;
		if(pty>=-d[i]&&(i!=11||!mdy)) {
			printf("%d: [%s]\n",i,chs[i].c_str());
			avy[i]=true;
		}
	}
}
void gcc() {
	now=0;
	memset(chc,0,sizeof(chc));
	for(int i=0;i<=20;++i) {
		if(i==0)
			if(pty>=6) chc[++now]=i;
		if(i>0&&i<=10)
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
	if(pty>50||ptc>50) {
		cc=chc[rand()%now+1];
		return;
	}
	int now2=0;
	int t[25];
	for(int i=1;i<=now;++i)
		t[chc[i]]=old[ptc][pty].psb[chc[i]];
	for(int i=1;i<=now;++i)
		if(t[chc[i]]==0)
			t[chc[i]]+=25;
	for(int i=1;i<=now;++i)
		for(int j=1;j<=t[chc[i]];++j)
			chc2[++now2]=chc[i];
	cc=chc2[rand()%now2+1];
}
void getdata() {
	long long a,b,c,d;
	freopen("data","r",stdin);
	cin>>tt;
	while(cin>>a>>b) {
		for(int i=0;i<=20;++i) {
			cin>>c>>d;
			if(a<=50&&b<=50) {
				old[a][b].win[i]=c,old[a][b].time[i]=d;
				if(d!=0) old[a][b].psb[i]=100*c/d;
			}
		}
	}
}
void upd() {
	if(yc==11) mdy=1;
	if(cc==11) mdc=1;
	if(ptc<=50&&pty<=50) {
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
	printf("加载中……\n");
	getdata();
	printf("加载完毕\n");
	Sleep(500);
	freopen("CON", "r", stdin);
	while(1) {
		HideCurSor();
		system("mode con cols=32 lines=30");
		show();
		gcc();
		if(zbms)
			printf("电脑选择了 [%s]\n输入114514关闭作弊模式\n",chs[cc].c_str());
		else printf("输入114514开启作弊模式\n");
		while(1) {
			scanf("%d",&yc);
			if(yc==114514) break;
			if(yc>20||yc<0) {
				printf("无效，请重选\n");
			}
			else if(!avy[yc]) {
				printf("你无法使用[%s]，请重选\n",chs[yc].c_str());
			}
			else break;
		}
		if(yc==114514) {
			if(!zbms) printf("作弊模式已开启\n");
			else printf("作弊模式已关闭\n");
			zb=true;
			zbms^=1;
			system("pause");
			continue;
		}
		printf("你选择了 [%s]\n",chs[yc].c_str());
		if(!zbms)
			printf("电脑选择了 [%s]\n",chs[cc].c_str());
		upd();
		if(bly<=0||blc<=0) break;
		system("pause");
	}
	if(blc<=0) {
		printf("你赢了\n");
		system("pause");
		if(!zb) {
			freopen("data","w",stdout);
			write(++tt);pc('\n');
			for(int i=0;i<=50;++i) {
					for(int j=0;j<=50;++j) {
					write(i);pc(' ');write(j);pc('\n');
					for(int k=0;k<=20;++k) {
						write(old[i][j].win[k]+nw[i][j].plr[k]);pc(' ');write(old[i][j].time[k]+nw[i][j].time[k]);pc(' ');
					}
					pc('\n');
				}
			}
			pcc();
		}
	}
	else {
		printf("你输了\n");
		system("pause");
		if(!zb) {
			freopen("data","w",stdout);
			write(++tt);pc('\n');
			for(int i=0;i<=50;++i) {
				for(int j=0;j<=50;++j) {
					write(i);pc(' ');write(j);pc('\n');
					for(int k=0;k<=20;++k) {
						write(old[i][j].win[k]+nw[i][j].cpt[k]);pc(' ');write(old[i][j].time[k]+nw[i][j].time[k]);pc(' ');
					}
					pc('\n');
				}
			}
			pcc();
		}
	}
}
int main() {
	run();
	return 0;
}
