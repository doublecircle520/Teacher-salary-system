//����ָ��������Ϣ
void searchnode1(struct node* headnode, char* depart)
{
	struct node* pmove = headnode->next;
	int num = 0;
	if (pmove == NULL)
	{
		printf("������Ϊ�գ��޷����ҡ�\n");
		return;
	}
	sort(headnode);
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
	if (num == 0)
	{
		printf("��û���ҵ������Ϣ��");
	}
}
//����ָ����ʦ��Ϣ
void searchnode(struct node* headnode, char* num)
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