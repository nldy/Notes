#include<stdio.h>
#include<string.h>
int value[25][1005];
int max(int a,int b){
    return a>b?a:b;
}
//����ѭ���о�д��̫�����ˣ�����û��ʲôif�ͰѺü������д�����Ū��ͨ��ʽ�Ӿ�������ˡ�
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
        for(i=2;i<=m;++i){       //���һ��ÿ�������ֵ
            t=value[1][i-1];
            for(j=1;j<i;++j){
                if(i%j==0){
                    t=max(t,value[1][j]);
                }
            }
            value[1][i]+=t;
        }
        for(i=2;i<=n;++i){//����Ϊ˳����
            value[i][1]+=value[i-1][1];//���������˵�һ�е����
            for(j=2;j<=m;j++){//ǰһ�����˵�һ�����������ʹ�2��ʼ�󣬲���if��Щ�����г���
                t=max(value[i-1][j],value[i][j-1]);
                for(k=1;k<j&&(j%k==0);++k)//forѭ����Ҳ������������
                    t=max(t,value[i][k]);
                value[i][j]+=t;
            }
        }
        printf("%d\n",value[n][m]);
    }
    return 0;
}
