#pragma once

#include <string>

#if !WIN32
#error This file must be included only on Windows!
#endif

namespace Zen
{
	class WinDir
	{
	public:
		// Creates a Directory of the given path. If a directory with the same name already exists, the function returns false.
		// If there is an error, an exception is thrown. If the directory is created, it returns true.
		static bool Create(const std::wstring& path);
		// Removes a Directory of the given path. If no directory with the name, the function returns false.
		// If there is an error, an exception is thrown. If the directory is removed, it returns true.
		static bool Remove(const std::wstring& path);
		static bool Exists(const std::wstring& path);

		static std::wstring GetCurrent();
	};
}