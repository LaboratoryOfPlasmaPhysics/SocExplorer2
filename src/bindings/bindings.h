#pragma once
#define QT_ANNOTATE_ACCESS_SPECIFIER(a) __attribute__((annotate(#a)))

#include "../SocExplorerObject.hpp"
#include "../Workspaces/Workspace.hpp"
#include "../Workspaces/WorkspacesManager.hpp"
#include "../Soc/SocModule.hpp"
#include "../Soc/Soc.hpp"
#include "../Factory/SocExplorerFactory.hpp"
#include "SocExplorerApp.hpp"
#include "../gui/mainwindow.hpp"
#include "PySocModule.hpp"
