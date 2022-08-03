#include <stdlib.h>
#include "PrintCMake/PrintCMake.h"
#include "UseAnother/Another.h"
#include "UseGLFW/UseGLFW.h"

int main()
{
    // use component Hello
    PrintCMake();

    // use component Another
    Another* another = new Another();
    another->HasDir();

    // use libraries glfw & glad
    InitGLFW();

    system("pause");
    return 0;
}