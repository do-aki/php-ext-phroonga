/**
 * phroonga: the PHP groonga extension
 *
 * @package     phroonga
 * @author      Ryusuke SEKIYAMA <rsky0711@gmail.com>
 * @copyright   2012 Ryusuke SEKIYAMA
 * @license     http://www.opensource.org/licenses/mit-license.php  MIT License
 */

#include "phroonga.h"

/* {{{ function prototypes */

static void prn_register_enum_rc(INIT_FUNC_ARGS);
static void prn_register_enum_encoding(INIT_FUNC_ARGS);
static void prn_register_enum_command_version(INIT_FUNC_ARGS);
static void prn_register_enum_log_level(INIT_FUNC_ARGS);
static void prn_register_enum_content_type(INIT_FUNC_ARGS);
static void prn_register_enum_builtin_type(INIT_FUNC_ARGS);
static void prn_register_enum_builtin_tokenizer(INIT_FUNC_ARGS);
static void prn_register_enum_proc_type(INIT_FUNC_ARGS);
static void prn_register_enum_operator(INIT_FUNC_ARGS);
static void prn_register_enum_info_type(INIT_FUNC_ARGS);
static void prn_register_enum_hook_entry(INIT_FUNC_ARGS);

static void prn_register_ctx_init_flags(INIT_FUNC_ARGS);
static void prn_register_table_cursor_open_flags(INIT_FUNC_ARGS);
static void prn_register_table_sort_flags(INIT_FUNC_ARGS);
static void prn_register_table_group_flags(INIT_FUNC_ARGS);
static void prn_register_obj_set_value_flags(INIT_FUNC_ARGS);
static void prn_register_snip_open_flags(INIT_FUNC_ARGS);
static void prn_register_logger_info_flags(INIT_FUNC_ARGS);
static void prn_register_obj_format_flags(INIT_FUNC_ARGS);
static void prn_register_expr_flags(INIT_FUNC_ARGS);
static void prn_register_ctx_cnnect_flags(INIT_FUNC_ARGS);

/* }}} */
/* {{{ prn_register_constants() */

