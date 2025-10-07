package junit.com;

public class BarCodeReceipt extends BaseReceipt {

	public BarCodeReceipt(int value) {
		super(value);
	}

	@Override
	public String addSpecificInformation() {
		String receiptContent = "";
		for (int i = 0; i < value(); i++) {
			receiptContent = receiptContent + "|";
		}
		receiptContent = receiptContent + "\n";
		receiptContent = receiptContent + "BARCODE RECEIPT";
		receiptContent = receiptContent + "----------------------------------";
		return receiptContent;
	}
}
