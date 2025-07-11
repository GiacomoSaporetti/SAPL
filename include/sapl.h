#ifndef SAPL_H
#define SAPL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "string_utilities.h"
#include "parser.h"
#include "database.h"

#define MAX_LINE_LENGTH 100

#define TO_BITS(v) *((union var_data*) &v)

#define ErrorMsg(msg) printf("Error: %s\n", msg);

#endif