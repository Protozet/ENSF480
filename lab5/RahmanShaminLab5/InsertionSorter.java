/**
 * InsertionSorter
 */
public class InsertionSorter <E extends Number & Comparable<E>> implements Sorter<E>{

    MyVector<E> reference;

    @Override
    public void sort() {
        int  n = reference.size();
        for(int i = 1; i < n; ++i){
            Item<E> key = reference.get(i);
            int j = i - 1;

            while(j >= 0 && reference.get(j).getItem().compareTo(key.getItem()) > 0){
                Item<E> temp = reference.get(j);
                reference.set(j + 1, temp);
                j = j - 1;
            }
            reference.set(j + 1, key);
        }
    }

    @Override
    public void assignReference(MyVector<E> contextReference) {
        reference = contextReference;
    }
}