#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fpi, *fps, *fpd, *fpq;
	fpi = fopen(argv[1],"r");							//opening input file to read
	fpd = fopen("dll.txt", "w");
	fpq = fopen("queue.txt", "w");
	fps = fopen("stack.txt", "w");
	char s[10];
	//printf("%s", argv[2]);
	int size = atoi(argv[2]);							//maximum stack size
	//printf("%d\n", size);
	int stack_size = 0;									
	int stack[size];
	int queue[size+1];
	int qhead = 0;
	int qtail = 0;
	while(fgets(s,10,fpi)!=NULL)
	{
		//printf("input1\n");
		int count = 0,num;
		
		char c = s[0];
		switch (c)
		{
			case '!':
				//printf("stack !\n");
				if(stack_size>0)
				{
					printf("stack_size = %d\n", stack_size);
					for(int i = stack_size-1; i >= 0; i--)
					{
						printf("i = %d ", i);
						printf("%d ",stack[i]);
						fprintf(fps,"%d ",stack[i]);
					}
					printf("\n");
					fprintf(fps,"\n");
				}
				else
					fprintf(fps,"\n");
				break;
			case '+':
				//printf("stack +\n");
				num = atoi(s+2);
				if(stack_size<size)
				{
					stack[stack_size] = num;
					stack_size++;
					//printf("%d ", stack[stack_size-1]);
					fprintf(fps, "pushed %d\n",stack[stack_size-1]);
				}
				else
					fprintf(fps,"overflow\n");
				break;
			case '-':
				//printf("stack -\n");
				if(stack_size>0)
				{
					fprintf(fps, "popped %d\n",stack[stack_size-1]);
					stack_size--;
				}
				else
					fprintf(fps, "underflow\n");
				break;
			case '?':
				//printf("stack ?\n");
				num = atoi(s+2);
				while(count<=stack_size)
				{
					if(stack[count]==num)
					{
						fprintf(fps, "found %d\n", num);
						break;
					}
					count++;
				}
				if(count>stack_size)
				{
					fprintf(fps, "not found %d\n", num);
				}
				break;
		}
	}
	
	fclose(fpi);
	fpi = fopen(argv[1],"r");
	while(fgets(s,10,fpi)!=NULL)
	{
		int count = 0,num;
		//printf("input2\n");
		char c = s[0];
		switch (c)
		{
			case '!':
				//printf("queue !\n");
				//printf("qtail = %d\n", qtail);
				//printf("qhead = %d\n", qhead);
				if(qhead!=qtail)
				{
					int i = qhead;
					while(i!=qtail)
					{
						//printf("%d ",queue[i]);
						fprintf(fpq,"%d ",queue[i]);
						i++;
						i = i%size;
					}
					//printf("\n");
					fprintf(fpq,"\n");
				}
				else
					fprintf(fpq,"\n");
				break;
			case '+':
				//printf("queue +\n");
				num = atoi(s+2);
				if(qhead!=(qtail+1)%size)
				{
					queue[qtail] = num;
					qtail = (qtail + 1)%size;
					fprintf(fpq, "enqueued %d\n",num);
					//printf("enqueued %d\n",num);
				}
				else
					fprintf(fpq,"overflow\n");
				break;
			case '-':
				//printf("queue -\n");
				if(qhead!=qtail)
				{
					fprintf(fpq, "dequeued %d\n",queue[qhead]);
					qhead = (qhead + 1)%size;
				}
				else
					fprintf(fpq, "underflow\n");
				break;
			case '?':
				//printf("queue ?\n");
				num = atoi(s+2);
				int j = qhead;
				while(j!=qtail)
				{
					if(queue[j]==num)
					{
						//printf("found %d\n",num);
						fprintf(fpq, "found %d\n", num);
						break;
					}
					count++;
					j++;
					j = j%size;
				}
				if(count>qtail)
				{
					fprintf(fpq, "not found %d\n", num);
				}
				break;
		}
	}
	fclose(fpi);



struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};


//	FILE *fpi, *fpd;
	fpi = fopen(argv[1], "r");
	//fpd = fopen("dll.txt", "w");
	//char s[10];
	//new_node->prev = NULL;	
	//new_node->next = NULL;
	struct Node* head = NULL;
	struct Node* del;
	struct Node* node1;
	struct Node* node2;
	struct Node* node3;
	while((fgets(s,10,fpi))!=NULL)
	{
		int num = atoi(s+2);
		char c = s[0];
		struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
		switch (c)
		{
			case '+':
	   
				//new_node = (struct Node*)malloc(sizeof(struct Node));
				new_node->next = head;
				new_node->data = num;
				new_node->prev = NULL;
				if((head)!=NULL)
					(head)->prev = new_node;
				(head) = new_node;
				//printf("inserted %d\n", num);
				fprintf(fpd,"inserted %d\n", num);
				break;




			case '-':

				node1 = head;
				while(node1!=NULL)
				{
				  if(node1->data==num)
				  {
						//printf("deleted %d\n", num);
						del = node1;
					if(del==(head) && del->next==NULL)
							head = NULL;
					else if(del==(head))
					{
						//printf("deleted %d\n", num);
						del->next->prev = NULL;
						head = del->next;
					}
					else if(del->next == NULL)
					{
						del->prev->next = NULL;
					}
					else
					{
						del->next->prev = del->prev;
						del->prev->next = del->next;
					}
					//printf("deleted %d\n", num);
					fprintf(fpd,"deleted %d\n", num);
					break;
				  }
				node1 = node1->next;
				}
				if(node1==NULL)
				{
				//printf("cannot delete %d\n", num);
				fprintf(fpd,"cannot delete %d\n", num);
				}
				//free(del);
				break;





				case '!':
					//struct Node* node2;
					node2 = head;
					while(node2!=NULL)
					{
						//printf("%d ", node2->data);
						fprintf(fpd,"%d ", node2->data);
						node2 = node2->next;
					}
					//printf("\n");
					fprintf(fpd,"\n");
					break;




				case '?':
					//struct Node* node3;
					node3 = head;
					while(node3!=NULL)
					{
						if(node3->data==num)
						{
							//printf("found %d\n",num);
							fprintf(fpd,"found %d\n",num);
							break;
						}
							node3 = node3->next;
					}
						if(node3==NULL)
						{
							//printf("NOT FOUND %d\n",num);
							fprintf(fpd,"NOT FOUND %d\n",num);
						}
					break;
				}
	}
}
