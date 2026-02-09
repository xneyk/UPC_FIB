package junit.com;

public class RevisionState extends PayStationState {
    @Override
    public String getState() {
        return "REVISION";
    }

    @Override
    public void revised(PayStationImpl context) {
        context.setState(new RevisedState());
    }
}