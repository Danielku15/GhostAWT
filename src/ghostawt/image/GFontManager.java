package ghostawt.image;

import java.awt.Font;
import java.util.Locale;

public class GFontManager {
    private static GFontManager instance;

    public static GFontManager getInstance() {
        if (instance == null) {
            instance = new GFontManager();
        }
        return instance;
    }

    private Font systemFont;

    private GFontManager() {
    }

    public Font[] getAllInstalledFonts() {
        if (systemFont == null) {
            loadSystemFont();
        }
        return new Font[] { systemFont };
    }

    private void loadSystemFont() {
        systemFont = new Font("System", Font.PLAIN, 12);
    }

    public String[] getInstalledFontFamilyNames(Locale requestedLocale) {
        return new String[] { "System" };
    }
}
