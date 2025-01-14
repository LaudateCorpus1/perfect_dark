#ifndef IN_GAME_GAME_1668E0_H
#define IN_GAME_GAME_1668E0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void currentPlayerSetLastRoomForOffset(s32 room);
void func0f1668f0(s32 index, s32 roomnum);
void func0f16692c(s32 index, s32 roomnum);
void func0f16696c(s32 index);
s32 func0f1669fc(void);
void func0f166a6c(Mtxf *matrix, s32 roomnum);
s32 func0f166c20(s32 roomnum);
Gfx *func0f166d7c(Gfx *gdl, s32 roomnum);
struct coord *func0f166dd0(s32 room);
void func0f166df0(s32 room, struct coord *globaldrawworldoffset);

#endif
