#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(KWIDGET_LIB)
#  define KWIDGET_EXPORT Q_DECL_EXPORT
# else
#  define KWIDGET_EXPORT Q_DECL_IMPORT
# endif
#else
# define KWIDGET_EXPORT
#endif
