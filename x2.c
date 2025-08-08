#include<stdio.h>
#include<ctype.h>
#define size 5
int s[size];
int top=-1;
void push(int x)
{
   if(top==size-1)
   {
       printf("overflow");
   }
    else
    {
        top++;
        s[top]=x;
    }
}
void pop()
{
   if(top==-1)
   {
       printf("underflow");
   }
   else
   {
       printf("deleted items is %d",s[top]);
       top--;
   }
}
void peek()
{
    if(top==-1)
    {
        printf("underflow");
    }
    else
    {
        printf("the item at the top is %d",s[top]);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\n stack is empty");
    }

    else
    {
        for(i=top;i>=0;i--)
            {
			 printf("%d ",s[i]);
		    }
    }
}
void main()
{
    int ch,x;
    do
    {
        printf("\n 1.push\n2.pop\n3.peek.\n4.display.\n5.exit\n");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
         case 1:printf("\n enter item to inseretd into stack");
                scanf("%d",&x);
                push(x);
                break;
         case 2:
               pop();
               break;
         case 3:
               peek();
               break;
         case 4:
               display();
               break;
        }
    }while(ch!=5);
} 
