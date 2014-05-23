package ghostawt;

import java.awt.Adjustable;
import java.awt.Component;
import java.awt.peer.ScrollPanePeer;

public class GScrollPanePeer extends GPanelPeer implements ScrollPanePeer {
    public GScrollPanePeer(Component target) {
        super(target);
    }

    @Override
    public int getHScrollbarHeight() {
        return 0;
    }

    @Override
    public int getVScrollbarWidth() {
        return 0;
    }

    @Override
    public void setScrollPosition(int x, int y) {
    }

    @Override
    public void childResized(int w, int h) {
    }

    @Override
    public void setUnitIncrement(Adjustable adj, int u) {
    }

    @Override
    public void setValue(Adjustable adj, int v) {
    }
}
