# Internship Test 
By Thales Lopes Araujo

## 1. Fix the Issues in the Following Code

### Requirements:
- **Compiler:** `gcc`
- **Task:** 
  - Remove errors and warnings.
  - Fix memory handling issues.

```c
#include <stdio.h>

int copyStr(char *x) {
 strcpy(x, "test");
 return 0;
}

int main() {
 const char x[3];
 copyStr((char *) x);
 printf("x=%s (%d bytes)\n", x, strlen(x));
 return 0;
} 
```
📄 [Answer](./Resposta%2001/Resposta01.md)

## 2. Describe the event occurred in the message log:

```
avc: denied { read write } for pid=1876 comm="syslogd"
name="xconsole" dev=tmpfs ino=5510
scontext=system_u:system_r:syslogd_t:s0
tcontext=system_u:object_r:device_t:s0 tclass=fifo_file permissive=1
```
📄 [Answer](./Resposta%2002/Resposta02.md)

## 3. In C language, what’s a static variable?

📄 [Answer](./Resposta%2003/Resposta03.md)

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
📄 [Answer](./Resposta%2004/Resposta04.md)


## 5. Describe the general architecture of an Android platform.

📄 [Answer](./Resposta%2005/Resposta05.md)

## 6. Explain about the following trace:

```
--------- beginning of crash
AndroidRuntime: FATAL EXCEPTION: main
Process: com.android.developer.crashsample, PID: 3686
java.lang.NullPointerException: crash sample
at
com.android.developer.crashsample.MainActivity$1.onClick(MainActivity
.java:27)
at android.view.View.performClick(View.java:6134)
at android.view.View$PerformClick.run(View.java:23965)
at android.os.Handler.handleCallback(Handler.java:751)
at android.os.Handler.dispatchMessage(Handler.java:95)
at android.os.Looper.loop(Looper.java:156)
at android.app.ActivityThread.main(ActivityThread.java:6440)
at java.lang.reflect.Method.invoke(Native Method)
at
com.android.internal.os.Zygote$MethodAndArgsCaller.run(Zygote.java:240)
at com.android.internal.os.ZygoteInit.main(ZygoteInit.java:746)
--------- beginning of system

```
📄 [Answer](./Resposta%2006/Resposta06.md)

## 7. Explain about the following trace:

```
*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
Build fingerprint: 'google/foo/bar:10/123.456/78910:user/releasekeys'
ABI: 'arm64'
Timestamp: 2020-02-16 11:16:31+0100
pid: 8288, tid: 8288, name: com.example.testapp >>>
com.example.testapp <<<
uid: 1010332
signal 11 (SIGSEGV), code 1 (SEGV_MAPERR), fault addr 0x0
Cause: null pointer dereference
 x0 0000007da81396c0 x1 0000007fc91522d4 x2 0000000000000001
x3 000000000000206e
 x4 0000007da8087000 x5 0000007fc9152310 x6 0000007d209c6c68
x7 0000007da8087000
 x8 0000000000000000 x9 0000007cba01b660 x10 0000000000430000
x11 0000007d80000000
 x12 0000000000000060 x13 0000000023fafc10 x14 0000000000000006
x15 ffffffffffffffff
 x16 0000007cba01b618 x17 0000007da44c88c0 x18 0000007da943c000
x19 0000007da8087000
 x20 0000000000000000 x21 0000007da8087000 x22 0000007fc9152540
x23 0000007d17982d6b
 x24 0000000000000004 x25 0000007da823c020 x26 0000007da80870b0
x27 0000000000000001
 x28 0000007fc91522d0 x29 0000007fc91522a0
 sp 0000007fc9152290 lr 0000007d22d4e354 pc 0000007cba01b640
backtrace:
 #00 pc 0000000000042f89
/data/app/com.example.testapp/lib/arm64/libexample.so
(com::example::Crasher::crash() const)
 #01 pc 0000000000000640
/data/app/com.example.testapp/lib/arm64/libexample.so
(com::example::runCrashThread())
 #02 pc 0000000000065a3b /system/lib/libc.so
(__pthread_start(void*))
 #03 pc 000000000001e4fd /system/lib/libc.so (__start_thread)
```

📄 [Answer](./Resposta%2007/Resposta07.md)
## 8. What is a deadlock?

📄 [Answer](./Resposta%2008/Resposta08.md)