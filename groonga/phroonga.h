/**
 * phroonga: the PHP groonga extension
 *
 * @package     phroonga
 * @author      Ryusuke SEKIYAMA <rsky0711@gmail.com>
 * @copyright   2012 Ryusuke SEKIYAMA
 * @license     http://www.opensource.org/licenses/mit-license.php  MIT License
 */

#ifndef PHROONGA_H
#define PHROONGA_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <stdint.h>
#include <groonga.h>

#define PHROONGA_VERSION "0.0.1"

BEGIN_EXTERN_C()

/* {{{ module globals */

ZEND_BEGIN_MODULE_GLOBALS(groonga)
	HashTable addr_id_map;
ZEND_END_MODULE_GLOBALS(groonga)

ZEND_EXTERN_MODULE_GLOBALS(groonga)

#ifdef ZTS
#define PRNG(v) TSRMG(groonga_globals_id, zend_groonga_globals *, v)
#else
#define PRNG(v) (groonga_globals.v)
#endif

/* }}} */
/* {{{ resource API */

PHPAPI int prn_get_le_ctx(void);
PHPAPI grn_ctx *prn_ctx_fetch(zval *zv TSRMLS_DC);

PHPAPI int prn_get_le_obj(void);
PHPAPI grn_obj *prn_obj_fetch(zval *zv TSRMLS_DC);

PHPAPI int prn_get_le_snip(void);
PHPAPI grn_snip *prn_snip_fetch(zval *zv TSRMLS_DC);

PHPAPI int prn_get_le_hash(void);
PHPAPI int prn_get_le_hash_cursor(void);
PHPAPI grn_hash *prn_hash_fetch(zval *zv TSRMLS_DC);
PHPAPI grn_hash_cursor *prn_hash_cursor_fetch(zval *zv TSRMLS_DC);

PHPAPI int prn_get_le_array(void);
PHPAPI int prn_get_le_array_cursor(void);
PHPAPI grn_array *prn_array_fetch(zval *zv TSRMLS_DC);
PHPAPI grn_array_cursor *prn_array_cursor_fetch(zval *zv TSRMLS_DC);

PHPAPI int prn_get_le_pat(void);
PHPAPI int prn_get_le_pat_cursor(void);
PHPAPI grn_pat *prn_pat_fetch(zval *zv TSRMLS_DC);
PHPAPI grn_pat_cursor *prn_pat_cursor_fetch(zval *zv TSRMLS_DC);

PHPAPI int prn_get_le_dat(void);
PHPAPI int prn_get_le_dat_cursor(void);
PHPAPI grn_dat *prn_dat_fetch(zval *zv TSRMLS_DC);
PHPAPI grn_dat_cursor *prn_dat_cursor_fetch(zval *zv TSRMLS_DC);

/* }}} */
/* {{{ miscellanous API */

PHPAPI const char *prn_errstr(grn_rc rc);
PHPAPI const char *prn_obj_type_name(grn_obj *obj);

/* }}} */

END_EXTERN_C()

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */