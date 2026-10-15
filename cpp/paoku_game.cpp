//编译选项:-lcomdlg32 -static
//编译器:Dev-C++

// ================= 跑酷游戏 -by sunnycl =================
#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<commdlg.h>

// ==================== made_game.h ====================
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define pass_ctrl ((GetAsyncKeyState(17)&0x8000)?1:0)
#define pass_shift ((GetAsyncKeyState(16)&0x8000)?1:0)
#define pass_capslock ((GetAsyncKeyState(20)&0x8000)?1:0)
#define pass_tab ((GetAsyncKeyState(9)&0x8000)?1:0)
#define pass_esc ((GetAsyncKeyState(27)&0x8000)?1:0)
#define pass_alt ((GetAsyncKeyState(18)&0x8000)?1:0)
#define pass_windows ((GetAsyncKeyState(91)&0x8000)?1:0)
#define pass_enter ((GetAsyncKeyState(13)&0x8000)?1:0)
#define pass_backspace ((GetAsyncKeyState(8)&0x8000)?1:0)
#define pass_up ((GetAsyncKeyState(38)&0x8000)?1:0)
#define pass_down ((GetAsyncKeyState(40)&0x8000)?1:0)
#define pass_left ((GetAsyncKeyState(37)&0x8000)?1:0)
#define pass_right ((GetAsyncKeyState(39)&0x8000)?1:0)
#define pass_f1 ((GetAsyncKeyState(112)&0x8000)?1:0)
#define pass_f2 ((GetAsyncKeyState(113)&0x8000)?1:0)
#define pass_f3 ((GetAsyncKeyState(114)&0x8000)?1:0)
#define pass_f4 ((GetAsyncKeyState(115)&0x8000)?1:0)
#define pass_f5 ((GetAsyncKeyState(116)&0x8000)?1:0)
#define pass_f6 ((GetAsyncKeyState(117)&0x8000)?1:0)
#define pass_f7 ((GetAsyncKeyState(118)&0x8000)?1:0)
#define pass_f8 ((GetAsyncKeyState(119)&0x8000)?1:0)
#define pass_f9 ((GetAsyncKeyState(120)&0x8000)?1:0)
#define pass_f10 ((GetAsyncKeyState(121)&0x8000)?1:0)
#define pass_f11 ((GetAsyncKeyState(122)&0x8000)?1:0)
#define pass_f12 ((GetAsyncKeyState(123)&0x8000)?1:0)
#define pass_delete ((GetAsyncKeyState(46)&0x8000)?1:0)
#define pass_space ((GetAsyncKeyState(32)&0x8000)?1:0)
#define pass(x) ((GetAsyncKeyState((int)(x))&0x8000)?1:0)
using namespace std;

void mode_con(int cols,int line) 
{
	string aa=to_string(cols),bb=to_string(line);
	string c="mode con cols=";
	c+=aa,c+=" lines=",c+=bb;
	system(c.c_str());
}
void setpos(int x,double y)
{
	x--;y--;y*=2;
	COORD pos;pos.X=y,pos.Y=x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void SetPos(int x,int y)
{
	COORD pos;pos.X=y,pos.Y=x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void color(string a)
{
	if(a=="gray") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
	if(a=="white") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(a=="skyblue") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(a=="green") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	if(a=="purple") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	if(a=="red") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	if(a=="yellow") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	if(a=="darkblue") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	if(a=="blue") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(a=="darkgreen") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
	if(a=="darkpurple") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE);
	if(a=="darkred") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
	if(a=="golden") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
	if(a=="graywhite") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}
bool passc(char a)
{
	if(a=='~')return ((GetAsyncKeyState(192)&0x8000)?1:0);
	else if(a=='-')return ((GetAsyncKeyState(189)&0x8000)?1:0);
	else if(a=='=')return ((GetAsyncKeyState(187)&0x8000)?1:0);
	else if(a=='[')return ((GetAsyncKeyState(219)&0x8000)?1:0);
	else if(a==']')return ((GetAsyncKeyState(221)&0x8000)?1:0);
	else if(a=='\\')return ((GetAsyncKeyState(220)&0x8000)?1:0);
	else if(a==';')return ((GetAsyncKeyState(186)&0x8000)?1:0);
	else if(a=='\'')return ((GetAsyncKeyState(222)&0x8000)?1:0);
	else if(a==',')return ((GetAsyncKeyState(188)&0x8000)?1:0);
	else if(a=='.')return ((GetAsyncKeyState(190)&0x8000)?1:0);
	else if(a=='/')return ((GetAsyncKeyState(191)&0x8000)?1:0);
	else return ((GetAsyncKeyState(int(a))&0x8000)?1:0);	
} 
void cls(){system("cls");}
void title(string a)
{
	string b="title ";
	b+=a;
	system(b.c_str());
}
void sys_color(string background,string fontcolor)
{
	char a,b;
	if(background=="black")a='0';
	if(background=="blue")a='1';
	if(background=="green")a='2';
	if(background=="lightgreen")a='3';
	if(background=="red")a='4';
	if(background=="purple")a='5';
	if(background=="yellow")a='6';
	if(background=="white")a='7';
	if(background=="gray")a='8';
	if(background=="thinblue")a='9';
	if(background=="thingreen")a='A';
	if(background=="thinlightgreen")a='B';
	if(background=="thinred")a='C';
	if(background=="thinpurple")a='D';
	if(background=="thinyellow")a='E';
	if(background=="brightwhite")a='F';
	
	if(fontcolor=="black")b='0';
	if(fontcolor=="blue")b='1';
	if(fontcolor=="green")b='2';
	if(fontcolor=="lightgreen")b='3';
	if(fontcolor=="red")b='4';
	if(fontcolor=="purple")b='5';
	if(fontcolor=="yellow")b='6';
	if(fontcolor=="white")b='7';
	if(fontcolor=="gray")b='8';
	if(fontcolor=="thinblue")b='9';
	if(fontcolor=="thingreen")b='A';
	if(fontcolor=="thinlightgreen")b='B';
	if(fontcolor=="thinred")b='C';
	if(fontcolor=="thinpurple")b='D';
	if(fontcolor=="thinyellow")b='E';
	if(fontcolor=="brightwhite")b='F';
	
	string c="color ";
	c+=a,c+=b;
	system(c.c_str()); 
}
void fastout(char *p)
{
    while(1)
    {
        if(*p!=0)putchar(*p++);
        else break;
    }
}
void slowout(char *p,int x)
{
    while(1)
    {
        if(*p!=0)putchar(*p++);
        else break;
    	Sleep(x);
    }
}
void rand_init()
{
	srand(time(0));
}
void no_cursor()
{
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}

// ==================== mouse_and_key.h ====================
#define pass_leftmouse (GetAsyncKeyState(1)&0x8000?1:0)
#define pass_rightmouse (GetAsyncKeyState(2)&0x8000?1:0)
#define mouse_pos_x (GetCursorPos(&pt)?pt.x:pt.x)
#define mouse_pos_y (GetCursorPos(&pt)?pt.y:pt.y)
#define press_leftmouse mouse_left_chick()
#define press_rightmouse mouse_right_chick()
#define press_ctrl keybd_event(17,0,0,0),keybd_event(17,0,KEYEVENTF_KEYUP,0);
#define press_shift keybd_event(16,0,0,0),keybd_event(16,0,KEYEVENTF_KEYUP,0);
#define press_capslock keybd_event(20,0,0,0),keybd_event(20,0,KEYEVENTF_KEYUP,0);
#define press_tab keybd_event(9,0,0,0),keybd_event(9,0,KEYEVENTF_KEYUP,0);
#define press_esc keybd_event(27,0,0,0),keybd_event(27,0,KEYEVENTF_KEYUP,0);
#define press_alt keybd_event(18,0,0,0),keybd_event(18,0,KEYEVENTF_KEYUP,0);
#define press_windows keybd_event(91,0,0,0),keybd_event(91,0,KEYEVENTF_KEYUP,0);
#define press_enter keybd_event(13,0,0,0),keybd_event(13,0,KEYEVENTF_KEYUP,0);
#define press_backspace keybd_event(8,0,0,0),keybd_event(8,0,KEYEVENTF_KEYUP,0);
#define press_up keybd_event(38,0,0,0),keybd_event(38,0,KEYEVENTF_KEYUP,0);
#define press_down keybd_event(40,0,0,0),keybd_event(40,0,KEYEVENTF_KEYUP,0);
#define press_left keybd_event(37,0,0,0),keybd_event(37,0,KEYEVENTF_KEYUP,0);
#define press_right keybd_event(39,0,0,0),keybd_event(39,0,KEYEVENTF_KEYUP,0);
#define press_f1 keybd_event(112,0,0,0),keybd_event(112,0,KEYEVENTF_KEYUP,0);
#define press_f2 keybd_event(113,0,0,0),keybd_event(113,0,KEYEVENTF_KEYUP,0);
#define press_f3 keybd_event(114,0,0,0),keybd_event(114,0,KEYEVENTF_KEYUP,0);
#define press_f4 keybd_event(115,0,0,0),keybd_event(115,0,KEYEVENTF_KEYUP,0);
#define press_f5 keybd_event(116,0,0,0),keybd_event(116,0,KEYEVENTF_KEYUP,0);
#define press_f6 keybd_event(117,0,0,0),keybd_event(117,0,KEYEVENTF_KEYUP,0);
#define press_f7 keybd_event(118,0,0,0),keybd_event(118,0,KEYEVENTF_KEYUP,0);
#define press_f8 keybd_event(119,0,0,0),keybd_event(119,0,KEYEVENTF_KEYUP,0);
#define press_f9 keybd_event(120,0,0,0),keybd_event(120,0,KEYEVENTF_KEYUP,0);
#define press_f10 keybd_event(121,0,0,0),keybd_event(121,0,KEYEVENTF_KEYUP,0);
#define press_f11 keybd_event(122,0,0,0),keybd_event(122,0,KEYEVENTF_KEYUP,0);
#define press_f12 keybd_event(123,0,0,0),keybd_event(123,0,KEYEVENTF_KEYUP,0);
#define press_delete keybd_event(46,0,0,0),keybd_event(46,0,KEYEVENTF_KEYUP,0);
#define press_space keybd_event(32,0,0,0),keybd_event(32,0,KEYEVENTF_KEYUP,0);

typedef BOOL (WINAPI *PROCSETCONSOLEFONT)(HANDLE, DWORD);
PROCSETCONSOLEFONT SetConsoleFont;
POINT pt;
void mouse_move(int x,int y)
{SetCursorPos(x,y);}
void mouse_left_chick()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}

