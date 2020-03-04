#include <cstring>;

void  strreplace(char* pszResult,const  char* pcszSubstr, const char* pcszStr2)
{
	if (pszResult == NULL || pcszSubstr == NULL || pcszStr2 == NULL)
		return;

	size_t lenghtSrc = strlen(pszResult);
	size_t lenghtSub = strlen(pcszSubstr);
	size_t lenghtSub2 = strlen(pcszStr2);
	ptrdiff_t i = lenghtSub2 - lenghtSub;

	char* pTmp = pszResult;
	for (; pTmp = strstr(pTmp, pcszSubstr); pTmp += lenghtSub2)
	{
		if (lenghtSub < lenghtSub2)
		{
			memmove(pTmp + i, pTmp, lenghtSrc - (size_t)(pTmp - pszResult));
			lenghtSrc += i;
		}
		else if (lenghtSub > lenghtSub2)
		{
			memcpy(pTmp, pTmp - i, lenghtSrc - (size_t)(pTmp - pszResult) + i);
			lenghtSrc -= i;
		}
		strncpy(pTmp, pcszStr2, lenghtSub2);
	}
}
int main()
{
	char first_string[] = "ausfgjagsbtrouisahfkaghrtohdfgdfhjgdffgfag"; 
	char searched_string[] = "ag";
	char substituted_string[] = "Reference";

	strreplace(&first_string[0],&searched_string[0], &substituted_string[0]);
}