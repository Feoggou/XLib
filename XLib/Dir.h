#pragma once

#include <string>

namespace Zen
{
	class Dir
	{
	public:
		Dir() = default;
		Dir(Dir&& other);
		explicit Dir(const std::wstring& path) : m_path(path) {}

		Dir& operator=(Dir&& other);

		bool Exists() const;
		bool Create();
		bool Remove();
		std::wstring FullPath() const;

	public:
		static Dir Create(const std::wstring& path);
		static bool Remove(const std::wstring& path);
		static bool Exists(const std::wstring& path);
		static Dir GetCurrent();

	private:
		std::wstring m_path;
	};
}