package ClassAssessment.Java;
import java.util.concurrent.Semaphore;
import java.util.LinkedList;

class ProducerConsumerLimited {
    private static final int BUFFER_SIZE = 2;
    private final LinkedList<Integer> buffer = new LinkedList<>();

    private final Semaphore mutex = new Semaphore(1);
    private final Semaphore empty = new Semaphore(BUFFER_SIZE);
    private final Semaphore full = new Semaphore(0);

    private static final int MAX_OPERATIONS = 5; 
    class Producer extends Thread {
        private final int id;
        private final int data;

        Producer(int id, int data) {
            this.id = id;
            this.data = data;
        }

        public void run() {
            try {
                for (int i = 0; i < MAX_OPERATIONS; i++) {
                    empty.acquire();
                    mutex.acquire();

                    buffer.add(data + i);
                    System.out.println("Producer " + id + ": Data " + (data + i) + " inserted into buffer");
                    System.out.println("Empty space: " + (BUFFER_SIZE - buffer.size()) + ", Full space: " + buffer.size());
                    System.out.println("----------------------------------");

                    mutex.release();
                    full.release();
                    sleep(1000);
                }
                System.out.println("Producer " + id + " finished producing.\n");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    class Consumer extends Thread {
        private final int id;

        Consumer(int id) {
            this.id = id;
        }

        public void run() {
            try {
                for (int i = 0; i < MAX_OPERATIONS; i++) {
                    full.acquire();
                    mutex.acquire();

                    int data = buffer.removeFirst();
                    System.out.println("Consumer " + id + ": Consumed Data " + data);
                    System.out.println("Empty space: " + (BUFFER_SIZE - buffer.size()) + ", Full space: " + buffer.size());
                    System.out.println("----------------------------------");

                    mutex.release();
                    empty.release();
                    sleep(1500);
                }
                System.out.println("Consumer " + id + " finished consuming.\n");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        ProducerConsumerLimited pc = new ProducerConsumerLimited();

        Producer p1 = pc.new Producer(1, 10);
        Producer p2 = pc.new Producer(2, 20);
        Consumer c1 = pc.new Consumer(1);
        Consumer c2 = pc.new Consumer(2);

        p1.start();
        p2.start();
        c1.start();
        c2.start();
    }
}