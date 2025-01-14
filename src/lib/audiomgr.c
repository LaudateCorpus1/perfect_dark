#include <ultra64.h>
#include "lib/init.h"
#include "lib/sched.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_09660.h"
#include "lib/lib_2fba0.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_30ce0.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

u32 var80091560;
u32 var80091564;
u64 var80091568;
u64 var80091570;
u64 var80091578;
u64 var80091580;
u64 var80091588;
u64 var80091590;
u32 var80091598;
u32 var8009159c;
u32 var800915a0;
u32 var800915a4;
u32 var800915a8;
u32 var800915ac;
u32 var800915b0;
u32 var800915b4;
u32 var800915b8;
u32 var800915bc;
u32 var800915c0;
u32 var800915c4;
AMAudioMgr g_AudioManager;
OSScClient var800918d0;
u32 var800918d8;
u32 var800918dc;
u32 var800918e0;
u32 var800918e4;
s32 var800918e8;
u32 var800918ec;
void *g_AudioSp;
OSScTask *g_AmgrCurrentCmdList;

u32 var8005cf90 = 0x00000000;
u8 var8005cf94 = 1;
u32 var8005cf98 = 0x00000001;
u32 var8005cf9c = 0x000014a0;
u32 var8005cfa0 = 0x00000000;
u32 var8005cfa4 = 0x00001358;
u32 var8005cfa8 = 0x00004d0c;
u32 var8005cfac = 0x00000000;
u32 var8005cfb0 = 0x000053ff;
u32 var8005cfb4 = 0x00000000;
u32 var8005cfb8 = 0x00000000;
u32 var8005cfbc = 0x00000000;
u32 var8005cfc0 = 0x00000001;
u32 var8005cfc4 = 0x000001b8;
u32 var8005cfc8 = 0x00000000;
u32 var8005cfcc = 0x00000068;
u32 var8005cfd0 = 0x00004000;
u32 var8005cfd4 = 0x00000000;
u32 var8005cfd8 = 0x00007fff;
u32 var8005cfdc = 0x00001db0;
u32 var8005cfe0 = 0x00001b58;
u32 var8005cfe4 = 0x00000000;
u32 var8005cfe8 = 0x00000001;
u32 var8005cfec = 0x000001b8;
u32 var8005cff0 = 0x00000000;
u32 var8005cff4 = 0x00000068;
u32 var8005cff8 = 0x00000000;
u32 var8005cffc = 0x00005fff;
u32 var8005d000 = 0x00007fff;
u32 var8005d004 = 0x0000017c;
u32 var8005d008 = 0x000001f4;
u32 var8005d00c = 0x00000000;
u32 var8005d010 = 0x00000006;
u32 var8005d014 = 0x00001868;
u32 var8005d018 = 0x00000000;
u32 var8005d01c = 0x00000160;
u32 var8005d020 = 0x00002666;
u32 var8005d024 = 0xffffd99a;
u32 var8005d028 = 0x00000000;
u32 var8005d02c = 0x00000000;
u32 var8005d030 = 0x00000000;
u32 var8005d034 = 0x00000000;
u32 var8005d038 = 0x00000188;
u32 var8005d03c = 0x00000640;
u32 var8005d040 = 0x0000235e;
u32 var8005d044 = 0xffffd99a;
u32 var8005d048 = 0x0000750c;
u32 var8005d04c = 0x00000000;
u32 var8005d050 = 0x00000000;
u32 var8005d054 = 0x00000bca;
u32 var8005d058 = 0x00000318;
u32 var8005d05c = 0x000009f8;
u32 var8005d060 = 0x00004000;
u32 var8005d064 = 0xffffc000;
u32 var8005d068 = 0x00006d78;
u32 var8005d06c = 0x00000000;
u32 var8005d070 = 0x00000000;
u32 var8005d074 = 0x00001286;
u32 var8005d078 = 0x00000c78;
u32 var8005d07c = 0x000015d8;
u32 var8005d080 = 0x0000521a;
u32 var8005d084 = 0xffffc000;
u32 var8005d088 = 0x0000724f;
u32 var8005d08c = 0x00000000;
u32 var8005d090 = 0x00000000;
u32 var8005d094 = 0x00001650;
u32 var8005d098 = 0x00000d28;
u32 var8005d09c = 0x000012c0;
u32 var8005d0a0 = 0x00002143;
u32 var8005d0a4 = 0xffffe000;
u32 var8005d0a8 = 0x00005de4;
u32 var8005d0ac = 0x00000000;
u32 var8005d0b0 = 0x00000000;
u32 var8005d0b4 = 0x00002286;
u32 var8005d0b8 = 0x00000000;
u32 var8005d0bc = 0x00001720;
u32 var8005d0c0 = 0x000032c8;
u32 var8005d0c4 = 0xffffcd38;
u32 var8005d0c8 = 0x00000000;
u32 var8005d0cc = 0x00000000;
u32 var8005d0d0 = 0x00000000;
u32 var8005d0d4 = 0x00004500;
u32 var8005d0d8 = 0x00000002;
u32 var8005d0dc = 0x000008b0;
u32 var8005d0e0 = 0x00000600;
u32 var8005d0e4 = 0x00000760;
u32 var8005d0e8 = 0x00007142;
u32 var8005d0ec = 0x00000000;
u32 var8005d0f0 = 0x00005bff;
u32 var8005d0f4 = 0x00000000;
u32 var8005d0f8 = 0x00000000;
u32 var8005d0fc = 0x00007bc9;
u32 var8005d100 = 0x00000000;
u32 var8005d104 = 0x00000528;
u32 var8005d108 = 0x00005f27;
u32 var8005d10c = 0xffffb288;
u32 var8005d110 = 0x00007ef1;
u32 var8005d114 = 0x00000000;
u32 var8005d118 = 0x00000001;
u32 var8005d11c = 0x000066bb;
u32 var8005d120 = 0x00000003;
u32 var8005d124 = 0x00000b40;
u32 var8005d128 = 0x00000000;
u32 var8005d12c = 0x00000160;
u32 var8005d130 = 0x00002666;
u32 var8005d134 = 0xffffd99a;
u32 var8005d138 = 0x00000000;
u32 var8005d13c = 0x00000000;
u32 var8005d140 = 0x00000000;
u32 var8005d144 = 0x00000000;
u32 var8005d148 = 0x00000188;
u32 var8005d14c = 0x00000640;
u32 var8005d150 = 0x0000235e;
u32 var8005d154 = 0xffffd99a;
u32 var8005d158 = 0x000016f2;
u32 var8005d15c = 0x00000000;
u32 var8005d160 = 0x00000000;
u32 var8005d164 = 0x00000bca;
u32 var8005d168 = 0x00000318;
u32 var8005d16c = 0x000009f8;
u32 var8005d170 = 0x00004000;
u32 var8005d174 = 0xffffc000;
u32 var8005d178 = 0x0000186b;
u32 var8005d17c = 0x00000000;
u32 var8005d180 = 0x00000000;
u32 var8005d184 = 0x00001286;
u32 var8005d188 = 0x00000003;
u32 var8005d18c = 0x00000b40;
u32 var8005d190 = 0x00000000;
u32 var8005d194 = 0x00000160;
u32 var8005d198 = 0x00002666;
u32 var8005d19c = 0xffffd99a;
u32 var8005d1a0 = 0x00000000;
u32 var8005d1a4 = 0x00000000;
u32 var8005d1a8 = 0x00000000;
u32 var8005d1ac = 0x00000000;
u32 var8005d1b0 = 0x00000188;
u32 var8005d1b4 = 0x00000640;
u32 var8005d1b8 = 0x0000235e;
u32 var8005d1bc = 0xffffd99a;
u32 var8005d1c0 = 0x000016f2;
u32 var8005d1c4 = 0x00000000;
u32 var8005d1c8 = 0x00000000;
u32 var8005d1cc = 0x00000bca;
u32 var8005d1d0 = 0x00000318;
u32 var8005d1d4 = 0x000009f8;
u32 var8005d1d8 = 0x00004000;
u32 var8005d1dc = 0xffffc000;
u32 var8005d1e0 = 0x0000186b;
u32 var8005d1e4 = 0x00000000;
u32 var8005d1e8 = 0x00000000;
u32 var8005d1ec = 0x00001286;
u32 var8005d1f0 = 0x00000003;
u32 var8005d1f4 = 0x00000898;
u32 var8005d1f8 = 0x00000000;
u32 var8005d1fc = 0x000004a0;
u32 var8005d200 = 0x00002666;
u32 var8005d204 = 0xffffd99a;
u32 var8005d208 = 0x00000000;
u32 var8005d20c = 0x00000000;
u32 var8005d210 = 0x00000000;
u32 var8005d214 = 0x00000000;
u32 var8005d218 = 0x000001a0;
u32 var8005d21c = 0x00000340;
u32 var8005d220 = 0x00000ccc;
u32 var8005d224 = 0xfffff334;
u32 var8005d228 = 0x00003fff;
u32 var8005d22c = 0x00000000;
u32 var8005d230 = 0x00000000;
u32 var8005d234 = 0x00000000;
u32 var8005d238 = 0x00000000;
u32 var8005d23c = 0x00000528;
u32 var8005d240 = 0x00001388;
u32 var8005d244 = 0x00000000;
u32 var8005d248 = 0x00000000;
u32 var8005d24c = 0x00000000;
u32 var8005d250 = 0x00000000;
u32 var8005d254 = 0x00005000;
u32 var8005d258 = 0x00000004;
u32 var8005d25c = 0x00000898;
u32 var8005d260 = 0x00000000;
u32 var8005d264 = 0x000005a8;
u32 var8005d268 = 0x00002666;
u32 var8005d26c = 0xffffd99a;
u32 var8005d270 = 0x00000000;
u32 var8005d274 = 0x00000000;
u32 var8005d278 = 0x00000000;
u32 var8005d27c = 0x00000000;
u32 var8005d280 = 0x000001e0;
u32 var8005d284 = 0x000004a0;
u32 var8005d288 = 0x00000ccc;
u32 var8005d28c = 0xfffff334;
u32 var8005d290 = 0x00003fff;
u32 var8005d294 = 0x00000000;
u32 var8005d298 = 0x00000000;
u32 var8005d29c = 0x00000000;
u32 var8005d2a0 = 0x000005a8;
u32 var8005d2a4 = 0x000007d0;
u32 var8005d2a8 = 0x00000ccc;
u32 var8005d2ac = 0xfffff334;
u32 var8005d2b0 = 0x00003fff;
u32 var8005d2b4 = 0x00000000;
u32 var8005d2b8 = 0x00000000;
u32 var8005d2bc = 0x00000000;
u32 var8005d2c0 = 0x00000000;
u32 var8005d2c4 = 0x00000810;
u32 var8005d2c8 = 0x00001f40;
u32 var8005d2cc = 0x00000000;
u32 var8005d2d0 = 0x00000000;
u32 var8005d2d4 = 0x00000000;
u32 var8005d2d8 = 0x00000000;
u32 var8005d2dc = 0x00005000;
u32 var8005d2e0 = 0x00000001;
u32 var8005d2e4 = 0x00001130;
u32 var8005d2e8 = 0x00000000;
u32 var8005d2ec = 0x00000f60;
u32 var8005d2f0 = 0x00002ee0;
u32 var8005d2f4 = 0x00000000;
u32 var8005d2f8 = 0x00007fff;
u32 var8005d2fc = 0x00000000;
u32 var8005d300 = 0x00000000;
u32 var8005d304 = 0x00000000;
u32 var8005d308 = 0x00000004;
u32 var8005d30c = 0x00000e98;
u32 var8005d310 = 0x000000c0;
u32 var8005d314 = 0x00000188;
u32 var8005d318 = 0x00002666;
u32 var8005d31c = 0xffffd99a;
u32 var8005d320 = 0x00003484;
u32 var8005d324 = 0x00000000;
u32 var8005d328 = 0x00000000;
u32 var8005d32c = 0x00000000;
u32 var8005d330 = 0x000001b8;
u32 var8005d334 = 0x00000580;
u32 var8005d338 = 0x00004000;
u32 var8005d33c = 0xffffc000;
u32 var8005d340 = 0x000019eb;
u32 var8005d344 = 0x00000000;
u32 var8005d348 = 0x00000000;
u32 var8005d34c = 0x00000000;
u32 var8005d350 = 0x00000a50;
u32 var8005d354 = 0x00000b98;
u32 var8005d358 = 0x00002000;
u32 var8005d35c = 0xffffe000;
u32 var8005d360 = 0x00000000;
u32 var8005d364 = 0x00000000;
u32 var8005d368 = 0x00000000;
u32 var8005d36c = 0x00000000;
u32 var8005d370 = 0x00000000;
u32 var8005d374 = 0x00000cb8;
u32 var8005d378 = 0x00004650;
u32 var8005d37c = 0xffffb9b0;
u32 var8005d380 = 0x00000000;
u32 var8005d384 = 0x0000017c;
u32 var8005d388 = 0x0000000a;
u32 var8005d38c = 0x00000000;
u32 var8005d390 = 0x00000001;
u32 var8005d394 = 0x00000528;
u32 var8005d398 = 0x00000000;
u32 var8005d39c = 0x00000448;
u32 var8005d3a0 = 0x00003334;
u32 var8005d3a4 = 0x00000000;
u32 var8005d3a8 = 0x00007335;
u32 var8005d3ac = 0x00000000;
u32 var8005d3b0 = 0x00000000;
u32 var8005d3b4 = 0x00000000;
u32 var8005d3b8 = 0x00000008;
u32 var8005d3bc = 0x00001b80;
u32 var8005d3c0 = 0x00000000;
u32 var8005d3c4 = 0x000000c0;
u32 var8005d3c8 = 0x00002666;
u32 var8005d3cc = 0xffffd99a;
u32 var8005d3d0 = 0x00000000;
u32 var8005d3d4 = 0x00000000;
u32 var8005d3d8 = 0x00000000;
u32 var8005d3dc = 0x00000000;
u32 var8005d3e0 = 0x000000c0;
u32 var8005d3e4 = 0x00000188;
u32 var8005d3e8 = 0x00002666;
u32 var8005d3ec = 0xffffd99a;
u32 var8005d3f0 = 0x00002b84;
u32 var8005d3f4 = 0x00000000;
u32 var8005d3f8 = 0x00000000;
u32 var8005d3fc = 0x00000000;
u32 var8005d400 = 0x00000370;
u32 var8005d404 = 0x00000b00;
u32 var8005d408 = 0x00004000;
u32 var8005d40c = 0xffffc000;
u32 var8005d410 = 0x000011eb;
u32 var8005d414 = 0x00000000;
u32 var8005d418 = 0x00000000;
u32 var8005d41c = 0x00000000;
u32 var8005d420 = 0x00000420;
u32 var8005d424 = 0x00000840;
u32 var8005d428 = 0x00002000;
u32 var8005d42c = 0xffffe000;
u32 var8005d430 = 0x00000000;
u32 var8005d434 = 0x00000000;
u32 var8005d438 = 0x00000000;
u32 var8005d43c = 0x00000000;
u32 var8005d440 = 0x00000dc0;
u32 var8005d444 = 0x00001810;
u32 var8005d448 = 0x00004000;
u32 var8005d44c = 0xffffc000;
u32 var8005d450 = 0x000011eb;
u32 var8005d454 = 0x00000000;
u32 var8005d458 = 0x00000000;
u32 var8005d45c = 0x00000000;
u32 var8005d460 = 0x00000e70;
u32 var8005d464 = 0x000014a0;
u32 var8005d468 = 0x00002000;
u32 var8005d46c = 0xffffe000;
u32 var8005d470 = 0x00000000;
u32 var8005d474 = 0x00000000;
u32 var8005d478 = 0x00000000;
u32 var8005d47c = 0x00000000;
u32 var8005d480 = 0x000014a0;
u32 var8005d484 = 0x00001738;
u32 var8005d488 = 0x00002000;
u32 var8005d48c = 0xffffe000;
u32 var8005d490 = 0x00000000;
u32 var8005d494 = 0x00000000;
u32 var8005d498 = 0x00000000;
u32 var8005d49c = 0x00000000;
u32 var8005d4a0 = 0x00000000;
u32 var8005d4a4 = 0x00001970;
u32 var8005d4a8 = 0x000032c8;
u32 var8005d4ac = 0xffffcd38;
u32 var8005d4b0 = 0x00000000;
u32 var8005d4b4 = 0x0000017c;
u32 var8005d4b8 = 0x0000000a;
u32 var8005d4bc = 0x00000000;
u32 var8005d4c0 = 0x00000001;
u32 var8005d4c4 = 0x00000a50;
u32 var8005d4c8 = 0x00000000;
u32 var8005d4cc = 0x00000898;
u32 var8005d4d0 = 0x00003334;
u32 var8005d4d4 = 0x00000000;
u32 var8005d4d8 = 0x00007335;
u32 var8005d4dc = 0x00000000;
u32 var8005d4e0 = 0x00000000;
u32 var8005d4e4 = 0x00000000;
u32 var8005d4e8 = 0x00000001;
u32 var8005d4ec = 0x00000148;
u32 var8005d4f0 = 0x00000000;
u32 var8005d4f4 = 0x00000000;
u32 var8005d4f8 = 0x00000000;
u32 var8005d4fc = 0x00000000;
u32 var8005d500 = 0x00000000;
u32 var8005d504 = 0x00000000;
u32 var8005d508 = 0x00000000;
u32 var8005d50c = 0x00000000;
s8 g_AudioIsThreadRunning = false;

