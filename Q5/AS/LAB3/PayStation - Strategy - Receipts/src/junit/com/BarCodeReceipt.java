package junit.com;

public class BarCodeReceipt extends ReceiptImpl {

	  public BarCodeReceipt (int value) { 
	    super(value); }

	  public String additionalPrint() {
		String receiptContent="";
		
		for (int i=0; i<value(); i++) {
		  receiptContent = receiptContent + "|"; }
		  receiptContent = receiptContent + "\n";
		  receiptContent = receiptContent + "BARCODE RECEIPT";
		return receiptContent;
	}
	  }

