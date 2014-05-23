package ghostawt.image;

import java.awt.Font;
import java.awt.Graphics2D;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;
import java.awt.HeadlessException;
import java.awt.image.BufferedImage;
import java.util.Locale;

public class GhostGraphicsEnvironment extends GraphicsEnvironment {
    private GraphicsDevice screenDevice;

    @Override
    public GraphicsDevice[] getScreenDevices() throws HeadlessException {
        return new GraphicsDevice[] {getDefaultScreenDevice()};
    }

    @Override
    public GraphicsDevice getDefaultScreenDevice() throws HeadlessException {
        if (screenDevice == null) {
            screenDevice = new GGraphicsDevice();
        }
        return screenDevice;
    }

    @Override
    public Graphics2D createGraphics(BufferedImage img) {
        return new GGraphics2D(getDefaultScreenDevice().getConfigurations()[0]);
    }

    @Override
    public Font[] getAllFonts() {
        GFontManager fm = GFontManager.getInstance();
        Font[] installedFonts = fm.getAllInstalledFonts();
        return installedFonts;
    }

    @Override
    public String[] getAvailableFontFamilyNames() {
        return getAvailableFontFamilyNames(Locale.getDefault());
    }

    @Override
    public String[] getAvailableFontFamilyNames(Locale requestedLocale) {
        return GFontManager.getInstance().getInstalledFontFamilyNames(requestedLocale);
    }

    public double getXResolution() {
        return 96;
    }

    public double getYResolution() {
        return 96;
    }

}
