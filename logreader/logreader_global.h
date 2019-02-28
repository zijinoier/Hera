#ifndef LOGREADER_GLOBAL_H
#define LOGREADER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LOGREADER_LIBRARY)
#  define LOGREADERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LOGREADERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGREADER_GLOBAL_H
