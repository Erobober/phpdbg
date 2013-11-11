/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2013 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Joe Watkins <joe.watkins@live.co.uk>                        |
   +----------------------------------------------------------------------+
*/

#ifndef PHPDBG_H
#define PHPDBG_H

#include "php.h"
#include "php_globals.h"
#include "php_variables.h"
#include "php_getopt.h"
#include "zend_builtin_functions.h"
#include "zend_extensions.h"
#include "zend_modules.h"
#include "zend_globals.h"
#include "zend_ini_scanner.h"
#include "zend_stream.h"
#include "SAPI.h"
#include <php_config.h>
#include "php_main.h"

#ifdef ZTS
# include "TSRM.h"
#endif

#ifdef ZTS
# define PHPDBG_G(v) TSRMG(phpdbg_globals_id, zend_phpdbg_globals *, v)
#else
# define PHPDBG_G(v) (phpdbg_globals.v)
#endif

#define PHPDBG_NEXT 2

typedef struct _phpdbg_command_t phpdbg_command_t;

ZEND_BEGIN_MODULE_GLOBALS(phpdbg)
	HashTable bp_files;
	HashTable bp_symbols;
	HashTable bp_oplines;
	char *exec;                 /* file to execute */
	size_t exec_len;            /* size of exec */
	zend_op_array *ops;         /* op_array */
	zval *retval;               /* return value */
	int bp_count;               /* breakpoint count */
	int stepping;               /* stepping */
	int vmret;                  /* return from last opcode handler execution */
	zend_bool has_file_bp;      /* file-based breakpoint has been set */
	zend_bool has_sym_bp;       /* symbol-based breakpoint has been set */
	zend_bool has_opline_bp;    /* opline-based breakpoint has been set */
	zend_bool quitting;         /* quitting flag */
	int quiet;                  /* quiet */
	phpdbg_command_t *last;     /* last command */
	const char *last_params;    /* last expression */
	size_t last_params_len;     /* last expression length */
ZEND_END_MODULE_GLOBALS(phpdbg)

#endif /* PHPDBG_H */