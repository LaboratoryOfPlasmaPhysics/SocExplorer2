#pragma once
#define QT_ANNOTATE_ACCESS_SPECIFIER(a) __attribute__((annotate(#a)))

#include "../SocExplorerObject.hpp"
#include "../Soc/SocModule.hpp"
#include "PySocModule.hpp"
