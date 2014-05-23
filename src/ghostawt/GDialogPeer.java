package ghostawt;

import java.awt.Component;
import java.awt.Window;
import java.awt.peer.DialogPeer;
import java.util.List;

public class GDialogPeer extends GWindowPeer implements DialogPeer {
    public GDialogPeer(Component target) {
        super(target);
    }

    @Override
    public void setTitle(String title) {
    }

    @Override
    public void setResizable(boolean resizeable) {
    }

    @Override
    public void blockWindows(List<Window> windows) {
    }
}