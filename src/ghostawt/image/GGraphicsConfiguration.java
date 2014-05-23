package ghostawt.image;

import java.awt.AWTException;
import java.awt.GraphicsConfiguration;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;
import java.awt.ImageCapabilities;
import java.awt.Rectangle;
import java.awt.geom.AffineTransform;
import java.awt.image.ColorModel;
import java.awt.image.VolatileImage;

public class GGraphicsConfiguration extends GraphicsConfiguration {
    private GGraphicsDevice device;

    public GGraphicsConfiguration(GGraphicsDevice device) {
        this.device = device;
    }

    @Override
    public GraphicsDevice getDevice() {
        return device;
    }

    @Override
    public ColorModel getColorModel() {
        return device.getColorModel();
    }

    @Override
    public ColorModel getColorModel(int transparency) {
        return getColorModel();
    }

    @Override
    public AffineTransform getDefaultTransform() {
        return new AffineTransform();
    }

    @Override
    public AffineTransform getNormalizingTransform() {
        GhostGraphicsEnvironment ge = (GhostGraphicsEnvironment) GraphicsEnvironment.getLocalGraphicsEnvironment();
        double xscale = ge.getXResolution() / 72.0;
        double yscale = ge.getYResolution() / 72.0;
        return new AffineTransform(xscale, 0.0, 0.0, yscale, 0.0, 0.0);
    }

    @Override
    public Rectangle getBounds() {
        return new Rectangle(1024, 768);
    }

    public VolatileImage createCompatibleVolatileImage(int width, int height, ImageCapabilities caps, int transparency) throws AWTException {
        return new GVolatileImage(this, width, height, transparency, caps);
    }

}
