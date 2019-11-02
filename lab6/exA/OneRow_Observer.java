package exA;

import java.util.ArrayList;

public class OneRow_Observer implements Observer {

    private Subject subject;
    private ArrayList<Double> data;

    public OneRow_Observer(Subject s) {
        subject = s;
        subject.registerObserver(this);
        display();
    }

    @Override
    public void update(ArrayList<Double> data) {
        this.data = data;
        display();
    }

    void display(){

    }

}
