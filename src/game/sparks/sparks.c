#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/chr/chr.h"
#include "game/game_0b3350.h"
#include "game/sparks/sparks.h"
#include "game/file.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "data.h"
#include "types.h"

const u32 var7f1b5600[] = {0xb8d1b717};

#if VERSION >= VERSION_PAL_FINAL
const u32 var7f1b6914pf[] = {0x3f99999a};
#endif

const u32 var7f1b5604[] = {0xb8d1b717};
const u32 var7f1b5608[] = {0x3d4ccccd};
const u32 var7f1b560c[] = {0x469c4000};
const u32 var7f1b5610[] = {0x3e4ccccd};

struct spark g_Sparks[100];
u32 g_NextSparkIndex;
u32 var800a3fc4;
struct sparkgroup g_SparkGroups[10];
u32 var800a4130;
u32 var800a4134;
u32 var800a4138;
u32 var800a413c;
u32 var800a4140;
u32 var800a4144;
u32 var800a4148;
u32 var800a414c;

struct sparktype g_SparkTypes[] = {
	//                                     weight
	//                                     |     max age
	//                                     |     |                                        decel
	//                                     |     |                                        |
#if VERSION >= VERSION_PAL_FINAL
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0x80ffffff, 0xffffffff, 0.024 },
	/*0x00*/ { 40,  -1,  30,   30,  0,  0, 2.4,              29,  29,  5,  1, 0x301010ff, 0x401010ff, 0.024 },
	/*0x00*/ { 40,  -1,  300,  200, 0,  0, 0.18,             5,   5,   4,  1, 0xffffff40, 0x560011a0, 0.024 },
	/*0x00*/ { 10,  1,   1200, 400, 0,  0, 0.18,             5,   5,   5,  1, 0xa0a0e000, 0xffffffff, 0.024 },
	/*0x00*/ { 40,  10,  10,   10,  0,  0, 3.6000001430511,  150, 75,  5,  1, 0x00ff6aff, 0xffffffff, 0.024 },
	/*0x00*/ { 15,  10,  20,   20,  0,  0, 0.78000003099442, 150, 75,  5,  1, 0xa0a0e0ff, 0xffffffff, 0.024 },
	/*0x00*/ { 1,   1,   120,  2,   0,  0, 0,                50,  50,  5,  1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 1,   1,   300,  50,  0,  0, 0,                5,   5,   5,  1, 0xffff8000, 0xffffffff, 0.024 },
	/*0x00*/ { 1,   1,   400,  100, 0,  0, 0,                8,   8,   5,  1, 0xffff8000, 0xffffffff, 0.024 },
	/*0x00*/ { 75,  100, 100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 75,  100, 20,   5,   0,  0, 1.8000000715256,  50,  50,  20, 1, 0xa0a0e0ff, 0xffffffff, 0.024 },
	/*0x00*/ { 20,  10,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 20,  10,  20,   5,   0,  0, 1.8000000715256,  50,  50,  20, 1, 0xa0a0e0ff, 0xffffffff, 0.024 },
	/*0x00*/ { 1,   0,   80,   1,   36, 6, 0,                100, 75,  15, 0, 0x0808f000, 0xffffffff, 0.024 },
	/*0x00*/ { 70,  0,   150,  15,  0,  0, 7.2000002861023,  33,  8,   3,  0, 0x11112880, 0xaaaaaa40, 0.024 },
	/*0x00*/ { 50,  28,  100,  1,   0,  0, 1.2,              50,  25,  10, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 300, 100, 100,  2,   0,  0, 0.36,             25,  1,   40, 2, 0xffff80ff, 0xffffffff, 0.119 },
	/*0x00*/ { 170, 80,  60,   5,   0,  0, 0.48000001907349, 25,  5,   10, 3, 0xa0a0e0ff, 0xffffffff, 0.119 },
	/*0x00*/ { 120, 40,  30,   7,   0,  0, 0.24000000953674, 50,  5,   15, 3, 0xffff80ff, 0xffffffff, 0.119 },
	/*0x00*/ { 80,  10,  10,   9,   0,  0, 0.12000000476837, 25,  5,   20, 3, 0xa0a0e0ff, 0xffffffff, 0.119 },
	/*0x00*/ { 100, 1,   100,  50,  0,  0, 2.4,              25,  16,  15, 1, 0xffff80ff, 0xffffffff, 0.024 },
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              100, 100, 30, 1, 0xff8080ff, 0xffff80ff, 0.024 },
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0x4fff4fff, 0xffffffff, 0.024 },
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2.4,              50,  50,  15, 1, 0xffff7f7f, 0xffffffff, 0.024 },
	/*0x00*/ { 40,  -1,  30,   10,  0,  0, 2.4,              41,  29,  10, 1, 0x301010ff, 0x401010ff, 0.024 },
	/*0x00*/ { 70,  0,   150,  15,  0,  0, 7.2000002861023,  33,  8,   3,  0, 0x1111a880, 0xaaaaff40, 0.024 },
