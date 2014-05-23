package ghostawt;

import java.awt.Component;
import java.awt.peer.ChoicePeer;

public class GChoicePeer extends GComponentPeer implements ChoicePeer {
    GChoicePeer(Component target) {
        super(target);
    }

    @Override
    public void add(String item, int index) {
    }

    @Override
    public void remove(int index) {
    }

    @Override
    public void removeAll() {
    }

    @Override
    public void select(int index) {
    }
}