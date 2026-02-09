package junit.com;

public class LinearRate implements RateStarategy {
    public int calculateTime(int insertedSoFar) {
        return insertedSoFar / 5 * 2;
    }
}