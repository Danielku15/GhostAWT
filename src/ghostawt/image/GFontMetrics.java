package ghostawt.image;

import java.awt.Font;
import java.awt.FontMetrics;

public class GFontMetrics extends FontMetrics {
    private static final long serialVersionUID = 8973610274117460237L;

    protected GFontMetrics(Font font) {
        super(font);
    }
    
    @Override
    public int stringWidth(String str) {
        if(str == null) return 0;
        return str.length() * font.getSize();
    }
}
