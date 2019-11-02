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
        System.out.println("Notification to Three-Column Table Observer: Data Changed:");
    }

}
