package junit.com;

public class NewYorkFactory implements PayStationFactory {
    public RateStrategy createRateStrategy() {
        return new LinearRateStrategy();
    }
    public Receipt createReceipt(int timeBought) {
        return new StandardReceipt(timeBought);
    }
}