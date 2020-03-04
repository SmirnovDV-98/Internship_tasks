#include "task3_Source.cpp";

int main()
{
	String str =  String ("afysgaf");
	String str2 = str;
	const String& str_ref = str;
	String str3 = String(str_ref);
	
	return 0;
}
