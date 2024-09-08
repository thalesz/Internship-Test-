## 5. Describe the general architecture of an Android platform.


## Answer


According to [Geeks](): Android architecture contains a different number of components to support any Android device’s needs. Android software contains an open-source Linux Kernel having a collection of a number of C/C++ libraries which are exposed through application framework services. Among all the components Linux Kernel provides the main functionality of operating system functions to smartphones and Dalvik Virtual Machine (DVM) provide a platform for running an Android application

| Component          | Description                                                                                                     | Key Elements and Functions                                                                                           |
|--------------------|-----------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------|
| **Applications**   | The top layer where user-facing apps reside. Includes both pre-installed apps and third-party apps.            | - Home, Contacts, Camera, Gallery<br>- Apps from Google Play Store (e.g., chat apps, games)                        |
| **Application Framework** | Provides essential classes and services for building Android applications.                              | - Activity Manager<br>- Notification Manager<br>- View System<br>- Package Manager                                   |
| **Android Runtime**| Provides the environment for running applications, including core libraries and the virtual machine.            | - Core Libraries<br>- Dalvik Virtual Machine (DVM)<br>- ART (Android Runtime) from Android 5.0 onwards              |
| **Platform Libraries** | Includes core libraries for media, graphics, and other functionalities.                                    | - Media Library<br>- Surface Manager<br>- OpenGL<br>- SQLite<br>- FreeType<br>- WebKit<br>- SSL                    |
| **Linux Kernel**   | The foundation of the Android system, managing hardware interactions and system resources.                       | - Security<br>- Memory Management<br>- Process Management<br>- Network Stack<br>- Driver Model                      |

![Image 01: Pictorial representation of Android architecture with several main components ](https://media.geeksforgeeks.org/wp-content/uploads/20240527105114/Android_Architecture.webp)


According to [Android Developers](https://developer.android.com/guide/platform?hl=pt-br): 
Android is an open-source software stack based on Linux, designed for a variety of devices and form factors.

| Component                         | Description                                                                                               | Key Features and Functions                                                                                                        |
|-----------------------------------|-----------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
| **Linux Kernel**                  | The foundation of the Android platform, managing low-level functions like threading and memory management. | - Security<br>- Memory Management<br>- Process Management<br>- Network Stack<br>- Driver Model                                 |
| **Hardware Abstraction Layer (HAL)** | Provides standard interfaces that expose hardware capabilities to the higher-level Java API framework.    | - Camera Module<br>- Bluetooth Module<br>- Other hardware-specific modules                                                         |
| **Android Runtime (ART)**         | Executes applications in its own process, utilizing Dalvik Executable (DEX) files.                        | - Ahead-of-Time (AOT) Compilation<br>- Just-in-Time (JIT) Compilation<br>- Optimized Garbage Collection<br>- Better Debugging Compatibility |
| **Native C/C++ Libraries**        | Core system services and components are built using native code and C/C++ libraries.                      | - Access to OpenGL ES<br>- Native Development Kit (NDK) for direct access to native libraries                                      |
| **Java API Framework**            | Provides a complete set of Java APIs for building Android apps, simplifying component and service reuse.  | - Advanced UI System<br>- Resource Manager<br>- Notification Manager<br>- Activity Manager<br>- Content Providers               |
| **System Apps**                   | Pre-installed core apps for email, SMS, calendar, browser, contacts, etc., with no special status.       | - Apps can be replaced by third-party apps (e.g., SMS app, web browser)<br>- System apps provide essential functionalities for users |


<img src="https://developer.android.com/static/guide/platform/images/android-stack_2x.png?hl=pt-br" alt="Main components of the Android platform" width="50%" />

---

[⬅️ Previous](../Resposta%2004/Resposta04.md)

<!-- Next Button -->
[➡️ Next](../Resposta%2006/Resposta06.md)

<!-- Home Button -->
 [🏠 Home](../README.md)
