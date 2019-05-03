#include<iostream>
using namespace std;
# define MAX 10
 
class node
{
	public:
		int data;
		node *add;
		node()
		{
			add=NULL;
		}
};
class lgraph
{
	//public:
	protected:
	int i,j,ver1,ver2;
	public:
		int d[10][10],ver;
		node *head[MAX];
		int ele;
		lgraph()
		{
			for(i=0;i<MAX;i++)
			{
				head[i]=NULL;
			}
		}
		void get();
		void display();
		void getdata();
		void adjmatrix();
};
void lgraph::get()
{
	node *prev;
	cout<<"\n Enter Total Number Of Vertices: ";
	cin>>ver1;
	for(i=0;i<ver1;i++)
	{
 
	cout<<"\n Enter Total Number Of Vertex Which Are Attached To vertex 
					"<<i+1<<" : ";
	
		cin>>ver2;
		for(j=0;j<ver2;j++)
		{
			cout<<"\n Enter Vertex which is attached to  vertex 
					"<<i+1<<" : ";
 
			cin>>ele;
			if(head[i]==NULL)
			{
				node *newnode;
				newnode=new node;
				newnode->data=ele;
				newnode->add=NULL;
				head[i]=newnode;
				//head=newnode;
				prev=head[i];
			}
			else
			{
				node *newnode;
				newnode=new node;
				newnode->data=ele;
				newnode->add=NULL;
				prev->add=newnode;
				prev=newnode;
			}
		}
	}
}
void lgraph::display()
{
	node *temp1;
	cout<<"\n\n\n Using Adjency list\n";
	for(i=0;i<ver1;i++)
	{
		cout<<"s["<<i+1<<"] -->";
		temp1=head[i];
		while(temp1->add!=NULL)
		{
			cout<<"s["<<temp1->data<<"]-->";
			temp1=temp1->add;
		}
		cout<<"s["<<temp1->data<<"]";
		cout<<"\n";
	}
}
void lgraph::getdata()
{
	//int i,j;
	cout<<"\n Enter Total Of Vertices: ";
	cin>>ver;
	for(i=1;i<=ver;i++)
	{
		for(j=i+1;j<=ver;j++)
		{
			cout<<"\n Enter Distance Between "<<i<<" and 
								"<<j<<": ";
			cin>>d[i][j];
			d[j][i]=d[i][j];
		}
	}
}
void lgraph::adjmatrix()
{
	//int i,j;
	cout<<"\n\n\n Using Adjency matrix\n";
	for(i=1;i<=ver;i++)
	{
		cout<<"\t"<<i;
	}
	cout<<"\n";
	for(i=1;i<=ver;i++)
	{
		cout<<i;
		for(j=1;j<=ver;j++)
		{
			cout<<"\t"<<d[i][j];
		}
		cout<<"\n ";
	}
}
class graph : public lgraph
{
	public:
 
 
	//public:
 
		graph()
		{
			for( i=0, j=0;i<10,j<10;i++,j++)
			{
				d[i][j]=0;
			}
		}
 
};
int main()
{
	graph g;
	char ans;
	int ch;
	double execution_time;
	clock_t time;
	do
	{
		cout<<"\n MENU:\n 1.Using Adjency Matrix\n 
				      2.Using Adjency List\n 
				      3.Runtime of Adjency matrix\n 
				      4.Runtime of Adjency list\n 
					Enter Your Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g.getdata();
				g.adjmatrix();
				break;
			case 2:
				g.get();
				g.display();
				break;
			case 3:
 
				time=clock();
				g.getdata();
				time=clock()-time;
				execution_time=(double(time))/CLOCKS_PER_SEC;
		cout<<"\nTime of execution of function input_graph_matrix() 
				is:\t"<<execution_time<<" sec\n\n";
				break;
			case 4:
 
				time=clock();
				g.get();
				time=clock()-time;
				execution_time=(double(time))/CLOCKS_PER_SEC;
		cout<<"\nTime of execution of function input_graph_matrix() 
					is:\t"<<execution_time<<" sec\n\n";
				break;
			default:
				cout<<"\n Enter Correct option";
		}
		cout<<"\n Do You Want To Continue(y/n): ";
		cin>>ans;
	}
	while(ans=='y');
}