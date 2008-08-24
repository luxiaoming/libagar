#include "ctxt.h"
#include "install.h"

struct install_item insthier[] = {
  {INST_MKDIR, 0, 0, ctxt_bindir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_incdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_dlibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_slibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_repos, 0, 0, 0755},
  {INST_COPY, "ag_dso.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-ada-conf.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-config.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-config.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-datasource.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-datasource.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-dso.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-dso.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-error.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-error.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-event.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-event.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-limits.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-limits.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-object.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-object.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-slist.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-slist.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-tail_queue.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-tail_queue.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-threads.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-threads.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-timeout.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-timeout.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-types.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-types.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-version.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-version.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-config.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-config.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-datasource.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-datasource.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-dso.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-dso.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-error.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-error.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-event.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-event.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-object.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-object.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-timeout.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-timeout.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-core-config.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-config.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-datasource.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-datasource.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-dso.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-dso.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-error.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-error.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-event.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-event.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-limits.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-limits.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-object.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-object.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-slist.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-slist.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-tail_queue.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-tail_queue.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-threads.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-threads.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-timeout.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-timeout.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-types.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-types.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-version.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-version.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-core-ada.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-ada.a", "libagar-core-ada.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "agar-core-ada-conf.ld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-core-ada-conf", 0, ctxt_bindir, 0, 0, 0755},
};
unsigned long insthier_len = sizeof(insthier) / sizeof(struct install_item);
