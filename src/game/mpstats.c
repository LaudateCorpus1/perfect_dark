#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/inventory/items.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b69d0.h"
#include "game/hudmsg.h"
#include "game/game_127910.h"
#include "game/mplayer/setup.h"
#include "game/game_197600.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "data.h"
#include "types.h"

u32 var80070590 = 0x00000000;

void mpstatsIncrementPlayerShotCount(struct gset *gset, s32 region)
{
	if (!weaponHasFlag(gset->weaponnum, WEAPONFLAG_DONTCOUNTSHOTS)) {
		g_Vars.currentplayerstats->shotcount[region]++;
	}
}

void mpstatsIncrementPlayerShotCount2(struct gset *gset, s32 region)
{
	if (region == 0) {
		if (!weaponHasFlag(gset->weaponnum, WEAPONFLAG_DONTCOUNTSHOTS)) {
			var80070590 = 1;
			g_Vars.currentplayerstats->shotcount[region]++;
		}
	} else {
		if (var80070590) {
			if (!weaponHasFlag(gset->weaponnum, WEAPONFLAG_DONTCOUNTSHOTS)) {
				g_Vars.currentplayerstats->shotcount[region]++;
			}

			var80070590 = 0;
		}
	}
}

void mpstats0f0b0520(void)
{
	var80070590 = 0;
}

s32 mpstatsGetPlayerShotCountByRegion(u32 type)
{
	return g_Vars.currentplayerstats->shotcount[type];
}

void mpstatsIncrementTotalKillCount(void)
{
	g_Vars.killcount++;
}

void mpstatsIncrementTotalKnockoutCount(void)
{
	g_Vars.knockoutcount++;
}

void mpstatsDecrementTotalKnockoutCount(void)
{
	g_Vars.knockoutcount--;
}

u8 mpstatsGetTotalKnockoutCount(void)
{
	return g_Vars.knockoutcount;
}

u32 mpstatsGetTotalKillCount(void)
{
	return g_Vars.killcount;
}

void mpstatsRecordPlayerKill(void)
{
	char text[256];
	s32 simulkills;
	s32 duration;
	s32 time;

	g_Vars.currentplayerstats->killcount++;
	g_Vars.currentplayer->killsthislife++;

	if (g_Vars.normmplayerisrunning) {
		time = getMissionTime();

		// Show HUD message
		// "Kill count: %d"
		sprintf(text, "%s: %d\n", langGet(L_GUN_001), g_Vars.currentplayerstats->killcount);
		hudmsgCreate(text, HUDMSGTYPE_DEFAULT);

		// Update slowest/fastest two kills
		if (g_Vars.currentplayerstats->killcount > 1) {
			duration = time - g_Vars.currentplayer->lastkilltime60;

			if (duration > g_Vars.currentplayerstats->slowest2kills) {
				g_Vars.currentplayerstats->slowest2kills = duration;
			}

			if (duration < g_Vars.currentplayerstats->fastest2kills) {
				g_Vars.currentplayerstats->fastest2kills = duration;
			}
		}

		// Update max simultaneous kills
		simulkills = 1;

		g_Vars.currentplayer->lastkilltime60_4 = g_Vars.currentplayer->lastkilltime60_3;
		g_Vars.currentplayer->lastkilltime60_3 = g_Vars.currentplayer->lastkilltime60_2;
		g_Vars.currentplayer->lastkilltime60_2 = g_Vars.currentplayer->lastkilltime60;
		g_Vars.currentplayer->lastkilltime60 = time;

		if (g_Vars.currentplayer->lastkilltime60_2 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_2 < 120) {
			simulkills++;

			if (g_Vars.currentplayer->lastkilltime60_3 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_3 < 120) {
				simulkills++;

				if (g_Vars.currentplayer->lastkilltime60_4 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_4 < 120) {
					simulkills++;
				}
			}
		}

		if (simulkills > g_Vars.currentplayerstats->maxsimulkills) {
			g_Vars.currentplayerstats->maxsimulkills = simulkills;
		}
	}
}

s32 mpstatsGetPlayerKillCount(void)
{
	return g_Vars.currentplayerstats->killcount;
}

void mpstatsIncrementPlayerGgKillCount(void)
{
	g_Vars.currentplayerstats->ggkillcount++;
}

void mpstatsRecordPlayerDeath(void)
{
	char buffer[256];

	g_Vars.currentplayer->deathcount++;

	if (g_Vars.normmplayerisrunning) {
		if (g_Vars.currentplayer->deathcount == 1) {
			sprintf(buffer, langGet(L_GUN_002)); // "Died once"
		} else {
			sprintf(buffer, "%s %d %s\n",
					langGet(L_GUN_003), // "Died"
					g_Vars.currentplayer->deathcount,
					langGet(L_GUN_004)); // "times"
		}

		hudmsgCreate(buffer, HUDMSGTYPE_DEFAULT);
	}
}

