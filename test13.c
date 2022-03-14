#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
int arr[20][20], a, b, c, d, e, f, g, look, h, i, j, k=0, look1, u, score=0, level=0, bestscore;

void gotoxy(int x,int y)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
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

void fileopen_rt(void){
    FILE * fp=fopen("snailscore.dat", "rt");
    if(fp==NULL)
        bestscore=0;
    else
        fscanf(fp, "%d", &bestscore);
    return;
}

void fileopen_wt(void){
    FILE * fp=fopen("snailscore.dat", "wt");
    fprintf(fp, "%d", score);
    fclose(fp);
    bestscore=score;
    return;
}

void reset(void){
    u=0;
    for(i=1;i<19;i++){
        for(j=1;j<19;j++)
            if(arr[i][j]==look){
                u=1;
                break; 
            }
        if(u==1)
            break;
    }
    arr[i][j]=0;
    gotoxy(2*j, i);printf("  ");
    return;
}

int main(void){
    fileopen_rt();
    system("title 별먹기 게임"); system("mode con cols=120 lines=21");
START:
    k=0;
    score=0;
    look=5;
    look1=7;
    CursorView(0);
    system("cls");
    gotoxy(20, 5);
    printf("Press any key to start");
    while(kbhit()==0) {}
    g=getch();
    system("cls");
    a=10; b=10;
    for(d=0;d<20;d++){
        arr[d][0]=-1;
        arr[0][d]=-1;
        arr[d][19]=-1;
        arr[19][d]=-1;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    for(c=0;c<20;c++){
        for(d=0;d<20;d++)
            if(arr[c][d]==-1)
                printf("■");
            else
                printf("  ");
        printf("\n");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(40, 6); printf("------------------------------------------------------------------"); 
	gotoxy(40, 7); printf("   w    : Up   ");     
	gotoxy(40, 8); printf("a     d : Left / Right  ");
	gotoxy(40, 9); printf("   s    : Down          ESC     : Exit  \"made by leesu0605\"");
	gotoxy(40, 10); printf("-----------------------------------------------------------------");
    gotoxy(2*(b-2), a); printf("■■■");arr[a][b]=4;arr[a][b-1]=look+1;arr[a][b-2]=look;
    while(kbhit()==0) {}
    while(1){
        if(k==0){
            do{
                c=rand() % 18; c+=1;
                d=rand() % 18; d+=1;
            }while(arr[c][d]>0);
            arr[c][d]=-2; 
            gotoxy(2*d, c); printf("★");
            k=1;
        }
            if(kbhit()){
                g=getch();
                switch(g){
                case 'w':
                case 72:
                        arr[a][b]=1;
                    break;
                case 's':
                case 80:
                        arr[a][b]=2;
                    break;
                case 'a':
                case 75:
                        arr[a][b]=3;
                    break;
                case 'd':
                case 77:
                        arr[a][b]=4;
                    break;
                case 27:
                    gotoxy(0, 0);
                    for(a=0;a<20;a++){
                        for(b=0;b<20;b++)
                            if(arr[a][b]==-1)
                                printf("■");
                            else if(arr[a][b]>=5)
                                printf("■");
                            else
                                printf("  ");
                    printf("\n");
                   }
                    goto END;
                }
            }
                if(arr[a][b]==1){
              arr[a][b]=look1;
			  arr[a][b]=look2;
                    a--;
                    if(arr[a][b]==-2)
                        k=0;
                    else if(arr[a][b]==-1)
                        goto END;
                    arr[a][b]=1;
                }else if(arr[a][b]==2){
              arr[a][b]=look1;
                    a++;
                    if(arr[a][b]==-2)
                        k=0;
                    else if(arr[a][b]==-1)
                        goto END;
                    arr[a][b]=2;
                }else if(arr[a][b]==3){
              arr[a][b]=look1;
                    b--;
                    if(arr[a][b]==-2)
                        k=0;
                    else if(arr[a][b]==-1)
                        goto END;
                    arr[a][b]=3;
                }else if(arr[a][b]==4){
              arr[a][b]=look1;
                    b++;
                    if(arr[a][b]==-2)
                        k=0;
                    else if(arr[a][b]==-1)
                        goto END;
                    arr[a][b]=4;
                }
            if(k!=0){
                reset();
                look++;
            }else
                score+=5;
            gotoxy(2*b, a);printf("■");
            gotoxy(45, 16); printf("level: %2d", level);
            if(score>bestscore)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            gotoxy(45, 14); printf("score: %4d       %s        bestscore: %4d", score, score>bestscore?"> ":"<=", bestscore);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            arr[19][19]=-2;
            gotoxy(38, 19);printf("■");
            look1++;
            Sleep(200-score/3);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
END:
    if(score<=bestscore){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(0,6); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");  
    gotoxy(0,7); printf("▤                              ▤");
    gotoxy(0,8); printf("▤  +-----------------------+   ▤");
    gotoxy(0,9); printf("▤  |  G A M E  O V E R..   |   ▤");
    gotoxy(0,10); printf("▤  +-----------------------+   ▤");
    gotoxy(0,11); printf("▤                              ▤");
    gotoxy(0,12); printf("▤     Press \"r\" to restart     ▤");
    gotoxy(0,13); printf("▤      Press ESC to exit       ▤");
    gotoxy(0,14); printf("▤       Score:   %6d        ▤", score);
    gotoxy(0,15); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
    }else{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    fileopen_wt();
    gotoxy(0,6); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");  
    gotoxy(0,7); printf("▤                              ▤");
    gotoxy(0,8); printf("▤  +-----------------------+   ▤");
    gotoxy(0,9); printf("▤  |       YOU WIN!        |   ▤");
    gotoxy(0,10); printf("▤  +-----------------------+   ▤");
    gotoxy(0,11); printf("▤                              ▤");
    gotoxy(0,12); printf("▤     Press \"r\" to restart     ▤");
    gotoxy(0,13); printf("▤      Press ESC to exit       ▤");
    gotoxy(0,14); printf("▤       Score:   %6d        ▤", score);
    gotoxy(0,15); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
    }
    while(1)
        if(kbhit()){
            g=getch();
             switch(g){
             case 'r':
                 for(i=1;i<19;i++)
                     for(j=1;j<19;j++)
                         arr[i][j]=0;
                 goto START;
             case 27:
                 exit(0);
             }
         }
    return 0;
}