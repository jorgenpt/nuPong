//
//  Strings.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 11/16/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Strings.h"

bool Strings::endsWith (std::string const &str, std::string const &ending)
{
    if (ending.length() > str.length()) {
        return false;
    }

    size_t index = str.length() - ending.length();
    return (str.compare(index, ending.length(), ending) == 0);
}
