#include <nds.h>
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
