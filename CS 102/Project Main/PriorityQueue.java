/*
* Isaac Sullivan
* PriorityQueue.java
* Project 1 Solution
* (Describe, in general, the code in the file.)
*/

/*
 * LinkedQueue represents a linked implementation of a queue.
 */
public class PriorityQueue<T> implements PriorityQueueADT<T>
{
	private int _count;
	private PriorityNode<T> _head, _tail;

	/*
	 * Constructor - Creates an empty queue.
	 */
	public PriorityQueue()
	{
		_count = 0;
		_head = _tail = null;
	}

	/*
	 * Adds one element to the rear of this queue. 
	 * Higher priorities are inserted closer to the front of the queue
	 * Items with the same priority are processed in normal queue order
	 * 
	 * @param element  the element to be added to the rear of the queue
	 * @param priority relative priority of the queue item
	 */
	public void enqueue(T element, int priority)
	{
		// TODO To be completed as a Programming Project
		// add in-order insertion of the PriorityNode based on getPriority() value
		// the higher the priority is the closer to head it gets
		// equivalent priority is normal queue logic

		PriorityNode<T> newNode = new PriorityNode<>(element, priority);

		if (isEmpty()) {
			_head = _tail = newNode;
		} else {
			PriorityNode<T> current = _head;
			PriorityNode<T> previous = null;
	
			// Traverse the list to find the insertion point
			while (current != null && current.getPriority() >= priority) {
				previous = current;
				current = current.getNext();
			}
	
			if (previous == null) {
				// Insert at the head
				newNode.setNext(_head);
				_head = newNode;
			} else if (current == null) {
				// Insert at the tail
				_tail.setNext(newNode);
				_tail = newNode;
			} else {
				// Insert in the middle
				previous.setNext(newNode);
				newNode.setNext(current);
			}
		}
	
		_count++;

	}

	/*
	 * OVERLOAD: Adds the specified element to the tail of this queue with default
	 * priority 0.
	 * 
	 * @param element the element to be added to the tail of the queue
	 */
	public void enqueue(T element)
	{
		// TODO To be completed as a Programming Project
		this.enqueue(element, 0);
	}

	/*
	 * Removes the element at the head of this queue and returns a reference to it.
	 * 
	 * @return the element at the head of this queue
	 * @throws EmptyCollectionException if the queue is empty
	 */
	public T dequeue() throws EmptyCollectionException
	{
		// TODO To be completed as a Programming Project
		if (isEmpty())
		throw new EmptyCollectionException("LinkedQueue");

		T result = _head.getElement();
		_head = _head.getNext();
		_count--;

		if (isEmpty())
			_tail = null;

		return result;
	}

	/*
	 * Returns a reference to the element at the head of this queue. The element is
	 * not removed from the queue.
	 * 
	 * @return a reference to the first element in this queue
	 * @throws EmptyCollectionsException if the queue is empty
	 */
	public T first() throws EmptyCollectionException
	{
		// TODO To be completed as a Programming Project
		if (_head == null)
		{
			throw new EmptyCollectionException("Queue is empty");
		}
		return _head.getElement();
	}

	/*
	 * Returns true if this queue is empty and false otherwise.
	 * 
	 * @return true if this queue is empty
	 */
	public boolean isEmpty()
	{
		// TODO To be completed as a Programming Project
		return _head == null;
	}

	/*
	 * Returns the number of elements currently in this queue.
	 * 
	 * @return the number of elements in the queue
	 */
	public int size()
	{
		// TODO To be completed as a Programming Project
		return _count;
	}

	/*
	 * Returns a string representation of this queue. Shows the list of PriorityNode
	 * elements by position and queue priority
	 * 
	 * @return the string representation of the queue
	 */
	public String toString()
	{
		// TODO To be completed as a Programming Project
		StringBuilder sb = new StringBuilder();
		PriorityNode<T> current = _head;
	
		while (current != null) {
			sb.append("[Element: ").append(current.getElement())
			  .append(", Priority: ").append(current.getPriority()).append("] -> ");
			current = current.getNext();
		}
	
		sb.append("null");
		return sb.toString();
	}
}
