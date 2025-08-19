// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

#include <iostream>
#include "ftpd_cpm.h"


/* FTP */
static uint8_t g_ftp_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    int iResult = 0;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup() failed with error: %d\n", iResult);
        return 1;
    }
    long addr = inet_addr("127.0.0.1");
    ftpd_cpm_init((uint8_t*)&addr);
    while (1)
    {
        ftpd_cpm_run(g_ftp_buf);
    }
    std::cout << "Hello World!\n";
}