void amgrHandleDoneMsg(AudioInfo *info);

void amgrAllocateStack(void)
{
	g_AudioSp = allocateStack(THREAD_AUDIO, STACKSIZE_AUDIO);
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel amgrCreate
/*     8988:	27bdfa48 */ 	addiu	$sp,$sp,-1464
/*     898c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     8990:	afb0001c */ 	sw	$s0,0x1c($sp)
/*     8994:	afa405b8 */ 	sw	$a0,0x5b8($sp)
/*     8998:	00a08025 */ 	move	$s0,$a1
/*     899c:	afb30028 */ 	sw	$s3,0x28($sp)
/*     89a0:	afb20024 */ 	sw	$s2,0x24($sp)
/*     89a4:	afb10020 */ 	sw	$s1,0x20($sp)
/*     89a8:	0c01362c */ 	jal	osAiSetFrequency
/*     89ac:	24045604 */ 	li	$a0,0x5604
/*     89b0:	8fa505b8 */ 	lw	$a1,0x5b8($sp)
/*     89b4:	3c0e7001 */ 	lui	$t6,0x7001
/*     89b8:	25ce9754 */ 	addiu	$t6,$t6,-26796
/*     89bc:	aca20018 */ 	sw	$v0,0x18($a1)
/*     89c0:	acae0010 */ 	sw	$t6,0x10($a1)
/*     89c4:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*     89c8:	3c048009 */ 	lui	$a0,0x8009
/*     89cc:	44825000 */ 	mtc1	$v0,$f10
/*     89d0:	448f2000 */ 	mtc1	$t7,$f4
/*     89d4:	24841e30 */ 	addiu	$a0,$a0,0x1e30
/*     89d8:	05e10005 */ 	bgez	$t7,.PF000089f0
/*     89dc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*     89e0:	3c014f80 */ 	lui	$at,0x4f80
/*     89e4:	44814000 */ 	mtc1	$at,$f8
/*     89e8:	00000000 */ 	nop
/*     89ec:	46083180 */ 	add.s	$f6,$f6,$f8
.PF000089f0:
/*     89f0:	46805420 */ 	cvt.s.w	$f16,$f10
/*     89f4:	3c0141c8 */ 	lui	$at,0x41c8
/*     89f8:	44812000 */ 	mtc1	$at,$f4
/*     89fc:	240200b8 */ 	li	$v0,0xb8
/*     8a00:	46103482 */ 	mul.s	$f18,$f6,$f16
/*     8a04:	46049003 */ 	div.s	$f0,$f18,$f4
/*     8a08:	4600020d */ 	trunc.w.s	$f8,$f0
/*     8a0c:	44194000 */ 	mfc1	$t9,$f8
/*     8a10:	00000000 */ 	nop
/*     8a14:	03201825 */ 	move	$v1,$t9
/*     8a18:	44835000 */ 	mtc1	$v1,$f10
/*     8a1c:	ac990000 */ 	sw	$t9,0x0($a0)
/*     8a20:	07210005 */ 	bgez	$t9,.PF00008a38
/*     8a24:	468051a0 */ 	cvt.s.w	$f6,$f10
/*     8a28:	3c014f80 */ 	lui	$at,0x4f80
/*     8a2c:	44818000 */ 	mtc1	$at,$f16
/*     8a30:	00000000 */ 	nop
/*     8a34:	46103180 */ 	add.s	$f6,$f6,$f16
.PF00008a38:
/*     8a38:	4600303c */ 	c.lt.s	$f6,$f0
/*     8a3c:	00000000 */ 	nop
/*     8a40:	45000004 */ 	bc1f	.PF00008a54
/*     8a44:	00000000 */ 	nop
/*     8a48:	24690001 */ 	addiu	$t1,$v1,0x1
/*     8a4c:	ac890000 */ 	sw	$t1,0x0($a0)
/*     8a50:	01201825 */ 	move	$v1,$t1
.PF00008a54:
/*     8a54:	0062001b */ 	divu	$zero,$v1,$v0
/*     8a58:	00005012 */ 	mflo	$t2
/*     8a5c:	3c018009 */ 	lui	$at,0x8009
/*     8a60:	14400002 */ 	bnez	$v0,.PF00008a6c
/*     8a64:	00000000 */ 	nop
/*     8a68:	0007000d */ 	break	0x7
.PF00008a6c:
/*     8a6c:	01420019 */ 	multu	$t2,$v0
/*     8a70:	00005812 */ 	mflo	$t3
/*     8a74:	256c00b8 */ 	addiu	$t4,$t3,0xb8
/*     8a78:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*     8a7c:	258dff48 */ 	addiu	$t5,$t4,-184
/*     8a80:	ac2d1e2c */ 	sw	$t5,0x1e2c($at)
/*     8a84:	3c018009 */ 	lui	$at,0x8009
/*     8a88:	258e0050 */ 	addiu	$t6,$t4,0x50
/*     8a8c:	ac2e1e34 */ 	sw	$t6,0x1e34($at)
/*     8a90:	3c018006 */ 	lui	$at,0x8006
/*     8a94:	0c00255c */ 	jal	func00009660
/*     8a98:	a020cc34 */ 	sb	$zero,-0x33cc($at)
/*     8a9c:	3c048009 */ 	lui	$a0,0x8009
/*     8aa0:	3c058009 */ 	lui	$a1,0x8009
/*     8aa4:	24a51db0 */ 	addiu	$a1,$a1,0x1db0
/*     8aa8:	24841d98 */ 	addiu	$a0,$a0,0x1d98
/*     8aac:	0c011f10 */ 	jal	osCreateMesgQueue
/*     8ab0:	24060008 */ 	li	$a2,0x8
/*     8ab4:	3c048009 */ 	lui	$a0,0x8009
/*     8ab8:	3c058009 */ 	lui	$a1,0x8009
/*     8abc:	24a51d78 */ 	addiu	$a1,$a1,0x1d78
/*     8ac0:	24841d60 */ 	addiu	$a0,$a0,0x1d60
/*     8ac4:	0c011f10 */ 	jal	osCreateMesgQueue
/*     8ac8:	24060008 */ 	li	$a2,0x8
/*     8acc:	3c128009 */ 	lui	$s2,0x8009
/*     8ad0:	26521e3c */ 	addiu	$s2,$s2,0x1e3c
/*     8ad4:	240f07d0 */ 	li	$t7,0x7d0
/*     8ad8:	3c108009 */ 	lui	$s0,0x8009
/*     8adc:	3c138009 */ 	lui	$s3,0x8009
/*     8ae0:	3c118009 */ 	lui	$s1,0x8009
/*     8ae4:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*     8ae8:	26315740 */ 	addiu	$s1,$s1,0x5740
/*     8aec:	26731b20 */ 	addiu	$s3,$s3,0x1b20
/*     8af0:	26101b18 */ 	addiu	$s0,$s0,0x1b18
.PF00008af4:
/*     8af4:	8e580000 */ 	lw	$t8,0x0($s2)
/*     8af8:	00002025 */ 	move	$a0,$zero
/*     8afc:	00002825 */ 	move	$a1,$zero
/*     8b00:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*     8b04:	afb90010 */ 	sw	$t9,0x10($sp)
/*     8b08:	02203025 */ 	move	$a2,$s1
/*     8b0c:	0c00bd05 */ 	jal	alHeapDBAlloc
/*     8b10:	24070001 */ 	li	$a3,0x1
/*     8b14:	26100004 */ 	addiu	$s0,$s0,0x4
/*     8b18:	0213082b */ 	sltu	$at,$s0,$s3
/*     8b1c:	1420fff5 */ 	bnez	$at,.PF00008af4
/*     8b20:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*     8b24:	3c108009 */ 	lui	$s0,0x8009
/*     8b28:	3c128009 */ 	lui	$s2,0x8009
/*     8b2c:	26521b24 */ 	addiu	$s2,$s2,0x1b24
/*     8b30:	26101b18 */ 	addiu	$s0,$s0,0x1b18
.PF00008b34:
/*     8b34:	24090060 */ 	li	$t1,0x60
/*     8b38:	afa90010 */ 	sw	$t1,0x10($sp)
/*     8b3c:	00002025 */ 	move	$a0,$zero
/*     8b40:	00002825 */ 	move	$a1,$zero
/*     8b44:	02203025 */ 	move	$a2,$s1
/*     8b48:	0c00bd05 */ 	jal	alHeapDBAlloc
/*     8b4c:	24070001 */ 	li	$a3,0x1
/*     8b50:	ae020008 */ 	sw	$v0,0x8($s0)
/*     8b54:	a4400004 */ 	sh	$zero,0x4($v0)
/*     8b58:	240a0e68 */ 	li	$t2,0xe68
/*     8b5c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     8b60:	00002025 */ 	move	$a0,$zero
/*     8b64:	00002825 */ 	move	$a1,$zero
/*     8b68:	02203025 */ 	move	$a2,$s1
/*     8b6c:	0c00bd05 */ 	jal	alHeapDBAlloc
/*     8b70:	24070001 */ 	li	$a3,0x1
/*     8b74:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*     8b78:	26100004 */ 	addiu	$s0,$s0,0x4
/*     8b7c:	0212082b */ 	sltu	$at,$s0,$s2
/*     8b80:	1420ffec */ 	bnez	$at,.PF00008b34
/*     8b84:	ad620000 */ 	sw	$v0,0x0($t3)
/*     8b88:	3c0d8006 */ 	lui	$t5,0x8006
/*     8b8c:	3c088009 */ 	lui	$t0,0x8009
/*     8b90:	25adcc38 */ 	addiu	$t5,$t5,-13256
/*     8b94:	25081040 */ 	addiu	$t0,$t0,0x1040
/*     8b98:	27a201b8 */ 	addiu	$v0,$sp,0x1b8
/*     8b9c:	27a30088 */ 	addiu	$v1,$sp,0x88
/*     8ba0:	27a50190 */ 	addiu	$a1,$sp,0x190
/*     8ba4:	27a60060 */ 	addiu	$a2,$sp,0x60
/*     8ba8:	24070001 */ 	li	$a3,0x1
/*     8bac:	25af0024 */ 	addiu	$t7,$t5,0x24
/*     8bb0:	27ac0588 */ 	addiu	$t4,$sp,0x588
.PF00008bb4:
/*     8bb4:	8da10000 */ 	lw	$at,0x0($t5)
/*     8bb8:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8bbc:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8bc0:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8bc4:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8bc8:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8bcc:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8bd0:	15affff8 */ 	bne	$t5,$t7,.PF00008bb4
/*     8bd4:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     8bd8:	8da10000 */ 	lw	$at,0x0($t5)
/*     8bdc:	3c198006 */ 	lui	$t9,0x8006
/*     8be0:	2739cc60 */ 	addiu	$t9,$t9,-13216
/*     8be4:	272a0024 */ 	addiu	$t2,$t9,0x24
/*     8be8:	27b80560 */ 	addiu	$t8,$sp,0x560
/*     8bec:	ad810000 */ 	sw	$at,0x0($t4)
.PF00008bf0:
/*     8bf0:	8f210000 */ 	lw	$at,0x0($t9)
/*     8bf4:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8bf8:	2718000c */ 	addiu	$t8,$t8,0xc
/*     8bfc:	af01fff4 */ 	sw	$at,-0xc($t8)
/*     8c00:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*     8c04:	af01fff8 */ 	sw	$at,-0x8($t8)
/*     8c08:	8f21fffc */ 	lw	$at,-0x4($t9)
/*     8c0c:	172afff8 */ 	bne	$t9,$t2,.PF00008bf0
/*     8c10:	af01fffc */ 	sw	$at,-0x4($t8)
/*     8c14:	8f210000 */ 	lw	$at,0x0($t9)
/*     8c18:	3c0e8006 */ 	lui	$t6,0x8006
/*     8c1c:	25cecc88 */ 	addiu	$t6,$t6,-13176
/*     8c20:	25cd0024 */ 	addiu	$t5,$t6,0x24
/*     8c24:	27ab0538 */ 	addiu	$t3,$sp,0x538
/*     8c28:	af010000 */ 	sw	$at,0x0($t8)
.PF00008c2c:
/*     8c2c:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8c30:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8c34:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8c38:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8c3c:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*     8c40:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8c44:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*     8c48:	15cdfff8 */ 	bne	$t6,$t5,.PF00008c2c
/*     8c4c:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8c50:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8c54:	3c098006 */ 	lui	$t1,0x8006
/*     8c58:	2529ccb0 */ 	addiu	$t1,$t1,-13136
/*     8c5c:	253900c0 */ 	addiu	$t9,$t1,0xc0
/*     8c60:	27ac0470 */ 	addiu	$t4,$sp,0x470
/*     8c64:	ad610000 */ 	sw	$at,0x0($t3)
.PF00008c68:
/*     8c68:	8d210000 */ 	lw	$at,0x0($t1)
/*     8c6c:	2529000c */ 	addiu	$t1,$t1,0xc
/*     8c70:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8c74:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8c78:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*     8c7c:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8c80:	8d21fffc */ 	lw	$at,-0x4($t1)
/*     8c84:	1539fff8 */ 	bne	$t1,$t9,.PF00008c68
/*     8c88:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     8c8c:	8d210000 */ 	lw	$at,0x0($t1)
/*     8c90:	8d390004 */ 	lw	$t9,0x4($t1)
/*     8c94:	3c0f8006 */ 	lui	$t7,0x8006
/*     8c98:	25efcd78 */ 	addiu	$t7,$t7,-12936
/*     8c9c:	25ee0048 */ 	addiu	$t6,$t7,0x48
/*     8ca0:	27b80428 */ 	addiu	$t8,$sp,0x428
/*     8ca4:	ad810000 */ 	sw	$at,0x0($t4)
/*     8ca8:	ad990004 */ 	sw	$t9,0x4($t4)
.PF00008cac:
/*     8cac:	8de10000 */ 	lw	$at,0x0($t7)
/*     8cb0:	25ef000c */ 	addiu	$t7,$t7,0xc
/*     8cb4:	2718000c */ 	addiu	$t8,$t8,0xc
/*     8cb8:	af01fff4 */ 	sw	$at,-0xc($t8)
/*     8cbc:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*     8cc0:	af01fff8 */ 	sw	$at,-0x8($t8)
/*     8cc4:	8de1fffc */ 	lw	$at,-0x4($t7)
/*     8cc8:	15eefff8 */ 	bne	$t7,$t6,.PF00008cac
/*     8ccc:	af01fffc */ 	sw	$at,-0x4($t8)
/*     8cd0:	3c0a8006 */ 	lui	$t2,0x8006
/*     8cd4:	254acdc0 */ 	addiu	$t2,$t2,-12864
/*     8cd8:	25490060 */ 	addiu	$t1,$t2,0x60
/*     8cdc:	27ab03c0 */ 	addiu	$t3,$sp,0x3c0
.PF00008ce0:
/*     8ce0:	8d410000 */ 	lw	$at,0x0($t2)
/*     8ce4:	254a000c */ 	addiu	$t2,$t2,0xc
/*     8ce8:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8cec:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8cf0:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*     8cf4:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8cf8:	8d41fffc */ 	lw	$at,-0x4($t2)
/*     8cfc:	1549fff8 */ 	bne	$t2,$t1,.PF00008ce0
/*     8d00:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8d04:	8d410000 */ 	lw	$at,0x0($t2)
/*     8d08:	8d490004 */ 	lw	$t1,0x4($t2)
/*     8d0c:	3c0d8006 */ 	lui	$t5,0x8006
/*     8d10:	25adce28 */ 	addiu	$t5,$t5,-12760
/*     8d14:	25af0060 */ 	addiu	$t7,$t5,0x60
/*     8d18:	27ac0358 */ 	addiu	$t4,$sp,0x358
/*     8d1c:	ad610000 */ 	sw	$at,0x0($t3)
/*     8d20:	ad690004 */ 	sw	$t1,0x4($t3)
.PF00008d24:
/*     8d24:	8da10000 */ 	lw	$at,0x0($t5)
/*     8d28:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8d2c:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8d30:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8d34:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8d38:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8d3c:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8d40:	15affff8 */ 	bne	$t5,$t7,.PF00008d24
/*     8d44:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     8d48:	8da10000 */ 	lw	$at,0x0($t5)
/*     8d4c:	8daf0004 */ 	lw	$t7,0x4($t5)
/*     8d50:	3c198006 */ 	lui	$t9,0x8006
/*     8d54:	2739ce90 */ 	addiu	$t9,$t9,-12656
/*     8d58:	272a0060 */ 	addiu	$t2,$t9,0x60
/*     8d5c:	27b802f0 */ 	addiu	$t8,$sp,0x2f0
/*     8d60:	ad810000 */ 	sw	$at,0x0($t4)
/*     8d64:	ad8f0004 */ 	sw	$t7,0x4($t4)
.PF00008d68:
/*     8d68:	8f210000 */ 	lw	$at,0x0($t9)
/*     8d6c:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8d70:	2718000c */ 	addiu	$t8,$t8,0xc
/*     8d74:	af01fff4 */ 	sw	$at,-0xc($t8)
/*     8d78:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*     8d7c:	af01fff8 */ 	sw	$at,-0x8($t8)
/*     8d80:	8f21fffc */ 	lw	$at,-0x4($t9)
/*     8d84:	172afff8 */ 	bne	$t9,$t2,.PF00008d68
/*     8d88:	af01fffc */ 	sw	$at,-0x4($t8)
/*     8d8c:	8f210000 */ 	lw	$at,0x0($t9)
/*     8d90:	8f2a0004 */ 	lw	$t2,0x4($t9)
/*     8d94:	3c0e8006 */ 	lui	$t6,0x8006
/*     8d98:	25cecef8 */ 	addiu	$t6,$t6,-12552
/*     8d9c:	25cd0084 */ 	addiu	$t5,$t6,0x84
/*     8da0:	27ab0268 */ 	addiu	$t3,$sp,0x268
/*     8da4:	af010000 */ 	sw	$at,0x0($t8)
/*     8da8:	af0a0004 */ 	sw	$t2,0x4($t8)
.PF00008dac:
/*     8dac:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8db0:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8db4:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8db8:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8dbc:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*     8dc0:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8dc4:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*     8dc8:	15cdfff8 */ 	bne	$t6,$t5,.PF00008dac
/*     8dcc:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8dd0:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8dd4:	3c098006 */ 	lui	$t1,0x8006
/*     8dd8:	2529cf80 */ 	addiu	$t1,$t1,-12416
/*     8ddc:	25390024 */ 	addiu	$t9,$t1,0x24
/*     8de0:	27ac0240 */ 	addiu	$t4,$sp,0x240
/*     8de4:	ad610000 */ 	sw	$at,0x0($t3)
.PF00008de8:
/*     8de8:	8d210000 */ 	lw	$at,0x0($t1)
/*     8dec:	2529000c */ 	addiu	$t1,$t1,0xc
/*     8df0:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8df4:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8df8:	8d21fff8 */ 	lw	$at,-0x8($t1)
/*     8dfc:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8e00:	8d21fffc */ 	lw	$at,-0x4($t1)
/*     8e04:	1539fff8 */ 	bne	$t1,$t9,.PF00008de8
/*     8e08:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     8e0c:	8d210000 */ 	lw	$at,0x0($t1)
/*     8e10:	3c188006 */ 	lui	$t8,0x8006
/*     8e14:	2718cfa8 */ 	addiu	$t8,$t8,-12376
/*     8e18:	270d0084 */ 	addiu	$t5,$t8,0x84
/*     8e1c:	00407025 */ 	move	$t6,$v0
/*     8e20:	ad810000 */ 	sw	$at,0x0($t4)
.PF00008e24:
/*     8e24:	8f010000 */ 	lw	$at,0x0($t8)
/*     8e28:	2718000c */ 	addiu	$t8,$t8,0xc
/*     8e2c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8e30:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*     8e34:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*     8e38:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*     8e3c:	8f01fffc */ 	lw	$at,-0x4($t8)
/*     8e40:	170dfff8 */ 	bne	$t8,$t5,.PF00008e24
/*     8e44:	adc1fffc */ 	sw	$at,-0x4($t6)
/*     8e48:	8f010000 */ 	lw	$at,0x0($t8)
/*     8e4c:	3c0b8006 */ 	lui	$t3,0x8006
/*     8e50:	256bd030 */ 	addiu	$t3,$t3,-12240
/*     8e54:	25790024 */ 	addiu	$t9,$t3,0x24
/*     8e58:	00a04825 */ 	move	$t1,$a1
/*     8e5c:	adc10000 */ 	sw	$at,0x0($t6)
.PF00008e60:
/*     8e60:	8d610000 */ 	lw	$at,0x0($t3)
/*     8e64:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8e68:	2529000c */ 	addiu	$t1,$t1,0xc
/*     8e6c:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*     8e70:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*     8e74:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*     8e78:	8d61fffc */ 	lw	$at,-0x4($t3)
/*     8e7c:	1579fff8 */ 	bne	$t3,$t9,.PF00008e60
/*     8e80:	ad21fffc */ 	sw	$at,-0x4($t1)
/*     8e84:	8d610000 */ 	lw	$at,0x0($t3)
/*     8e88:	3c0c8006 */ 	lui	$t4,0x8006
/*     8e8c:	258cd058 */ 	addiu	$t4,$t4,-12200
/*     8e90:	258d0108 */ 	addiu	$t5,$t4,0x108
/*     8e94:	0060c025 */ 	move	$t8,$v1
/*     8e98:	ad210000 */ 	sw	$at,0x0($t1)
.PF00008e9c:
/*     8e9c:	8d810000 */ 	lw	$at,0x0($t4)
/*     8ea0:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8ea4:	2718000c */ 	addiu	$t8,$t8,0xc
/*     8ea8:	af01fff4 */ 	sw	$at,-0xc($t8)
/*     8eac:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8eb0:	af01fff8 */ 	sw	$at,-0x8($t8)
/*     8eb4:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8eb8:	158dfff8 */ 	bne	$t4,$t5,.PF00008e9c
/*     8ebc:	af01fffc */ 	sw	$at,-0x4($t8)
/*     8ec0:	3c0e8006 */ 	lui	$t6,0x8006
/*     8ec4:	25ced160 */ 	addiu	$t6,$t6,-11936
/*     8ec8:	25d90024 */ 	addiu	$t9,$t6,0x24
/*     8ecc:	00c05825 */ 	move	$t3,$a2
.PF00008ed0:
/*     8ed0:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8ed4:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8ed8:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8edc:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8ee0:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*     8ee4:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8ee8:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*     8eec:	15d9fff8 */ 	bne	$t6,$t9,.PF00008ed0
/*     8ef0:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8ef4:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8ef8:	3c0f8006 */ 	lui	$t7,0x8006
/*     8efc:	25efd188 */ 	addiu	$t7,$t7,-11896
/*     8f00:	25ec0024 */ 	addiu	$t4,$t7,0x24
/*     8f04:	27a90038 */ 	addiu	$t1,$sp,0x38
/*     8f08:	ad610000 */ 	sw	$at,0x0($t3)
.PF00008f0c:
/*     8f0c:	8de10000 */ 	lw	$at,0x0($t7)
/*     8f10:	25ef000c */ 	addiu	$t7,$t7,0xc
/*     8f14:	2529000c */ 	addiu	$t1,$t1,0xc
/*     8f18:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*     8f1c:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*     8f20:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*     8f24:	8de1fffc */ 	lw	$at,-0x4($t7)
/*     8f28:	15ecfff8 */ 	bne	$t7,$t4,.PF00008f0c
/*     8f2c:	ad21fffc */ 	sw	$at,-0x4($t1)
/*     8f30:	8de10000 */ 	lw	$at,0x0($t7)
/*     8f34:	ad210000 */ 	sw	$at,0x0($t1)
/*     8f38:	91180000 */ 	lbu	$t8,0x0($t0)
/*     8f3c:	8fb005b8 */ 	lw	$s0,0x5b8($sp)
/*     8f40:	54f80004 */ 	bnel	$a3,$t8,.PF00008f54
/*     8f44:	8fb005b8 */ 	lw	$s0,0x5b8($sp)
/*     8f48:	10000003 */ 	b	.PF00008f58
/*     8f4c:	ae020020 */ 	sw	$v0,0x20($s0)
/*     8f50:	8fb005b8 */ 	lw	$s0,0x5b8($sp)
.PF00008f54:
/*     8f54:	ae030020 */ 	sw	$v1,0x20($s0)
.PF00008f58:
/*     8f58:	3c048009 */ 	lui	$a0,0x8009
/*     8f5c:	248453f8 */ 	addiu	$a0,$a0,0x53f8
/*     8f60:	8c820000 */ 	lw	$v0,0x0($a0)
/*     8f64:	28410002 */ 	slti	$at,$v0,0x2
/*     8f68:	14200010 */ 	bnez	$at,.PF00008fac
/*     8f6c:	28410002 */ 	slti	$at,$v0,0x2
/*     8f70:	1420000e */ 	bnez	$at,.PF00008fac
/*     8f74:	00e01825 */ 	move	$v1,$a3
/*     8f78:	26020004 */ 	addiu	$v0,$s0,0x4
/*     8f7c:	91190000 */ 	lbu	$t9,0x0($t0)
.PF00008f80:
/*     8f80:	54f90004 */ 	bnel	$a3,$t9,.PF00008f94
/*     8f84:	ac460020 */ 	sw	$a2,0x20($v0)
/*     8f88:	10000002 */ 	b	.PF00008f94
/*     8f8c:	ac450020 */ 	sw	$a1,0x20($v0)
/*     8f90:	ac460020 */ 	sw	$a2,0x20($v0)
.PF00008f94:
/*     8f94:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*     8f98:	24630001 */ 	addiu	$v1,$v1,0x1
/*     8f9c:	24420004 */ 	addiu	$v0,$v0,0x4
/*     8fa0:	006e082a */ 	slt	$at,$v1,$t6
/*     8fa4:	5420fff6 */ 	bnezl	$at,.PF00008f80
/*     8fa8:	91190000 */ 	lbu	$t9,0x0($t0)
.PF00008fac:
/*     8fac:	3c048009 */ 	lui	$a0,0x8009
/*     8fb0:	24841dd0 */ 	addiu	$a0,$a0,0x1dd0
/*     8fb4:	0c00bd28 */ 	jal	n_alInit
/*     8fb8:	02002825 */ 	move	$a1,$s0
/*     8fbc:	00002025 */ 	move	$a0,$zero
/*     8fc0:	0c00c13f */ 	jal	func00030bfc
/*     8fc4:	2405003c */ 	li	$a1,0x3c
/*     8fc8:	3c0b8009 */ 	lui	$t3,0x8009
/*     8fcc:	8d6b1e40 */ 	lw	$t3,0x1e40($t3)
/*     8fd0:	3c048009 */ 	lui	$a0,0x8009
/*     8fd4:	3c067001 */ 	lui	$a2,0x7001
/*     8fd8:	240d0014 */ 	li	$t5,0x14
/*     8fdc:	afad0014 */ 	sw	$t5,0x14($sp)
/*     8fe0:	24c6907c */ 	addiu	$a2,$a2,-28548
/*     8fe4:	24841b30 */ 	addiu	$a0,$a0,0x1b30
/*     8fe8:	24050004 */ 	li	$a1,0x4
/*     8fec:	00003825 */ 	move	$a3,$zero
/*     8ff0:	0c000fac */ 	jal	osCreateThread
/*     8ff4:	afab0010 */ 	sw	$t3,0x10($sp)
/*     8ff8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     8ffc:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*     9000:	8fb10020 */ 	lw	$s1,0x20($sp)
/*     9004:	8fb20024 */ 	lw	$s2,0x24($sp)
/*     9008:	8fb30028 */ 	lw	$s3,0x28($sp)
/*     900c:	03e00008 */ 	jr	$ra
/*     9010:	27bd05b8 */ 	addiu	$sp,$sp,0x5b8
);
#else
GLOBAL_ASM(
glabel amgrCreate
/*     8a48:	27bdfa40 */ 	addiu	$sp,$sp,-1472
/*     8a4c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     8a50:	afa405c0 */ 	sw	$a0,0x5c0($sp)
/*     8a54:	afb50030 */ 	sw	$s5,0x30($sp)
/*     8a58:	afb4002c */ 	sw	$s4,0x2c($sp)
/*     8a5c:	afb30028 */ 	sw	$s3,0x28($sp)
/*     8a60:	afb20024 */ 	sw	$s2,0x24($sp)
/*     8a64:	afb10020 */ 	sw	$s1,0x20($sp)
/*     8a68:	afb0001c */ 	sw	$s0,0x1c($sp)
/*     8a6c:	0c01389c */ 	jal	osAiSetFrequency
/*     8a70:	24045604 */ 	addiu	$a0,$zero,0x5604
/*     8a74:	44822000 */ 	mtc1	$v0,$f4
/*     8a78:	3c0141f0 */ 	lui	$at,0x41f0
/*     8a7c:	44814000 */ 	mtc1	$at,$f8
/*     8a80:	468021a0 */ 	cvt.s.w	$f6,$f4
/*     8a84:	8fa505c0 */ 	lw	$a1,0x5c0($sp)
/*     8a88:	3c0e7001 */ 	lui	$t6,%hi(func00009844)
/*     8a8c:	3c158009 */ 	lui	$s5,%hi(g_Is4Mb)
/*     8a90:	25ce9844 */ 	addiu	$t6,$t6,%lo(func00009844)
/*     8a94:	26b50af0 */ 	addiu	$s5,$s5,%lo(g_Is4Mb)
/*     8a98:	46083083 */ 	div.s	$f2,$f6,$f8
/*     8a9c:	aca20018 */ 	sw	$v0,0x18($a1)
/*     8aa0:	acae0010 */ 	sw	$t6,0x10($a1)
/*     8aa4:	92af0000 */ 	lbu	$t7,0x0($s5)
/*     8aa8:	24140001 */ 	addiu	$s4,$zero,0x1
/*     8aac:	240400b8 */ 	addiu	$a0,$zero,0xb8
/*     8ab0:	168f0006 */ 	bne	$s4,$t7,.L00008acc
/*     8ab4:	46001006 */ 	mov.s	$f0,$f2
/*     8ab8:	3c013f00 */ 	lui	$at,0x3f00
/*     8abc:	44815000 */ 	mtc1	$at,$f10
/*     8ac0:	00000000 */ 	nop
/*     8ac4:	460a1002 */ 	mul.s	$f0,$f2,$f10
/*     8ac8:	00000000 */ 	nop
.L00008acc:
/*     8acc:	4600040d */ 	trunc.w.s	$f16,$f0
/*     8ad0:	3c038009 */ 	lui	$v1,%hi(var800918e0)
/*     8ad4:	246318e0 */ 	addiu	$v1,$v1,%lo(var800918e0)
/*     8ad8:	44198000 */ 	mfc1	$t9,$f16
/*     8adc:	00000000 */ 	nop
/*     8ae0:	03201025 */ 	or	$v0,$t9,$zero
/*     8ae4:	44829000 */ 	mtc1	$v0,$f18
/*     8ae8:	ac790000 */ 	sw	$t9,0x0($v1)
/*     8aec:	07210005 */ 	bgez	$t9,.L00008b04
/*     8af0:	46809120 */ 	cvt.s.w	$f4,$f18
/*     8af4:	3c014f80 */ 	lui	$at,0x4f80
/*     8af8:	44813000 */ 	mtc1	$at,$f6
/*     8afc:	00000000 */ 	nop
/*     8b00:	46062100 */ 	add.s	$f4,$f4,$f6
.L00008b04:
/*     8b04:	4600203c */ 	c.lt.s	$f4,$f0
/*     8b08:	00000000 */ 	nop
/*     8b0c:	45000004 */ 	bc1f	.L00008b20
/*     8b10:	00000000 */ 	nop
/*     8b14:	24480001 */ 	addiu	$t0,$v0,0x1
/*     8b18:	ac680000 */ 	sw	$t0,0x0($v1)
/*     8b1c:	01001025 */ 	or	$v0,$t0,$zero
.L00008b20:
/*     8b20:	0044001b */ 	divu	$zero,$v0,$a0
/*     8b24:	00004812 */ 	mflo	$t1
/*     8b28:	3c018009 */ 	lui	$at,%hi(var800918dc)
/*     8b2c:	14800002 */ 	bnez	$a0,.L00008b38
/*     8b30:	00000000 */ 	nop
/*     8b34:	0007000d */ 	break	0x7
.L00008b38:
/*     8b38:	01240019 */ 	multu	$t1,$a0
/*     8b3c:	00005012 */ 	mflo	$t2
/*     8b40:	254b00b8 */ 	addiu	$t3,$t2,0xb8
/*     8b44:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*     8b48:	256cff48 */ 	addiu	$t4,$t3,-184
/*     8b4c:	ac2c18dc */ 	sw	$t4,%lo(var800918dc)($at)
/*     8b50:	3c018009 */ 	lui	$at,%hi(var800918e4)
/*     8b54:	256d0050 */ 	addiu	$t5,$t3,0x50
/*     8b58:	ac2d18e4 */ 	sw	$t5,%lo(var800918e4)($at)
/*     8b5c:	3c018006 */ 	lui	$at,%hi(var8005cf94)
/*     8b60:	0c002598 */ 	jal	func00009660
/*     8b64:	a020cf94 */ 	sb	$zero,%lo(var8005cf94)($at)
/*     8b68:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x280)
/*     8b6c:	3c058009 */ 	lui	$a1,%hi(g_AudioManager+0x298)
/*     8b70:	24a51860 */ 	addiu	$a1,$a1,%lo(g_AudioManager+0x298)
/*     8b74:	24841848 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x280)
/*     8b78:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     8b7c:	24060008 */ 	addiu	$a2,$zero,0x8
/*     8b80:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x248)
/*     8b84:	3c058009 */ 	lui	$a1,%hi(g_AudioManager+0x260)
/*     8b88:	24a51828 */ 	addiu	$a1,$a1,%lo(g_AudioManager+0x260)
/*     8b8c:	24841810 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x248)
/*     8b90:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     8b94:	24060008 */ 	addiu	$a2,$zero,0x8
/*     8b98:	92af0000 */ 	lbu	$t7,0x0($s5)
/*     8b9c:	3c128009 */ 	lui	$s2,%hi(var800918ec)
/*     8ba0:	265218ec */ 	addiu	$s2,$s2,%lo(var800918ec)
/*     8ba4:	240e07d0 */ 	addiu	$t6,$zero,0x7d0
/*     8ba8:	168f0003 */ 	bne	$s4,$t7,.L00008bb8
/*     8bac:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*     8bb0:	000ec843 */ 	sra	$t9,$t6,0x1
/*     8bb4:	ae590000 */ 	sw	$t9,0x0($s2)
.L00008bb8:
/*     8bb8:	3c108009 */ 	lui	$s0,%hi(g_AudioManager)
/*     8bbc:	3c138009 */ 	lui	$s3,%hi(g_AudioManager+0x8)
/*     8bc0:	3c118009 */ 	lui	$s1,%hi(g_SndHeap)
/*     8bc4:	263151f0 */ 	addiu	$s1,$s1,%lo(g_SndHeap)
/*     8bc8:	267315d0 */ 	addiu	$s3,$s3,%lo(g_AudioManager+0x8)
/*     8bcc:	261015c8 */ 	addiu	$s0,$s0,%lo(g_AudioManager)
.L00008bd0:
/*     8bd0:	8e480000 */ 	lw	$t0,0x0($s2)
/*     8bd4:	00002025 */ 	or	$a0,$zero,$zero
/*     8bd8:	00002825 */ 	or	$a1,$zero,$zero
/*     8bdc:	000848c0 */ 	sll	$t1,$t0,0x3
/*     8be0:	afa90010 */ 	sw	$t1,0x10($sp)
/*     8be4:	02203025 */ 	or	$a2,$s1,$zero
/*     8be8:	0c00bec5 */ 	jal	alHeapDBAlloc
/*     8bec:	02803825 */ 	or	$a3,$s4,$zero
/*     8bf0:	26100004 */ 	addiu	$s0,$s0,0x4
/*     8bf4:	0213082b */ 	sltu	$at,$s0,$s3
/*     8bf8:	1420fff5 */ 	bnez	$at,.L00008bd0
/*     8bfc:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*     8c00:	3c108009 */ 	lui	$s0,%hi(g_AudioManager)
/*     8c04:	3c128009 */ 	lui	$s2,%hi(g_AudioManager+0x0c)
/*     8c08:	265215d4 */ 	addiu	$s2,$s2,%lo(g_AudioManager+0x0c)
/*     8c0c:	261015c8 */ 	addiu	$s0,$s0,%lo(g_AudioManager)
.L00008c10:
/*     8c10:	240a0060 */ 	addiu	$t2,$zero,0x60
/*     8c14:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     8c18:	00002025 */ 	or	$a0,$zero,$zero
/*     8c1c:	00002825 */ 	or	$a1,$zero,$zero
/*     8c20:	02203025 */ 	or	$a2,$s1,$zero
/*     8c24:	0c00bec5 */ 	jal	alHeapDBAlloc
/*     8c28:	02803825 */ 	or	$a3,$s4,$zero
/*     8c2c:	ae020008 */ 	sw	$v0,0x8($s0)
/*     8c30:	a4400004 */ 	sh	$zero,0x4($v0)
/*     8c34:	240b0c00 */ 	addiu	$t3,$zero,0xc00
/*     8c38:	afab0010 */ 	sw	$t3,0x10($sp)
/*     8c3c:	00002025 */ 	or	$a0,$zero,$zero
/*     8c40:	00002825 */ 	or	$a1,$zero,$zero
/*     8c44:	02203025 */ 	or	$a2,$s1,$zero
/*     8c48:	0c00bec5 */ 	jal	alHeapDBAlloc
/*     8c4c:	02803825 */ 	or	$a3,$s4,$zero
/*     8c50:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*     8c54:	26100004 */ 	addiu	$s0,$s0,0x4
/*     8c58:	0212082b */ 	sltu	$at,$s0,$s2
/*     8c5c:	1420ffec */ 	bnez	$at,.L00008c10
/*     8c60:	ad820000 */ 	sw	$v0,0x0($t4)
/*     8c64:	3c0e8006 */ 	lui	$t6,%hi(var8005cf98)
/*     8c68:	25cecf98 */ 	addiu	$t6,$t6,%lo(var8005cf98)
/*     8c6c:	27a201c0 */ 	addiu	$v0,$sp,0x1c0
/*     8c70:	27a30090 */ 	addiu	$v1,$sp,0x90
/*     8c74:	27a50198 */ 	addiu	$a1,$sp,0x198
/*     8c78:	27a60068 */ 	addiu	$a2,$sp,0x68
/*     8c7c:	25d80024 */ 	addiu	$t8,$t6,0x24
/*     8c80:	27ad0590 */ 	addiu	$t5,$sp,0x590
.L00008c84:
/*     8c84:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8c88:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8c8c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8c90:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*     8c94:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*     8c98:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*     8c9c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*     8ca0:	15d8fff8 */ 	bne	$t6,$t8,.L00008c84
/*     8ca4:	ada1fffc */ 	sw	$at,-0x4($t5)
/*     8ca8:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8cac:	3c088006 */ 	lui	$t0,%hi(var8005cfc0)
/*     8cb0:	2508cfc0 */ 	addiu	$t0,$t0,%lo(var8005cfc0)
/*     8cb4:	250a0024 */ 	addiu	$t2,$t0,0x24
/*     8cb8:	27b90568 */ 	addiu	$t9,$sp,0x568
/*     8cbc:	ada10000 */ 	sw	$at,0x0($t5)
.L00008cc0:
/*     8cc0:	8d010000 */ 	lw	$at,0x0($t0)
/*     8cc4:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8cc8:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8ccc:	af21fff4 */ 	sw	$at,-0xc($t9)
/*     8cd0:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8cd4:	af21fff8 */ 	sw	$at,-0x8($t9)
/*     8cd8:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8cdc:	150afff8 */ 	bne	$t0,$t2,.L00008cc0
/*     8ce0:	af21fffc */ 	sw	$at,-0x4($t9)
/*     8ce4:	8d010000 */ 	lw	$at,0x0($t0)
/*     8ce8:	3c0c8006 */ 	lui	$t4,%hi(var8005cfe8)
/*     8cec:	258ccfe8 */ 	addiu	$t4,$t4,%lo(var8005cfe8)
/*     8cf0:	25980024 */ 	addiu	$t8,$t4,0x24
/*     8cf4:	27ab0540 */ 	addiu	$t3,$sp,0x540
/*     8cf8:	af210000 */ 	sw	$at,0x0($t9)
.L00008cfc:
/*     8cfc:	8d810000 */ 	lw	$at,0x0($t4)
/*     8d00:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8d04:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8d08:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8d0c:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8d10:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8d14:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8d18:	1598fff8 */ 	bne	$t4,$t8,.L00008cfc
/*     8d1c:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8d20:	8d810000 */ 	lw	$at,0x0($t4)
/*     8d24:	3c0d8006 */ 	lui	$t5,%hi(var8005d010)
/*     8d28:	25add010 */ 	addiu	$t5,$t5,%lo(var8005d010)
/*     8d2c:	25aa00c0 */ 	addiu	$t2,$t5,0xc0
/*     8d30:	27ae0478 */ 	addiu	$t6,$sp,0x478
/*     8d34:	ad610000 */ 	sw	$at,0x0($t3)
.L00008d38:
/*     8d38:	8da10000 */ 	lw	$at,0x0($t5)
/*     8d3c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8d40:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8d44:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*     8d48:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8d4c:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*     8d50:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8d54:	15aafff8 */ 	bne	$t5,$t2,.L00008d38
/*     8d58:	adc1fffc */ 	sw	$at,-0x4($t6)
/*     8d5c:	8da10000 */ 	lw	$at,0x0($t5)
/*     8d60:	8daa0004 */ 	lw	$t2,0x4($t5)
/*     8d64:	3c198006 */ 	lui	$t9,%hi(var8005d0d8)
/*     8d68:	2739d0d8 */ 	addiu	$t9,$t9,%lo(var8005d0d8)
/*     8d6c:	27380048 */ 	addiu	$t8,$t9,0x48
/*     8d70:	27a80430 */ 	addiu	$t0,$sp,0x430
/*     8d74:	adc10000 */ 	sw	$at,0x0($t6)
/*     8d78:	adca0004 */ 	sw	$t2,0x4($t6)
.L00008d7c:
/*     8d7c:	8f210000 */ 	lw	$at,0x0($t9)
/*     8d80:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8d84:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8d88:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*     8d8c:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*     8d90:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*     8d94:	8f21fffc */ 	lw	$at,-0x4($t9)
/*     8d98:	1738fff8 */ 	bne	$t9,$t8,.L00008d7c
/*     8d9c:	ad01fffc */ 	sw	$at,-0x4($t0)
/*     8da0:	3c0b8006 */ 	lui	$t3,%hi(var8005d120)
/*     8da4:	256bd120 */ 	addiu	$t3,$t3,%lo(var8005d120)
/*     8da8:	256a0060 */ 	addiu	$t2,$t3,0x60
/*     8dac:	27ac03c8 */ 	addiu	$t4,$sp,0x3c8
.L00008db0:
/*     8db0:	8d610000 */ 	lw	$at,0x0($t3)
/*     8db4:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8db8:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8dbc:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8dc0:	8d61fff8 */ 	lw	$at,-0x8($t3)
/*     8dc4:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8dc8:	8d61fffc */ 	lw	$at,-0x4($t3)
/*     8dcc:	156afff8 */ 	bne	$t3,$t2,.L00008db0
/*     8dd0:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     8dd4:	8d610000 */ 	lw	$at,0x0($t3)
/*     8dd8:	8d6a0004 */ 	lw	$t2,0x4($t3)
/*     8ddc:	3c0e8006 */ 	lui	$t6,%hi(var8005d188)
/*     8de0:	25ced188 */ 	addiu	$t6,$t6,%lo(var8005d188)
/*     8de4:	25d80060 */ 	addiu	$t8,$t6,0x60
/*     8de8:	27ad0360 */ 	addiu	$t5,$sp,0x360
/*     8dec:	ad810000 */ 	sw	$at,0x0($t4)
/*     8df0:	ad8a0004 */ 	sw	$t2,0x4($t4)
.L00008df4:
/*     8df4:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8df8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8dfc:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8e00:	ada1fff4 */ 	sw	$at,-0xc($t5)
/*     8e04:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*     8e08:	ada1fff8 */ 	sw	$at,-0x8($t5)
/*     8e0c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*     8e10:	15d8fff8 */ 	bne	$t6,$t8,.L00008df4
/*     8e14:	ada1fffc */ 	sw	$at,-0x4($t5)
/*     8e18:	8dc10000 */ 	lw	$at,0x0($t6)
/*     8e1c:	8dd80004 */ 	lw	$t8,0x4($t6)
/*     8e20:	3c088006 */ 	lui	$t0,%hi(var8005d1f0)
/*     8e24:	2508d1f0 */ 	addiu	$t0,$t0,%lo(var8005d1f0)
/*     8e28:	250a0060 */ 	addiu	$t2,$t0,0x60
/*     8e2c:	27b902f8 */ 	addiu	$t9,$sp,0x2f8
/*     8e30:	ada10000 */ 	sw	$at,0x0($t5)
/*     8e34:	adb80004 */ 	sw	$t8,0x4($t5)
.L00008e38:
/*     8e38:	8d010000 */ 	lw	$at,0x0($t0)
/*     8e3c:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8e40:	2739000c */ 	addiu	$t9,$t9,0xc
/*     8e44:	af21fff4 */ 	sw	$at,-0xc($t9)
/*     8e48:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8e4c:	af21fff8 */ 	sw	$at,-0x8($t9)
/*     8e50:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8e54:	150afff8 */ 	bne	$t0,$t2,.L00008e38
/*     8e58:	af21fffc */ 	sw	$at,-0x4($t9)
/*     8e5c:	8d010000 */ 	lw	$at,0x0($t0)
/*     8e60:	8d0a0004 */ 	lw	$t2,0x4($t0)
/*     8e64:	3c0c8006 */ 	lui	$t4,%hi(var8005d258)
/*     8e68:	258cd258 */ 	addiu	$t4,$t4,%lo(var8005d258)
/*     8e6c:	25980084 */ 	addiu	$t8,$t4,0x84
/*     8e70:	27ab0270 */ 	addiu	$t3,$sp,0x270
/*     8e74:	af210000 */ 	sw	$at,0x0($t9)
/*     8e78:	af2a0004 */ 	sw	$t2,0x4($t9)
.L00008e7c:
/*     8e7c:	8d810000 */ 	lw	$at,0x0($t4)
/*     8e80:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8e84:	256b000c */ 	addiu	$t3,$t3,0xc
/*     8e88:	ad61fff4 */ 	sw	$at,-0xc($t3)
/*     8e8c:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8e90:	ad61fff8 */ 	sw	$at,-0x8($t3)
/*     8e94:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8e98:	1598fff8 */ 	bne	$t4,$t8,.L00008e7c
/*     8e9c:	ad61fffc */ 	sw	$at,-0x4($t3)
/*     8ea0:	8d810000 */ 	lw	$at,0x0($t4)
/*     8ea4:	3c0d8006 */ 	lui	$t5,%hi(var8005d2e0)
/*     8ea8:	25add2e0 */ 	addiu	$t5,$t5,%lo(var8005d2e0)
/*     8eac:	25aa0024 */ 	addiu	$t2,$t5,0x24
/*     8eb0:	27ae0248 */ 	addiu	$t6,$sp,0x248
/*     8eb4:	ad610000 */ 	sw	$at,0x0($t3)
.L00008eb8:
/*     8eb8:	8da10000 */ 	lw	$at,0x0($t5)
/*     8ebc:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8ec0:	25ce000c */ 	addiu	$t6,$t6,0xc
/*     8ec4:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*     8ec8:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8ecc:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*     8ed0:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8ed4:	15aafff8 */ 	bne	$t5,$t2,.L00008eb8
/*     8ed8:	adc1fffc */ 	sw	$at,-0x4($t6)
/*     8edc:	8da10000 */ 	lw	$at,0x0($t5)
/*     8ee0:	3c088006 */ 	lui	$t0,%hi(var8005d308)
/*     8ee4:	2508d308 */ 	addiu	$t0,$t0,%lo(var8005d308)
/*     8ee8:	250f0084 */ 	addiu	$t7,$t0,0x84
/*     8eec:	0040c025 */ 	or	$t8,$v0,$zero
/*     8ef0:	adc10000 */ 	sw	$at,0x0($t6)
.L00008ef4:
/*     8ef4:	8d010000 */ 	lw	$at,0x0($t0)
/*     8ef8:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8efc:	2718000c */ 	addiu	$t8,$t8,0xc
/*     8f00:	af01fff4 */ 	sw	$at,-0xc($t8)
/*     8f04:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8f08:	af01fff8 */ 	sw	$at,-0x8($t8)
/*     8f0c:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8f10:	150ffff8 */ 	bne	$t0,$t7,.L00008ef4
/*     8f14:	af01fffc */ 	sw	$at,-0x4($t8)
/*     8f18:	8d010000 */ 	lw	$at,0x0($t0)
/*     8f1c:	3c0c8006 */ 	lui	$t4,%hi(var8005d390)
/*     8f20:	258cd390 */ 	addiu	$t4,$t4,%lo(var8005d390)
/*     8f24:	25890024 */ 	addiu	$t1,$t4,0x24
/*     8f28:	00a05025 */ 	or	$t2,$a1,$zero
/*     8f2c:	af010000 */ 	sw	$at,0x0($t8)
.L00008f30:
/*     8f30:	8d810000 */ 	lw	$at,0x0($t4)
/*     8f34:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8f38:	254a000c */ 	addiu	$t2,$t2,0xc
/*     8f3c:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*     8f40:	8d81fff8 */ 	lw	$at,-0x8($t4)
/*     8f44:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*     8f48:	8d81fffc */ 	lw	$at,-0x4($t4)
/*     8f4c:	1589fff8 */ 	bne	$t4,$t1,.L00008f30
/*     8f50:	ad41fffc */ 	sw	$at,-0x4($t2)
/*     8f54:	8d810000 */ 	lw	$at,0x0($t4)
/*     8f58:	3c0d8006 */ 	lui	$t5,%hi(var8005d3b8)
/*     8f5c:	25add3b8 */ 	addiu	$t5,$t5,%lo(var8005d3b8)
/*     8f60:	25b90108 */ 	addiu	$t9,$t5,0x108
/*     8f64:	00607825 */ 	or	$t7,$v1,$zero
/*     8f68:	ad410000 */ 	sw	$at,0x0($t2)
.L00008f6c:
/*     8f6c:	8da10000 */ 	lw	$at,0x0($t5)
/*     8f70:	25ad000c */ 	addiu	$t5,$t5,0xc
/*     8f74:	25ef000c */ 	addiu	$t7,$t7,0xc
/*     8f78:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*     8f7c:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*     8f80:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*     8f84:	8da1fffc */ 	lw	$at,-0x4($t5)
/*     8f88:	15b9fff8 */ 	bne	$t5,$t9,.L00008f6c
/*     8f8c:	ade1fffc */ 	sw	$at,-0x4($t7)
/*     8f90:	3c088006 */ 	lui	$t0,%hi(var8005d4c0)
/*     8f94:	2508d4c0 */ 	addiu	$t0,$t0,%lo(var8005d4c0)
/*     8f98:	250b0024 */ 	addiu	$t3,$t0,0x24
/*     8f9c:	00c04825 */ 	or	$t1,$a2,$zero
.L00008fa0:
/*     8fa0:	8d010000 */ 	lw	$at,0x0($t0)
/*     8fa4:	2508000c */ 	addiu	$t0,$t0,0xc
/*     8fa8:	2529000c */ 	addiu	$t1,$t1,0xc
/*     8fac:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*     8fb0:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*     8fb4:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*     8fb8:	8d01fffc */ 	lw	$at,-0x4($t0)
/*     8fbc:	150bfff8 */ 	bne	$t0,$t3,.L00008fa0
/*     8fc0:	ad21fffc */ 	sw	$at,-0x4($t1)
/*     8fc4:	8d010000 */ 	lw	$at,0x0($t0)
/*     8fc8:	3c0a8006 */ 	lui	$t2,%hi(var8005d4e8)
/*     8fcc:	254ad4e8 */ 	addiu	$t2,$t2,%lo(var8005d4e8)
/*     8fd0:	25590024 */ 	addiu	$t9,$t2,0x24
/*     8fd4:	27ac0040 */ 	addiu	$t4,$sp,0x40
/*     8fd8:	ad210000 */ 	sw	$at,0x0($t1)
.L00008fdc:
/*     8fdc:	8d410000 */ 	lw	$at,0x0($t2)
/*     8fe0:	254a000c */ 	addiu	$t2,$t2,0xc
/*     8fe4:	258c000c */ 	addiu	$t4,$t4,0xc
/*     8fe8:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*     8fec:	8d41fff8 */ 	lw	$at,-0x8($t2)
/*     8ff0:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*     8ff4:	8d41fffc */ 	lw	$at,-0x4($t2)
/*     8ff8:	1559fff8 */ 	bne	$t2,$t9,.L00008fdc
/*     8ffc:	ad81fffc */ 	sw	$at,-0x4($t4)
/*     9000:	8d410000 */ 	lw	$at,0x0($t2)
/*     9004:	ad810000 */ 	sw	$at,0x0($t4)
/*     9008:	92ad0000 */ 	lbu	$t5,0x0($s5)
/*     900c:	8fa705c0 */ 	lw	$a3,0x5c0($sp)
/*     9010:	568d0004 */ 	bnel	$s4,$t5,.L00009024
/*     9014:	8fa705c0 */ 	lw	$a3,0x5c0($sp)
/*     9018:	10000003 */ 	b	.L00009028
/*     901c:	ace20020 */ 	sw	$v0,0x20($a3)
/*     9020:	8fa705c0 */ 	lw	$a3,0x5c0($sp)
.L00009024:
/*     9024:	ace30020 */ 	sw	$v1,0x20($a3)
.L00009028:
/*     9028:	3c048009 */ 	lui	$a0,%hi(var80094ea8)
/*     902c:	24844ea8 */ 	addiu	$a0,$a0,%lo(var80094ea8)
/*     9030:	8c820000 */ 	lw	$v0,0x0($a0)
/*     9034:	28410002 */ 	slti	$at,$v0,0x2
/*     9038:	14200010 */ 	bnez	$at,.L0000907c
/*     903c:	28410002 */ 	slti	$at,$v0,0x2
/*     9040:	1420000e */ 	bnez	$at,.L0000907c
/*     9044:	02801825 */ 	or	$v1,$s4,$zero
/*     9048:	24e20004 */ 	addiu	$v0,$a3,0x4
/*     904c:	92b80000 */ 	lbu	$t8,0x0($s5)
.L00009050:
/*     9050:	56980004 */ 	bnel	$s4,$t8,.L00009064
/*     9054:	ac460020 */ 	sw	$a2,0x20($v0)
/*     9058:	10000002 */ 	b	.L00009064
/*     905c:	ac450020 */ 	sw	$a1,0x20($v0)
/*     9060:	ac460020 */ 	sw	$a2,0x20($v0)
.L00009064:
/*     9064:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*     9068:	24630001 */ 	addiu	$v1,$v1,0x1
/*     906c:	24420004 */ 	addiu	$v0,$v0,0x4
/*     9070:	006b082a */ 	slt	$at,$v1,$t3
/*     9074:	5420fff6 */ 	bnezl	$at,.L00009050
/*     9078:	92b80000 */ 	lbu	$t8,0x0($s5)
.L0000907c:
/*     907c:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x2b8)
/*     9080:	24841880 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x2b8)
/*     9084:	0c00bee8 */ 	jal	n_alInit
/*     9088:	00e02825 */ 	or	$a1,$a3,$zero
/*     908c:	00002025 */ 	or	$a0,$zero,$zero
/*     9090:	0c00c2ff */ 	jal	func00030bfc
/*     9094:	2405003c */ 	addiu	$a1,$zero,0x3c
/*     9098:	3c088009 */ 	lui	$t0,%hi(g_AudioSp)
/*     909c:	8d0818f0 */ 	lw	$t0,%lo(g_AudioSp)($t0)
/*     90a0:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x18)
/*     90a4:	3c067001 */ 	lui	$a2,%hi(amgrMain)
/*     90a8:	24090014 */ 	addiu	$t1,$zero,0x14
/*     90ac:	afa90014 */ 	sw	$t1,0x14($sp)
/*     90b0:	24c69154 */ 	addiu	$a2,$a2,%lo(amgrMain)
/*     90b4:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x18)
/*     90b8:	24050004 */ 	addiu	$a1,$zero,0x4
/*     90bc:	00003825 */ 	or	$a3,$zero,$zero
/*     90c0:	0c000fb8 */ 	jal	osCreateThread
/*     90c4:	afa80010 */ 	sw	$t0,0x10($sp)
/*     90c8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     90cc:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*     90d0:	8fb10020 */ 	lw	$s1,0x20($sp)
/*     90d4:	8fb20024 */ 	lw	$s2,0x24($sp)
/*     90d8:	8fb30028 */ 	lw	$s3,0x28($sp)
/*     90dc:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*     90e0:	8fb50030 */ 	lw	$s5,0x30($sp)
/*     90e4:	03e00008 */ 	jr	$ra
/*     90e8:	27bd05c0 */ 	addiu	$sp,$sp,0x5c0
);
#endif

