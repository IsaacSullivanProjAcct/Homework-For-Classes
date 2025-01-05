/*
* Isaac Sullivan
* PriorityNode.java
* Project 1 Solution
* (Describe, in general, the code in the file.)
*/

/*
 * Represents a node in a linked list.
 */
public class PriorityNode<T>
{
	private PriorityNode<T> _next;
	private T _element;
	private int _priority;
	private final int _MAX_PRIORITY = 100;

	/*
	 * Creates an empty node with a given priority.
	 */
	public PriorityNode(T elem, int priority)
	{
		// TODO To be completed as a Programming Project
		_next = null;
		_element = elem;
		if (priority >= 0 && priority <= _MAX_PRIORITY) {
            _priority = priority; // Valid priority is assigned.
        } else {
            _priority = 0; // Default priority if invalid.
        }
	}

	/*
	 * Creates a node storing the specified element with a default priority.
	 * 
	 * @param elem element to be stored
	 */
	public PriorityNode(T elem)
	{
		// TODO To be completed as a Programming Project
		this(elem, 0);
		
	}

	/*
	 * Returns the node that follows this one.
	 * 
	 * @return reference to next node
	 */
	public PriorityNode<T> getNext()
	{
		// TODO To be completed as a Programming Project
		return _next;
	}

	/*
	 * Sets the node that follows this one.
	 * 
	 * @param node node to follow this one
	 */
	public void setNext(PriorityNode<T> node)
	{
		// TODO To be completed as a Programming Project
		_next = node;
	}

	/*
	 * Returns the element stored in this node.
	 * 
	 * @return element stored at the node
	 */
	public T getElement()
	{
		// TODO To be completed as a Programming Project
		return _element;
	}

	/*
	 * Returns the priority of this node.
	 * 
	 * @return element priority the node
	 */
	public int getPriority()
	{
		// TODO To be completed as a Programming Project
		return _priority;
	}

	/*
	 * Sets the element stored in this node.
	 * 
	 * @param elem element to be stored at this node
	 */
	public void setElement(T elem)
	{
		// TODO To be completed as a Programming Project
		_element = elem;
	}
}
