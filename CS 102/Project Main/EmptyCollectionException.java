/*
* Isaac Sullivan
* EmptyCollectionException.java
* Project 1 Solution
* (Describe, in general, the code in the file.)
*/
/*
 * Represents the situation in which a collection is empty.
 */
public class EmptyCollectionException extends RuntimeException
{
    /*
     * Sets up this exception with an appropriate message.
     * @param collection the name of the collection
     */
    public EmptyCollectionException(String collection)
    {
        super("The " + collection + " is empty.");
    }
}
