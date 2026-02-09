package junit.com;

public abstract class PayStationState {
    public abstract String getState();

    public void revision(PayStationImpl context) {
        throw new IllegalStateException("Unable going REVISION form " + getState());
    }

    public void revised(PayStationImpl context) {
        throw new IllegalStateException("Unable going REVISED form " + getState());
    }
}