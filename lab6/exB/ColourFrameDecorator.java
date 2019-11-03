package exB;

import java.awt.Graphics;

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
        
    }
}