#include <wups.h>
#include <notifications/notifications.h>

WUPS_PLUGIN_NAME("ArroU");
WUPS_PLUGIN_DESCRIPTION("");
WUPS_PLUGIN_VERSION("v0.0");
WUPS_PLUGIN_AUTHOR("Nanashi-Hax");
WUPS_USE_WUT_DEVOPTAB();
WUPS_USE_STORAGE("ArroU");

INITIALIZE_PLUGIN()
{
    NotificationModule_InitLibrary();
    NotificationModule_AddInfoNotification("ArroU");
}