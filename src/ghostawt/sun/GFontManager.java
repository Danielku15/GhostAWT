package ghostawt.sun;

import sun.awt.FontConfiguration;

public class GFontManager extends sun.font.SunFontManager {
    @Override
    protected FontConfiguration createFontConfiguration() {
        FontConfiguration fc = new GFontConfiguration(this);
        fc.init();
        return fc;
    }

    @Override
    public FontConfiguration createFontConfiguration(boolean preferLocaleFonts, boolean preferPropFonts) {
        return new GFontConfiguration(this, preferLocaleFonts, preferPropFonts);
    }

    @Override
    public String[] getDefaultPlatformFont() {
        return new String[]{"Arial", "Arial.ttf"};
    }

    @Override
    protected String getFontPath(boolean noType1Fonts) {
        return "";
    }
}