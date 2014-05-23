package ghostawt;

import java.awt.Event;
import java.awt.PopupMenu;
import java.awt.peer.PopupMenuPeer;

public class GPopupMenuPeer extends GMenuPeer implements PopupMenuPeer {
    public GPopupMenuPeer(PopupMenu target) {
        super(target);
    }

    @Override
    public void show(Event e) {
    }
}