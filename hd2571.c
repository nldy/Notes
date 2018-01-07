#include<stdio.h>
#include<string.h>
int value[25][1005];
int max(int a,int b){
    return a>b?a:b;
}
//整个循环感觉写得太精巧了，根本没用什么if就把好几种情况写清楚，弄成通用式子就求出来了。
int main(){
    int ncase;
    int n,m;
    int i,j,k,t;
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d%d",&n,&m);
        memset(value,0,sizeof(value));
        for(i=1;i<=n;++i){
            for(j=1;j<=m;++j)
                scanf("%d",&value[i][j]);
        }
        t=0;
        for(i=2;i<=m;++i){       //求第一排每个的最大值
            t=value[1][i-1];
            for(j=1;j<i;++j){
                if(i%j==0){
                    t=max(t,value[1][j]);
                }
            }
            value[1][i]+=t;
        }
        for(i=2;i<=n;++i){//以行为顺序求
            value[i][1]+=value[i-1][1];//这样就求了第一列的情况
            for(j=2;j<=m;j++){//前一排求了第一列情况，这里就从2开始求，不用if这些多余列出来
                t=max(value[i-1][j],value[i][j-1]);
                for(k=1;k<j&&(j%k==0);++k)//for循环里也可以有条件啊
                    t=max(t,value[i][k]);
                value[i][j]+=t;
            }
        }
        printf("%d\n",value[n][m]);
    }
    return 0;
}
