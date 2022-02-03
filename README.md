说明：
和电脑玩结

----------
作者：tzc_nydzsf

----------
置顶：与V3以及之前的版本data不兼容，V3以及之前版本并未公开

----------
运行 getdata.exe 可以使电脑进行自动对局并保存数据

getdata.exe会先输出目前已保存的对局数

首先输入两个整数 n 和 m 示保存数据的间隔和总对局数，之后程序会自动运行，每运行完 k\*n 局后会保存数据并输出 k\*n 表示已经进行了多少局

建议输入范围在100000~1000000之间，输入的数小会增加保存频率导致程序运行速度缓慢，太大会导致保存间隔很长

通常情况下1000000次对局可在约1秒完成

此程序并不会删除之前 data 内的数据，而是在此基础上添加对局记录

----------
规则如下：

攻击型：

1: [单刀 -1]

2: [双刀 -2]

3: [致命 -3]

4: [地波 -4]

5: [片波 -5]

6: [派波 -6]

7: [气波 -7]

8: [青龙波 -8]

9: [金龙波 -10]

10: [世界末日 -15]

11: [免单 0]

非攻击型：

12: [小防 0]

13: [大防 0]

14: [反弹 0]

15: [吸 0]

16: [拉 0]

17: [收 -1]

18: [青龙收 -1]

19: [金龙收 -1]

20: [结 +1]

特殊性：

0: [摩擦 0]

攻击型同样点数抵消，点数差1扣0.5血量，点数差大于1扣除全部血量（此时免单相当于单刀）

使用除免单外攻击如果对方没防住直接死亡，使用免单则扣除0.5血量

免单一局只能使用一次

小防：防住点数不大于2的攻击

大防：防住点数为3-5的攻击

反弹：反弹点数不大于1的攻击

收：防住点数为6-7的攻击

青龙收：防住点数为8的青龙波

金龙收：防住点数为10的金龙波

吸：如果对方使用点数不大于5的攻击，则获得对方使用此攻击所需的点数

拉：不能防住任何攻击，但对方如果使用吸则对方直接死亡

结：获得1点

摩擦：当对方使用点数不大于7的攻击时可以获得对方使用此攻击所需的点数

当对方使用点数大于7的攻击时可以防住对方的攻击

当对方不使用攻击时则使用者直接死亡

----------
Update:

V1.1 修复自爆显示

-Update time: 2021/07/02

V1.2 修复规则显示，添加 readme.txt

-Update time: 2021/07/02

V1.2.1 更改电脑选择机制

-Update time: 2021/07/02

V2.0 增加 save 保存之前赢的记录，优先选择赢的概率大的选项

-Update time: 2021/07/02

V2.1 将 save 更名为 data，修复自爆显示

-Update time: 2021/07/02

V2.2 修复 data 存储

-Update time: 2021/07/03

V1.3/V2.3 修复大防能防住派波、气波、青龙波和金龙波的 BUG

-Update time: 2021/07/04

V2.4 增加作弊模式功能，输入"114514" 可开启/关闭作弊模式

-Update time: 2021/07/04

V2.5 作弊模式的对局数据不再存入 data

-Update time: 2021/07/05

V2.5.3 更新 getdata.exe 并添加这个程序的说明

-Update time: 2021/07/06

V2.6 更新选择机制

-Update time: 2021/07/11

V1.4/V2.7 更新显示

-Update time: 2021/07/26

V1.5/V2.8 修复使用金龙波攻击青龙波对方只扣除0.5血量的 BUG

-Update time: 2021/07/31

V3.0 添加世界末日

-Update time: 2021/07/31

V2.9/V3.1 修复作弊模式显示的 BUG

-Update time: 2021/08/09

V1.6/V2.10 修复地波显示

-Update time: 2021/08/10

V3.2 更新getdata.exe、data以及程序，data与之前版本不兼容

-Update time: 2021/09/05

V3.3 对data进行了调整，界面并无变化

-Update time: 2021/09/12

V4.0 添加了摩擦，并增加了挑战版（开局自定点数）以及无限挑战版的程序（每次结束后需输入'y'/'Y'/'n'/'N'表示是否继续）

-Update time: 2021/09/12

V2.11/V3.4 修复自爆

-Update time: 2021/10/05

V4.1 修复自爆和规则以及挑战版显示

-Update time: 2021/10/05

V4.2 修改了getdata.exe和计算机选择的方式

-Update time: 2022/02/03