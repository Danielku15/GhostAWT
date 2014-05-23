package ghostawt;

import java.awt.Component;
import java.awt.peer.ScrollbarPeer;

public class GScrollbarPeer extends GComponentPeer implements ScrollbarPeer {
    public GScrollbarPeer(Component target) {
        super(target);
    }

    @Override
    public void setValues(int value, int visible, int minimum, int maximum) {
    }

    @Override
    public void setLineIncrement(int l) {
    }

    @Override
    public void setPageIncrement(int l) {
    }
}