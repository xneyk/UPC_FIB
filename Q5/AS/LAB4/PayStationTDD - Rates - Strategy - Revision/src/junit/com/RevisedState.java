package junit.com;

public class RevisedState extends PayStationState {
    @Override
    public String getState() {
        return "REVISED";
    }

    @Override
    public void revision(PayStationImpl context) {
        context.setState(new RevisionState());
    }
}