#define PRN_REGISTER_CONSTANT(name) \
	REGISTER_LONG_CONSTANT(#name, name, CONST_PERSISTENT | CONST_CS)

PRN_LOCAL void prn_register_constants(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_ID_NIL);
	PRN_REGISTER_CONSTANT(GRN_ID_MAX);

	prn_register_enum_rc(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_encoding(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_command_version(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_log_level(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_content_type(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_builtin_type(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_builtin_tokenizer(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_proc_type(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_operator(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_info_type(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_enum_hook_entry(INIT_FUNC_ARGS_PASSTHRU);

	prn_register_ctx_init_flags(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_table_cursor_open_flags(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_table_sort_flags(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_table_group_flags(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_obj_set_value_flags(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_snip_open_flags(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_logger_info_flags(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_obj_format_flags(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_expr_flags(INIT_FUNC_ARGS_PASSTHRU);
	prn_register_ctx_cnnect_flags(INIT_FUNC_ARGS_PASSTHRU);
}

/* }}} */
/* {{{ prn_register_enum_rc() */

static void prn_register_enum_rc(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_SUCCESS);
	PRN_REGISTER_CONSTANT(GRN_END_OF_DATA);
	PRN_REGISTER_CONSTANT(GRN_UNKNOWN_ERROR);
	PRN_REGISTER_CONSTANT(GRN_OPERATION_NOT_PERMITTED);
	PRN_REGISTER_CONSTANT(GRN_NO_SUCH_FILE_OR_DIRECTORY);
	PRN_REGISTER_CONSTANT(GRN_NO_SUCH_PROCESS);
	PRN_REGISTER_CONSTANT(GRN_INTERRUPTED_FUNCTION_CALL);
	PRN_REGISTER_CONSTANT(GRN_INPUT_OUTPUT_ERROR);
	PRN_REGISTER_CONSTANT(GRN_NO_SUCH_DEVICE_OR_ADDRESS);
	PRN_REGISTER_CONSTANT(GRN_ARG_LIST_TOO_LONG);
	PRN_REGISTER_CONSTANT(GRN_EXEC_FORMAT_ERROR);
	PRN_REGISTER_CONSTANT(GRN_BAD_FILE_DESCRIPTOR);
	PRN_REGISTER_CONSTANT(GRN_NO_CHILD_PROCESSES);
	PRN_REGISTER_CONSTANT(GRN_RESOURCE_TEMPORARILY_UNAVAILABLE);
	PRN_REGISTER_CONSTANT(GRN_NOT_ENOUGH_SPACE);
	PRN_REGISTER_CONSTANT(GRN_PERMISSION_DENIED);
	PRN_REGISTER_CONSTANT(GRN_BAD_ADDRESS);
	PRN_REGISTER_CONSTANT(GRN_RESOURCE_BUSY);
	PRN_REGISTER_CONSTANT(GRN_FILE_EXISTS);
	PRN_REGISTER_CONSTANT(GRN_IMPROPER_LINK);
	PRN_REGISTER_CONSTANT(GRN_NO_SUCH_DEVICE);
	PRN_REGISTER_CONSTANT(GRN_NOT_A_DIRECTORY);
	PRN_REGISTER_CONSTANT(GRN_IS_A_DIRECTORY);
	PRN_REGISTER_CONSTANT(GRN_INVALID_ARGUMENT);
	PRN_REGISTER_CONSTANT(GRN_TOO_MANY_OPEN_FILES_IN_SYSTEM);
	PRN_REGISTER_CONSTANT(GRN_TOO_MANY_OPEN_FILES);
	PRN_REGISTER_CONSTANT(GRN_INAPPROPRIATE_I_O_CONTROL_OPERATION);
	PRN_REGISTER_CONSTANT(GRN_FILE_TOO_LARGE);
	PRN_REGISTER_CONSTANT(GRN_NO_SPACE_LEFT_ON_DEVICE);
	PRN_REGISTER_CONSTANT(GRN_INVALID_SEEK);
	PRN_REGISTER_CONSTANT(GRN_READ_ONLY_FILE_SYSTEM);
	PRN_REGISTER_CONSTANT(GRN_TOO_MANY_LINKS);
	PRN_REGISTER_CONSTANT(GRN_BROKEN_PIPE);
	PRN_REGISTER_CONSTANT(GRN_DOMAIN_ERROR);
	PRN_REGISTER_CONSTANT(GRN_RESULT_TOO_LARGE);
	PRN_REGISTER_CONSTANT(GRN_RESOURCE_DEADLOCK_AVOIDED);
	PRN_REGISTER_CONSTANT(GRN_NO_MEMORY_AVAILABLE);
	PRN_REGISTER_CONSTANT(GRN_FILENAME_TOO_LONG);
	PRN_REGISTER_CONSTANT(GRN_NO_LOCKS_AVAILABLE);
	PRN_REGISTER_CONSTANT(GRN_FUNCTION_NOT_IMPLEMENTED);
	PRN_REGISTER_CONSTANT(GRN_DIRECTORY_NOT_EMPTY);
	PRN_REGISTER_CONSTANT(GRN_ILLEGAL_BYTE_SEQUENCE);
	PRN_REGISTER_CONSTANT(GRN_SOCKET_NOT_INITIALIZED);
	PRN_REGISTER_CONSTANT(GRN_OPERATION_WOULD_BLOCK);
	PRN_REGISTER_CONSTANT(GRN_ADDRESS_IS_NOT_AVAILABLE);
	PRN_REGISTER_CONSTANT(GRN_NETWORK_IS_DOWN);
	PRN_REGISTER_CONSTANT(GRN_NO_BUFFER);
	PRN_REGISTER_CONSTANT(GRN_SOCKET_IS_ALREADY_CONNECTED);
	PRN_REGISTER_CONSTANT(GRN_SOCKET_IS_NOT_CONNECTED);
	PRN_REGISTER_CONSTANT(GRN_SOCKET_IS_ALREADY_SHUTDOWNED);
	PRN_REGISTER_CONSTANT(GRN_OPERATION_TIMEOUT);
	PRN_REGISTER_CONSTANT(GRN_CONNECTION_REFUSED);
	PRN_REGISTER_CONSTANT(GRN_RANGE_ERROR);
	PRN_REGISTER_CONSTANT(GRN_TOKENIZER_ERROR);
	PRN_REGISTER_CONSTANT(GRN_FILE_CORRUPT);
	PRN_REGISTER_CONSTANT(GRN_INVALID_FORMAT);
	PRN_REGISTER_CONSTANT(GRN_OBJECT_CORRUPT);
	PRN_REGISTER_CONSTANT(GRN_TOO_MANY_SYMBOLIC_LINKS);
	PRN_REGISTER_CONSTANT(GRN_NOT_SOCKET);
	PRN_REGISTER_CONSTANT(GRN_OPERATION_NOT_SUPPORTED);
	PRN_REGISTER_CONSTANT(GRN_ADDRESS_IS_IN_USE);
	PRN_REGISTER_CONSTANT(GRN_ZLIB_ERROR);
	PRN_REGISTER_CONSTANT(GRN_LZO_ERROR);
	PRN_REGISTER_CONSTANT(GRN_STACK_OVER_FLOW);
	PRN_REGISTER_CONSTANT(GRN_SYNTAX_ERROR);
	PRN_REGISTER_CONSTANT(GRN_RETRY_MAX);
	PRN_REGISTER_CONSTANT(GRN_INCOMPATIBLE_FILE_FORMAT);
	PRN_REGISTER_CONSTANT(GRN_UPDATE_NOT_ALLOWED);
	PRN_REGISTER_CONSTANT(GRN_TOO_SMALL_OFFSET);
	PRN_REGISTER_CONSTANT(GRN_TOO_LARGE_OFFSET);
	PRN_REGISTER_CONSTANT(GRN_TOO_SMALL_LIMIT);
	PRN_REGISTER_CONSTANT(GRN_CAS_ERROR);
	PRN_REGISTER_CONSTANT(GRN_UNSUPPORTED_COMMAND_VERSION);
}

/* }}} */
/* {{{ prn_register_enum_encoding() */

static void prn_register_enum_encoding(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_ENC_DEFAULT);
	PRN_REGISTER_CONSTANT(GRN_ENC_NONE);
	PRN_REGISTER_CONSTANT(GRN_ENC_EUC_JP);
	PRN_REGISTER_CONSTANT(GRN_ENC_UTF8);
	PRN_REGISTER_CONSTANT(GRN_ENC_SJIS);
	PRN_REGISTER_CONSTANT(GRN_ENC_LATIN1);
	PRN_REGISTER_CONSTANT(GRN_ENC_KOI8R);
}

/* }}} */
/* {{{ prn_register_enum_command_version() */

static void prn_register_enum_command_version(INIT_FUNC_ARGS)
{
	/* enum members */
	PRN_REGISTER_CONSTANT(GRN_COMMAND_VERSION_DEFAULT);
	PRN_REGISTER_CONSTANT(GRN_COMMAND_VERSION_1);
	PRN_REGISTER_CONSTANT(GRN_COMMAND_VERSION_2);
	/* aliases */
	PRN_REGISTER_CONSTANT(GRN_COMMAND_VERSION_MIN);
	PRN_REGISTER_CONSTANT(GRN_COMMAND_VERSION_STABLE);
	PRN_REGISTER_CONSTANT(GRN_COMMAND_VERSION_MAX);
}

/* }}} */
/* {{{ prn_register_enum_log_level() */

static void prn_register_enum_log_level(INIT_FUNC_ARGS)
{
	/* enum members */
	PRN_REGISTER_CONSTANT(GRN_LOG_NONE);
	PRN_REGISTER_CONSTANT(GRN_LOG_EMERG);
	PRN_REGISTER_CONSTANT(GRN_LOG_ALERT);
	PRN_REGISTER_CONSTANT(GRN_LOG_CRIT);
	PRN_REGISTER_CONSTANT(GRN_LOG_ERROR);
	PRN_REGISTER_CONSTANT(GRN_LOG_WARNING);
	PRN_REGISTER_CONSTANT(GRN_LOG_NOTICE);
	PRN_REGISTER_CONSTANT(GRN_LOG_INFO);
	PRN_REGISTER_CONSTANT(GRN_LOG_DEBUG);
	PRN_REGISTER_CONSTANT(GRN_LOG_DUMP);
	/* aliases */
	PRN_REGISTER_CONSTANT(GRN_LOG_DEFAULT_LEVEL);
}

/* }}} */
/* {{{ prn_register_enum_content_type() */

static void prn_register_enum_content_type(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_CONTENT_NONE);
	PRN_REGISTER_CONSTANT(GRN_CONTENT_TSV);
	PRN_REGISTER_CONSTANT(GRN_CONTENT_JSON);
	PRN_REGISTER_CONSTANT(GRN_CONTENT_XML);
	PRN_REGISTER_CONSTANT(GRN_CONTENT_MSGPACK);
}

/* }}} */
/* {{{ prn_register_enum_builtin_type() */

static void prn_register_enum_builtin_type(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_DB_VOID);
	PRN_REGISTER_CONSTANT(GRN_DB_DB);
	PRN_REGISTER_CONSTANT(GRN_DB_OBJECT);
	PRN_REGISTER_CONSTANT(GRN_DB_BOOL);
	PRN_REGISTER_CONSTANT(GRN_DB_INT8);
	PRN_REGISTER_CONSTANT(GRN_DB_UINT8);
	PRN_REGISTER_CONSTANT(GRN_DB_INT16);
	PRN_REGISTER_CONSTANT(GRN_DB_UINT16);
	PRN_REGISTER_CONSTANT(GRN_DB_INT32);
	PRN_REGISTER_CONSTANT(GRN_DB_UINT32);
	PRN_REGISTER_CONSTANT(GRN_DB_INT64);
	PRN_REGISTER_CONSTANT(GRN_DB_UINT64);
	PRN_REGISTER_CONSTANT(GRN_DB_FLOAT);
	PRN_REGISTER_CONSTANT(GRN_DB_TIME);
	PRN_REGISTER_CONSTANT(GRN_DB_SHORT_TEXT);
	PRN_REGISTER_CONSTANT(GRN_DB_TEXT);
	PRN_REGISTER_CONSTANT(GRN_DB_LONG_TEXT);
	PRN_REGISTER_CONSTANT(GRN_DB_TOKYO_GEO_POINT);
	PRN_REGISTER_CONSTANT(GRN_DB_WGS84_GEO_POINT);
}

/* }}} */
/* {{{ prn_register_enum_builtin_tokenizer() */

static void prn_register_enum_builtin_tokenizer(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_DB_MECAB);
	PRN_REGISTER_CONSTANT(GRN_DB_DELIMIT);
	PRN_REGISTER_CONSTANT(GRN_DB_UNIGRAM);
	PRN_REGISTER_CONSTANT(GRN_DB_BIGRAM);
	PRN_REGISTER_CONSTANT(GRN_DB_TRIGRAM);
}

/* }}} */
/* {{{ prn_register_enum_proc_type() */

static void prn_register_enum_proc_type(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_PROC_TOKENIZER);
	PRN_REGISTER_CONSTANT(GRN_PROC_COMMAND);
	PRN_REGISTER_CONSTANT(GRN_PROC_FUNCTION);
	PRN_REGISTER_CONSTANT(GRN_PROC_HOOK);
}

/* }}} */
/* {{{ prn_register_enum_operator() */

static void prn_register_enum_operator(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_OP_PUSH);
	PRN_REGISTER_CONSTANT(GRN_OP_POP);
	PRN_REGISTER_CONSTANT(GRN_OP_NOP);
	PRN_REGISTER_CONSTANT(GRN_OP_CALL);
	PRN_REGISTER_CONSTANT(GRN_OP_INTERN);
	PRN_REGISTER_CONSTANT(GRN_OP_GET_REF);
	PRN_REGISTER_CONSTANT(GRN_OP_GET_VALUE);
	PRN_REGISTER_CONSTANT(GRN_OP_AND);
	PRN_REGISTER_CONSTANT(GRN_OP_AND_NOT);
	PRN_REGISTER_CONSTANT(GRN_OP_OR);
	PRN_REGISTER_CONSTANT(GRN_OP_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_STAR_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_SLASH_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_MOD_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_PLUS_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_MINUS_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_SHIFTL_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_SHIFTR_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_SHIFTRR_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_AND_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_XOR_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_OR_ASSIGN);
	PRN_REGISTER_CONSTANT(GRN_OP_JUMP);
	PRN_REGISTER_CONSTANT(GRN_OP_CJUMP);
	PRN_REGISTER_CONSTANT(GRN_OP_COMMA);
	PRN_REGISTER_CONSTANT(GRN_OP_BITWISE_OR);
	PRN_REGISTER_CONSTANT(GRN_OP_BITWISE_XOR);
	PRN_REGISTER_CONSTANT(GRN_OP_BITWISE_AND);
	PRN_REGISTER_CONSTANT(GRN_OP_BITWISE_NOT);
	PRN_REGISTER_CONSTANT(GRN_OP_EQUAL);
	PRN_REGISTER_CONSTANT(GRN_OP_NOT_EQUAL);
	PRN_REGISTER_CONSTANT(GRN_OP_LESS);
	PRN_REGISTER_CONSTANT(GRN_OP_GREATER);
	PRN_REGISTER_CONSTANT(GRN_OP_LESS_EQUAL);
	PRN_REGISTER_CONSTANT(GRN_OP_GREATER_EQUAL);
	PRN_REGISTER_CONSTANT(GRN_OP_IN);
	PRN_REGISTER_CONSTANT(GRN_OP_MATCH);
	PRN_REGISTER_CONSTANT(GRN_OP_NEAR);
	PRN_REGISTER_CONSTANT(GRN_OP_NEAR2);
	PRN_REGISTER_CONSTANT(GRN_OP_SIMILAR);
	PRN_REGISTER_CONSTANT(GRN_OP_TERM_EXTRACT);
	PRN_REGISTER_CONSTANT(GRN_OP_SHIFTL);
	PRN_REGISTER_CONSTANT(GRN_OP_SHIFTR);
	PRN_REGISTER_CONSTANT(GRN_OP_SHIFTRR);
	PRN_REGISTER_CONSTANT(GRN_OP_PLUS);
	PRN_REGISTER_CONSTANT(GRN_OP_MINUS);
	PRN_REGISTER_CONSTANT(GRN_OP_STAR);
	PRN_REGISTER_CONSTANT(GRN_OP_SLASH);
	PRN_REGISTER_CONSTANT(GRN_OP_MOD);
	PRN_REGISTER_CONSTANT(GRN_OP_DELETE);
	PRN_REGISTER_CONSTANT(GRN_OP_INCR);
	PRN_REGISTER_CONSTANT(GRN_OP_DECR);
	PRN_REGISTER_CONSTANT(GRN_OP_INCR_POST);
	PRN_REGISTER_CONSTANT(GRN_OP_DECR_POST);
	PRN_REGISTER_CONSTANT(GRN_OP_NOT);
	PRN_REGISTER_CONSTANT(GRN_OP_ADJUST);
	PRN_REGISTER_CONSTANT(GRN_OP_EXACT);
	PRN_REGISTER_CONSTANT(GRN_OP_LCP);
	PRN_REGISTER_CONSTANT(GRN_OP_PARTIAL);
	PRN_REGISTER_CONSTANT(GRN_OP_UNSPLIT);
	PRN_REGISTER_CONSTANT(GRN_OP_PREFIX);
	PRN_REGISTER_CONSTANT(GRN_OP_SUFFIX);
	PRN_REGISTER_CONSTANT(GRN_OP_GEO_DISTANCE1);
	PRN_REGISTER_CONSTANT(GRN_OP_GEO_DISTANCE2);
	PRN_REGISTER_CONSTANT(GRN_OP_GEO_DISTANCE3);
	PRN_REGISTER_CONSTANT(GRN_OP_GEO_DISTANCE4);
	PRN_REGISTER_CONSTANT(GRN_OP_GEO_WITHINP5);
	PRN_REGISTER_CONSTANT(GRN_OP_GEO_WITHINP6);
	PRN_REGISTER_CONSTANT(GRN_OP_GEO_WITHINP8);
	PRN_REGISTER_CONSTANT(GRN_OP_OBJ_SEARCH);
	PRN_REGISTER_CONSTANT(GRN_OP_EXPR_GET_VAR);
	PRN_REGISTER_CONSTANT(GRN_OP_TABLE_CREATE);
	PRN_REGISTER_CONSTANT(GRN_OP_TABLE_SELECT);
	PRN_REGISTER_CONSTANT(GRN_OP_TABLE_SORT);
	PRN_REGISTER_CONSTANT(GRN_OP_TABLE_GROUP);
	PRN_REGISTER_CONSTANT(GRN_OP_JSON_PUT);
}

/* }}} */
/* {{{ prn_register_enum_info_type() */

static void prn_register_enum_info_type(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_INFO_ENCODING);
	PRN_REGISTER_CONSTANT(GRN_INFO_SOURCE);
	PRN_REGISTER_CONSTANT(GRN_INFO_DEFAULT_TOKENIZER);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_SIZE);
	PRN_REGISTER_CONSTANT(GRN_INFO_CURR_MAX);
	PRN_REGISTER_CONSTANT(GRN_INFO_MAX_ELEMENT_SIZE);
	PRN_REGISTER_CONSTANT(GRN_INFO_SEG_SIZE);
	PRN_REGISTER_CONSTANT(GRN_INFO_CHUNK_SIZE);
	PRN_REGISTER_CONSTANT(GRN_INFO_MAX_SECTION);
	PRN_REGISTER_CONSTANT(GRN_INFO_HOOK_LOCAL_DATA);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_A);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_CHUNK);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_CHUNK_SIZE);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_BUFFER_FREE);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_NTERMS);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_NTERMS_VOID);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_SIZE_IN_CHUNK);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_POS_IN_CHUNK);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_SIZE_IN_BUFFER);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_POS_IN_BUFFER);
	PRN_REGISTER_CONSTANT(GRN_INFO_ELEMENT_ESTIMATE_SIZE);
	PRN_REGISTER_CONSTANT(GRN_INFO_NGRAM_UNIT_SIZE);
	/*
	PRN_REGISTER_CONSTANT(GRN_INFO_VERSION);
	PRN_REGISTER_CONSTANT(GRN_INFO_CONFIGURE_OPTIONS);
	PRN_REGISTER_CONSTANT(GRN_INFO_CONFIG_PATH);
	*/
	PRN_REGISTER_CONSTANT(GRN_INFO_PARTIAL_MATCH_THRESHOLD);
	PRN_REGISTER_CONSTANT(GRN_INFO_II_SPLIT_THRESHOLD);
	PRN_REGISTER_CONSTANT(GRN_INFO_SUPPORT_ZLIB);
	PRN_REGISTER_CONSTANT(GRN_INFO_SUPPORT_LZO);
}

