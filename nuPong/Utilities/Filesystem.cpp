//
//  Filesystem.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 11/16/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Filesystem.h"

#include <fstream>
#include <sstream>

#include <dirent.h>

bool Filesystem::entries(const std::string& path, std::vector<std::string>* dirEntries)
{
    DIR* dir = opendir(path.c_str());
    if (!dir) {
        return false;
    }

    dirent entry;
    dirent* currentEntry;
    int status = 0;
    while ((status = readdir_r(dir, &entry, &currentEntry)) == 0) {
        // Check if we're at the end of the directroy stream.
        if (currentEntry == NULL) {
            break;
        }

        dirEntries->push_back(entry.d_name);
    }

    int closeStatus = closedir(dir);
    return (closeStatus == 0 && status == 0);
}

bool Filesystem::readFile(const std::string& path, std::string* contents)
{
    //First, let us load the vertex shader.
    std::fstream file(path, std::ios::in);
    if (!file.is_open()) {
        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    contents->assign(buffer.str());
    return true;
}
