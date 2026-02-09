package junit.com;

/**
 * Implementation of the pay station.
 * <p>
 * Responsibilities:
 * <p>
 * 1) Accept payment;
 * 2) Calculate parking time based on payment;
 * 3) Know earning, parking time bought;
 * 4) Issue receipts;
 * 5) Handle buy and cancel events.
 * <p>
 * This source code is from the book
 * "Flexible, Reliable Software:
 * Using Patterns and Agile Development"
 * published 2010 by CRC Press.
 * Author:
 * Henrik B Christensen
 * Department of Computer Science
 * Aarhus University
 * <p>
 * Please visit http://www.baerbak.com/ for further information.
 * <p>
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * <p>
 * http://www.apache.org/licenses/LICENSE-2.0
 * <p>
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

public class PayStationImpl implements PayStation {
    private int insertedSoFar;
    private int timeBought;


    /**
     * the strategy for rate calculations
     */
    private RateStrategy rateStrategy;

    private PayStationState state;

    /**
     * Construct a pay station instance with the given
     * rate calculation strategy.
     *
     * @param rateStrategy the rate calculation strategy to use
     *                     and the initial state (assuming revised with the today date)
     */
    public PayStationImpl(RateStrategy rateStrategy) {
        this.rateStrategy = rateStrategy;
        this.state = new RevisedState();
    }

    public void addPayment(int coinValue)
            throws IllegalCoinException {
        switch (coinValue) {
            case 5:
                break;
            case 10:
                break;
            case 25:
                break;
            default:
                throw new IllegalCoinException("Invalid coin: " + coinValue);
        }
        insertedSoFar += coinValue;
        timeBought = rateStrategy.calculateTime(insertedSoFar);
    }

    public int readDisplay() {
        return timeBought;
    }

    public Receipt buy() {
        Receipt r = new ReceiptImpl(timeBought);
        reset();
        return r;
    }

    public void cancel() {
        reset();
    }

    private void reset() {
        timeBought = insertedSoFar = 0;
    }

    public String getState() {
        return state.getState();
    }

    public void setState(PayStationState state) {
        this.state = state;
    }

    public void revision() {
        state.revision(this);
    }

    public void revised() {
        state.revised(this);
    }
}

