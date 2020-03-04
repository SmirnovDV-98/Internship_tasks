#include <cstring>;
#include <cstddef>;
#include <iostream>;


class String
{
	char* m_pszStr;
public:


	String(const char* pcszStr) : m_pszStr((char*) std::calloc(1 + std::strlen(pcszStr), sizeof(char)))
	{
		std::strcpy(m_pszStr, pcszStr);
	}
	operator const char* () const
	{
		return m_pszStr;
	}

	String( const String &s)
	{
		size_t size = sizeof(m_pszStr);
		if (size != sizeof(s.m_pszStr))
		{
			size = sizeof(s.m_pszStr);
			delete[] m_pszStr;
			m_pszStr = new char[size + 1];
		}
		strcpy(m_pszStr, s.m_pszStr);
	}


	String operator = (const String& s)
{
	size_t length= sizeof (s);
    if (this != &s)
    {
		m_pszStr = new char[length];
        memcpy(m_pszStr, s.m_pszStr, length);
    }
    return *this;
}
};