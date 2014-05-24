package ghostawt.sun;

import java.awt.Font;
import java.io.File;
import java.io.InputStream;
import java.nio.file.CopyOption;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;

import sun.awt.FontConfiguration;
import sun.font.Font2D;
import sun.font.PhysicalFont;

public class GFontManager extends sun.font.SunFontManager {

    private PhysicalFont _default;

    public GFontManager() {
        System.out.println("Font Manager Created");
    }

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
        return new String[] { "Lucida Sans Regular", "LucidaSansRegular.ttf" };
    }

    @Override
    protected String getFontPath(boolean noType1Fonts) {
        return "";
    }

    @Override
    public synchronized PhysicalFont getDefaultPhysicalFont() {
        if (_default == null) {
            _default = (PhysicalFont) loadDefault();
        }
        return _default;
    }

    @Override
    public synchronized Font2D findFont2D(String name, int style, int fallback) {
        return getDefaultPhysicalFont();
    }

    private Font2D loadDefault() {
        try {
            String[] defaultFont = getDefaultPlatformFont();

            File tempFile = File.createTempFile(defaultFont[0], "ttf");
            tempFile.deleteOnExit();

            InputStream link = (getClass().getResourceAsStream(defaultFont[1]));
            Files.copy(link, tempFile.getAbsoluteFile().toPath(), StandardCopyOption.REPLACE_EXISTING);
            return createFont2D(tempFile, Font.TRUETYPE_FONT, false, null);
        } catch (Exception e) {
            System.err.println("Could not load arial font");
            e.printStackTrace();
            return null;
        }
    }
}