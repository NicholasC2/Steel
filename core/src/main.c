#include <nds.h>
#include <nds/arm9/console.h>
#include <nds/arm9/video.h>
// #include <fs/zip.h>
#include <fat.h>
#include <dirent.h>
#include <string.h>

// #include <config.h>
// #include <gfx/theme.h>
#include <defs.h>

#include <stdio.h>

// #include "bg-bottom.h"

struct dirent **fileList;
int fileCount;
int selectedFile = 0;
const char* currentDir = "/";

int changeDir(const char* dir) {
    fileCount = scandir(dir, &fileList, NULL, alphasort);
    if (fileCount < 0) {
        return fileCount;
    }
    return 0;
}

void printDir(struct dirent** fileList, int fileCount, int selectedFile) {
	consoleClear();
	iprintf("Steel for DS Version 1.0.\n");
	iprintf("Path: %s\n", currentDir);
	for (int i = 0; i < fileCount; i++) {
		if(selectedFile == i) {
			iprintf("> %s\n", fileList[i]->d_name);
		} else {
			iprintf("  %s\n", fileList[i]->d_name);
		}
	}
}

int main(void)
{
    consoleDemoInit();
	fatInitDefault();

	// videoSetMode(MODE_5_2D);
    // vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	if(changeDir(currentDir) != 0) return 0;
	printDir(fileList, fileCount, selectedFile);

    while (1) {
		scanKeys();
		if (keysDown() & KEY_UP) {
			if(selectedFile > 0) {
				if(changeDir(currentDir) != 0) return 0;
				selectedFile -= 1;
				printDir(fileList, fileCount, selectedFile);
			}
		}
		if (keysDown() & KEY_DOWN) {
			if(selectedFile < fileCount - 1) {
				if(changeDir(currentDir) != 0) return 0;
				selectedFile += 1;
				printDir(fileList, fileCount, selectedFile);
			}
		}
		if (keysDown() & KEY_A) {
			if(fileList[selectedFile]->d_type == DT_DIR) {
				currentDir = strcat(currentDir, strcat(fileList[selectedFile]->d_name, "/"));
				currentDir = (currentDir);
				if(changeDir(currentDir) != 0) return 0;
				selectedFile = 0;
				printDir(fileList, fileCount, selectedFile);
			}
		}
		swiWaitForVBlank();
	}

	// int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);

	// dmaCopy(bg_bottomBitmap, bgGetGfxPtr(bg3), 256*256);
	// dmaCopy(bg_bottomPal, BG_PALETTE, 256*2);

	return 0;
}
