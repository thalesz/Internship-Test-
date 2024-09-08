## 8. What is a deadlock?

### 1. Definition

According to Professor Carlos A. Maziero in his book Operating Systems: Concepts and Mechanisms, The control of concurrency between tasks accessing shared resources involves suspending some tasks while others access the resources, in order to ensure their consistency. For this, each resource is associated with a semaphore or an equivalent mechanism. Tasks request and wait for the semaphore to be released before accessing the corresponding resource.

In some cases, the use of semaphores or mutexes can lead to deadlock situations, where all tasks involved become blocked while waiting for semaphore releases, and no further progress is made.


### 2. Example

The following code implements a funds transfer operation between two bank accounts. Each account is associated with a mutex, used to provide exclusive access to the account's data and thus avoid race conditions:

```  c
typedef struct conta_t
{
    int saldo; // current balance of the account
    mutex m; // mutex associated with the account
    // ... // other account information
} conta_t;

void transferir(conta_t* contaDeb, conta_t* contaCred, int valor)
{
    lock(contaDeb->m); // acquire access to contaDeb
    lock(contaCred->m); // acquire access to contaCred

    if (contaDeb->saldo >= valor)
    {
        contaDeb->saldo -= valor; // debit amount from contaDeb
        contaCred->saldo += valor; // credit amount to contaCred
    }
    unlock(contaDeb->m); // release access to contaDeb
    unlock(contaCred->m); // release access to contaCred
}
```

If two bank clients (represented by tasks t1 and t2) simultaneously perform transfer operations between their accounts (t1 transfers an amount v1 from c1 to c2 and t2 transfers an amount v2 from c2 to c1), a deadlock situation could occur. This happens if both tasks lock the accounts in opposite orders, causing each task to wait for the other to release a mutex.

In this situation, task t1 holds the mutex for c1 and requests the mutex for c2, while t2 holds the mutex for c2 and requests the mutex for c1. Since neither task can proceed without acquiring the desired mutex and neither can release its own mutex before obtaining the other mutex and completing the transfer, a deadlock occurs.


| Condition       | Description                                                                                                                               | Bank Account Example                                                                  |
|-----------------|-------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------|
| Mutual Exclusion | Access to resources must be done in a mutually exclusive manner, controlled by semaphores or equivalent mechanisms.                      | Only one task can access each account at a time.                                      |
| Hold and Wait    | A task can request access to other resources without releasing the resources it already holds.                                          | Each task obtains the semaphore for one account and requests the semaphore for the other account to proceed. |
| No Preemption    | A task will only release the resources it holds when it decides to, not unexpectedly (i.e., the operating system does not forcibly take away the resources allocated to tasks). | Each task holds the mutexes it has acquired until it explicitly releases them.         |
| Circular Wait    | There is a cycle of waiting for resource release among the tasks involved: task t1 waits for a resource held by task t2 (t1 → t2), which waits for a resource held by task t3, and so on, with task tn waiting for a resource held by t1. This circular dependency can be formally expressed as: t1 → t2 → t3 → · · · → tn → t1. | In the bank account example, t1 → t2 → t1 shows a clear cycle.     |

### 3.  Prevent, avoid, and detect deadlocks                   

In concurrent systems, deadlocks are a serious issue that can halt task execution and impact overall system performance. To address these challenges, several techniques have been developed to prevent, avoid, and detect deadlocks. The table below summarizes these techniques, including mutual exclusion, hold and wait, no preemption, and circular wait for prevention, as well as deadlock avoidance using algorithms like the Banker's Algorithm. Additionally, it covers methods for detecting deadlocks and resolving them through task elimination and rollback strategies. Understanding these techniques is crucial for maintaining system reliability and efficiency.

According to [Alex Coletta](https://alexcoletta.eng.br/artigos/deadlock-em-sistemas-operacionais/): It involves placing restrictions on processes to make deadlocks impossible. The aim is to eliminate the conditions that lead to deadlocks by implementing strategies such as:


| **Category**            | **Technique**          | **Description**                                                                                     | **Example**                                                                                           |
|-------------------------|------------------------|-----------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------|
| **Deadlock Prevention** | Mutual Exclusion       | Avoid the need for mutual exclusion, where only one task can access a resource at a time.          | Using a printer spooler that manages printer access so tasks don’t need exclusive access.            |
|                         | Hold and Wait          | Ensure tasks either request all needed resources at once or one resource at a time.                 | Splitting a bank transfer into separate debit and credit operations to avoid simultaneous access.     |
|                         | No Preemption          | Allow resources to be taken from tasks if necessary to prevent deadlocks.                          | Preempting memory pages by saving and restoring their state when needed.                             |
|                         | Circular Wait          | Prevent circular chains of dependencies between tasks and resources.                               | Enforcing a global order for resource requests (e.g., accounts must be accessed in a specific order). |
| **Deadlock Avoidance**  | Banker's Algorithm     | Keep the system in a safe state by avoiding requests that could lead to deadlock.                   | The Banker's Algorithm checks if resource allocation keeps the system in a safe state.                |
| **Deadlock Detection**  | Deadlock Detection     | Check the resource allocation graph for cycles that indicate deadlocks.                            | Using algorithms to detect cycles in the resource allocation graph.                                  |
|                         | Task Elimination       | Terminate tasks involved in the deadlock to free up resources.                                      | Choosing and terminating one or more tasks to resolve the deadlock.                                   |
|                         | Rollback               | Revert the system to a previous state before the deadlock occurred.                                | Using checkpoints to roll back database transactions if a deadlock is detected.                      |





---

[⬅️ Previous](../Resposta%2007/Resposta07.md)


<!-- Home Button -->
 [🏠 Home](../README.md)
