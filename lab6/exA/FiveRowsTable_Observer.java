package exA;

import java.util.ArrayList;

public class FiveRowsTable_Observer implements Observer {

    private Subject subject;
    private ArrayList<Double> data;

    public FiveRowsTable_Observer(Subject s) {
        subject = s;
        subject.registerObserver(this);
    }

    @Override
    public void update(ArrayList<Double> data) {
        this.data = data;
        display();
    }

    public void display(){
        System.out.println("Notification to Five-Rows Table Observer: Data Changed:");
    }

}
