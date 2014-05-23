package ghostawt;

import java.awt.Dimension;
import java.awt.TextComponent;
import java.awt.im.InputMethodRequests;
import java.awt.peer.TextAreaPeer;

public class GTextAreaPeer extends GTextComponentPeer implements TextAreaPeer {
    public GTextAreaPeer(TextComponent target) {
        super(target);
    }

    @Override
    public InputMethodRequests getInputMethodRequests() {
        return null;
    }

    @Override
    public void insert(String text, int pos) {
    }

    @Override
    public void replaceRange(String text, int start, int end) {
    }

    @Override
    public Dimension getPreferredSize(int rows, int columns) {
        return null;
    }

    @Override
    public Dimension getMinimumSize(int rows, int columns) {
        return null;
    }
}