#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int a[21][12], b, c, d, e, r, f, x, y, z, j, k, m, n, temp, r, r1, score=0, level=1, s=0, bestscore, color, h;
char g;
void gotoxy(int x, int y);
void reset_z(void);void reset_o(void);
int check_fliction(void);void check_left_fliction(void);void check_right_fliction(void);
void CursorView(char show);
void check_clear(void);
void game_over(void);
void pause_p(void);
void fileopen_rt(void);
void fileopen_wt(void);

int main(void)
{
    fileopen_rt();
    srand((unsigned)time(NULL));
    CursorView(0);
    system("cls");
	color=1;
	while(kbhit()==0){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color%16);	if(kbhit()) break;
	gotoxy(0,0);printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣");Sleep(100);if(kbhit()) break;
    gotoxy(0,1);printf("▣■■■□□□■■■□□□■■■□■■■■▣");Sleep(100);if(kbhit()) break;
    gotoxy(0,2);printf("▣□■□■■■□■□■■□□■□□■□□□▣");Sleep(100);if(kbhit()) break;
    gotoxy(0,3);printf("▣□■□■□□□■□■□■□■□□■■■■▣");Sleep(100);if(kbhit()) break;
    gotoxy(0,4);printf("▣□■□■■■□■□■■□■■■□□□□■▣");Sleep(100);if(kbhit()) break;
    gotoxy(0,5);printf("▣□□□■□□□□□■□■□□□□■■■■▣");Sleep(100);if(kbhit()) break;
	gotoxy(0,6);printf("▣□□□■■■□□□■□■□□□□□□□□▣");Sleep(100);if(kbhit()) break;
	gotoxy(0,7);printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣");Sleep(100);if(kbhit()) break;
    gotoxy(0,8);printf("                           made by leesu0605");Sleep(100);if(kbhit()) break;
	gotoxy(9,11);printf("press any key to start");
	for(z=0;z<50;z++){
		Sleep(30);if(kbhit()){y=1;break;}
	}
			color++;
			if(color%16==0)
				color++;
			if(y==1)
				break;
	}
	h=getch();
    system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    for(b=0;b<21;b++)
    {
        a[20][b/2]=1;
        a[b][0]=1;
        a[b][11]=1;
        for(c=0;c<12;c++)
            if(a[b][c]==1)
                printf("▩");
            else
                printf("  ");
        printf("\n");
    }
    gotoxy(24, 3);
    printf("---------------------------------------------------------------------------------------");
        r=rand() % 5;
        if(r==1){
        	c=4; j=2; x=1;
        }
        else if(r==0){
        	c=5; j=2; x=5;
        }
        else if(r==2){
            c=4;j=1;x=6;
        }
		else if(r==3){
			c=4; j=2; x=8;
		}
		else if(r==4){
			c=4;j=2;x=10;
		}
    while(1){
		if(s>=10) {
			level++;
			s=0;
		}
		r=r1;
        if(r==0){
        	c=4; j=2; x=1;
        }
        else if(r==1){
        	c=5; j=2; x=5;
        }
        else if(r==2){
            c=4;j=1;x=6;
        }
		else if(r==3){
			c=4; j=2; x=8;
		}
		else if(r==4){
			c=4;j=2;x=10;
		}
        r1=rand() % 5;
        for(b=0;;b++)
        {
            reset_o();
            for(f=0;f<10-level;f++)
            {
				gotoxy(25, 5); printf(" LEVEL : %2d", level); 
				gotoxy(25, 7); printf("<---    N E X T    ");
				gotoxy(25, 8); printf("                  ");
				gotoxy(25, 9); printf("                  ");
				gotoxy(25, 10); printf("                  ");
				gotoxy(25, 11); printf("                  ");
				gotoxy(24, 12); printf("---------------------------------------------------------------------------------------"); 
				if(score>bestscore)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);gotoxy(25, 14); printf("CURRENT : %6d     %s      BEST : %6d", score, score<=bestscore?"<=":"> ", bestscore);SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				gotoxy(25, 16); printf("   w    : Change Shape  SPACE : Drop");     
				gotoxy(25, 17); printf("a     d : Left / Right  p     : Pause");
				gotoxy(25, 18); printf("   s    : Down          ESC   : Exit                     \"made by leesu0605\"");
				gotoxy(24, 20); printf("---------------------------------------------------------------------------------------");
				gotoxy(34, 9);
				if(r1==0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					printf("▣");
					gotoxy(34, 10); printf("▣▣▣");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else if(r1==1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("▣▣");
					gotoxy(34, 10); printf("▣▣");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else if(r1==2){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
					printf("▣▣▣▣");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else if(r1==3){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
					printf("▣▣");
					gotoxy(34, 10); printf("  ▣▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else if(r1==4){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					printf("  ▣");
					gotoxy(34, 10); printf("▣▣▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
                y=0;
                Sleep(50);
                if(kbhit()){
                    y=0;
                    g=getch();
                    switch(g)
                    {
                    case 'a':
                        check_left_fliction();
                        if(y==0)
                        {
                            reset_z();
                            c--;
                            reset_o();
                        }
                        break;
                    case 'd':
                        check_right_fliction();
                        if(y==0)
                        {
                            reset_z();
                            c++;
                            reset_o();
                        }
                        break;
                    case 's':
                        if(check_fliction())
                        {
                            reset_z();
                            b++;
                            reset_o();
                        }
                        break;
                    case 'w':
                        if(x==1){
                            if(a[b][c+1]==0&&a[b+2][c+1]==0&&a[b+2][c]==0){
                                reset_z(); j=3; x=2; reset_o();
							}}
                         else if(x==2){
                             if(a[b][c]==0&&a[b][c+2]==0&&a[b+1][c+2]==0){
                                 reset_z();j=2; x=3;reset_o();
							 }}
                         else if(x==3){
                             if(a[b+1][c]==0&&a[b+2][c]==0){
                                 reset_z();j=3;x=4;reset_o();
							 }}
                         else if(x==4){
                             if(a[b+1][c+1]==0&&a[b+1][c+2]==0){
                                 reset_z();j=2; x=1;reset_o();
							 }}
                         else if(x==6){
                             if(a[b+1][c]==0&&a[b+2][c]==0&&a[b+3][c]==0){
                                 reset_z();j=4;x=7;reset_o();
							 }}
                         else if(x==7){
                             if(a[b][c+1]==0&&a[b][c+2]==0&&a[b][c+3]==0){
                                 reset_z();j=1;x=6;reset_o();
							 }}
						 else if(x==8){
							 if(a[b+1][c]==0&&a[b+2][c]==0){
								 reset_z();j=3;x=9;reset_o();
							 }}
						 else if(x==9){
							 if(a[b][c]==0&&a[b+1][c+2]==0){
								 reset_z();j=2;x=8;reset_o();
							 }}
						 else if(x==10){
							 if(a[b+2][c+1]==0){
								 reset_z();j=3;x=11;reset_o();
							 }}
						 else if(x==11){
							 if(a[b][c]==0&&a[b][c+2]==0){
								 reset_z();j=2;x=12;reset_o();
							 }}
						 else if(x==12){
							 if(a[b+1][c]==0&&a[b+2][c]==0){
								 reset_z();j=3;x=13;reset_o();
							 }}
						 else if(x==13){
							 if(a[b][c+1]==0&&a[b+1][c+2]==0){
								 reset_z();j=2;x=10;reset_o();
							 }}
                         break;
					case 'p':
						pause_p();
						break;
					case ' ':
						while(check_fliction()){
							reset_z();
							b++;
							reset_o();
						}
						break;
					case 27:
						system("cls");
						game_over();
						exit(0);
                    }
          }
        }
             if(check_fliction())
                 reset_z();
             else
             {
                 check_clear();
				 if(b<=3){
					 game_over(); exit(0);
				 }
				 score+=100;
                 break;
             }
       }
 }
           return 0;
}

void gotoxy(int x, int y){
    COORD pos ={x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void reset_z(void){
    if(x==1){
    a[b][c]=0;    a[b+1][c]=0;    a[b+1][c+1]=0;    a[b+1][c+2]=0;
    gotoxy(2*c, b);    printf("  ");    gotoxy(2*c, (b+1));    printf("  ");    gotoxy(2*(c+1), (b+1));    printf("  ");    gotoxy(2*(c+2), (b+1));    printf("  ");
    }
    else if(x==2){
    a[b][c+1]=0;    a[b+1][c+1]=0;    a[b+2][c]=0;    a[b+2][c+1]=0;
    gotoxy(2*(c+1), b);    printf("  ");    gotoxy(2*(c+1), (b+1));    printf("  ");    gotoxy(2*c, (b+2));    printf("  ");    gotoxy(2*(c+1), (b+2));    printf("  ");
    }
    else if(x==3){
    a[b][c]=0;    a[b][c+1]=0;    a[b][c+2]=0;    a[b+1][c+2]=0;
    gotoxy(2*(c+1), b);    printf("  ");    gotoxy(2*(c+2), b);    printf("  ");    gotoxy(2*c, b);    printf("  ");    gotoxy(2*(c+2), (b+1));    printf("  ");
    }
    else if(x==4){
    a[b][c]=0;    a[b][c+1]=0;    a[b+1][c]=0;    a[b+2][c]=0;
    gotoxy(2*(c+1), b);    printf("  ");    gotoxy(2*(c), b+2);    printf("  ");    gotoxy(2*c, b);    printf("  ");    gotoxy(2*(c), (b+1));    printf("  ");
    }
    else if(x==5){
    a[b][c]=0;    a[b][c+1]=0;    a[b+1][c]=0;    a[b+1][c+1]=0;
    gotoxy(2*(c+1), b);    printf("  ");    gotoxy(2*(c), b+1);    printf("  ");    gotoxy(2*c, b);    printf("  ");    gotoxy(2*(c+1), (b+1));    printf("  ");
    }
    else if(x==6){
    a[b][c]=0;    a[b][c+1]=0;    a[b][c+2]=0;    a[b][c+3]=0;
    gotoxy(2*(c+1), b);    printf("  ");    gotoxy(2*(c+2), b);    printf("  ");    gotoxy(2*c, b);    printf("  ");    gotoxy(2*(c+3), (b));    printf("  ");
    }
    else if(x==7){
    a[b][c]=0;    a[b+1][c]=0;    a[b+2][c]=0;    a[b+3][c]=0;
    gotoxy(2*(c), b);    printf("  ");    gotoxy(2*(c), b+1);    printf("  ");    gotoxy(2*c, b+2);    printf("  ");    gotoxy(2*(c), (b+3));    printf("  ");
    }
	else if(x==8){
	a[b][c]=0;	a[b][c+1]=0;	a[b+1][c+1]=0;	a[b+1][c+2]=0;
    gotoxy(2*(c), b);    printf("  ");    gotoxy(2*(c+1), b+1);    printf("  ");    gotoxy(2*(c+1), b);    printf("  ");    gotoxy(2*(c+2), (b+1));    printf("  ");
    }
	else if(x==9){
	a[b][c+1]=0;	a[b+1][c+1]=0;	a[b+1][c]=0;	a[b+2][c]=0;
    gotoxy(2*(c), b+2);    printf("  ");    gotoxy(2*(c), b+1);    printf("  ");    gotoxy(2*(c+1), b);    printf("  ");    gotoxy(2*(c+1), (b+1));    printf("  ");
    }
	else if(x==10){
	a[b][c+1]=0;	a[b+1][c]=0;	a[b+1][c+1]=0;	a[b+1][c+2]=0;
	gotoxy(2*(c+1), b); printf("  ");	gotoxy(2*c, b+1); printf("  ");	gotoxy(2*(c+1), b+1); printf("  ");	gotoxy(2*(c+2), b+1); printf("  ");
	}
	else if(x==11){
	a[b][c+1]=0;	a[b+1][c+1]=0;	a[b+1][c]=0;	a[b+2][c+1]=0;
	gotoxy(2*(c+1), b); printf("  ");	gotoxy(2*(c+1), b+1); printf("  ");	gotoxy(2*(c), b+1); printf("  ");	gotoxy(2*(c+1), b+2); printf("  ");
	}
	else if(x==12){
	a[b][c]=0;	a[b][c+1]=0;	a[b][c+2]=0;	a[b+1][c+1]=0;
	gotoxy(2*(c), b); printf("  ");	gotoxy(2*(c+1), b); printf("  ");	gotoxy(2*(c+2), b); printf("  ");	gotoxy(2*(c+1), b+1); printf("  ");
	}
	else if(x==13){
	a[b][c]=0;a[b+1][c]=0;a[b+1][c+1]=0;a[b+2][c]=0;
	gotoxy(2*c, b);printf("  "); gotoxy(2*c, b+1);printf("  "); gotoxy(2*(c+1), b+1); printf("  "); gotoxy(2*c, b+2); printf("  ");
	}
    return;
}

void reset_o(void){
    if(x==1){
    a[b][c]=1;    a[b+1][c]=1;    a[b+1][c+1]=1;    a[b+1][c+2]=1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);gotoxy(2*c, b);printf("▣");
    gotoxy(2*c, (b+1)); printf("▣");
    gotoxy(2*(c+1), (b+1));printf("▣");
    gotoxy(2*(c+2), (b+1));printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(x==2){
    a[b][c+1]=1;    a[b+1][c+1]=1;    a[b+2][c]=1;    a[b+2][c+1]=1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);gotoxy(2*(c+1), b);printf("▣");
    gotoxy(2*(c+1), (b+1));    printf("▣");
    gotoxy(2*(c+1), (b+2));    printf("▣");
    gotoxy(2*c, (b+2));    printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(x==3){
    a[b][c]=1;    a[b][c+1]=1;    a[b][c+2]=1;    a[b+1][c+2]=1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);gotoxy(2*(c+1), b);    printf("▣");
    gotoxy(2*(c+2), b);    printf("▣");
    gotoxy(2*c, b);    printf("▣");
    gotoxy(2*(c+2), (b+1));    printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(x==4){
    a[b][c]=1;    a[b][c+1]=1;    a[b+1][c]=1;    a[b+2][c]=1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);gotoxy(2*(c+1), b);    printf("▣");
    gotoxy(2*(c), b+2);    printf("▣");
    gotoxy(2*c, b);    printf("▣");
    gotoxy(2*(c), (b+1));    printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(x==5){
    a[b][c]=2;    a[b][c+1]=2;    a[b+1][c]=2;    a[b+1][c+1]=2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);gotoxy(2*(c+1), b);    printf("▣");
    gotoxy(2*(c), b+1);    printf("▣");
    gotoxy(2*c, b);    printf("▣");
    gotoxy(2*(c+1), (b+1));    printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(x==6){
    a[b][c]=3;    a[b][c+1]=3;    a[b][c+2]=3;    a[b][c+3]=3;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);gotoxy(2*(c+1), b);    printf("▣");
    gotoxy(2*(c+2), b);    printf("▣");
    gotoxy(2*c, b);    printf("▣");
    gotoxy(2*(c+3), (b));    printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else if(x==7){
    a[b+1][c]=3;    a[b+2][c]=3;    a[b+3][c]=3;    a[b][c]=3;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);gotoxy(2*(c), b+1);    printf("▣");
    gotoxy(2*(c), b);    printf("▣");
    gotoxy(2*c, b+2);    printf("▣");
    gotoxy(2*(c), (b+3));    printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
	else if(x==8){
	a[b][c]=4;	a[b][c+1]=4;	a[b+1][c+1]=4;	a[b+1][c+2]=4;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);gotoxy(2*(c), b);    printf("▣");
    gotoxy(2*(c+1), b+1);    printf("▣");
    gotoxy(2*(c+1), b);    printf("▣");
    gotoxy(2*(c+2), (b+1));    printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
	else if(x==9){
	a[b][c+1]=4;	a[b+1][c+1]=4;	a[b+1][c]=4;	a[b+2][c]=4;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);gotoxy(2*(c), b+2);    printf("▣");
    gotoxy(2*(c), b+1);    printf("▣");
    gotoxy(2*(c+1), b);    printf("▣");
    gotoxy(2*(c+1), (b+1));    printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
	else if(x==10){
	a[b][c+1]=5;	a[b+1][c]=5;	a[b+1][c+1]=5;	a[b+1][c+2]=5;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);gotoxy(2*(c+1), b); printf("▣");
	gotoxy(2*c, b+1); printf("▣");
	gotoxy(2*(c+1), b+1); printf("▣");
	gotoxy(2*(c+2), b+1); printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if(x==11){
	a[b][c+1]=5;	a[b+1][c+1]=5;	a[b+1][c]=5;	a[b+2][c+1]=5;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);gotoxy(2*(c+1), b); printf("▣");
	gotoxy(2*(c+1), b+1); printf("▣");
	gotoxy(2*(c), b+1); printf("▣");
	gotoxy(2*(c+1), b+2); printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if(x==12){
	a[b][c]=5;	a[b][c+1]=5;	a[b][c+2]=5;	a[b+1][c+1]=5;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);gotoxy(2*(c), b); printf("▣");
	gotoxy(2*(c+1), b); printf("▣");
	gotoxy(2*(c+2), b); printf("▣");
	gotoxy(2*(c+1), b+1); printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if(x==13){
	a[b][c]=5;a[b+1][c]=5;a[b+1][c+1]=5;a[b+2][c]=5;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);gotoxy(2*c, b);printf("▣"); gotoxy(2*c, b+1);printf("▣"); gotoxy(2*(c+1), b+1); printf("▣"); gotoxy(2*c, b+2); printf("▣");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
    return;
}

int check_fliction(void)
{
    if(x==1)
        if(a[b+2][c]==0&&a[b+2][c+1]==0&&a[b+2][c+2]==0)
            return 1;
        else
            return 0;
    else if(x==2)
        if(a[b+3][c]==0&&a[b+3][c+1]==0)
            return 1;
        else
            return 0;
    else if(x==3)
        if(a[b+1][c]==0&&a[b+1][c+1]==0&&a[b+2][c+2]==0)
            return 1;
        else
            return 0;
    else if(x==4)
        if(a[b+3][c]==0&&a[b+1][c+1]==0)
            return 1;
        else
            return 0;
    else if(x==5)
        if(a[b+2][c]==0&&a[b+2][c+1]==0)
            return 1;
        else
            return 0;
    else if(x==6)
        if(a[b+1][c]==0&&a[b+1][c+1]==0&&a[b+1][c+2]==0&&a[b+1][c+3]==0)
            return 1;
        else
            return 0;
    else if(x==7)
        if(a[b+4][c]==0)
            return 1;
        else
            return 0;
	else if(x==8)
		if(a[b+1][c]==0&&a[b+2][c+1]==0&&a[b+2][c+2]==0)
			return 1;
		else
			return 0;
	else if(x==9)
		if(a[b+3][c]==0&&a[b+2][c+1]==0)
			return 1;
		else
			return 0;
	else if(x==10)
		if(a[b+2][c]==0&&a[b+2][c+1]==0&&a[b+2][c+2]==0)
			return 1;
		else
			return 0;
	else if(x==11)
		if(a[b+2][c]==0&&a[b+3][c+1]==0)
			return 1;
		else
			return 0;
	else if(x==12)
		if(a[b+1][c]==0&&a[b+2][c+1]==0&&a[b+1][c+2]==0)
			return 1;
		else
			return 0;
	else if(x==13)
		if(a[b+3][c]==0&&a[b+2][c+1]==0)
			return 1;
		else
			return 0;
    return 0;
}

void CursorView(char show)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

void check_right_fliction(void)
{
    if(x==1){
        if(a[b][c+1]!=0||a[b+1][c+3]!=0)
			y=1;}
    else if(x==2){
        if(a[b][c+2]!=0||a[b+1][c+2]!=0||a[b+2][c+2]!=0)
			y=1;}
    else if(x==3){
        if(a[b][c+3]!=0||a[b+1][c+3]!=0)
			y=1;}
    else if(x==4){
        if(a[b][c+2]!=0||a[b+1][c+1]!=0||a[b+2][c+1]!=0)
			y=1;}
    else if(x==5){
       if(a[b][c+2]!=0||a[b+1][c+2]!=0)
		   y=1;}
    else if(x==6){
        if(a[b][c+4]!=0)
			y=1;}
    else if(x==7){
         if(a[b][c+1]!=0||a[b+1][c+1]!=0||a[b+2][c+1]!=0||a[b+3][c+1]!=0)
			 y=1;}
	else if(x==8){
		if(a[b][c+2]!=0||a[b+1][c+3]!=0)
			y=1;}
	else if(x==9){
		if(a[b][c+2]!=0||a[b+1][c+2]!=0||a[b+2][c+1]!=0)
			y=1;}
	else if(x==10){
		if(a[b][c+2]!=0||a[b+1][c+3]!=0)
			y=1;}
	else if(x==11){
		if(a[b][c+2]!=0||a[b+1][c+2]!=0||a[b+2][c+2]!=0)
			y=1;}
	else if(x==12){
		if(a[b][c+3]!=0||a[b+1][c+2]!=0)
			y=1;}
	else if(x==13){
		if(a[b][c+1]!=0||a[b+1][c+2]!=0||a[b+2][c+1]!=0)
			y=1;}
    return;
}

void check_left_fliction(void)
{
    if(x==1){
        if(a[b][c-1]!=0||a[b+1][c-1]!=0)
			y=1;}
    else if(x==2){
        if(a[b][c]!=0||a[b+1][c]!=0||a[b+2][c-1]!=0)
			y=1;}
    else if(x==3){
        if(a[b][c-1]!=0||a[b+1][c+1]!=0)
			y=1;}
    else if(x==4){
        if(a[b][c-1]!=0||a[b+1][c-1]!=0||a[b+2][c-1]!=0)
			y=1;}
    else if(x==5){
       if(a[b][c-1]!=0||a[b+1][c-1]!=0)
		   y=1;}
    else if(x==6){
        if(a[b][c-1]!=0)
			y=1;}
    else if(x==7){
         if(a[b][c-1]!=0||a[b+1][c-1]!=0||a[b+2][c-1]!=0||a[b+3][c-1]!=0)
			 y=1;}
	else if(x==8){
		if(a[b][c-1]!=0||a[b+1][c]!=0)
			y=1;}
	else if(x==9){
		if(a[b][c]!=0||a[b+1][c-1]!=0||a[b+2][c-1]!=0)
			y=1;}
	else if(x==10){
		if(a[b][c]!=0||a[b+1][c-1]!=0)
			y=1;}
	else if(x==11){
		if(a[b][c]!=0||a[b+1][c-1]!=0||a[b+2][c]!=0)
			y=1;}
	else if(x==12){
		if(a[b][c-1]!=0||a[b+1][c]!=0)
			y=1;}
	else if(x==13){
		if(a[b][c-1]!=0||a[b+1][c-1]!=0||a[b+2][c-1]!=0)
			y=1;}
    return;
}
void check_clear(void)
{
            n=0;
            for(m=b+j-1;m>=b-1;m--)
            if(a[m][1]!=0&&a[m][2]!=0&&a[m][3]!=0&&a[m][4]!=0&&a[m][5]!=0&&a[m][6]!=0&&a[m][7]!=0&&a[m][8]!=0&&a[m][9]!=0&&a[m][10]!=0)
            {
				gotoxy(2, m);printf("★★★★★★★★★★");
                n++;
			}
			for(m=b+j-1;m>=b-1;m--)
			if(a[m][1]!=0&&a[m][2]!=0&&a[m][3]!=0&&a[m][4]!=0&&a[m][5]!=0&&a[m][6]!=0&&a[m][7]!=0&&a[m][8]!=0&&a[m][9]!=0&&a[m][10]!=0){
                for(z=1;z<11;z++)
                    a[m][z]=0;
                for(z=1;z<11;z++)
                    for(y=m;y>4;y--)
                    {
                        temp=a[y][z];
                        a[y][z]=a[y-1][z];
                        a[y-1][z]=temp;
                    }
                    m++;
            }    
    if(n>=1){
	if(n>=2){
	gotoxy(10, 5);
	printf("%dcombo!", n);Sleep(1000);
	}
	else
		Sleep(500);
	s+=n;
	score+=n*n*100;
	gotoxy(0, 0);
    for(z=0;z<20;z++)
    {
        a[20][z/2]=1;
        a[z][0]=1;
        a[z][11]=1;
        for(y=0;y<12;y++){
            if(a[z][y]==1)
                if(y==0||y==11){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    printf("▩");
				}
                else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("▣");
				}
            else if(a[z][y]==2){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    printf("▣");
			}
			else if(a[z][y]==0)
                printf("  ");
			else if(a[z][y]==4){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                    printf("▣");
			}
			else if(a[z][y]==3){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("▣");
			}
			else if(a[z][y]==5){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					printf("▣");
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				printf("▣");
			}
		}
		printf("\n");
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    for(y=0;y<12;y++)
        printf("▩");
    }
    gotoxy(23, 3);
    printf("---------------------------------------------------------------------------------------");
    return;
}

void game_over(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(0,6); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");  
    gotoxy(0,7); printf("▤                              ▤");
    gotoxy(0,8); printf("▤  +-----------------------+   ▤");
    gotoxy(0,9); printf("▤  |  G A M E  O V E R..   |   ▤");
    gotoxy(0,10); printf("▤  +-----------------------+   ▤");
    gotoxy(0,11); printf("▤   YOUR SCORE: %6d         ▤",score);
    gotoxy(0,12); printf("▤                              ▤");
	fileopen_wt();
    gotoxy(0,14); printf("▤                              ▤");
    gotoxy(0,15); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	return;
}

void pause_p(void)
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(0,6); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");  
    gotoxy(0,7); printf("▤                              ▤");
    gotoxy(0,8); printf("▤  +-----------------------+   ▤");
    gotoxy(0,9); printf("▤  |	     PAUSED..       |   ▤");
    gotoxy(0,10); printf("▤  +-----------------------+   ▤");
    gotoxy(0,11); printf("▤                              ▤");
    gotoxy(0,12); printf("▤                              ▤");
    gotoxy(0,13); printf("▤     Press \'c\' to resume..    ▤");
    gotoxy(0,14); printf("▤                              ▤");
    gotoxy(0,15); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	Sleep(100);
WAIT:
	while(kbhit()==0)
		Sleep(30);
	g=getch();
	if(g!='c')
		goto WAIT;
	system("cls");
for(z=0;z<20;z++)
    {
        a[20][z/2]=1;
        a[z][0]=1;
        a[z][11]=1;
        for(y=0;y<12;y++){
            if(a[z][y]==1)
                if(y==0||y==11){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    printf("▩");
				}
                else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("▣");
				}
            else if(a[z][y]==2){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    printf("▣");
			}
			else if(a[z][y]==3){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    printf("▣");
			}
			else if(a[z][y]==0)
                printf("  ");
			else if(a[z][y]==4){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				printf("▣");
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				printf("▣");
			}
		}
        printf("\n");
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    for(y=0;y<12;y++)
        printf("▩");
    gotoxy(23, 2);
    printf("---------------------------------------------------------------------------------------");
	return;
}

void fileopen_rt(void){
	FILE* file=fopen("bestscore.dat", "rt");
	if(file==NULL)
		bestscore=0;
	else{
		fscanf(file, "%d", &bestscore);
	    fclose(file);
	}
	return;
}

void fileopen_wt(void){
	if(score>bestscore){
		FILE* file=fopen("bestscore.dat", "wt");
		gotoxy(0,13); printf("▤  ★★★ BEST SCORE! ★★★   ▤");
		fprintf(file, "%d", score);
		fclose(file);
	}
	else
		gotoxy(0,13);printf("▤                              ▤");
	return;
}