/* }}} */
/* {{{ prn_register_enum_hook_entry() */

static void prn_register_enum_hook_entry(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_HOOK_SET);
	PRN_REGISTER_CONSTANT(GRN_HOOK_GET);
	PRN_REGISTER_CONSTANT(GRN_HOOK_INSERT);
	PRN_REGISTER_CONSTANT(GRN_HOOK_DELETE);
	PRN_REGISTER_CONSTANT(GRN_HOOK_SELECT);
}

/* }}} */
/* {{{ prn_register_ctx_init_flags() */

static void prn_register_ctx_init_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_CTX_USE_QL);
	PRN_REGISTER_CONSTANT(GRN_CTX_BATCH_MODE);
	PRN_REGISTER_CONSTANT(GRN_CTX_PER_DB);
}

/* }}} */
/* {{{ prn_register_table_cursor_open_flags() */

static void prn_register_table_cursor_open_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_CURSOR_ASCENDING);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_DESCENDING);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_GE);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_GT);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_LE);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_LT);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_BY_KEY);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_BY_ID);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_PREFIX);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_SIZE_BY_BIT);
	PRN_REGISTER_CONSTANT(GRN_CURSOR_RK);
}

/* }}} */
/* {{{ prn_register_table_sort_flags() */

static void prn_register_table_sort_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_TABLE_SORT_ASC);
	PRN_REGISTER_CONSTANT(GRN_TABLE_SORT_DESC);
}

