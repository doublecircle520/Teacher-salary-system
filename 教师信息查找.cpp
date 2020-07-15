//查找指定部门信息
void searchnode1(struct node* headnode, char* depart)
{
	struct node* pmove = headnode->next;
	int num = 0;
	if (pmove == NULL)
	{
		printf("【链表为空，无法查找】\n");
		return;
	}
	sort(headnode);
	for (pmove = headnode->next; pmove != NULL; pmove = pmove->next)
	{
		if (strcmp(pmove->data.depart, depart) == 0)
		{
			if (num == 0)
			{
				printf("教师工号\t部门名称\t基本工资\t绩效工资\t职务工资\t扣款\t实发工资\n");
				num++;
			}
			printf("%s\t\t%s\t%d\t\t%d\t\t%d\t\t%d\t%d\n", pmove->data.num, pmove->data.depart, pmove->data.basepay, pmove->data.meritpay, pmove->data.jobpay, pmove->data.cutpay, pmove->data.finalpay);
		}
	}
	if (num == 0)
	{
		printf("【没有找到相关信息】");
	}
}
//查找指定教师信息
void searchnode(struct node* headnode, char* num)
{
	struct node* pmove = headnode->next;
	if (pmove == NULL)
	{
		printf("【链表为空，无法查找】\n");
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
		printf("教师工号\t部门名称\t基本工资\t绩效工资\t职务工资\t扣款\t实发工资\n");
		printf("%s\t\t%s\t%d\t\t%d\t\t%d\t\t%d\t%d\n", pmove->data.num, pmove->data.depart, pmove->data.basepay, pmove->data.meritpay, pmove->data.jobpay, pmove->data.cutpay, pmove->data.finalpay);
		return;
	}
	else
	{
		printf("【没有找到相关信息】\n");
		return;
	}
}