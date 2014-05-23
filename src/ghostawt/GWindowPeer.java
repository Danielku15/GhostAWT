package ghostawt;

import java.awt.Component;
import java.awt.Dialog;
import java.awt.peer.WindowPeer;

public class GWindowPeer extends GPanelPeer implements WindowPeer {
    public GWindowPeer(Component target) {
        super(target);
    }

    @Override
    public void toFront() {
    }

    @Override
    public void toBack() {
    }

    @Override
    public void updateAlwaysOnTopState() {
    }

    @Override
    public void updateFocusableWindowState() {
    }

    @Override
    public void setModalBlocked(Dialog blocker, boolean blocked) {
    }

    @Override
    public void updateMinimumSize() {
    }

    @Override
    public void updateIconImages() {
    }

    @Override
    public void setOpacity(float opacity) {
    }

    @Override
    public void setOpaque(boolean isOpaque) {
    }

    @Override
    public void updateWindow() {
    }

    @Override
    public void repositionSecurityWarning() {
    }
}
