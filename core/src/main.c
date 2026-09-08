#include <nds.h>
#include <nds/arm9/video.h>
#include <nds/arm9/background.h>

int main(void)
{
    while (1)
    {
        swiWaitForVBlank();
    }

    return 0;
}
