// M?t s? hàm, th? t?c xây d?ng s?n d? dùng cho ti?n
// Ði suu t?m là chính
 
// Define thêm m?t vài phím  kí t?
#define    KEY_A    0x41
#define    KEY_B    0x42
#define    KEY_C    0x43
#define    KEY_D    0x44
#define    KEY_E    0x45
#define    KEY_F    0x46
#define    KEY_G    0x47
#define    KEY_H    0x48
#define    KEY_I    0x49
#define    KEY_J    0x4A
#define    KEY_K    0x4B
#define    KEY_L    0x4C
#define    KEY_M    0x4D
#define    KEY_N    0x4E
#define    KEY_O    0x4F
#define    KEY_P    0x50
#define    KEY_Q    0x51
#define    KEY_R    0x52
#define    KEY_S    0x53
#define    KEY_T    0x54
#define    KEY_U    0x55
#define    KEY_V    0x56
#define    KEY_W    0x57
#define    KEY_X    0x58
#define    KEY_Y    0x59
#define    KEY_Z    0x5A
#define     KEY_LEFT    VK_LEFT
#define     KEY_RIGHT   VK_RIGHT
#define     KEY_UP      VK_UP
#define     KEY_DOWN    VK_DOWN
#define     KEY_ESC     VK_ESCAPE
 
#include "windows.h"
 
double _tickCount; // Bi?n d?m th?i gian, s? d?ng cho Mainloop
 
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); // L?y handle c?a s? console hi?n hành
 
// Ðua con tr? d?n t?a d? x:y
void gotoxy(short x,short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
 
// Ð?t màu cho ch?
void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
 
// Ð?t màu n?n cho ch?
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
 
// Thi?t l?p ch? d? hi?n th?, có fullscreen hay không
BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)
{
    typedef BOOL (WINAPI *SCDMProc_t) (HANDLE, DWORD, LPDWORD);
    SCDMProc_t SetConsoleDisplayMode;
    HMODULE hKernel32;
    BOOL bFreeLib = FALSE, ret;
    const char KERNEL32_NAME[] = "kernel32.dll";
 
    hKernel32 = GetModuleHandleA(KERNEL32_NAME);
    if (hKernel32 == NULL)
    {
        hKernel32 = LoadLibraryA(KERNEL32_NAME);
        if (hKernel32 == NULL)
            return FALSE;
 
        bFreeLib = true;
    }
 
    SetConsoleDisplayMode =
        (SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");
    if (SetConsoleDisplayMode == NULL)
    {
        SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
        ret = FALSE;
    }
    else
    {
        DWORD tmp;
        ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &tmp);
    }
 
    if (bFreeLib)
        FreeLibrary(hKernel32);
 
    return ret;
}
 
// Ð?t ch? d? FullScreen
void setFullScreen()
{
    NT_SetConsoleDisplayMode( GetStdHandle( STD_OUTPUT_HANDLE ), 1 );
}
 
// Thoát kh?i fullscreen
void exitFullScreen()
{
    NT_SetConsoleDisplayMode( GetStdHandle( STD_OUTPUT_HANDLE ), 0 );
}
 
// ?n hi?n con tr? nh?p nháy trong c?a s? Console
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
 
// Xóa toàn b? n?i dung c?a s? console - chôm t? MSDN
void cls( HANDLE hConsole )
{
   COORD coordScreen = { 0, 0 };    // home for the cursor 
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   DWORD dwConSize;
 
// Get the number of character cells in the current buffer. 
 
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
      return;
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
 
   // Fill the entire screen with blanks.
 
   if( !FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
      dwConSize, coordScreen, &cCharsWritten ))
      return;
 
   // Get the current text attribute.
 
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
      return;
 
   // Set the buffer's attributes accordingly.
 
   if( !FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
      dwConSize, coordScreen, &cCharsWritten ))
      return;
 
   // Put the cursor at its home coordinates.
 
   SetConsoleCursorPosition( hConsole, coordScreen );
}
// Vi?t l?i hàm clrscr, không c?n cung du?c nhung d? nhìn vào code cho d?p m?t
void clrscr()
{
    cls(hCon);
}
// Ki?m tra xem phím nào du?c nh?n, tr? v? true n?u phím dó dã du?c nh?n xu?ng
bool checkKey(int key)
{
    return GetAsyncKeyState(key);
}
 
/*
Khúc này mình t? sáng tác thêm d? th?c hi?n vòng l?p chính trong game
R?t ti?n d?ng
Vì g?i mainloop b?ng vòng l?p while s? ch?y r?t nhanh, khó ki?m soát du?c t?c d?
nên gi?i pháp dua ra là dùng m?t b? d?m, c? sau m?t quãng th?i gian tang giá tr?
n?u giá tr? dó d?t d?n m?t m?c nh?t d?nh thì m?i g?i hàm mainloop
Cách này ki?m soát t?c d? game khá t?t
Có thêm m?t cách khác là dùng Timer, nhung ? dây mình làm v?y cho don gi?n
*/
 
// reset l?i b? d?m
void resetTick()
{
    _tickCount = 0;
}
 
// Ð?m, th?c hi?n vi?c tang bi?n d?m
void tickCount()
{
    _tickCount += 0.1;
}
 
// tr? v? giá tr? hi?n t?i c?a bi?n d?m
double getTickCount()
{
    return _tickCount;
}
 
// Th?c hi?n vi?c d?m và g?i vòng l?p chính (mainloop)
// Tham s? truy?n vào g?m có: giá tr? c?c d?i mà sau khi tang d?n m?c dó, s? g?i ti?p mainloop và renderloop
//        gloop: game loop hay còn g?i là mainloop, th?c hi?n vi?c x? lý logic trong game
//        rloop: render loop, th?c hi?n vi?c in các hình ?nh, ch?,.. trong game ra màn hình
void Tick(double maxValue, void (*gloop) (), void (*rloop) ())
{
    tickCount();
        if (getTickCount() > maxValue){ 
            resetTick();
            gloop(); // Game loop
        }
    rloop(); // Render loop
}
