package junit.com;

public class StandardReceipt extends BaseReceipt {

	public StandardReceipt(int value) {
		super(value);
	}

	@Override
	public String addSpecificInformation() {
		String receiptContent = "";
		receiptContent = receiptContent + "STANDARD RECEIPT";
	  receiptContent = receiptContent + "----------------------------------";
		return receiptContent;
	}
}
