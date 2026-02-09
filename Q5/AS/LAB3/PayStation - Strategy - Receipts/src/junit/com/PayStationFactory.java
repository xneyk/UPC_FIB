package junit.com;

public interface PayStationFactory {
    RateStrategy createRateStrategy();
    Receipt createReceipt(int timeBought);
}