#ifndef _IN_GAME_GAME_097BA0_H
#define _IN_GAME_GAME_097BA0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f097ba0(s32 handnum, s32 weaponnum);
s32 func0f097d0c(s32 weaponnum);
u32 func0f097d64(void);
u32 func0f097df0(void);
u32 func0f097e74(void);
u32 func0f097f28(void);
u32 func0f098030(void);
f32 func0f09815c(struct hand *hand);
u32 func0f0981e8(void);
bool func0f098884(struct guncmd *cmd, struct shorthand *hand);
void func0f0988e0(struct guncmd *cmd, s32 handnum, struct hand *hand);
bool func0f098a44(struct hand *hand, s32 time);
bool handIsAnimBusy(struct hand *hand);
void handResetAnim(struct hand *hand);
void handGetWeaponInfo(struct handweaponinfo *info, s32 handnum);
s32 func0f098ca0(s32 arg0, struct handweaponinfo *info, struct hand *hand);
u32 func0f098df8(void);
u32 func0f098f8c(void);
bool func0f099008(s32 handnum);
bool func0f0990b0(struct weaponfunc *basefunc, struct weapon *weapon);
bool func0f099188(struct hand *hand, s32 gunfunc);
s32 handTickIncIdle(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate);
void func0f099780(struct hand *hand, f32 angle);
s32 handTickIncAutoSwitch(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate);
u32 func0f099c24(void);
s32 handTickIncReload(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate);
s32 handTickIncChangeFunc(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate);
s32 func0f09a3f8(struct hand *hand, struct weaponfunc *func);
void func0f09a6f8(struct handweaponinfo *info, s32 handnum, struct hand *hand, struct weaponfunc *func);
bool func0f09aba4(struct hand *hand, struct handweaponinfo *info, s32 handnum, struct weaponfunc_shoot *func);
bool handTickIncAttackingShoot(struct handweaponinfo *info, s32 handnum, struct hand *hand);
bool handTickIncAttackingThrow(s32 handnum, struct hand *hand);
s32 weaponGetMinClipQty(s32 weaponnum, s32 funcnum);
bool handTickIncAttackingClose(s32 handnum, struct hand *hand);
bool handTickIncAttackingSpecial(struct hand *hand);
s32 handTickIncAttackEmpty(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate);
s32 handTickIncAttack(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate);
bool handIsReadyToSwitch(s32 handnum);
bool func0f09bec8(s32 handnum);
u32 func0f09bf44(void);
s32 handTickIncChangeGun(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate);
s32 handTickIncState2(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate);
s32 handTickInc(struct handweaponinfo *info, s32 handnum, s32 lvupdate);
bool handSetState(s32 handnum, s32 state);
void handTick(s32 handnum);
void func0f09ce8c(void);
void func0f09ceac(void);
f32 handGetNoiseRadius(s32 handnum);
void currentPlayerDecreaseNoiseRadius(void);
void func0f09d140(s32 hand);
u32 func0f09d550(void);
void func0f09d8dc(f32 breathing, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
bool func0f09dd7c(void);
u32 func0f09ddcc(void);
u8 *func0f09ddec(void);
u32 func0f09ddfc(void);
void func0f09df50(void);
void func0f09df64(s32 weaponnum);
void func0f09df9c(void);
bool func0f09e004(s32 newowner);
u32 func0f09e144(void);
void func0f09e4e0(void);
u32 func0f09ea90(void);
bool func0f09eae4(void);
s32 func0f09ebbc(void);
void func0f09ebcc(struct defaultobj *obj, struct coord *coord, s16 *rooms, Mtxf *matrix1, f32 *arg4, Mtxf *matrix2, struct prop *prop, struct coord *pos);
u32 func0f09ed2c(void);
struct var8009ce58 *func0f09ee18(struct chrdata *chr, struct shorthand *hand, struct coord *pos, s16 *rooms, Mtxf *arg4, struct coord *arg5);
void handCreateThrownProjectile(s32 handnum, struct shorthand *hand);
u32 func0f09f848(void);
u32 func0f09f974(void);
void func0f09fa20(s32 handnum);
void handCreateFiredProjectile(s32 handnum);
void func0f0a0394(f32 autoaimx, f32 autoaimy, f32 damp, f32 arg3);
void currentPlayerSwivelGunTowards(f32 screenx, f32 screeny, f32 damp);
void func0f0a0b98(f32 arg0, f32 arg1);
void currentPlayerGetCrossPos(f32 *x, f32 *y);
void func0f0a0c08(struct coord *arg0, struct coord *arg1);
void func0f0a0c44(s32 handnum, struct coord *param_2, struct coord *arg2);
void handCalculateShotSpread(struct coord *arg0, struct coord *arg1, s32 handnum, bool dorandom);
u32 func0f0a0fac(void);
void handSetLastShootInfo(struct coord *pos, struct coord *dir, s32 handnum);
u32 handGetUnk0c30(s32 handnum);
void func0f0a134c(s32 handnum);
void func0f0a1528(void);
void currentPlayerEquipWeapon(s32 weaponnum);
s32 handGetWeaponNum(s32 handnum);
bool func0f0a1a10(s32 weaponnum);
s32 func0f0a1a68(s32 arg0);
void func0f0a1ab0(void);
void func0f0a1b50(void);
void func0f0a1c2c(void);
bool currentPlayerHasAmmoForWeapon(s32 weaponnum);
void currentPlayerAutoSwitchWeapon(void);
void currentPlayerEquipWeaponWrapper(bool arg0, s32 weaponnum);
s32 handIsFiring(s32 handnum);
s32 handGetAttackType(s32 handnum);
char *weaponGetName(s32 weaponnum);
u16 weaponGetNameId(s32 weaponnum);
char *weaponGetShortName(s32 arg0);
void currentPlayerReloadHandIfPossible(s32 handnum);
void handSetAdjustPos(f32 angle);
void func0f0a2308(s32 handnum);
u32 func0f0a233c(void);
u32 func0f0a2498(void);
u32 func0f0a24f0(void);
u32 func0f0a27c8(void);
void func0f0a29c8(void);
bool weaponIsMissionCritical(s32 weaponnum);
void currentPlayerLoseGunInNbombStorm(struct prop *prop);
u32 func0f0a2da8(void);
u32 func0f0a2e94(void);
void playerDetonateRemoteMines(s32 playernum);
u32 func0f0a3160(void);
u32 func0f0a3490(void);
u32 func0f0a37b4(void);
u32 func0f0a3aa4(void);
u32 func0f0a3eac(void);
u32 func0f0a4094(void);
u32 func0f0a419c(void);
u32 func0f0a4334(void);
u32 func0f0a4438(void);
u32 func0f0a4570(void);
u32 func0f0a45d0(void);
u32 func0f0a46a4(void);
u32 func0f0a4e44(void);
u32 func0f0a5300(void);
u32 func0f0a5550(void);
u32 func0f0a695c(void);
u32 func0f0a6c30(void);
u32 func0f0a70f8(void);
void func0f0a7138(Gfx **gdl);
struct audiohandle **func0f0a7d5c(void);
void func0f0a7d98(struct shorthand *hand, struct prop *prop, s32 arg2);
void func0f0a8404(struct coord *pos, s16 *rooms, s32 arg2);
u32 func0f0a84c8(void);
void handSetTriggerOn(s32 handnum, bool on);
s32 currentPlayerConsiderToggleGunFunction(s32 usedowntime, bool firing, s32 arg2);
void func0f0a8c50(void);
bool currentPlayerIsUsingSecondaryFunction(void);
void handsTick(bool triggeron);
void playersSetPassiveMode(bool enable);
void currentPlayerSetAimType(u32 aimtype);
void handSetAimPos(struct coord *coord);
void handSetHitPos(struct coord *coord);
void func0f0a9494(u32 operation);
void func0f0a94d0(u32 operation, struct coord *pos, struct coord *rot);
void func0f0a95ec(u32 arg0, bool enable);
void currentPlayerSetAmmoQuantity(s32 ammotype, s32 quantity);
s32 currentPlayerGetAmmoCountWithCheck(s32 type);
s32 currentPlayerGetAmmoCount(s32 ammotype);
s32 ammotypeGetMaxCapacity(u32 ammotype);
bool ammotypeAllowsUnlimitedAmmo(u32 ammotype);
void currentPlayerGiveUnlimitedAmmo(bool force);
u32 weaponGetAmmoType(u32 weaponnum, u32 func);
s32 currentPlayerGetAmmoQuantityForWeapon(u32 weaponnum, u32 func);
void currentPlayerGiveAmmoForWeapon(u32 weaponnum, u32 func, u32 quantity);
u32 func0f0a9b10(void);
u32 func0f0a9b68(void);
u32 func0f0a9d2c(void);
void abmagReset(struct abmag *abmag);
u32 func0f0a9da8(void);
u32 func0f0a9fc0(void);
Gfx *hudRenderAmmo(Gfx *gdl);
void cboostAdd(s32 arg0);
void cboostSubtract(s32 arg0);
void cboostBoost(void);
void cboostRevert(void);
void speedpillTick(void);
void currentPlayerSetGunSightVisible(u32 bits, bool visible);
Gfx *func0f0abcb0(Gfx *gdl);
void func0f0abd30(s32 handnum);
s32 getCurrentPlayerWeaponIdWrapper(s32 handnum);
s8 freeFireslotWrapper(s32 fireslot);
s8 freeFireslot(s32 fireslot);

#endif
