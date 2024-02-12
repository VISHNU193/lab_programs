#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify up
void max_heapify_up(int heap[], int index) {
    while (index > 0) {
        int parent_index = (index - 1) / 2;
        if (heap[index] > heap[parent_index]) {
            swap(&heap[index], &heap[parent_index]);
            index = parent_index;
        } else {
            break;
        }
    }
}

// Function to heapify down
void max_heapify_down(int heap[], int size, int index) {
    while (1) {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int largest = index;

        if (left_child_index < size && heap[left_child_index] > heap[largest]) {
            largest = left_child_index;
        }
        if (right_child_index < size && heap[right_child_index] > heap[largest]) {
            largest = right_child_index;
        }

        if (largest != index) {
            swap(&heap[index], &heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

// Function to insert a new element into the max heap
void insert_max_heap(int heap[], int* size, int value) {
    heap[*size] = value;
    (*size)++;
    max_heapify_up(heap, *size - 1);
}

// Function to extract the maximum element from the max heap
int extract_max(int heap[], int* size) {
    if (*size <= 0) {
        return -1; // Heap is empty
    }
    int max_val = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    max_heapify_down(heap, *size, 0);
    return max_val;
}

// In-order traversal
void inorder_traversal(int heap[], int size, int index) {
    if (index < size) {
        inorder_traversal(heap, size, 2 * index + 1);
        printf("%d ", heap[index]);
        inorder_traversal(heap, size, 2 * index + 2);
    }
}

// Pre-order traversal
void preorder_traversal(int heap[], int size, int index) {
    if (index < size) {
        printf("%d ", heap[index]);
        preorder_traversal(heap, size, 2 * index + 1);
        preorder_traversal(heap, size, 2 * index + 2);
    }
}

// Post-order traversal
void postorder_traversal(int heap[], int size, int index) {
    if (index < size) {
        postorder_traversal(heap, size, 2 * index + 1);
        postorder_traversal(heap, size, 2 * index + 2);
        printf("%d ", heap[index]);
    }
}

int main() {
    int heap[100];
    int size = 0;

    insert_max_heap(heap, &size, 10);
    insert_max_heap(heap, &size, 9);
    insert_max_heap(heap, &size, 8);
    insert_max_heap(heap, &size, 7);
    insert_max_heap(heap, &size, 6);
    insert_max_heap(heap, &size, 5);

    printf("In-order traversal: ");
    inorder_traversal(heap, size, 0);
    printf("\nPre-order traversal: ");
    preorder_traversal(heap, size, 0);
    printf("\nPost-order traversal: ");
    postorder_traversal(heap, size, 0);

    int max_val = extract_max(heap, &size);
    printf("\nMax Value: %d\n", max_val);

    printf("In-order traversal after extracting max: ");
    inorder_traversal(heap, size, 0);

    return 0;
}