void mpstatsRecordPlayerSuicide(void)
{
	char text[256];
	s32 simulkills;
	s32 duration;
	s32 time;
	s32 mpindex;
	struct mpchr *mpchr;

	if (g_Vars.normmplayerisrunning) {
		time = getMissionTime();
		mpindex = g_Vars.currentplayerstats->mpindex;

		if (mpindex < 4) {
			mpchr = &g_MpPlayers[mpindex].base;
		} else {
			mpchr = &g_MpSimulants[mpindex - 4].base;
		}

		// Show HUD message
		// "Suicide count: %d"
		sprintf(text, "%s: %d\n", langGet(L_GUN_005), mpchr->killcounts[mpindex]);
		hudmsgCreate(text, HUDMSGTYPE_DEFAULT);

		// Update slowest/fastest two kills
		if (g_Vars.currentplayerstats->killcount > 1) {
			duration = time - g_Vars.currentplayer->lastkilltime60;

			if (duration > g_Vars.currentplayerstats->slowest2kills) {
				g_Vars.currentplayerstats->slowest2kills = duration;
			}

			if (duration < g_Vars.currentplayerstats->fastest2kills) {
				g_Vars.currentplayerstats->fastest2kills = duration;
			}
		}

		// Update max simultaneous kills
		simulkills = 1;

		g_Vars.currentplayer->lastkilltime60_4 = g_Vars.currentplayer->lastkilltime60_3;
		g_Vars.currentplayer->lastkilltime60_3 = g_Vars.currentplayer->lastkilltime60_2;
		g_Vars.currentplayer->lastkilltime60_2 = g_Vars.currentplayer->lastkilltime60;
		g_Vars.currentplayer->lastkilltime60 = time;

		if (g_Vars.currentplayer->lastkilltime60_2 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_2 < 120) {
			simulkills++;

			if (g_Vars.currentplayer->lastkilltime60_3 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_3 < 120) {
				simulkills++;

				if (g_Vars.currentplayer->lastkilltime60_4 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_4 < 120) {
					simulkills++;
				}
			}
		}

		if (simulkills > g_Vars.currentplayerstats->maxsimulkills) {
			g_Vars.currentplayerstats->maxsimulkills = simulkills;
		}
	}
}

void mpstatsRecordDeath(s32 aplayernum, s32 vplayernum)
{
	s32 vmpindex = -1;
	struct mpchr *vmpchr = NULL;
	s32 ampindex;
	struct mpchr *ampchr = NULL;
	s32 prevplayernum;
	char text[256];

	if (g_Vars.normmplayerisrunning && g_MpSetup.scenario == MPSCENARIO_POPACAP) {
		func0f1847b8();
	}

	// Find attacker and victim mpchrs
	if (aplayernum >= 0) {
		ampindex = func0f18d074(aplayernum);

		if (ampindex >= 0) {
			if (ampindex < 4) {
				ampchr = &g_MpPlayers[ampindex].base;
			} else {
				ampchr = &g_MpSimulants[ampindex - 4].base;
			}
		}
	}

	if (vplayernum >= 0) {
		vmpindex = func0f18d074(vplayernum);

		if (vmpindex >= 0) {
			if (vmpindex < 4) {
				vmpchr = &g_MpPlayers[vmpindex].base;
			} else {
				vmpchr = &g_MpSimulants[vmpindex - 4].base;
			}
		}
	}

	if (vplayernum >= 0 && aplayernum == vplayernum) {
		// Player suicide
		if (vmpchr && vmpindex >= 0) {
			vmpchr->numdeaths++;
			vmpchr->killcounts[vmpindex]++;
		}

		if (vplayernum < PLAYERCOUNT()) {
			prevplayernum = g_Vars.currentplayernum;
			setCurrentPlayerNum(vplayernum);
			mpstatsRecordPlayerSuicide();
			setCurrentPlayerNum(prevplayernum);
		}
	} else {
		// Normal kill
		if (vplayernum >= 0) {
			if (vmpchr) {
				vmpchr->numdeaths++;
			}

			if (vplayernum < PLAYERCOUNT()) {
				// Victim was a player
				prevplayernum = g_Vars.currentplayernum;
				setCurrentPlayerNum(vplayernum);

				if (g_Vars.normmplayerisrunning && aplayernum >= 0) {
					// "Killed by %s"
					sprintf(text, "%s %s", langGet(L_MISC_183), var800ac500[aplayernum]->name);
					hudmsgCreate(text, HUDMSGTYPE_DEFAULT);
				}

				mpstatsRecordPlayerDeath();
				setCurrentPlayerNum(prevplayernum);
			}
		}

		if (ampchr && vmpindex >= 0) {
			ampchr->killcounts[vmpindex]++;
		}

		if (aplayernum >= 0 && aplayernum < PLAYERCOUNT()) {
			// Attacker was a player
			prevplayernum = g_Vars.currentplayernum;
			setCurrentPlayerNum(aplayernum);

			if (g_Vars.normmplayerisrunning && vplayernum >= 0) {
				// "Killed %s"
				sprintf(text, "%s %s", langGet(L_MISC_184), var800ac500[vplayernum]->name);
				hudmsgCreate(text, HUDMSGTYPE_DEFAULT);
			}

			mpstatsRecordPlayerKill();
			setCurrentPlayerNum(prevplayernum);
		}

		// If someone killed an aibot
		if (g_Vars.normmplayerisrunning
				&& aplayernum >= 0
				&& vplayernum >= PLAYERCOUNT()
				&& aplayernum != vplayernum) {
			g_MpPlayerChrs[vplayernum]->aibot->lastkilledbyplayernum = aplayernum;
		}
	}

	if (g_Vars.normmplayerisrunning && aplayernum >= 0 && g_MpPlayerChrs[aplayernum]->aibot) {
		s32 index = mpGetWeaponIndexByWeaponNum(g_MpPlayerChrs[aplayernum]->aibot->weaponnum);

		if (index >= 0) {
			if (aplayernum == vplayernum) {
				g_MpPlayerChrs[aplayernum]->aibot->suicidesbygunfunc[index][g_MpPlayerChrs[aplayernum]->aibot->gunfunc]++;
			} else {
				g_MpPlayerChrs[aplayernum]->aibot->killsbygunfunc[index][g_MpPlayerChrs[aplayernum]->aibot->gunfunc]++;
			}
		}
	}

	g_Vars.totalkills++;
}
