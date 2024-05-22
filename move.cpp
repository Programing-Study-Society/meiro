#include <stdio.h>
#include "main.h"

// ƒLƒƒƒ‰‚ÌˆÚ“®ˆ—
int move(int* x, int* y, int z, bool board[WIDTH][HEIGHT]) {
    int xy[2] = { *x, *y };

    // “ü—Í•ûŒü‚ÉˆÚ“®
    if (z == 1)
        xy[1]--;
    else if (z == 2)
        xy[1]++;
    else if (z == 3)
        xy[0]++;
    else if (z == 4)
        xy[0]--;

    // “ü—Í•ûŒü‚ÉˆÚ“®‰Â”\‚©”»’è
    if ((WIDTH > xy[0] && xy[0] > 0) && (HEIGHT > xy[1] && xy[1] > 0)) {
        // ˆÚ“®‰Â”\‚È‚çˆÚ“®
        if (board[xy[0]][xy[1]] == false) {
            *x = xy[0];
            *y = xy[1];
            return 1;
        }
    }

    return 0;
}