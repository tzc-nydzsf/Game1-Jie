#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int d[]={0,			-1,			-2,			-3,			-4,			-5,
					-6,			-7,			-8,			-10,		-15,
					0,			0,			0,			0,			0,			
					0,			-1,			-1,			-1,			1};
string chs[]={"",	"单刀 -1","双刀 -2","致命 -3","地波 -4","片波 -5",
					"派波 -6","气波 -7","青龙波 -8","金龙波 -10","世界末日 -15",
					"免单 0","小防 0","大防 0","反弹 0","吸 0",
					"拉 0","收 -1","青龙收 -1","金龙收 -1","结 +1"};
int bly=2,blc=2,pty=2,ptc=2,yc,cc,aty,atc;
bool mdy,mdc,avy[25],avc[25];
int now,chc[25];
void SetPos(int i,int j) {
	COORD pos={j,i};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out, pos);
}
void rule() {
	system("mode con cols=83 lines=35");
	printf("规则如下：\n攻击型：\n");
	for(int i=1;i<=11;++i)
		if(i!=10) printf("%d: [%s]\n",i,chs[i].c_str(),d[i]);
	printf("非攻击型：\n");
	for(int i=12;i<=20;++i)
		printf("%d: [%s]\n",i,chs[i].c_str(),d[i]);
	printf("攻击型同样点数抵消，点数差1扣0.5血量，点数差大于1扣除全部血量（此时免单相当于单刀）\n");
	printf("使用除免单外攻击如果对方没防住直接死亡，使用免单则扣除0.5血量\n");
	printf("免单一局只能使用一次\n");
	printf("小防：防住点数不大于2的攻击\n");
	printf("大防：防住点数为3-5的攻击\n");
	printf("反弹：反弹点数不大于1的攻击\n");
	printf("收：防住点数为6-7的攻击\n");
	printf("青龙收：防住点数为8的青龙波\n");
	printf("金龙收：防住点数为10的金龙波\n");
	printf("吸：如果对方使用点数不大于5的攻击，则获得对方使用次攻击所需的点数\n");
	printf("拉：不能防住任何攻击，但对方如果使用吸则对方直接死亡\n");
	printf("结：获得1点\n");
}
void show() {
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
		if(pty>=-d[i]&&i!=10&&(i!=11||!mdy)) {
			printf("%d: [%s]\n",i,chs[i].c_str(),d[i]);
			avy[i]=true;
		}
	}
}
void gcc() {
	now=0;
	memset(chc,0,sizeof(chc));
	for(int i=1;i<=20;++i) {
		if(i<=9)
			if(ptc>=-d[i]) chc[++now]=i;
		if(i==11)
			if(!mdc) chc[++now]=i;
		if(i==12)
			if(pty>1||!mdy) chc[++now]=i;
		if(i==13)
			if(pty>=3) chc[++now]=i;
		if(i==14)
			if(pty>0||!mdy) chc[++now]=i;
		if(i==15)
			if(pty>0) chc[++now]=i;
		if(i==16)
			if(ptc>0) chc[++now]=i;
		if(i==17)
			if(pty>=6&&ptc>0) chc[++now]=i;
		if(i==18)
			if(pty>=8&&ptc>0) chc[++now]=i;
		if(i==19)
			if(pty>=10&&ptc>0) chc[++now]=i;
		if(i==20)
			chc[++now]=i;
	}
	cc=chc[rand()%now+1];
}
void upd() {
	pty+=d[yc];ptc+=d[cc];
	if(yc==11) mdy=1;
	if(cc==11) mdc=1;
	if(yc<=11) aty=yc%10+(yc%10)/9;
	if(cc<=11) atc=cc%10+(yc%10)/9;
	if(yc==9) aty=10;
	if(cc==9) atc=10;
	if(yc<=11&&cc<=11) {
		if(aty>atc) blc-=aty-atc;
		else bly-=atc-aty;
		return;
	}
	if(yc>11&&cc>11) {
		if(yc==15&&cc==16) bly=0;
		if(yc==16&&cc==15) blc=0;
		return;
	}
	if(yc==12)
		if(cc>2&&cc<11) bly=0;
	if(cc==12)
		if(yc>2&&yc<11) blc=0;
	if(yc==13)
		if(cc<=2||cc>5&&cc<11) bly=0;
		else if(cc==11) bly-=1;
	if(cc==13)
		if(yc<=2||yc>5&&yc<11) blc=0;
		else if(yc==11) blc-=1;
	if(yc==14)
		if(cc>1&&cc<11) bly=0;
		else if(cc==1) blc=0;
		else if(cc==11) blc-=1;
	if(cc==14)
		if(yc>1&&yc<11) blc=0;
		else if(yc==1) bly=0;
		else if(yc==11) bly-=1;
	if(yc==15)
		if(cc>5&&cc<11) bly=0;
		else pty-=d[cc];
	if(cc==15)
		if(yc>5&&yc<11) blc=0;
		else ptc-=d[yc];
	if(yc==16||yc==20)
		if(cc==11) bly-=1;
		else bly=0;
	if(cc==16||cc==20)
		if(yc==11) blc-=1;
		else blc=0;
	if(yc==17)
		if(cc<=5||cc>=8&&cc!=11) bly=0;
		else if(cc==11) bly-=1;
	if(cc==17)
		if(yc<=5||yc>=8&&yc!=11) blc=0;
		else if(yc==11) blc-=1;
	if(yc==18)
		if(cc<=7||cc>=10&&cc!=11) bly=0;
		else if(cc==11) bly-=1;
	if(cc==18)
		if(yc<=7||yc>=10&&yc!=11) blc=0;
		else if(yc==11) blc-=1;
	if(yc==19)
		if(cc<=8&&cc!=11) bly=0;
		else if(cc==11) bly-=1;
	if(cc==19)
		if(yc<=8&&yc!=11) blc=0;
		else if(yc==11) blc-=1;
}
void run() {
	srand(time(0));
	rule();
	while(bly>0&&blc>0) {
		system("pause");
		system("mode con cols=30 lines=30");
		show();
		gcc();
		while(1) {
			scanf("%d",&yc);
			if(yc>20||yc<=0||yc==10) {
				printf("无效，请重选\n");
			}
			else if(!avy[yc]) {
				printf("你无法使用[%s]，请重选\n",chs[yc].c_str());
			}
			else break;
		}
		if(!avy[yc]) {
			printf("你自爆了！\n");
			break;
		}
		printf("你选择了 [%s]\n",chs[yc].c_str());
		upd();
		printf("电脑选择了 [%s]\n",chs[cc].c_str());
	}
	if(blc<=0) printf("你赢了！\n");
	else printf("你输了！\n");
	system("pause");
}
int main() {
	run();
	return 0;
}
