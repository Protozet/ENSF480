
public class SelectionSorter <E extends Number & Comparable<E>> implements Sorter<E>{

    MyVector<E> reference;

    @Override
    public void sort() {
        int  n = reference.size();

        for(int i = 0; i < n - 1; i++){
            int min = i;
            for(int j = i + 1; j < n; j++){
                if(reference.get(j).getItem().compareTo(reference.get(min).getItem()) < 0){
                    min = j;
                }
            }
            Item<E> temp = reference.get(min);
            Item<E> insert = reference.get(i);
            reference.set(min, insert);
            reference.set(i, temp);
        }
    }

    @Override
    public void assignReference(MyVector<E> contextReference) {
        reference = contextReference;
    }
    
}