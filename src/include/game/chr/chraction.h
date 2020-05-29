#ifndef _IN_GAME_CHR_CHRACTION_H
#define _IN_GAME_CHR_CHRACTION_H
#include <ultra64.h>
#include "types.h"

f32 func0f02dff0(u32 arg0);
u32 func0f02e064(struct chrdata *chr);
bool func0f02e124(struct prop *prop);
f32 func0f02e15c(struct chrdata *chr, f32 arg1, f32 arg2);
s32 func0f02e1cc(struct chrdata *chr, s32 arg1);
u32 func0f02e260(void);
u32 func0f02e2d0(void);
f32 chrGetDistanceToEntity(struct chrdata *chr, u32 entitytype, s32 entityid);
void func0f02e3dc(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4);
u32 func0f02e4f8(void);
u32 func0f02e550(void);
u32 func0f02e684(void);
void func0f02e6dc(struct chrdata *chr, f32 arg1);
void chrStand(struct chrdata *chr);
u32 func0f02ec94(struct chrdata *chr);
void func0f02ed88(struct chrdata *chr);
void func0f02ef40(struct chrdata *chr);
void func0f02f070(struct chrdata *chr);
void chrDoSurprisedThing(struct chrdata *chr);
void chrDoSurprisedOneHand(struct chrdata *chr);
void chrSurrenderStartAnim(struct chrdata *chr);
void func0f02f8a4(struct chrdata *chr);
void func0f02fc2c(struct chrdata *chr);
void func0f02fe18(struct chrdata *chr);
void chrAttackStand(struct chrdata *chr, s32 entitytype, s32 entityid);
void chrAttackLie(struct chrdata *chr, s32 entitytype, s32 entityid);
void chrAttackKneel(struct chrdata *chr, s32 entitytype, s32 entityid);
u32 func0f030584(void);
void chrAttackWalk(struct chrdata *chr, u32 speed);
u32 func0f030a40(void);
void chrAttackRoll(struct chrdata *chr, bool direction);
void func0f030ff8(struct chrdata *chr, u32 anim_id, f32 fstartframe, f32 fendframe, u8 flags, u32 transition, f32 result);
void func0f031254(struct chrdata *chr);
void func0f031384(struct chrdata *chr, u32 *arg1, bool arg2, s32 *firing, u32 entitytype, u32 entityid, u32 arg6);
void chrAttackAmount(struct chrdata *chr, u32 arg1, u32 arg2, u32 arg3);
u32 func0f0319a8(void);
u32 func0f032ac4(void);
void func0f032fe4(struct chrdata *chr, struct coord *pos, f32 arg2, f32 arg3, u32 *arg4, u32 arg5);
void func0f03323c(struct chrdata *chr, struct coord *pos, f32 arg2);
u32 func0f033654(void);
u32 func0f0336a8(void);
u32 func0f033728(void);
u32 func0f0338e0(void);
void chrSetShield(struct chrdata *chr, f32 shield);
u32 func0f034080(void);
void func0f034124(struct chrdata *chr, f32 arg1, struct coord *coord, u8 *arg3, u32 arg4);
u32 func0f03417c(void);
void func0f0341dc(struct chrdata *chr, f32 arg1, struct coord *coord, u8 *arg3, struct prop *prop, u32 arg5, struct prop *prop2, s32 arg7, s32 arg8, s32 arg9, u32 arg10);
void func0f034330(struct chrdata *chr, f32 arg1, struct coord *vector, u8 *arg3, struct prop *prop, s32 arg5);
u32 func0f034410(void);
u32 func0f034480(void);
void func0f034524(struct chrdata *chr, f32 arg1, struct coord *vector, u8 *arg3, struct prop *prop, u32 arg5, u32 arg6, struct prop *prop2, u32 arg8, u32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13);
u32 func0f03645c(void);
u32 func0f03654c(void);
bool propHasClearLineToPos(struct prop *prop, struct coord *dstpos, struct coord *vector);
bool func0f036918(struct prop *prop, struct coord *coord, f32 arg2);
bool func0f036974(struct prop *prop, struct coord *coord);
void chrGetSideVectorToTarget(struct chrdata *chr, bool side, struct coord *vector);
u32 chrCanRollInDirection(struct chrdata *chr, bool side, f32 distance);
void chrGetSideVector(struct chrdata *chr, bool side, struct coord *vector);
bool chrCanJumpInDirection(struct chrdata *chr, bool side, f32 distance);
u32 func0f036c08(struct chrdata *chr, s32 *arg1, s32 *arg2);
void func0f036ee4(struct chrdata *chr, s8 *maxwaypoints, s32 *arg2, struct coord *prevpos);
void func0f036fc0(struct chrdata *chr, s32 *arg1, s32 *arg2, s32 arg3);
u32 func0f0370a8(void);
u32 func0f037124(void);
u32 func0f037224(void);
void func0f0372e8(struct chrdata *chr);
u32 func0f03733c(void);
u32 func0f0373dc(void);
u32 func0f0374a0(void);
s32 func0f0374e4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u32 func0f037580(void);
u32 func0f0375b0(void);
u32 func0f0375e8(void);
void func0f0379b0(struct chrdata *chr, struct coord *pos);
void func0f037b70(struct chrdata *chr);
u32 chrGoToPos(struct chrdata *chr, struct coord *pos, s16 *room, u32 speed);
u32 func0f038868(void);
void func0f038b9c(struct chrdata *chr, struct path *path);
bool chrCanSeeEntity(struct chrdata *chr, struct coord *pos, s16 *rooms, bool arg3, u32 entitytype, u32 entityid);
bool chrCanSeeAttackTarget(struct chrdata *chr, struct coord *pos, s16 *rooms, bool arg3);
bool chrCanSeeChr(struct chrdata *chr, struct chrdata *target, s16 *room);
bool chrCanViewPos(struct chrdata *viewerchr, struct coord *pos, s16 *rooms);
bool func0f039474(struct chrdata *chr, struct coord *pos, s16 *room);
bool func0f039558(struct chrdata *chr, struct prop *prop);
bool chrIsStopped(struct chrdata *chr);
u32 chrCheckTargetInSight(struct chrdata *chr);
bool chrIsReadyForOrders(struct chrdata *chr);
u32 chrTrySidestep(struct chrdata *chr);
u32 chrTryJumpOut(struct chrdata *chr);
bool chrTryRunSideways(struct chrdata *chr);
u32 chrTryAttackWalk(struct chrdata *chr);
bool chrTryAttackRun(struct chrdata *chr);
u32 chrTryAttackRoll(struct chrdata *chr);
u32 chrTryAttackAmount(struct chrdata *chr, u32 arg1, u32 arg2, u8 arg3, u8 arg4);
bool chrGoToPad(struct chrdata *chr, s32 padnum, u32 speed);
u32 func0f03abd0(void);
u32 func0f03aca0(struct chrdata *chr, u32 arg1, u32 arg2);
u32 chrTryRunFromTarget(struct chrdata *chr);
u32 func0f03b1e0(struct chrdata *chr);
bool chrDropItem(struct chrdata *chr, u32 modelnum, u32 weaponnum);
void func0f03ba44(struct chrdata *chr, u32 arg1, u32 arg2, u32 arg3);
u32 chrTryPunchOrKick(struct chrdata *chr, u32 arg1);
u32 func0f03c044(void);
void chrTickStand(struct chrdata *chr);
void chrTickAnim(struct chrdata *chr);
void chrTickSurrender(struct chrdata *chr);
void chrTickDead(struct chrdata *chr);
void func0f03ce8c(struct chrdata *chr, s32 arg1);
void chrTickDie(struct chrdata *chr);
void chrTickDruggedComingUp(struct chrdata *chr);
void chrTickDruggedDrop(struct chrdata *chr);
void chrTickDruggedKo(struct chrdata *chr);
void chrTickArgh(struct chrdata *chr);
void chrTickPreArgh(struct chrdata *chr);
void chrTickSidestep(struct chrdata *chr);
void chrTickJumpOut(struct chrdata *chr);
void chrTickStartAlarm(struct chrdata *chr);
void chrTickSurprised(struct chrdata *chr);
void func0f03e29c(struct chrdata *chr, s32 arg1, s32 arg2, s32 arg3, struct coord *arg4, struct coord *arg5);
f32 func0f03e45c(struct chrdata *chr);
f32 func0f03e5f0(struct chrdata *chr);
f32 func0f03e754(struct chrdata *chr);
void func0f03e788(struct chrdata *chr, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
u32 func0f03e9f4(void);
u32 func0f03f778(void);
u32 func0f03fa10(void);
u32 func0f03fab0(void);
u32 func0f03fde4(void);
void func0f03ff2c(struct chrdata *chr, struct coord *pos, struct coord *vector, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6);
void func0f04031c(struct coord *coord, f32 arg1, struct coord *coord2, f32 *arg3);
u32 func0f0404d4(void);
u32 func0f041a74(void);
u32 func0f041c44(void);
u32 func0f041d38(void);
u32 func0f041e48(void);
void chrTickAttackAmount(struct chrdata *chr);
void func0f04279c(struct chrdata *chr, bool arg1, bool arg2);
void robotAttack(struct chrdata *chr);
void chrTickRobotAttack(struct chrdata *chr);
void chrTickAttack(struct chrdata *chr);
void chrTickAttackRoll(struct chrdata *chr);
u32 func0f043944(void);
void chrTickThrowGrenade(struct chrdata *chr);
s32 func0f043f2c(struct chrdata *chr, struct coord *runpos, s32 arg2, f32 *arg3);
void chrTickAttackWalk(struct chrdata *chr);
u32 func0f0445c4(void);
bool func0f0446e0(struct coord *prevpos, struct coord *curpos, struct coord *targetpos, f32 arg3);
u32 func0f044808(void);
void chrTickRunPos(struct chrdata *chr);
u32 func0f044b68(void);
u32 func0f044c38(void);
u32 func0f0451a8(void);
u32 func0f045760(void);
u32 func0f045a70(void);
u32 func0f045b9c(void);
u32 func0f046648(void);
u32 func0f046a60(void);
void chrTickGoPos(struct chrdata *chr);
void chrTickPatrol(struct chrdata *chr);
bool chrStartSkJump(struct chrdata *chr, u8 arg1, u8 arg2, s32 arg3, u8 arg4);
void chrTickSkJump(struct chrdata *chr);
void chrTick(struct chrdata *chr);
void func0f0482cc(u32 ailistid);
u32 func0f048398(void);
f32 chrGetAngleToPos(struct chrdata *chr, struct coord *pos);
u32 func0f048b78(void);
u32 func0f048cc0(void);
f32 func0f048dcc(struct chrdata *chr);
bool func0f048e74(struct chrdata *chr, u32 arg1);
u32 func0f048f20(struct chrdata *chr, u8 b);
u32 func0f048fcc(void);
u32 func0f049068(struct chrdata *chr, u32 arg1, u32 arg2);
bool func0f04911c(struct chrdata *chr, struct coord *pos, u8 arg2);
f32 chrGetSameFloorDistanceToPad(struct chrdata *chr, s32 pad_id);
void func0f049644(u32 playernum);
s32 chrResolveId(struct chrdata *ref, s32 id);
f32 chrGetTimer(struct chrdata *chr);
bool chrCanSeeTargetWithExtraCheck(struct chrdata *chr);
bool chrSawInjury(struct chrdata *chr, u8 arg1);
bool chrSawDeath(struct chrdata *chr, u8 arg1);
u32 func0f04a2d4(void);
u32 func0f04a37c(void);
u32 func0f04a4ec(struct chrdata *chr, s32 arg1);
u32 func0f04a674(struct chrdata *chr, s32 arg1);
bool func0f04a7dc(u8 arg0, struct chrdata *chr, f32 distance, s32 arg3);
bool func0f04a848(u8 chrnum, struct chrdata *chr, f32 distance, struct coord *pos, s16 *room);
u32 chrIsInLoadedRoom(struct chrdata *chr);
u32 func0f04aeb0(void);
u32 func0f04af84(void);
struct prop *chrSpawnAtCoord(s32 body, s32 head, struct coord *pos, s16 *room, f32 arg4, u8 *ailist, u32 flags);
u32 func0f04b658(struct chrdata *chr);
bool chrMoveToPos(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3, u32 allowonscreen);
bool chrCheckCoverOutOfSight(struct chrdata *chr, s32 covernum, bool arg2);
s32 func0f04ba34(struct chrdata *chr, u16 arg1, u32 arg2);
u32 func0f04bffc(struct chrdata *chr, u32 arg1, u32 arg2);
void chrRunFromPos(struct chrdata *chr, u32 speed, f32 distance, struct coord *pos);
u32 func0f04c784(void);
void func0f04c874(struct chrdata *chr, u32 flags, struct coord *pos, s32 arg3, s32 arg4);
u32 rebuildTeams(void);
u32 rebuildSquadrons(void);
u32 func0f04d000(struct chrdata *chr);
void func0f02e9a0(struct chrdata *chr, f32 arg1);
void func0f02ed28(struct chrdata *chr, f32 arg1);
void chrStop(struct chrdata *chr);
void chrKneel(struct chrdata *chr);
void chrStartAlarm(struct chrdata *chr);
void chrThrowGrenade(struct chrdata *chr, s32 arg1, s32 arg2);
void chrDoSurprisedSurrender(struct chrdata *chr);
void chrDoSurprisedLookAround(struct chrdata *chr);
void chrSurrender(struct chrdata *chr);
void chrSidestep(struct chrdata *chr, bool side);
void chrJumpOut(struct chrdata *chr, bool side);
void chrRunToPos(struct chrdata *chr, struct coord *pos);
void func0f03119c(struct chrdata *chr);
f32 chrGetShield(struct chrdata *chr);
void func0f036358(struct chrdata *chr, s32 arg1);
void func0f037088(struct chrdata *chr, s32 *arg1, s32 *arg2);
void chrSetField66To0(struct chrdata *chr);
s32 func0f037560(s32 arg0, s32 arg1, s32 arg2);
struct path *pathFindById(u32 path_id);
void chrRecordLastVisibleTargetTime(struct chrdata *chr);
bool chrCanSeeTarget(struct chrdata *chr);
void chrRecordLastSeeTargetTime(struct chrdata *chr);
void chrRecordLastHearTargetTime(struct chrdata *chr);
bool chrIsDead(struct chrdata *chr);
bool chrTryAttackStand(struct chrdata *chr, s32 entitytype, s32 entityid);
bool chrTryAttackKneel(struct chrdata *chr, s32 entitytype, s32 entityid);
bool chrTryAttackLie(struct chrdata *chr, s32 entitytype, s32 entityid);
bool chrTryModifyAttack(struct chrdata *chr, u32 entitytype, s32 entityid);
bool chrFaceEntity(struct chrdata *chr, u32 entitytype, u32 entityid);
bool chrSetPath(struct chrdata *chr, u32 path_id);
u32 chrStartPath(struct chrdata *chr);
u32 chrTrySurrender(struct chrdata *chr);
bool chrFadeOut(struct chrdata *chr);
bool chrGoToTarget(struct chrdata *chr, u32 speed);
bool chrGoToChr(struct chrdata *chr, u32 dst_chrnum, u32 speed);
bool chrGoToProp(struct chrdata *chr, struct prop *prop, s32 speed);
bool chrTryStop(struct chrdata *chr);
bool chrTrySurprisedOneHand(struct chrdata *chr);
bool chrTrySurprisedSurrender(struct chrdata *chr);
bool chrTrySurprisedLookAround(struct chrdata *chr);
bool chrTryKneel(struct chrdata *chr);
bool func0f03af44(struct chrdata *chr, u32 anim_id, f32 fstartframe, f32 fendframe, u8 flags, u32 transition, f32 result);
bool chrTryStartAlarm(struct chrdata *chr, s32 pad_id);
s32 chrConsiderGrenadeThrow(struct chrdata *chr, u32 entitytype, u32 entityid);
void chrTickKneel(struct chrdata *chr);
void func0f03ccdc(struct chrdata *chr);
void func0f03cd04(struct chrdata *chr);
void chrTickTest(struct chrdata *chr);
void func0f03e538(struct chrdata *chr, f32 arg1);
f32 func0f03e578(struct chrdata *chr);
void func0f03e5b0(struct chrdata *chr, f32 arg1);
void chrResetAimEndProperties(struct chrdata *chr);
void chrSetFiring(struct chrdata *chr, s32 hand, bool firing);
void chrStopFiring(struct chrdata *chr);
void func0f03f988(struct chrdata *chr, s32 hand, s32 arg2);
void func0f0429d8(struct chrdata *chr, f32 arg1, f32 arg2);
void unregisterDangerousProp(struct prop *prop);
void registerDangerousProp(struct prop *prop);
bool chrDetectDangerousObject(struct chrdata *chr, u8 flags);
void chrTickBondDie(struct chrdata *chr);
s32 func0f046a30(struct chrdata *chr);
bool chrTrySkJump(struct chrdata *chr, u8 arg1, u8 arg2, s32 arg3, u8 arg4);
bool chrSawTargetRecently(struct chrdata *chr);
bool chrHeardTargetRecently(struct chrdata *chr);
f32 chrGetAngleToTarget(struct chrdata *chr);
f32 chrGetDistanceToTarget(struct chrdata *chr);
f32 chrGetDistanceToTarget2(struct chrdata *chr);
f32 chrGetDistanceToCurrentPlayer(struct chrdata *chr);
f32 propGetDistanceToProp(struct prop *a, struct prop *b);
f32 propGetLateralDistanceToProp(struct prop *a, struct prop *b);
f32 chrGetDistanceToPad(struct chrdata *chr, s32 pad_id);
f32 chrGetDistanceToCoord(struct chrdata *chr, struct coord *pos);
f32 chrGetLateralDistanceToCoord(struct chrdata *chr, struct coord *pos);
f32 chrGetLateralDistanceToPad(struct chrdata *chr, s32 pad_id);
f32 chrGetSquaredDistanceToCoord(struct chrdata *chr, struct coord *pos);
f32 coordGetSquaredDistanceToCoord(struct coord *a, struct coord *b);
s32 chrGetPadRoom(struct chrdata *chr, s32 pad_id);
s32 chrResolvePadId(struct chrdata *chr, s32 pad_id);
struct chrdata *chrFindById(struct chrdata *data, s32 chrnum);
s32 propGetIndexByChrId(struct chrdata *chr, s32 chrnum);
f32 chrGetDistanceToChr(struct chrdata *chr1, s32 chr2num);
f32 chrGetDistanceFromTargetToPad(struct chrdata *chr, s32 pad_id);
void chrSetFlags(struct chrdata *chr, u32 flags, u8 bank);
void chrUnsetFlags(struct chrdata *chr, u32 flags, u8 bank);
bool chrHasFlag(struct chrdata *chr, u32 flag, u8 bank);
void chrSetFlagsById(struct chrdata *ref, u32 chrnum, u32 flags, u32 bank);
void chrUnsetFlagsById(struct chrdata *ref, u32 chrnum, u32 flags, u32 bank);
bool chrHasFlagById(struct chrdata *ref, u32 chrnum, u32 flag, u32 bank);
void chrSetStageFlag(struct chrdata *chr, u32 flag);
void chrUnsetStageFlag(struct chrdata *chr, u32 flag);
bool chrHasStageFlag(struct chrdata *chr, u32 flag);
bool chrIsHearingTarget(struct chrdata *chr);
void chrRestartTimer(struct chrdata *chr);
u32 chrResetNearMiss(struct chrdata *chr);
s32 chrGetNumArghs(struct chrdata *chr);
s32 chrGetNumCloseArghs(struct chrdata *chr);
void decrementByte(u8 *dst, u8 amount);
void incrementByte(u8 *dst, u8 amount);
bool chrCanHearAlarm(struct chrdata *chr);
bool func0f04a76c(struct chrdata *chr, f32 distance);
bool func0f04a79c(u8 chrnum, struct chrdata *chr, f32 distance);
bool chrCompareTeams(struct chrdata *chr1, struct chrdata *chr2, u8 checktype);
void chrSetChrPreset(struct chrdata *chr, s32 chrpreset);
void chrSetChrPresetByChrnum(struct chrdata *chr, s32 chrnum, s32 chrpreset);
void chrSetPadPreset(struct chrdata *chr, s32 pad_id);
void chrSetPadPresetByChrnum(struct chrdata *chr, s32 chrnum, s32 pad_id);
struct prop *chrSpawnAtPad(struct chrdata *chr, s32 body, s32 head, s32 pad, u8 *ailist, u32 flags);
struct prop *chrSpawnAtChr(struct chrdata *basechr, s32 body, s32 head, u32 chrnum, u8 *ailist, u32 flags);
s16 chrGoToCover(struct chrdata *chr, u8 speed);
void chrAddTargetToBdlist(struct chrdata *chr);
s32 chrGetDistanceLostToTargetInLastSecond(struct chrdata *chr);
bool chrIsTargetNearlyInSight(struct chrdata *chr, u32 distance);
bool chrIsNearlyInTargetsSight(struct chrdata *chr, u32 distance);
s16 *teamGetChrIds(s32 team_id);
s16 *squadronGetChrIds(s32 squadron_id);
void audioMarkAsRecentlyPlayed(s16 audioid);
bool audioWasNotPlayedRecently(s16 audioid);
void func0f04cf90(struct chrdata *chr, s32 arg1);
bool func0f04d44c(struct chrdata *chr);
void chrEmitSparks(struct chrdata *chr);

#endif
