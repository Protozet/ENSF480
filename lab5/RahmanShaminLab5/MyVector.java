import java.util.ArrayList;

// MyVector.java

public class MyVector <E extends Number & Comparable<E>> { 

    private ArrayList<Item<E>> storageM;
    private Sorter<E> sorter;
    
    public MyVector(int n) {
        storageM = new ArrayList<Item<E>>(n);
        sorter = new BubbleSorter<E>();     // as per notes, strategy is set as strategy1 by default
        sorter.assignReference(this);
    }
    public MyVector(ArrayList<Item<E>> arr) {
        storageM = arr;
        sorter = new BubbleSorter<E>();     // as per notes, strategy is set as strategy1 by default
        sorter.assignReference(this);
    }
    public Item<E> get(int index){
        return storageM.get(index);
    }
    public void set(int index, Item<E> a){
        storageM.set(index, a);
    }
    public int size(){
        return storageM.size();
    }
    public void add(Item<E> value){
        storageM.add(value);
    }
    public void setSortStrategy(Sorter<E> s){
        sorter = s;
        sorter.assignReference(this);
    }
    public void performSort(){
        sorter.sort();
    }
    public void display(){
        for(int i = 0 ; i < storageM.size(); i++){
            System.out.println(storageM.get(i).getItem() + " ");
        }
        System.out.println();
    }
}