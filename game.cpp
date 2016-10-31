#include <bits/stdc++.h>
using namespace std;
int score=0;
int board[4][4];
bool b[4][4];
int upper(int n)
{
	int coun=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(board[j][i]!=0){
				if(board[k][i]==0)
					continue;
				else if(board[k][i]==board[j][i] and board[k][i]!=0)
				{
					board[j][i]+=board[k][i];
					board[k][i]=0;
					score+=board[j][i];
					break;
				}
				
				else if(board[j+1][i]==0 and board[k][i]!=0)
				{
					
						board[j+1][i]=board[k][i];
						board[k][i]=0;
					    j++;

					
					
				}
				else 
				{
					board[j+1][i]=board[k][i];
					j++;
				}
			}
				else

				{
					if(board[k][i]!=0)
						{
							board[j][i]=board[k][i];
							board[k][i]=0;
						}
						else continue;
				}

			}

		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==0)
			 {
			 	b[i][j]=false;
			 }
			 else
			 	{
			 		b[i][j]=true;
			 		coun++;
			 	}
		}
	}
	return coun;
}
int down(int n)
{
	int coun=0;
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>0;j--)
		{
			for(int k=j-1;k>=0;k--)
			{
				if(board[j][i]!=0){
				if(board[k][i]==0)
					continue;
				else if(board[k][i]==board[j][i] and board[k][i]!=0)
				{
					board[j][i]+=board[k][i];
					board[k][i]=0;
					score+=board[j][i];
					break;
				}
				
				else if(board[j-1][i]==0 and board[k][i]!=0)
				{
					board[j-1][i]=board[k][i];
					board[k][i]=0;
					j--;


				}
				else
				{
					board[j-1][i]=board[k][i];
					//board[k][i]=0;
					j--;
				}
			}
				else
				{
					if(board[k][i]!=0)
						{
							board[j][i]=board[k][i];
							board[k][i]=0;
						}
						else
							continue;
				}

			}

		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==0)
			 {
			 	b[i][j]=false;
			 }
			 else
			 	{
			 		b[i][j]=true;
			 		coun++;
			 	}
		}
	}
	return coun;
}
int left(int n)
{
	int coun=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(board[i][j]!=0){
				if(board[i][k]==0)
					continue;
				else if(board[i][j]==board[i][k] and board[i][k]!=0)
				{
					board[i][j]+=board[i][k];
					board[i][k]=0;
					score+=board[i][j];
					break;
				}
				
				else if(board[i][j+1]==0 and board[i][k]!=0)
				{
					board[i][j+1]=board[i][k];
					board[i][k]=0;
					j++;


				}
				else
				{
					board[i][j+1]=board[i][k];
					j++;


				}
			}
				else
				{
					if(board[i][k]!=0)
						{
							board[i][j]=board[i][k];
							board[i][k]=0;
						}
						else continue;
				}

			}

		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==0)
			 {
			 	b[i][j]=false;
			 }
			 else
			 	{
			 		b[i][j]=true;
			 		coun++;
			 	}
		}
	}
	return coun;
}
int right(int n)
{
	int coun=0;
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>0;j--)
		{
			for(int k=j-1;k>=0;k--)
			{
				if(board[i][j]!=0){
				if(board[i][k]==0)
					continue;
				else if(board[i][j]==board[i][k] and board[i][k]!=0)
				{
					board[i][j]+=board[i][k];
					board[i][k]=0;
					score+=board[i][j];
					break;
				}
				
				else if(board[i][j-1]==0 and board[i][k]!=0) 
				{
					board[i][j-1]=board[i][k];
					board[i][k]=0;
					j--;


				}
				else 
				{
					board[i][j-1]=board[i][k];
					
					j--;


				}
			}
				else
				{
					if(board[i][k]!=0)
						{
							board[i][j]=board[i][k];
							board[i][k]=0;
						}
						else
							continue;
				}

			}

		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==0)
			 {
			 	b[i][j]=false;
			 }
			 else
			 	{
			 		b[i][j]=true;
			 		coun++;
			 	}
		}
	}
	return coun;
}
int main()
{
	int n;
	n=4;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j]=0;
			b[i][j]=false;
		}
	}
	int count=0;
	while(count!=(n*n))
	{
		tr:int a=rand()%5;
		if(a!=2 and a!=4)
			a=2;
		int p=rand()%n;
		int q=rand()%n;
		if(b[p][q]==false)
		{
			board[p][q]=a;
			b[p][q]=true;
			count++;
		}
		else
			goto tr;

		cout<<"YOUR SCORE IS "<<score<<endl;

		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<"   ";
		}
		cout<<endl;
	}
		LOOP:cout<<"U for up::D for down::L for left::R for right"<<endl;
		char c;
		cin>>c;
		if(c=='U' or c=='u')
		{
			count=upper(4);
		}
		else if(c=='D' or c=='d')
		{
			count=down(4);
		}
		else if(c=='L' or c=='l')
		{
			count=left(4);
		}
		else if(c=='R' or c=='r')
		{
			count=right(4);
		}
		else
			goto LOOP;


	}
	cout<<"YOUR SCORE IS "<<score<<endl;

}