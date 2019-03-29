#include "clr¶ÑÕ»Òç³ö¼ì²â.h"

void writeLog(String^ str)
{
	if (!Directory::Exists("Log"))
	{
		Directory::CreateDirectory("Log");
	}
	StreamWriter^ sw = gcnew StreamWriter("Log\\ErrLog.txt", true);
	{
		sw->WriteLine(str);
		sw->WriteLine("---------------------------------------------------------");
		sw->Close();
	}
}
void Application_ThreadException(Object^ sender, System::Threading::ThreadExceptionEventArgs^ e)
{
	String^str;
	String^ strDateInfo = "An unhandled exception in the application:" + DateTime::Now.ToString() + "\r\n";
	Exception ^error = e->Exception;
	if (error != nullptr)
	{
		str = String::Format(strDateInfo + "Exception types:{0}\r\nException message:{1}\r\nException information:{2}\r\n",
			error->GetType()->Name, error->Message, error->StackTrace);
	}
	else
	{
		str = String::Format("Error application threads:{0}", e);
	}
	writeLog(str);

	MessageBox::Show("A fatal error, please stop the current operation and promptly contact the author! ", "System Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

void CurrentDomain_UnhandledException(Object^ sender, UnhandledExceptionEventArgs ^e)
{
	String^str;
	Exception^ error = (Exception^)e->ExceptionObject;
	String ^strDateInfo = "An unhandled exception in the application:" + DateTime::Now.ToString() + "\r\n";
	if (error != nullptr)
	{
		str = String::Format(strDateInfo + "Application UnhandledException:{0};\n\rStack information:{1}", error->Message, error->StackTrace);
	}
	else
	{
		str = String::Format("Application UnhandledError:{0}", e);
	}
	writeLog(str);
	MessageBox::Show("A fatal error, please stop the current operation and promptly contact the author! ", "System Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
