package ghostawt;

import java.awt.Component;
import java.awt.peer.LabelPeer;

public class GLabelPeer extends GComponentPeer implements LabelPeer {
    public GLabelPeer(Component target) {
        super(target);
    }

    @Override
    public void setText(String label) {
    }

    @Override
    public void setAlignment(int alignment) {
    }
}