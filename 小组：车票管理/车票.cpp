#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "time.h"
//�����Ϣ��
#define SIZELIMIT 10 //ÿ��εľ�����Ϣ���ַ�����������10����
#define MAXNUM 1000 //�趨���ֻ��¼��1000��������Ϣ
typedef struct cardbase //����һ�����ڰ����Ϣ�Ľṹ�壬ȡ��ΪCardBase
{
char C_ID[SIZELIMIT];//���
char C_TIME[SIZELIMIT];//����ʱ��
char C_ANAME[SIZELIMIT];//���վ
char C_BNAME[SIZELIMIT];//�յ�վ
char C_USETIME[SIZELIMIT];//�г�ʱ��
char C_MAXNUM[SIZELIMIT];//�����
char C_REMAINNUM[SIZELIMIT];//��Ʊ����
}CardBase;
int cbNum=0;//��¼�����
CardBase cBList[MAXNUM];//����б�
//��ȡ�����Ϣ
void readcardbasefile()
{
FILE *fp;
//���ļ�ʧ���򴴽��ļ�
if((fp=fopen("./number.dat","r"))==NULL)
{
//�������д����ļ�
if ((fp=fopen("./number.dat","w"))==NULL)
{
exit(0); //����
}
else
{
fclose(fp);
}
return ;
}
/*�ļ�λ��ָ���ƶ����ļ�ĩβ*/
fseek(fp,0,2);//�ض�λ�ļ��ڲ�λ��ָ��
/* int fseek( FILE *stream, long offset, int origin );
��һ������streamΪ�ļ�ָ��
�ڶ�������offsetΪƫ������������ʾ����ƫ�ƣ�������ʾ����ƫ��
����������origin�趨���ļ������￪ʼƫ��,����ȡֵΪ��SEEK_CUR�� SEEK_END �� SEEK_SET
SEEK_SET�� �ļ���ͷ
SEEK_CUR�� ��ǰλ��
SEEK_END�� �ļ���β
����SEEK_SET,SEEK_CUR��SEEK_END����Ϊ0��1��2.
����֮��
fseek(fp,100L,0);��streamָ���ƶ������ļ���ͷ100�ֽڴ���
fseek(fp,100L,1);��streamָ���ƶ������ļ���ǰλ��100�ֽڴ���
fseek(fp,-100L,2);��streamָ���˻ص����ļ���β100�ֽڴ��� */
if (ftell(fp)>0)//�ļ���Ϊ��
/*ftell�������ڵõ��ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽ���
Ҳ���ǵõ��ļ����������ֽ���,�������0��������ļ��ǿ�*/
{
//�ļ�λ��ָ���ƶ����ļ���ʼ
rewind(fp);
char buff[10]={0};
for (cbNum=0;!feof(fp) && fread(&cBList[cbNum],sizeof(CardBase),1,fp);cbNum++)
/*����feof��������������ļ�����������feof��fp����ֵΪ����ֵ������Ϊ0��
������ļ�������!feof(fp)Ϊ0������ѭ��
����fread�������Ǵ�һ���ļ����ж����ݣ�������óɹ�����ʵ�ʶ�ȡ�����������
������ɹ�������ļ�ĩβ���� 0*/
fgets(buff,10,fp);
/*char *fgets(char *buf, int bufsize, FILE *stream);
���ļ��ṹ��ָ��stream�ж�ȡ���ݣ�ÿ�ζ�ȡһ�С���ȡ�����ݱ�����bufָ����ַ������У�
ÿ������ȡbufsize-1���ַ�����bufsize���ַ���'\0'��������ļ��еĸ��У�����bufsize���ַ���
�������оͽ������������У��������һ�����з������ַ�������bufsize-1����fgetsֻ����һ�����������У�
���ǣ�������������NULL�ַ���β����fgets����һ�ε��û���������С������ɹ�������buf��ʧ�ܻ�����ļ���β����NULL��
������ǲ���ֱ��ͨ��fgets�ķ���ֵ���жϺ����Ƿ��ǳ������ֹ�ģ�Ӧ�ý���feof��������ferror�������жϡ�
*/
fclose(fp);
}
else
{
fclose(fp);
}
return;
}
//��������Ϣ
void writecardbasefile()
{
int i;
FILE *fp;
if ((fp=fopen("./number.dat","w"))==NULL)
{
printf("ϵͳ����");
}
char buff[10]={0};
strcpy(buff,"\r\n");
for (i=0;i<cbNum;i++)
{
if (fwrite(&cBList[i],sizeof(CardBase),1,fp)!=1)
{
printf("ϵͳ����");
}
if (fwrite(buff,2,1,fp)!=1)
{
printf("ϵͳ����");
}
}
fclose(fp);
}
//����������Ϣ
void writesortfile()
{
int i;
FILE *fp;
if ((fp=fopen("./sort.dat","w"))==NULL)
{
printf("ϵͳ����");
}
char buff[10]={0};
strcpy(buff,"\r\n");
for (i=0;i<cbNum;i++)
{
if (fwrite(&cBList[i],sizeof(CardBase),1,fp)!=1)
{
printf("ϵͳ����");
}
if (fwrite(buff,2,1,fp)!=1)
{
printf("ϵͳ����");
}
}
fclose(fp);
}
//��ӡ������󷵻�
void printReturn(char *info)
{
printf("\n\n\t %s",info);
fflush(stdin);//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ.
getchar();
}
//������Ϣ
void setInfo(char pinfo[1024],char desinfo[])
{
printf("\n\t%s:",pinfo);
fflush(stdin);
scanf("%s",desinfo);
}
//ϵͳ��ʼ��
void initsystem()
{
readcardbasefile();
};
//¼����
void infoinput()
{
setInfo("���",cBList[cbNum].C_ID);
setInfo("����ʱ��(24Сʱ��)",cBList[cbNum].C_TIME);
setInfo("���վ",cBList[cbNum].C_ANAME);
setInfo("�յ�վ",cBList[cbNum].C_BNAME);
setInfo("�г�ʱ��",cBList[cbNum].C_USETIME);
setInfo("�����",cBList[cbNum].C_MAXNUM);
setInfo("��Ʊ����",cBList[cbNum].C_REMAINNUM);
cbNum++;
writecardbasefile();
printReturn("\n\t¼��ɹ����س�������");
};
//ʱ��Ƚ�
int timecmp(char A[10])
{
//����ʱ��ת������
char tempa[10]={0};
int ta=0;
int i;
for(i=0;i<strlen(A);i++)
if(A[i]!=':'&&A[i]!='��') //ð�ŵ����������Ӣ������
{
tempa[ta]=A[i];
ta++;
}
int atime=atoi(tempa);//���ַ����������
//��ȡϵͳʱ��
char tempb[10]={0};
time_t t = time(0);
strftime( tempb, 10, "%H%M",localtime(&t) );
int btime=atoi(tempb);
//�Ƚ�
if(atime<=btime) //�Ѿ�����
return 1;
if(((atime-btime<=30)&&(atime-btime>5)&&(atime/100==btime/100))||(((atime%100+(60-btime%100))<=30)&&(atime%100+(60-btime%100))>5&&(atime/100-btime/100==1))) //�෢����Сʱ����,ֹͣ��Ʊ,%��ʾȡ��
return 2;
if(((atime-btime<=5)&&(atime/100==btime/100))||((atime%100+(60-btime%100)&&(atime/100-btime/100==1))<=5)) //�෢��ǰ�������ֹͣ��Ʊ
return 3;
return 0; //���԰�����Ʊ
}
//������а��
void queryallinfo()
{
printf("�����Ϣ\n");
printf("���   ����ʱ��    ���վ    �յ�վ  �г�ʱ��   �����   ��Ʊ����   ״̬\n");
int i;
for(i=0;i<cbNum;i++)
{
char temp[20]={0};
strcpy(temp,"δ����");
if(1==timecmp(cBList[i].C_TIME))
strcpy(temp,"�ѷ���");
if(2==timecmp(cBList[i].C_TIME))
strcpy(temp,"ֹͣ��Ʊ");
if(3==timecmp(cBList[i].C_TIME))
strcpy(temp,"ֹͣ��Ʊ");
printf("%-010s%-010s%-010s%-010s%-010s%-010s%-010s%s\n",
cBList[i].C_ID,cBList[i].C_TIME,
cBList[i].C_ANAME,cBList[i].C_BNAME,cBList[i].C_USETIME,
cBList[i].C_MAXNUM,cBList[i].C_REMAINNUM,temp );
}
printReturn("\n\t�س�������");
};
//ͨ����κŲ�·��
void queryinfobyID()
{
char ID[20]={0};
setInfo("�����κ�",ID);
int i;
for( i=0;i<cbNum;i++)
{
if(strcmp(cBList[i].C_ID,ID)==0)
{
printf("�����Ϣ\n");
printf("���   ����ʱ��    ���վ    �յ�վ  �г�ʱ��    �����   ��Ʊ����\n");
printf("%-010s%-010s%-010s%-010s%-010s%-010s%-010s\n",
cBList[i].C_ID,cBList[i].C_TIME,
cBList[i].C_ANAME,cBList[i].C_BNAME,cBList[i].C_USETIME,
cBList[i].C_MAXNUM,cBList[i].C_REMAINNUM );
printReturn("\n\t�س�������");
return;
}
}
printReturn("\n\tָ����Ϣ�����ڣ��س�������");
};
//ͨ���յ�վ��·��
void queryinfobyBNAME()
{
char Name[20]={0};
setInfo("�����յ�վ",Name);
int i;
for(i=0;i<cbNum;i++)
{
if(strcmp(cBList[i].C_BNAME,Name)==0)
{
printf("�����Ϣ\n");
printf("���   ����ʱ��    ���վ    �յ�վ  �г�ʱ��    �����   ��Ʊ����\n");
printf("%-010s%-010s%-010s%-010s%-010s%-010s%-010s\n",
cBList[i].C_ID,cBList[i].C_TIME,
cBList[i].C_ANAME,cBList[i].C_BNAME,cBList[i].C_USETIME,
cBList[i].C_MAXNUM,cBList[i].C_REMAINNUM );
printReturn("\n\t�س�������");
return;
}
}
printReturn("\n\tָ����Ϣ�����ڣ��س�������");
};
//������Ʊ�������򱣴�
void sortSave()
{
//ð������
int i,j;
for(i=0;i<cbNum;i++)
for(j=0;j<cbNum-i-1;j++)
{
if(atoi(cBList[j].C_REMAINNUM)<atoi(cBList[j+1].C_REMAINNUM))
{
CardBase temp=cBList[j];
cBList[j]=cBList[j+1];
cBList[j+1]=temp;
}
}
//��ӡ������
queryallinfo();
//����������
writesortfile();
};
//��Ʊ
void sale()
{
char ID[20]={0};
setInfo("�����κ�",ID);
int i;
for(i=0;i<cbNum;i++)
{
if(strcmp(cBList[i].C_ID,ID)==0)
{
if(cBList[i].C_REMAINNUM==0)
{
printReturn("\n\t��Ʊ���㣬�س�����");
return;
}
//��Ʊ����
int temp=atoi(cBList[i].C_REMAINNUM)-1;
if(temp<0) temp=0;//ȷ����Ʊ��Ϊ����
_itoa(temp,cBList[i].C_REMAINNUM,10);
//���浽�ļ�
writecardbasefile();
printf("�����Ϣ\n");
printf("���   ����ʱ��    ���վ    �յ�վ  �г�ʱ��    �����   ��Ʊ����\n");
printf("%-010s%-010s%-010s%-010s%-010s%-010s%-010s\n",
cBList[i].C_ID,cBList[i].C_TIME,
cBList[i].C_ANAME,cBList[i].C_BNAME,cBList[i].C_USETIME,
cBList[i].C_MAXNUM,cBList[i].C_REMAINNUM );
printReturn("\n\t��Ʊ�ɹ����س�����");
return;
}
}
printReturn("\n\tָ����β����ڣ��س�������");
};
//��Ʊ
void back()
{
char ID[20]={0};
setInfo("�����κ�",ID);
int i;
for(i=0;i<cbNum;i++)
{
if(strcmp(cBList[i].C_ID,ID)==0)
{
//��Ʊ����
int temp=atoi(cBList[i].C_REMAINNUM)+1;
_itoa(temp,cBList[i].C_REMAINNUM,10);
//���浽�ļ�
writecardbasefile();
printf("�����Ϣ\n");
printf("���   ����ʱ��    ���վ    �յ�վ  �г�ʱ��    �����   ��Ʊ����\n");
printf("%-010s%-010s%-010s%-010s%-010s%-010s%-010s\n",
cBList[i].C_ID,cBList[i].C_TIME,
cBList[i].C_ANAME,cBList[i].C_BNAME,cBList[i].C_USETIME,
cBList[i].C_MAXNUM,cBList[i].C_REMAINNUM );
printReturn("\n\t\t��Ʊ�ɹ����س�����");
return;
}
}
printReturn("\n\tָ����β����ڣ��س�������");
};
//���³�����Ϣ
void update()
{
int flag;
char ID[20]={0};
setInfo("������Ҫɾ�����޸ĵĳ��Σ���ȷ�ϳ���������ȷ��",ID);
do
{
printf("\n\t��������ʾ���³�����Ϣ���˳��޸��밴0��:");
printf("\n\t1��ɾ������;2���޸ķ���ʱ��;3���޸����վ;4���޸��յ�վ;");
printf("\n\t5���޸��г�ʱ��;6���޸Ķ����;7���޸���Ʊ����;0:�˳��޸�;");
printf("\n\t��ѡ��");
scanf("%d",&flag);
int i;
CardBase temp;
for(i=0;i<cbNum;i++)
{
if(strcmp(cBList[i].C_ID,ID)==0)
{
if(flag==1) //ɾ��������Ϣ
{
int j;
for(j=i;j<cbNum;j++)
cBList[j]=cBList[j+1];//��������ݸ���ǰ�������
cbNum--;//��������һ
//���浽�ļ�
writecardbasefile();
}
if(flag==2) //�޸ķ���ʱ��
{
setInfo("�������µķ���ʱ��",cBList[i].C_TIME);
temp=cBList[i];
//���浽�ļ�
writecardbasefile();
}
if(flag==3) //�޸����վ
{
setInfo("�������µ����վ",cBList[i].C_ANAME);
temp=cBList[i];
//���浽�ļ�
writecardbasefile();
}
if(flag==4) //�޸��յ�վ
{
setInfo("�������µ��յ�վ",cBList[i].C_BNAME);
temp=cBList[i];
//���浽�ļ�
writecardbasefile();
}
if(flag==5) //�޸��г�ʱ��
{
setInfo("�������µ��г�ʱ��",cBList[i].C_USETIME);
temp=cBList[i];
//���浽�ļ�
writecardbasefile();
}
if(flag==6) //�޸Ķ����
{
setInfo("�������µĶ����",cBList[i].C_MAXNUM);
temp=cBList[i];
//���浽�ļ�
writecardbasefile();
}
if(flag==7) //�޸���Ʊ����
{
setInfo("�������µ���Ʊ����",cBList[i].C_REMAINNUM);
temp=cBList[i];
//���浽�ļ�
writecardbasefile();
}
}
}
//������ɺ���ʾ���º�İ����Ϣ,�����ɾ����������ʾ,��flag������0��ʱ����ʾ������Ϣ
if(flag!=1&&flag!=0)
{ printf("���º�İ����Ϣ\n");
printf("���   ����ʱ��    ���վ    �յ�վ  �г�ʱ��    �����   ��Ʊ����\n");
printf("%-010s%-010s%-010s%-010s%-010s%-010s%-010s\n",
temp.C_ID,temp.C_TIME,
temp.C_ANAME,temp.C_BNAME,temp.C_USETIME,
temp.C_MAXNUM,temp.C_REMAINNUM );
}
}while(flag);
printReturn("\n\t��ɳ�����Ϣ���£��س�������");
};
void mainmenu()
{
while(1)
{
char select;
do{
system("cls");//����
printf("\n\t �q�T�T�T�T�T�T�T�T�T���������T�T�T�r");
printf("\n\t�� �𳵰��ϵͳ ��");
printf("\n\t�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�s");
printf("\n\t ������������������������������������");
printf("\n\t ��1.¼���� ��");
printf("\n\t ��2.������а�� ��");
printf("\n\t ��3.ͨ����κŲ�·�� ��");
printf("\n\t ��4.ͨ���յ�վ��·�� ��");
printf("\n\t ��5.���򱣴� ��");
printf("\n\t ��6.��Ʊ ��");
printf("\n\t ��7.��Ʊ ��");
printf("\n\t ��8.���³�����Ϣ ��");
printf("\n\t ��0.�˳���¼ ��");
printf("\n\t ������������������������������������");
printf("\n\t ��ѡ��");
fflush(stdin);//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ.
select=getchar();//�ȴ��û���������
}while (select<'0'||select>'8');
switch(select)
{
case '0':exit(0);break;
case '1':infoinput();break;
case '2':queryallinfo();break;
case '3':queryinfobyID();break;
case '4':queryinfobyBNAME();break;
case '5':sortSave();break;
case '6':sale();break;
case '7':back();break;
case '8':update();break;
}
}
}
//������
int main()
{
initsystem(); //ϵͳ��ʼ��
while(1)
{
mainmenu();
}
}