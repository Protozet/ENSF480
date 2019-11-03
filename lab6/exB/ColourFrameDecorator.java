package exB;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;
import java.awt.BasicStroke;
import java.awt.Color;

public class ColourFrameDecorator extends Decorator{
    
    int thickness;

    public ColourFrameDecorator(Component c, int xCoord, int yCoord, int w, int h, int thicc){
        cmp = c;
        x = xCoord;
        y = yCoord;
        width = w;
        height = h;
        thickness = thicc;
    }

    @Override
    public void draw(Graphics g) {
        Graphics2D g2d = (Graphics2D)g;
        // Stroke oldStroke = g2d.getStroke();
        // Color oldColor = g2d.getColor();
        g2d.setStroke(new BasicStroke(thickness));
        g2d.setColor(Color.red);
        g2d.drawRect(x, y, width, height);
        cmp.draw(g);
        // g2d.setStroke(oldStroke);
        // g2d.setColor(oldColor);
    }
}