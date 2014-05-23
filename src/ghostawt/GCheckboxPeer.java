package ghostawt;

import java.awt.CheckboxGroup;
import java.awt.Component;
import java.awt.peer.CheckboxPeer;

public class GCheckboxPeer extends GComponentPeer implements CheckboxPeer {
    GCheckboxPeer(Component target) {
        super(target);
    }

    @Override
    public void setState(boolean state) {
    }

    @Override
    public void setCheckboxGroup(CheckboxGroup g) {
    }

    @Override
    public void setLabel(String label) {
    }
}