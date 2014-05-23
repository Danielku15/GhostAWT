package ghostawt;

import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.peer.MenuBarPeer;

public class GMenuBarPeer extends GMenuPeer implements MenuBarPeer {
    public GMenuBarPeer(MenuBar target) {
        super(target);
    }

    @Override
    public void addMenu(Menu m) {
    }

    @Override
    public void delMenu(int index) {
    }

    @Override
    public void addHelpMenu(Menu m) {
    }
}