#else
	/*0x00*/ { 100, 28,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x01*/ { 100, 28,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0x80ffffff, 0xffffffff, 0.02 },
	/*0x02*/ { 40,  -1,  30,   30,  0,  0, 2,                35,  35,  5,  1, 0x301010ff, 0x401010ff, 0.02 },
	/*0x03*/ { 40,  -1,  300,  200, 0,  0, 0.15,             5,   5,   4,  1, 0xffffff40, 0x560011a0, 0.02 },
	/*0x04*/ { 10,  1,   1200, 400, 0,  0, 0.15,             5,   5,   5,  1, 0xa0a0e000, 0xffffffff, 0.02 },
	/*0x05*/ { 40,  10,  10,   10,  0,  0, 3,                180, 90,  5,  1, 0x00ff6aff, 0xffffffff, 0.02 },
	/*0x06*/ { 15,  10,  20,   20,  0,  0, 0.65,             180, 90,  5,  1, 0xa0a0e0ff, 0xffffffff, 0.02 },
	/*0x07*/ { 1,   1,   120,  2,   0,  0, 0,                60,  60,  5,  1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x08*/ { 1,   1,   300,  50,  0,  0, 0,                5,   5,   5,  1, 0xffff8000, 0xffffffff, 0.02 },
	/*0x09*/ { 1,   1,   400,  100, 0,  0, 0,                10,  10,  5,  1, 0xffff8000, 0xffffffff, 0.02 },
	/*0x0a*/ { 75,  100, 100,  1,   0,  0, 2,                60,  60,  15, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x0b*/ { 75,  100, 20,   5,   0,  0, 1.5,              60,  60,  20, 1, 0xa0a0e0ff, 0xffffffff, 0.02 },
	/*0x0c*/ { 20,  10,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x0d*/ { 20,  10,  20,   5,   0,  0, 1.5,              60,  60,  20, 1, 0xa0a0e0ff, 0xffffffff, 0.02 },
	/*0x0e*/ { 1,   0,   80,   1,   30, 5, 0,                120, 90,  15, 0, 0x0808f000, 0xffffffff, 0.02 },
	/*0x0f*/ { 70,  0,   150,  15,  0,  0, 6,                40,  10,  3,  0, 0x11112880, 0xaaaaaa40, 0.02 },
	/*0x10*/ { 50,  28,  100,  1,   0,  0, 1,                60,  30,  10, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x11*/ { 300, 100, 100,  2,   0,  0, 0.3,              30,  1,   40, 2, 0xffff80ff, 0xffffffff, 0.1  },
	/*0x12*/ { 170, 80,  60,   5,   0,  0, 0.4,              30,  5,   10, 3, 0xa0a0e0ff, 0xffffffff, 0.1  },
	/*0x13*/ { 120, 40,  30,   7,   0,  0, 0.2,              60,  5,   15, 3, 0xffff80ff, 0xffffffff, 0.1  },
	/*0x14*/ { 80,  10,  10,   9,   0,  0, 0.1,              30,  5,   20, 3, 0xa0a0e0ff, 0xffffffff, 0.1  },
	/*0x15*/ { 100, 1,   100,  50,  0,  0, 2,                30,  20,  15, 1, 0xffff80ff, 0xffffffff, 0.02 },
	/*0x16*/ { 100, 28,  100,  1,   0,  0, 2,                120, 120, 30, 1, 0xff8080ff, 0xffff80ff, 0.02 },
	/*0x17*/ { 100, 28,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0x4fff4fff, 0xffffffff, 0.02 },
	/*0x18*/ { 100, 28,  100,  1,   0,  0, 2,                60,  60,  15, 1, 0xffff7f7f, 0xffffffff, 0.02 },
	/*0x19*/ { 40,  -1,  30,   10,  0,  0, 2,                50,  35,  10, 1, 0x301010ff, 0x401010ff, 0.02 },
	/*0x1a*/ { 70,  0,   150,  15,  0,  0, 6,                40,  10,  3,  0, 0x1111a880, 0xaaaaff40, 0.02 },
#endif
};

s32 g_SparksAreActive = false;

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f12f6c0
/*  f130200:	3c03800a */ 	lui	$v1,0x800a
/*  f130204:	24634560 */ 	addiu	$v1,$v1,0x4560
/*  f130208:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f13020c:	24010064 */ 	li	$at,0x64
/*  f130210:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f130214:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f130218:	0301001a */ 	div	$zero,$t8,$at
/*  f13021c:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f130220:	44800000 */ 	mtc1	$zero,$f0
/*  f130224:	3c0f800a */ 	lui	$t7,0x800a
/*  f130228:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f13022c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f130230:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f130234:	25ef3a70 */ 	addiu	$t7,$t7,0x3a70
/*  f130238:	0000c810 */ 	mfhi	$t9
/*  f13023c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f130240:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f130244:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f130248:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f13024c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f130250:	e6000000 */ 	swc1	$f0,0x0($s0)
/*  f130254:	e6000004 */ 	swc1	$f0,0x4($s0)
/*  f130258:	e6000008 */ 	swc1	$f0,0x8($s0)
/*  f13025c:	00a08825 */ 	move	$s1,$a1
/*  f130260:	0c004ad4 */ 	jal	random
/*  f130264:	e7a00020 */ 	swc1	$f0,0x20($sp)
/*  f130268:	96230000 */ 	lhu	$v1,0x0($s1)
/*  f13026c:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f130270:	00034040 */ 	sll	$t0,$v1,0x1
/*  f130274:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f130278:	0049001b */ 	divu	$zero,$v0,$t1
/*  f13027c:	00005010 */ 	mfhi	$t2
/*  f130280:	01435823 */ 	subu	$t3,$t2,$v1
/*  f130284:	448b2000 */ 	mtc1	$t3,$f4
/*  f130288:	15200002 */ 	bnez	$t1,.PF0f130294
/*  f13028c:	00000000 */ 	nop
/*  f130290:	0007000d */ 	break	0x7
.PF0f130294:
/*  f130294:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f130298:	0c004ad4 */ 	jal	random
/*  f13029c:	e606000c */ 	swc1	$f6,0xc($s0)
/*  f1302a0:	96230000 */ 	lhu	$v1,0x0($s1)
/*  f1302a4:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f1302a8:	00036040 */ 	sll	$t4,$v1,0x1
/*  f1302ac:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f1302b0:	004d001b */ 	divu	$zero,$v0,$t5
/*  f1302b4:	00007010 */ 	mfhi	$t6
/*  f1302b8:	01c37823 */ 	subu	$t7,$t6,$v1
/*  f1302bc:	448f4000 */ 	mtc1	$t7,$f8
/*  f1302c0:	15a00002 */ 	bnez	$t5,.PF0f1302cc
/*  f1302c4:	00000000 */ 	nop
/*  f1302c8:	0007000d */ 	break	0x7
.PF0f1302cc:
/*  f1302cc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1302d0:	0c004ad4 */ 	jal	random
/*  f1302d4:	e60a0010 */ 	swc1	$f10,0x10($s0)
/*  f1302d8:	96230000 */ 	lhu	$v1,0x0($s1)
/*  f1302dc:	c6100010 */ 	lwc1	$f16,0x10($s0)
/*  f1302e0:	44803000 */ 	mtc1	$zero,$f6
/*  f1302e4:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f1302e8:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f1302ec:	0059001b */ 	divu	$zero,$v0,$t9
/*  f1302f0:	00004010 */ 	mfhi	$t0
/*  f1302f4:	01034823 */ 	subu	$t1,$t0,$v1
/*  f1302f8:	44899000 */ 	mtc1	$t1,$f18
/*  f1302fc:	46103032 */ 	c.eq.s	$f6,$f16
/*  f130300:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f130304:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f130308:	17200002 */ 	bnez	$t9,.PF0f130314
/*  f13030c:	00000000 */ 	nop
/*  f130310:	0007000d */ 	break	0x7
.PF0f130314:
/*  f130314:	e6040014 */ 	swc1	$f4,0x14($s0)
/*  f130318:	45000005 */ 	bc1f	.PF0f130330
/*  f13031c:	00001025 */ 	move	$v0,$zero
/*  f130320:	3c017f1b */ 	lui	$at,0x7f1b
/*  f130324:	c4286910 */ 	lwc1	$f8,0x6910($at)
/*  f130328:	e6080010 */ 	swc1	$f8,0x10($s0)
/*  f13032c:	c6100010 */ 	lwc1	$f16,0x10($s0)
.PF0f130330:
/*  f130330:	02001825 */ 	move	$v1,$s0
/*  f130334:	2404000c */ 	li	$a0,0xc
.PF0f130338:
/*  f130338:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f13033c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f130340:	4600703c */ 	c.lt.s	$f14,$f0
/*  f130344:	46000087 */ 	neg.s	$f2,$f0
/*  f130348:	45020003 */ 	bc1fl	.PF0f130358
/*  f13034c:	4602703c */ 	c.lt.s	$f14,$f2
/*  f130350:	46000386 */ 	mov.s	$f14,$f0
/*  f130354:	4602703c */ 	c.lt.s	$f14,$f2
.PF0f130358:
/*  f130358:	00000000 */ 	nop
/*  f13035c:	45000002 */ 	bc1f	.PF0f130368
/*  f130360:	00000000 */ 	nop
/*  f130364:	46001386 */ 	mov.s	$f14,$f2
.PF0f130368:
/*  f130368:	1444fff3 */ 	bne	$v0,$a0,.PF0f130338
/*  f13036c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f130370:	c602000c */ 	lwc1	$f2,0xc($s0)
/*  f130374:	c6000014 */ 	lwc1	$f0,0x14($s0)
/*  f130378:	e7ae0020 */ 	swc1	$f14,0x20($sp)
/*  f13037c:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f130380:	00000000 */ 	nop
/*  f130384:	46108482 */ 	mul.s	$f18,$f16,$f16
/*  f130388:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f13038c:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f130390:	0c0127b4 */ 	jal	sqrtf
/*  f130394:	46043300 */ 	add.s	$f12,$f6,$f4
/*  f130398:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f13039c:	c608000c */ 	lwc1	$f8,0xc($s0)
/*  f1303a0:	c6120010 */ 	lwc1	$f18,0x10($s0)
/*  f1303a4:	46007083 */ 	div.s	$f2,$f14,$f0
/*  f1303a8:	c6040014 */ 	lwc1	$f4,0x14($s0)
/*  f1303ac:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f1303b0:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f1303b4:	00000000 */ 	nop
/*  f1303b8:	46029182 */ 	mul.s	$f6,$f18,$f2
/*  f1303bc:	00000000 */ 	nop
/*  f1303c0:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f1303c4:	e60a000c */ 	swc1	$f10,0xc($s0)
/*  f1303c8:	e6060010 */ 	swc1	$f6,0x10($s0)
/*  f1303cc:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f1303d0:	e6080014 */ 	swc1	$f8,0x14($s0)
/*  f1303d4:	962a0000 */ 	lhu	$t2,0x0($s1)
/*  f1303d8:	c608000c */ 	lwc1	$f8,0xc($s0)
/*  f1303dc:	05410003 */ 	bgez	$t2,.PF0f1303ec
/*  f1303e0:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f1303e4:	25410001 */ 	addiu	$at,$t2,0x1
/*  f1303e8:	00015843 */ 	sra	$t3,$at,0x1
.PF0f1303ec:
/*  f1303ec:	448b9000 */ 	mtc1	$t3,$f18
/*  f1303f0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1303f4:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f1303f8:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f1303fc:	e6040010 */ 	swc1	$f4,0x10($s0)
/*  f130400:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f130404:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*  f130408:	46124280 */ 	add.s	$f10,$f8,$f18
/*  f13040c:	c6120014 */ 	lwc1	$f18,0x14($s0)
/*  f130410:	e60a000c */ 	swc1	$f10,0xc($s0)
/*  f130414:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f130418:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f13041c:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f130420:	e6080010 */ 	swc1	$f8,0x10($s0)
/*  f130424:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f130428:	460a9180 */ 	add.s	$f6,$f18,$f10
/*  f13042c:	c6120010 */ 	lwc1	$f18,0x10($s0)
/*  f130430:	e6060014 */ 	swc1	$f6,0x14($s0)
/*  f130434:	c4206914 */ 	lwc1	$f0,0x6914($at)
/*  f130438:	c6060014 */ 	lwc1	$f6,0x14($s0)
/*  f13043c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f130440:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f130444:	00000000 */ 	nop
/*  f130448:	46009282 */ 	mul.s	$f10,$f18,$f0
/*  f13044c:	e608000c */ 	swc1	$f8,0xc($s0)
/*  f130450:	44804000 */ 	mtc1	$zero,$f8
/*  f130454:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f130458:	e60a0010 */ 	swc1	$f10,0x10($s0)
/*  f13045c:	c6120010 */ 	lwc1	$f18,0x10($s0)
/*  f130460:	46124032 */ 	c.eq.s	$f8,$f18
/*  f130464:	e6040014 */ 	swc1	$f4,0x14($s0)
/*  f130468:	45000003 */ 	bc1f	.PF0f130478
/*  f13046c:	00000000 */ 	nop
/*  f130470:	c42a6918 */ 	lwc1	$f10,0x6918($at)
/*  f130474:	e60a0010 */ 	swc1	$f10,0x10($s0)
.PF0f130478:
/*  f130478:	8e2c0018 */ 	lw	$t4,0x18($s1)
/*  f13047c:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f130480:	51a0000d */ 	beqzl	$t5,.PF0f1304b8
/*  f130484:	96380010 */ 	lhu	$t8,0x10($s1)
/*  f130488:	0c004ad4 */ 	jal	random
/*  f13048c:	00000000 */ 	nop
/*  f130490:	962e0010 */ 	lhu	$t6,0x10($s1)
/*  f130494:	004e001b */ 	divu	$zero,$v0,$t6
/*  f130498:	00007810 */ 	mfhi	$t7
/*  f13049c:	ae0f0018 */ 	sw	$t7,0x18($s0)
/*  f1304a0:	15c00002 */ 	bnez	$t6,.PF0f1304ac
/*  f1304a4:	00000000 */ 	nop
/*  f1304a8:	0007000d */ 	break	0x7
.PF0f1304ac:
/*  f1304ac:	10000004 */ 	b	.PF0f1304c0
/*  f1304b0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1304b4:	96380010 */ 	lhu	$t8,0x10($s1)
.PF0f1304b8:
/*  f1304b8:	ae180018 */ 	sw	$t8,0x18($s0)
/*  f1304bc:	8fbf001c */ 	lw	$ra,0x1c($sp)
.PF0f1304c0:
/*  f1304c0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1304c4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1304c8:	03e00008 */ 	jr	$ra
/*  f1304cc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#else
GLOBAL_ASM(
glabel func0f12f6c0
/*  f12f6c0:	3c03800a */ 	lui	$v1,%hi(g_NextSparkIndex)
/*  f12f6c4:	24633fc0 */ 	addiu	$v1,$v1,%lo(g_NextSparkIndex)
/*  f12f6c8:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f12f6cc:	24010064 */ 	addiu	$at,$zero,0x64
/*  f12f6d0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f12f6d4:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f12f6d8:	0301001a */ 	div	$zero,$t8,$at
/*  f12f6dc:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f12f6e0:	44800000 */ 	mtc1	$zero,$f0
/*  f12f6e4:	3c0f800a */ 	lui	$t7,%hi(g_Sparks)
/*  f12f6e8:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f12f6ec:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f12f6f0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f12f6f4:	25ef34d0 */ 	addiu	$t7,$t7,%lo(g_Sparks)
/*  f12f6f8:	0000c810 */ 	mfhi	$t9
/*  f12f6fc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f12f700:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f12f704:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f12f708:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f12f70c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f12f710:	e6000000 */ 	swc1	$f0,0x0($s0)
/*  f12f714:	e6000004 */ 	swc1	$f0,0x4($s0)
/*  f12f718:	e6000008 */ 	swc1	$f0,0x8($s0)
/*  f12f71c:	00a08825 */ 	or	$s1,$a1,$zero
/*  f12f720:	0c004b70 */ 	jal	random
/*  f12f724:	e7a00020 */ 	swc1	$f0,0x20($sp)
/*  f12f728:	96230000 */ 	lhu	$v1,0x0($s1)
/*  f12f72c:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f12f730:	00034040 */ 	sll	$t0,$v1,0x1
/*  f12f734:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f12f738:	0049001b */ 	divu	$zero,$v0,$t1
/*  f12f73c:	00005010 */ 	mfhi	$t2
/*  f12f740:	01435823 */ 	subu	$t3,$t2,$v1
/*  f12f744:	448b2000 */ 	mtc1	$t3,$f4
/*  f12f748:	15200002 */ 	bnez	$t1,.L0f12f754
/*  f12f74c:	00000000 */ 	nop
/*  f12f750:	0007000d */ 	break	0x7
.L0f12f754:
/*  f12f754:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12f758:	0c004b70 */ 	jal	random
/*  f12f75c:	e606000c */ 	swc1	$f6,0xc($s0)
/*  f12f760:	96230000 */ 	lhu	$v1,0x0($s1)
/*  f12f764:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f12f768:	00036040 */ 	sll	$t4,$v1,0x1
/*  f12f76c:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f12f770:	004d001b */ 	divu	$zero,$v0,$t5
/*  f12f774:	00007010 */ 	mfhi	$t6
/*  f12f778:	01c37823 */ 	subu	$t7,$t6,$v1
/*  f12f77c:	448f4000 */ 	mtc1	$t7,$f8
/*  f12f780:	15a00002 */ 	bnez	$t5,.L0f12f78c
/*  f12f784:	00000000 */ 	nop
/*  f12f788:	0007000d */ 	break	0x7
.L0f12f78c:
/*  f12f78c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f12f790:	0c004b70 */ 	jal	random
/*  f12f794:	e60a0010 */ 	swc1	$f10,0x10($s0)
/*  f12f798:	96230000 */ 	lhu	$v1,0x0($s1)
/*  f12f79c:	c6100010 */ 	lwc1	$f16,0x10($s0)
/*  f12f7a0:	44803000 */ 	mtc1	$zero,$f6
/*  f12f7a4:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f12f7a8:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f12f7ac:	0059001b */ 	divu	$zero,$v0,$t9
/*  f12f7b0:	00004010 */ 	mfhi	$t0
/*  f12f7b4:	01034823 */ 	subu	$t1,$t0,$v1
/*  f12f7b8:	44899000 */ 	mtc1	$t1,$f18
/*  f12f7bc:	46103032 */ 	c.eq.s	$f6,$f16
/*  f12f7c0:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f12f7c4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f12f7c8:	17200002 */ 	bnez	$t9,.L0f12f7d4
/*  f12f7cc:	00000000 */ 	nop
/*  f12f7d0:	0007000d */ 	break	0x7
.L0f12f7d4:
/*  f12f7d4:	e6040014 */ 	swc1	$f4,0x14($s0)
/*  f12f7d8:	45000005 */ 	bc1f	.L0f12f7f0
/*  f12f7dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f12f7e0:	3c017f1b */ 	lui	$at,%hi(var7f1b5600)
/*  f12f7e4:	c4285600 */ 	lwc1	$f8,%lo(var7f1b5600)($at)
/*  f12f7e8:	e6080010 */ 	swc1	$f8,0x10($s0)
/*  f12f7ec:	c6100010 */ 	lwc1	$f16,0x10($s0)
.L0f12f7f0:
/*  f12f7f0:	02001825 */ 	or	$v1,$s0,$zero
/*  f12f7f4:	2404000c */ 	addiu	$a0,$zero,0xc
.L0f12f7f8:
/*  f12f7f8:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f12f7fc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12f800:	4600703c */ 	c.lt.s	$f14,$f0
/*  f12f804:	46000087 */ 	neg.s	$f2,$f0
/*  f12f808:	45020003 */ 	bc1fl	.L0f12f818
/*  f12f80c:	4602703c */ 	c.lt.s	$f14,$f2
/*  f12f810:	46000386 */ 	mov.s	$f14,$f0
/*  f12f814:	4602703c */ 	c.lt.s	$f14,$f2
.L0f12f818:
/*  f12f818:	00000000 */ 	nop
/*  f12f81c:	45000002 */ 	bc1f	.L0f12f828
/*  f12f820:	00000000 */ 	nop
/*  f12f824:	46001386 */ 	mov.s	$f14,$f2
.L0f12f828:
/*  f12f828:	1444fff3 */ 	bne	$v0,$a0,.L0f12f7f8
/*  f12f82c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12f830:	c602000c */ 	lwc1	$f2,0xc($s0)
/*  f12f834:	c6000014 */ 	lwc1	$f0,0x14($s0)
/*  f12f838:	e7ae0020 */ 	swc1	$f14,0x20($sp)
/*  f12f83c:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f12f840:	00000000 */ 	nop
/*  f12f844:	46108482 */ 	mul.s	$f18,$f16,$f16
/*  f12f848:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12f84c:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f12f850:	0c012974 */ 	jal	sqrtf
/*  f12f854:	46043300 */ 	add.s	$f12,$f6,$f4
/*  f12f858:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f12f85c:	c608000c */ 	lwc1	$f8,0xc($s0)
/*  f12f860:	c6120010 */ 	lwc1	$f18,0x10($s0)
/*  f12f864:	46007083 */ 	div.s	$f2,$f14,$f0
/*  f12f868:	c6040014 */ 	lwc1	$f4,0x14($s0)
/*  f12f86c:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f12f870:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f12f874:	00000000 */ 	nop
/*  f12f878:	46029182 */ 	mul.s	$f6,$f18,$f2
/*  f12f87c:	00000000 */ 	nop
/*  f12f880:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f12f884:	e60a000c */ 	swc1	$f10,0xc($s0)
/*  f12f888:	e6060010 */ 	swc1	$f6,0x10($s0)
/*  f12f88c:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f12f890:	e6080014 */ 	swc1	$f8,0x14($s0)
/*  f12f894:	962a0000 */ 	lhu	$t2,0x0($s1)
/*  f12f898:	c608000c */ 	lwc1	$f8,0xc($s0)
/*  f12f89c:	05410003 */ 	bgez	$t2,.L0f12f8ac
/*  f12f8a0:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f12f8a4:	25410001 */ 	addiu	$at,$t2,0x1
/*  f12f8a8:	00015843 */ 	sra	$t3,$at,0x1
.L0f12f8ac:
/*  f12f8ac:	448b9000 */ 	mtc1	$t3,$f18
/*  f12f8b0:	3c017f1b */ 	lui	$at,%hi(var7f1b5604)
/*  f12f8b4:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f12f8b8:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f12f8bc:	e6040010 */ 	swc1	$f4,0x10($s0)
/*  f12f8c0:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f12f8c4:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*  f12f8c8:	46124280 */ 	add.s	$f10,$f8,$f18
/*  f12f8cc:	c6120014 */ 	lwc1	$f18,0x14($s0)
/*  f12f8d0:	e60a000c */ 	swc1	$f10,0xc($s0)
/*  f12f8d4:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f12f8d8:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f12f8dc:	44802000 */ 	mtc1	$zero,$f4
/*  f12f8e0:	e6080010 */ 	swc1	$f8,0x10($s0)
/*  f12f8e4:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f12f8e8:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f12f8ec:	46082032 */ 	c.eq.s	$f4,$f8
/*  f12f8f0:	460a9180 */ 	add.s	$f6,$f18,$f10
/*  f12f8f4:	45000003 */ 	bc1f	.L0f12f904
/*  f12f8f8:	e6060014 */ 	swc1	$f6,0x14($s0)
/*  f12f8fc:	c4325604 */ 	lwc1	$f18,%lo(var7f1b5604)($at)
/*  f12f900:	e6120010 */ 	swc1	$f18,0x10($s0)
.L0f12f904:
/*  f12f904:	8e2c0018 */ 	lw	$t4,0x18($s1)
/*  f12f908:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f12f90c:	51a0000d */ 	beqzl	$t5,.L0f12f944
/*  f12f910:	96380010 */ 	lhu	$t8,0x10($s1)
/*  f12f914:	0c004b70 */ 	jal	random
/*  f12f918:	00000000 */ 	nop
/*  f12f91c:	962e0010 */ 	lhu	$t6,0x10($s1)
/*  f12f920:	004e001b */ 	divu	$zero,$v0,$t6
/*  f12f924:	00007810 */ 	mfhi	$t7
/*  f12f928:	ae0f0018 */ 	sw	$t7,0x18($s0)
/*  f12f92c:	15c00002 */ 	bnez	$t6,.L0f12f938
/*  f12f930:	00000000 */ 	nop
/*  f12f934:	0007000d */ 	break	0x7
.L0f12f938:
/*  f12f938:	10000004 */ 	b	.L0f12f94c
/*  f12f93c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f12f940:	96380010 */ 	lhu	$t8,0x10($s1)
.L0f12f944:
/*  f12f944:	ae180018 */ 	sw	$t8,0x18($s0)
/*  f12f948:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f12f94c:
/*  f12f94c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f12f950:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f12f954:	03e00008 */ 	jr	$ra
/*  f12f958:	27bd0028 */ 	addiu	$sp,$sp,0x28
);
#endif

/**
 * This function handles an out-of-memory situation when creating a spark, by
 * shrinking whichever spark group was about to be overwritten.
 */
void sparkgroupEnsureFreeSparkSlot(struct sparkgroup *group)
{
	s32 i;

	for (i = 0; i < 10; i++) {
		if (&g_SparkGroups[i] != group && g_SparkGroups[i].startindex == g_NextSparkIndex) {
			g_SparkGroups[i].startindex = (g_SparkGroups[i].startindex + 1) % 100;
			g_SparkGroups[i].numsparks--;

			if (g_SparkGroups[i].numsparks == 0) {
				g_SparkGroups[i].age = 0;
			}
		}
	}
}

GLOBAL_ASM(
glabel sparksCreate
/*  f12f9f0:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f12f9f4:	3c03800a */ 	lui	$v1,%hi(var800a4130)
/*  f12f9f8:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f12f9fc:	24634130 */ 	addiu	$v1,$v1,%lo(var800a4130)
/*  f12fa00:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f12fa04:	00194080 */ 	sll	$t0,$t9,0x2
/*  f12fa08:	3c098008 */ 	lui	$t1,%hi(g_SparkTypes)
/*  f12fa0c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f12fa10:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f12fa14:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f12fa18:	3c18800a */ 	lui	$t8,%hi(g_SparkGroups)
/*  f12fa1c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f12fa20:	2529ec80 */ 	addiu	$t1,$t1,%lo(g_SparkTypes)
/*  f12fa24:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f12fa28:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f12fa2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12fa30:	27183fc8 */ 	addiu	$t8,$t8,%lo(g_SparkGroups)
/*  f12fa34:	01098021 */ 	addu	$s0,$t0,$t1
/*  f12fa38:	24010002 */ 	addiu	$at,$zero,0x2
/*  f12fa3c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f12fa40:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f12fa44:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f12fa48:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f12fa4c:	afa7007c */ 	sw	$a3,0x7c($sp)
/*  f12fa50:	01f88821 */ 	addu	$s1,$t7,$t8
/*  f12fa54:	13210004 */ 	beq	$t9,$at,.L0f12fa68
/*  f12fa58:	afb00068 */ 	sw	$s0,0x68($sp)
/*  f12fa5c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f12fa60:	5721001c */ 	bnel	$t9,$at,.L0f12fad4
/*  f12fa64:	8fa80084 */ 	lw	$t0,0x84($sp)
.L0f12fa68:
/*  f12fa68:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f12fa6c:	51400019 */ 	beqzl	$t2,.L0f12fad4
/*  f12fa70:	8fa80084 */ 	lw	$t0,0x84($sp)
/*  f12fa74:	914b0000 */ 	lbu	$t3,0x0($t2)
/*  f12fa78:	24010003 */ 	addiu	$at,$zero,0x3
/*  f12fa7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f12fa80:	55610014 */ 	bnel	$t3,$at,.L0f12fad4
/*  f12fa84:	8fa80084 */ 	lw	$t0,0x84($sp)
/*  f12fa88:	8d420004 */ 	lw	$v0,0x4($t2)
/*  f12fa8c:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f12fa90:	0fc09451 */ 	jal	bodyGetBloodColour
/*  f12fa94:	84440010 */ 	lh	$a0,0x10($v0)
/*  f12fa98:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f12fa9c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f12faa0:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f12faa4:	15810005 */ 	bne	$t4,$at,.L0f12fabc
/*  f12faa8:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f12faac:	ae0d001c */ 	sw	$t5,0x1c($s0)
/*  f12fab0:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f12fab4:	1000005f */ 	b	.L0f12fc34
/*  f12fab8:	ae0e0020 */ 	sw	$t6,0x20($s0)
.L0f12fabc:
/*  f12fabc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f12fac0:	15e1005c */ 	bne	$t7,$at,.L0f12fc34
/*  f12fac4:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f12fac8:	1000005a */ 	b	.L0f12fc34
/*  f12facc:	ae180020 */ 	sw	$t8,0x20($s0)
/*  f12fad0:	8fa80084 */ 	lw	$t0,0x84($sp)
.L0f12fad4:
/*  f12fad4:	24010019 */ 	addiu	$at,$zero,0x19
/*  f12fad8:	15010056 */ 	bne	$t0,$at,.L0f12fc34
/*  f12fadc:	00000000 */ 	nop
/*  f12fae0:	0c004b70 */ 	jal	random
/*  f12fae4:	00000000 */ 	nop
/*  f12fae8:	30490001 */ 	andi	$t1,$v0,0x1
/*  f12faec:	51200004 */ 	beqzl	$t1,.L0f12fb00
/*  f12faf0:	00002825 */ 	or	$a1,$zero,$zero
/*  f12faf4:	10000002 */ 	b	.L0f12fb00
/*  f12faf8:	3c0500ff */ 	lui	$a1,0xff
/*  f12fafc:	00002825 */ 	or	$a1,$zero,$zero
.L0f12fb00:
/*  f12fb00:	0c004b70 */ 	jal	random
/*  f12fb04:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f12fb08:	30590001 */ 	andi	$t9,$v0,0x1
/*  f12fb0c:	13200003 */ 	beqz	$t9,.L0f12fb1c
/*  f12fb10:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f12fb14:	10000002 */ 	b	.L0f12fb20
/*  f12fb18:	3c04ff00 */ 	lui	$a0,0xff00
.L0f12fb1c:
/*  f12fb1c:	00002025 */ 	or	$a0,$zero,$zero
.L0f12fb20:
/*  f12fb20:	afa40034 */ 	sw	$a0,0x34($sp)
/*  f12fb24:	0c004b70 */ 	jal	random
/*  f12fb28:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f12fb2c:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f12fb30:	8fa40034 */ 	lw	$a0,0x34($sp)
/*  f12fb34:	11600003 */ 	beqz	$t3,.L0f12fb44
/*  f12fb38:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f12fb3c:	10000002 */ 	b	.L0f12fb48
/*  f12fb40:	3403ff00 */ 	dli	$v1,0xff00
.L0f12fb44:
/*  f12fb44:	00001825 */ 	or	$v1,$zero,$zero
.L0f12fb48:
/*  f12fb48:	00645025 */ 	or	$t2,$v1,$a0
/*  f12fb4c:	01451025 */ 	or	$v0,$t2,$a1
/*  f12fb50:	344c00ff */ 	ori	$t4,$v0,0xff
/*  f12fb54:	240100ff */ 	addiu	$at,$zero,0xff
/*  f12fb58:	1581000c */ 	bne	$t4,$at,.L0f12fb8c
/*  f12fb5c:	ae0c001c */ 	sw	$t4,0x1c($s0)
/*  f12fb60:	0c004b70 */ 	jal	random
/*  f12fb64:	00000000 */ 	nop
/*  f12fb68:	24010003 */ 	addiu	$at,$zero,0x3
/*  f12fb6c:	0041001b */ 	divu	$zero,$v0,$at
/*  f12fb70:	8e0d001c */ 	lw	$t5,0x1c($s0)
/*  f12fb74:	00007010 */ 	mfhi	$t6
/*  f12fb78:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f12fb7c:	3418ff00 */ 	dli	$t8,0xff00
/*  f12fb80:	01f84004 */ 	sllv	$t0,$t8,$t7
/*  f12fb84:	01a84825 */ 	or	$t1,$t5,$t0
/*  f12fb88:	ae09001c */ 	sw	$t1,0x1c($s0)
.L0f12fb8c:
/*  f12fb8c:	0c004b70 */ 	jal	random
/*  f12fb90:	00000000 */ 	nop
/*  f12fb94:	30590001 */ 	andi	$t9,$v0,0x1
/*  f12fb98:	13200003 */ 	beqz	$t9,.L0f12fba8
/*  f12fb9c:	00002825 */ 	or	$a1,$zero,$zero
/*  f12fba0:	10000001 */ 	b	.L0f12fba8
/*  f12fba4:	3c0500ff */ 	lui	$a1,0xff
.L0f12fba8:
/*  f12fba8:	0c004b70 */ 	jal	random
/*  f12fbac:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f12fbb0:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f12fbb4:	11600003 */ 	beqz	$t3,.L0f12fbc4
/*  f12fbb8:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f12fbbc:	10000002 */ 	b	.L0f12fbc8
/*  f12fbc0:	3c04ff00 */ 	lui	$a0,0xff00
.L0f12fbc4:
/*  f12fbc4:	00002025 */ 	or	$a0,$zero,$zero
.L0f12fbc8:
/*  f12fbc8:	afa40034 */ 	sw	$a0,0x34($sp)
/*  f12fbcc:	0c004b70 */ 	jal	random
/*  f12fbd0:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f12fbd4:	304a0001 */ 	andi	$t2,$v0,0x1
/*  f12fbd8:	8fa40034 */ 	lw	$a0,0x34($sp)
/*  f12fbdc:	11400003 */ 	beqz	$t2,.L0f12fbec
/*  f12fbe0:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f12fbe4:	10000002 */ 	b	.L0f12fbf0
/*  f12fbe8:	3403ff00 */ 	dli	$v1,0xff00
.L0f12fbec:
/*  f12fbec:	00001825 */ 	or	$v1,$zero,$zero
.L0f12fbf0:
/*  f12fbf0:	00646025 */ 	or	$t4,$v1,$a0
/*  f12fbf4:	01851025 */ 	or	$v0,$t4,$a1
/*  f12fbf8:	344e00ff */ 	ori	$t6,$v0,0xff
/*  f12fbfc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f12fc00:	15c1000c */ 	bne	$t6,$at,.L0f12fc34
/*  f12fc04:	ae0e0020 */ 	sw	$t6,0x20($s0)
/*  f12fc08:	0c004b70 */ 	jal	random
/*  f12fc0c:	00000000 */ 	nop
/*  f12fc10:	24010003 */ 	addiu	$at,$zero,0x3
/*  f12fc14:	0041001b */ 	divu	$zero,$v0,$at
/*  f12fc18:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f12fc1c:	00007810 */ 	mfhi	$t7
/*  f12fc20:	000f68c0 */ 	sll	$t5,$t7,0x3
/*  f12fc24:	3408ff00 */ 	dli	$t0,0xff00
/*  f12fc28:	01a84804 */ 	sllv	$t1,$t0,$t5
/*  f12fc2c:	0309c825 */ 	or	$t9,$t8,$t1
/*  f12fc30:	ae190020 */ 	sw	$t9,0x20($s0)
.L0f12fc34:
/*  f12fc34:	3c03800a */ 	lui	$v1,%hi(var800a4130)
/*  f12fc38:	24634130 */ 	addiu	$v1,$v1,%lo(var800a4130)
/*  f12fc3c:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f12fc40:	2401000a */ 	addiu	$at,$zero,0xa
/*  f12fc44:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f12fc48:	256a0001 */ 	addiu	$t2,$t3,0x1
/*  f12fc4c:	0141001a */ 	div	$zero,$t2,$at
/*  f12fc50:	00006010 */ 	mfhi	$t4
/*  f12fc54:	2401000f */ 	addiu	$at,$zero,0xf
/*  f12fc58:	15c1001b */ 	bne	$t6,$at,.L0f12fcc8
/*  f12fc5c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f12fc60:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f12fc64:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f12fc68:	00001825 */ 	or	$v1,$zero,$zero
/*  f12fc6c:	11e00016 */ 	beqz	$t7,.L0f12fcc8
/*  f12fc70:	00004140 */ 	sll	$t0,$zero,0x5
/*  f12fc74:	3c0d800a */ 	lui	$t5,%hi(g_SparkGroups)
/*  f12fc78:	25ad3fc8 */ 	addiu	$t5,$t5,%lo(g_SparkGroups)
/*  f12fc7c:	010d1021 */ 	addu	$v0,$t0,$t5
/*  f12fc80:	8c580008 */ 	lw	$t8,0x8($v0)
.L0f12fc84:
/*  f12fc84:	57000003 */ 	bnezl	$t8,.L0f12fc94
/*  f12fc88:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f12fc8c:	00602025 */ 	or	$a0,$v1,$zero
/*  f12fc90:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f12fc94:
/*  f12fc94:	2861000a */ 	slti	$at,$v1,0xa
/*  f12fc98:	10200003 */ 	beqz	$at,.L0f12fca8
/*  f12fc9c:	24420024 */ 	addiu	$v0,$v0,0x24
/*  f12fca0:	0482fff8 */ 	bltzl	$a0,.L0f12fc84
/*  f12fca4:	8c580008 */ 	lw	$t8,0x8($v0)
.L0f12fca8:
/*  f12fca8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12fcac:	108100e0 */ 	beq	$a0,$at,.L0f130030
/*  f12fcb0:	000448c0 */ 	sll	$t1,$a0,0x3
/*  f12fcb4:	01244821 */ 	addu	$t1,$t1,$a0
/*  f12fcb8:	3c19800a */ 	lui	$t9,%hi(g_SparkGroups)
/*  f12fcbc:	27393fc8 */ 	addiu	$t9,$t9,%lo(g_SparkGroups)
/*  f12fcc0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f12fcc4:	01398821 */ 	addu	$s1,$t1,$t9
.L0f12fcc8:
/*  f12fcc8:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f12fccc:	00001825 */ 	or	$v1,$zero,$zero
/*  f12fcd0:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f12fcd4:	1160005f */ 	beqz	$t3,.L0f12fe54
/*  f12fcd8:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f12fcdc:	1040005d */ 	beqz	$v0,.L0f12fe54
/*  f12fce0:	00000000 */ 	nop
/*  f12fce4:	c44e0000 */ 	lwc1	$f14,0x0($v0)
/*  f12fce8:	c4420004 */ 	lwc1	$f2,0x4($v0)
/*  f12fcec:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f12fcf0:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f12fcf4:	afa00058 */ 	sw	$zero,0x58($sp)
/*  f12fcf8:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f12fcfc:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f12fd00:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f12fd04:	0c012974 */ 	jal	sqrtf
/*  f12fd08:	46085300 */ 	add.s	$f12,$f10,$f8
/*  f12fd0c:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f12fd10:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f12fd14:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f12fd18:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f12fd1c:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f12fd20:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f12fd24:	46005203 */ 	div.s	$f8,$f10,$f0
/*  f12fd28:	3c01c000 */ 	lui	$at,0xc000
/*  f12fd2c:	46008483 */ 	div.s	$f18,$f16,$f0
/*  f12fd30:	e4480008 */ 	swc1	$f8,0x8($v0)
/*  f12fd34:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f12fd38:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f12fd3c:	e4520000 */ 	swc1	$f18,0x0($v0)
/*  f12fd40:	c44e0000 */ 	lwc1	$f14,0x0($v0)
/*  f12fd44:	e4460004 */ 	swc1	$f6,0x4($v0)
/*  f12fd48:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f12fd4c:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f12fd50:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f12fd54:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f12fd58:	c48c0000 */ 	lwc1	$f12,0x0($a0)
/*  f12fd5c:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f12fd60:	44815000 */ 	mtc1	$at,$f10
/*  f12fd64:	460e6402 */ 	mul.s	$f16,$f12,$f14
/*  f12fd68:	46088480 */ 	add.s	$f18,$f16,$f8
/*  f12fd6c:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f12fd70:	460a3082 */ 	mul.s	$f2,$f6,$f10
/*  f12fd74:	00000000 */ 	nop
/*  f12fd78:	46027402 */ 	mul.s	$f16,$f14,$f2
/*  f12fd7c:	460c8200 */ 	add.s	$f8,$f16,$f12
/*  f12fd80:	e7a8005c */ 	swc1	$f8,0x5c($sp)
/*  f12fd84:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f12fd88:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f12fd8c:	46022482 */ 	mul.s	$f18,$f4,$f2
/*  f12fd90:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f12fd94:	e7aa0060 */ 	swc1	$f10,0x60($sp)
/*  f12fd98:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f12fd9c:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f12fda0:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f12fda4:	46028102 */ 	mul.s	$f4,$f16,$f2
/*  f12fda8:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f12fdac:	46084402 */ 	mul.s	$f16,$f8,$f8
/*  f12fdb0:	00000000 */ 	nop
/*  f12fdb4:	460a5102 */ 	mul.s	$f4,$f10,$f10
/*  f12fdb8:	e7a60064 */ 	swc1	$f6,0x64($sp)
/*  f12fdbc:	46063202 */ 	mul.s	$f8,$f6,$f6
/*  f12fdc0:	46048480 */ 	add.s	$f18,$f16,$f4
/*  f12fdc4:	0c012974 */ 	jal	sqrtf
/*  f12fdc8:	46124300 */ 	add.s	$f12,$f8,$f18
/*  f12fdcc:	44806000 */ 	mtc1	$zero,$f12
/*  f12fdd0:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f12fdd4:	46000086 */ 	mov.s	$f2,$f0
/*  f12fdd8:	460c0032 */ 	c.eq.s	$f0,$f12
/*  f12fddc:	3c013f80 */ 	lui	$at,0x3f80
/*  f12fde0:	45020004 */ 	bc1fl	.L0f12fdf4
/*  f12fde4:	860a0002 */ 	lh	$t2,0x2($s0)
/*  f12fde8:	44811000 */ 	mtc1	$at,$f2
/*  f12fdec:	00000000 */ 	nop
/*  f12fdf0:	860a0002 */ 	lh	$t2,0x2($s0)
.L0f12fdf4:
/*  f12fdf4:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f12fdf8:	c7b20060 */ 	lwc1	$f18,0x60($sp)
/*  f12fdfc:	448a3000 */ 	mtc1	$t2,$f6
/*  f12fe00:	00000000 */ 	nop
/*  f12fe04:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f12fe08:	46028103 */ 	div.s	$f4,$f16,$f2
/*  f12fe0c:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f12fe10:	e7a8005c */ 	swc1	$f8,0x5c($sp)
/*  f12fe14:	860c0002 */ 	lh	$t4,0x2($s0)
/*  f12fe18:	c7a80064 */ 	lwc1	$f8,0x64($sp)
/*  f12fe1c:	448c3000 */ 	mtc1	$t4,$f6
/*  f12fe20:	00000000 */ 	nop
/*  f12fe24:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f12fe28:	46028283 */ 	div.s	$f10,$f16,$f2
/*  f12fe2c:	460a9102 */ 	mul.s	$f4,$f18,$f10
/*  f12fe30:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*  f12fe34:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f12fe38:	448e3000 */ 	mtc1	$t6,$f6
/*  f12fe3c:	00000000 */ 	nop
/*  f12fe40:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f12fe44:	46028483 */ 	div.s	$f18,$f16,$f2
/*  f12fe48:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f12fe4c:	10000024 */ 	b	.L0f12fee0
/*  f12fe50:	e7aa0064 */ 	swc1	$f10,0x64($sp)
.L0f12fe54:
/*  f12fe54:	51e0001e */ 	beqzl	$t7,.L0f12fed0
/*  f12fe58:	44800000 */ 	mtc1	$zero,$f0
/*  f12fe5c:	86020002 */ 	lh	$v0,0x2($s0)
/*  f12fe60:	2841ffff */ 	slti	$at,$v0,-1
/*  f12fe64:	14200019 */ 	bnez	$at,.L0f12fecc
/*  f12fe68:	28410002 */ 	slti	$at,$v0,0x2
/*  f12fe6c:	10200017 */ 	beqz	$at,.L0f12fecc
/*  f12fe70:	3c014120 */ 	lui	$at,0x4120
/*  f12fe74:	44810000 */ 	mtc1	$at,$f0
/*  f12fe78:	c5e40000 */ 	lwc1	$f4,0x0($t7)
/*  f12fe7c:	44828000 */ 	mtc1	$v0,$f16
/*  f12fe80:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f12fe84:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f12fe88:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f12fe8c:	e7b2005c */ 	swc1	$f18,0x5c($sp)
/*  f12fe90:	86080002 */ 	lh	$t0,0x2($s0)
/*  f12fe94:	c5ea0004 */ 	lwc1	$f10,0x4($t7)
/*  f12fe98:	44888000 */ 	mtc1	$t0,$f16
/*  f12fe9c:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f12fea0:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f12fea4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f12fea8:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f12feac:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f12feb0:	c5f20008 */ 	lwc1	$f18,0x8($t7)
/*  f12feb4:	448d8000 */ 	mtc1	$t5,$f16
/*  f12feb8:	46009282 */ 	mul.s	$f10,$f18,$f0
/*  f12febc:	46808120 */ 	cvt.s.w	$f4,$f16
/*  f12fec0:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f12fec4:	10000006 */ 	b	.L0f12fee0
/*  f12fec8:	e7a60064 */ 	swc1	$f6,0x64($sp)
.L0f12fecc:
/*  f12fecc:	44800000 */ 	mtc1	$zero,$f0
.L0f12fed0:
/*  f12fed0:	00000000 */ 	nop
/*  f12fed4:	e7a0005c */ 	swc1	$f0,0x5c($sp)
/*  f12fed8:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f12fedc:	e7a00064 */ 	swc1	$f0,0x64($sp)
.L0f12fee0:
/*  f12fee0:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f12fee4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f12fee8:	ae290008 */ 	sw	$t1,0x8($s1)
/*  f12feec:	3c19800a */ 	lui	$t9,%hi(g_NextSparkIndex)
/*  f12fef0:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f12fef4:	8f393fc0 */ 	lw	$t9,%lo(g_NextSparkIndex)($t9)
/*  f12fef8:	ae39000c */ 	sw	$t9,0xc($s1)
/*  f12fefc:	960b0014 */ 	lhu	$t3,0x14($s0)
/*  f12ff00:	ae2b0004 */ 	sw	$t3,0x4($s1)
/*  f12ff04:	8faa0078 */ 	lw	$t2,0x78($sp)
/*  f12ff08:	c5480000 */ 	lwc1	$f8,0x0($t2)
/*  f12ff0c:	e6280018 */ 	swc1	$f8,0x18($s1)
/*  f12ff10:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f12ff14:	c5920004 */ 	lwc1	$f18,0x4($t4)
/*  f12ff18:	e632001c */ 	swc1	$f18,0x1c($s1)
/*  f12ff1c:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f12ff20:	c5d00008 */ 	lwc1	$f16,0x8($t6)
/*  f12ff24:	e6300020 */ 	swc1	$f16,0x20($s1)
/*  f12ff28:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f12ff2c:	ae280010 */ 	sw	$t0,0x10($s1)
/*  f12ff30:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f12ff34:	ae2f0014 */ 	sw	$t7,0x14($s1)
/*  f12ff38:	960d0014 */ 	lhu	$t5,0x14($s0)
/*  f12ff3c:	19a0000d */ 	blez	$t5,.L0f12ff74
/*  f12ff40:	02202025 */ 	or	$a0,$s1,$zero
.L0f12ff44:
/*  f12ff44:	0fc4be57 */ 	jal	sparkgroupEnsureFreeSparkSlot
/*  f12ff48:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f12ff4c:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f12ff50:	0fc4bdb0 */ 	jal	func0f12f6c0
/*  f12ff54:	02002825 */ 	or	$a1,$s0,$zero
/*  f12ff58:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f12ff5c:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f12ff60:	97090014 */ 	lhu	$t1,0x14($t8)
/*  f12ff64:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f12ff68:	0069082a */ 	slt	$at,$v1,$t1
/*  f12ff6c:	5420fff5 */ 	bnezl	$at,.L0f12ff44
/*  f12ff70:	02202025 */ 	or	$a0,$s1,$zero
.L0f12ff74:
/*  f12ff74:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f12ff78:	24010009 */ 	addiu	$at,$zero,0x9
/*  f12ff7c:	24050018 */ 	addiu	$a1,$zero,0x18
/*  f12ff80:	1320000b */ 	beqz	$t9,.L0f12ffb0
/*  f12ff84:	24060020 */ 	addiu	$a2,$zero,0x20
/*  f12ff88:	1321000d */ 	beq	$t9,$at,.L0f12ffc0
/*  f12ff8c:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x4b4)
/*  f12ff90:	2401000a */ 	addiu	$at,$zero,0xa
/*  f12ff94:	13210013 */ 	beq	$t9,$at,.L0f12ffe4
/*  f12ff98:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x4b4)
/*  f12ff9c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f12ffa0:	13210019 */ 	beq	$t9,$at,.L0f130008
/*  f12ffa4:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x4b4)
/*  f12ffa8:	1000001f */ 	b	.L0f130028
/*  f12ffac:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f12ffb0:
/*  f12ffb0:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f12ffb4:	8e240010 */ 	lw	$a0,0x10($s1)
/*  f12ffb8:	1000001b */ 	b	.L0f130028
/*  f12ffbc:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f12ffc0:
/*  f12ffc0:	8d6ba474 */ 	lw	$t3,%lo(g_Vars+0x4b4)($t3)
/*  f12ffc4:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f12ffc8:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f12ffcc:	11610015 */ 	beq	$t3,$at,.L0f130024
/*  f12ffd0:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f12ffd4:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f12ffd8:	8e240010 */ 	lw	$a0,0x10($s1)
/*  f12ffdc:	10000012 */ 	b	.L0f130028
/*  f12ffe0:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f12ffe4:
/*  f12ffe4:	8d4aa474 */ 	lw	$t2,%lo(g_Vars+0x4b4)($t2)
/*  f12ffe8:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f12ffec:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f12fff0:	1141000c */ 	beq	$t2,$at,.L0f130024
/*  f12fff4:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f12fff8:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f12fffc:	8e240010 */ 	lw	$a0,0x10($s1)
/*  f130000:	10000009 */ 	b	.L0f130028
/*  f130004:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f130008:
/*  f130008:	8d8ca474 */ 	lw	$t4,%lo(g_Vars+0x4b4)($t4)
/*  f13000c:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f130010:	240500c8 */ 	addiu	$a1,$zero,0xc8
/*  f130014:	11810003 */ 	beq	$t4,$at,.L0f130024
/*  f130018:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f13001c:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f130020:	8e240010 */ 	lw	$a0,0x10($s1)
.L0f130024:
/*  f130024:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f130028:
/*  f130028:	3c018008 */ 	lui	$at,%hi(g_SparksAreActive)
/*  f13002c:	ac2ef0b8 */ 	sw	$t6,%lo(g_SparksAreActive)($at)
.L0f130030:
/*  f130030:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f130034:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f130038:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f13003c:	03e00008 */ 	jr	$ra
/*  f130040:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel sparksRender
/*  f130044:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f130048:	3c0e8008 */ 	lui	$t6,%hi(g_SparksAreActive)
/*  f13004c:	8dcef0b8 */ 	lw	$t6,%lo(g_SparksAreActive)($t6)
/*  f130050:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f130054:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f130058:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f13005c:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f130060:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f130064:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f130068:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f13006c:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f130070:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f130074:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f130078:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f13007c:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f130080:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f130084:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f130088:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f13008c:	11c003e0 */ 	beqz	$t6,.L0f131010
/*  f130090:	afa40170 */ 	sw	$a0,0x170($sp)
/*  f130094:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f130098:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f13009c:	4480a000 */ 	mtc1	$zero,$f20
/*  f1300a0:	27a40170 */ 	addiu	$a0,$sp,0x170
/*  f1300a4:	c6021bc0 */ 	lwc1	$f2,0x1bc0($s0)
/*  f1300a8:	3c05800b */ 	lui	$a1,%hi(var800ab5a4)
/*  f1300ac:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f1300b0:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f1300b4:	00003825 */ 	or	$a3,$zero,$zero
/*  f1300b8:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f1300bc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1300c0:	45020004 */ 	bc1fl	.L0f1300d4
/*  f1300c4:	46001407 */ 	neg.s	$f16,$f2
/*  f1300c8:	10000002 */ 	b	.L0f1300d4
/*  f1300cc:	46001406 */ 	mov.s	$f16,$f2
/*  f1300d0:	46001407 */ 	neg.s	$f16,$f2
.L0f1300d4:
/*  f1300d4:	c60e1bbc */ 	lwc1	$f14,0x1bbc($s0)
/*  f1300d8:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f1300dc:	00000000 */ 	nop
/*  f1300e0:	45020004 */ 	bc1fl	.L0f1300f4
/*  f1300e4:	46007307 */ 	neg.s	$f12,$f14
/*  f1300e8:	10000002 */ 	b	.L0f1300f4
/*  f1300ec:	46007306 */ 	mov.s	$f12,$f14
/*  f1300f0:	46007307 */ 	neg.s	$f12,$f14
.L0f1300f4:
/*  f1300f4:	4610603c */ 	c.lt.s	$f12,$f16
/*  f1300f8:	00000000 */ 	nop
/*  f1300fc:	45020019 */ 	bc1fl	.L0f130164
/*  f130100:	c6001bc4 */ 	lwc1	$f0,0x1bc4($s0)
/*  f130104:	c6001bc4 */ 	lwc1	$f0,0x1bc4($s0)
/*  f130108:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f13010c:	00000000 */ 	nop
/*  f130110:	45020004 */ 	bc1fl	.L0f130124
/*  f130114:	46000407 */ 	neg.s	$f16,$f0
/*  f130118:	10000002 */ 	b	.L0f130124
/*  f13011c:	46000406 */ 	mov.s	$f16,$f0
/*  f130120:	46000407 */ 	neg.s	$f16,$f0
.L0f130124:
/*  f130124:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f130128:	00000000 */ 	nop
/*  f13012c:	45020004 */ 	bc1fl	.L0f130140
/*  f130130:	46001307 */ 	neg.s	$f12,$f2
/*  f130134:	10000002 */ 	b	.L0f130140
/*  f130138:	46001306 */ 	mov.s	$f12,$f2
/*  f13013c:	46001307 */ 	neg.s	$f12,$f2
.L0f130140:
/*  f130140:	4610603c */ 	c.lt.s	$f12,$f16
/*  f130144:	00000000 */ 	nop
/*  f130148:	45000003 */ 	bc1f	.L0f130158
/*  f13014c:	00000000 */ 	nop
/*  f130150:	10000019 */ 	b	.L0f1301b8
/*  f130154:	24170002 */ 	addiu	$s7,$zero,0x2
.L0f130158:
/*  f130158:	10000017 */ 	b	.L0f1301b8
/*  f13015c:	24170001 */ 	addiu	$s7,$zero,0x1
/*  f130160:	c6001bc4 */ 	lwc1	$f0,0x1bc4($s0)
.L0f130164:
/*  f130164:	0000b825 */ 	or	$s7,$zero,$zero
/*  f130168:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f13016c:	00000000 */ 	nop
/*  f130170:	45020004 */ 	bc1fl	.L0f130184
/*  f130174:	46000407 */ 	neg.s	$f16,$f0
/*  f130178:	10000002 */ 	b	.L0f130184
/*  f13017c:	46000406 */ 	mov.s	$f16,$f0
/*  f130180:	46000407 */ 	neg.s	$f16,$f0
.L0f130184:
/*  f130184:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f130188:	00000000 */ 	nop
/*  f13018c:	45020004 */ 	bc1fl	.L0f1301a0
/*  f130190:	46007307 */ 	neg.s	$f12,$f14
/*  f130194:	10000002 */ 	b	.L0f1301a0
/*  f130198:	46007306 */ 	mov.s	$f12,$f14
/*  f13019c:	46007307 */ 	neg.s	$f12,$f14
.L0f1301a0:
/*  f1301a0:	4610603c */ 	c.lt.s	$f12,$f16
/*  f1301a4:	00000000 */ 	nop
/*  f1301a8:	45000003 */ 	bc1f	.L0f1301b8
/*  f1301ac:	00000000 */ 	nop
/*  f1301b0:	10000001 */ 	b	.L0f1301b8
/*  f1301b4:	24170002 */ 	addiu	$s7,$zero,0x2
.L0f1301b8:
/*  f1301b8:	8ca5b5a4 */ 	lw	$a1,%lo(var800ab5a4)($a1)
/*  f1301bc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1301c0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1301c4:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f1301c8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1301cc:	8fb90170 */ 	lw	$t9,0x170($sp)
/*  f1301d0:	3c09ba00 */ 	lui	$t1,0xba00
/*  f1301d4:	35291402 */ 	ori	$t1,$t1,0x1402
/*  f1301d8:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f1301dc:	afa80170 */ 	sw	$t0,0x170($sp)
/*  f1301e0:	af200004 */ 	sw	$zero,0x4($t9)
/*  f1301e4:	af290000 */ 	sw	$t1,0x0($t9)
/*  f1301e8:	8faa0170 */ 	lw	$t2,0x170($sp)
/*  f1301ec:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1301f0:	358c0602 */ 	ori	$t4,$t4,0x602
/*  f1301f4:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f1301f8:	afab0170 */ 	sw	$t3,0x170($sp)
/*  f1301fc:	240d00c0 */ 	addiu	$t5,$zero,0xc0
/*  f130200:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f130204:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f130208:	8fae0170 */ 	lw	$t6,0x170($sp)
/*  f13020c:	3c190040 */ 	lui	$t9,0x40
/*  f130210:	3c18b900 */ 	lui	$t8,0xb900
/*  f130214:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f130218:	afaf0170 */ 	sw	$t7,0x170($sp)
/*  f13021c:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f130220:	373949d8 */ 	ori	$t9,$t9,0x49d8
/*  f130224:	add90004 */ 	sw	$t9,0x4($t6)
/*  f130228:	add80000 */ 	sw	$t8,0x0($t6)
/*  f13022c:	8fa80170 */ 	lw	$t0,0x170($sp)
/*  f130230:	3c0ab900 */ 	lui	$t2,0xb900
/*  f130234:	354a0002 */ 	ori	$t2,$t2,0x2
/*  f130238:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f13023c:	afa90170 */ 	sw	$t1,0x170($sp)
/*  f130240:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f130244:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f130248:	8fab0170 */ 	lw	$t3,0x170($sp)
/*  f13024c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f130250:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f130254:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f130258:	afac0170 */ 	sw	$t4,0x170($sp)
/*  f13025c:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f130260:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f130264:	8fae0170 */ 	lw	$t6,0x170($sp)
/*  f130268:	3c18ba00 */ 	lui	$t8,0xba00
/*  f13026c:	37180903 */ 	ori	$t8,$t8,0x903
/*  f130270:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f130274:	afaf0170 */ 	sw	$t7,0x170($sp)
/*  f130278:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f13027c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f130280:	add80000 */ 	sw	$t8,0x0($t6)
/*  f130284:	8fa80170 */ 	lw	$t0,0x170($sp)
/*  f130288:	3c0bff32 */ 	lui	$t3,0xff32
/*  f13028c:	3c0afcff */ 	lui	$t2,0xfcff
/*  f130290:	25090008 */ 	addiu	$t1,$t0,0x8
/*  f130294:	afa90170 */ 	sw	$t1,0x170($sp)
/*  f130298:	354a99ff */ 	ori	$t2,$t2,0x99ff
/*  f13029c:	356b7f3f */ 	ori	$t3,$t3,0x7f3f
/*  f1302a0:	3c017f1b */ 	lui	$at,%hi(var7f1b5608)
/*  f1302a4:	ad0b0004 */ 	sw	$t3,0x4($t0)
/*  f1302a8:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f1302ac:	c43c5608 */ 	lwc1	$f28,%lo(var7f1b5608)($at)
/*  f1302b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1302b4:	3c13800a */ 	lui	$s3,%hi(g_SparkGroups)
/*  f1302b8:	4481c000 */ 	mtc1	$at,$f24
/*  f1302bc:	26733fc8 */ 	addiu	$s3,$s3,%lo(g_SparkGroups)
/*  f1302c0:	c7b60120 */ 	lwc1	$f22,0x120($sp)
/*  f1302c4:	c7ba013c */ 	lwc1	$f26,0x13c($sp)
/*  f1302c8:	241e01f0 */ 	addiu	$s8,$zero,0x1f0
/*  f1302cc:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f1302d0:	8e6c0008 */ 	lw	$t4,0x8($s3)
.L0f1302d4:
/*  f1302d4:	afb3016c */ 	sw	$s3,0x16c($sp)
/*  f1302d8:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f1302dc:	11800345 */ 	beqz	$t4,.L0f130ff4
/*  f1302e0:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f1302e4:	8e620014 */ 	lw	$v0,0x14($s3)
/*  f1302e8:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f1302ec:	4600c406 */ 	mov.s	$f16,$f24
/*  f1302f0:	10400007 */ 	beqz	$v0,.L0f130310
/*  f1302f4:	96030010 */ 	lhu	$v1,0x10($s0)
/*  f1302f8:	904d0001 */ 	lbu	$t5,0x1($v0)
/*  f1302fc:	31ae0002 */ 	andi	$t6,$t5,0x2
/*  f130300:	55c00012 */ 	bnezl	$t6,.L0f13034c
/*  f130304:	24010001 */ 	addiu	$at,$zero,0x1
/*  f130308:	1000000f */ 	b	.L0f130348
/*  f13030c:	00008825 */ 	or	$s1,$zero,$zero
.L0f130310:
/*  f130310:	8e780010 */ 	lw	$t8,0x10($s3)
/*  f130314:	3c0f800a */ 	lui	$t7,%hi(g_Rooms)
/*  f130318:	8def4928 */ 	lw	$t7,%lo(g_Rooms)($t7)
/*  f13031c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f130320:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f130324:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f130328:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f13032c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f130330:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f130334:	95090000 */ 	lhu	$t1,0x0($t0)
/*  f130338:	312a0004 */ 	andi	$t2,$t1,0x4
/*  f13033c:	55400003 */ 	bnezl	$t2,.L0f13034c
/*  f130340:	24010001 */ 	addiu	$at,$zero,0x1
/*  f130344:	00008825 */ 	or	$s1,$zero,$zero
.L0f130348:
/*  f130348:	24010001 */ 	addiu	$at,$zero,0x1
.L0f13034c:
/*  f13034c:	1461002c */ 	bne	$v1,$at,.L0f130400
/*  f130350:	00000000 */ 	nop
/*  f130354:	c6640020 */ 	lwc1	$f4,0x20($s3)
/*  f130358:	c6060020 */ 	lwc1	$f6,0x20($s0)
/*  f13035c:	c6680018 */ 	lwc1	$f8,0x18($s3)
/*  f130360:	c60a0018 */ 	lwc1	$f10,0x18($s0)
/*  f130364:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f130368:	c604001c */ 	lwc1	$f4,0x1c($s0)
/*  f13036c:	c672001c */ 	lwc1	$f18,0x1c($s3)
/*  f130370:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f130374:	e7b00138 */ 	swc1	$f16,0x138($sp)
/*  f130378:	46049381 */ 	sub.s	$f14,$f18,$f4
/*  f13037c:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f130380:	00000000 */ 	nop
/*  f130384:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f130388:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f13038c:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f130390:	0c012974 */ 	jal	sqrtf
/*  f130394:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f130398:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f13039c:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f1303a0:	3c014316 */ 	lui	$at,0x4316
/*  f1303a4:	44812000 */ 	mtc1	$at,$f4
/*  f1303a8:	c6020024 */ 	lwc1	$f2,0x24($s0)
/*  f1303ac:	c7b00138 */ 	lwc1	$f16,0x138($sp)
/*  f1303b0:	3c014316 */ 	lui	$at,0x4316
/*  f1303b4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f1303b8:	46041301 */ 	sub.s	$f12,$f2,$f4
/*  f1303bc:	45000002 */ 	bc1f	.L0f1303c8
/*  f1303c0:	46020683 */ 	div.s	$f26,$f0,$f2
/*  f1303c4:	00008825 */ 	or	$s1,$zero,$zero
.L0f1303c8:
/*  f1303c8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f1303cc:	00000000 */ 	nop
/*  f1303d0:	45020007 */ 	bc1fl	.L0f1303f0
/*  f1303d4:	461ac03c */ 	c.lt.s	$f24,$f26
/*  f1303d8:	460c0181 */ 	sub.s	$f6,$f0,$f12
/*  f1303dc:	44814000 */ 	mtc1	$at,$f8
/*  f1303e0:	00000000 */ 	nop
/*  f1303e4:	46083483 */ 	div.s	$f18,$f6,$f8
/*  f1303e8:	4612c401 */ 	sub.s	$f16,$f24,$f18
/*  f1303ec:	461ac03c */ 	c.lt.s	$f24,$f26
.L0f1303f0:
/*  f1303f0:	00000000 */ 	nop
/*  f1303f4:	45000002 */ 	bc1f	.L0f130400
/*  f1303f8:	00000000 */ 	nop
/*  f1303fc:	4600c686 */ 	mov.s	$f26,$f24
.L0f130400:
/*  f130400:	12200020 */ 	beqz	$s1,.L0f130484
/*  f130404:	26021bb0 */ 	addiu	$v0,$s0,0x1bb0
/*  f130408:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f13040c:	c6640018 */ 	lwc1	$f4,0x18($s3)
/*  f130410:	c672001c */ 	lwc1	$f18,0x1c($s3)
/*  f130414:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f130418:	e7a60124 */ 	swc1	$f6,0x124($sp)
/*  f13041c:	c4480004 */ 	lwc1	$f8,0x4($v0)
/*  f130420:	c6660020 */ 	lwc1	$f6,0x20($s3)
/*  f130424:	46124281 */ 	sub.s	$f10,$f8,$f18
/*  f130428:	c7b20124 */ 	lwc1	$f18,0x124($sp)
/*  f13042c:	e7aa0128 */ 	swc1	$f10,0x128($sp)
/*  f130430:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f130434:	46129282 */ 	mul.s	$f10,$f18,$f18
/*  f130438:	e7b00138 */ 	swc1	$f16,0x138($sp)
/*  f13043c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f130440:	c7a40128 */ 	lwc1	$f4,0x128($sp)
/*  f130444:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f130448:	e7a8012c */ 	swc1	$f8,0x12c($sp)
/*  f13044c:	c7b2012c */ 	lwc1	$f18,0x12c($sp)
/*  f130450:	46129102 */ 	mul.s	$f4,$f18,$f18
/*  f130454:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f130458:	0c012974 */ 	jal	sqrtf
/*  f13045c:	46082300 */ 	add.s	$f12,$f4,$f8
/*  f130460:	3c017f1b */ 	lui	$at,%hi(var7f1b560c)
/*  f130464:	c42a560c */ 	lwc1	$f10,%lo(var7f1b560c)($at)
/*  f130468:	c7b00138 */ 	lwc1	$f16,0x138($sp)
/*  f13046c:	46000586 */ 	mov.s	$f22,$f0
/*  f130470:	4600503c */ 	c.lt.s	$f10,$f0
/*  f130474:	00000000 */ 	nop
/*  f130478:	45000002 */ 	bc1f	.L0f130484
/*  f13047c:	00000000 */ 	nop
/*  f130480:	00008825 */ 	or	$s1,$zero,$zero
.L0f130484:
/*  f130484:	122002db */ 	beqz	$s1,.L0f130ff4
/*  f130488:	3c0d8008 */ 	lui	$t5,%hi(g_SparkTypes)
/*  f13048c:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f130490:	25adec80 */ 	addiu	$t5,$t5,%lo(g_SparkTypes)
/*  f130494:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f130498:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f13049c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f1304a0:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f1304a4:	018d9021 */ 	addu	$s2,$t4,$t5
/*  f1304a8:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1304ac:	26750018 */ 	addiu	$s5,$s3,0x18
/*  f1304b0:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f1304b4:	e7b00138 */ 	swc1	$f16,0x138($sp)
/*  f1304b8:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f1304bc:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f1304c0:	c7b00138 */ 	lwc1	$f16,0x138($sp)
/*  f1304c4:	00408825 */ 	or	$s1,$v0,$zero
/*  f1304c8:	8e0400d8 */ 	lw	$a0,0xd8($s0)
/*  f1304cc:	3c0e8007 */ 	lui	$t6,%hi(g_InCutscene)
/*  f1304d0:	14800013 */ 	bnez	$a0,.L0f130520
/*  f1304d4:	00000000 */ 	nop
/*  f1304d8:	8dce0764 */ 	lw	$t6,%lo(g_InCutscene)($t6)
/*  f1304dc:	15c00010 */ 	bnez	$t6,.L0f130520
/*  f1304e0:	00000000 */ 	nop
/*  f1304e4:	8e030480 */ 	lw	$v1,0x480($s0)
/*  f1304e8:	50600007 */ 	beqzl	$v1,.L0f130508
/*  f1304ec:	8e191c54 */ 	lw	$t9,0x1c54($s0)
/*  f1304f0:	1060000b */ 	beqz	$v1,.L0f130520
/*  f1304f4:	00000000 */ 	nop
/*  f1304f8:	80780037 */ 	lb	$t8,0x37($v1)
/*  f1304fc:	17000008 */ 	bnez	$t8,.L0f130520
/*  f130500:	00000000 */ 	nop
/*  f130504:	8e191c54 */ 	lw	$t9,0x1c54($s0)
.L0f130508:
/*  f130508:	8e0f00c4 */ 	lw	$t7,0xc4($s0)
/*  f13050c:	03204027 */ 	nor	$t0,$t9,$zero
/*  f130510:	01e84824 */ 	and	$t1,$t7,$t0
/*  f130514:	312a0001 */ 	andi	$t2,$t1,0x1
/*  f130518:	55400016 */ 	bnezl	$t2,.L0f130574
/*  f13051c:	8e48001c */ 	lw	$t0,0x1c($s2)
.L0f130520:
/*  f130520:	14800018 */ 	bnez	$a0,.L0f130584
/*  f130524:	3c0b8007 */ 	lui	$t3,%hi(g_InCutscene)
/*  f130528:	8d6b0764 */ 	lw	$t3,%lo(g_InCutscene)($t3)
/*  f13052c:	55600016 */ 	bnezl	$t3,.L0f130588
/*  f130530:	960a0010 */ 	lhu	$t2,0x10($s0)
/*  f130534:	8e030480 */ 	lw	$v1,0x480($s0)
/*  f130538:	50600007 */ 	beqzl	$v1,.L0f130558
/*  f13053c:	8e0e1c54 */ 	lw	$t6,0x1c54($s0)
/*  f130540:	50600011 */ 	beqzl	$v1,.L0f130588
/*  f130544:	960a0010 */ 	lhu	$t2,0x10($s0)
/*  f130548:	806c0037 */ 	lb	$t4,0x37($v1)
/*  f13054c:	5580000e */ 	bnezl	$t4,.L0f130588
/*  f130550:	960a0010 */ 	lhu	$t2,0x10($s0)
/*  f130554:	8e0e1c54 */ 	lw	$t6,0x1c54($s0)
.L0f130558:
/*  f130558:	8e0d00c4 */ 	lw	$t5,0xc4($s0)
/*  f13055c:	01c0c027 */ 	nor	$t8,$t6,$zero
/*  f130560:	01b8c824 */ 	and	$t9,$t5,$t8
/*  f130564:	332f0008 */ 	andi	$t7,$t9,0x8
/*  f130568:	51e00007 */ 	beqzl	$t7,.L0f130588
/*  f13056c:	960a0010 */ 	lhu	$t2,0x10($s0)
/*  f130570:	8e48001c */ 	lw	$t0,0x1c($s2)
.L0f130574:
/*  f130574:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f130578:	8e490020 */ 	lw	$t1,0x20($s2)
/*  f13057c:	100000b2 */ 	b	.L0f130848
/*  f130580:	ac490004 */ 	sw	$t1,0x4($v0)
.L0f130584:
/*  f130584:	960a0010 */ 	lhu	$t2,0x10($s0)
.L0f130588:
/*  f130588:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13058c:	554100ab */ 	bnel	$t2,$at,.L0f13083c
/*  f130590:	8e49001c */ 	lw	$t1,0x1c($s2)
/*  f130594:	461ac181 */ 	sub.s	$f6,$f24,$f26
/*  f130598:	3c01437f */ 	lui	$at,0x437f
/*  f13059c:	44819000 */ 	mtc1	$at,$f18
/*  f1305a0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1305a4:	3c014f00 */ 	lui	$at,0x4f00
/*  f1305a8:	46123102 */ 	mul.s	$f4,$f6,$f18
/*  f1305ac:	444bf800 */ 	cfc1	$t3,$31
/*  f1305b0:	44ccf800 */ 	ctc1	$t4,$31
/*  f1305b4:	00000000 */ 	nop
/*  f1305b8:	46002224 */ 	cvt.w.s	$f8,$f4
/*  f1305bc:	444cf800 */ 	cfc1	$t4,$31
/*  f1305c0:	00000000 */ 	nop
/*  f1305c4:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f1305c8:	51800013 */ 	beqzl	$t4,.L0f130618
/*  f1305cc:	440c4000 */ 	mfc1	$t4,$f8
/*  f1305d0:	44814000 */ 	mtc1	$at,$f8
/*  f1305d4:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1305d8:	46082201 */ 	sub.s	$f8,$f4,$f8
/*  f1305dc:	44ccf800 */ 	ctc1	$t4,$31
/*  f1305e0:	00000000 */ 	nop
/*  f1305e4:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1305e8:	444cf800 */ 	cfc1	$t4,$31
/*  f1305ec:	00000000 */ 	nop
/*  f1305f0:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f1305f4:	15800005 */ 	bnez	$t4,.L0f13060c
/*  f1305f8:	00000000 */ 	nop
/*  f1305fc:	440c4000 */ 	mfc1	$t4,$f8
/*  f130600:	3c018000 */ 	lui	$at,0x8000
/*  f130604:	10000007 */ 	b	.L0f130624
/*  f130608:	01816025 */ 	or	$t4,$t4,$at
.L0f13060c:
/*  f13060c:	10000005 */ 	b	.L0f130624
/*  f130610:	240cffff */ 	addiu	$t4,$zero,-1
/*  f130614:	440c4000 */ 	mfc1	$t4,$f8
.L0f130618:
/*  f130618:	00000000 */ 	nop
/*  f13061c:	0580fffb */ 	bltz	$t4,.L0f13060c
/*  f130620:	00000000 */ 	nop
.L0f130624:
/*  f130624:	3c01437f */ 	lui	$at,0x437f
/*  f130628:	44cbf800 */ 	ctc1	$t3,$31
/*  f13062c:	44815000 */ 	mtc1	$at,$f10
/*  f130630:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f130634:	3c014f00 */ 	lui	$at,0x4f00
/*  f130638:	460ad182 */ 	mul.s	$f6,$f26,$f10
/*  f13063c:	000c7400 */ 	sll	$t6,$t4,0x10
/*  f130640:	444df800 */ 	cfc1	$t5,$31
/*  f130644:	44d8f800 */ 	ctc1	$t8,$31
/*  f130648:	00000000 */ 	nop
/*  f13064c:	460034a4 */ 	cvt.w.s	$f18,$f6
/*  f130650:	4458f800 */ 	cfc1	$t8,$31
/*  f130654:	00000000 */ 	nop
/*  f130658:	33180078 */ 	andi	$t8,$t8,0x78
/*  f13065c:	53000013 */ 	beqzl	$t8,.L0f1306ac
/*  f130660:	44189000 */ 	mfc1	$t8,$f18
/*  f130664:	44819000 */ 	mtc1	$at,$f18
/*  f130668:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f13066c:	46123481 */ 	sub.s	$f18,$f6,$f18
/*  f130670:	44d8f800 */ 	ctc1	$t8,$31
/*  f130674:	00000000 */ 	nop
/*  f130678:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f13067c:	4458f800 */ 	cfc1	$t8,$31
/*  f130680:	00000000 */ 	nop
/*  f130684:	33180078 */ 	andi	$t8,$t8,0x78
/*  f130688:	17000005 */ 	bnez	$t8,.L0f1306a0
/*  f13068c:	00000000 */ 	nop
/*  f130690:	44189000 */ 	mfc1	$t8,$f18
/*  f130694:	3c018000 */ 	lui	$at,0x8000
/*  f130698:	10000007 */ 	b	.L0f1306b8
/*  f13069c:	0301c025 */ 	or	$t8,$t8,$at
.L0f1306a0:
/*  f1306a0:	10000005 */ 	b	.L0f1306b8
/*  f1306a4:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f1306a8:	44189000 */ 	mfc1	$t8,$f18
.L0f1306ac:
/*  f1306ac:	00000000 */ 	nop
/*  f1306b0:	0700fffb */ 	bltz	$t8,.L0f1306a0
/*  f1306b4:	00000000 */ 	nop
.L0f1306b8:
/*  f1306b8:	8e4f001c */ 	lw	$t7,0x1c($s2)
/*  f1306bc:	44cdf800 */ 	ctc1	$t5,$31
/*  f1306c0:	0018ce00 */ 	sll	$t9,$t8,0x18
/*  f1306c4:	31e800ff */ 	andi	$t0,$t7,0xff
/*  f1306c8:	44882000 */ 	mtc1	$t0,$f4
/*  f1306cc:	032e1825 */ 	or	$v1,$t9,$t6
/*  f1306d0:	05010005 */ 	bgez	$t0,.L0f1306e8
/*  f1306d4:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f1306d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1306dc:	44815000 */ 	mtc1	$at,$f10
/*  f1306e0:	00000000 */ 	nop
/*  f1306e4:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f1306e8:
/*  f1306e8:	46088182 */ 	mul.s	$f6,$f16,$f8
/*  f1306ec:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1306f0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1306f4:	4449f800 */ 	cfc1	$t1,$31
/*  f1306f8:	44caf800 */ 	ctc1	$t2,$31
/*  f1306fc:	00000000 */ 	nop
/*  f130700:	460034a4 */ 	cvt.w.s	$f18,$f6
/*  f130704:	444af800 */ 	cfc1	$t2,$31
/*  f130708:	00000000 */ 	nop
/*  f13070c:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f130710:	51400013 */ 	beqzl	$t2,.L0f130760
/*  f130714:	440a9000 */ 	mfc1	$t2,$f18
/*  f130718:	44819000 */ 	mtc1	$at,$f18
/*  f13071c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f130720:	46123481 */ 	sub.s	$f18,$f6,$f18
/*  f130724:	44caf800 */ 	ctc1	$t2,$31
/*  f130728:	00000000 */ 	nop
/*  f13072c:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f130730:	444af800 */ 	cfc1	$t2,$31
/*  f130734:	00000000 */ 	nop
/*  f130738:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f13073c:	15400005 */ 	bnez	$t2,.L0f130754
/*  f130740:	00000000 */ 	nop
/*  f130744:	440a9000 */ 	mfc1	$t2,$f18
/*  f130748:	3c018000 */ 	lui	$at,0x8000
/*  f13074c:	10000007 */ 	b	.L0f13076c
/*  f130750:	01415025 */ 	or	$t2,$t2,$at
.L0f130754:
/*  f130754:	10000005 */ 	b	.L0f13076c
/*  f130758:	240affff */ 	addiu	$t2,$zero,-1
/*  f13075c:	440a9000 */ 	mfc1	$t2,$f18
.L0f130760:
/*  f130760:	00000000 */ 	nop
/*  f130764:	0540fffb */ 	bltz	$t2,.L0f130754
/*  f130768:	00000000 */ 	nop
.L0f13076c:
/*  f13076c:	006a5825 */ 	or	$t3,$v1,$t2
/*  f130770:	356c3f00 */ 	ori	$t4,$t3,0x3f00
/*  f130774:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f130778:	8e4d001c */ 	lw	$t5,0x1c($s2)
/*  f13077c:	44c9f800 */ 	ctc1	$t1,$31
/*  f130780:	3c014f80 */ 	lui	$at,0x4f80
/*  f130784:	31b800ff */ 	andi	$t8,$t5,0xff
/*  f130788:	44982000 */ 	mtc1	$t8,$f4
/*  f13078c:	07010004 */ 	bgez	$t8,.L0f1307a0
/*  f130790:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f130794:	44814000 */ 	mtc1	$at,$f8
/*  f130798:	00000000 */ 	nop
/*  f13079c:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f1307a0:
/*  f1307a0:	460a8182 */ 	mul.s	$f6,$f16,$f10
/*  f1307a4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1307a8:	3c014f00 */ 	lui	$at,0x4f00
/*  f1307ac:	4459f800 */ 	cfc1	$t9,$31
/*  f1307b0:	44cef800 */ 	ctc1	$t6,$31
/*  f1307b4:	00000000 */ 	nop
/*  f1307b8:	460034a4 */ 	cvt.w.s	$f18,$f6
/*  f1307bc:	444ef800 */ 	cfc1	$t6,$31
/*  f1307c0:	00000000 */ 	nop
/*  f1307c4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1307c8:	51c00013 */ 	beqzl	$t6,.L0f130818
/*  f1307cc:	440e9000 */ 	mfc1	$t6,$f18
/*  f1307d0:	44819000 */ 	mtc1	$at,$f18
/*  f1307d4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1307d8:	46123481 */ 	sub.s	$f18,$f6,$f18
/*  f1307dc:	44cef800 */ 	ctc1	$t6,$31
/*  f1307e0:	00000000 */ 	nop
/*  f1307e4:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f1307e8:	444ef800 */ 	cfc1	$t6,$31
/*  f1307ec:	00000000 */ 	nop
/*  f1307f0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1307f4:	15c00005 */ 	bnez	$t6,.L0f13080c
/*  f1307f8:	00000000 */ 	nop
/*  f1307fc:	440e9000 */ 	mfc1	$t6,$f18
/*  f130800:	3c018000 */ 	lui	$at,0x8000
/*  f130804:	10000007 */ 	b	.L0f130824
/*  f130808:	01c17025 */ 	or	$t6,$t6,$at
.L0f13080c:
/*  f13080c:	10000005 */ 	b	.L0f130824
/*  f130810:	240effff */ 	addiu	$t6,$zero,-1
/*  f130814:	440e9000 */ 	mfc1	$t6,$f18
.L0f130818:
/*  f130818:	00000000 */ 	nop
/*  f13081c:	05c0fffb */ 	bltz	$t6,.L0f13080c
/*  f130820:	00000000 */ 	nop
.L0f130824:
/*  f130824:	006e7825 */ 	or	$t7,$v1,$t6
/*  f130828:	35e83f00 */ 	ori	$t0,$t7,0x3f00
/*  f13082c:	44d9f800 */ 	ctc1	$t9,$31
/*  f130830:	10000005 */ 	b	.L0f130848
/*  f130834:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f130838:	8e49001c */ 	lw	$t1,0x1c($s2)
.L0f13083c:
/*  f13083c:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f130840:	8e4a0020 */ 	lw	$t2,0x20($s2)
/*  f130844:	ac4a0004 */ 	sw	$t2,0x4($v0)
.L0f130848:
/*  f130848:	96440012 */ 	lhu	$a0,0x12($s2)
/*  f13084c:	96470010 */ 	lhu	$a3,0x10($s2)
/*  f130850:	3c0a0704 */ 	lui	$t2,0x704
/*  f130854:	0087082a */ 	slt	$at,$a0,$a3
/*  f130858:	50200064 */ 	beqzl	$at,.L0f1309ec
/*  f13085c:	8fb00170 */ 	lw	$s0,0x170($sp)
/*  f130860:	8e660008 */ 	lw	$a2,0x8($s3)
/*  f130864:	00e41823 */ 	subu	$v1,$a3,$a0
/*  f130868:	0086082a */ 	slt	$at,$a0,$a2
/*  f13086c:	1020005e */ 	beqz	$at,.L0f1309e8
/*  f130870:	00c42823 */ 	subu	$a1,$a2,$a0
/*  f130874:	00655823 */ 	subu	$t3,$v1,$a1
/*  f130878:	448b2000 */ 	mtc1	$t3,$f4
/*  f13087c:	44835000 */ 	mtc1	$v1,$f10
/*  f130880:	904c0003 */ 	lbu	$t4,0x3($v0)
/*  f130884:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f130888:	3c014f80 */ 	lui	$at,0x4f80
/*  f13088c:	448c9000 */ 	mtc1	$t4,$f18
/*  f130890:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f130894:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f130898:	05810004 */ 	bgez	$t4,.L0f1308ac
/*  f13089c:	46064003 */ 	div.s	$f0,$f8,$f6
/*  f1308a0:	44815000 */ 	mtc1	$at,$f10
/*  f1308a4:	00000000 */ 	nop
/*  f1308a8:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f1308ac:
/*  f1308ac:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f1308b0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1308b4:	3c014f00 */ 	lui	$at,0x4f00
/*  f1308b8:	444df800 */ 	cfc1	$t5,$31
/*  f1308bc:	44d8f800 */ 	ctc1	$t8,$31
/*  f1308c0:	00000000 */ 	nop
/*  f1308c4:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f1308c8:	4458f800 */ 	cfc1	$t8,$31
/*  f1308cc:	00000000 */ 	nop
/*  f1308d0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1308d4:	53000013 */ 	beqzl	$t8,.L0f130924
/*  f1308d8:	44183000 */ 	mfc1	$t8,$f6
/*  f1308dc:	44813000 */ 	mtc1	$at,$f6
/*  f1308e0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1308e4:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f1308e8:	44d8f800 */ 	ctc1	$t8,$31
/*  f1308ec:	00000000 */ 	nop
/*  f1308f0:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f1308f4:	4458f800 */ 	cfc1	$t8,$31
/*  f1308f8:	00000000 */ 	nop
/*  f1308fc:	33180078 */ 	andi	$t8,$t8,0x78
/*  f130900:	17000005 */ 	bnez	$t8,.L0f130918
/*  f130904:	00000000 */ 	nop
/*  f130908:	44183000 */ 	mfc1	$t8,$f6
/*  f13090c:	3c018000 */ 	lui	$at,0x8000
/*  f130910:	10000007 */ 	b	.L0f130930
/*  f130914:	0301c025 */ 	or	$t8,$t8,$at
.L0f130918:
/*  f130918:	10000005 */ 	b	.L0f130930
/*  f13091c:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f130920:	44183000 */ 	mfc1	$t8,$f6
.L0f130924:
/*  f130924:	00000000 */ 	nop
/*  f130928:	0700fffb */ 	bltz	$t8,.L0f130918
/*  f13092c:	00000000 */ 	nop
.L0f130930:
/*  f130930:	90590007 */ 	lbu	$t9,0x7($v0)
/*  f130934:	44cdf800 */ 	ctc1	$t5,$31
/*  f130938:	a0580003 */ 	sb	$t8,0x3($v0)
/*  f13093c:	44999000 */ 	mtc1	$t9,$f18
/*  f130940:	3c014f80 */ 	lui	$at,0x4f80
/*  f130944:	07210004 */ 	bgez	$t9,.L0f130958
/*  f130948:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f13094c:	44812000 */ 	mtc1	$at,$f4
/*  f130950:	00000000 */ 	nop
/*  f130954:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f130958:
/*  f130958:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f13095c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f130960:	3c014f00 */ 	lui	$at,0x4f00
/*  f130964:	444ef800 */ 	cfc1	$t6,$31
/*  f130968:	44cff800 */ 	ctc1	$t7,$31
/*  f13096c:	00000000 */ 	nop
/*  f130970:	460041a4 */ 	cvt.w.s	$f6,$f8
/*  f130974:	444ff800 */ 	cfc1	$t7,$31
/*  f130978:	00000000 */ 	nop
/*  f13097c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f130980:	51e00013 */ 	beqzl	$t7,.L0f1309d0
/*  f130984:	440f3000 */ 	mfc1	$t7,$f6
/*  f130988:	44813000 */ 	mtc1	$at,$f6
/*  f13098c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f130990:	46064181 */ 	sub.s	$f6,$f8,$f6
/*  f130994:	44cff800 */ 	ctc1	$t7,$31
/*  f130998:	00000000 */ 	nop
/*  f13099c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f1309a0:	444ff800 */ 	cfc1	$t7,$31
/*  f1309a4:	00000000 */ 	nop
/*  f1309a8:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f1309ac:	15e00005 */ 	bnez	$t7,.L0f1309c4
/*  f1309b0:	00000000 */ 	nop
/*  f1309b4:	440f3000 */ 	mfc1	$t7,$f6
/*  f1309b8:	3c018000 */ 	lui	$at,0x8000
/*  f1309bc:	10000007 */ 	b	.L0f1309dc
/*  f1309c0:	01e17825 */ 	or	$t7,$t7,$at
.L0f1309c4:
/*  f1309c4:	10000005 */ 	b	.L0f1309dc
/*  f1309c8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1309cc:	440f3000 */ 	mfc1	$t7,$f6
.L0f1309d0:
/*  f1309d0:	00000000 */ 	nop
/*  f1309d4:	05e0fffb */ 	bltz	$t7,.L0f1309c4
/*  f1309d8:	00000000 */ 	nop
.L0f1309dc:
/*  f1309dc:	44cef800 */ 	ctc1	$t6,$31
/*  f1309e0:	a04f0007 */ 	sb	$t7,0x7($v0)
/*  f1309e4:	00000000 */ 	nop
.L0f1309e8:
/*  f1309e8:	8fb00170 */ 	lw	$s0,0x170($sp)
.L0f1309ec:
/*  f1309ec:	354a0008 */ 	ori	$t2,$t2,0x8
/*  f1309f0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1309f4:	26090008 */ 	addiu	$t1,$s0,0x8
/*  f1309f8:	afa90170 */ 	sw	$t1,0x170($sp)
/*  f1309fc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f130a00:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f130a04:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f130a08:	3c017f1b */ 	lui	$at,%hi(var7f1b5610)
/*  f130a0c:	c4325610 */ 	lwc1	$f18,%lo(var7f1b5610)($at)
/*  f130a10:	4612b582 */ 	mul.s	$f22,$f22,$f18
/*  f130a14:	0c002f9d */ 	jal	viGetFovY
/*  f130a18:	00000000 */ 	nop
/*  f130a1c:	3c014270 */ 	lui	$at,0x4270
/*  f130a20:	44812000 */ 	mtc1	$at,$f4
/*  f130a24:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f130a28:	46040283 */ 	div.s	$f10,$f0,$f4
/*  f130a2c:	460ab582 */ 	mul.s	$f22,$f22,$f10
/*  f130a30:	0c00566c */ 	jal	func000159b0
/*  f130a34:	00000000 */ 	nop
/*  f130a38:	e7bc00d4 */ 	swc1	$f28,0xd4($sp)
/*  f130a3c:	e7bc00e8 */ 	swc1	$f28,0xe8($sp)
/*  f130a40:	e7bc00fc */ 	swc1	$f28,0xfc($sp)
/*  f130a44:	e7bc0110 */ 	swc1	$f28,0x110($sp)
/*  f130a48:	02a02025 */ 	or	$a0,$s5,$zero
/*  f130a4c:	0c005775 */ 	jal	func00015dd4
/*  f130a50:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f130a54:	0fc2d5be */ 	jal	currentPlayerGetMatrix1740
/*  f130a58:	00000000 */ 	nop
/*  f130a5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f130a60:	0c0056f8 */ 	jal	func00015be0
/*  f130a64:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f130a68:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f130a6c:	00000000 */ 	nop
/*  f130a70:	00408825 */ 	or	$s1,$v0,$zero
/*  f130a74:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f130a78:	0c005815 */ 	jal	func00016054
/*  f130a7c:	00402825 */ 	or	$a1,$v0,$zero
/*  f130a80:	8fb00170 */ 	lw	$s0,0x170($sp)
/*  f130a84:	3c0d0102 */ 	lui	$t5,0x102
/*  f130a88:	35ad0040 */ 	ori	$t5,$t5,0x40
/*  f130a8c:	260c0008 */ 	addiu	$t4,$s0,0x8
/*  f130a90:	afac0170 */ 	sw	$t4,0x170($sp)
/*  f130a94:	02202025 */ 	or	$a0,$s1,$zero
/*  f130a98:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f130a9c:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f130aa0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f130aa4:	8e780004 */ 	lw	$t8,0x4($s3)
/*  f130aa8:	8e75000c */ 	lw	$s5,0xc($s3)
/*  f130aac:	1b000151 */ 	blez	$t8,.L0f130ff4
/*  f130ab0:	0015c8c0 */ 	sll	$t9,$s5,0x3
.L0f130ab4:
/*  f130ab4:	0335c823 */ 	subu	$t9,$t9,$s5
/*  f130ab8:	3c0e800a */ 	lui	$t6,%hi(g_Sparks)
/*  f130abc:	25ce34d0 */ 	addiu	$t6,$t6,%lo(g_Sparks)
/*  f130ac0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f130ac4:	032e8821 */ 	addu	$s1,$t9,$t6
/*  f130ac8:	8e2f0018 */ 	lw	$t7,0x18($s1)
/*  f130acc:	51e00140 */ 	beqzl	$t7,.L0f130fd0
/*  f130ad0:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f130ad4:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f130ad8:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f130adc:	00408025 */ 	or	$s0,$v0,$zero
/*  f130ae0:	00002025 */ 	or	$a0,$zero,$zero
/*  f130ae4:	00401825 */ 	or	$v1,$v0,$zero
.L0f130ae8:
/*  f130ae8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f130aec:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f130af0:	a460fffc */ 	sh	$zero,-0x4($v1)
/*  f130af4:	1494fffc */ 	bne	$a0,$s4,.L0f130ae8
/*  f130af8:	a460fffe */ 	sh	$zero,-0x2($v1)
/*  f130afc:	c62e000c */ 	lwc1	$f14,0xc($s1)
/*  f130b00:	c6220010 */ 	lwc1	$f2,0x10($s1)
/*  f130b04:	c6200014 */ 	lwc1	$f0,0x14($s1)
/*  f130b08:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f130b0c:	00000000 */ 	nop
/*  f130b10:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f130b14:	46064480 */ 	add.s	$f18,$f8,$f6
/*  f130b18:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f130b1c:	0c012974 */ 	jal	sqrtf
/*  f130b20:	46122300 */ 	add.s	$f12,$f4,$f18
/*  f130b24:	8e680008 */ 	lw	$t0,0x8($s3)
/*  f130b28:	96490008 */ 	lhu	$t1,0x8($s2)
/*  f130b2c:	964b0004 */ 	lhu	$t3,0x4($s2)
/*  f130b30:	c6240000 */ 	lwc1	$f4,0x0($s1)
/*  f130b34:	01090019 */ 	multu	$t0,$t1
/*  f130b38:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f130b3c:	4600248d */ 	trunc.w.s	$f18,$f4
/*  f130b40:	24010001 */ 	addiu	$at,$zero,0x1
/*  f130b44:	02002025 */ 	or	$a0,$s0,$zero
/*  f130b48:	44189000 */ 	mfc1	$t8,$f18
/*  f130b4c:	00000000 */ 	nop
/*  f130b50:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f130b54:	00005012 */ 	mflo	$t2
/*  f130b58:	016a6021 */ 	addu	$t4,$t3,$t2
/*  f130b5c:	448c5000 */ 	mtc1	$t4,$f10
/*  f130b60:	240c0080 */ 	addiu	$t4,$zero,0x80
/*  f130b64:	2418ffe0 */ 	addiu	$t8,$zero,-32
/*  f130b68:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f130b6c:	c62a0004 */ 	lwc1	$f10,0x4($s1)
/*  f130b70:	46164180 */ 	add.s	$f6,$f8,$f22
/*  f130b74:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f130b78:	46003083 */ 	div.s	$f2,$f6,$f0
/*  f130b7c:	440e4000 */ 	mfc1	$t6,$f8
/*  f130b80:	00000000 */ 	nop
/*  f130b84:	a60e0002 */ 	sh	$t6,0x2($s0)
/*  f130b88:	c6260008 */ 	lwc1	$f6,0x8($s1)
/*  f130b8c:	a2090007 */ 	sb	$t1,0x7($s0)
/*  f130b90:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130b94:	44082000 */ 	mfc1	$t0,$f4
/*  f130b98:	00000000 */ 	nop
/*  f130b9c:	a6080004 */ 	sh	$t0,0x4($s0)
/*  f130ba0:	c632000c */ 	lwc1	$f18,0xc($s1)
/*  f130ba4:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f130ba8:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130bac:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130bb0:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130bb4:	440a2000 */ 	mfc1	$t2,$f4
/*  f130bb8:	00000000 */ 	nop
/*  f130bbc:	a60a000c */ 	sh	$t2,0xc($s0)
/*  f130bc0:	c6320010 */ 	lwc1	$f18,0x10($s1)
/*  f130bc4:	c6280004 */ 	lwc1	$f8,0x4($s1)
/*  f130bc8:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130bcc:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130bd0:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130bd4:	440d2000 */ 	mfc1	$t5,$f4
/*  f130bd8:	00000000 */ 	nop
/*  f130bdc:	a60d000e */ 	sh	$t5,0xe($s0)
/*  f130be0:	c6320014 */ 	lwc1	$f18,0x14($s1)
/*  f130be4:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f130be8:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f130bec:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130bf0:	240dff00 */ 	addiu	$t5,$zero,-256
/*  f130bf4:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130bf8:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130bfc:	44192000 */ 	mfc1	$t9,$f4
/*  f130c00:	00000000 */ 	nop
/*  f130c04:	a6190010 */ 	sh	$t9,0x10($s0)
/*  f130c08:	c632000c */ 	lwc1	$f18,0xc($s1)
/*  f130c0c:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f130c10:	24190120 */ 	addiu	$t9,$zero,0x120
/*  f130c14:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130c18:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130c1c:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130c20:	440f2000 */ 	mfc1	$t7,$f4
/*  f130c24:	00000000 */ 	nop
/*  f130c28:	a60f0018 */ 	sh	$t7,0x18($s0)
/*  f130c2c:	c6320010 */ 	lwc1	$f18,0x10($s1)
/*  f130c30:	c6280004 */ 	lwc1	$f8,0x4($s1)
/*  f130c34:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130c38:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130c3c:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130c40:	44092000 */ 	mfc1	$t1,$f4
/*  f130c44:	00000000 */ 	nop
/*  f130c48:	a609001a */ 	sh	$t1,0x1a($s0)
/*  f130c4c:	c6320014 */ 	lwc1	$f18,0x14($s1)
/*  f130c50:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f130c54:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f130c58:	46029282 */ 	mul.s	$f10,$f18,$f2
/*  f130c5c:	a60c0008 */ 	sh	$t4,0x8($s0)
/*  f130c60:	a60d000a */ 	sh	$t5,0xa($s0)
/*  f130c64:	a6180014 */ 	sh	$t8,0x14($s0)
/*  f130c68:	a61e0016 */ 	sh	$s8,0x16($s0)
/*  f130c6c:	a6190020 */ 	sh	$t9,0x20($s0)
/*  f130c70:	a61e0022 */ 	sh	$s8,0x22($s0)
/*  f130c74:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f130c78:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f130c7c:	440a2000 */ 	mfc1	$t2,$f4
/*  f130c80:	12e00007 */ 	beqz	$s7,.L0f130ca0
/*  f130c84:	a60a001c */ 	sh	$t2,0x1c($s0)
/*  f130c88:	12e10044 */ 	beq	$s7,$at,.L0f130d9c
/*  f130c8c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f130c90:	52e10082 */ 	beql	$s7,$at,.L0f130e9c
/*  f130c94:	c62e000c */ 	lwc1	$f14,0xc($s1)
/*  f130c98:	100000be */ 	b	.L0f130f94
/*  f130c9c:	8fb10170 */ 	lw	$s1,0x170($sp)
.L0f130ca0:
/*  f130ca0:	c6200014 */ 	lwc1	$f0,0x14($s1)
/*  f130ca4:	4600b48d */ 	trunc.w.s	$f18,$f22
/*  f130ca8:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f130cac:	44029000 */ 	mfc1	$v0,$f18
/*  f130cb0:	45020004 */ 	bc1fl	.L0f130cc4
/*  f130cb4:	46000407 */ 	neg.s	$f16,$f0
/*  f130cb8:	10000002 */ 	b	.L0f130cc4
/*  f130cbc:	46000406 */ 	mov.s	$f16,$f0
/*  f130cc0:	46000407 */ 	neg.s	$f16,$f0
.L0f130cc4:
/*  f130cc4:	c6220010 */ 	lwc1	$f2,0x10($s1)
/*  f130cc8:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f130ccc:	00000000 */ 	nop
/*  f130cd0:	45020004 */ 	bc1fl	.L0f130ce4
/*  f130cd4:	46001307 */ 	neg.s	$f12,$f2
/*  f130cd8:	10000002 */ 	b	.L0f130ce4
/*  f130cdc:	46001306 */ 	mov.s	$f12,$f2
/*  f130ce0:	46001307 */ 	neg.s	$f12,$f2
.L0f130ce4:
/*  f130ce4:	4610603c */ 	c.lt.s	$f12,$f16
/*  f130ce8:	00000000 */ 	nop
/*  f130cec:	45020017 */ 	bc1fl	.L0f130d4c
/*  f130cf0:	8e6e0008 */ 	lw	$t6,0x8($s3)
/*  f130cf4:	8e6b0008 */ 	lw	$t3,0x8($s3)
/*  f130cf8:	964a000a */ 	lhu	$t2,0xa($s2)
/*  f130cfc:	860f000e */ 	lh	$t7,0xe($s0)
/*  f130d00:	96480006 */ 	lhu	$t0,0x6($s2)
/*  f130d04:	016a0019 */ 	multu	$t3,$t2
/*  f130d08:	8619001a */ 	lh	$t9,0x1a($s0)
/*  f130d0c:	01e84823 */ 	subu	$t1,$t7,$t0
/*  f130d10:	00006012 */ 	mflo	$t4
/*  f130d14:	012c6823 */ 	subu	$t5,$t1,$t4
/*  f130d18:	01a2c023 */ 	subu	$t8,$t5,$v0
/*  f130d1c:	a618000e */ 	sh	$t8,0xe($s0)
/*  f130d20:	964b000a */ 	lhu	$t3,0xa($s2)
/*  f130d24:	8e680008 */ 	lw	$t0,0x8($s3)
/*  f130d28:	964e0006 */ 	lhu	$t6,0x6($s2)
/*  f130d2c:	010b0019 */ 	multu	$t0,$t3
/*  f130d30:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f130d34:	00005012 */ 	mflo	$t2
/*  f130d38:	01ea4821 */ 	addu	$t1,$t7,$t2
/*  f130d3c:	01226021 */ 	addu	$t4,$t1,$v0
/*  f130d40:	10000093 */ 	b	.L0f130f90
/*  f130d44:	a60c001a */ 	sh	$t4,0x1a($s0)
/*  f130d48:	8e6e0008 */ 	lw	$t6,0x8($s3)
.L0f130d4c:
/*  f130d4c:	9648000a */ 	lhu	$t0,0xa($s2)
/*  f130d50:	860d0010 */ 	lh	$t5,0x10($s0)
/*  f130d54:	96580006 */ 	lhu	$t8,0x6($s2)
/*  f130d58:	01c80019 */ 	multu	$t6,$t0
/*  f130d5c:	8609001c */ 	lh	$t1,0x1c($s0)
/*  f130d60:	01b8c823 */ 	subu	$t9,$t5,$t8
/*  f130d64:	00005812 */ 	mflo	$t3
/*  f130d68:	032b7823 */ 	subu	$t7,$t9,$t3
/*  f130d6c:	01e25023 */ 	subu	$t2,$t7,$v0
/*  f130d70:	a60a0010 */ 	sh	$t2,0x10($s0)
/*  f130d74:	964e000a */ 	lhu	$t6,0xa($s2)
/*  f130d78:	8e780008 */ 	lw	$t8,0x8($s3)
/*  f130d7c:	964c0006 */ 	lhu	$t4,0x6($s2)
/*  f130d80:	030e0019 */ 	multu	$t8,$t6
/*  f130d84:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f130d88:	00004012 */ 	mflo	$t0
/*  f130d8c:	01a8c821 */ 	addu	$t9,$t5,$t0
/*  f130d90:	03225821 */ 	addu	$t3,$t9,$v0
/*  f130d94:	1000007e */ 	b	.L0f130f90
/*  f130d98:	a60b001c */ 	sh	$t3,0x1c($s0)
.L0f130d9c:
/*  f130d9c:	c62e000c */ 	lwc1	$f14,0xc($s1)
/*  f130da0:	4600b28d */ 	trunc.w.s	$f10,$f22
/*  f130da4:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f130da8:	44025000 */ 	mfc1	$v0,$f10
/*  f130dac:	45020004 */ 	bc1fl	.L0f130dc0
/*  f130db0:	46007407 */ 	neg.s	$f16,$f14
/*  f130db4:	10000002 */ 	b	.L0f130dc0
/*  f130db8:	46007406 */ 	mov.s	$f16,$f14
/*  f130dbc:	46007407 */ 	neg.s	$f16,$f14
.L0f130dc0:
/*  f130dc0:	c6200014 */ 	lwc1	$f0,0x14($s1)
/*  f130dc4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f130dc8:	00000000 */ 	nop
/*  f130dcc:	45020004 */ 	bc1fl	.L0f130de0
/*  f130dd0:	46000307 */ 	neg.s	$f12,$f0
/*  f130dd4:	10000002 */ 	b	.L0f130de0
/*  f130dd8:	46000306 */ 	mov.s	$f12,$f0
/*  f130ddc:	46000307 */ 	neg.s	$f12,$f0
.L0f130de0:
/*  f130de0:	4610603c */ 	c.lt.s	$f12,$f16
/*  f130de4:	00000000 */ 	nop
/*  f130de8:	45020017 */ 	bc1fl	.L0f130e48
/*  f130dec:	8e6f0008 */ 	lw	$t7,0x8($s3)
/*  f130df0:	8e780008 */ 	lw	$t8,0x8($s3)
/*  f130df4:	964e000a */ 	lhu	$t6,0xa($s2)
/*  f130df8:	860a0010 */ 	lh	$t2,0x10($s0)
/*  f130dfc:	96490006 */ 	lhu	$t1,0x6($s2)
/*  f130e00:	030e0019 */ 	multu	$t8,$t6
/*  f130e04:	860b001c */ 	lh	$t3,0x1c($s0)
/*  f130e08:	01496023 */ 	subu	$t4,$t2,$t1
/*  f130e0c:	00006812 */ 	mflo	$t5
/*  f130e10:	018d4023 */ 	subu	$t0,$t4,$t5
/*  f130e14:	0102c823 */ 	subu	$t9,$t0,$v0
/*  f130e18:	a6190010 */ 	sh	$t9,0x10($s0)
/*  f130e1c:	9658000a */ 	lhu	$t8,0xa($s2)
/*  f130e20:	8e690008 */ 	lw	$t1,0x8($s3)
/*  f130e24:	964f0006 */ 	lhu	$t7,0x6($s2)
/*  f130e28:	01380019 */ 	multu	$t1,$t8
/*  f130e2c:	016f5021 */ 	addu	$t2,$t3,$t7
/*  f130e30:	00007012 */ 	mflo	$t6
/*  f130e34:	014e6021 */ 	addu	$t4,$t2,$t6
/*  f130e38:	01826821 */ 	addu	$t5,$t4,$v0
/*  f130e3c:	10000054 */ 	b	.L0f130f90
/*  f130e40:	a60d001c */ 	sh	$t5,0x1c($s0)
/*  f130e44:	8e6f0008 */ 	lw	$t7,0x8($s3)
.L0f130e48:
/*  f130e48:	9649000a */ 	lhu	$t1,0xa($s2)
/*  f130e4c:	8608000c */ 	lh	$t0,0xc($s0)
/*  f130e50:	96590006 */ 	lhu	$t9,0x6($s2)
/*  f130e54:	01e90019 */ 	multu	$t7,$t1
/*  f130e58:	860c0018 */ 	lh	$t4,0x18($s0)
/*  f130e5c:	01195823 */ 	subu	$t3,$t0,$t9
/*  f130e60:	0000c012 */ 	mflo	$t8
/*  f130e64:	01785023 */ 	subu	$t2,$t3,$t8
/*  f130e68:	01427023 */ 	subu	$t6,$t2,$v0
/*  f130e6c:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f130e70:	964f000a */ 	lhu	$t7,0xa($s2)
/*  f130e74:	8e790008 */ 	lw	$t9,0x8($s3)
/*  f130e78:	964d0006 */ 	lhu	$t5,0x6($s2)
/*  f130e7c:	032f0019 */ 	multu	$t9,$t7
/*  f130e80:	018d4021 */ 	addu	$t0,$t4,$t5
/*  f130e84:	00004812 */ 	mflo	$t1
/*  f130e88:	01095821 */ 	addu	$t3,$t0,$t1
/*  f130e8c:	0162c021 */ 	addu	$t8,$t3,$v0
/*  f130e90:	1000003f */ 	b	.L0f130f90
/*  f130e94:	a6180018 */ 	sh	$t8,0x18($s0)
/*  f130e98:	c62e000c */ 	lwc1	$f14,0xc($s1)
.L0f130e9c:
/*  f130e9c:	4600b20d */ 	trunc.w.s	$f8,$f22
/*  f130ea0:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f130ea4:	44024000 */ 	mfc1	$v0,$f8
/*  f130ea8:	45020004 */ 	bc1fl	.L0f130ebc
/*  f130eac:	46007407 */ 	neg.s	$f16,$f14
/*  f130eb0:	10000002 */ 	b	.L0f130ebc
/*  f130eb4:	46007406 */ 	mov.s	$f16,$f14
/*  f130eb8:	46007407 */ 	neg.s	$f16,$f14
.L0f130ebc:
/*  f130ebc:	c6220010 */ 	lwc1	$f2,0x10($s1)
/*  f130ec0:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f130ec4:	00000000 */ 	nop
/*  f130ec8:	45020004 */ 	bc1fl	.L0f130edc
/*  f130ecc:	46001307 */ 	neg.s	$f12,$f2
/*  f130ed0:	10000002 */ 	b	.L0f130edc
/*  f130ed4:	46001306 */ 	mov.s	$f12,$f2
/*  f130ed8:	46001307 */ 	neg.s	$f12,$f2
.L0f130edc:
/*  f130edc:	4610603c */ 	c.lt.s	$f12,$f16
/*  f130ee0:	00000000 */ 	nop
/*  f130ee4:	45020017 */ 	bc1fl	.L0f130f44
/*  f130ee8:	8e6a0008 */ 	lw	$t2,0x8($s3)
/*  f130eec:	8e790008 */ 	lw	$t9,0x8($s3)
/*  f130ef0:	964f000a */ 	lhu	$t7,0xa($s2)
/*  f130ef4:	860e000e */ 	lh	$t6,0xe($s0)
/*  f130ef8:	964c0006 */ 	lhu	$t4,0x6($s2)
/*  f130efc:	032f0019 */ 	multu	$t9,$t7
/*  f130f00:	8618001a */ 	lh	$t8,0x1a($s0)
/*  f130f04:	01cc6823 */ 	subu	$t5,$t6,$t4
/*  f130f08:	00004012 */ 	mflo	$t0
/*  f130f0c:	01a84823 */ 	subu	$t1,$t5,$t0
/*  f130f10:	01225823 */ 	subu	$t3,$t1,$v0
/*  f130f14:	a60b000e */ 	sh	$t3,0xe($s0)
/*  f130f18:	9659000a */ 	lhu	$t9,0xa($s2)
/*  f130f1c:	8e6c0008 */ 	lw	$t4,0x8($s3)
/*  f130f20:	964a0006 */ 	lhu	$t2,0x6($s2)
/*  f130f24:	01990019 */ 	multu	$t4,$t9
/*  f130f28:	030a7021 */ 	addu	$t6,$t8,$t2
/*  f130f2c:	00007812 */ 	mflo	$t7
/*  f130f30:	01cf6821 */ 	addu	$t5,$t6,$t7
/*  f130f34:	01a24021 */ 	addu	$t0,$t5,$v0
/*  f130f38:	10000015 */ 	b	.L0f130f90
/*  f130f3c:	a608001a */ 	sh	$t0,0x1a($s0)
/*  f130f40:	8e6a0008 */ 	lw	$t2,0x8($s3)
.L0f130f44:
/*  f130f44:	964c000a */ 	lhu	$t4,0xa($s2)
/*  f130f48:	8609000c */ 	lh	$t1,0xc($s0)
/*  f130f4c:	964b0006 */ 	lhu	$t3,0x6($s2)
/*  f130f50:	014c0019 */ 	multu	$t2,$t4
/*  f130f54:	860d0018 */ 	lh	$t5,0x18($s0)
/*  f130f58:	012bc023 */ 	subu	$t8,$t1,$t3
/*  f130f5c:	0000c812 */ 	mflo	$t9
/*  f130f60:	03197023 */ 	subu	$t6,$t8,$t9
/*  f130f64:	01c27823 */ 	subu	$t7,$t6,$v0
/*  f130f68:	a60f000c */ 	sh	$t7,0xc($s0)
/*  f130f6c:	964a000a */ 	lhu	$t2,0xa($s2)
/*  f130f70:	8e6b0008 */ 	lw	$t3,0x8($s3)
/*  f130f74:	96480006 */ 	lhu	$t0,0x6($s2)
/*  f130f78:	016a0019 */ 	multu	$t3,$t2
/*  f130f7c:	01a84821 */ 	addu	$t1,$t5,$t0
/*  f130f80:	00006012 */ 	mflo	$t4
/*  f130f84:	012cc021 */ 	addu	$t8,$t1,$t4
/*  f130f88:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f130f8c:	a6190018 */ 	sh	$t9,0x18($s0)
.L0f130f90:
/*  f130f90:	8fb10170 */ 	lw	$s1,0x170($sp)
.L0f130f94:
/*  f130f94:	3c0d0420 */ 	lui	$t5,0x420
/*  f130f98:	35ad0024 */ 	ori	$t5,$t5,0x24
/*  f130f9c:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f130fa0:	afaf0170 */ 	sw	$t7,0x170($sp)
/*  f130fa4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f130fa8:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f130fac:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f130fb0:	8fa80170 */ 	lw	$t0,0x170($sp)
/*  f130fb4:	3c0abf00 */ 	lui	$t2,0xbf00
/*  f130fb8:	24090a14 */ 	addiu	$t1,$zero,0xa14
/*  f130fbc:	250b0008 */ 	addiu	$t3,$t0,0x8
/*  f130fc0:	afab0170 */ 	sw	$t3,0x170($sp)
/*  f130fc4:	ad090004 */ 	sw	$t1,0x4($t0)
/*  f130fc8:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f130fcc:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f130fd0:
/*  f130fd0:	24010064 */ 	addiu	$at,$zero,0x64
/*  f130fd4:	02a1001a */ 	div	$zero,$s5,$at
/*  f130fd8:	8fb8016c */ 	lw	$t8,0x16c($sp)
/*  f130fdc:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f130fe0:	0000a810 */ 	mfhi	$s5
/*  f130fe4:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f130fe8:	02d9082a */ 	slt	$at,$s6,$t9
/*  f130fec:	5420feb1 */ 	bnezl	$at,.L0f130ab4
/*  f130ff0:	0015c8c0 */ 	sll	$t9,$s5,0x3
.L0f130ff4:
/*  f130ff4:	3c0e800a */ 	lui	$t6,%hi(var800a4130)
/*  f130ff8:	25ce4130 */ 	addiu	$t6,$t6,%lo(var800a4130)
/*  f130ffc:	26730024 */ 	addiu	$s3,$s3,0x24
/*  f131000:	566efcb4 */ 	bnel	$s3,$t6,.L0f1302d4
/*  f131004:	8e6c0008 */ 	lw	$t4,0x8($s3)
/*  f131008:	e7ba013c */ 	swc1	$f26,0x13c($sp)
/*  f13100c:	e7b60120 */ 	swc1	$f22,0x120($sp)
.L0f131010:
/*  f131010:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f131014:	8fa20170 */ 	lw	$v0,0x170($sp)
/*  f131018:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f13101c:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f131020:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f131024:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f131028:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f13102c:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f131030:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f131034:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f131038:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f13103c:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f131040:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f131044:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f131048:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f13104c:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f131050:	03e00008 */ 	jr	$ra
/*  f131054:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
