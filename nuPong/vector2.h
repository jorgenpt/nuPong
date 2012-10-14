//
//  vector2.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef nuPong_vector2_h
#define nuPong_vector2_h


typedef struct {
    float x, y;
} vector2_t;

vector2_t vector2_add(vector2_t a, vector2_t b);
vector2_t vector2_scale(vector2_t vec, float scale);

#endif
