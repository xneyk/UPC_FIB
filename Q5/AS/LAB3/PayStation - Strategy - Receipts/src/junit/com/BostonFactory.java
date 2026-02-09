package junit.com;

public class BostonFactory implements PayStationFactory {
    public RateStrategy createRateStrategy() {
        return new ProgressiveRateStrategy();
    }
    public Receipt createReceipt(int timeBought) {
        return new BarCodeReceipt(timeBought);
    }
}