void mousepos_exepos()
{
    HWND hwnd=GetForegroundWindow();
    GetCursorPos(&pt);
    ScreenToClient(hwnd,&pt);
    pt.x=pt.y/16;
    pt.y=pt.x/8;	
}
int exepos_x()
{
	mousepos_exepos();
	return pt.x+1;
}
int exepos_y()
{
	mousepos_exepos();
	return pt.y+1;	
}
void mouse_right_chick()
{	
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
}
void press(char c) //只能字母和数字，其他键不行 
{
	if(c>='a'&&c<='z')
	{
		keybd_event(((c)-'a'+65),0,0,0);
		keybd_event(((c)-'a'+65),0,KEYEVENTF_KEYUP,0);
	}
	else if(c>='A'&&c<='Z')
	{
		keybd_event((int)c,0,0,0);
		keybd_event((int)c,0,KEYEVENTF_KEYUP,0);
	}
	else  
	{
		keybd_event((int)c,0,0,0);
		keybd_event((int)c,0,KEYEVENTF_KEYUP,0);
	}
}
void DisableConsoleSelection()  
{  
    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);  
    DWORD mode;  
    GetConsoleMode(hConsole, &mode);  
	SetConsoleMode(hConsole, mode & ~(ENABLE_PROCESSED_INPUT|ENABLE_QUICK_EDIT_MODE)); 
}

// ==================== paoku.h ====================
const int DASH_DISTANCE = 10;

void kunnan_map(int n, int m) {
    ofstream out("play.in");
    mt19937 rnd(time(0));
    vector<vector<char> > mp(n+1, vector<char>(m+1, '#'));
    
    int platform_height = n/2;
    int gap_size = 15;
    int platform_length = 2;
    
    for (int j = 1; j <= m; j += gap_size + platform_length) {
        for (int k = 0; k < platform_length && j + k <= m; k++) {
            mp[platform_height][j + k] = '*';
            if (k == 0) mp[platform_height][j + k] = '<';
            else if (k == platform_length - 1) mp[platform_height][j + k] = '>';
            else if (rnd() % 3 == 0) mp[platform_height][j + k] = '^';
            else mp[platform_height][j + k] = '*';
        }
    }
    
    int num_moving_platforms = 10;
    for (int i = 0; i < num_moving_platforms; i++) {
        int height = platform_height - (3 + rnd() % 5);
        if (height < 3) height = 3;
        
        int start_j = 20 + rnd() % (m - 40);
        int length = 1 + rnd() % 2;
        
        for (int j = start_j; j < start_j + length && j <= m; j++) {
            mp[height][j] = '*';
        }
    }
    
    int num_moving_spikes = 20;
    for (int i = 0; i < num_moving_spikes; i++) {
        int height = 3 + rnd() % (n - 6);
        int start_j = 10 + rnd() % (m - 20);
		mp[height][start_j] = '@';
    }
    
    int num_spike_columns = 15;
    for (int i = 0; i < num_spike_columns; i++) {
        int col = 15 + rnd() % (m - 30);
        int height_start = 1 + rnd() % (n/3);
        int height_end = n/2 + rnd() % (n/2);
        
        for (int h = height_start; h <= height_end; h++) {
            if (mp[h][col] == '#') {
                mp[h][col] = (h == height_start) ? '^' : '@';
            }
        }
    }
    
    int num_traps = 8;
    for (int i = 0; i < num_traps; i++) {
        int col = 20 + rnd() % (m - 40);
        int height = platform_height - (2 + rnd() % 4);
        
        for (int j = col; j < col + 4; j++) {
            if (j <= m) mp[height][j] = '*';
        }
        mp[height][col+2] = '^';
    }
    
    int start_x = platform_height - 1;
    int start_y = 2;
    mp[start_x][start_y] = 'P';
    mp[start_x+1][start_y]='*';
    mp[start_x+1][start_y-1]='*';
    mp[start_x+1][start_y+1]='*';
    int end_x = 3 + rnd() % 3;
    int end_y = m - 5;
    mp[end_x][end_y] = 'E';
    
    for (int i = end_x - 2; i <= end_x + 2; i++) {
        for (int j = end_y - 3; j <= end_y + 3; j++) {
            if (i >= 1 && i <= n && j >= 1 && j <= m) {
                if (mp[i][j] == '#' && (i != end_x || j != end_y)) {
                    if (rnd() % 3 == 0) {
                        mp[i][j] = (i < end_x) ? '^' : 'V';
                    }
                }
            }
        }
    }
    
    out << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            out << mp[i][j];
        }
        out << endl;
    }
    out.close();
}

void diyu_map(int n, int m) {
    ofstream out("play.in");
    mt19937 rnd(time(0));
    vector<vector<char> > mp(n+1, vector<char>(m+1, '#'));
    
    int path_height = n/2;
    int path_spacing = 8;
    
    for (int j = 10; j < m - 10; j += path_spacing) {
        mp[path_height][j] = (rnd() % 2 == 0) ? '<' : '>';
        
        if (rnd() % 5 == 0 && j < m - 20) {
            int variation = (rnd() % 3) - 1;
            int new_height = path_height + variation;
            
            if (new_height > 3 && new_height < n - 3) {
                mp[new_height][j + path_spacing/2] = (rnd() % 2 == 0) ? '<' : '>';
                
                if (variation != 0) {
                    int step = (variation > 0) ? 1 : -1;
                    for (int h = path_height; h != new_height; h += step) {
                        if (h != path_height && h != new_height) {
                            mp[h][j + path_spacing/4] = (rnd() % 2 == 0) ? '<' : '>';
                        }
                    }
                }
            }
        }
    }
    
    int num_death_spikes = 120 + rnd() % 50;
    for (int i = 0; i < num_death_spikes; i++) {
        int spike_x = 3 + rnd() % (n - 6);
        int spike_y = 10 + rnd() % (m - 20);
        
        bool too_close = false;
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int check_x = spike_x + dx;
                int check_y = spike_y + dy;
                if (check_x >= 1 && check_x <= n && check_y >= 1 && check_y <= m) {
                    if (mp[check_x][check_y] == '<' || mp[check_x][check_y] == '>' || 
                        mp[check_x][check_y] == '^' || mp[check_x][check_y] == 'V') {
                        too_close = true;
                        break;
                    }
                }
            }
            if (too_close) break;
        }
        
        if (!too_close && mp[spike_x][spike_y] == '#') {
            mp[spike_x][spike_y] = '@';
        }
    }
    
    int num_death_zones = 8 + rnd() % 8;
    for (int i = 0; i < num_death_zones; i++) {
        int zone_x = 5 + rnd() % (n - 10);
        int zone_y = 20 + rnd() % (m - 40);
        int zone_width = 4 + rnd() % 6;
        int zone_height = 2 + rnd() % 4;
        
        bool overlaps_path = false;
        for (int x = zone_x; x < zone_x + zone_height && x <= n; x++) {
            for (int y = zone_y; y < zone_y + zone_width && y <= m; y++) {
                if (mp[x][y] == '<' || mp[x][y] == '>' || 
                    mp[x][y] == '^' || mp[x][y] == 'V') {
                    overlaps_path = true;
                    break;
                }
            }
            if (overlaps_path) break;
        }
        
        if (!overlaps_path) {
            for (int x = zone_x; x < zone_x + zone_height && x <= n; x++) {
                for (int y = zone_y; y < zone_y + zone_width && y <= m; y++) {
                    if (mp[x][y] == '#' && rnd() % 3 == 0) {
                        mp[x][y] = '@';
                    }
                }
            }
        }
    }
    
    int start_x = path_height - 1;
    int start_y = 5;
    mp[start_x][start_y] = 'P';
    
    for (int i = start_x - 1; i <= start_x + 1; i++) {
        for (int j = start_y - 1; j <= start_y + 1; j++) {
            if (i >= 1 && i <= n && j >= 1 && j <= m) {
                if (mp[i][j] == '@') mp[i][j] = '#';
            }
        }
    }
    
    if (mp[start_x + 1][start_y] == '#') {
        mp[start_x + 1][start_y] = '>';
    }
    
    int end_x = path_height;
    int end_y = m - 8;
    mp[end_x][end_y] = 'E';
    
    for (int i = end_x - 1; i <= end_x + 1; i++) {
        for (int j = end_y - 2; j <= end_y + 2; j++) {
            if (i >= 1 && i <= n && j >= 1 && j <= m) {
                if (mp[i][j] == '@') mp[i][j] = '#';
                
                if ((i == end_x - 1 || i == end_x + 1) && j == end_y && mp[i][j] == '#') {
                    mp[i][j] = (rnd() % 2 == 0) ? '<' : '>';
                }
                
                if (i == end_x && j == end_y - 1 && mp[i][j] == '#') {
                    mp[i][j] = (rnd() % 2 == 0) ? '<' : '>';
                }
            }
        }
    }
    
    int connect_x = end_x;
    int connect_y = end_y - 3;
    
    while (connect_y > m - 20) {
        if (mp[connect_x][connect_y] == '#') {
            mp[connect_x][connect_y] = (rnd() % 2 == 0) ? '<' : '>';
        }
        connect_y -= 2;
    }
    
    int num_branch_paths = 5 + rnd() % 5;
    for (int i = 0; i < num_branch_paths; i++) {
        int branch_start = 20 + rnd() % (m - 40);
        int branch_height = path_height - (2 + rnd() % 4);
        int branch_length = 5 + rnd() % 10;
        
        for (int j = branch_start; j < branch_start + branch_length && j <= m; j++) {
            if (mp[branch_height][j] == '#') {
                mp[branch_height][j] = (rnd() % 2 == 0) ? '<' : '>';
            }
            
            if (rnd() % 3 == 0) {
                int spike_x = branch_height + (rnd() % 3) - 1;
                int spike_y = j + (rnd() % 3) - 1;
                
                if (spike_x >= 1 && spike_x <= n && spike_y >= 1 && spike_y <= m && 
                    mp[spike_x][spike_y] == '#') {
                    mp[spike_x][spike_y] = '@';
                }
            }
        }
    }
    
    out << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            out << mp[i][j];
        }
        out << endl;
    }
    out.close();
}

