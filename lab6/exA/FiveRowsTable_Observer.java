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
        System.out.println("\nNotification to Five-Rows Table Observer: Data Changed:");
        int offset = 0;
        int i = 0;
        while(offset < 5){
            for (Double double1 : data) {
                if(i % 5 == 0 || i == 0){
                    if((i + offset) >= data.size()) break;
                    System.out.print(data.get(i + offset) + " ");
                }
                i++;
            }
            offset++;
            i = 0;
            System.out.println();
        }
    }

}
