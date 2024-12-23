//
// Created by zhengwei.
//

#include<iostream>
using namespace std;
#define N 404
int paths[N];//记录路径
int dx[4]={1,0,-1,0};//控制走的方向
int dy[4]={0,1,0,-1};
int cntx[N],cnty[N];//记录两个方向上每个箭靶中箭的数量
int n,tot=0;
bool success=false;//是否到达终点
bool visited[N][N];//标记某点是否走过
bool check() {
    for (int i = 1; i <= n; ++i) {
        if(cntx[i]!=0 || cnty[i] != 0)
            return false;
    }
    return true;
}

void dfs(int x, int y, int num)//num记录步数
{
    paths[num]=(y-1)*n+x-1; //将该点编号记录到路径中
    visited[x][y]=true;//将该点标记为已经走过的状态
    cntx[x]--;//拔掉对应的箭
    cnty[y]--;
    if(/*num==tot/2&&*/x==n&&y==n&&check())//判断是否到达终点
    {
        success=true;
        return;
    }
    for(int i=0;i<4;i++)//上下左右四个方向搜索下一步
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(!success&&!visited[xx][yy]&&1<=xx&&xx<=n&&yy>=1&&yy<=n)//没有到达终点，下一步(xx,yy)未走过且在地图范围内
        {
            if(cntx[xx]>0&&cnty[yy]>0)//该点对应箭靶上有箭，说明该点可以走
            {
                dfs(xx,yy,num+1);//搜索下一步
                visited[xx][yy]=false;//复原，回溯
                cntx[xx]++;
                cnty[yy]++;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&cntx[i]);
        tot+=cntx[i];//tot 统计箭的总数量
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&cnty[i]);
        tot+=cnty[i];
    }
    dfs(1,1,1);
    for(int i=1;i<=tot/2;i++)//输出答案。
    {
        printf("%d ",paths[i]);
    }
    return 0;
}