void putong_map(int n, int m) {
    ofstream out("play.in");
    mt19937 rnd(time(0));
    vector<vector<char> > mp(n+1, vector<char>(m+1, '#'));
    
    int platform_height = n/2;
    
    for (int j = 1; j <= m; j += 1) {
        if (rnd() % 6 > 2) {
            mp[platform_height][j] = '*';
        }
    }
    
    int num_platform_variations = 25 + rnd() % 15;
    for (int i = 0; i < num_platform_variations; i++) {
        int variation_type = rnd() % 6;
        
        if (variation_type == 0) {
            int height = platform_height - (4 + rnd() % 6);
            int start_j = 25 + rnd() % (m - 50);
            int length = 4 + rnd() % 6;
            
            for (int j = start_j; j < start_j + length && j <= m; j++) {
                mp[height][j] = '*';
            }
        } else if (variation_type == 1) {
            int height = platform_height + (4 + rnd() % 6);
            int start_j = 25 + rnd() % (m - 50);
            int length = 4 + rnd() % 6;
            
            for (int j = start_j; j < start_j + length && j <= m; j++) {
                mp[height][j] = '*';
            }
        } else if (variation_type == 2) {
            int start_j = 35 + rnd() % (m - 70);
            int hole_length = 6 + rnd() % 6;
            
            for (int j = start_j; j < start_j + hole_length && j <= m; j++) {
                mp[platform_height][j] = '#';
            }
            
            for (int j = start_j; j < start_j + hole_length && j <= m; j++) {
                if (platform_height + 3 <= n && rnd() % 3 == 0) {
                    mp[platform_height + 3][j] = '@';
                }
            }
        } else if (variation_type == 3) {
            int column_x = 30 + rnd() % (m - 60);
            int column_height = 5 + rnd() % 8;
            int column_start = platform_height - column_height;
            
            for (int h = column_start; h <= platform_height; h++) {
                if (h >= 1 && h <= n) {
                    mp[h][column_x] = '*';
                }
            }
        } else if (variation_type == 4) {
            int start_x = 25 + rnd() % (m - 50);
            int start_y = platform_height - (4 + rnd() % 6);
            int end_y = platform_height + (4 + rnd() % 6);
            int length = 10 + rnd() % 10;
            
            for (int j = 0; j < length && start_x + j <= m; j++) {
                int current_y = start_y + (end_y - start_y) * j / length;
                if (current_y >= 1 && current_y <= n) {
                    mp[current_y][start_x + j] = '*';
                }
            }
        } else {
            int cluster_x = 30 + rnd() % (m - 60);
            int cluster_y = platform_height - (3 + rnd() % 5);
            int cluster_size = 3 + rnd() % 4;
            
            for (int dx = 0; dx < cluster_size; dx++) {
                for (int dy = 0; dy < cluster_size; dy++) {
                    if (rnd() % 3 == 0) {
                        int pos_x = cluster_x + dx * 2;
                        int pos_y = cluster_y + dy;
                        
                        if (pos_x >= 1 && pos_x <= m && pos_y >= 1 && pos_y <= n) {
                            mp[pos_y][pos_x] = '*';
                        }
                    }
                }
            }
        }
    }
    
    int num_spikes = 60 + rnd() % 30;
    int num_death_spikes = 35 + rnd() % 20;
    
    for (int i = 0; i < num_spikes; i++) {
        int spike_x, spike_y;
        
        do {
            spike_x = platform_height - 1;
            spike_y = 35 + rnd() % (m - 70);
        } while (mp[spike_x + 1][spike_y] != '*' && 
                 mp[spike_x + 1][spike_y + 1] != '*' &&
                 mp[spike_x + 1][spike_y - 1] != '*');
        
        int spike_type = rnd() % 4;
        switch(spike_type) {
            case 0: mp[spike_x][spike_y] = '<'; break;
            case 1: mp[spike_x][spike_y] = '>'; break;
            case 2: mp[spike_x][spike_y] = '^'; break;
            case 3: mp[spike_x][spike_y] = 'V'; break;
        }
    }
    
    for (int i = 0; i < num_death_spikes; i++) {
        int spike_x = 5 + rnd() % (n - 10);
        int spike_y = 40 + rnd() % (m - 80);
        
        if (mp[spike_x][spike_y] == '#') {
            bool too_close_to_path = false;
            for (int dx = -2; dx <= 2; dx++) {
                for (int dy = -2; dy <= 2; dy++) {
                    int check_x = spike_x + dx;
                    int check_y = spike_y + dy;
                    if (check_x >= 1 && check_x <= n && check_y >= 1 && check_y <= m) {
                        if (mp[check_x][check_y] == '*' && 
                            (abs(dx) + abs(dy)) < 2) {
                            too_close_to_path = true;
                            break;
                        }
                    }
                }
                if (too_close_to_path) break;
            }
            
            if (!too_close_to_path) {
                mp[spike_x][spike_y] = '@';
            }
        }
    }
    
    int num_dash_challenges = 10 + rnd() % 5;
    for (int i = 0; i < num_dash_challenges; i++) {
        int challenge_start = 45 + i * 25;
        int gap_length = 14 + rnd() % 10;
        
        for (int j = challenge_start; j < challenge_start + gap_length && j <= m; j++) {
            mp[platform_height][j] = '#';
        }
        
        for (int j = challenge_start; j < challenge_start + gap_length && j <= m; j++) {
            if (platform_height + 3 <= n) {
                if (rnd() % 2 == 0) {
                    mp[platform_height + 3][j] = '@';
                } else if (rnd() % 2 == 0) {
                    mp[platform_height + 2][j] = '^';
                }
                
                if (rnd() % 4 == 0 && platform_height + 4 <= n) {
                    mp[platform_height + 4][j] = '@';
                }
            }
        }
        
        int reward_height = platform_height - (4 + rnd() % 5);
        int reward_length = 4 + rnd() % 4;
        
        for (int j = challenge_start + gap_length; 
             j < challenge_start + gap_length + reward_length && j <= m; j++) {
            mp[reward_height][j] = '*';
        }
        
        for (int j = challenge_start + gap_length; 
             j < challenge_start + gap_length + reward_length && j <= m; j++) {
            if (reward_height - 1 >= 1 && rnd() % 3 == 0) {
                mp[reward_height - 1][j] = 'V';
            }
        }
    }
    
    int num_puzzles = 8 + rnd() % 5;
    for (int i = 0; i < num_puzzles; i++) {
        int puzzle_start = 70 + i * 35;
        int puzzle_type = rnd() % 4;
        
        if (puzzle_type == 0) {
            for (int j = puzzle_start; j < puzzle_start + 25 && j <= m; j++) {
                if (j % 5 == 0) {
                    mp[platform_height - 4][j] = '*';
                } else if (j % 5 == 2) {
                    mp[platform_height + 3][j] = '*';
                } else if (j % 5 == 4) {
                    mp[platform_height - 2][j] = '*';
                } else {
                    mp[platform_height][j] = '*';
                }
            }
        } else if (puzzle_type == 1) {
            for (int j = puzzle_start; j < puzzle_start + 30 && j <= m; j++) {
                if (j % 6 != 0) {
                    mp[platform_height][j] = '*';
                }
            }
            for (int j = puzzle_start; j < puzzle_start + 30 && j <= m; j++) {
                if (j % 6 == 0) {
                    if (platform_height + 2 <= n) {
                        mp[platform_height + 2][j] = '^';
                    }
                    if (platform_height + 3 <= n && rnd() % 2 == 0) {
                        mp[platform_height + 3][j] = '@';
                    }
                }
            }
        } else if (puzzle_type == 2) {
            for (int j = puzzle_start; j < puzzle_start + 22 && j <= m; j++) {
                if (j % 4 == 0) {
                    for (int h = platform_height - 6; h <= platform_height; h++) {
                        if (h >= 1 && h <= n) {
                            mp[h][j] = '*';
                        }
                    }
                    if (platform_height - 7 >= 1 && rnd() % 3 == 0) {
                        mp[platform_height - 7][j] = 'V';
                    }
                }
            }
        } else {
            for (int j = puzzle_start; j < puzzle_start + 28 && j <= m; j++) {
                if (j % 7 < 5) {
                    mp[platform_height][j] = '*';
                }
                
                if (j % 7 == 6 && platform_height - 3 >= 1) {
                    mp[platform_height - 3][j] = '*';
                }
                
                if (j % 7 == 0 && platform_height + 3 <= n) {
                    mp[platform_height + 3][j] = '^';
                }
            }
        }
    }
    
    int start_x = platform_height - 1;
    int start_y = 5;
    mp[start_x][start_y] = 'P';
    mp[start_x+1][start_y] = '*';
    for (int i = start_x - 2; i <= start_x + 2; i++) {
        for (int j = start_y - 2; j <= start_y + 2; j++) {
            if (i >= 1 && i <= n && j >= 1 && j <= m) {
                if (mp[i][j] == '@' && (abs(i - start_x) + abs(j - start_y)) < 2) {
                    mp[i][j] = '#';
                }
            }
        }
    }
    
    int end_x = platform_height;
    int end_y = m - 8;
    mp[end_x][end_y] = 'E';
    
    for (int j = end_y - 20; j < end_y; j++) {
        if (j % 5 == 0 && platform_height - 4 >= 1) {
            mp[platform_height - 4][j] = '*';
        } else if (j % 5 == 2 && platform_height + 3 <= n) {
            mp[platform_height + 3][j] = '*';
        } else if (j % 5 == 3 && platform_height - 2 >= 1) {
            mp[platform_height - 2][j] = '*';
        } else if (j % 5 == 4) {
            // 留空
        } else {
            mp[platform_height][j] = '*';
        }
    }
    
    for (int j = end_y - 15; j < end_y - 5; j++) {
        if (j % 4 == 0 && platform_height + 2 <= n) {
            mp[platform_height + 2][j] = '^';
        }
        if (j % 6 == 0 && platform_height - 3 >= 1) {
            mp[platform_height - 3][j] = 'V';
        }
        if (j % 8 == 0 && platform_height + 4 <= n) {
            mp[platform_height + 4][j] = '@';
        }
    }
    
    int num_collectibles = 40 + rnd() % 20;
    int num_secrets = 5 + rnd() % 4;
    
    for (int i = 0; i < num_collectibles; i++) {
        int collect_x = platform_height - (3 + rnd() % 10);
        int collect_y = 30 + rnd() % (m - 60);
        
        if (mp[collect_x][collect_y] == '#' && 
            ((collect_x < n && mp[collect_x + 1][collect_y] == '*') ||
             (collect_x > 1 && mp[collect_x - 1][collect_y] == '*') ||
             (collect_y < m && mp[collect_x][collect_y + 1] == '*') ||
             (collect_y > 1 && mp[collect_x][collect_y - 1] == '*'))) {
            mp[collect_x][collect_y] = '@';
            
            if (rnd() % 3 == 0 && collect_x - 1 >= 1) {
                mp[collect_x - 1][collect_y] = 'V';
            }
            if (rnd() % 3 == 0 && collect_x + 1 <= n) {
                mp[collect_x + 1][collect_y] = '^';
            }
        }
    }
    
    for (int i = 0; i < num_secrets; i++) {
        int secret_x = platform_height - (6 + rnd() % 8);
        int secret_y = 50 + rnd() % (m - 100);
        int secret_size = 3 + rnd() % 4;
        
        bool valid_location = true;
        for (int x = secret_x; x < secret_x + secret_size && x <= n; x++) {
            for (int y = secret_y; y < secret_y + secret_size && y <= m; y++) {
                if (mp[x][y] != '#') {
                    valid_location = false;
                    break;
                }
            }
            if (!valid_location) break;
        }
        
        if (valid_location) {
            for (int x = secret_x; x < secret_x + secret_size && x <= n; x++) {
                for (int y = secret_y; y < secret_y + secret_size && y <= m; y++) {
                    mp[x][y] = '#';
                }
            }
            
            for (int x = secret_x - 1; x <= secret_x + secret_size && x <= n; x++) {
                for (int y = secret_y - 1; y <= secret_y + secret_size && y <= m; y++) {
                    if (x < secret_x || x >= secret_x + secret_size || 
                        y < secret_y || y >= secret_y + secret_size) {
                        if (mp[x][y] == '#') {
                            mp[x][y] = '@';
                        }
                    }
                }
            }
            
            int entrance_x = secret_x + rnd() % secret_size;
            int entrance_y = secret_y + rnd() % secret_size;
            mp[entrance_x][entrance_y] = '#';
        }
    }
    
    out << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            out << mp[i][j];
        }
        out << endl;
    }
    out.close();
}

