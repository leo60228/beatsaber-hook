#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <linux/limits.h>
#include <sys/sendfile.h>
#include <sys/stat.h>



#include "../shared/inline-hook/inlineHook.h"
#include "../shared/utils/utils.h"

#define ASSETS_PATH "/data/app/com.beatgames.beatsaber-1/base.apk/assets/bin/Data/"
#define ASSETS_FAKE_PATH "/sdcard/Android/data/com.beatgames.beatsaber/files/redirected_assets/"




MAKE_HOOK_NAT(open_nat, open, int, char* path, int oflag, mode_t mode)
{
    //log("Opened file at %s\n", path)
    return open_nat(path, oflag, mode);
}


__attribute__((constructor)) void lib_main()
{
    log("sample-plugin loaded!");
    INSTALL_HOOK_NAT(open_nat);
}