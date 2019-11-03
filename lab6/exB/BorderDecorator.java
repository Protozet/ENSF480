package exB;

import java.awt.Graphics;

public class BorderDecorator extends Decorator{
    //new BorderDecorator(t, 30, 30, 100, 100);

    public BorderDecorator(Component c, int xCoord, int yCoord, int w, int h){
        cmp = c;
        x = xCoord;
        y = yCoord;
        width = w;
        height = h;
    }

    @Override
    public void draw(Graphics g) {
        
    }
}