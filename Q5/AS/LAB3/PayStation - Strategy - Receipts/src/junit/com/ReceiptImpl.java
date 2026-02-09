package junit.com;

public abstract class ReceiptImpl implements Receipt{

	private int value;

	public ReceiptImpl(int value) {
		this.value = value;
	}

	@Override
	public int value() {
	return value; }

	@Override
	public String print() {
	String receiptContent = "----------------------------------";
	receiptContent = receiptContent + "\n";
	receiptContent = receiptContent + "-------- PARKING RECEIPT --------";
	receiptContent = receiptContent + "\n";
	receiptContent = receiptContent + "         Value " + value + " minutes";
	receiptContent = receiptContent + "\n";
	receiptContent = receiptContent + additionalPrint();
	receiptContent = receiptContent + "----------------------------------";
	return receiptContent; }
	
	public abstract String additionalPrint();
}