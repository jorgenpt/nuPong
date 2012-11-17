//
//  Filesystem.h
//  nuPong
//
//  Created by Jørgen Tjernø on 11/16/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Filesystem__
#define __nuPong__Filesystem__

#include <vector>
#include <string>

namespace Filesystem {
    /** Read the entries in the given path.
     *
     * Returns false if it fails, otherwise fills 'dirEntries' with the contents of the directory.
     */
    bool entries(const std::string& path, std::vector<std::string>* dirEntries);

    /** Read the contents of a file.
     *
     * Returns false if it fails, otherwise fills 'contents' with the contents of the file.
     */
    bool readFile(const std::string& path, std::string* contents);
};

#endif /* defined(__nuPong__Filesystem__) */
