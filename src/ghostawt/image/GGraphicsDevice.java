package ghostawt.image;

import java.awt.GraphicsConfiguration;
import java.awt.GraphicsDevice;
import java.awt.image.ColorModel;

public class GGraphicsDevice extends GraphicsDevice {
    private String idString;
    private GGraphicsConfiguration defaultConfiguration;
    private ColorModel colorModel;
    
    
    public GGraphicsDevice() {
        idString = "Display0";
    }
    
    @Override
    public int getType() {
        return TYPE_RASTER_SCREEN;
    }

    @Override
    public String getIDstring() {
        return idString;
    }

    @Override
    public GraphicsConfiguration[] getConfigurations() {
        return new GraphicsConfiguration[]{getDefaultConfiguration()};
    }

    @Override
    public GraphicsConfiguration getDefaultConfiguration() {
        if(defaultConfiguration == null) {
            defaultConfiguration = new GGraphicsConfiguration(this);
        }
        return defaultConfiguration;
    }

    public ColorModel getColorModel() {
        if (colorModel == null)  {
            colorModel = ColorModel.getRGBdefault();
        }
        return colorModel;
    }

}
