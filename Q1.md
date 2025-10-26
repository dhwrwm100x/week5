# Explain the primary differences between an array and a linked list in terms of memory allocation, insertion/deletion efficiency, and data access.

### **Differences Between Array and Linked List**

| **Feature** | **Array** | **Linked List** |
|--------------|------------|----------------|
| **Memory Allocation** | Uses **contiguous (continuous)** memory locations. Size must be defined in advance. | Uses **dynamic (non-contiguous)** memory allocation; size can grow or shrink at runtime. |
| **Insertion / Deletion** | **Slow and costly**, as elements may need to be shifted. | **Efficient**, as only pointers are updated; no shifting needed. |
| **Data Access** | **Fast (O(1))** — direct access using index. | **Slow (O(n))** — must traverse nodes sequentially from the head. |
| **Memory Usage** | Uses **less memory** since no extra pointers are stored. | Uses **more memory** due to storage of pointer(s) in each node. |

**Summary:**  
Arrays are best for quick access and fixed-size data, while linked lists are better for frequent insertion and deletion operations where the size changes dynamically.
