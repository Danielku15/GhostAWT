package ghostawt;

import java.awt.Font;
import java.awt.MenuItem;
import java.awt.peer.MenuItemPeer;

public class GMenuItemPeer extends GObjectPeer implements MenuItemPeer {
    protected GMenuItemPeer(Object target) {
        super(target);
    }

    public GMenuItemPeer(MenuItem target) {
        super(target);
    }

    @Override
    public void dispose() {
    }

    @Override
    public void setFont(Font f) {
    }

    @Override
    public void setLabel(String label) {
    }

    @Override
    public void setEnabled(boolean e) {
    }
}
