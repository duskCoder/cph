/*
 * Copyright (c) 2015 <Olivier Gayot <duskcoder@gmail.com>
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgement in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

static const char *answer_yes = "y";
static const char *answer_no = "n";

static unsigned int seed_g;

static struct option options_g[] = {
    {
        .name = "yes",
        .has_arg = required_argument,
        .flag = NULL,
        .val = 'y',
    }, {
        .name = "no",
        .has_arg = required_argument,
        .flag = NULL,
        .val = 'n',
    }, {
        .name = 0,
        .has_arg = 0,
        .flag = NULL,
        .val = 0,
    }
};

static int parse_arguments(int *argcp, char *argv[])
{
    int opt;
    int ret = 0;

    while ((opt = getopt_long(*argcp, argv, "y:n:s:", options_g, NULL)) >= 0)
    {
        switch (opt) {
            case 'y':
                answer_yes = optarg;
                break;
            case 'n':
                answer_no = optarg;
                break;
            case '?':
                ret = -1;
                break;
            default:
                break;
        }
    }

    return ret;
}

int main(int argc, char *argv[])
{
    seed_g = time(NULL);
    if (parse_arguments(&argc, argv) < 0) {
        fprintf(stderr, "usage: %s [OPTIONS]\n", argv[0]);
        return -1;
    }

    srand(seed_g);

    for (;;) {
        switch (rand() % 2) {
            case 0:
                puts(answer_yes);
                break;
            case 1:
                puts(answer_no);
                break;
        }
    }

    return 0;
}
