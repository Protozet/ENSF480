package exA;

import java.util.ArrayList;

public class DoubleArrayListSubject implements Subject{
    public ArrayList<Double> data;
    private ArrayList<Observer> observers;

    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
        o.update(data);
    }

    @Override
    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyAllObservers() {
        for (Observer o : observers) {
            o.update(data);
        }
    }

    public DoubleArrayListSubject() {
        super();
    }

    public void addData(Double d){
        data.add(d);
    }

    public void setData(double d, int index){
        data.set(index, d);
    }

    public void display(){
        
    }
}