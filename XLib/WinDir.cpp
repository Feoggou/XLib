#include "XWin.h"

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

void WinDir::Create(const std::wstring& path)
{
	BOOL ok = CreateDirectoryW(path.data(), NULL);
	if (!ok)
	{
		throw FSException(GetLastError());
	}
}

void WinDir::Remove(const std::wstring& path)
{
	BOOL ok = RemoveDirectoryW(path.data());
	if (!ok)
	{
		throw FSException(GetLastError());
	}
}