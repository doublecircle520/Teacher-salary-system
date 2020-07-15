#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct teacher
{
	char num[10];//��ʦ����
	char depart[20];//��������
	int basepay;//��������
	int meritpay;//��Ч����
	int jobpay;//ְ����
	int cutpay;//�ۿ�
	int finalpay;//ʵ������
};
struct node
{
	struct teacher data;
	struct node* next;
};
struct node* createlist()//��������
{
	struct node* headnode = (struct node*)malloc(sizeof(struct node));
	//��ͷ����������data������ʼ��
	headnode->next = NULL;
	return headnode;
}
struct node* list = createlist();
struct node* createnode(struct teacher data)//�������
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->data.finalpay = newnode->data.basepay + newnode->data.meritpay + newnode->data.jobpay - newnode->data.cutpay;
	newnode->next = NULL;
	return newnode;
}
void sort(struct node*headnode)//���������ݽ�������ʵ�����ʣ�
{
	struct node* p = headnode->next;
	struct node* q = headnode->next;
	struct teacher teacher1;
	for (; p->next; p = p->next) { // ȷ���Ƚϴ���

		for (q = headnode->next; q->next; q = q->next) {
			if (q->data.finalpay > q->next->data.finalpay) {

				teacher1= q->data;
				q->data = q->next->data;
				q->next->data = teacher1;
			}
		}

	}
}
void printlist(struct node* headnode)//��ӡ������
{
	struct node* pmove = headnode->next;
	printf("��ʦ����\t��������\t��������\t��Ч����\tְ����\t�ۿ�\tʵ������\n");
	sort(headnode);
	pmove = headnode->next;
	while (pmove!=NULL)
	{
		printf("%s\t\t%s\t%d\t\t%d\t\t%d\t\t%d\t%d\n", pmove->data.num, pmove->data.depart, pmove->data.basepay, pmove->data.meritpay, pmove->data.jobpay, pmove->data.cutpay, pmove->data.finalpay );
		pmove = pmove->next;
	}
	printf("\n");
}
void insertnode(struct node* headnode, struct teacher data)//������(ͷ�巨)
{
	struct node* newnode = createnode(data);
	newnode->next = headnode->next;
	headnode->next = newnode;
}
void deleatnode1(struct node* headnode, char* depart)//����ɾ����Ϣ
{
	struct node* posnode = headnode->next;
	struct node* frontnode = headnode;
	int flag=0;
	if (posnode == NULL)
	{
		printf("������Ϊ�գ��޷�ɾ����\n");
		return;
	}
	printf("%s", depart);
	system("pause");
	while(posnode!=NULL)
	{
		if (strcmp(posnode->data.depart, depart) == 0)
		{
			frontnode->next = posnode->next;
			free(posnode);
			flag++;
			posnode = frontnode->next;
		}
		else
		{
			frontnode = posnode;
			posnode = frontnode->next;
		}
	}
	if (flag == 0)
	{
		printf("δ�ҵ�%s��ʦ��Ϣ",depart);
	}
	else
	{
		printf("%s��ʦ��Ϣɾ���ɹ�", depart);
	}
}
void deleatnode(struct node* headnode,char*num)//ɾ�����
{
	struct node* posnode = headnode->next;
	struct node* frontnode = headnode;
	if (posnode == NULL)
	{
		printf("������Ϊ�գ��޷�ɾ����\n");
		return;
	}
	while (strcmp(posnode->data.num,num))
	{
		frontnode = posnode;
		posnode = frontnode->next;
		if (posnode == NULL)
		{
			printf("��δ�ҵ�ָ��λ�ã��޷�ɾ����\n");
			return;
		}
	}
	frontnode->next = posnode->next;
	free(posnode);
	printf("��ָ����Ϣɾ���ɹ���\n");
}
void searchnode1(struct node* headnode, char* depart)//�������(�������Ʋ���)
{
	struct node* pmove = headnode->next;
	int num = 0;
	if (pmove == NULL)
	{
		printf("������Ϊ�գ��޷����ҡ�\n");
		return;
	}
	for (pmove = headnode->next; pmove != NULL; pmove = pmove->next)
	{
		if (strcmp(pmove->data.depart, depart) == 0)
		{
			if (num == 0)
			{
				printf("��ʦ����\t��������\t��������\t��Ч����\tְ����\t�ۿ�\tʵ������\n");
				num++;
			}
			printf("%s\t\t%s\t%d\t\t%d\t\t%d\t\t%d\t%d\n", pmove->data.num, pmove->data.depart, pmove->data.basepay, pmove->data.meritpay, pmove->data.jobpay, pmove->data.cutpay, pmove->data.finalpay);
		}
	}
	if (num==0)
	{
		printf("��û���ҵ������Ϣ��");
	}
}
void searchnode(struct node* headnode, char* num)//�������(���Ų���)
{
	struct node* pmove = headnode->next;
	if (pmove == NULL)
	{
		printf("������Ϊ�գ��޷����ҡ�\n");
		return;
	}
	while (strcmp(pmove->data.num, num))
	{
		pmove = pmove->next;
		if (pmove == NULL)
			break;
	}
	if (pmove)
	{
		printf("��ʦ����\t��������\t��������\t��Ч����\tְ����\t�ۿ�\tʵ������\n");
		printf("%s\t\t%s\t%d\t\t%d\t\t%d\t\t%d\t%d\n", pmove->data.num, pmove->data.depart, pmove->data.basepay, pmove->data.meritpay, pmove->data.jobpay, pmove->data.cutpay, pmove->data.finalpay);
		return;
	}
	else
	{
		printf("��û���ҵ������Ϣ��\n");
		return;
	}
}
void changenode(struct node* headnode, char* num)
{
	struct node* pmove = headnode->next;
	if (pmove == NULL)
	{
		printf("������Ϊ�գ������޸ġ�\n");
		return;
	}
	while (strcmp(pmove->data.num, num))
	{
		pmove = pmove->next;
		if (pmove == NULL)
			break;
	}
	if (pmove)
	{
		printf("�������޸���Ϣ\n");
		scanf("%s%s%d%d%d%d", pmove->data.num, pmove->data.depart, &pmove->data.basepay, &pmove->data.meritpay, &pmove->data.jobpay, &pmove->data.cutpay);
		printf("���޸���Ϣ�ɹ���\n");
		return;
	}
	else
	{
		printf("���������Ϣ���޷��޸ġ�\n");
		return;
	}
}
void upbasepay(struct node*headnode, char*depart, int up)
{
	int flag = 0;
	struct node* movenode = headnode->next;
	while (movenode != NULL)
	{
		if (strcmp(movenode->data.depart, depart) == 0)
		{
			movenode->data.basepay = movenode->data.basepay + up;
			flag++;
		}
		movenode = movenode->next;
	}
	if (flag == 0)
	{
		printf("δ�ҵ���ز�����Ϣ��\n");
	}
	else
	{
		printf("%s %d����ʦ���������޸���ϡ�\n",depart,flag);
	}
}
void upjobpay(struct node* headnode, int merit, int up)
{
	int flag = 0;
	struct node* movenode = headnode->next;
	while (movenode != NULL)
	{
		if (movenode->data.meritpay > merit|| movenode->data.meritpay == merit)
		{
			movenode->data.jobpay= movenode->data.jobpay + up;
			flag++;
		}
		movenode = movenode->next;
	}
	if (flag == 0)
	{
		printf("��Ч������н��׼���ߣ�δ���ҵ��������� ��\n");
	}
	else
	{
		printf("��Ϊ%d�������ʦ���ְ����.\n", flag);
	}
}
void writeExcel(struct node *headnode,char* num)//����ָ����ʦ���ʱ���
{
	FILE* fp = NULL;
	struct node* movenode=headnode->next;
	fp = fopen("D:\\test.xls", "w");
	while (movenode != NULL)
	{
		if (strcmp(movenode->data.num, num) == 0)
		{
			fprintf(fp, "��ʦ����\t��������\t��������\t��Ч����\tְ����\t�ۿ�\tʵ������\n");
			fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d", movenode->data.num, movenode->data.depart, movenode->data.basepay, movenode->data.meritpay, movenode->data.jobpay, movenode->data.cutpay, movenode->data.finalpay);
		}
		movenode = movenode->next;
	}
	printf("���ʱ������ɳɹ���\n");
	fclose(fp);
}
void writeExcel1(struct node* headnode, char* depart)//����ָ�����Ź��ʱ���
{
	FILE* fp = NULL;
	int flag=0;
	struct node* movenode = headnode->next;
	fp = fopen("D:\\test.xls", "w");
	while (movenode != NULL)
	{
		if (strcmp(movenode->data.depart, depart) == 0)
		{
			if (flag == 0)
			{
				fprintf(fp, "��ʦ����\t��������\t��������\t��Ч����\tְ����\t�ۿ�\tʵ������\n");
				fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", movenode->data.num, movenode->data.depart, movenode->data.basepay, movenode->data.meritpay, movenode->data.jobpay, movenode->data.cutpay, movenode->data.finalpay);
				flag++;
			}
			else
			{
				fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", movenode->data.num, movenode->data.depart, movenode->data.basepay, movenode->data.meritpay, movenode->data.jobpay, movenode->data.cutpay, movenode->data.finalpay);
			}
		}
		movenode = movenode->next;
	}
	printf("%s���ʱ������ɳɹ���\n",depart);
	fclose(fp);
}
void writeExcel2(struct node* headnode)//��ӡ���н�ʦ���ʱ���
{
	FILE* fp = NULL;
	int flag = 0;
	struct node* movenode = headnode->next;
	fp = fopen("D:\\test.xls", "w");
	while (movenode != NULL)
	{
			if (flag == 0)
			{
				fprintf(fp, "��ʦ����\t��������\t��������\t��Ч����\tְ����\t�ۿ�\tʵ������\n");
				fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", movenode->data.num, movenode->data.depart, movenode->data.basepay, movenode->data.meritpay, movenode->data.jobpay, movenode->data.cutpay, movenode->data.finalpay);
				flag++;
			}
			else
			{
				fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\n", movenode->data.num, movenode->data.depart, movenode->data.basepay, movenode->data.meritpay, movenode->data.jobpay, movenode->data.cutpay, movenode->data.finalpay);
			}
		movenode = movenode->next;
	}
	printf("ȫ����ʦ���ʱ������ɳɹ���\n" );
	fclose(fp);
}
//�ļ�������
void readfile(struct node* headnode, char* filename)
{
	//���ļ�
	FILE* fp;
	struct teacher data;
	fp = fopen(filename, "r");
	//���ļ�
	while (!feof(fp))
	{
		fscanf(fp, "%s\t%s\t%d\t%d\t%d\t%d\n", data.num, data.depart, &data.basepay, &data.meritpay, &data.jobpay, &data.cutpay);
		insertnode(list, data);
	}
	/*while (fscanf(fp, "%s\t%s\t%d\t%d\t%d\t%d\n", data.num, data.depart, &data.basepay, &data.meritpay, &data.jobpay, &data.cutpay));
	{
		insertnode(list, data);
	}*/
	//�ر��ļ�
	fclose(fp);
}
//�ļ�д����
void writefile(struct node* headnode, char* filename)
{
	FILE* fp;
	fp = fopen(filename, "w");
	struct node* pmove = headnode->next;
	while (pmove!=NULL)
	{
		fprintf(fp, "%s %s %d %d %d %d %d\n", pmove->data.num, pmove->data.depart, pmove->data.basepay, pmove->data.meritpay, pmove->data.jobpay, pmove->data.cutpay, pmove->data.finalpay);
		pmove = pmove->next;
	}
	fclose(fp);
}
void menu()//�˵�����
{
	printf("-------------��ʦ���ʹ���ϵͳ-----------------\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.¼����Ϣ\n");
	printf("\t\t2.�����Ϣ\n");
	printf("\t\t3.������Ϣ\n");
	printf("\t\t4.ɾ����Ϣ\n");
	printf("\t\t5.�޸���Ϣ\n");
	printf("\t\t6.��������\n");
	printf("\t\t7.��ӡ����\n");
	printf("----------------------------------------------\n");
}
//struct node* list = createlist();
void keydown()//�û���������
{
	int up;//�����Ƿ�
	int merit;//���ż�Ч���ʱ�׼
	int choice;//���幦�ܱ��
	int choice1;//����������������
	int choice2;//���������޸ķ�ʽ
	int search;//������ҷ�ʽ
	char bbnum[20],bbdepart[20];//�����ӡ�����ʦ��š������ӡ����
	char pldepart[20];//������������Ĳ���
	char searchnum[20],searchdepart[20],changenum[20];//������ҵĹ��š����ҵĲ��š����޸ĵĽ�ʦ����
	printf("�����빦�ܱ�ţ�\n");
	struct teacher data;
	scanf("%d", &choice);
	switch (choice)
	{
	case 0:
		printf("��ϵͳ�����˳�����ӭ���´�ʹ�á�\n");
			system("pause");
			exit(0);
		break;
	case 1:
		printf("\t\t����ӭ����¼����Ϣģ�顿\n");
		printf("�������ʦ��Ϣ��\n");
		scanf("%s%s%d%d%d%d", data.num, data.depart, &data.basepay, &data.meritpay, &data.jobpay, &data.cutpay);
		insertnode(list, data);
		break;
	case 2:
		printf("\t\t����ӭ������Ϣ���ģ�顿\n");
		printlist(list);
		break;
	case 3:
		printf("\t\t����ӭ������Ϣ����ģ�顿\n");
		printf("����ѡ����ҷ�ʽ��\n");
		printf("1.��ʦ���Ų���\t2.�������Ų���\n");
		scanf("%d", &search);
		switch (search)
		{
		case 1:
			printf("��������Ҫ���ҵĽ�ʦ���ţ�\n");
				scanf("%s",searchnum);
				searchnode(list, searchnum);
			break;
		case 2:
			printf("��������Ҫ���ҵĲ������ƣ�\n");
			scanf("%s", searchdepart);
			searchnode1(list, searchdepart);
			break;
		default :
			printf("������ѡ�����������������롿\n");
			system("pause");
			break;
		}
		break;
	case 4:
		printf("\t\t����ӭ������Ϣɾ��ģ�顿\n");
		printf("������ɾ���Ľ�ʦ����:\n");
		scanf("%s", data.num);
		deleatnode(list, data.num);
		break;
	case 5:
		printf("\t\t����ӭ������Ϣ�޸�ģ�顿\n");
		printf("���������޸ĵĽ�ʦ����\n");
		scanf("%s", changenum);
		changenode(list, changenum);
		break;
	case 6:
		printf("--------[��������ģ��]--------\n");
		printf("\t1.���������Ϣ\n\t2.����ɾ����Ϣ\n\t3.�����޸���Ϣ\n");
		printf("------------------------------\n");
		printf("�����빦�ܱ��: \n");
		scanf("%d", &choice1);
		switch (choice1)
		{
		case 1:
			printf("\t\t�����������Ϣ��\n");
			printf("��������Ҫ����Ĳ��ţ�\n");
			scanf("%s", pldepart);
			searchnode1(list, pldepart);
			break;
		case 2:
			printf("\t\t������ɾ����Ϣ��\n");
			printf("��ѡ����Ҫɾ���Ĳ��� \n");
				scanf("%s", pldepart);
			deleatnode1(list, pldepart);
			break;
		case 3:
			printf("\t\t�������޸���Ϣ��\n");
			printf("��ѡ���޸ķ�ʽ��\n");
			printf("1.�����Ž����޸�  2.����Ч���ʽ����޸� \n");
			printf("�����빦�ܱ�ţ� \n");
			scanf("%d", &choice2);
			switch (choice2)
			{
			case 1:
				printf("�����벿�����ƣ�\n");
				scanf("%s", pldepart );
				printf("���Ż��������Ƿ���\n");
				scanf("%d", &up);
				 upbasepay(list, pldepart, up);
				break;
			case 2:
				printf("���������ż�Ч���ʱ�׼�� \n");
				scanf("%d", &merit);
				printf("������ְ�����Ƿ��� \n");
				scanf("%d", &up);
				upjobpay(list, merit, up);
				break; 
			default:
				printf("������ѡ�����������������롿\n");
				system("pause");
				break;
			}
			break;
		}
		break;
	case 7:
		printf("--------[�����ӡģ��]--------\n");
		printf("\t1.ָ����ʦ�����ӡ\n\t2.ָ�����ű����ӡ\n\t3.ȫ����Ϣ�����ӡ\n");
		printf("------------------------------\n");
		printf("�����빦�ܱ��: \n");
		scanf("%d", &choice1);
		switch (choice1)
		{
		case 1:
			printf("�������ʦ���ţ� \n");
			scanf("%s", bbnum);
			writeExcel(list, bbnum);
			break;
		case 2:
			printf("�����벿�����ƣ� \n");
			scanf("%s", bbdepart);
			writeExcel1(list, bbdepart);
			break;
		case 3:
			writeExcel2(list);
			break;
		default:
			printf("�����빦�ܱ���������������롿\n");
			system("pause");
			break;
		}
		printf("�������ʦ���ţ� \n");
		scanf("%s", bbnum);
		writeExcel(list,bbnum);
		break;
	default:
		printf("�����빦�ܱ���������������롿\n");
		system("pause");
		break;
	}
	writefile(list, "2.txt");
}
int main()
{
	readfile(list,"1.txt");
	while (1)
	{
     menu();
	 keydown();
	 system("pause");
	 system("cls");//����
	}
	system("pause");
	return 0;
}