#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<conio.h>
//定义二维数组 
int arr[4][4]={}; 
int a=0;
//记录分数 
int score=0;
//记录是否产生移动
bool is_move=true; 
bool win=false;
void rand_two(void);
bool is_full(void);
void show(void);
void up(void); 
void down(void); 
void left(void); 
void right(void); 
bool is_die(void);

int main()
{
	srand(time(NULL));
	rand_two();
	show();
	while(1)
	{	
		int dir = getch();
		is_move=false;
		if(72 == dir)
		{
			up();
		}
		else if(80 == dir)
		{
			down();
		}
		else if(75 == dir)
		{
			left();
		}
		else if(77 == dir)
		{
			right();
		}
		system("cls");
		is_full();
		rand_two();
		show();
		if(is_die())
		{
			printf("\nyou lose");
			return 0;
		}	
		if(win)
		{
			printf("\nyou win");
			return 0;	
		}	
	}
}
bool is_full(void)
{
	for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(0 == arr[i][j])
				{
					return false;
				}
			}
		}
	return true;
}

void rand_two(void)
{
		for(;is_move;)
		{
			int x=rand()%4;
			int y=rand()%4;
			if(arr[x][y]==0)
			{
				arr[x][y]=2;
				return;
			}
		}

}

void show(void)
{	
	for(int i=0;i<4;i++)
	{	printf("---------------------\n");
		for(int j=0;j<4;j++)
		{	
			if(arr[i][j])
			{
				printf("|%4d",arr[i][j]);
			}
			else
			{
				printf("|    ");
			}
		
		}
			printf("|\n");
	}
	printf("---------------------\n");
	printf("得分： %d ",score);
}
void up(void)
{
	for(int j=0;j<4;j++)
	{
		int end=0;
		for(int b=1;b<4;b++)
		{	
			for(int i=b;i>end;i--)
			{	
				if(arr[i-1][j]==0&&arr[i][j]!=0)//如果第j列 第i-1行为0，但i行不是0，两个数字交换位置 
				{
					a=arr[i-1][j];
					arr[i-1][j]=arr[i][j];
					arr[i][j]=a;
					is_move=true;
				}			
				if(arr[i-1][j]==arr[i][j]&&arr[i-1][j]!=0)//第j列下面的和上面相同，则上面的变为和，下面变成0 ， 
				{
					arr[i-1][j]=arr[i-1][j]+arr[i][j];
					score+=arr[i-1][j]; 
					arr[i][j]=0;
					end=i;
					if(arr[i-1][j]==2048)
					{
						win=true;
					}
					else
					{
						is_move=true;
					}
				}
			}
		}
	}		
}

void down(void)
{
	for(int j=0;j<4;j++)//列 
	{
		int end=4;
		for(int b=3;b>0;b--)//行 
		{	
			for(int i=b;i<end;i++)
			{	
				if(arr[i][j]==0&&arr[i-1][j]!=0)//如果第j列 第i-1行为0，但i行不是0，两个数字交换位置 
				{
					a=arr[i][j];
					arr[i][j]=arr[i-1][j];
					arr[i-1][j]=a;
					is_move=true;
				}			
				if(arr[i-1][j]==arr[i][j]&&arr[i][j]!=0)//第j列下面的和上面相同，则上面的变为和，下面变成0 ， 
				{
					arr[i][j]=arr[i-1][j]+arr[i][j];
					score+=arr[i][j]; 
					arr[i-1][j]=0;
					end=i;
					if(arr[i][j]==2048)
					{
						win=true;
					}
					else
					{
						is_move=true;
					}
				}
			}
		}
	}		

}

void left(void)
{
	
	for(int j=0;j<4;j++)//行 
	{
		int end=0;
		for(int b=1;b<4;b++)//列 
		{	
			for(int i=b;i>end;i--)
			{	
				if(arr[j][i-1]==0&&arr[j][i]!=0)//如果第j列 第i-1行为0，但i行不是0，两个数字交换位置 
				{
					a=arr[j][i-1];
					arr[j][i-1]=arr[j][i];
					arr[j][i]=a;
					is_move=true;
				}			
				if(arr[j][i-1]==arr[j][i]&&arr[j][i-1]!=0)//第j列下面的和上面相同，则上面的变为和，下面变成0 ， 
				{
					arr[j][i-1]=arr[j][i-1]+arr[j][i];
					score+=arr[j][i-1]; 
					arr[j][i]=0;
					end=i;
					if(arr[j][i-1]==2048)
					{
						win=true;
					}
					else
					{
						is_move=true;
					}
				}
			}
		}
	}
	
	
}

void right(void)
{
	for(int j=0;j<4;j++)//列 
	{
		int end=4;
		for(int b=3;b>0;b--)//行 
		{	
			for(int i=b;i<end;i++)
			{	
				if(arr[j][i]==0&&arr[j][i-1]!=0)//如果第j列 第i-1行为0，但i行不是0，两个数字交换位置 
				{
					a=arr[j][i];
					arr[j][i]=arr[j][i-1];
					arr[j][i-1]=a;
					is_move=true;
				}			
				if(arr[j][i-1]==arr[j][i]&&arr[j][i]!=0)//第j列下面的和上面相同，则上面的变为和，下面变成0 ， 
				{
					arr[j][i]=arr[j][i-1]+arr[j][i];
					score+=arr[j][i]; 
					arr[j][i-1]=0;
					end=i;
					if(arr[j][i]==2048)
					{
						win=true;
					}
					else
					{
						is_move=true;
					}
				}
			}
		}
	}		

}

bool is_die(void)
{
	if(false== is_full())
	{
		return false;
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i][j]==arr[i][j+1])
			{
				return false;
			}
		}
	}
	
		for(int j=0;j<4;j++)
	{
		for(int i=0;i<3;i++)
		{
			if(arr[i][j]==arr[i+1][j])
			{
				return false;
			}
		}
	}
}

