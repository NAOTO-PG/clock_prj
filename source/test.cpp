#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <windows.h>

typedef enum{
    SUCCESS,
    FAILED
} JUDGE;

// Clock クラスの定義
class Clock
{
public:
    int hour;
    int minute;
    int seccond;
    void set(int hour, int minute, int seccond);
    void print();
    void countup();
};

void Clock::set(int hour, int minute, int seccond)
{
    this->hour = hour % 24;
    this->minute = minute % 60;
    this->seccond = seccond % 60;
}

void Clock::print()
{
    printf("%02d:%02d:%02d\n", hour, minute, seccond);
    fflush(stdout);
}

void Clock::countup()
{
    this->seccond++;
    if ( 60 == this->seccond) {
        this->seccond = 0;
        this->minute++;
        if (60 == this->minute) {
            this->minute = 0;
            this->hour++;;
            if (24 == this->hour){
                this->hour = 0;
            }
        }
    }
    
}


JUDGE clock_main(DWORD start_time)
{
    JUDGE ret = FAILED;
    DWORD end = GetTickCount();    // 終了時間

    if (1 <= ((end - start_time)/1000)) {
        ret = SUCCESS;
    }
    return ret;
}


int main(void){
    DWORD start = GetTickCount();       // スタート時間
    JUDGE res = FAILED;
    Clock clk;
    clk.set(22, 28, 0);
    clk.print();

    while(1){
        res = clock_main(start);
        if (SUCCESS == res) {
            /* 秒カウントアップ＆表示 */
            clk.countup();
            clk.print();
            start = GetTickCount();
        }
    }

}