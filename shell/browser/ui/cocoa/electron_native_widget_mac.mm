// Copyright (c) 2018 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "shell/browser/ui/cocoa/electron_native_widget_mac.h"

#include "shell/browser/ui/cocoa/electron_ns_window.h"
#include "shell/browser/ui/cocoa/electron_ns_panel.h"

namespace electron {

ElectronNativeWidgetMac::ElectronNativeWidgetMac(
    NativeWindowMac* shell,
    std::string window_type,
    NSUInteger style_mask,
    views::internal::NativeWidgetDelegate* delegate)
    : views::NativeWidgetMac(delegate),
      shell_(shell),
      window_type_(window_type),
      style_mask_(style_mask) {}

ElectronNativeWidgetMac::~ElectronNativeWidgetMac() {}

NativeWidgetMacNSWindow* ElectronNativeWidgetMac::CreateNSWindow(
    const remote_cocoa::mojom::CreateWindowParams* params) {
  if (window_type_ == "panel") {
    return static_cast<NativeWidgetMacNSWindow*>(
      [[[ElectronNSPanel alloc] initWithShell:shell_
                                styleMask:style_mask_] autorelease]);
  } else {
    return [[[ElectronNSWindow alloc] initWithShell:shell_
                                      styleMask:style_mask_] autorelease];
  }
}

}  // namespace electron
