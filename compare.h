#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>
#include <assert.h>


char** string_split(const char* in, const char d);

void free_string_array(char **nodes);

#define DEBUG printf
#define TRACE printf
#define __u64 long long

#define true 1
#define false 0
#define bool _Bool

#define BANNER "SWUpdate v" SWU_VER "\n"

#define SWUPDATE_GENERAL_STRING_SIZE	256
#define SWUPDATE_UPDATE_DESCRIPTION_STRING_SIZE	512
#define MAX_IMAGE_FNAME	SWUPDATE_GENERAL_STRING_SIZE
#define MAX_URL		SWUPDATE_GENERAL_STRING_SIZE
#define MAX_VOLNAME	SWUPDATE_GENERAL_STRING_SIZE
#define MAX_HW_VERSIONS	10
#define MAX_LINE	80
#define BOOTLOADER_VAR_LENGTH 16
#define MAX_REVISION_LENGTH	SWUPDATE_GENERAL_STRING_SIZE
#define MAX_BOOT_SCRIPT_LINE_LENGTH	1024
#define MAX_SEEK_STRING_SIZE	32

/*
 * swupdate uses SHA256 hashes
 */
#define SHA256_HASH_LENGTH	32

/* These are fixed path to temporary files */
#define SCRIPTS_DIR_SUFFIX	"scripts/"
#define DATADST_DIR_SUFFIX	"datadst/"
#define BOOT_SCRIPT_SUFFIX	"boot-script"
