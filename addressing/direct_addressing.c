
#include <stdio.h>

#include "direct_addressing.h"

extern ic;


void run_direct_addressing(InstructionCount *ic, ParsedCommand *ppc, BitsCommand *pbc, int are, ReadingTwoList **rtl) {

    /**FIRST*/

    int i = 0;

    /**First command**/
    assign_first_command(ppc, pbc, are);


    /**SECOND**/
    /**address of the label - second reading**/
    if (ppc->args_num == 1) {
        add_second_reading_line(rtl, ppc->dst, ppc,NULL, pbc + 1, ic->row + 1);

    } else if (ppc->args_num == 2) {
        add_second_reading_line(rtl, ppc->src, ppc, NULL,pbc + 1, ic->row + 1);
        add_second_reading_line(rtl, ppc->dst, ppc, NULL,pbc + 2, ic->row + 2);
    }

    for (; i < ppc->args_num + 1; i++) {
        /**Write the command to the bin file**/
        write_command_to_file(ic, pbc + i, BIN_FILENAME);
        ic->dc++;
        ic->row = START_ROW_NUM + ic->dc + ic->ic;
    }
}