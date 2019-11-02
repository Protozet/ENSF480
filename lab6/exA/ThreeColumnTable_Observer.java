package exA;

import java.util.ArrayList;

public class ThreeColumnTable_Observer implements Observer {

    private Subject subject;
    private ArrayList<Double> data;

    public ThreeColumnTable_Observer(Subject s) {
        subject = s;
        subject.registerObserver(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
        this.data = data;
        display();
    }

    public void display(){
        System.out.print("\nNotification to Three-Column Table Observer: Data Changed:");
        int i = 0;
        for (Double double1 : data) {
            if(i % 3 == 0)
                System.out.println();
            System.out.print(double1 + " ");
            i++;
        }
        System.out.println();
    }

}
