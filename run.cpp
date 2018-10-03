#include<bits/stdc++.h>
using namespace std;
int a[135]={0,164,231,477,532,543,893,918,1282,1524,1651,1665,1732,1928,2255,2381,2605,2894,2924,3077,3197,3306,3426,3523,3727,3809,3964,4011,4169,4244,4352,4476,4553,4620,4694,4856,4912,4958,5277,5457,5559,5679,5724,5884,5992,6042,6072,6241,6291,6357,6395,6422,6480,6530,6594,6652,6715,6771,6840,6965,7012,7136,7244,7318,7354,7499,7530,7542,7606,7641,7721,7758,7799,7853,7918,7957,7998,8032,8078,8115,8153,8290,8358,8400,8461,8504,8508,8540,8546,8601,8628,8875,8909,8948,8991,9030,9066,9107,9162,9203,9254,9289,9344,9385,9432,9481,9540,9572,9621,9660,9708,9741,9770,9805,9851,9889,10215,10244,10282,10319,10343,10395,10425,10487,10511,10548,10574,10604,10656,10712,10745,10808,10844,10880,10924};
char cmd[10000];
int evaluate(int your_score,int sa,int enemy_score)
{
    double Ea=Ea=1/(1+pow(10,(enemy_score-your_score)/400));
    double Eb=1-Ea;
    return int(your_score+32*(sa-Ea));
}
int main()
{
    int elo,c=0;
    while(c==0)
    {
        srand(time(0));
        freopen("./data.txt","r",stdin);
        cin>>elo;
        fclose(stdin);
        printf("Your score in lz is:%d\n",elo);
        int *enemy=lower_bound(a,a+135,elo);
        cout<<*enemy<<endl;
        if(rand()%1==0) sprintf(cmd,"gogui-twogtp -black 'gogui-display' -white './leelaz -g -w ./networks/%d -p 1600 --noponder' -size 19 -komi 7.5 -verbose -auto",*enemy);
        else sprintf(cmd,"gogui-twogtp -white 'gogui-display' -black './leelaz -g -w ./networks/%d -p 1600 --noponder' -size 19 -komi 7.5 -verbose -auto",*enemy);
        puts(cmd);
        system(cmd);
        cout<<"If you were win,press the 1,else press the 0(PLEASE BE HONEST)";
        int s;
        cin>>s;
        elo=evaluate(elo,s,*enemy);
        freopen("./data.txt","w",stdout);
        cout<<elo;
        fclose(stdout);
        cout<<"Now your score is "<<elo<<"."<<endl;
        cout<<"Do you want to play more game? If you want,please press 0.";
        cin>>c;
    }
    return 0;
}