/* }}} */
/* {{{ prn_register_table_group_flags() */

static void prn_register_table_group_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_TABLE_GROUP_CALC_COUNT);
	PRN_REGISTER_CONSTANT(GRN_TABLE_GROUP_CALC_MAX);
	PRN_REGISTER_CONSTANT(GRN_TABLE_GROUP_CALC_MIN);
	PRN_REGISTER_CONSTANT(GRN_TABLE_GROUP_CALC_SUM);
	PRN_REGISTER_CONSTANT(GRN_TABLE_GROUP_CALC_AVG);
}

/* }}} */
/* {{{ prn_register_obj_set_value_flags() */

static void prn_register_obj_set_value_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_OBJ_SET_MASK);
	PRN_REGISTER_CONSTANT(GRN_OBJ_SET);
	PRN_REGISTER_CONSTANT(GRN_OBJ_INCR);
	PRN_REGISTER_CONSTANT(GRN_OBJ_DECR);
	PRN_REGISTER_CONSTANT(GRN_OBJ_APPEND);
	PRN_REGISTER_CONSTANT(GRN_OBJ_PREPEND);
	PRN_REGISTER_CONSTANT(GRN_OBJ_GET);
	PRN_REGISTER_CONSTANT(GRN_OBJ_COMPARE);
	PRN_REGISTER_CONSTANT(GRN_OBJ_LOCK);
	PRN_REGISTER_CONSTANT(GRN_OBJ_UNLOCK);
}

