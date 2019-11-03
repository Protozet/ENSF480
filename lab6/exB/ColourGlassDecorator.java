package exB;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.AlphaComposite;

public class ColourGlassDecorator extends Decorator{

    public ColourGlassDecorator(Component c, int xCoord, int yCoord, int w, int h){
        cmp = c;
        x = xCoord;
        y = yCoord;
        width = w;
        height = h;
    }

    @Override
    public void draw(Graphics g) {
        Graphics2D g2d = (Graphics2D)g;
        cmp.draw(g);

        g2d.setStroke(new BasicStroke(3));
        g2d.setColor(Color.green);
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1 * 0.2f));
        g2d.fillRect(x, y, width, height);
    }
}