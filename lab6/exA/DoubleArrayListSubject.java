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
        data = new ArrayList<Double>();
        observers = new ArrayList<Observer>();
    }

    public void addData(Double d){
        data.add(d);
        notifyAllObservers();
    }

    public void setData(double d, int index){
        data.set(index, d);
        notifyAllObservers();
    }

    public void display(){
        if(data.isEmpty())
            System.out.println("Empty List ...");
        else
            for (Double double1 : data) {
                System.out.println(double1);
            }
    }

    public void populate(double arr[]){
        for (double d : arr) {
            data.add(d);
        }
    }
}