/* }}} */
/* {{{ prn_register_snip_open_flags() */

static void prn_register_snip_open_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_SNIP_NORMALIZE);
	PRN_REGISTER_CONSTANT(GRN_SNIP_COPY_TAG);
	PRN_REGISTER_CONSTANT(GRN_SNIP_SKIP_LEADING_SPACES);
}

/* }}} */
/* {{{ prn_register_logger_info_flags() */

static void prn_register_logger_info_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_LOG_TIME);
	PRN_REGISTER_CONSTANT(GRN_LOG_TITLE);
	PRN_REGISTER_CONSTANT(GRN_LOG_MESSAGE);
	PRN_REGISTER_CONSTANT(GRN_LOG_LOCATION);
}

/* }}} */
/* {{{ prn_register_obj_format_flags() */

static void prn_register_obj_format_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_OBJ_FORMAT_WITH_COLUMN_NAMES);
	PRN_REGISTER_CONSTANT(GRN_OBJ_FORMAT_ASARRAY);
}

/* }}} */
/* {{{ prn_register_expr_flags() */

static void prn_register_expr_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_EXPR_SYNTAX_QUERY);
	PRN_REGISTER_CONSTANT(GRN_EXPR_SYNTAX_SCRIPT);
	PRN_REGISTER_CONSTANT(GRN_EXPR_SYNTAX_OUTPUT_COLUMNS);
	PRN_REGISTER_CONSTANT(GRN_EXPR_ALLOW_PRAGMA);
	PRN_REGISTER_CONSTANT(GRN_EXPR_ALLOW_COLUMN);
	PRN_REGISTER_CONSTANT(GRN_EXPR_ALLOW_UPDATE);
	PRN_REGISTER_CONSTANT(GRN_EXPR_ALLOW_LEADING_NOT);
}

/* }}} */
/* {{{ prn_register_ctx_cnnect_flags() */

static void prn_register_ctx_cnnect_flags(INIT_FUNC_ARGS)
{
	PRN_REGISTER_CONSTANT(GRN_CTX_MORE);
	PRN_REGISTER_CONSTANT(GRN_CTX_TAIL);
	PRN_REGISTER_CONSTANT(GRN_CTX_HEAD);
	PRN_REGISTER_CONSTANT(GRN_CTX_QUIET);
	PRN_REGISTER_CONSTANT(GRN_CTX_QUIT);
}

/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
