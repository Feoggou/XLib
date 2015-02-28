#include "XWin.h"

#include <cassert>

#include "WinDir.h"
#include "FSException.h"

#if !WIN32
#error This file must be included only on Windows!
#endif

using namespace Zen;

bool WinDir::Exists(const std::wstring& path)
{
	DWORD result = GetFileAttributesW(path.data());

	if (result == INVALID_FILE_ATTRIBUTES)
	{
		DWORD error = GetLastError();
		switch (error)
		{
		case ERROR_FILE_NOT_FOUND:
		case ERROR_PATH_NOT_FOUND:
		return false;

		default:
		throw FSException(error);
		}
	}

	return true;
}

bool WinDir::Create(const std::wstring& path)
{
	BOOL ok = CreateDirectoryW(path.data(), NULL);
	if (!ok)
	{
		DWORD error = GetLastError();
		if (error == ERROR_ALREADY_EXISTS)
		{
			return false;
		}
		
		throw FSException(GetLastError());
	}

	return true;
}

bool WinDir::Remove(const std::wstring& path)
{
	BOOL ok = RemoveDirectoryW(path.data());
	if (!ok)
	{
		DWORD error = GetLastError();
		if (error == ERROR_FILE_NOT_FOUND)
		{
			return false;
		}

		throw FSException(GetLastError());
	}

	return true;
}

std::wstring WinDir::GetCurrent()
{
	DWORD nCount = GetCurrentDirectoryW(0, NULL);
	if (!nCount) { throw FSException(GetLastError()); }

	std::wstring dirPath;
	dirPath.resize(nCount);
	wchar_t* data = const_cast<wchar_t*>(dirPath.data());

	DWORD result = GetCurrentDirectoryW(nCount, data);
	if (!result) { throw FSException(GetLastError()); }

	// the return value - result - specifies the number of characters that are written to the buffer,
	// NOT including the terminating null character, unlike nCount.
	assert(result + 1 == nCount);

	return dirPath;
}