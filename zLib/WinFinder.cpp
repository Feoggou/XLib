
#include "XWin.h"
#include "WinFinder.h"

Zen::Results Zen::WinFind::Find()
{
    WIN32_FIND_DATAW findData;
    BOOL more = true;
    std::wstring fileName;

    HANDLE hFind = FindFirstFileW(L"*", &findData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        more = false;
        DWORD lastError = GetLastError();
        if (lastError != ERROR_FILE_NOT_FOUND)
            throw std::exception("TODO");
    }

    while (more)
    {
        if (wcscmp(findData.cFileName, L".") != 0 && wcscmp(findData.cFileName, L"..") != 0)
            fileName = findData.cFileName;

        more = FindNextFileW(hFind, &findData);
    }

    //TODO: Retrieving multiple items. Also, ERROR_NO_MORE_FILES
    FindClose(hFind);

    if (fileName.empty())
        return Results{};

    ResultItem item = { fileName };
    return Results{ item };
}
