#include <nds.h>
#include <nds/arm9/console.h>
#include <nds/interrupts.h>
#include <stdio.h>

int main(void)
{
    consoleDemoInit();

    iprintf("Hello, World!\n");
    iprintf("Steel for DS\n");
    iprintf("Version 1.0\n");

    while (1) {
        swiWaitForVBlank();
    }

    return 0;
}
