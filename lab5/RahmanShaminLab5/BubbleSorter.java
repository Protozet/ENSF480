/**
 * BubbleSorter
 */
public class BubbleSorter <E extends Number & Comparable<E>> implements Sorter<E>{

    MyVector<E> reference;

    @Override
    public void sort() {
        int  n = reference.size();
        for(int i = 0; i < n - 1; i ++){
            for(int j = 0; j < n - i - 1; j++){
                if(reference.get(j).getItem().compareTo(reference.get(j + 1).getItem()) > 0){
                    Item<E> temp = reference.get(j);
                    Item<E> insert = reference.get(j + 1);
                    reference.set(j, insert);
                    reference.set(j + 1, temp);
                }
            }
        }
    }

    @Override
    public void assignReference(MyVector<E> contextReference) {
        reference = contextReference;
    }
}