//
//  vector2.c
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "vector2.h"

vector2_t vector2_add(vector2_t a, vector2_t b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

vector2_t vector2_scale(vector2_t vec, float scale) {
    vec.x *= scale;
    vec.y *= scale;
    return vec;
}
