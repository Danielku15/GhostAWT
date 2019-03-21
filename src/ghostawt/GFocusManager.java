/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package ghostawt;

import java.awt.Component;
import java.awt.KeyboardFocusManager;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import sun.awt.CausedFocusEvent;

public class GFocusManager {

  public boolean requestFocus(Component lightweightChild, boolean temporary, CausedFocusEvent.Cause cause) {
    try {
      KeyboardFocusManager manager = KeyboardFocusManager.getCurrentKeyboardFocusManager();
      Component oldFocusOwner = manager.getFocusOwner();
      FocusEvent event = new CausedFocusEvent(lightweightChild, 0, temporary, oldFocusOwner, cause);
      fireFocusLost(oldFocusOwner, event);

      Method setFocusOwner = KeyboardFocusManager.class.getDeclaredMethod("setGlobalFocusOwner", Component.class);
      setFocusOwner.setAccessible(true);
      setFocusOwner.invoke(manager, lightweightChild);

      Method setPermFocusOwner = KeyboardFocusManager.class.getDeclaredMethod("setGlobalPermanentFocusOwner", Component.class);
      setPermFocusOwner.setAccessible(true);
      setPermFocusOwner.invoke(manager, lightweightChild);

      fireFocusGained(lightweightChild, event);
      return true;
    }
    catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException ex) {
      return false;
    }
  }

  public boolean isFocusable(Component component) {
    return component != null && component.isFocusable();
  }

  private static void fireFocusLost(Component component, FocusEvent event) {
    if (component == null) {
      return;
    }
    for (FocusListener listener : component.getFocusListeners()) {
      listener.focusLost(event);
    }
  }

  private static void fireFocusGained(Component component, FocusEvent event) {
    if (component == null) {
      return;
    }
    for (FocusListener listener : component.getFocusListeners()) {
      listener.focusGained(event);
    }
  }
}
