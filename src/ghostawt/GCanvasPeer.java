package ghostawt;

import java.awt.Component;
import java.awt.GraphicsConfiguration;
import java.awt.peer.CanvasPeer;

public class GCanvasPeer extends GComponentPeer implements CanvasPeer {
    public GCanvasPeer(Component target) {
        super(target);
    }

    @Override
    public GraphicsConfiguration getAppropriateGraphicsConfiguration(GraphicsConfiguration gc) {
        return gc;
    }
}
