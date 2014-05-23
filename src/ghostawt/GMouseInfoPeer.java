package ghostawt;

import java.awt.Point;
import java.awt.Window;
import java.awt.peer.MouseInfoPeer;

public class GMouseInfoPeer implements MouseInfoPeer {
    @Override
    public int fillPointWithCoords(Point point) {
        return 0;
    }

    @Override
    public boolean isWindowUnderMouse(Window w) {
        return false;
    }
}
