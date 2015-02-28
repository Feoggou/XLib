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
		static void Create(const std::wstring& path);
		static void Remove(const std::wstring& path);
		static bool Exists(const std::wstring& path);
	};
}