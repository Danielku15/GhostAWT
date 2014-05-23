package ghostawt;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.peer.ListPeer;

public class GListPeer extends GComponentPeer implements ListPeer {
    public GListPeer(Component target) {
        super(target);
    }

    @Override
    public int[] getSelectedIndexes() {
        return null;
    }

    @Override
    public void add(String item, int index) {
    }

    @Override
    public void delItems(int start, int end) {
    }

    @Override
    public void removeAll() {
    }

    @Override
    public void select(int index) {
    }

    @Override
    public void deselect(int index) {
    }

    @Override
    public void makeVisible(int index) {
    }

    @Override
    public void setMultipleMode(boolean m) {
    }

    @Override
    public Dimension getPreferredSize(int rows) {
        return null;
    }

    @Override
    public Dimension getMinimumSize(int v) {
        return null;
    }
}