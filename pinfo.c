#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "mmu.h"
#include "param.h"
#include "proc.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf(2,"Usage: pinfo <pid>");
    }
    else
    {
        struct proc_stat p;
        p.pid = -1;
        p.num_run = -1;
        p.runtime = -1;
        if (getpinfo(&p, atoi(argv[1])) < 0)
            printf(1, "No such process\n");
        else
            printf(1, "pid=%d\nruntime=%d\nnum_run=%d\n", p.pid, p.runtime, p.num_run);
    }
    exit();
}