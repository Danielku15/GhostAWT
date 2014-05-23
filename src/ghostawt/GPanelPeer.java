package ghostawt;

import java.awt.Component;
import java.awt.Insets;
import java.awt.peer.PanelPeer;

public class GPanelPeer extends GCanvasPeer implements PanelPeer {
    public GPanelPeer(Component target) {
        super(target);
    }

    @Override
    public Insets getInsets() {
        return new Insets(0, 0, 0, 0);
    }

    @Override
    public void beginValidate() {
    }

    @Override
    public void endValidate() {
    }

    @Override
    public void beginLayout() {
    }

    @Override
    public void endLayout() {
    }
}