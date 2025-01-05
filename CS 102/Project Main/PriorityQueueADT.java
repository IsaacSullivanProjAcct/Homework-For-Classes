/*
* Isaac Sullivan
* PriorityQueueADT.java
* Project 1 Solution
* (Describe, in general, the code in the file.)
*/
/*
 * QueueADT defines the interface to a queue collection.
 */
public interface PriorityQueueADT<T>
{
	/*
	 * Adds one element to the rear of this queue. 
	 * Higher priorities are inserted closer to the front of the queue
	 * Items with the same priority are processed in normal queue order
	 * 
	 * @param element  the element to be added to the rear of the queue
	 * @param priority relative priority of the queue item
	 */
	public void enqueue(T element, int priority);

	/*
	 * Removes and returns the element at the front of this queue.
	 * 
	 * @return the element at the front of the queue
	 */
	public T dequeue();

	/*
	 * Returns without removing the element at the front of this queue.
	 * 
	 * @return the first element in the queue
	 */
	public T first();

	/*
	 * Returns true if this queue contains no elements.
	 * 
	 * @return true if this queue is empty
	 */
	public boolean isEmpty();

	/*
	 * Returns the number of elements in this queue.
	 * 
	 * @return the integer representation of the size of the queue
	 */
	public int size();

	/*
	 * Returns a string representation of this queue.
	 * 
	 * @return the string representation of the queue
	 */
	public String toString();
}