void jiandan_map(int n, int m) {
    ofstream out("play.in");
    mt19937 rnd(time(0));
    vector<vector<char> > mp(n+1, vector<char>(m+1, '#'));
    
    int platform_height = n/2;
    
    for (int j = 1; j <= m; j += 1) {
        if (rnd() % 10 > 1) {
            mp[platform_height][j] = '*';
        }
    }
    
    int num_platform_variations = 15 + rnd() % 10;
    for (int i = 0; i < num_platform_variations; i++) {
        int variation_type = rnd() % 4;
        
        if (variation_type == 0) {
            int height = platform_height - (2 + rnd() % 4);
            int start_j = 15 + rnd() % (m - 30);
            int length = 6 + rnd() % 8;
            
            for (int j = start_j; j < start_j + length && j <= m; j++) {
                mp[height][j] = '*';
            }
        } else if (variation_type == 1) {
            int height = platform_height + (2 + rnd() % 4);
            int start_j = 15 + rnd() % (m - 30);
            int length = 6 + rnd() % 8;
            
            for (int j = start_j; j < start_j + length && j <= m; j++) {
                mp[height][j] = '*';
            }
        } else if (variation_type == 2) {
            int start_j = 25 + rnd() % (m - 50);
            int hole_length = 4 + rnd() % 4;
            
            for (int j = start_j; j < start_j + hole_length && j <= m; j++) {
                mp[platform_height][j] = '#';
            }
        } else {
            int column_x = 20 + rnd() % (m - 40);
            int column_height = 3 + rnd() % 4;
            int column_start = platform_height - column_height;
            
            for (int h = column_start; h <= platform_height; h++) {
                if (h >= 1 && h <= n) {
                    mp[h][column_x] = '*';
                }
            }
        }
    }
    
    int num_spikes = 25 + rnd() % 15;
    for (int i = 0; i < num_spikes; i++) {
        int spike_x, spike_y;
        
        do {
            spike_x = platform_height - 1;
            spike_y = 25 + rnd() % (m - 50);
        } while (mp[spike_x + 1][spike_y] != '*' && 
                 mp[spike_x + 1][spike_y + 1] != '*' &&
                 mp[spike_x + 1][spike_y - 1] != '*');
        
        int spike_type = rnd() % 4;
        switch(spike_type) {
            case 0: mp[spike_x][spike_y] = '<'; break;
            case 1: mp[spike_x][spike_y] = '>'; break;
            case 2: mp[spike_x][spike_y] = '^'; break;
            case 3: mp[spike_x][spike_y] = 'V'; break;
        }
    }
    
    int num_dash_challenges = 6 + rnd() % 4;
    for (int i = 0; i < num_dash_challenges; i++) {
        int challenge_start = 30 + i * 35;
        int gap_length = 10 + rnd() % 6;
        
        for (int j = challenge_start; j < challenge_start + gap_length && j <= m; j++) {
            mp[platform_height][j] = '#';
        }
        
        int reward_height = platform_height - (2 + rnd() % 3);
        int reward_length = 4 + rnd() % 4;
        
        for (int j = challenge_start + gap_length; 
             j < challenge_start + gap_length + reward_length && j <= m; j++) {
            mp[reward_height][j] = '*';
        }
        
        for (int j = challenge_start; j < challenge_start + gap_length && j <= m; j++) {
            if (platform_height + 2 <= n) {
                mp[platform_height + 2][j] = '@';
            }
        }
    }
    
    int num_puzzles = 4 + rnd() % 3;
    for (int i = 0; i < num_puzzles; i++) {
        int puzzle_start = 50 + i * 50;
        int puzzle_type = rnd() % 2;
        
        if (puzzle_type == 0) {
            for (int j = puzzle_start; j < puzzle_start + 15 && j <= m; j++) {
                if (j % 3 == 0) {
                    mp[platform_height - 2][j] = '*';
                } else {
                    mp[platform_height][j] = '*';
                }
            }
        } else {
            for (int j = puzzle_start; j < puzzle_start + 15 && j <= m; j++) {
                if (j % 4 != 0) {
                    mp[platform_height][j] = '*';
                }
            }
        }
    }
    
    int start_x = platform_height - 1;
    int start_y = 5;
    mp[start_x][start_y] = 'P';
    mp[start_x+1][start_y] = '*';
    for (int i = start_x - 1; i <= start_x + 1; i++) {
        for (int j = start_y - 1; j <= start_y + 1; j++) {
            if (i >= 1 && i <= n && j >= 1 && j <= m) {
                if (mp[i][j] == '<' || mp[i][j] == '>' || 
                    mp[i][j] == '^' || mp[i][j] == 'V' || 
                    mp[i][j] == '@') {
                    mp[i][j] = '*';
                }
            }
        }
    }
    
    int end_x = platform_height;
    int end_y = m - 5;
    mp[end_x][end_y] = 'E';
    
    for (int i = end_x - 2; i <= end_x + 2; i++) {
        for (int j = end_y - 3; j <= end_y + 3; j++) {
            if (i >= 1 && i <= n && j >= 1 && j <= m) {
                if (mp[i][j] == '<' || mp[i][j] == '>' || 
                    mp[i][j] == '^' || mp[i][j] == 'V' || 
                    mp[i][j] == '@') {
                    mp[i][j] = '*';
                }
            }
        }
    }
    
    for (int j = end_y - 8; j < end_y; j++) {
        if (j % 3 == 0 && platform_height - 2 >= 1) {
            mp[platform_height - 2][j] = '*';
        } else {
            mp[platform_height][j] = '*';
        }
    }
    
    int num_collectibles = 25 + rnd() % 10;
    for (int i = 0; i < num_collectibles; i++) {
        int collect_x = platform_height - (1 + rnd() % 5);
        int collect_y = 20 + rnd() % (m - 40);
        
        if (mp[collect_x][collect_y] == '#' && 
            (mp[collect_x + 1][collect_y] == '*' || 
             (collect_x < n && mp[collect_x + 1][collect_y] == '#' && 
              collect_x + 2 <= n && mp[collect_x + 2][collect_y] == '*'))) {
            mp[collect_x][collect_y] = '@';
        }
    }
    
    out << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            out << mp[i][j];
        }
        out << endl;
    }
    out.close();
}

// ==================== main.cpp ====================
int n,m,nn,mm;
char mp[5000][5000],mmpp[5000][5000];
char last[100][100];
int cctx[5000][5000];
int x,y;
bool pdxy()
{
	if(x>=1&&x<=n&&y>=1&&y<=n)return 1;
	return 0;
}
void mes(string content, string title) {
	MessageBox(NULL, content.c_str(), title.c_str(), MB_OK);
	return;
}
string OpenFileDialog(HWND hwnd=NULL) {
    OPENFILENAMEA ofn;
    char fileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "In Files\0*.in\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "";
    ofn.lpstrTitle = "选择要打开的地图文件";
    if (GetOpenFileNameA(&ofn)) return fileName;
    return "";
}
std::string GetSaveFilePath(HWND hwnd = NULL) {
    OPENFILENAMEA ofn;
    char fileName[MAX_PATH] ="";
	sprintf(fileName,"paoku_map_%d",(int)(time(0)));
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "In Files\0*.in\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT;
    ofn.lpstrDefExt = "in";
    ofn.lpstrTitle = "保存地图";
    if (GetSaveFileNameA(&ofn)) return fileName;
    return "";
}
std::string GetReplaySavePath(HWND hwnd = NULL) {
    OPENFILENAMEA ofn;
    char fileName[MAX_PATH] ="";
	sprintf(fileName,"replay_%d",(int)(time(0)));
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Replay Files\0*.dat\0All Files\0*.*\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT;
    ofn.lpstrDefExt = "dat";
    ofn.lpstrTitle = "保存回放文件";
    if (GetSaveFileNameA(&ofn)) return fileName;
    return "";
}
string path;
int edt=0;
void print(); 

// ==================== 回放系统 ====================
struct ReplayFrame {
    int x, y, t;
    int flag;   // bit0=冲刺, bit1=二段跳
};
const int MAX_REPLAY_FRAMES = 200000;
ReplayFrame g_replay[MAX_REPLAY_FRAMES];
int g_replayLen = 0;
int g_recBaseT = 0;
int g_lastRecT = 0;

void saveWinReplay(const string& fname)
{
    if (g_replayLen < 2) return;
    
    ifstream min("play.in");
    if (!min.is_open()) return;
    int mn, mm2;
    if (!(min >> mn >> mm2)) { min.close(); return; }
    if (mn <= 0 || mn > 1000 || mm2 <= 0 || mm2 > 1000) { min.close(); return; }
    
    ofstream out(fname.c_str());
    if (!out.is_open()) { min.close(); return; }
    
    out << mn << " " << mm2 << endl;
    for (int i = 0; i < mn; i++) {
        string row;
        min >> row;
        out << row << endl;
    }
    min.close();
    
    out << g_replayLen << endl;
    for (int i = 0; i < g_replayLen; i++) {
        out << g_replay[i].x << " " << g_replay[i].y << " "
            << g_replay[i].t << " " << g_replay[i].flag << endl;
    }
    out.close();
}

