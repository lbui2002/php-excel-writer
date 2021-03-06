/*
  +----------------------------------------------------------------------+
  | Vtiful Extension                                                     |
  +----------------------------------------------------------------------+
  | Copyright (c) 2017-2017 The Viest                                    |
  +----------------------------------------------------------------------+
  | http://www.viest.me                                                  |
  +----------------------------------------------------------------------+
  | Author: viest <dev@service.viest.me>                                 |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_VTIFUL_H
#define PHP_VTIFUL_H

extern zend_module_entry vtiful_module_entry;
#define phpext_vtiful_ptr &vtiful_module_entry

#define PHP_VTIFUL_VERSION "1.0.0"

#ifdef PHP_WIN32
#	define PHP_VTIFUL_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_VTIFUL_API __attribute__ ((visibility("default")))
#else
#	define PHP_VTIFUL_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#define VTIFUL_RESOURCE_NAME "vtiful"

extern int le_vtiful;

#define VTIFUL_STARTUP_MODULE(module) ZEND_MODULE_STARTUP_N(vtiful_##module)(INIT_FUNC_ARGS_PASSTHRU)
#define VTIFUL_STARTUP_FUNCTION(module) ZEND_MINIT_FUNCTION(vtiful_##module)
#define VTIFUL_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(vtiful, v)

void _php_vtiful_excel_close(zend_resource *rsrc TSRMLS_DC);

#if defined(ZTS) && defined(COMPILE_DL_VTIFUL)
ZEND_TSRMLS_CACHE_EXTERN();
#endif

PHP_MINIT_FUNCTION(vtiful);
PHP_MSHUTDOWN_FUNCTION(vtiful);
PHP_RINIT_FUNCTION(vtiful);
PHP_RSHUTDOWN_FUNCTION(vtiful);
PHP_MINFO_FUNCTION(vtiful);

#endif


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
