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

