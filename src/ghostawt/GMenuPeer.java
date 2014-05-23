package ghostawt;

import java.awt.MenuItem;
import java.awt.peer.MenuPeer;

public class GMenuPeer extends GMenuItemPeer implements MenuPeer {
    protected GMenuPeer(Object target) {
        super(target);
    }
    
    public GMenuPeer(MenuItem target) {
        super(target);
    }

    @Override
    public void addSeparator() {
    }

    @Override
    public void addItem(MenuItem item) {
    }

    @Override
    public void delItem(int index) {
    }
}