package ghostawt;

import java.awt.Component;
import java.awt.Window;

import sun.awt.KeyboardFocusManagerPeerImpl;

public class GKeyboardFocusManagerPeer extends KeyboardFocusManagerPeerImpl {
    @Override
    public void setCurrentFocusedWindow(Window win) {
        // Not used on Windows
        throw new RuntimeException("not implemented");
    }

    @Override
    public Window getCurrentFocusedWindow() {
        return null;
    }

    @Override
    public void setCurrentFocusOwner(Component comp) {
    }

    @Override
    public Component getCurrentFocusOwner() {
        return null;
    }
}