void doPlayReplay(ifstream& fin)
{
    int mn, mm2;
    if (!(fin >> mn >> mm2)) {
        mes("回放文件损坏", "错误");
        return;
    }
    if (mn <= 0 || mn > 1000 || mm2 <= 0 || mm2 > 1000) {
        mes("回放地图尺寸无效", "错误");
        return;
    }
    
    fo(i,1,4999)fo(j,1,4999)mp[i][j]='#',cctx[i][j]=0;
    fo(i,1,mn) {
        string row;
        fin >> row;
        fo(j,1,mm2) {
            char ch = (j-1 < (int)row.size()) ? row[j-1] : '#';
            mp[i+20][j+20] = ch;
            if (mp[i+20][j+20] == 'P') mp[i+20][j+20] = '#';
        }
    }
    n = mn + 40;
    m = mm2 + 40;
    
    int len;
    if (!(fin >> len)) return;
    if (len < 2) { mes("回放数据为空", "提示"); return; }
    if (len > MAX_REPLAY_FRAMES) len = MAX_REPLAY_FRAMES;
    
    for (int i = 0; i < len; i++) {
        if (!(fin >> g_replay[i].x >> g_replay[i].y 
                   >> g_replay[i].t >> g_replay[i].flag)) {
            len = i; break;
        }
    }
    g_replayLen = len;
    
    cls();
    mode_con(70,27);
    sys_color("black","white");
    color("white");
    title("回放播放 -by sunnycl");
    no_cursor();
    
    fo(i,1,50)fo(j,1,50)last[i][j]='.';
    
    setpos(1, 24);
    color("yellow");
    fastout("★  精 彩 回 放  ★");
    setpos(2, 22);
    color("gray");
    fastout("按任意键跳过");
    
    x = g_replay[0].x;
    y = g_replay[0].y;
    edt = 0;
    
    int t0 = clock();
    int idx = 0;
    int totalFrames = g_replayLen;
    int startMs = g_replay[0].t;
    
    while (idx < totalFrames) {
        int curMs = clock() - t0 + startMs;
        
        while (idx < totalFrames && g_replay[idx].t <= curMs) {
            x = g_replay[idx].x;
            y = g_replay[idx].y;
            
            if (g_replay[idx].flag & 1) cctx[x+50][y+50] = clock();
            if (g_replay[idx].flag & 2) edt = clock();
            idx++;
        }
        if (idx >= totalFrames) break;
        
        color("white");
        print();
        
        setpos(27, 1);
        color("white");
        printf("进度:%3d%%   ", (idx*100)/totalFrames);
        color("golden");
        printf("回放中...   ");
        color("gray");
        printf("(金色=冲刺 ▼=二段跳)   ");
        
        bool skip = false;
        for (int k = 3; k <= 200; k++) {
            if (pass(k)) { skip = true; break; }
        }
        if (skip) {
            for (int k = 3; k <= 200; k++)
                while(pass(k)) Sleep(5);
            break;
        }
        Sleep(12);
    }
    
    setpos(12, 25);
    color("golden");
    fastout("★  回 放 结 束  ★");
    setpos(13, 24);
    color("white");
    fastout("按任意键返回主菜单");
    while(1) {
        bool any = false;
        for (int k = 3; k <= 200; k++)
            if (pass(k)) { any = true; break; }
        if (any) {
            for (int k = 3; k <= 200; k++)
                while(pass(k)) Sleep(5);
            break;
        }
        Sleep(20);
    }
}

void playReplayFromFile()
{
    OPENFILENAMEA ofn;
    char fileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "Replay Files\0*.dat\0All Files\0*.*\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrTitle = "选择回放文件";
    
    if (!GetOpenFileNameA(&ofn)) {
        return;
    }
    
    string loadpath = fileName;
    
    ifstream fin(loadpath.c_str());
    if (!fin.is_open()) {
        mes("无法打开回放文件", "错误");
        return;
    }
    
    doPlayReplay(fin);
    fin.close();
}

void playReplayMemory()
{
    if (g_replayLen < 2) {
        mes("本局还没有录制到回放数据\n请先玩一会游戏", "本局回放");
        return;
    }
    
    ifstream in("play.in");
    if (!in.is_open()) {
        mes("找不到 play.in, 无法回放", "错误");
        return;
    }
    fo(i,1,4999)fo(j,1,4999)mp[i][j]='#',cctx[i][j]=0;
    in>>n>>m;
    fo(i,1,n)
        fo(j,1,m)
        {
            in>>mp[i+20][j+20];
            if(mp[i+20][j+20]=='P') mp[i+20][j+20]='#';
        }
    n+=40;m+=40;
    in.close();
    
    cls();
    mode_con(70,27);
    sys_color("black","white");
    color("white");
    title("本局回放 -by sunnycl");
    no_cursor();
    
    fo(i,1,50)fo(j,1,50)last[i][j]='.';
    
    setpos(1, 24);
    color("yellow");
    fastout("★  本 局 回 放  ★");
    setpos(2, 22);
    color("gray");
    fastout("按任意键跳过");
    
    x = g_replay[0].x;
    y = g_replay[0].y;
    edt = 0;
    
    int t0 = clock();
    int idx = 0;
    int totalFrames = g_replayLen;
    int startMs = g_replay[0].t;
    
    while (idx < totalFrames) {
        int curMs = clock() - t0 + startMs;
        
        while (idx < totalFrames && g_replay[idx].t <= curMs) {
            x = g_replay[idx].x;
            y = g_replay[idx].y;
            
            if (g_replay[idx].flag & 1) cctx[x+50][y+50] = clock();
            if (g_replay[idx].flag & 2) edt = clock();
            idx++;
        }
        if (idx >= totalFrames) break;
        
        color("white");
        print();
        
        setpos(27, 1);
        color("white");
        printf("进度:%3d%%   ", (idx*100)/totalFrames);
        color("golden");
        printf("回放中...   ");
        color("gray");
        printf("(金色=冲刺 ▼=二段跳)   ");
        
        bool skip = false;
        for (int k = 3; k <= 200; k++) {
            if (pass(k)) { skip = true; break; }
        }
        if (skip) {
            for (int k = 3; k <= 200; k++)
                while(pass(k)) Sleep(5);
            break;
        }
        Sleep(12);
    }
    
    setpos(12, 25);
    color("golden");
    fastout("★  回 放 结 束  ★");
    setpos(13, 24);
    color("white");
    fastout("按任意键继续");
    while(1) {
        bool any = false;
        for (int k = 3; k <= 200; k++)
            if (pass(k)) { any = true; break; }
        if (any) {
            for (int k = 3; k <= 200; k++)
                while(pass(k)) Sleep(5);
            break;
        }
        Sleep(20);
    }
}
// ==================== 回放系统结束 ====================

