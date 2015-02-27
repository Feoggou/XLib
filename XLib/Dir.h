#pragma once

#include <string>

namespace Zen
{
	class Dir
	{
	public:
		Dir() {}
		Dir(const std::wstring& path) : m_path(path) {}

		bool Exists() const;
		std::wstring Name() const;

	public:
		static Dir Create(const std::wstring& path);
		static void Remove(const std::wstring& path);
		static bool Exists(const std::wstring& path);

	private:
		std::wstring m_path;
	};
}