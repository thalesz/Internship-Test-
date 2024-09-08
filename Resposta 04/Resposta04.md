## 4.  Fix the issues in the following code:

```java
public class StringTest {
    private static boolean strEquals(String str1, String str2) {
    if (str1 == str2) {
    return true;
    }
    return false;
    }
    public static void main(String args[]) {
    String str1 = "abcde";
    String str2 = new String("abcde");
    boolean equal = strEquals(str1, str2);
    System.out.println("String are " + (equal ? "equal" :
   "different"));
    }
   }
```

## Answer

### 0. First compilation

```
Roaming\x5cCode\x5cUser\x5cworkspaceStorage\x5c56da1dec558fa4197314d15f91c5a6b0\x5credhat.java\x5cjdt_ws\x5cRespostas teste_5f8de154\x5cbin' 'StringTest' ;ff46d7a8-f7a1-41ee-85ad-8953af298cd7String are different
```


### 1. Understanding the Difference Between equals() and == in Java

The issue with the code lies in the way string equality is being checked. In Java, using the == operator compares the references (memory locations) of the two strings rather than their actual content. To compare the content of strings, you should use the equals() method

According to [Medium](https://medium.com/@AlexanderObregon/understanding-the-difference-between-equals-and-in-java-10a075326720#:~:text=The%20%3D%3D%20operator%20in%20Java,the%20same%20object%20in%20memory.) : The == operator in Java is used to compare the references of two objects. It checks whether the two object references being compared point to the same object in memory. 

The equals() method in Java is used to compare the content of two objects. It checks whether two objects are meaningfully equivalent, regardless of whether they share the same memory location. The default implementation of equals() in the Object class compares the object references, similar to the == operator. However, many classes override the equals() method to compare the actual content of the objects, such as String, Integer, or any custom class that you create.

According to [W3School](https://www.w3schools.com/java/ref_string_equals.asp): The equals() method compares two strings, and returns true if the strings are equal, and false if not.

``` java
public class StringTest {
    private static boolean strEquals(String str1, String str2) {
        // Use the equals() method to compare the content of the strings
        return str1.equals(str2);
    }

    public static void main(String[] args) {
        String str1 = "abcde";
        String str2 = new String("abcde");
        boolean equal = strEquals(str1, str2);
        System.out.println("Strings are " + (equal ? "equal" : "different"));
    }
}
```

Use the == operator to compare object references and the equals() method to compare the content of objects.

---

[⬅️ Previous](../Resposta%2003/Resposta03.md)

<!-- Next Button -->
[➡️ Next](../Resposta%2005/Resposta05.md)

<!-- Home Button -->
 [🏠 Home](../README.md)
