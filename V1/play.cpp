#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int d[]={0,			-1,			-2,			-3,			-4,			-5,
					-6,			-7,			-8,			-10,		-15,
					0,			0,			0,			0,			0,			
					0,			-1,			-1,			-1,			1};
string chs[]={"",	"���� -1","˫�� -2","���� -3","�ز� -4","Ƭ�� -5",
					"�ɲ� -6","���� -7","������ -8","������ -10","����ĩ�� -15",
					"�ⵥ 0","С�� 0","��� 0","���� 0","�� 0",
					"�� 0","�� -1","������ -1","������ -1","�� +1"};
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
}
void show() {
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
				printf("��Ч������ѡ\n");
			}
			else if(!avy[yc]) {
				printf("���޷�ʹ��[%s]������ѡ\n",chs[yc].c_str());
			}
			else break;
		}
		if(!avy[yc]) {
			printf("���Ա��ˣ�\n");
			break;
		}
		printf("��ѡ���� [%s]\n",chs[yc].c_str());
		upd();
		printf("����ѡ���� [%s]\n",chs[cc].c_str());
	}
	if(blc<=0) printf("��Ӯ�ˣ�\n");
	else printf("�����ˣ�\n");
	system("pause");
}
int main() {
	run();
	return 0;
}
