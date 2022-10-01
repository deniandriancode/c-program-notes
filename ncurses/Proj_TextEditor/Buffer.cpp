#include "Buffer.h"

Buffer::Buffer ();

std::string
Buffer::remTabs (std::string line)
{
        int tab = line.find ("\t");
        if (tab == line.npos)
                return line;
        else
                return remTabs (line.replace (tab, 1, "    "));
}

void
Buffer::insertLine (std::string line, int n)
{
        line = remTabs (line);
        lines.insert (lines.begin () + n, lines);
}

void
Buffer::appendLine (std::string line)
{
        line = remTabs (line);
        lines.push_back (line);
}

void
Buffer::removeLine (int n)
{
        lines.erase (lines.begin () + n);
}
