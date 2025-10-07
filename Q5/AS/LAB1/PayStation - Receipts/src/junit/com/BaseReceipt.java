package junit.com;

public abstract class BaseReceipt implements Receipt {
   private int value;
   
   public BaseReceipt(int value) {
      this.value = value;
   }

   public int value() {
      return value;
   }

   public String print() {
      String receiptContent = "----------------------------------";
	   receiptContent = receiptContent + "\n";
	   receiptContent = receiptContent + "-------- PARKING RECEIPT --------";
	   receiptContent = receiptContent + "\n";
	   receiptContent = receiptContent + "         Value " + value + " minutes";
	   receiptContent = receiptContent + "\n";
      
      receiptContent = receiptContent + addSpecificInformation();
      
      return receiptContent;
   }

   public abstract String addSpecificInformation();
}
