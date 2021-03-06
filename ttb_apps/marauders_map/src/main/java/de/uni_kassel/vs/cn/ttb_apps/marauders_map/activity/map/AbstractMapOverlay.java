package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.map;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.widget.ImageView;

/**
 * Created by marci on 05.02.16.
 */
public abstract class AbstractMapOverlay {

    private static double[] origin;
    private static double pixelToMeterResolution;

    private ImageView mapView;

    protected Bitmap underlyinMap;

    private final Canvas canvas;

    /**
     *
     * @param imageView the overlay needs an ImageView to apply to.
     * @param underlyingMap the map on which will be drawn on top.
     */
    public AbstractMapOverlay(ImageView imageView, Bitmap underlyingMap, Canvas canvas) {
        this.mapView = imageView;
        this.underlyinMap = underlyingMap;
        this.canvas = canvas;
    }

    private static boolean intialized = false;

    /**
     *
     */
    protected void redrawUnderlyingMap() {
        mapView.post(new Runnable() {
            @Override
            public void run() {
                drawOverlay(canvas);
                mapView.invalidate();
            }
        });

    }

    protected abstract void drawOverlay(Canvas canvas);

    public final void render() {
        redrawUnderlyingMap();
    }

    public static void setOrigin(double[] newOrigin) {
        origin = newOrigin;
    }

    public double[] getOrigin() {
        return origin;
    }

    public double getPixelToMeterResolution() {
        return pixelToMeterResolution;
    }

    public static void setPixelToMeterResolution(double newPixelToMeterResolution) {
        pixelToMeterResolution = newPixelToMeterResolution;
    }

    public double[] getPixelForMeter(double meterX, double meterY) {
        int height = mapView.getDrawable().getBounds().height();

        double xMetersFromOrigin = Math.abs(origin[0]) + meterX;
        double yMetersFromOrigin = Math.abs(origin[0]) + meterY;

        double Xpixels = xMetersFromOrigin / pixelToMeterResolution;
        double Ypixels = yMetersFromOrigin / pixelToMeterResolution;

        return new double[] {Xpixels, height - Ypixels};
    }

    public double[] getMeterForPixel(double pixelX, double pixelY) {
        int height = mapView.getDrawable().getBounds().height();
        double meterY, meterX;

        meterY = ((pixelY - height) * -pixelToMeterResolution + origin[1]);
        meterX = pixelX * pixelToMeterResolution;
        meterX = meterX + origin[0];
        return new double[] {meterX, meterY};
    }
}
