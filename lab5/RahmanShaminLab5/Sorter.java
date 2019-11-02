// sorter.java

public interface Sorter <E extends Number & Comparable<E>> {
    public void sort();
    public void assignReference(MyVector <E> contextReference);
}
