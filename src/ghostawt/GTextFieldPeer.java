package ghostawt;

import java.awt.Dimension;
import java.awt.TextComponent;
import java.awt.im.InputMethodRequests;
import java.awt.peer.TextFieldPeer;

public class GTextFieldPeer extends GTextComponentPeer implements TextFieldPeer {
    public GTextFieldPeer(TextComponent target) {
        super(target);
    }

    @Override
    public InputMethodRequests getInputMethodRequests() {
        return null;
    }

    @Override
    public void setEchoChar(char echoChar) {
    }

    @Override
    public Dimension getPreferredSize(int columns) {
        return null;
    }

    @Override
    public Dimension getMinimumSize(int columns) {
        return null;
    }
}