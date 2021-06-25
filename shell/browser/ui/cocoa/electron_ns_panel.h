// Copyright (c) 2018 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef SHELL_BROWSER_UI_COCOA_ELECTRON_NS_PANEL_H_
#define SHELL_BROWSER_UI_COCOA_ELECTRON_NS_PANEL_H_

#include "components/remote_cocoa/app_shim/native_widget_mac_nspanel.h"
#include "shell/browser/ui/cocoa/event_dispatching_window.h"
#include "ui/views/widget/native_widget_mac.h"

namespace electron {

class NativeWindowMac;

}  // namespace electron

@interface ElectronNSPanel : NativeWidgetMacNSPanel {
 @private
  electron::NativeWindowMac* shell_;
}
@property BOOL acceptsFirstMouse;
@property BOOL enableLargerThanScreen;
@property BOOL disableAutoHideCursor;
@property BOOL disableKeyOrMainWindow;
@property(nonatomic, retain) NSView* vibrantView;
@property(nonatomic, retain) NSImage* cornerMask;
- (id)initWithShell:(electron::NativeWindowMac*)shell
          styleMask:(NSUInteger)styleMask;
- (electron::NativeWindowMac*)shell;
- (id)accessibilityFocusedUIElement;
- (NSRect)originalContentRectForFrameRect:(NSRect)frameRect;
- (void)toggleFullScreenMode:(id)sender;
- (NSImage*)_cornerMask;
@end

#endif  // SHELL_BROWSER_UI_COCOA_ELECTRON_NS_PANEL_H_