void amgrStartThread(void)
{
	osStartThread(&g_AudioManager.thread);
	g_AudioIsThreadRunning = true;
}

OSMesgQueue *amgrGetFrameMesgQueue(void)
{
	return &g_AudioManager.audioFrameMsgQ;
}

/**
 * This doesn't set g_AudioIsThreadRunning to false, but that's okay because
 * this is only called when resetting the console, and when that happens the
 * variable is likely reset too.
 */
void amgrStopThread(void)
{
	if (g_AudioIsThreadRunning) {
		osStopThread(&g_AudioManager.thread);
	}
}

void amgrMain(void *arg)
{
	s32 count = 0;
	bool done = false;
	s16 *msg = NULL;
	AudioInfo *info = NULL;

	static u32 var8005d514 = 1;

#if VERSION >= VERSION_PAL_FINAL
	osScAddClient(&g_SchedThread, &var800918d0, &g_AudioManager.audioFrameMsgQ, (void *)true);
#else
	osScAddClient(&g_SchedThread, &var800918d0, &g_AudioManager.audioFrameMsgQ, (void *)!IS4MB());
#endif

	while (!done) {
		osRecvMesg(&g_AudioManager.audioFrameMsgQ, (OSMesg *) &msg, OS_MESG_BLOCK);

		switch (*msg) {
		case 4:
			var80091588 = osGetTime();
			func00009aa0(0x30000);
			amgrHandleFrameMsg(g_AudioManager.audioInfo[var80092828 % 3], info);
			func00009a08();

			count++;
			func00009aa0(0x60000);

			var80091590 = osGetTime();
			var80091570 = var80091590 - var80091588;

			if (count % 240 == 0) {
				var80091578 = var80091580 / 240;
				var80091580 = 0; var80091568 = 0;
			} else {
				var80091580 = (var80091580 + var80091590) - var80091588;
			}

			if (var80091568 < var80091590 - var80091588) {
				var80091568 = var80091590 - var80091588;
			}

			if (var8005d514 == 0) {
				osRecvMesg(&g_AudioManager.audioReplyMsgQ, (OSMesg *) &info, OS_MESG_BLOCK);
			}

			var8005d514 = 0;
			amgrHandleDoneMsg(info);
			break;
		case 5:
			done = true;
			break;
		case 10:
			done = true;
			break;
		}
	}

	n_alClose(&g_AudioManager.g);
}

