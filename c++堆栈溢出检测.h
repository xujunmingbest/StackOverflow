#ifndef _CALL_STACK_TOOL_2017_10_30_
#define _CALL_STACK_TOOL_2017_10_30_

#include <Windows.h>  
#include <DbgHelp.h>  
#include <iostream>  
#include <vector>  

// ��Ӷ�dbghelp.lib�ı�������  
//  
#pragma comment(lib, "dbghelp.lib")  

using namespace std;

const int MAX_ADDRESS_LENGTH = 32;
const int MAX_NAME_LENGTH = 1024;

// ������Ϣ  
//   
struct CrashInfo
{
	CHAR ErrorCode[MAX_ADDRESS_LENGTH];
	CHAR Address[MAX_ADDRESS_LENGTH];
	CHAR Flags[MAX_ADDRESS_LENGTH];
};

// CallStack��Ϣ  
//   
struct CallStackInfo
{
	CHAR ModuleName[MAX_NAME_LENGTH];
	CHAR MethodName[MAX_NAME_LENGTH];
	CHAR FileName[MAX_NAME_LENGTH];
	CHAR LineNumber[MAX_NAME_LENGTH];
};

// ��ȫ�����ַ�������  
void SafeStrCpy(char* szDest, size_t nMaxDestSize, const char* szSrc);

// �õ����������Ϣ   
CrashInfo GetCrashInfo(const EXCEPTION_RECORD *pRecord);

// �õ�CallStack��Ϣ    
vector<CallStackInfo> GetCallStack(const CONTEXT *pContext);

LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException);

#endif