void print()
{
	fo(i,x-12,x+12)
	{
		fo(j,y-17,y+17)
		{
			int xx=i-(x-12)+1,yy=j-(y-17)+1;
			setpos(xx,yy);
			if(i==x+1&&j==y&&clock()-edt<=150)
			{if(last[xx][yy]!='J')color("yellow"),printf("▼"),last[xx][yy]='J';}
			else if(i==x&&j==y)
			{if(last[xx][yy]!='P')color("skyblue"),printf("●"),last[xx][yy]='P';}
			else if(clock()-cctx[i+50][j+50]<=150)
			{if(last[xx][yy]!='C')color("yellow"),printf("■"),last[xx][yy]='C';}
			else if(i>n||i<1||j>m||j<1)
			{if(last[xx][yy]!='#')printf("  "),last[xx][yy]='#';}
			else if(mp[i][j]=='#'&&last[xx][yy]!='#')
			printf("  "),last[xx][yy]='#';
			else if(mp[i][j]=='*')
			{if(last[xx][yy]!='*')color("white"),printf("■"),last[xx][yy]='*';}
			else if(mp[i][j]=='E')
			{if(last[xx][yy]!='E')color("yellow"),printf("★"),last[xx][yy]='E';}	
			else if(mp[i][j]=='^')
			{if(last[xx][yy]!='^')color("red"),printf("△"),last[xx][yy]='^';}
			else if(mp[i][j]=='<')
			{if(last[xx][yy]!='<')color("red"),printf("＜"),last[xx][yy]='<';}
			else if(mp[i][j]=='>')
			{if(last[xx][yy]!='>')color("red"),printf("＞"),last[xx][yy]='>';}
			else if(mp[i][j]=='V')
			{if(last[xx][yy]!='V')color("red"),printf("▽"),last[xx][yy]='V';}
			else if(mp[i][j]=='@')
			{if(last[xx][yy]!='@')color("red"),printf("＊"),last[xx][yy]='@';}
		}
	}	
}
signed main() 
{
	DisableConsoleSelection();
	sys_color("black","white");
	rand_init();
	no_cursor();
	mode_con(70,27);
	main:
	cls();
	color("white");
	title("跑酷游戏 -by sunnycl");
	setpos(2,3);
	slowout("跑酷游戏 -by sunnycl",20);
	setpos(5,4);
	slowout("开始游戏",20);
	setpos(7,5);
	slowout("新手教程",20);
	setpos(9,6);
	slowout("地图工坊",20);
	setpos(11,7);
	slowout("回放集锦",20);
	setpos(13,8);
	slowout("退出游戏",20);
 	int nandu=0; 
	while(1) 
	{
		while(exepos_x()==5)
		{
			color("yellow");
			setpos(5,3);
			fastout("▕开始游戏");
			setpos(4,4);
			fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
			setpos(6,4);
			fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");	
			if(pass_leftmouse)
			{
				mode_con(70,27);
				cls();
				choosenandu:
				color("white");
				setpos(2,3);
				slowout("选择难度",20);
				setpos(5,4);
				slowout("简单",20);
				setpos(7,5);
				slowout("普通",20);
				setpos(9,6);
				slowout("困难",20);
				setpos(11,7);
				slowout("地狱",20);	
				setpos(13,8);
				slowout("从本地导入",20);	
				while(1) 
				{
					while(exepos_x()==5)
					{
						color("yellow");
						setpos(5,3);
						fastout("▕简单");
						setpos(4,4);
						fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
						setpos(6,4);
						fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
						if(pass_leftmouse){nandu=1;goto getmap;}			
					}
					color("white");
					setpos(5,3);
					fastout("  简单");
					setpos(4,4);
					fastout("                                                                ");
					setpos(6,4);
					fastout("                                                                ");
					while(exepos_x()==7)
					{
						color("yellow");
						setpos(7,4);
						fastout("▕普通");
						setpos(6,5);
						fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
						setpos(8,5);
						fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
						if(pass_leftmouse){nandu=2;goto getmap;}
					}
					color("white");
					setpos(7,4);
					fastout("  普通");
					setpos(6,5);
					fastout("                                                              ");
					setpos(8,5);
					fastout("                                                              ");
					while(exepos_x()==9)
					{
						color("yellow");
						setpos(9,5);
						fastout("▕困难");
						setpos(8,6);
						fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
						setpos(10,6);
						fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
						if(pass_leftmouse){nandu=3;goto getmap;}	
					}
					color("white");
					setpos(9,5);
					fastout("  困难");
					setpos(8,6);
					fastout("                                                            ");
					setpos(10,6);
					fastout("                                                            ");
					while(exepos_x()==11)
					{
						color("yellow");
						setpos(11,6);
						fastout("▕地狱");
						setpos(10,7);
						fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
						setpos(12,7);
						fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
						if(pass_leftmouse){nandu=4;goto getmap;}	
					}
					color("white");
					setpos(11,6);
					fastout("  地狱");
					setpos(10,7);
					fastout("                                                          ");
					setpos(12,7);
					fastout("                                                          ");		
					while(exepos_x()==13)
					{
						color("yellow");
						setpos(13,7);
						fastout("▕从本地导入");
						setpos(12,8);
						fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
						setpos(14,8);
						fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
						if(pass_leftmouse)
						{
							nandu=5;
							path=OpenFileDialog();
							if(path=="")
							{
								mes("导入失败","提示");
								goto choosenandu; 
							}
							goto getmap;
						}	
					}
					color("white");
					setpos(13,7);
					fastout("  从本地导入");
					setpos(12,8);
					fastout("                                                        ");
					setpos(14,8);
					fastout("                                                        ");	
	
				}			
			}	
		}
		color("white");
		setpos(5,3);
		fastout("  开始游戏");
		setpos(4,4);
		fastout("                                                                ");
		setpos(6,4);
		fastout("                                                                ");
		while(exepos_x()==7)
		{
			color("yellow");
			setpos(7,4);
			fastout("▕新手教程");
			setpos(6,5);
			fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
			setpos(8,5);
			fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
			if(pass_leftmouse)
			{
				cls();
				color("white");
				slowout("\n    新手教程\n\n",30);
				slowout("    游戏指南：\n",30);
				color("skyblue");slowout("      ●",30);color("white");
				slowout("表示你的角色\n",30);
				color("white");slowout("      ■",30);color("white");
				slowout("表示平台，没有危险\n",30);
				color("red");slowout("      △▽＜＞",30);color("white");
				slowout("表示不同方向的尖刺\n",30);
				color("red");slowout("      △▽＜＞",30);color("white");
				slowout("是单一方向的尖刺，只会在单一方向上才能对你造成伤害\n",30);
				slowout("      也就是说，你可以贴着尖刺的背面走\n",30);
				color("red");slowout("      ＊",30);color("white");
				slowout("是全方向的尖刺，会在所有方向上才能对你造成伤害\n",30);
				color("yellow");slowout("      ★",30);color("white");
				slowout("表示终点；\n",30);
				slowout("      你的目标是到达终点，死亡就会回到原点，并且总耗时增加5秒\n\n",30);
				slowout("    操作指南：\n",30);
				slowout("      你可以按住 A/D 移动，W 跳跃，在空中可以二段跳，\n",30);
				slowout("      按下<或>可以进行对应方向的冲刺，按下W可以提前结束冲刺。\n      冲刺的CD为2秒，二段跳可以取消冲刺CD。\n",30);
				slowout("      在冲刺时，如果下面有平台或者尖刺，那么就可以刷新二段跳。\n\n",30);
				slowout("    好了，你可以开始你的挑战了！\n    ",30);
				system("pause");
				goto main;
			}
		}
		color("white");
		setpos(7,4);
		fastout("  新手教程");
		setpos(6,5);
		fastout("                                                              ");
		setpos(8,5);
		fastout("                                                              ");
		while(exepos_x()==9)
		{
			color("yellow");
			setpos(9,5);
			fastout("▕地图工坊");
			setpos(8,6);
			fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
			setpos(10,6);
			fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
			if(pass_leftmouse)
			{
				goto map_editor;
			}
		}
		color("white");
		setpos(9,5);
		fastout("  地图工坊");
		setpos(8,6);
		fastout("                                                            ");
		setpos(10,6);
		fastout("                                                            ");
		
		while(exepos_x()==11)
		{
			color("yellow");
			setpos(11,6);
			fastout("▕回放集锦");
			setpos(10,7);
			fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
			setpos(12,7);
			fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
			if(pass_leftmouse)
			{
				while(pass_leftmouse) Sleep(10);
				playReplayFromFile();
				mode_con(70,27);
				goto main;
			}
		}
		color("white");
		setpos(11,6);
		fastout("  回放集锦");
		setpos(10,7);
		fastout("                                                          ");
		setpos(12,7);
		fastout("                                                          ");
		
		while(exepos_x()==13)
		{
			color("yellow");
			setpos(13,7);
			fastout("▕退出游戏");
			setpos(12,8);
			fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
			setpos(14,8);
			fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
			if(pass_leftmouse)exit(0);	
		}
		color("white");
		setpos(13,7);
		fastout("  退出游戏");
		setpos(12,8);
		fastout("                                                        ");
		setpos(14,8);
		fastout("                                                        ");		
	}
	
	// ================= 地图工坊 =================
	map_editor:
	{
		cls();
		title("地图工坊 -by sunnycl");
		color("white");
		no_cursor();
		
		const int MOFF = 2000;
		const int XLIM = 1900;
		const int YLIM = 1900;
		
		memset(mmpp, '#', sizeof(mmpp));
		
		int min_x = 0, max_x = 29;
		int min_y = 0, max_y = 99;
		
		for(int y = 0; y <= 99; y++)
			mmpp[15 + MOFF][y + MOFF] = '*';
		mmpp[14 + MOFF][3 + MOFF] = 'P';
		mmpp[14 + MOFF][96 + MOFF] = 'E';
		
		int cx = 14, cy = 3;
		char cur = '*';
		
		const int VH = 24, VW = 35;
		const int midR = VH / 2;
		const int midC = VW / 2;
		
		int tmove = clock();
		int tplace = clock();
		
		bool key_s = false, key_l = false, key_q = false, key_esc = false;
		
		while(1)
		{
			for(int r = 0; r < VH; r++)
			{
				for(int c = 0; c < VW; c++)
				{
					int mx = cx + (r - midR);
					int my = cy + (c - midC);
					setpos(r + 1, c + 1);
					
					bool inb   = (mx >= min_x && mx <= max_x && my >= min_y && my <= max_y);
					bool iscur = (r == midR && c == midC);
					
					char cell = inb ? mmpp[mx + MOFF][my + MOFF] : '#';
					
					int colorCode;
					if(iscur)             colorCode = 0x60;
					else if(!inb)         colorCode = 0x08;
					else
					{
						switch(cell)
						{
							case '#': colorCode = 0x08; break;
							case '*': colorCode = 0x0F; break;
							case 'E': colorCode = 0x0E; break;
							case 'P': colorCode = 0x0B; break;
							default:  colorCode = 0x0C; break;
						}
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
					
					if(!inb || cell == '#')  printf(". ");
					else if(cell == '*')     printf("■");
					else if(cell == 'E')     printf("★");
					else if(cell == 'P')     printf("●");
					else if(cell == '^')     printf("△");
					else if(cell == 'V')     printf("▽");
					else if(cell == '<')     printf("＜");
					else if(cell == '>')     printf("＞");
					else if(cell == '@')     printf("＊");
					else                     printf("  ");
				}
			}
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			
			setpos(25, 1);
			printf("当前方块: ");
			int cc = 0x0F;
			const char* cname = "空气";
			if(cur == '#')      { cc = 0x08; cname = "空气"; }
			else if(cur == '*') { cc = 0x0F; cname = "平台"; }
			else if(cur == 'E') { cc = 0x0E; cname = "终点"; }
			else if(cur == 'P') { cc = 0x0B; cname = "出生"; }
			else if(cur == '^') { cc = 0x0C; cname = "上刺"; }
			else if(cur == 'V') { cc = 0x0C; cname = "下刺"; }
			else if(cur == '<') { cc = 0x0C; cname = "左刺"; }
			else if(cur == '>') { cc = 0x0C; cname = "右刺"; }
			else if(cur == '@') { cc = 0x0C; cname = "全刺"; }
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cc);
			printf("%s", cname);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			printf("                          ");
			
			setpos(26, 1);
			printf("1空气 2平台 3终点 4上刺 5下刺 6左刺 7右刺 8全刺 9出生点      ");
			
			setpos(27, 1);
			printf("方向键移动  空格放置  S保存  L加载  Q/Esc返回       ");
			
			if(clock() - tmove >= 80)
			{
				if(pass_up)         { cx--; tmove = clock(); }
				else if(pass_down)  { cx++; tmove = clock(); }
				else if(pass_left)  { cy--; tmove = clock(); }
				else if(pass_right) { cy++; tmove = clock(); }
			}
			
			if(cx < -XLIM) cx = -XLIM;
			if(cx >  XLIM) cx =  XLIM;
			if(cy < -YLIM) cy = -YLIM;
			if(cy >  YLIM) cy =  YLIM;
			
			if(pass_space && clock() - tplace >= 100)
			{
				mmpp[cx + MOFF][cy + MOFF] = cur;
				
				if(cur != '#')
				{
					if(cx < min_x) min_x = cx;
					if(cx > max_x) max_x = cx;
					if(cy < min_y) min_y = cy;
					if(cy > max_y) max_y = cy;
				}
				else
				{
					bool changed = true;
					while(changed)
					{
						changed = false;
						if(min_x < max_x)
						{
							bool empty = true;
							for(int y = min_y; y <= max_y; y++)
								if(mmpp[min_x + MOFF][y + MOFF] != '#') { empty = false; break; }
							if(empty) { min_x++; changed = true; }
						}
						if(max_x > min_x)
						{
							bool empty = true;
							for(int y = min_y; y <= max_y; y++)
								if(mmpp[max_x + MOFF][y + MOFF] != '#') { empty = false; break; }
							if(empty) { max_x--; changed = true; }
						}
						if(min_y < max_y)
						{
							bool empty = true;
							for(int x = min_x; x <= max_x; x++)
								if(mmpp[x + MOFF][min_y + MOFF] != '#') { empty = false; break; }
							if(empty) { min_y++; changed = true; }
						}
						if(max_y > min_y)
						{
							bool empty = true;
							for(int x = min_x; x <= max_x; x++)
								if(mmpp[x + MOFF][max_y + MOFF] != '#') { empty = false; break; }
							if(empty) { max_y--; changed = true; }
						}
					}
				}
				tplace = clock();
			}
			
			if(pass('1')) cur = '#';
			if(pass('2')) cur = '*';
			if(pass('3')) cur = 'E';
			if(pass('4')) cur = '^';
			if(pass('5')) cur = 'V';
			if(pass('6')) cur = '<';
			if(pass('7')) cur = '>';
			if(pass('8')) cur = '@';
			if(pass('9')) cur = 'P';
			
			if(pass('S'))
			{
				if(!key_s)
				{
					key_s = true;
					while(pass('S')) Sleep(10);
					string savepath = GetSaveFilePath();
					if(savepath != "")
					{
						ofstream out(savepath.c_str());
						int en = max_x - min_x + 1;
						int em = max_y - min_y + 1;
						out << en << " " << em << endl;
						for(int i = 0; i < en; i++)
						{
							for(int j = 0; j < em; j++)
								out << mmpp[min_x + i + MOFF][min_y + j + MOFF];
							out << endl;
						}
						out.close();
						
						setpos(12, 6);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x2A);
						printf("  保存成功! %s", savepath.c_str());
						for(int k = 0; k < 60; k++) printf(" ");
						setpos(13, 6);
						printf("  地图尺寸: %d x %d", en, em);
						for(int k = 0; k < 60; k++) printf(" ");
						Sleep(700);
					}
				}
			}
			else key_s = false;
			
			if(pass('L'))
			{
				if(!key_l)
				{
					key_l = true;
					while(pass('L')) Sleep(10);
					string loadpath = OpenFileDialog();
					if(loadpath != "")
					{
						ifstream in(loadpath.c_str());
						int ln, lm;
						if(in >> ln >> lm && ln >= 1 && ln <= 1000 && lm >= 1 && lm <= 1000)
						{
							memset(mmpp, '#', sizeof(mmpp));
							min_x = 0; max_x = ln - 1;
							min_y = 0; max_y = lm - 1;
							
							for(int i = 0; i < ln; i++)
							{
								string row;
								in >> row;
								for(int j = 0; j < lm && j < (int)row.size(); j++)
									mmpp[i + MOFF][j + MOFF] = row[j];
							}
							
							cx = 0; cy = 0;
							bool found = false;
							for(int j = 0; j < lm && !found; j++)
								for(int i = 0; i < ln && !found; i++)
									if(mmpp[i + MOFF][j + MOFF] != '#')
									{
										cx = i; cy = j; found = true;
									}
							
							setpos(12, 6);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x2A);
							printf("  加载成功! %s", loadpath.c_str());
							for(int k = 0; k < 60; k++) printf(" ");
							setpos(13, 6);
							printf("  地图尺寸: %d x %d", ln, lm);
							for(int k = 0; k < 60; k++) printf(" ");
							Sleep(700);
						}
						else
						{
							setpos(12, 6);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4E);
							printf("  加载失败: 地图尺寸无效 (最大 1000x1000)");
							for(int k = 0; k < 60; k++) printf(" ");
							setpos(13, 6);
							printf("  请检查文件格式，或换一张地图试试");
							for(int k = 0; k < 60; k++) printf(" ");
							Sleep(900);
						}
						in.close();
					}
				}
			}
			else key_l = false;
			
			if(pass('Q'))
			{
				if(!key_q)
				{
					key_q = true;
					while(pass('Q')) Sleep(10);
					goto main;
				}
			}
			else key_q = false;
			
			if(pass_esc)
			{
				if(!key_esc)
				{
					key_esc = true;
					while(pass_esc) Sleep(10);
					goto main;
				}
			}
			else key_esc = false;
			
			Sleep(15);
		}
	}
	
	getmap:
	int start_time=clock(); 
    rand_init();
	if(nandu==1)jiandan_map(30,400); 
	if(nandu==2)putong_map(30,300); 
	if(nandu==3)kunnan_map(30,200); 
	if(nandu==4)diyu_map(30,200); 
	if(nandu==5)
	{
		ifstream in(path.c_str());
		in>>nn>>mm;
		fo(i,1,nn)
			fo(j,1,mm)
				in>>mmpp[i][j];	
		in.close();
		ofstream out("play.in");
		out<<nn<<" "<<mm<<endl;
		fo(i,1,nn)
		{
			fo(j,1,mm)
				out<<mmpp[i][j];
			out<<endl;
		}
		out.close();
	}
    int die=0;
    
	start:
	g_replayLen = 0;
	g_recBaseT = clock();
	g_lastRecT = 0;
	
	mode_con(70,27);
	ifstream in("play.in");
	fo(i,1,4999)fo(j,1,4999)mp[i][j]='#',cctx[i][j]=0;
	in>>n>>m;
	fo(i,1,n)
		fo(j,1,m)
		{
			in>>mp[i+20][j+20];
			if(mp[i+20][j+20]=='P')x=i+20,y=j+20,mp[i+20][j+20]='#';
		}
	n+=40,m+=40;
	in.close();
	int txl=clock(),td=clock()-70,ta=clock()-70,tw=clock()-300,tycs=2,tty=clock(),tyh=10,tyds=2,fx=1,cfx;
	int cc=0,ccjl=10,tcc=clock()-2000,tcc2=clock();
	double zl=1,ty=tyh+1;
	edt=0;
	int fpscnt=0,tfps=clock();
	goto pause;
	while(1)
	{
		if(pass_esc)
		{
			esc:
			int t1=clock();
			cls();
			color("white");
			setpos(2,3);
			slowout("选项",20);
			setpos(5,4);
			slowout("继续游戏",20);
			setpos(7,5);
			slowout("重新开始",20);
			setpos(9,6);
			slowout("导出地图",20);
			setpos(11,7);
			slowout("返回主界面",20);
			while(1) 
			{
				while(exepos_x()==5)
				{
					color("yellow");
					setpos(5,3);
					fastout("▕继续游戏");
					setpos(4,4);
					fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
					setpos(6,4);
					fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
					if(pass_leftmouse)
					{
						while(pass_leftmouse) Sleep(10);
						int t2=clock();
						start_time+=t2-t1;
						goto pause;
					}			
				}
				color("white");
				setpos(5,3);
				fastout("  继续游戏");
				setpos(4,4);
				fastout("                                                                ");
				setpos(6,4);
				fastout("                                                                ");
				while(exepos_x()==7)
				{
					color("yellow");
					setpos(7,4);
					fastout("▕重新开始");
					setpos(6,5);
					fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
					setpos(8,5);
					fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
					if(pass_leftmouse)
					{
						while(pass_leftmouse) Sleep(10);
						goto start;
					}
				}
				color("white");
				setpos(7,4);
				fastout("  重新开始");
				setpos(6,5);
				fastout("                                                              ");
				setpos(8,5);
				fastout("                                                              ");
				while(exepos_x()==9)
				{
					color("yellow");
					setpos(9,5);
					fastout("▕导出地图");
					setpos(8,6);
					fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
					setpos(10,6);
					fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
					if(pass_leftmouse)
					{
						while(pass_leftmouse) Sleep(10);
						path=GetSaveFilePath(); 
						ifstream in("play.in");
						in>>nn>>mm;
						fo(i,1,nn)
							fo(j,1,mm)
								in>>mmpp[i][j];	
						in.close();
						ofstream out(path.c_str());
						out<<nn<<" "<<mm<<endl;
						fo(i,1,nn)
						{
							fo(j,1,mm)
								out<<mmpp[i][j];
							out<<endl;
						}
						out.close();
						int t2=clock();
						start_time+=t2-t1;
						goto esc;
					}	
				}
				color("white");
				setpos(9,5);
				fastout("  导出地图");
				setpos(8,6);
				fastout("                                                            ");
				setpos(10,6);
				fastout("                                                            ");
				
				while(exepos_x()==11)
				{
					color("yellow");
					setpos(11,6);
					fastout("▕返回主界面");
					setpos(10,7);
					fastout("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁");
					setpos(12,7);
					fastout("▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔");
					if(pass_leftmouse){while(pass_leftmouse) Sleep(10); goto main;}
				}
				color("white");
				setpos(11,6);
				fastout("  返回主界面");
				setpos(10,7);
				fastout("                                                        ");
				setpos(12,7);
				fastout("                                                        ");
			}				
		} 
		if(0==1)
		{//pause
			pause:
			
			setpos(26,1);color("white"); 
			fo(i,1,10)printf("-------"); 
			setpos(27,1);
			printf("死亡次数:%d 时间:%d分%d秒 评价:",die,((clock()-start_time)/1000)/60,((clock()-start_time)/1000)%60);
			if(((clock()-start_time)/1000)<=60)color("golden"),cout<<"S";
			else if(((clock()-start_time)/1000)<=120)color("purple"),cout<<"A";
			else if(((clock()-start_time)/1000)<=180)color("red"),cout<<"B";
			else if(((clock()-start_time)/1000)<=240)color("blue"),cout<<"C";
			else if(((clock()-start_time)/1000)<=300)color("green"),cout<<"D";
			else if(((clock()-start_time)/1000)<=360)color("white"),cout<<"E";
			else color("gray"),cout<<"F";
			color("white");
			printf("  冲刺:");
			int ccc;
			if(clock()-tcc>=2000)printf("██"),ccc=0;
			else if(clock()-tcc>=1000)printf("█"),ccc=clock()-tcc-1000;
			
			if(ccc<=125)printf("  ");
			else if(ccc<=250)printf("▏");
			else if(ccc<=375)printf("▎");
			else if(ccc<=500)printf("▍");
			else if(ccc<=625)printf("▌");
			else if(ccc<=750)printf("▋");
			else if(ccc<=875)printf("▊");
			else if(ccc<=1000)printf("▉");
			printf("    ");
			fo(i,1,50)fo(j,1,50)last[i][j]='.';
			print();
			fo(i,1,50)fo(j,1,50)last[i][j]='.';
			int t1=clock(); 
			sys_color("black","white");
			setpos(12,15);color("white"); 
			printf("按下任意键开始"); 
			while(1)
			{
				fo(i,3,200)if(pass(i))goto brea;
				continue;
				brea:break;
			}
			int t2=clock();
			start_time+=t2-t1;
		}
		 
		
		{//print
			fpscnt++;

			setpos(26,1);color("white"); 
			fo(i,1,10)printf("-------"); 
			setpos(27,1);
			printf("死亡次数:%d 时间:%d分%d秒 评价:",die,((clock()-start_time)/1000)/60,((clock()-start_time)/1000)%60);
			if(((clock()-start_time)/1000)<=60)color("golden"),cout<<"S";
			else if(((clock()-start_time)/1000)<=120)color("purple"),cout<<"A";
			else if(((clock()-start_time)/1000)<=180)color("red"),cout<<"B";
			else if(((clock()-start_time)/1000)<=240)color("blue"),cout<<"C";
			else if(((clock()-start_time)/1000)<=300)color("green"),cout<<"D";
			else if(((clock()-start_time)/1000)<=360)color("white"),cout<<"E";
			else color("gray"),cout<<"F";
			color("white");
			printf(" 冲刺:");
			color("white");
			int ccc;
			if(clock()-tcc>=2000)printf("██"),ccc=0;
			else if(clock()-tcc>=1000)printf("█"),ccc=clock()-tcc-1000;
			else ccc=clock()-tcc;
			if(ccc<=125)printf("  ");
			else if(ccc<=250)printf("▏");
			else if(ccc<=375)printf("▎");
			else if(ccc<=500)printf("▍");
			else if(ccc<=625)printf("▌");
			else if(ccc<=750)printf("▋");
			else if(ccc<=875)printf("▊");
			else if(ccc<=1000)printf("▉");
			printf("    ");
			if(clock()-tfps>=1000)
			{
				setpos(27,32);
				printf("fps:%d",fpscnt);
				if(fpscnt<10)printf("   ");
				else if(fpscnt<100)printf("  ");
				else if(fpscnt<1000)printf(" ");
				fpscnt=0;
				tfps=clock();
			}
			print();
		}
		
		{//录制
			if(clock()-g_lastRecT >= 25 && g_replayLen < MAX_REPLAY_FRAMES)
			{
				g_replay[g_replayLen].x = x;
				g_replay[g_replayLen].y = y;
				g_replay[g_replayLen].t = clock() - g_recBaseT;
				g_replay[g_replayLen].flag = 0;
				if(cc) g_replay[g_replayLen].flag |= 1;
				if(edt && clock()-edt <= 150) g_replay[g_replayLen].flag |= 2;
				g_replayLen++;
				g_lastRecT = clock();
			}
		}
		
		if(1==0)
		{//win
			win:
			int x=(clock()-start_time)/1000;
			setpos(12,14);
			sys_color("yellow","white");
			printf("你赢了! 5秒后继续"); 
			Sleep(1000);		
			setpos(12,14);
			printf("你赢了! 4秒后继续"); 	 
			Sleep(1000);
			setpos(12,14);
			printf("你赢了! 3秒后继续");  
			Sleep(1000);	
			setpos(12,14);
			printf("你赢了! 2秒后继续"); 
			Sleep(1000); 	
			setpos(12,14);
			printf("你赢了! 1秒后继续");  
			Sleep(1000);
			cls();
			sys_color("black","white"); 
			color("white"); 
			slowout("\n  结算\n",20);
			slowout("  难度:",20);
			Sleep(1000);
			if(nandu==1)cout<<"简单"<<endl; 
			if(nandu==2)cout<<"普通"<<endl; 
			if(nandu==3)cout<<"困难"<<endl; 
			if(nandu==4)cout<<"地狱"<<endl; 
			if(nandu==5)cout<<"外部导入"<<endl; 
			slowout("  用时:",20);
			Sleep(1000);
			cout<<x/60<<"分"<<x%60<<"秒"<<endl;
			Sleep(1000);
			slowout("  死亡次数:",20);
			Sleep(1000);
			cout<<die<<" 次"<<endl;
			Sleep(1000);
			slowout("  评价:",20);
			Sleep(1000);
			if(x<=60)color("golden"),cout<<"S";
			else if(x<=120)color("purple"),cout<<"A";
			else if(x<=180)color("red"),cout<<"B";
			else if(x<=240)color("blue"),cout<<"C";
			else if(x<=300)color("green"),cout<<"D";
			else if(x<=360)color("white"),cout<<"E";
			else color("gray"),cout<<"F";
			cout<<endl;
			Sleep(1000);
			color("white");
			cout<<endl;
			
			{
				setpos(21, 5);
				color("yellow");
				fastout("★ 是否保存本次通关回放?");

				color("white");
				setpos(23, 5);
				fastout("  保存到文件  ");
				setpos(26, 5);
				fastout("  直接跳过    ");
				setpos(28, 1);
				fastout("                                            ");

				int choice = 0;
				int lastHover = -1;

				while(choice == 0) {
					int mx = exepos_x();
					int hover = 0;
					if(mx == 23) hover = 1;
					else if(mx == 26) hover = 2;

					if(hover != lastHover) {
						lastHover = hover;

						setpos(23, 5);
						if(hover == 1) {
							color("yellow");
							fastout("▕保存到文件  ");
						} else {
							color("white");
							fastout("  保存到文件  ");
						}

						setpos(26, 5);
						if(hover == 2) {
							color("yellow");
							fastout("▕直接跳过    ");
						} else {
							color("white");
							fastout("  直接跳过    ");
						}
						setpos(28, 1);
					}

					if(pass_leftmouse && hover != 0) {
						while(pass_leftmouse) Sleep(10);
						choice = hover;
					}
					Sleep(15);
				}

				if(choice == 1) {
					string rpPath = GetReplaySavePath();
					if(rpPath != "") {
						saveWinReplay(rpPath);
						setpos(21, 5);
						color("green");
						fastout("? 回放已保存!            ");
						setpos(22, 5);
						color("gray");
						cout << "  " << rpPath << "          ";
						Sleep(800);
					} else {
						setpos(21, 5);
						color("gray");
						fastout("  已取消保存              ");
						Sleep(500);
					}
				} else {
					setpos(21, 5);
					fastout("                              ");
					setpos(23, 5);
					fastout("                              ");
					setpos(26, 5);
					fastout("                              ");
				}
			}
			
			goto main;
		}
		
		if(x>n||y>m||x<1||y<1)
		{//die
			die:
			die++;
			int t1=clock(); 
			setpos(12,11);color("white"); 
			sys_color("red","white");
			printf("你死了! 时间增加5秒,按下R以重生"); 
			while(!pass('R'));
			while(pass('R'));
			int t2=clock();
			start_time+=t2-t1;
			start_time-=5000; 
			goto start;
		}	
		
		{//check win and die
			if(!cc&&x>=0&&x<n&&y>=1&&y<=m&&mp[x+1][y]=='E'&&ty>tyh)goto win;
			if(clock()-td>=50&&(pass('D')||cc&&cfx==1)&&!(x<1||x>n||y<0||y>=m)&&(mp[x][y+1]=='E'))goto win;
			if(clock()-ta>=50&&(pass('A')||cc&&cfx==0)&&!(x<1||x>n||y<=1||y>m+1)&&(mp[x][y-1]=='E'))goto win;
			if(!cc&&x>=1&&x<=n+1&&y>=1&&y<=m&&mp[x-1][y]=='E'&&ty<=tyh)goto win;		
			if(!cc&&x>=0&&x<n&&y>=1&&y<=m&&(mp[x+1][y]=='^'||mp[x+1][y]=='@')&&ty>tyh)goto die;
			if(clock()-td>=50&&(pass('D')||cc&&cfx==1)&&!(x<1||x>n||y<0||y>=m)&&(mp[x][y+1]=='<'||mp[x][y+1]=='@'))goto die;
			if(clock()-ta>=50&&(pass('A')||cc&&cfx==0)&&!(x<1||x>n||y<=1||y>m+1)&&(mp[x][y-1]=='>'||mp[x][y-1]=='@'))goto die;
			if(!cc&&x>=1&&x<=n+1&&y>=1&&y<=m&&(mp[x-1][y]=='V'||mp[x-1][y]=='@')&&ty<=tyh)goto die;
		}
		
		{//check 冲刺 
		
			if(cc)cctx[x+50][y+50]=clock();
			if(clock()-tcc>=2000&&pass(188))
			{
				tcc=clock();
				cc=ccjl;
				cfx=0;
			}
			if(clock()-tcc>=2000&&pass(190))
			{
				tcc=clock();
				cc=ccjl;
				cfx=1;
			}
			if(clock()-tcc2>=30&&cc&&cfx==1&&(x<1||x>n||y<0||y>=m||mp[x][y+1]=='#'))
			{
				y++;
				td=ta=clock();	
				tcc2=clock();			
				cc--;
			}
			else if(clock()-tcc2>=30&&cc&&cfx==1&&!(x<1||x>n||y<0||y>=m||mp[x][y+1]=='#'||mp[x][y+1]=='@'||mp[x][y+1]=='<'))cc=0;
			if(clock()-tcc2>=30&&cc&&cfx==0&&(x<1||x>n||y<=1||y>m+1||mp[x][y-1]=='#'))
			{
				y--;
				ta=td=clock();	
				tcc2=clock();	
				cc--;
			}
			else if(clock()-tcc2>=30&&cc&&cfx==0&&!(x<1||x>n||y<=1||y>m+1||mp[x][y-1]=='#'||mp[x][y-1]=='@'||mp[x][y-1]=='>'))cc=0;
			if(pass('W'))cc=0;
		}
		
		{//重力系统 
			if(x-1>=1&&x-1<=n&&y>=1&&y<=m&&mp[x-1][y]!='#')ty=tyh+1;
			if(clock()-tw>=300&&pass('W')&&tycs>0)
			{
				if(tycs==1)edt=clock(),tcc=clock()-2000; 
				tycs--;
				ty=1;
				zl=1;
				tw=clock();
			}
			
			if(!cc&&clock()-tty>=((sqrt(196.0-19.6*(ty-1))-sqrt(196.0-19.6*(ty)))/9.8)*550.0&&ty<=tyh&&(x<=1||x>n+1||y<1||y>m||mp[x-1][y]=='#'))
			{
				x--;
				ty++;
				tty=clock(); 
			}				
			if(!cc&&ty>tyh&&clock()-txl>=(sqrt(zl*2.0/9.8)-sqrt((zl-1)*2.0/9.8))*550.0&&(x>=n||y<1||y>m||x<0||mp[x+1][y]=='#'))
			{
				x++;
				zl++;
				txl=clock();
			}
			if(x>=0&&x<n&&y>=1&&y<=m&&mp[x+1][y]!='#'&&mp[x+1][y]!='@'&&mp[x+1][y]!='^')tycs=tyds,zl=1,ty=tyh+1;
			if(x>=n||x<0||y>m||y<1||mp[x+1][y]=='#')tycs=min(tycs,tyds-1);
		} 
		
		{//移动系统 
			if(clock()-td>=80&&pass('D')&&(x<1||x>n||y<0||y>=m||mp[x][y+1]=='#'))
			{
				y++;fx=1;
				td=clock();					
			}
			if(clock()-ta>=80&&pass('A')&&(x<1||x>n||y<=1||y>m+1||mp[x][y-1]=='#'))
			{
				y--;fx=0;
				ta=clock();					
			}
		} 

	}	
	return 0;
}
