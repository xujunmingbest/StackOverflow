#ifndef _CALL_STACK_TOOL_2017_10_30_
#define _CALL_STACK_TOOL_2017_10_30_

#include <Windows.h>  
#include <DbgHelp.h>  
#include <iostream>  
#include <vector>  

// 添加对dbghelp.lib的编译依赖  
//  
#pragma comment(lib, "dbghelp.lib")  

using namespace std;

const int MAX_ADDRESS_LENGTH = 32;
const int MAX_NAME_LENGTH = 1024;

// 崩溃信息  
//   
struct CrashInfo
{
	CHAR ErrorCode[MAX_ADDRESS_LENGTH];
	CHAR Address[MAX_ADDRESS_LENGTH];
	CHAR Flags[MAX_ADDRESS_LENGTH];
};

// CallStack信息  
//   
struct CallStackInfo
{
	CHAR ModuleName[MAX_NAME_LENGTH];
	CHAR MethodName[MAX_NAME_LENGTH];
	CHAR FileName[MAX_NAME_LENGTH];
	CHAR LineNumber[MAX_NAME_LENGTH];
};

// 安全拷贝字符串函数  
void SafeStrCpy(char* szDest, size_t nMaxDestSize, const char* szSrc);

// 得到程序崩溃信息   
CrashInfo GetCrashInfo(const EXCEPTION_RECORD *pRecord);

// 得到CallStack信息    
vector<CallStackInfo> GetCallStack(const CONTEXT *pContext);

LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException);

#endif
