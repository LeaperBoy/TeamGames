//永远不要对没有发言环节的狼人杀抱有希望
#include<bits/stdc++.h>
using namespace std;
int life[7]={1,1,1,1,1,1};
int potions[5]={-1,1};
int vote[7]={0};
string name[7]={"预言家","女巫","平民","平民","狼人","狼人"}; 
int seer(int x,int y,int n,int p1,int p2,int l1,int l2)
{
int rescued;
int die;
int die_potions;
bool gameover=false;
while(gameover==false)
{
    cout<<endl<<"下一天：----------------------------"<<endl;
    for(int i=1;i<=4;i++)
    {
        if(i==1&&(life[l1]>=0 or life[l2]>=0))
        {
            cout<<"狼人:"<<endl;
            srand((unsigned)time(NULL)); 
            die=rand()%6;
            while(name[die]=="狼人"||life[die]==-1) die=rand()%6;
            life[die]--;
            cout<<"狼人杀了"<<name[die]<<endl;
        }
        if(i==2&&life[x]>=0)
        {
            cout<<"预言家:"<<endl;
            cout<<"你是预言家，请输入0~5的编号（代表相应的人）（除了"<<x<<"号）来预言"<<endl;
            int res;
            cin>>res;
            if(name[res]=="平民"||name[res]=="女巫"||name[res]=="预言家") cout<<"好人"<<endl; 
            if(name[res]=="狼人") cout<<"坏人"<<endl; 
        }
        if(i==3&&life[n]>=0)
        {
            cout<<"女巫:"<<endl;
            int dor;
            srand((unsigned)time(NULL)); 
            dor=rand()%3;
            if(dor==0)
            {
                die_potions=rand()%6;
                while(name[die_potions]=="女巫"||life[die_potions]<=0) die_potions=rand()%6;
                life[die_potions]--;
                potions[dor]++;
                cout<<"女巫杀了"<<name[die_potions]<<endl;
            }
            if(dor==1)
            {
                int help;
                for(int i=0;i<6;i++) if(life[i]==0) life[i]++,help=i;
                potions[dor]--;
                cout<<"女巫救了"<<name[help]<<endl;
            }
            if(dor==2)
            {
                cout<<"没用药"<<endl; 
            }
        }
        if(i==4)
        {
            int sum_die=0;
            cout<<"今晚";
            for(int j=0;j<6;j++)
            {
                if(life[j]==0) 
                {
                    sum_die++;
                    life[j]--;
                    cout<<j<<"号"<<name[j]<<"死了"; 
                }
            } 
            if(sum_die==0) cout<<"是平安夜";
            int fl=0,fp=0;
            for(int j=0;j<6;j++)
            {
                if(life[j]==1)
                {
                    if(name[j]=="狼人") fl++;
                    else fp++;
                }
            }
            if(fl==0) 
            {
                cout<<endl<<"平民赢了"<<endl; 
                gameover=true;
                continue;
            }
            if(fp==0)
            {
                cout<<endl<<"狼人赢了"<<endl;
                gameover=true; 
                continue;
            }
            cout<<endl<<"投票"<<endl; 
            int a[7]={0,0,0,0,0,0};
            for(int j=0;j<6;j++)
            {
                if(j==x&&life[x]==1) 
                {
                    cout<<"请投0~5号你认为是狼人的";
                    int ps;
                    cin>>ps;
                    a[ps]++; 
                }
                else if(life[j]==1)
                {
                    srand((unsigned)time(NULL)); 
                    int cs;
                    cs=rand()%6;
                    while(life[cs]!=1||cs==j) cs=rand()%6;
                    a[cs]++;
                }
            }
            cout<<"投票结果:"<<endl;
            cout<<"0 1 2 3 4 5"<<endl;
            for(int j=0;j<6;j++) cout<<a[j]<<" ";
            cout<<endl;
            int max=-1,mp;
            for(int j=0;j<6;j++) if(a[j]>=max) max=a[j],mp=j;
            cout<<mp<<"号"<<name[mp]<<"出局"<<endl<<endl;
            life[mp]=-1; 
            int good=0,bad=0;
            for(int j=0;j<6;j++)
            {
                if(life[j]==1&&(name[j]=="平民"||name[j]=="女巫"||name[j]=="预言家")) good++;
                if(life[j]==1&&name[j]=="狼人") bad++;
            }
            if(bad==0) 
            {
                cout<<"平民赢了"<<endl;
                gameover=true;
            }
            if(good==0) 
            {
                cout<<"狼人赢了"<<endl;
                gameover=true;
            }
        }
    }
    system("pause");
}
return 0;
}
int Lycan(int x,int y,int n,int p1,int p2,int l1,int l2)
{
int rescued;
int die;
int die_potions;
bool gameover=false;
while(gameover==false)
{
    cout<<endl<<"下一天：----------------------------"<<endl;
    for(int i=1;i<=4;i++)
    {
        if(i==1&&life[x]>=0)
        {
            cout<<"狼人:"<<endl;
            cout<<"你是狼人，请输入0~5的编号（代表相应的人）（除了"<<x<<"和"<<l1+l2-x<<"号）来杀死"<<endl; 
            cin>>die;
            life[die]--;
            cout<<"狼人杀了"<<name[die]<<endl;
        }
        if(i==1&&life[x]==-1&&life[l1+l2-x]>=0)
        {
            cout<<"狼人:"<<endl;
            srand((unsigned)time(NULL)); 
            die=rand()%6;
            while(name[die]=="狼人"||life[die]==-1) die=rand()%6;
            life[die]--;
            cout<<"狼人杀了"<<name[die]<<endl;
        }
        if(i==2&&life[y]>=0)
        {
            cout<<"预言家:"<<endl;
            cout<<"预言完毕"<<endl; 
        }
        if(i==3&&life[n]>=0)
        {
            cout<<"女巫:"<<endl;
            int dor;
            srand((unsigned)time(NULL)); 
            dor=rand()%3;
            if(dor==0)
            {
                die_potions=rand()%6;
                while(name[die_potions]=="女巫"||life[die_potions]<=0) die_potions=rand()%6;
                life[die_potions]--;
                potions[dor]++;
                cout<<"女巫杀了"<<name[die_potions]<<endl;
            }
            if(dor==1)
            {
                int help;
                for(int i=0;i<6;i++) if(life[i]==0) life[i]++,help=i;
                potions[dor]--;
                cout<<"女巫救了"<<name[help]<<endl;
            }
            if(dor==2)
            {
                cout<<"没用药"<<endl; 
            }
        }
        if(i==4)
        {
            int sum_die=0;
            cout<<"今晚";
            for(int j=0;j<6;j++)
            {
                if(life[j]==0) 
                {
                    sum_die++;
                    life[j]--;
                    cout<<j<<"号"<<name[j]<<"死了"; 
                }
            } 
            if(sum_die==0) cout<<"是平安夜";
            int fl=0,fp=0;
            for(int j=0;j<6;j++)
            {
                if(life[j]==1)
                {
                    if(name[j]=="狼人") fl++;
                    else fp++;
                }
            }
            if(fl==0) 
            {
                cout<<endl<<"平民赢了"<<endl; 
                gameover=true;
                continue;
            }
            if(fp==0)
            {
                cout<<endl<<"狼人赢了"<<endl;
                gameover=true; 
                continue;
            }
            cout<<endl<<"投票"<<endl; 
            int a[7]={0,0,0,0,0,0};
            for(int j=0;j<6;j++)
            {
                if(j==x&&life[x]==1) 
                {
                    cout<<"请投0~5号你认为是狼人的";
                    int ps;
                    cin>>ps;
                    a[ps]++; 
                }
                else if(life[j]==1)
                {
                    srand((unsigned)time(NULL)); 
                    int cs;
                    cs=rand()%6;
                    while(life[cs]!=1||cs==j) cs=rand()%6;
                    a[cs]++;
                }
            }
            cout<<"投票结果:"<<endl;
            cout<<"0 1 2 3 4 5"<<endl;
            for(int j=0;j<6;j++) cout<<a[j]<<" ";
            cout<<endl;
            int max=-1,mp;
            for(int j=0;j<6;j++) if(a[j]>=max) max=a[j],mp=j;
            cout<<mp<<"号"<<name[mp]<<"出局"<<endl<<endl;
            life[mp]=-1; 
            int good=0,bad=0;
            for(int j=0;j<6;j++)
            {
                if(life[j]==1&&(name[j]=="平民"||name[j]=="女巫"||name[j]=="预言家")) good++;
                if(life[j]==1&&name[j]=="狼人") bad++;
            }
            if(bad==0) 
            {
                cout<<"平民赢了"<<endl;
                gameover=true;
            }
            if(good==0) 
            {
                cout<<"狼人赢了"<<endl;
                gameover=true;
            }
        }
    }
    system("pause");
}
return 0;
}
int witch(int x,int y,int n,int p1,int p2,int l1,int l2)
{
int rescued;
int die;
int die_potions;
bool gameover=false;
while(gameover==false)
{
    cout<<endl<<"下一天：----------------------------"<<endl;
    for(int i=1;i<=4;i++)
    {
        if(i==1&&(life[l1]>=0 or life[l2]>=0))
        {
            cout<<"狼人:"<<endl;
            srand((unsigned)time(NULL)); 
            die=rand()%6;
            while(name[die]=="狼人"||life[die]==-1) die=rand()%6;
            life[die]--;
            cout<<"狼人杀了"<<name[die]<<endl;
        }
        if(i==2&&life[y]>=0)
        {
            cout<<"预言家:"<<endl;
            cout<<"预言完毕"<<endl; 
        }
        if(i==3&&life[n]>=0)
        {
            cout<<"女巫:"<<endl;
            cout<<"你是女巫，请输入d、r、n。d代表要杀、r代表要救，n代表不用药"<<endl;
            char dor;
            cin>>dor;
            if(dor=='d')
            {
                cout<<"请输入0~5号你要杀的人（除了"<<n<<"号）"<<endl;
                cin>>die_potions;
                life[die_potions]--;
                potions[0]++;
                cout<<"女巫杀了"<<name[die_potions]<<endl;
            }
            if(dor=='r')
            {
                int help;
                for(int i=0;i<6;i++) if(life[i]==0) life[i]++,help=i;
                potions[1]--;
                cout<<"女巫救了"<<name[help]<<endl;
            }
            if(dor=='n')
            {
                cout<<"没用药"<<endl; 
            }
        }
        if(i==4)
        {
            int sum_die=0;
            cout<<"今晚";
            for(int j=0;j<6;j++)
            {
                if(life[j]==0) 
                {
                    sum_die++;
                    life[j]--;
                    cout<<j<<"号"<<name[j]<<"死了"; 
                }
            } 
            if(sum_die==0) cout<<"是平安夜";
            int fl=0,fp=0;
            for(int j=0;j<6;j++)
            {
                if(life[j]==1)
                {
                    if(name[j]=="狼人") fl++;
                    else fp++;
                }
            }
            if(fl==0) 
            {
                cout<<endl<<"平民赢了"<<endl; 
                gameover=true;
                continue;
            }
            if(fp==0)
            {
                cout<<endl<<"狼人赢了"<<endl;
                gameover=true; 
                continue;
            }
            cout<<endl<<"投票"<<endl; 
            int a[7]={0,0,0,0,0,0};
            for(int j=0;j<6;j++)
            {
                if(j==x&&life[x]==1) 
                {
                    cout<<"请投0~5号你认为是狼人的";
                    int ps;
                    cin>>ps;
                    a[ps]++; 
                }
                else if(life[j]==1)
                {
                    srand((unsigned)time(NULL)); 
                    int cs;
                    cs=rand()%6;
                    while(life[cs]!=1||cs==j) cs=rand()%6;
                    a[cs]++;
                }
            }
            cout<<"投票结果:"<<endl;
            cout<<"0 1 2 3 4 5"<<endl;
            for(int j=0;j<6;j++) cout<<a[j]<<" ";
            cout<<endl;
            int max=-1,mp;
            for(int j=0;j<6;j++) if(a[j]>=max) max=a[j],mp=j;
            cout<<mp<<"号"<<name[mp]<<"出局"<<endl<<endl;
            life[mp]=-1; 
            int good=0,bad=0;
            for(int j=0;j<6;j++)
            {
                if(life[j]==1&&(name[j]=="平民"||name[j]=="女巫"||name[j]=="预言家")) good++;
                if(life[j]==1&&name[j]=="狼人") bad++;
            }
            if(bad==0) 
            {
                cout<<"平民赢了"<<endl;
                gameover=true;
            }
            if(good==0) 
            {
                cout<<"狼人赢了"<<endl;
                gameover=true;
            }
        }
    }
    system("pause");
}
return 0;
}
int commoner(int x,int y,int n,int p1,int p2,int l1,int l2)
{
int rescued;
int die;
int die_potions;
bool gameover=false;
while(gameover==false)
{
    cout<<endl<<"下一天：----------------------------"<<endl;
    for(int i=1;i<=4;i++)
    {
        if(i==1&&(life[l1]>=0 or life[l2]>=0))
        {
            cout<<"狼人:"<<endl;
            srand((unsigned)time(NULL)); 
            die=rand()%6;
            while(name[die]=="狼人"||life[die]==-1) die=rand()%6;
            life[die]--;
            cout<<"狼人杀了"<<name[die]<<endl;
        }
        if(i==2&&life[y]>=0)
        {
            cout<<"预言家:"<<endl;
            cout<<"预言完毕"<<endl; 
        }
        if(i==3&&life[n]>=0)
        {
            cout<<"女巫:"<<endl;
            int dor;
            srand((unsigned)time(NULL)); 
            dor=rand()%3;
            if(dor==0)
            {
                die_potions=rand()%6;
                while(name[die_potions]=="女巫"||life[die_potions]<=0) die_potions=rand()%6;
                life[die_potions]--;
                potions[dor]++;
                cout<<"女巫杀了"<<name[die_potions]<<endl;
            }
            if(dor==1)
            {
                int help;
                for(int i=0;i<6;i++) if(life[i]==0) life[i]++,help=i;
                potions[dor]--;
                cout<<"女巫救了"<<name[help]<<endl;
            }
            if(dor==2)
            {
                cout<<"没用药"<<endl; 
            }
        }
        if(i==4)
        {
            int sum_die=0;
            cout<<"今晚";
            for(int j=0;j<6;j++)
            {
                if(life[j]==0) 
                {
                    sum_die++;
                    life[j]--;
                    cout<<j<<"号"<<name[j]<<"死了"; 
                }
            } 
            if(sum_die==0) cout<<"是平安夜";
            int fl=0,fp=0;
            for(int j=0;j<6;j++)
            {
                if(life[j]==1)
                {
                    if(name[j]=="狼人") fl++;
                    else fp++;
                }
            }
            if(fl==0) 
            {
                cout<<endl<<"平民赢了"<<endl; 
                gameover=true;
                continue;
            }
            if(fp==0)
            {
                cout<<endl<<"狼人赢了"<<endl;
                gameover=true; 
                continue;
            }
            cout<<endl<<"投票"<<endl; 
            int a[7]={0,0,0,0,0,0};
            for(int j=0;j<6;j++)
            {
                if(j==x&&life[x]==1) 
                {
                    cout<<"请投0~5号你认为是狼人的";
                    int ps;
                    cin>>ps;
                    a[ps]++; 
                }
                else if(life[j]==1)
                {
                    srand((unsigned)time(NULL)); 
                    int cs;
                    cs=rand()%6;
                    while(life[cs]!=1||cs==j) cs=rand()%6;
                    a[cs]++;
                }
            }
            cout<<"投票结果:"<<endl;
            cout<<"0 1 2 3 4 5"<<endl;
            for(int j=0;j<6;j++) cout<<a[j]<<" ";
            cout<<endl;
            int max=-1,mp;
            for(int j=0;j<6;j++) if(a[j]>=max) max=a[j],mp=j;
            cout<<mp<<"号"<<name[mp]<<"出局"<<endl<<endl;
            life[mp]=-1; 
            int good=0,bad=0;
            for(int j=0;j<6;j++)
            {
                if(life[j]==1&&(name[j]=="平民"||name[j]=="女巫"||name[j]=="预言家")) good++;
                if(life[j]==1&&name[j]=="狼人") bad++;
            }
            if(bad==0) 
            {
                cout<<"平民赢了"<<endl;
                gameover=true;
            }
            if(good==0) 
            {
                cout<<"狼人赢了"<<endl;
                gameover=true;
            }
        }
    }
    system("pause");
}
return 0;
}
int main()
{
begin:
cout<<"狼人杀"<<endl;
cout<<"1个预言家 1个女巫 2个平民 2个狼人"<<endl;
srand((unsigned)time(NULL)); 
for(int i=1;i<=1000;i++)
{
    int x=rand()%6; 
    int y=rand()%6;
    swap(name[x],name[y]);
}
int player=rand()%6;
cout<<"你是"<<name[player]<<endl<<"您的编号是"<<player<<endl<<endl;
int l1,l2,l=1;
int y;
int n;
int p1,p2,p=1;
for(int i=0;i<6;i++)
{
    if(name[i]=="狼人"&&l==1) 
    {
        l1=i;
        l++;
        continue;
    }
    if(name[i]=="狼人"&&l==2) l2=i,l++;
    if(name[i]=="预言家") y=i;
    if(name[i]=="女巫") n=i;
    if(name[i]=="平民"&&p==1) 
    {
        p1=i;
        p++;
        continue;
    }
    if(name[i]=="平民"&&p==2) p2=i,p++;
}
if(player==y) seer(player,y,n,p1,p2,l1,l2);
if(player==l1 or player==l2) Lycan(player,y,n,p1,p2,l1,l2);
if(player==n) witch(player,y,n,p1,p2,l1,l2);
if(player==p1 or player==p2) commoner(player,y,n,p1,p2,l1,l2);
else return 0;
}
