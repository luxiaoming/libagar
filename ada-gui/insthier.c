#include "ctxt.h"
#include "install.h"

struct install_item insthier[] = {
  {INST_MKDIR, 0, 0, ctxt_bindir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_incdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_dlibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_slibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_repos, 0, 0, 0755},
  {INST_COPY, "ag_draw.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ag_surface.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ag_unit.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ag_widget.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "ag_window.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-ada-conf.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-colors.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-colors.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-draw.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-draw.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-pixelformat.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-pixelformat.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-point.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-point.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-rect.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-rect.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-style.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-style.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-surface.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-surface.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-text.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-text.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-unit.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-unit.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-view.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-view.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-widget.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-widget.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-window.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-window.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui.ads", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui.ads", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-colors.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-colors.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-draw.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-draw.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-surface.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-surface.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-text.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-text.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-unit.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-unit.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-view.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-view.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-widget.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-widget.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-window.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-window.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui.adb", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui.adb", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-colors.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-colors.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-draw.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-draw.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-pixelformat.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-pixelformat.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-point.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-point.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-rect.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-rect.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-style.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-style.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-surface.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-surface.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-text.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-text.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-unit.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-unit.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-view.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-view.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-widget.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-widget.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-window.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-window.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui.ali", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui.ali", 0, ctxt_incdir, 0, 0, 0444},
  {INST_COPY, "agar-gui-ada.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-ada.a", "libagar-gui-ada.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "agar-gui-ada-conf.ld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "agar-gui-ada-conf", 0, ctxt_bindir, 0, 0, 0755},
};
unsigned long insthier_len = sizeof(insthier) / sizeof(struct install_item);
