/*
* Isaac Sullivan
* PriorityQueueTester.java
* Project 1 Solution
* (Describe, in general, the code in the file.)
*/

public class PriorityQueueTester
{

	public static void main(String[] args)
	{
		// basic tests of the Priority Queue Class
		// Add your own tests for further analysis
		// be sure to test Exception conditions

		PriorityQueue<String> pQ = new PriorityQueue<String>();

		pQ.enqueue("one");
		pQ.enqueue("two", 2);
		pQ.enqueue("three", 3);
		pQ.enqueue("four", 4);
		pQ.enqueue("five", 5);
		pQ.enqueue("six", 6);
		pQ.enqueue("seven", 7);
		pQ.enqueue("eight");
		pQ.enqueue("nine", 1);
		pQ.enqueue("ten", 1);

		System.out.println("First in line: " + pQ.first());
		System.out.println(pQ);
		
		// test removing all queue elements
		while (!pQ.isEmpty())
		{
			System.out.print(pQ.dequeue() + " -> ");
		}
		System.out.println("(empty)\n");

		pQ.enqueue("one");
		pQ.enqueue("two");
		pQ.enqueue("three");
		pQ.enqueue("four");
		pQ.enqueue("five");
		pQ.enqueue("six");
		pQ.enqueue("seven");
		pQ.enqueue("eight");
		pQ.enqueue("nine");
		pQ.enqueue("ten", 1000);
		pQ.enqueue("eleven", -200);
		
		System.out.println("First in line: " + pQ.first());
		System.out.println(pQ);
		while (!pQ.isEmpty())
		{
			System.out.print(pQ.dequeue() + " -> ");
		}
		System.out.println("(empty)\n");

	}

}
