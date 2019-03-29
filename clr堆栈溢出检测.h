#pragma once
using namespace System;
using namespace System::Threading;
using namespace System::IO;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
void writeLog(String^ str);
void Application_ThreadException(Object^ sender, System::Threading::ThreadExceptionEventArgs^ e);
void CurrentDomain_UnhandledException(Object^ sender, UnhandledExceptionEventArgs ^e);