GLOBAL_ASM(
glabel amgrHandleFrameMsg
/*     9448:	3c068009 */ 	lui	$a2,%hi(g_AmgrCurrentCmdList)
/*     944c:	8cc618f4 */ 	lw	$a2,%lo(g_AmgrCurrentCmdList)($a2)
/*     9450:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*     9454:	afb00018 */ 	sw	$s0,0x18($sp)
/*     9458:	00808025 */ 	or	$s0,$a0,$zero
/*     945c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     9460:	10c00007 */ 	beqz	$a2,.L00009480
/*     9464:	afa50034 */ 	sw	$a1,0x34($sp)
/*     9468:	3c048009 */ 	lui	$a0,%hi(g_SchedThread)
/*     946c:	3c018009 */ 	lui	$at,%hi(g_AmgrCurrentCmdList)
/*     9470:	ac2618f4 */ 	sw	$a2,%lo(g_AmgrCurrentCmdList)($at)
/*     9474:	2484dbd0 */ 	addiu	$a0,$a0,%lo(g_SchedThread)
/*     9478:	0c0007ea */ 	jal	__scHandleRetraceViaPri
/*     947c:	00c02825 */ 	or	$a1,$a2,$zero
.L00009480:
/*     9480:	0c00264f */ 	jal	amgrClearDmaBuffers
/*     9484:	00000000 */ 	nop
/*     9488:	3c198006 */ 	lui	$t9,%hi(var8005cf90)
/*     948c:	8f39cf90 */ 	lw	$t9,%lo(var8005cf90)($t9)
/*     9490:	3c0ea450 */ 	lui	$t6,0xa450
/*     9494:	3c098009 */ 	lui	$t1,%hi(g_AudioManager)
/*     9498:	00194080 */ 	sll	$t0,$t9,0x2
/*     949c:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*     94a0:	01284821 */ 	addu	$t1,$t1,$t0
/*     94a4:	8d2915c8 */ 	lw	$t1,%lo(g_AudioManager)($t1)
/*     94a8:	000fc082 */ 	srl	$t8,$t7,0x2
/*     94ac:	afb8002c */ 	sw	$t8,0x2c($sp)
/*     94b0:	afa90024 */ 	sw	$t1,0x24($sp)
/*     94b4:	0c012d20 */ 	jal	osVirtualToPhysical
/*     94b8:	8e040000 */ 	lw	$a0,0x0($s0)
/*     94bc:	8fa30034 */ 	lw	$v1,0x34($sp)
/*     94c0:	00403025 */ 	or	$a2,$v0,$zero
/*     94c4:	50600009 */ 	beqzl	$v1,.L000094ec
/*     94c8:	8fab002c */ 	lw	$t3,0x2c($sp)
/*     94cc:	84650004 */ 	lh	$a1,0x4($v1)
/*     94d0:	8c640000 */ 	lw	$a0,0x0($v1)
/*     94d4:	afa20028 */ 	sw	$v0,0x28($sp)
/*     94d8:	00055080 */ 	sll	$t2,$a1,0x2
/*     94dc:	0c0138f0 */ 	jal	osAiSetNextBuffer
/*     94e0:	01402825 */ 	or	$a1,$t2,$zero
/*     94e4:	8fa60028 */ 	lw	$a2,0x28($sp)
/*     94e8:	8fab002c */ 	lw	$t3,0x2c($sp)
.L000094ec:
/*     94ec:	3c058009 */ 	lui	$a1,%hi(var800918e8)
/*     94f0:	3c038006 */ 	lui	$v1,%hi(var8005cf94)
/*     94f4:	2d6100f9 */ 	sltiu	$at,$t3,0xf9
/*     94f8:	1420000b */ 	bnez	$at,.L00009528
/*     94fc:	24a518e8 */ 	addiu	$a1,$a1,%lo(var800918e8)
/*     9500:	2463cf94 */ 	addiu	$v1,$v1,%lo(var8005cf94)
/*     9504:	906c0000 */ 	lbu	$t4,0x0($v1)
/*     9508:	3c0d8009 */ 	lui	$t5,%hi(var800918dc)
/*     950c:	15800006 */ 	bnez	$t4,.L00009528
/*     9510:	00000000 */ 	nop
/*     9514:	8dad18dc */ 	lw	$t5,%lo(var800918dc)($t5)
/*     9518:	240e0002 */ 	addiu	$t6,$zero,0x2
/*     951c:	a60d0004 */ 	sh	$t5,0x4($s0)
/*     9520:	1000000a */ 	b	.L0000954c
/*     9524:	a06e0000 */ 	sb	$t6,0x0($v1)
.L00009528:
/*     9528:	3c0f8009 */ 	lui	$t7,%hi(var800918e0)
/*     952c:	8def18e0 */ 	lw	$t7,%lo(var800918e0)($t7)
/*     9530:	3c038006 */ 	lui	$v1,%hi(var8005cf94)
/*     9534:	2463cf94 */ 	addiu	$v1,$v1,%lo(var8005cf94)
/*     9538:	a60f0004 */ 	sh	$t7,0x4($s0)
/*     953c:	90620000 */ 	lbu	$v0,0x0($v1)
/*     9540:	10400002 */ 	beqz	$v0,.L0000954c
/*     9544:	2458ffff */ 	addiu	$t8,$v0,-1
/*     9548:	a0780000 */ 	sb	$t8,0x0($v1)
.L0000954c:
/*     954c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*     9550:	0c00c4b9 */ 	jal	alAudioFrame
/*     9554:	86070004 */ 	lh	$a3,0x4($s0)
/*     9558:	26060008 */ 	addiu	$a2,$s0,0x8
/*     955c:	3c038006 */ 	lui	$v1,%hi(rspbootTextStart)
/*     9560:	3c088006 */ 	lui	$t0,%hi(rspbootTextEnd)
/*     9564:	24639fe0 */ 	addiu	$v1,$v1,%lo(rspbootTextStart)
/*     9568:	24040002 */ 	addiu	$a0,$zero,0x2
/*     956c:	3c198009 */ 	lui	$t9,%hi(g_AudioManager+0x280)
/*     9570:	2508a0b0 */ 	addiu	$t0,$t0,%lo(rspbootTextEnd)
/*     9574:	3c0a8006 */ 	lui	$t2,%hi(aspMainTextStart)
/*     9578:	3c0b8009 */ 	lui	$t3,%hi(aspMainDataStart)
/*     957c:	27391848 */ 	addiu	$t9,$t9,%lo(g_AudioManager+0x280)
/*     9580:	01034823 */ 	subu	$t1,$t0,$v1
/*     9584:	254ab4d0 */ 	addiu	$t2,$t2,%lo(aspMainTextStart)
/*     9588:	256ba2d0 */ 	addiu	$t3,$t3,%lo(aspMainDataStart)
/*     958c:	240c1000 */ 	addiu	$t4,$zero,0x1000
/*     9590:	240d0800 */ 	addiu	$t5,$zero,0x800
/*     9594:	acc00000 */ 	sw	$zero,0x0($a2)
/*     9598:	acd90050 */ 	sw	$t9,0x50($a2)
/*     959c:	acd00054 */ 	sw	$s0,0x54($a2)
/*     95a0:	acc40008 */ 	sw	$a0,0x8($a2)
/*     95a4:	acc40010 */ 	sw	$a0,0x10($a2)
/*     95a8:	acc00014 */ 	sw	$zero,0x14($a2)
/*     95ac:	acc30018 */ 	sw	$v1,0x18($a2)
/*     95b0:	acc9001c */ 	sw	$t1,0x1c($a2)
/*     95b4:	acca0020 */ 	sw	$t2,0x20($a2)
/*     95b8:	accb0028 */ 	sw	$t3,0x28($a2)
/*     95bc:	accc0024 */ 	sw	$t4,0x24($a2)
/*     95c0:	accd002c */ 	sw	$t5,0x2c($a2)
/*     95c4:	8fae0024 */ 	lw	$t6,0x24($sp)
/*     95c8:	3c018009 */ 	lui	$at,%hi(g_AmgrCurrentCmdList)
/*     95cc:	acce0040 */ 	sw	$t6,0x40($a2)
/*     95d0:	8faf0024 */ 	lw	$t7,0x24($sp)
/*     95d4:	acc00048 */ 	sw	$zero,0x48($a2)
/*     95d8:	acc0004c */ 	sw	$zero,0x4c($a2)
/*     95dc:	004fc023 */ 	subu	$t8,$v0,$t7
/*     95e0:	0018c8c3 */ 	sra	$t9,$t8,0x3
/*     95e4:	001940c0 */ 	sll	$t0,$t9,0x3
/*     95e8:	3c028006 */ 	lui	$v0,%hi(var8005cf90)
/*     95ec:	acc80044 */ 	sw	$t0,0x44($a2)
/*     95f0:	2442cf90 */ 	addiu	$v0,$v0,%lo(var8005cf90)
/*     95f4:	8c490000 */ 	lw	$t1,0x0($v0)
/*     95f8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     95fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     9600:	392a0001 */ 	xori	$t2,$t1,0x1
/*     9604:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*     9608:	ac2618f4 */ 	sw	$a2,%lo(g_AmgrCurrentCmdList)($at)
/*     960c:	03e00008 */ 	jr	$ra
/*     9610:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

// Mismatch:
// - Regalloc, likely relating to g_AmgrCurrentCmdList = g_AmgrCurrentCmdList
// - g_AmgrCurrentCmdList needs to be moved into this file
//void amgrHandleFrameMsg(struct audioinfo *info, struct audioinfo *previnfo)
//{
//	u32 somevalue;
//	s16 *outbuffer;
//	Acmd *datastart;
//	Acmd *cmd;
//	OSScTask *task;
//	static OSScTask *g_AmgrCurrentCmdList;
//
//	extern u32 vara4500004;
//	extern u8 rspbootTextStart;
//	extern u8 rspbootTextEnd;
//	extern u8 aspMainTextStart;
//	extern u8 aspMainDataStart;
//
//	if (g_AmgrCurrentCmdList) {
//		g_AmgrCurrentCmdList = g_AmgrCurrentCmdList;
//		__scHandleRetraceViaPri(&g_SchedThread, g_AmgrCurrentCmdList);
//	}
//
//	amgrClearDmaBuffers();
//
//	somevalue = vara4500004 / 4;
//	datastart = g_AudioManager.ACMDList[var8005cf90];
//	outbuffer = (s16 *) osVirtualToPhysical(info->data);
//
//	if (previnfo) {
//		osAiSetNextBuffer(previnfo->data, previnfo->framesamples * 4);
//	}
//
//	if (somevalue > 248 && var8005cf94 == 0) {
//		info->framesamples = var800918dc;
//		var8005cf94 = 2;
//	} else {
//		info->framesamples = var800918e0;
//
//		if (var8005cf94 != 0) {
//			var8005cf94--;
//		}
//	}
//
//	cmd = alAudioFrame(datastart, &var800918e8, outbuffer, info->framesamples);
//
//	task = &info->task;
//
//	task->next = NULL;
//	task->msgQ = &var80091848;
//	task->msg = info;
//	task->flags = OS_SC_NEEDS_RSP;
//	task->list.t.type = M_AUDTASK;
//	task->list.t.flags = 0;
//	task->list.t.ucode_boot = (u64 *) &rspbootTextStart;
//	task->list.t.ucode_boot_size = (u32) &rspbootTextEnd - (u32) &rspbootTextStart;
//	task->list.t.ucode = (u64 *) &aspMainTextStart;
//	task->list.t.ucode_data = (u64 *) &aspMainDataStart;
//	task->list.t.ucode_size = SP_UCODE_SIZE;
//	task->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
//	task->list.t.data_ptr = (u64 *) datastart;
//	task->list.t.data_size = (cmd - datastart) * sizeof(Acmd);
//	task->list.t.yield_data_ptr = NULL;
//	task->list.t.yield_data_size = 0;
//
//	var8005cf90 ^= 1;
//
//	g_AmgrCurrentCmdList = task;
//}

void amgrHandleDoneMsg(AudioInfo *info)
{
	static bool firsttime = true;

	if ((s32)osAiGetLength() >> 2 == 0 && firsttime == false) {
		firsttime = false;
	}
}
